
// ScreenSnapperForm.cpp
//
// Part of ScreenSnapper, a Windows utility to make screenshots and save them as JPG
//
// Sofware by Michiel Overtoom, motoom@xs4all.nl, february 2010
//

#include <vcl.h>
#pragma hdrstop
#include "ScreenSnapperForm.h"
#include <clipbrd.hpp>
#include <mmsystem.h>
#include "MainForm.h"
#include "AntiAlias.h"
#include <jpeg.hpp> // when using IJG jpeg lib instead of VCL's builtin JPEG routines
#include "JpegVclGlue.h" // when using IJG jpeg lib instead of VCL's builtin JPEG routines
#pragma package(smart_init)
#pragma resource "*.dfm"

/*
todo:
- Implement delete. We really miss it.
- Multiple select filenames (for delete)
- Editing of the screenshot from within Snapper:
	* red brush for encircling interesting spots and freehand drawing
    * text annotation
	* highlighting with yellow marker (behind black pixels)
    * 'spot' highlight (and subsequent dimming of the rest)
- Optional upper limit for size of JPG (in bytes) (for forums that allow only pictures below a certain byte size)
- Optional 'Save as BMP' instead of JPG
- Place filename on clipboard after making snap (optional)
- Replace Snap listbox with a listview with multiple columns: Filename, date/time (both sortable)
- When making a snap, add it to the listbiew and highlight it too
- cropping
- bitmap overlay on screenshot
- font appearance configurable
- bicubic quality resize to arbitrary size
*/

TScreenSnapper *ScreenSnapper;

HWND NextHandle=0;
int Nr=1;

__fastcall TScreenSnapper::TScreenSnapper(TComponent* Owner) : TForm(Owner)
{
	 NextHandle=(HWND)SetClipboardViewer(Handle); // Register with clipboard chain
}


__fastcall TScreenSnapper::~TScreenSnapper()
{
	ChangeClipboardChain(Handle,NextHandle); // Unregister from clipboard chain
}


AnsiString __fastcall TScreenSnapper::JapanDatum(void)
{
	static AnsiString Months[]={"","jan","feb","mar","apr","may","jun","jul","aug","sep","oct","nov","dec"};
	SYSTEMTIME St;
	GetSystemTime(&St);
	AnsiString Tmp;
	Tmp.printf("%d-%s-%d",St.wYear,Months[St.wMonth].c_str(),St.wDay);
	return Tmp;
}


void __fastcall TScreenSnapper::WndProc(TMessage &Msg)
{
	// User placed something on the clipboard
	if (Msg.Msg==WM_DRAWCLIPBOARD) {
		TClipboard *Clip=Clipboard();
		if (Clip->HasFormat(CF_BITMAP)) { // Clipboard has a bitmap, process it

			// Start processing, sound camera shutter click
			if (Main->SoundsCheck->Checked) PlaySound("Shutter",HInstance,SND_RESOURCE|SND_ASYNC);

			// Ensure folder exists
			if (!Main->EnsureSnapsFolder()) return;

			Clipboard()->Open();
			HBITMAP Hb=(HBITMAP)Clip->GetAsHandle(CF_BITMAP);
			if (Hb) {
				// UI
				Main->IntroMemo->Visible=false;
				Main->NameLab->Visible=true;
				Main->AllSheetShownBefore=false;

				Graphics::TBitmap *Bm=new Graphics::TBitmap();
				Bm->Handle=Hb;

				// Crop if necessary
				Main->Crop(Bm,Main->MonitorCombo->ItemIndex); // 'The Parameter is incorrect, OutOfResources exception

				/* Old crop code, didn't work very well for multi-monitor
				if (Main->CropCheck->Checked) {
					int LimitWidth=StrToIntDef(Main->CropWidthEdit->Text,0);
					int LimitHeight=StrToIntDef(Main->CropHeightEdit->Text,0);
					if (LimitWidth>0 && LimitHeight>0) {
						if (LimitWidth<Bm->Width) Bm->Width=LimitWidth;
						if (LimitHeight<Bm->Height) Bm->Height=LimitHeight;
						}
					}
				*/

				// Convert to editable format
				Bm->PixelFormat=pf24bit;

				AnsiString FontOverlayName="Arial";
				int FontSizeOverlay=24;
				TColor FontShadowColor=clBlack;
				TColor FontColor=TColor(RGB(255,192,0));

				// Overlay (fixed text at top)
				AnsiString S=Main->OverlayEdit->Text.Trim();
				if (S!="") {
					TCanvas *Can=Bm->Canvas;
					Can->Font->Name=FontOverlayName;
					Can->Font->Size=FontSizeOverlay;
					SetBkMode(Can->Handle,TRANSPARENT);
					// Shadow
					Can->Font->Color=FontShadowColor;
					Can->TextOut(16,16,S);
					// Text itself
					Can->Font->Color=FontColor;
					Can->TextOut(14,14,S);
					}

				// Find a free serial nr
				for (;;) {
					AnsiString Format=IncludeTrailingBackslash(Main->FolderEdit->Text)+Main->PrefixEdit->Text+"-"+JapanDatum()+"-%03d.jpg";
					Savename.printf(Format.c_str(),Nr++);
					if (!FileExists(Savename)) break;
					}

				// Save full size
				if (!Main->SaveHalfSizeCheck->Checked) {
					SaveToJpgFile(Bm,Savename,Main->JpgQualityBar->Position);
					/* Orig code
					TJPEGImage *Jpg=new TJPEGImage;
					Jpg->CompressionQuality=Main->JpgQualityBar->Position;
					Jpg->Assign(Bm);
					Jpg->SaveToFile(Savename);
					delete Jpg;
					*/
					}

				// Shrink bitmap for display purposes
				Graphics::TBitmap *Half=new Graphics::TBitmap();
				Graphics::TBitmap *Quart=new Graphics::TBitmap();
				AntiAlias(Bm,Half,false);

				// Save half size
				if (Main->SaveHalfSizeCheck->Checked) {
					SaveToJpgFile(Half,Savename,Main->JpgQualityBar->Position);
					/* Orig code
					TJPEGImage *Jpg=new TJPEGImage;
					Jpg->CompressionQuality=Main->JpgQualityBar->Position;
					Jpg->Assign(Half);
					Jpg->SaveToFile(Savename);
					delete Jpg;
					*/
					}
				AntiAlias(Half,Quart,false);
				Main->Img->Picture->Bitmap->Assign(Quart);
				Main->NameLab->Caption="Last saved: "+Savename;
				delete Half;
				delete Quart;
				delete Bm;

				// Done processing, sound camera transport
				if (Main->SoundsCheck->Checked) PlaySound("Transport",HInstance,SND_RESOURCE|SND_ASYNC);
				}
			Clipboard()->Close();
			}
		SendMessage(NextHandle,WM_DRAWCLIPBOARD,0,0);
		}

	
	// Standard response to clipboard chain management
	if (Msg.Msg==WM_CHANGECBCHAIN) {
		if ((HWND)Msg.WParam==NextHandle)
			NextHandle=(HWND)Msg.LParam;
		else
			SendMessage(NextHandle,WM_CHANGECBCHAIN,Msg.WParam,Msg.LParam);
		}

	TForm::WndProc(Msg);
}



// MainForm.cpp
//
// Main userinterface with the three tab pages.
//
// Part of ScreenSnapper, a Windows utility to make screenshots and save them as JPG
//
// Sofware by Michiel Overtoom, motoom@xs4all.nl, february 2010
//

#include <vcl.h>
#pragma hdrstop
#include <vector.h>
#include <jpeg.hpp>
#include <clipbrd.hpp>
#include <filectrl.hpp>
#include "MainForm.h"
#include "Reg.h"
#include "Files.h"
#include "ImgViewerForm.h"
#include "ScreenSnapperForm.h"
#include "AntiAlias.h"
#include "BrowseForFolderDialog.h"
#include "ActivateExistingRunningInstance.h"
#include "JpegVclGlue.h"
#pragma package(smart_init)
#pragma link "Systray"
#pragma resource "*.dfm"

TMain *Main;

__fastcall TMain::TMain(TComponent* Owner) : TForm(Owner)
{
	if (ActivateExistingRunningInstance(Handle,"TMain","Snapper")) {
		PostQuitMessage(0);
		return;
		}

	JpgQualityBar->Position=Reg::GetInt("JpgQuality",90);
	JpgQualityLab->Caption=AnsiString(JpgQualityBar->Position);
	ClickShotCheck->Checked=Reg::GetBool("ClickShotCheck",false);
	SoundsCheck->Checked=Reg::GetBool("SoundsCheck",true);
	// CropCheck->Checked=Reg::GetBool("Crop",false);
	// CropWidthEdit->Enabled=CropCheck->Checked;
	// CropHeightEdit->Enabled=CropCheck->Checked;
	// CropWidthEdit->Text=Reg::GetString("CropWidth");
	// CropHeightEdit->Text=Reg::GetString("CropHeight");
	SaveHalfSizeCheck->Checked=Reg::GetBool("SaveHalfSize",false);
	OverlayEdit->Text=Reg::GetString("Overlay");
	Caption="Snapper "+OverlayEdit->Text;
	if (ClickShotCheck->Checked)
		Systray->Hint="Snapper - Click to make screenshot";
	else
		Systray->Hint=Caption;
	FolderEdit->Text=Reg::GetString("Folder",ExtractFilePath(Application->ExeName));

	AnsiString Compname;
	char ComputerName[MAX_COMPUTERNAME_LENGTH + 1];
	DWORD ComputerNameLen=MAX_COMPUTERNAME_LENGTH;
	if (GetComputerName(ComputerName,&ComputerNameLen))
		Compname=ComputerName;
	if (Compname=="") Prefix="Snap";
	PrefixEdit->Text=Reg::GetString("Prefix",Compname);

	FillMonitorCombo(Reg::GetInt("Monitor",0));

	Pages->ActivePage=SettingsSheet;
	Systray->Enabled=true; // Minimalize to systray

	ExitInsteadOfMinimize=false;
	AllSheetShownBefore=false;

	#ifdef REG_INSTRUMENTATION
	Reg::ShowLog("TMain constructor");
	Reg::ClearLog();
	#endif
}


__fastcall TMain::~TMain()
{
	Reg::PutInt("JpgQuality",JpgQualityBar->Position);
	Reg::PutBool("SoundsCheck",SoundsCheck->Checked);
	Reg::PutBool("ClickShotCheck",ClickShotCheck->Checked);
	Reg::PutInt("Monitor",MonitorCombo->ItemIndex);
	// Reg::PutBool("Crop",CropCheck->Checked);
	// Reg::PutString("CropWidth",CropWidthEdit->Text);
	// Reg::PutString("CropHeight",CropHeightEdit->Text);
	Reg::PutBool("SaveHalfSize",SaveHalfSizeCheck->Checked);
	Reg::PutString("Overlay",OverlayEdit->Text);
	Reg::PutString("Folder",FolderEdit->Text);
	Reg::PutString("Prefix",PrefixEdit->Text);
	#ifdef REG_INSTRUMENTATION
	Reg::ShowLog("TMain destructor");
	Reg::DestroyLog();
	#endif
}


void __fastcall TMain::SystrayLeftClick(TObject *Sender)
{
	if (ClickShotCheck->Checked)
		keybd_event(VK_SNAPSHOT,0,0,0);
	else
		Application->Restore();
}


void __fastcall TMain::OpenPopupItemClick(TObject *Sender)
{
	Application->Restore();
}


void __fastcall TMain::SettingsPopupItemClick(TObject *Sender)
{
	Application->Restore();
	Pages->ActivePage=SettingsSheet;
}


void __fastcall TMain::UnloadPopupItemClick(TObject *Sender)
{
	ExitButtonClick(this);
}


void __fastcall TMain::OverlayEditChange(TObject *Sender)
{
	Caption="Snapper "+OverlayEdit->Text;
	Systray->Hint=Caption;
}


void __fastcall TMain::JpgQualityBarChange(TObject *Sender)
{
	JpgQualityLab->Caption=JpgQualityBar->Position;
}


void __fastcall TMain::MainSheetShow(TObject *Sender)
{
	Status->Panels->Items[0]->Text="Mail questions & suggestions to motoom@xs4all.nl";
}

/*
	Coordinates: left,top,right,bottom
	Observations:
		- The MONITORINFO's rcMonitor and rcWork always contain the same coordinates (at least for me)
		- The primary monitor always has coords (0,0)..(ResW,ResH).

	My monitors
	#0: Dell 1920x1200
	#1: Sony 1280x1024

	Monitors next to each other
	Virtual screen size: 3200x1200

	Setup: Dell rechts primary, Sony links (simplest layout)

		#0:    0,0,1920,1200   (primary)
		#1: 1920,0,3200,1024

	Setup: Dell links, Sony rechts primary
		#0: 1280,0,3200,1200
		#1:    0,0,1280,1024 (primary)

	Setup: Dell links primary, Sony rechts (secondary monitor left of primary; negative coordinates)
		#0: 0,0,1920,1200 (primary)
		#1: -1280,0,0,1024

	Monitor on top/ below eachother
	Virtual screen size: 1920x2224

	Setup: Dell boven primary, Sony onder
	#0: 0,0,1920,1200 (primary)
	#1: 0,1200,1280,2224

	Setup: Dell onder primary, Sony boven (left aligned)
	#0: 0,0,1920,1200 (primary)
	#1: 0,-1024,1280,0

	Setup: Dell onder primary, Sony boven (center aligned)
	#0: 0,0,1920,1200 (primary)
	#1: 280,-1024,1560,0

	Setup: Dell boven, sony onder primary
	ODS: #0: 0,-1200,1920,0
	ODS: #1: 0,0,1280,1024 (primary)

	Monitors skewed
	Virtual screen size: 3200x2224
	Dell primary, Sony Southwest of it:

	#0: 0,0,1920,1200 (primary)
	#1: -1280,1200,0,2224


*/

void __fastcall TMain::FillMonitorCombo(int Select)
{
	MonitorCombo->Items->Clear();

	int DesktopW=GetSystemMetrics(SM_CXVIRTUALSCREEN);
	int DesktopH=GetSystemMetrics(SM_CYVIRTUALSCREEN);
	AnsiString Description="Entire desktop, "+AnsiString(DesktopW)+"x"+AnsiString(DesktopH);
	MonitorCombo->Items->Add(Description);
	for (int i=0;i<Screen->MonitorCount;i++) {
		AnsiString Description="Monitor #"+AnsiString(i+1);
		HMONITOR Hm=Screen->Monitors[i]->Handle;
		MONITORINFO Mi;
		ZeroMemory(&Mi,sizeof(Mi));
		Mi.cbSize=sizeof(Mi);
		if (GetMonitorInfo(Hm,&Mi)) {
			int W=Mi.rcMonitor.right-Mi.rcMonitor.left;
			int H=Mi.rcMonitor.bottom-Mi.rcMonitor.top;
			Description="Monitor #"+AnsiString(i+1)+", "+AnsiString(W)+"x"+AnsiString(H);
			// AnsiString S="#"+AnsiString(i)+": "+AnsiString(Mi.rcMonitor.left)+","+AnsiString(Mi.rcMonitor.top)+","+AnsiString(Mi.rcMonitor.right)+","+AnsiString(Mi.rcMonitor.bottom)+"  "+AnsiString(Mi.rcWork.left)+","+AnsiString(Mi.rcWork.top)+","+AnsiString(Mi.rcWork.right)+","+AnsiString(Mi.rcWork.bottom);
			// OutputDebugString(S.c_str());
			if (Mi.dwFlags&MONITORINFOF_PRIMARY) Description+=" (primary)";
			}
		MonitorCombo->Items->Add(Description);
		}

	if (Select<MonitorCombo->Items->Count)
		MonitorCombo->ItemIndex=Select;
	else
		MonitorCombo->ItemIndex=0;
}


void TMain::Crop(Graphics::TBitmap *Src,int Monitor)
{
	if (Monitor<=0) return; // 0=Entire desktop
	if (Screen->MonitorCount<1) return; // No monitors found

	int DesktopW=GetSystemMetrics(SM_CXVIRTUALSCREEN),DesktopH=GetSystemMetrics(SM_CYVIRTUALSCREEN);

	// If the user pressed Alt-PrtScreen, only a part of the desktop has been captured (only the active window)
	// In this case, do not crop.  Only crop when the entire desktop has been captured.
	if (Src->Width!=DesktopW && Src->Height!=DesktopH) return;

	// Make a list of all monitor rectangles
	RECT *Rects=new TRect[Screen->MonitorCount];
	for (int i=0;i<Screen->MonitorCount;i++) {
		HMONITOR Hm=Screen->Monitors[i]->Handle;
		MONITORINFO Mi;
		ZeroMemory(&Mi,sizeof(Mi));
		Mi.cbSize=sizeof(Mi);
		if (!GetMonitorInfo(Hm,&Mi)) {
			ShowMessage("Error: Unable to get information for monitor #"+AnsiString(i+1));
			Rects[i]=TRect(0,0,0,0);
			}
		else
			Rects[i]=TRect(Mi.rcMonitor.left,Mi.rcMonitor.top,Mi.rcMonitor.right,Mi.rcMonitor.bottom);
		}
	// When negative coordinates are found, shift all monitor rectangles to the positive
	bool Done=false;
	while (!Done) {
		Done=true;
		for (int i=0;i<Screen->MonitorCount;i++) {
			if (Rects[i].left<0) {
				int OffX= -Rects[i].left;
				for (int j=0;j<Screen->MonitorCount;j++) {
					Rects[j].left+=OffX;
					Rects[j].right+=OffX;
					}
				Done=false;
				break;
				}
			if (Rects[i].top<0) {
				int OffY= -Rects[i].top;
				for (int j=0;j<Screen->MonitorCount;j++) {
					Rects[j].top+=OffY;
					Rects[j].bottom+=OffY;
					}
				Done=false;
				break;
				}
			// todo: right & top coordinates should be checked for too?
			}
		}
	// check that the bounds should now match the desktop resolution
	int MinX=Rects[0].left;
	int MinY=Rects[0].top;
	int MaxX=Rects[0].right;
	int MaxY=Rects[0].bottom;
	for (int i=0;i<Screen->MonitorCount;i++) {
		if (Rects[i].left<MinX) MinX=Rects[i].left;
		if (Rects[i].right>MaxX) MaxX=Rects[i].right;
		if (Rects[i].top<MinY) MinY=Rects[i].top;
		if (Rects[i].bottom>MaxY) MaxY=Rects[i].bottom;
		}
	AnsiString Error;
	if (MinX!=0)
		Error+="MinX is "+AnsiString(MinX)+", but it should be 0\n";
	if (MinY!=0)
		Error+="MinY is "+AnsiString(MinY)+", but it should be 0\n";
	if (MaxX!=DesktopW)
		Error+="MaxX is "+AnsiString(MaxX)+", but it should be "+AnsiString(DesktopW)+"\n";
	if (MaxY!=DesktopH)
		Error+="MaxY is "+AnsiString(MaxY)+", but it should be "+AnsiString(DesktopH)+"\n";
	if (Error!="") {
		ShowMessage("Snapper found a logical error in itself.\n\n"+Error+"\nPlease forward this error (and a description of your multimonitor setup) to motoom@xs4all.nl");
		delete Rects;
		return;
		}

	Monitor--;
	Graphics::TBitmap *Dst=new Graphics::TBitmap;
	Dst->PixelFormat=Src->PixelFormat;
	int W=Rects[Monitor].right-Rects[Monitor].left;
	int H=Rects[Monitor].bottom-Rects[Monitor].top;
	Dst->Width=W;
	Dst->Height=H;
	Dst->Canvas->CopyRect(TRect(0,0,W,H),Src->Canvas,Rects[Monitor]);
	Src->Assign(Dst);
	delete Dst;

	delete Rects;
}

void __fastcall TMain::SettingsSheetShow(TObject *Sender)
{
	ActiveControl=PrefixEdit;
	Status->Panels->Items[0]->Text="";
}


// Load a Jpeg picture
Graphics::TBitmap *JpegLoad(const AnsiString &Filename)
{
	Graphics::TBitmap *Bm=new Graphics::TBitmap;
	LoadFromJpgFile(Bm,Filename);
	return Bm;

	/* Orig code
	TJPEGImage *Img=new TJPEGImage;
	Img->LoadFromFile(Filename);

	Graphics::TBitmap *Bm=new Graphics::TBitmap;
	Bm->Assign(Img);

	delete Img;
	return Bm;
	*/
}


// Reduce a TBitmap until it fits Width, Height
void __fastcall TMain::ReduceBitmap(Graphics::TBitmap **Bm,int Width,int Height)
{
	while ((*Bm)->Width>Width || (*Bm)->Height>Height) {
		Graphics::TBitmap *Half=new Graphics::TBitmap;
		AntiAlias(*Bm,Half,false);
		delete *Bm;
		*Bm=Half;
		}
}


void __fastcall TMain::ImgClick(TObject *Sender)
{
	if (ScreenSnapper->Savename!="") {
		Clipboard()->AsText="\""+ScreenSnapper->Savename+"\"";
		Status->Panels->Items[0]->Text="Filename copied to clipboard: \""+ScreenSnapper->Savename+"\"";
		}
}


void __fastcall TMain::ImgDblClick(TObject *Sender)
{
	if (ScreenSnapper->Savename!="")
		OpenViewer(ScreenSnapper->Savename);
}


void __fastcall TMain::OpenViewer(const AnsiString &Filename)
{
	ImgViewer->Img->Hint=Filename+" (click to close)";
	ImgViewer->Img->Picture->LoadFromFile(Filename);
	ImgViewer->Caption="Actual size image - "+Filename+" (click to close)";
	ImgViewer->Show();
}


void __fastcall TMain::FolderEditChange(TObject *Sender)
{
	AllSheetShownBefore=false;
}


bool __fastcall TMain::EnsureSnapsFolder(void)
{
	if (DirectoryExists(FolderEdit->Text)) return true;

	AnsiString Msg="The folder\r\n\r\n"+FolderEdit->Text+"\r\n\r\ndoes not exist. Create this folder?";
	if (MessageBox(Handle,Msg.c_str(),"Create folder?",MB_YESNO)==IDYES)
		return ForceDirectories(FolderEdit->Text);

	return false;
}


void __fastcall TMain::FolderEditKeyPress(TObject *Sender, char &Key)
{
	if (Key=='\r') {
		EnsureSnapsFolder();
		Key=0;
		}
}


void __fastcall TMain::ChooseButtonClick(TObject *Sender)
{
	TBrowseForFolderDialog *Brow=new TBrowseForFolderDialog(this);
	Brow->Folder=FolderEdit->Text;
	if (Brow->Execute())
		FolderEdit->Text=Brow->Folder;
	delete Brow;
}

void __fastcall TMain::FormClose(TObject *Sender, TCloseAction &Action)
{
	if (ExitInsteadOfMinimize) return;
	// Minimize instead of close
	Action=caNone;
	Application->Minimize();
}


void __fastcall TMain::ExitButtonClick(TObject *Sender)
{
	ExitInsteadOfMinimize=true;
	Close();
}


void __fastcall TMain::PrefixEditKeyPress(TObject *Sender, char &Key)
{
	if (Key=='\\' || Key=='/' || Key==':' || Key=='*' || Key=='?' || Key=='\"' || Key=='<' || Key=='>' || Key=='|') {
		MessageBeep(0);
		Key=0;
		return;
		}
}


void __fastcall TMain::FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
	if (Key==VK_F4 && Shift.Contains(ssAlt)) {
		ExitInsteadOfMinimize=true;
		Close();
		}
	if (Key==VK_ESCAPE) {
		Key=0;
		Application->Minimize();
		}
}


void __fastcall TMain::PreviewListKeyDown(TObject *Sender, WORD &Key,
	  TShiftState Shift)
{
	if (Key==VK_DELETE) ShowMessage("Todo: Delete selected screenshot");
}


void __fastcall TMain::AllSheetShow(TObject *Sender)
{
	if (!AllSheetShownBefore) {
		TFiles *Files=new TFiles();
		Files->Add(FolderEdit->Text,"*.jpg",false,false);
		PreviewList->Items=Files->Filelist;
		delete Files;
		AllSheetShownBefore=true;
		}
}


void __fastcall TMain::PreviewListClick(TObject *Sender)
{
	LoadTim->Enabled=false;
	LoadTim->Enabled=true;

	int Index=PreviewList->ItemIndex;
	if (Index!=-1) {
		AnsiString Filename=IncludeTrailingBackslash(FolderEdit->Text)+PreviewList->Items->Strings[Index];
		Clipboard()->AsText="\""+Filename+"\"";
		Status->Panels->Items[0]->Text="Filename copied to clipboard: \""+Filename+"\"";
		}
}


void __fastcall TMain::PreviewListDblClick(TObject *Sender)
{
	int Index=PreviewList->ItemIndex;
	if (Index!=-1) {
		AnsiString Filename=IncludeTrailingBackslash(FolderEdit->Text)+PreviewList->Items->Strings[Index];
		OpenViewer(Filename);
		}
}


void __fastcall TMain::LoadTimTimer(TObject *Sender)
{
	LoadTim->Enabled=false;

	int Index=PreviewList->ItemIndex;
	if (Index>PreviewList->Items->Count-1) return;

	AnsiString Filename=IncludeTrailingBackslash(FolderEdit->Text)+PreviewList->Items->Strings[Index];
	if (!FileExists(Filename)) {
		PreviewImg->Picture->Assign(0);
		return;
		}

	Graphics::TBitmap *Bm=JpegLoad(Filename);
	ReduceBitmap(&Bm,PreviewImg->Width,PreviewImg->Height);
	PreviewImg->Picture->Assign(Bm);
	delete Bm;
}


void __fastcall TMain::OkButtonClick(TObject *Sender)
{
	Application->Minimize();
}


void __fastcall TMain::AllSheetResize(TObject *Sender)
{
	LoadTim->Enabled=false;
	LoadTim->Enabled=true;
}

void __fastcall TMain::PreviewImgDblClick(TObject *Sender)
{
	int Index=PreviewList->ItemIndex;
	if (Index>PreviewList->Items->Count-1) return;

	AnsiString Filename=IncludeTrailingBackslash(FolderEdit->Text)+PreviewList->Items->Strings[Index];
	OpenViewer(Filename);
}




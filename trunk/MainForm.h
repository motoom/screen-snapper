
// MainForm.h
//
// Part of ScreenSnapper, a Windows utility to make screenshots and save them as JPG
//
// Sofware by Michiel Overtoom, motoom@xs4all.nl, february 2010
//

#ifndef MainFormH
#define MainFormH

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "Systray.hpp"
#include <Menus.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <ComCtrls.hpp>
#include <Buttons.hpp>
#include <jpeg.hpp>
#include <Dialogs.hpp>

class TMain : public TForm
{
__published:	// IDE-managed Components
	TSystray *Systray;
	TPopupMenu *Popup;
	TMenuItem *OpenPopupItem;
	TMenuItem *UnloadPopupItem;
	TStatusBar *Status;
	TPageControl *Pages;
	TTabSheet *MainSheet;
	TImage *Img;
	TLabel *NameLab;
	TTabSheet *SettingsSheet;
	TCheckBox *SoundsCheck;
	TCheckBox *SaveHalfSizeCheck;
	TLabel *Label4;
	TEdit *OverlayEdit;
	TButton *OverlayFontButton;
	TLabel *Label5;
	TScrollBar *JpgQualityBar;
	TLabel *JpgQualityLab;
	TMemo *IntroMemo;
	TLabel *Label1;
	TEdit *FolderEdit;
	TButton *ChooseButton;
	TButton *ExitButton;
	TEdit *PrefixEdit;
	TLabel *Label2;
	TTabSheet *AllSheet;
	TListBox *PreviewList;
	TSplitter *Splitter1;
	TImage *PreviewImg;
	TTimer *LoadTim;
	TButton *OkButton;
	TFontDialog *OverlayFontDlg;
	TLabel *Label3;
	TEdit *OverlayTopEdit;
	TLabel *Label8;
	TMenuItem *SettingsPopupItem;
	TCheckBox *ClickShotCheck;
	TLabel *Label9;
	TComboBox *MonitorCombo;
	void __fastcall OpenPopupItemClick(TObject *Sender);
	void __fastcall UnloadPopupItemClick(TObject *Sender);
	void __fastcall ImgClick(TObject *Sender);
	void __fastcall JpgQualityBarChange(TObject *Sender);
	void __fastcall OverlayEditChange(TObject *Sender);
	void __fastcall MainSheetShow(TObject *Sender);
	void __fastcall SettingsSheetShow(TObject *Sender);
	void __fastcall ImgDblClick(TObject *Sender);
	void __fastcall FolderEditChange(TObject *Sender);
	void __fastcall FolderEditKeyPress(TObject *Sender, char &Key);
	void __fastcall ChooseButtonClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ExitButtonClick(TObject *Sender);
	void __fastcall PrefixEditKeyPress(TObject *Sender, char &Key);
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall PreviewListKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall AllSheetShow(TObject *Sender);
	void __fastcall PreviewListClick(TObject *Sender);
	void __fastcall LoadTimTimer(TObject *Sender);
	void __fastcall OkButtonClick(TObject *Sender);
	void __fastcall AllSheetResize(TObject *Sender);
	void __fastcall PreviewImgDblClick(TObject *Sender);
	void __fastcall PreviewListDblClick(TObject *Sender);
	void __fastcall SystrayLeftClick(TObject *Sender);
	void __fastcall SettingsPopupItemClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	AnsiString Prefix;
	bool ExitInsteadOfMinimize;
	bool ThumbnailsShownBefore;
	bool AllSheetShownBefore;
	//
	__fastcall TMain(TComponent* Owner);
	__fastcall ~TMain();
	Graphics::TBitmap *CreateThumbnailBitmap(const AnsiString &Filename);
	void __fastcall FillMonitorCombo(int Select=0);
	void __fastcall ReduceBitmap(Graphics::TBitmap **Bm,int Width,int Height);
	void __fastcall HighlightThumbnail(TPanel *HighlightPan,bool WithUnselectOfOthers=true);
	void __fastcall OpenViewer(const AnsiString &Filename);
	bool __fastcall EnsureSnapsFolder(void);
	void Crop(Graphics::TBitmap *Src,int Monitor=0);
	};

extern PACKAGE TMain *Main;

#endif

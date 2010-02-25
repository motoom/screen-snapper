
// ScreenSnapperForm.h
//
// Part of ScreenSnapper, a Windows utility to make screenshots and save them as JPG
//
// Sofware by Michiel Overtoom, motoom@xs4all.nl, february 2010
//

#ifndef ScreenSnapperFormH
#define ScreenSnapperFormH

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>

class TScreenSnapper : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
private:	// User declarations
public:		// User declarations
	AnsiString Savename;
	//
	__fastcall TScreenSnapper(TComponent* Owner);
	__fastcall ~TScreenSnapper();
	AnsiString __fastcall JapanDatum(void);
	void __fastcall WndProc(TMessage &Msg);
};

extern PACKAGE TScreenSnapper *ScreenSnapper;

#endif

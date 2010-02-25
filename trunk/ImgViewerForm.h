
// ImgViewerForm.h
//
// Part of ScreenSnapper, a Windows utility to make screenshots and save them as JPG
//
// Sofware by Michiel Overtoom, motoom@xs4all.nl, february 2010
//

#ifndef ImgViewerFormH
#define ImgViewerFormH

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>

class TImgViewer : public TForm
{
__published:	// IDE-managed Components
	TImage *Img;
	void __fastcall ImgClick(TObject *Sender);
	void __fastcall FormClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TImgViewer(TComponent* Owner);
};

extern PACKAGE TImgViewer *ImgViewer;

#endif

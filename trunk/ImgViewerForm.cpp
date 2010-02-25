
// ImgViewerForm.cpp
//
// Part of ScreenSnapper, a Windows utility to make screenshots and save them as JPG
//
// Sofware by Michiel Overtoom, motoom@xs4all.nl, february 2010
//

#include <vcl.h>
#pragma hdrstop
#include "ImgViewerForm.h"
#pragma package(smart_init)
#pragma resource "*.dfm"

TImgViewer *ImgViewer;

__fastcall TImgViewer::TImgViewer(TComponent* Owner)
	: TForm(Owner)
{
}

void __fastcall TImgViewer::ImgClick(TObject *Sender)
{
	Close();	
}

void __fastcall TImgViewer::FormClick(TObject *Sender)
{
	Close();	
}


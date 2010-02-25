
// AntiAlias.cpp
//
// Halves the size of a bitmap, blending pixels.
//
// Sofware by Michiel Overtoom, motoom@xs4all.nl
//
// Version 1.0

#include <vcl.h>
#pragma hdrstop
#include "AntiAlias.h"
#pragma package(smart_init)

void __fastcall AntiAlias(Graphics::TBitmap *SrcBm,Graphics::TBitmap *DstBm,bool GrayScale)
{
	SrcBm->PixelFormat=pf24bit;
	int SrcW=SrcBm->Width;
	int SrcH=SrcBm->Height;

	int DstW=SrcW/2;
	int DstH=SrcH/2;

	DstBm->PixelFormat=pf24bit;
	DstBm->Width=DstW;
	DstBm->Height=DstH;

	int DstY=0;

	if (!GrayScale) {
		for (int SrcY=0;SrcY<DstH;SrcY++) {  // DstH is only half that of SrcH
			Byte *SrcP=(Byte *)SrcBm->ScanLine[SrcY*2];
			Byte *SrcPBelow=(Byte *)SrcBm->ScanLine[SrcY*2+1];
			Byte *DstP=(Byte *)DstBm->ScanLine[DstY];

			*DstP=0;

			for (int SrcX=0;SrcX<SrcW/2;SrcX++) {
				int SumRed,SumGreen,SumBlue;

				SumRed=*SrcP++;
				SumGreen=*SrcP++;
				SumBlue=*SrcP++;

				SumRed+=*SrcPBelow++;
				SumGreen+=*SrcPBelow++;
				SumBlue+=*SrcPBelow++;

				SumRed+=*SrcP++;
				SumGreen+=*SrcP++;
				SumBlue+=*SrcP++;

				SumRed+=*SrcPBelow++;
				SumGreen+=*SrcPBelow++;
				SumBlue+=*SrcPBelow++;

				SumRed>>=2;
				SumGreen>>=2;
				SumBlue>>=2;

				*DstP++=SumRed;
				*DstP++=SumGreen;
				*DstP++=SumBlue;
				}
			DstY++;
			}
		}
	else {
    	// with Grayscale
		for (int SrcY=0;SrcY<DstH;SrcY++) {  // DstH is only half that of SrcH
			Byte *SrcP=(Byte *)SrcBm->ScanLine[SrcY*2];
			Byte *SrcPBelow=(Byte *)SrcBm->ScanLine[SrcY*2+1];
			Byte *DstP=(Byte *)DstBm->ScanLine[DstY];

			*DstP=0;

			for (int SrcX=0;SrcX<SrcW/2;SrcX++) {
				int Sum=0;

				for (int i=0;i<6;i++) {
					Sum+=*SrcP++;
					Sum+=*SrcPBelow++;
					}

				Sum/=12;

				*DstP++=Sum;
				*DstP++=Sum;
				*DstP++=Sum;
				}
			DstY++;
			}
	}
}

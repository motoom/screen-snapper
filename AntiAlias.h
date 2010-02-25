
// AntiAlias.h
//
// Halves the size of a bitmap, blending pixels.
//
// Sofware by Michiel Overtoom, motoom@xs4all.nl
//
// Version 1.0

#ifndef AntiAliasH
#define AntiAliasH
void __fastcall AntiAlias(Graphics::TBitmap *SrcBm,Graphics::TBitmap *DstBm,bool GrayScale=false);
#endif

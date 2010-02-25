
// SplitWords.cpp
//
// Version 0.31 (22 jan 2000)

#include <vcl.h>
#pragma hdrstop
#include "SplitWords.h"
#pragma package(smart_init)

// Parse a sentence with (possibly multi-)space/splitchar-separated words into a stringlist.
void __fastcall SplitWords(const AnsiString &Source,TStringList *Dst,const char SplitChar)
{
	Dst->Clear();
	
	// Private copy of the source to tinker with.
	AnsiString Src=Source;
	
	// Prepare the split positions.
	for (int i=1;i<=Src.Length();i++) if (Src[i]==SplitChar) Src[i]='\n';
	
	// Split it into lines.
	Dst->Text=Src;

	// Condense the stringlist by deleteing out empty lines.
	int Lin=0;
	while (Lin<Dst->Count) 
		if (Dst->Strings[Lin].IsEmpty()) 
			Dst->Delete(Lin); else Lin++;
}

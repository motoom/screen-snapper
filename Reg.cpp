
// Reg.cpp
//
// Sofware by Michiel Overtoom, motoom@xs4all.nl
//
// Version 3.1, may 2004
// 3.1: Added instrumentation
// 3.0: Better default handling in GetString
//

#include <Vcl.h>
#pragma hdrstop
#include <registry.hpp>
#include "Reg.h"
#pragma package(smart_init)

#ifdef REG_INSTRUMENTATION
#include <clipbrd.hpp>
TStringList *RegLog=0;


AnsiString __fastcall Reg::ClearLog(void)
{
	if (!RegLog) RegLog=new TStringList();
	RegLog->Clear();
}

AnsiString __fastcall Reg::ShowLog(const AnsiString &Title)
{
	AnsiString Msg="The registry routines produced the following log:\n\n"+RegLog->Text+"\n\nDo you want to place this text on the clipboard so you can paste it into another application?";
	if (Application->MessageBox(Msg.c_str(),Title.c_str(),MB_YESNO)==IDYES)
		Clipboard()->AsText=RegLog->Text;
}

AnsiString __fastcall Reg::DestroyLog(void)
{
	if (RegLog) {
		delete RegLog;
		RegLog=0;
		}
}
#endif

// pure readonly; do not create anything, return default if key not found or other error
AnsiString __fastcall Reg::GetString(const AnsiString &Key,const AnsiString &Default)
{
	#ifdef REG_INSTRUMENTATION
	if (!RegLog) RegLog=new TStringList();
	#endif
	TRegistry *R=new TRegistry();
	AnsiString Section=Application->Title;
	int Dash=Section.Pos("-");
	if (Dash) Section=Section.SubString(1,Dash-1);
	Section=Section.Trim();
	if (Section.IsEmpty()) throw Exception("Reg::GetString: Application title must be set");
	AnsiString KeyName="Software\\"+Section;
	if (!R->OpenKey(KeyName,false)) {
		#ifdef REG_INSTRUMENTATION
		AnsiString S="Reg::GetString(\""+Key+"\",\""+Default+"\"): OpenKey(\""+KeyName+"\") failed, key does not exist. Returning the default, \""+Default+"\"";
		RegLog->Add(S);
		#endif
		return Default;
		}
	if (!R->ValueExists(Key)) {
		#ifdef REG_INSTRUMENTATION
		AnsiString S="Reg::GetString(\""+Key+"\",\""+Default+"\"): ValueExists(\""+Key+"\") failed, value does not exist. Returning the default, \""+Default+"\"";
		RegLog->Add(S);
		#endif
		return Default;
		}
	AnsiString Value;
	try {
		Value=R->ReadString(Key);
		#ifdef REG_INSTRUMENTATION
		AnsiString S="Reg::GetString(\""+Key+"\",\""+Default+"\"): ReadString(\""+Key+"\") succeeded. Returning \""+Value+"\"";
		RegLog->Add(S);
		#endif
		}
	catch (Exception &E) {
		Value=Default;
		#ifdef REG_INSTRUMENTATION
		AnsiString S="Reg::GetString(\""+Key+"\",\""+Default+"\"): ReadString(\""+Key+"\") failed. Returning the default, \""+Value+"\"";
		RegLog->Add(S);
		#endif
		}
	delete R;
	return Value;
}


// do the utmost to create if possible, else do nothing. But report success/failure.
bool __fastcall Reg::PutString(const AnsiString &Key,const AnsiString &Value) // static
{
	#ifdef REG_INSTRUMENTATION
	if (!RegLog) RegLog=new TStringList();
	#endif
	TRegistry *R=new TRegistry();
	AnsiString Section=Application->Title;
	int Dash=Section.Pos("-");
	if (Dash) Section=Section.SubString(1,Dash-1);
	Section=Section.Trim();
	if (Section.IsEmpty()) throw Exception("Reg::SetString: Application title must be set");
	AnsiString KeyName="Software\\"+Section;
	if (!R->OpenKey(KeyName,true)) {
		#ifdef REG_INSTRUMENTATION
		AnsiString S="Reg::PutString(\""+Key+"\",\""+Value+"\"): OpenKey(\""+KeyName+"\") failed, can't create key. Returning false";
		RegLog->Add(S);
		#endif
		return false;
		}
	bool Result;
	try {
		R->WriteString(Key,Value);
		#ifdef REG_INSTRUMENTATION
		AnsiString S="Reg::PutString(\""+Key+"\",\""+Value+"\"): WriteString(\""+Key+"\",\""+Value+"\") succeeded. Returning true";
		RegLog->Add(S);
		#endif
		Result=true;
		}
	catch (Exception &E) {
		#ifdef REG_INSTRUMENTATION
		AnsiString S="Reg::PutString(\""+Key+"\",\""+Value+"\"): WriteString(\""+Key+"\",\""+Value+"\") failed. Returning false";
		RegLog->Add(S);
		#endif
		Result=false;
		}
	delete R;
	return Result;
}


int __fastcall Reg::GetInt(const AnsiString &Key,int Default)
{
	AnsiString Value=GetString(Key);
	return StrToIntDef(Value,Default);
}

bool __fastcall Reg::PutInt(const AnsiString &Key,const int Value)
{
	return PutString(Key,AnsiString(Value));
}



bool __fastcall Reg::GetBool(const AnsiString &Key,bool Default)
{
	AnsiString Value=GetString(Key);
	if (Value.AnsiCompareIC("true")==0) return true;
	if (Value.AnsiCompareIC("false")==0) return false;
	return Default;
}


bool __fastcall Reg::PutBool(const AnsiString &Key,const bool Value)
{
	return PutString(Key,Value?"true":"false");
}


bool __fastcall Reg::PutColor(const AnsiString &Key,const TColor &Value)
{
	return PutString(Key,AnsiString(Value));
}


TColor __fastcall Reg::GetColor(const AnsiString &Key,const TColor &Default)
{
	return (TColor)StrToIntDef(GetString(Key,AnsiString(Default)),Default);
}


bool __fastcall Reg::PutFont(const AnsiString &Key,TFont *Value)
{
	AnsiString S,Attribs="";
	if (Value->Style.Contains(fsBold)) Attribs+="b";
	if (Value->Style.Contains(fsItalic)) Attribs+="i";
	if (Value->Style.Contains(fsUnderline)) Attribs+="u";
	if (Value->Style.Contains(fsStrikeOut)) Attribs+="s";
	S.printf("%s,%d,%s,%d",Value->Name.c_str(),Value->Size,Attribs.c_str(),Value->Color);
	return PutString(Key,S);
}


// Parse a sentence with (possibly multi-)space/splitchar-separated words into a stringlist.
void __fastcall Reg::SplitWords(const AnsiString &Source,TStringList *Dst,const char SplitChar)
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


bool __fastcall Reg::GetFont(const AnsiString &Key,TFont *Value,const AnsiString &Default)
{
	AnsiString S=GetString(Key,Default);
	if (S=="") return false;

	TStringList *Tmp=new TStringList;
	SplitWords(S,Tmp,',');

	if (Tmp->Count>3)
		Value->Color=(TColor)StrToIntDef(Tmp->Strings[3],clBlack);

	if (Tmp->Count>2) {
		for (int i=1;i<=Tmp->Strings[2].Length();i++) {
			switch(Tmp->Strings[2][i]) {
				case 'b': case 'B': Value->Style=Value->Style<<fsBold; break;
				case 'i': case 'I': Value->Style=Value->Style<<fsItalic; break;
				case 'u': case 'U': Value->Style=Value->Style<<fsUnderline; break;
				case 's': case 'S': Value->Style=Value->Style<<fsStrikeOut; break;
				}
			}
		}

	if (Tmp->Count>1)
		Value->Size=StrToIntDef(Tmp->Strings[1],12);

	if (Tmp->Count>0)
		Value->Name=Tmp->Strings[0];

	delete Tmp;
	return true;
}



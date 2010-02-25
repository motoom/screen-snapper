
// Files.cpp
//
// Sofware by Michiel Overtoom, motoom@xs4all.nl
//
// version 1.21 (jul 2002)
// - sorting on filename part
//
// version 1.2 (oct 2000)
// - sorting on filename and number in filename
//
// version 1.14 (jun 2000)
// - detects hidden files, too


#include <vcl.h>
#pragma hdrstop
#include <stdlib.h>
#include "Files.h"
#pragma package(smart_init)


__fastcall TFiles::TFiles()
{
	FFileList=new TStringList;
}


__fastcall TFiles::~TFiles()
{
	delete FFileList;
}


AnsiString __fastcall TFiles::EnsureBackslash(AnsiString S) // static
{
	S.Unique();
	S.Trim();
	if (S.IsEmpty()) S="\\";
	if (*S.AnsiLastChar()!='\\') S=S+"\\";
	return S;
}


void __fastcall TFiles::Clear(void)
{
	FFileList->Clear();
}


void __fastcall TFiles::Add(const AnsiString &Path,const AnsiString &Mask,bool FullName,bool Subdirectories) // Path is bv "C:\dir\", mask bv. "*.gif"
{
	TSearchRec F;
	int AllFilesProcessed=FindFirst(EnsureBackslash(Path)+Mask,faReadOnly|faHidden|faSysFile|faArchive,F);
	while (!AllFilesProcessed) {
		if (FullName)
			FFileList->Add(EnsureBackslash(Path)+F.Name);
		else
			FFileList->Add(F.Name);
		AllFilesProcessed=FindNext(F);
		}
	FindClose(F);

	// See if there are any subdirectories which must be processed too
	if (Subdirectories) {
		int AllFilesProcessed=FindFirst(EnsureBackslash(Path)+"*",faDirectory,F);
		while (!AllFilesProcessed) {
			if (F.Name!="." && F.Name!="..") {
				AnsiString SubPath=EnsureBackslash(Path)+F.Name;
				Add(SubPath,Mask,FullName,Subdirectories);
				}
			AllFilesProcessed=FindNext(F);
			}
		FindClose(F);
		}
}


void __fastcall TFiles::Sort(void)
{
	FFileList->Sort();
}


int __fastcall TFiles::ExtractNumeral(const AnsiString &Src)
{
	char *S=Src.c_str();
	while (*S) {
		if (*S>='0' && *S<='9') return atoi(S);
		S++;
		}
	return 0;
}


void __fastcall TFiles::NumericSort(void)
{
	for (int i=0;i<FFileList->Count-1;i++) {
		int Smallest=ExtractNumeral(FFileList->Strings[i]);
		int SmallestPos=i;
		for (int j=i+1;j<FFileList->Count;j++) {
			int Candidate=ExtractNumeral(FFileList->Strings[j]);
			if (Candidate<Smallest) {
				Smallest=Candidate;
				SmallestPos=j;
				}
			}
		if (SmallestPos!=i)
			FFileList->Exchange(i,SmallestPos);
		}
}


void __fastcall TFiles::FilenameSort(void)
{
	for (int i=0;i<FFileList->Count-1;i++) {
		AnsiString Smallest=ExtractFileName(FFileList->Strings[i]);
		int SmallestPos=i;
		for (int j=i+1;j<FFileList->Count;j++) {
			AnsiString Candidate=ExtractFileName(FFileList->Strings[j]);
			if (Candidate<Smallest) {
				Smallest=Candidate;
				SmallestPos=j;
				}
			}
		if (SmallestPos!=i)
			FFileList->Exchange(i,SmallestPos);
		}
}


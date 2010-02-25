
// Files.h
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

#ifndef FilesH
#define FilesH

class TFiles {
  public:
	static AnsiString __fastcall EnsureBackslash(AnsiString S);
	__fastcall TFiles();
	__fastcall ~TFiles();
	void __fastcall Clear(void);
	void __fastcall Add(const AnsiString &Path,const AnsiString &Mask="*.*",bool FullName=true,bool Subdirectories=false);
	void __fastcall Sort(void);
	void __fastcall NumericSort(void);
	void __fastcall FilenameSort(void);
	int __fastcall ExtractNumeral(const AnsiString &Src);
	//
	__property TStringList *Filelist={read=FFileList};

  private:
	TStringList *FFileList;
	};

#endif


// Reg.h
//
// Sofware by Michiel Overtoom, motoom@xs4all.nl
//
// Version 3.1, may 2004
// 3.1: Added instrumentation
// 3.0: Better default handling in GetString
//

#ifndef RegH
#define RegH

// Define this one for chatty messageboxes during execution of routines
// #define REG_INSTRUMENTATION

#ifdef REG_INSTRUMENTATION
extern TStringList *RegLog;
#endif

class Reg {
  public:

	#ifdef REG_INSTRUMENTATION
	static AnsiString __fastcall ClearLog(void);
	static AnsiString __fastcall ShowLog(const AnsiString &Title);
	static AnsiString __fastcall DestroyLog(void);
	#endif

	static AnsiString __fastcall GetString(const AnsiString &Key,const AnsiString &Default="");
	static bool __fastcall PutString(const AnsiString &Key,const AnsiString &Value);

	static int __fastcall GetInt(const AnsiString &Key,int Default=0);
	static bool __fastcall PutInt(const AnsiString &Key,const int Value);

	static bool __fastcall GetBool(const AnsiString &Key,bool Default=false);
	static bool __fastcall PutBool(const AnsiString &Key,const bool Value);

	static bool __fastcall PutColor(const AnsiString &Key,const TColor &Value);
	static TColor __fastcall GetColor(const AnsiString &Key,const TColor &Default);

	static bool __fastcall PutFont(const AnsiString &Key,TFont *Value);
	static bool __fastcall GetFont(const AnsiString &Key,TFont *Value, const AnsiString &Default);

	static void __fastcall SplitWords(const AnsiString &Source,TStringList *Dst,const char SplitChar);
	};
#endif


#ifndef BrowseForFolderDialogH
#define BrowseForFolderDialogH

#include <SysUtils.hpp>
#include <Controls.hpp>
#include <Classes.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>

class PACKAGE TBrowseForFolderDialog : public TCommonDialog
{
private:
protected:
	static int CALLBACK SetSelProc(HWND hWnd,UINT uMsg,LPARAM lParam,LPARAM lpData);
	AnsiString FFolder,FTitle;
public:
	__fastcall TBrowseForFolderDialog(TComponent* Owner);
	virtual bool __fastcall Execute(void);
__published:
	__property AnsiString Title={read=FTitle,write=FTitle};
	__property AnsiString Folder={read=FFolder,write=FFolder};

};

#endif

#include <vcl.h>
#pragma hdrstop
#include <shlobj.h>
#include "BrowseForFolderDialog.h"

#pragma package(smart_init)


__fastcall TBrowseForFolderDialog::TBrowseForFolderDialog(TComponent* Owner) : TCommonDialog(Owner)
{
}


int CALLBACK TBrowseForFolderDialog::SetSelProc(HWND hWnd,UINT uMsg,LPARAM lParam,LPARAM lpData) // static
{
	if (uMsg==BFFM_INITIALIZED) SendMessage(hWnd,BFFM_SETSELECTION,TRUE,lpData);
	return 0;
}


bool __fastcall TBrowseForFolderDialog::Execute(void)
{
	LPMALLOC g_pMalloc;
	SHGetMalloc(&g_pMalloc);

	char folderbuffer[MAX_PATH];
	strcpy(folderbuffer,FFolder.c_str());
	int Len=strlen(folderbuffer);
	if (folderbuffer[Len-1]=='\\') folderbuffer[Len-1]=0;

	// Fill BROWSEINFO
	BROWSEINFO info;
	ZeroMemory(&info,sizeof(info));
	info.hwndOwner		= GetActiveWindow();
	info.pszDisplayName = folderbuffer;
	info.lpszTitle		= Title.c_str();
	info.ulFlags		= BIF_RETURNONLYFSDIRS;
	info.lpfn			= SetSelProc;
	info.lParam			= (LPARAM)(LPCSTR)folderbuffer;

	LPITEMIDLIST lpitem=SHBrowseForFolder(&info);
	if (!lpitem) return false;

	// Convert the ITEMIDLIST to the complete folder name
	if (!SHGetPathFromIDList(lpitem,folderbuffer)) return false;

	g_pMalloc->Free(lpitem);

	FFolder=folderbuffer;
	return true;
}


namespace Browseforfolderdialog
{
	void __fastcall PACKAGE Register()
	{
		TComponentClass classes[1] = {__classid(TBrowseForFolderDialog)};
		RegisterComponents("Ovosoft", classes, 0);
	}
}



// ActivateExistingRunningInstance.cpp
//
// Part of ScreenSnapper, a Windows utility to make screenshots and save them as JPG
//
// Enumerates the toplevel windows to see wether Snapper is already running.
// If it is, activates the running instance (actually, it displays only a message at the moment)
//
// Sofware by Michiel Overtoom, motoom@xs4all.nl


#include <vcl.h>
#pragma hdrstop
#include "ActivateExistingRunningInstance.h"
#pragma package(smart_init)

struct EnumInfoStruct {
	AnsiString WindowClassName;
	AnsiString StartsWithTitle;
	HWND OurSelf;
	HWND Found;
	};


BOOL CALLBACK EnumWindowsProc(HWND hwnd,LPARAM lParam)
{
	char Class[1024];
	GetClassName(hwnd,Class,sizeof(Class)-1);
	char Title[1024];
	GetWindowText(hwnd,Title,sizeof(Title)-1);
	// HINSTANCE Instance=(HINSTANCE)GetWindowLong(hwnd,GWL_HINSTANCE);
	// ShowMessage(AnsiString(Class)+"\n"+AnsiString(Title));
	EnumInfoStruct *Ei=(EnumInfoStruct *)lParam;
	if (AnsiString(Class)==Ei->WindowClassName  &&
		strnicmp(Title,Ei->StartsWithTitle.c_str(),Ei->StartsWithTitle.Length())==0) {
			if (hwnd!=Ei->OurSelf) {
				Ei->Found=hwnd;
				return false;
				}
			}
	return true;
}


ActivateExistingRunningInstance(HWND OurSelf,const AnsiString &WindowClassName,const AnsiString &StartsWithTitle)
{
	EnumInfoStruct Ei;
	Ei.WindowClassName=WindowClassName;
	Ei.StartsWithTitle=StartsWithTitle;
	Ei.OurSelf=OurSelf;
	Ei.Found=0;
	EnumWindows((WNDENUMPROC)EnumWindowsProc,(LPARAM)&Ei);
	if (Ei.Found) {
        ShowMessage("Snapper is already running.\n\nLook for it on the taskbar,\nor in the system tray (at the bottom of the screen).");
		// ShowWindow(Ei.Found,SW_RESTORE); // PostMessage(Ei.Found,WM_SHOW,0,0);
		return true;
		}
	return false;
}


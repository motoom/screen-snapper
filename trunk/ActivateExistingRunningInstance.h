
// ActivateExistingRunningInstance.cpp
//
// Part of ScreenSnapper, a Windows utility to make screenshots and save them as JPG
//
// Enumerates the toplevel windows to see wether Snapper is already running.
// If it is, activates the running instance (actually, it displays only a message at the moment)
//
// Sofware by Michiel Overtoom, motoom@xs4all.nl

#ifndef ActivateExistingRunningInstanceH
#define ActivateExistingRunningInstanceH
ActivateExistingRunningInstance(HWND OurSelf,const AnsiString &WindowClassName,const AnsiString &StartsWithTitle);
#endif

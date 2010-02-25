
// Snapper.cpp
//
// Sofware by Michiel Overtoom, motoom@xs4all.nl, 2004-2010
//

#include <vcl.h>
#pragma hdrstop

USEFORM("ScreenSnapperForm.cpp", ScreenSnapper);
USEFORM("MainForm.cpp", Main);
USEUNIT("AntiAlias.cpp");
USERC("ScreenSnapperSounds.rc");
USEUNIT("Reg.cpp");
USEUNIT("Files.cpp");
USEFORM("ImgViewerForm.cpp", ImgViewer);
USEUNIT("SplitWords.cpp");
USEUNIT("BrowseForFolderDialog.cpp");
USERES("Snapper.res");
USEUNIT("ActivateExistingRunningInstance.cpp");
USEUNIT("..\Jpeglib\JpegVclGlue.cpp");
USELIB("..\Jpeglib\Jpeglib.lib");

WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	try
	{
		Application->Initialize();
		Application->Title = "Snapper";
		Application->CreateForm(__classid(TMain), &Main);
		Application->CreateForm(__classid(TImgViewer), &ImgViewer);
		Application->CreateForm(__classid(TScreenSnapper), &ScreenSnapper);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	return 0;
}


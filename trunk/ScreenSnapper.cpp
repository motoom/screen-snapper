
#include <vcl.h>
#pragma hdrstop
USERES("ScreenSnapper.res");
USEFORM("ScreenSnapperForm.cpp", Snapper);
USEFORM("MainForm.cpp", Main);
USEUNIT("AntiAlias.cpp");
USERC("ScreenSnapperSounds.rc");
USEUNIT("Reg.cpp");
USEUNIT("Files.cpp");
USEFORM("ImgViewerForm.cpp", ImgViewer);

WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	try
	{
		Application->Initialize();
		Application->Title = "ScreenSnapper";
		Application->CreateForm(__classid(TMain), &Main);
		Application->CreateForm(__classid(TSnapper), &Snapper);
		Application->CreateForm(__classid(TImgViewer), &ImgViewer);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	return 0;
}


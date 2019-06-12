#include <wx/wx.h>
#include "ProjektGFKMainFrame.h"

class MyApp : public wxApp {

public:

	virtual bool OnInit();
	virtual int OnExit() { return 0; }
};

IMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
	wxFrame *mainFrame = new ProjektGFKMainFrame(NULL);
	mainFrame->SetIcon(wxICON(AAAAAppicon));
	mainFrame->Show(true);
	SetTopWindow(mainFrame);

	return true;
}
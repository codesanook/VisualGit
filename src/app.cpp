#include "pch.h"
#include "app.h"
#include "mainframe.h"

IMPLEMENT_DYNAMIC_CLASS(App, wxApp)

BEGIN_EVENT_TABLE(App, wxApp)
END_EVENT_TABLE()

App::App()
{
}

App::~App()
{
}

wxString App::GetIconFileName(const wxString& name, int width, int height)
{
    wxFileName filename = wxFileName::DirName(wxStandardPaths::Get().GetResourcesDir());

    filename.AppendDir(wxT("icons"));
    filename.AppendDir(wxString::Format(wxT("%dx%d"), width, height));
    filename.SetFullName(name);

    return filename.GetFullPath();
}

bool App::OnInit()
{
    if ( !wxApp::OnInit() )
        return false;
    
    wxInitAllImageHandlers();

    MainFrame *frame = new MainFrame(_("Visual Git"));
    frame->Show(true);
    SetTopWindow(frame);

    return true;
}

IMPLEMENT_APP(App)

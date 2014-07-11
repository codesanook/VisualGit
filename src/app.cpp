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

bool App::OnInit()
{
    if ( !wxApp::OnInit() )
        return false;

    MainFrame *frame = new MainFrame(_("Visual Git"));
    frame->Show(true);
    SetTopWindow(frame);

    return true;
}

IMPLEMENT_APP(App)

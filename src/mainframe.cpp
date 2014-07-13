#include "pch.h"
#include "mainframe.h"
#include "app.h"

IMPLEMENT_DYNAMIC_CLASS(MainFrame, wxFrame)

BEGIN_EVENT_TABLE(MainFrame, wxFrame)
END_EVENT_TABLE()

MainFrame::MainFrame()
{
}

MainFrame::MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
        : wxFrame((wxFrame *) NULL, wxID_ANY, title, pos, size)
{
    // set icons
    wxIconBundle icons;
    icons.AddIcon(App::GetIconFileName(wxT("visualgit.png"), 16, 16), wxBITMAP_TYPE_PNG);
    icons.AddIcon(App::GetIconFileName(wxT("visualgit.png"), 32, 32), wxBITMAP_TYPE_PNG);
    icons.AddIcon(App::GetIconFileName(wxT("visualgit.png"), 48, 48), wxBITMAP_TYPE_PNG);
    SetIcons(icons);
}

MainFrame::~MainFrame()
{
}

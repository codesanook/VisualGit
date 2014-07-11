#include "pch.h"
#include "mainframe.h"

IMPLEMENT_DYNAMIC_CLASS(MainFrame, wxFrame)

BEGIN_EVENT_TABLE(MainFrame, wxFrame)
END_EVENT_TABLE()

MainFrame::MainFrame()
{
}

MainFrame::MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
        : wxFrame((wxFrame *) NULL, wxID_ANY, title, pos, size)
{
}

MainFrame::~MainFrame()
{
}

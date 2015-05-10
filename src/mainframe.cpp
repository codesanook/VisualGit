#include "pch.h"
#include "mainframe.h"
#include "app.h"
#include "clonedialog.h"

enum
{
    ID_START = wxID_HIGHEST,
    ID_GIT_CLONE
};

IMPLEMENT_DYNAMIC_CLASS(MainFrame, wxFrame)

BEGIN_EVENT_TABLE(MainFrame, wxFrame)
    EVT_MENU    (ID_GIT_CLONE,  MainFrame::OnCloneGitRepository)
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

    InitStatusBar();
    InitMenuBar();
    InitToolBar();
    InitSplitter();
}

MainFrame::~MainFrame()
{
}

void MainFrame::InitMenuBar()
{
    wxMenuBar *menuBar = new wxMenuBar();
    wxMenu *menus;

    // Git
    menus = new wxMenu();
    menus->Append(ID_GIT_CLONE, _("Clone..."), _("Clone a git repository"));
    menuBar->Append(menus, _("Git"));

    // Help
    menus = new wxMenu();
    menus->Append(wxID_ABOUT, _("About"), _("View information about VisualGit"));
    menuBar->Append(menus, _("Help"));

    SetMenuBar(menuBar);
}

void MainFrame::InitRepositoriesWindow()
{
    m_repositories = new wxTreeCtrl(m_splitter);
}

void MainFrame::InitRepositoryWindows()
{
    m_emptyView = new wxPanel(m_splitter);
}

void MainFrame::InitSplitter()
{
    m_splitter = new wxSplitterWindow(this);
    InitRepositoriesWindow();
    InitRepositoryWindows();
    m_splitter->SplitVertically(m_repositories, m_emptyView);
    m_splitter->SetMinimumPaneSize(100);
}

void MainFrame::InitStatusBar()
{
    wxStatusBar *statusBar = CreateStatusBar();
}

void MainFrame::InitToolBar()
{
    wxToolBar *toolBar = CreateToolBar();
}

void MainFrame::OnCloneGitRepository(wxCommandEvent& WXUNUSED(event))
{
    CloneDialog cloneDialog(this);
    if ( cloneDialog.ShowModal() != wxID_OK )
        return;
}

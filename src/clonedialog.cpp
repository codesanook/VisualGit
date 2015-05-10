#include "pch.h"
#include "clonedialog.h"

enum
{
    ID_START = wxID_HIGHEST,
    ID_BROWSE_DEST
};

IMPLEMENT_DYNAMIC_CLASS(CloneDialog, wxDialog)

BEGIN_EVENT_TABLE(CloneDialog, wxDialog)
END_EVENT_TABLE()

CloneDialog::CloneDialog()
{
}

CloneDialog::CloneDialog(wxWindow *parent, const wxPoint& pos)
    : wxDialog(parent, wxID_ANY, _("Clone Git Repository"), pos)
{
    InitControls();
    m_target->SetFocus();
}

void CloneDialog::InitControls()
{
    wxBoxSizer *mainSizer = new wxBoxSizer(wxVERTICAL);
    InitGitCloningControls(mainSizer);
    InitDialogButtons(mainSizer);
    SetSizerAndFit(mainSizer);
}

void CloneDialog::InitDialogButtons(wxSizer *mainSizer)
{
    wxSizer *sizer = CreateButtonSizer(wxOK | wxCANCEL);
    if ( sizer )
        mainSizer->Add(sizer, 0, wxBOTTOM | wxLEFT | wxRIGHT | wxEXPAND, 3);
}

void CloneDialog::InitGitCloningControls(wxSizer *mainSizer)
{
    wxGridBagSizer *sizer = new wxGridBagSizer(5, 6);
    wxStaticText *label;
    wxButton *button;

    // repository to clone
    label = new wxStaticText(this, wxID_ANY, _("Repository to clone:"));
    sizer->Add(label, wxGBPosition(0, 0), wxDefaultSpan, wxALIGN_CENTER_VERTICAL);
    m_target = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(300, -1));
    sizer->Add(m_target, wxGBPosition(0, 1), wxGBSpan(1, 2), wxEXPAND | wxALIGN_CENTER_VERTICAL);

    // target directory
    label = new wxStaticText(this, wxID_ANY, _("Destination directory:"));
    sizer->Add(label, wxGBPosition(1, 0), wxDefaultSpan, wxALIGN_CENTER_VERTICAL);
    m_dest = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(300, -1));
    sizer->Add(m_dest, wxGBPosition(1, 1), wxDefaultSpan, wxALIGN_CENTER_VERTICAL);
    button = new wxButton(this, ID_BROWSE_DEST, _("Browse..."));
    sizer->Add(button, wxGBPosition(1, 2), wxDefaultSpan, wxALIGN_CENTER_VERTICAL);

    mainSizer->Add(sizer, 0, wxALL | wxEXPAND, 7);
}

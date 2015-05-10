#ifndef CLONEDIALOG_H
#define CLONEDIALOG_H

class CloneDialog : public wxDialog
{
public:
    CloneDialog();
    CloneDialog(wxWindow *parent, const wxPoint& pos = wxDefaultPosition);

private:
    void InitControls();
    void InitDialogButtons(wxSizer *mainSizer);
    void InitGitCloningControls(wxSizer *mainSizer);

    wxTextCtrl *m_target;
    wxTextCtrl *m_dest;

    DECLARE_EVENT_TABLE()
    DECLARE_DYNAMIC_CLASS_NO_COPY(CloneDialog)
};

#endif // CLONEDIALOG_H

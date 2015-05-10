#ifndef MAINFRAME_H
#define MAINFRAME_H

class MainFrame : public wxFrame
{
public:
    MainFrame();
    MainFrame(const wxString& title,
              const wxPoint& pos = wxDefaultPosition,
              const wxSize& size = wxDefaultSize);
    virtual ~MainFrame();

private:
    void InitMenuBar();

    DECLARE_EVENT_TABLE()
    DECLARE_DYNAMIC_CLASS_NO_COPY(MainFrame)
};

#endif // MAINFRAME_H

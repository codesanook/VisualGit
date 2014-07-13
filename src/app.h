#ifndef APP_H
#define APP_H

class App : public wxApp
{
public:
    App();
    virtual ~App();

    static wxString GetIconFileName(const wxString& name, int width, int height);

    virtual bool OnInit();

private:
    DECLARE_EVENT_TABLE()
    DECLARE_DYNAMIC_CLASS_NO_COPY(App)
};

DECLARE_APP(App)

#endif // APP_H

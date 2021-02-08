/***************************************************************
 * Name:      TestMain.h
 * Purpose:   Defines Application Frame
 * Author:    vivek (raovivekkumar11@gmail.com)
 * Created:   2021-02-04
 * Copyright: vivek ()
 * License:
 **************************************************************/

#ifndef TESTMAIN_H
#define TESTMAIN_H

#include <wx/stc/stc.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/stattext.h>
#include <wx/statusbr.h>
#include <wx/textctrl.h>

class TestFrame: public wxFrame {
    public:

        TestFrame(wxWindow * parent, wxWindowID id = -1);
    virtual~TestFrame();

    private:

    void OnQuit(wxCommandEvent & event);
    void OnAbout(wxCommandEvent & event);
    void OnButton3Click(wxCommandEvent & event);
    void OnButton2Click(wxCommandEvent & event);
    void OnButton4Click(wxCommandEvent & event);
    void OnButton5Click(wxCommandEvent & event);
    void OnButton1Click(wxCommandEvent & event);

    static const long ID_TEXTCTRL1;
    static const long ID_BUTTON1;
    static const long ID_BUTTON2;
    static const long ID_BUTTON3;
    static const long ID_BUTTON4;
    static const long ID_TEXTCTRL2;
    static const long ID_BUTTON5;
    static const long ID_STATICTEXT1;
    static const long ID_PANEL1;
    static const long ID_MENUITEM1;
    static const long idMenuAbout;
    static const long ID_STATUSBAR1;
    wxButton * Button1;
    wxButton * Button2;
    wxButton * Button3;
    wxButton * Button4;
    wxButton * Button5;
    wxPanel * Panel1;
    wxStaticText * StaticText1;
    wxStatusBar * StatusBar1;
    wxTextCtrl * TextCtrl1;
    wxTextCtrl * TextCtrl2;

    DECLARE_EVENT_TABLE()
};

#endif // TESTMAIN_H

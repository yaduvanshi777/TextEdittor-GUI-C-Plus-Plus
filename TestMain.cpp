/***************************************************************
 * Name:      TestMain.cpp
 * Purpose:   Defines Application Frame
 * Author:    vivek (raovivekkumar11@gmail.com)
 * Created:   2021-02-04
 * Copyright: vivek ()
 * License:
 **************************************************************/

#include "TestMain.h"
#include <wx/msgdlg.h>
#include <wx/string.h>
#include <wx/dataobj.h>
#include <wx/clipbrd.h>
#include <wx/file.h>
#include <wx/stc/stc.h>
#include <wx/artprov.h>
#include <wx/bitmap.h>
#include <wx/font.h>
#include <wx/icon.h>
#include <wx/image.h>
#include <wx/intl.h>
#include <wx/settings.h>
#include <wx/string.h>

enum wxbuildinfoformat {
    short_f,
    long_f
};

wxString wxbuildinfo(wxbuildinfoformat format) {
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f) {
        #if defined(__WXMSW__)
        wxbuild << _T("-Windows");
        #elif defined(__UNIX__)
        wxbuild << _T("-Linux");
        #endif

        #if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
        #else
        wxbuild << _T("-ANSI build");
        #endif // wxUSE_UNICODE
    }

    return wxbuild;
}

const long TestFrame::ID_TEXTCTRL1 = wxNewId();
const long TestFrame::ID_BUTTON1 = wxNewId();
const long TestFrame::ID_BUTTON2 = wxNewId();
const long TestFrame::ID_BUTTON3 = wxNewId();
const long TestFrame::ID_BUTTON4 = wxNewId();
const long TestFrame::ID_TEXTCTRL2 = wxNewId();
const long TestFrame::ID_BUTTON5 = wxNewId();
const long TestFrame::ID_STATICTEXT1 = wxNewId();
const long TestFrame::ID_PANEL1 = wxNewId();
const long TestFrame::ID_MENUITEM1 = wxNewId();
const long TestFrame::idMenuAbout = wxNewId();
const long TestFrame::ID_STATUSBAR1 = wxNewId();

BEGIN_EVENT_TABLE(TestFrame, wxFrame)
END_EVENT_TABLE()

TestFrame::TestFrame(wxWindow * parent, wxWindowID id) {
    wxTheClipboard -> Open();
    wxMenu * Menu1;
    wxMenu * Menu2;
    wxMenuBar * MenuBar1;
    wxMenuItem * MenuItem1;
    wxMenuItem * MenuItem2;

    Create(parent, wxID_ANY, _("Text Editor"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(1080, 512));
    SetMinSize(wxSize(1080, 600));
    SetMaxSize(wxSize(1080, 600)); {
        wxIcon FrameIcon;
        FrameIcon.CopyFromBitmap(wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_HELP_PAGE")), wxART_FRAME_ICON));
        SetIcon(FrameIcon);
    }

    Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(0, 24), wxSize(1000, 500), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    Panel1 -> SetMinSize(wxSize(1000, 500));
    Panel1 -> SetMaxSize(wxSize(-1, -1));
    Panel1 -> SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNSHADOW));

    TextCtrl1 = new wxTextCtrl(Panel1, ID_TEXTCTRL1, wxEmptyString, wxPoint(112, 64), wxSize(960, 448), wxTE_MULTILINE | wxTE_RICH | wxTE_RICH2 | wxTE_AUTO_URL | wxTE_NOHIDESEL | wxTE_LEFT | wxTE_DONTWRAP | wxBORDER_DOUBLE | wxBORDER_SUNKEN | wxTAB_TRAVERSAL | wxNO_FULL_REPAINT_ON_RESIZE | wxVSCROLL | wxALWAYS_SHOW_SB, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    //    StyledTextCtrl1 = new wxStyledTextCtrl(Panel1, ID_TEXTCTRL1, wxPoint(112,64), wxSize(960,448));

    wxFont TextCtrl1Font(12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, _T("Sans"), wxFONTENCODING_DEFAULT);
    TextCtrl1 -> SetFont(TextCtrl1Font);
    TextCtrl1 -> SetToolTip(_("insert text here"));
    Button1 = new wxButton(Panel1, ID_BUTTON1, _("Save"), wxPoint(16, 72), wxDefaultSize, wxTAB_TRAVERSAL, wxDefaultValidator, _T("ID_BUTTON1"));
    Button1 -> SetToolTip(_("save text from editor"));
    Button2 = new wxButton(Panel1, ID_BUTTON2, _("Clear"), wxPoint(16, 120), wxDefaultSize, wxTAB_TRAVERSAL, wxDefaultValidator, _T("ID_BUTTON2"));
    Button2 -> SetToolTip(_("clear text from editor"));
    Button3 = new wxButton(Panel1, ID_BUTTON3, _("Copy"), wxPoint(16, 168), wxSize(-1, -1), wxTAB_TRAVERSAL, wxDefaultValidator, _T("ID_BUTTON3"));
    Button3 -> SetToolTip(_("copy text from editor to clipboard"));
    Button4 = new wxButton(Panel1, ID_BUTTON4, _("Exit"), wxPoint(16, 280), wxDefaultSize, wxTAB_TRAVERSAL, wxDefaultValidator, _T("ID_BUTTON4"));
    Button4 -> SetToolTip(_("exit from application"));
    TextCtrl2 = new wxTextCtrl(Panel1, ID_TEXTCTRL2, _("abc.txt"), wxPoint(160, 16), wxSize(192, 30), wxBORDER_STATIC | wxTAB_TRAVERSAL, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    Button5 = new wxButton(Panel1, ID_BUTTON5, _("Paste"), wxPoint(16, 216), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON5"));

    StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("File Name"), wxPoint(40, 24), wxSize(112, 17), 0, _T("ID_STATICTEXT1"));

    StaticText1 -> SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOWTEXT));
    wxFont StaticText1Font(13, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, _T("Saab"), wxFONTENCODING_DEFAULT);
    StaticText1 -> SetFont(StaticText1Font);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, ID_MENUITEM1, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1 -> Append(MenuItem1);
    MenuBar1 -> Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2 -> Append(MenuItem2);
    MenuBar1 -> Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = {
        -1
    };
    int __wxStatusBarStyles_1[1] = {
        wxSB_NORMAL
    };
    StatusBar1 -> SetFieldsCount(1, __wxStatusBarWidths_1);
    StatusBar1 -> SetStatusStyles(1, __wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    Center();

    Connect(ID_BUTTON1, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction) & TestFrame::OnButton1Click);
    Connect(ID_BUTTON2, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction) & TestFrame::OnButton2Click);
    Connect(ID_BUTTON3, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction) & TestFrame::OnButton3Click);
    Connect(ID_BUTTON4, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction) & TestFrame::OnButton4Click);
    Connect(ID_BUTTON5, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction) & TestFrame::OnButton5Click);
    Connect(ID_MENUITEM1, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction) & TestFrame::OnQuit);
    Connect(idMenuAbout, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction) & TestFrame::OnAbout);
}

TestFrame::~TestFrame() {
    wxTheClipboard -> Close();
}

void TestFrame::OnQuit(wxCommandEvent & event) {
    Close();
}

void TestFrame::OnAbout(wxCommandEvent & event) {
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void TestFrame::OnButton3Click(wxCommandEvent & event) {
    wxTextDataObject * data = new wxTextDataObject(TextCtrl1 -> GetValue());
    wxTheClipboard -> SetData(data);
}

void TestFrame::OnButton2Click(wxCommandEvent & event) {
    wxString val = wxT("");
    TextCtrl1 -> SetValue(val);
}

void TestFrame::OnButton4Click(wxCommandEvent & event) {
    Close();
}

void TestFrame::OnButton5Click(wxCommandEvent & event) {
    if (wxTheClipboard -> IsSupported(wxDF_TEXT)) {
        wxTextDataObject data;
        wxTheClipboard -> GetData(data);
        TextCtrl1 -> SetValue(data.GetText());
    }
}

void TestFrame::OnButton1Click(wxCommandEvent & event) {
    wxString text = TextCtrl1 -> GetValue();
    wxString file_name = TextCtrl2 -> GetValue();
    file_name = file_name.Trim();
    if (file_name == wxT(""))
        file_name = "Untitled";
    wxFile * file = new wxFile(file_name, wxFile::write);
    file -> Write(text);
    file -> Close();
}

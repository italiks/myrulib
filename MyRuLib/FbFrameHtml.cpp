#include "FbFrameHtml.h"
#include "FbDatabase.h"
#include "FbConst.h"
#include "FbParams.h"
#include "FbMainMenu.h"
#include "BaseThread.h"
#include "MyRuLibApp.h"
#include "InfoCash.h"
#include <wx/wfstream.h>
#include <wx/txtstrm.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/textctrl.h>

BEGIN_EVENT_TABLE(FbFrameHtml, wxAuiMDIChildFrame)
    EVT_MENU(ID_HTML_SUBMIT, FbFrameHtml::OnComment)
    EVT_MENU(ID_BOOKINFO_UPDATE, FbFrameHtml::OnInfoUpdate)
    EVT_MENU(wxID_SAVE, FbFrameHtml::OnSave)
END_EVENT_TABLE()

wxString FbFrameHtml::GetMd5sum(const int id)
{
	FbCommonDatabase database;
	wxString sql = wxT("SELECT md5sum FROM books WHERE id=?");
	wxSQLite3Statement stmt = database.PrepareStatement(sql);
	stmt.Bind(1, id);
	wxSQLite3ResultSet res = stmt.ExecuteQuery();
	if (res.NextRow())
		return res.GetString(0);
	else
		return wxEmptyString;
}

FbFrameHtml::FbFrameHtml(wxAuiMDIParentFrame * parent, BookTreeItemData & data)
    :wxAuiMDIChildFrame(parent, ID_FRAME_HTML, _("Комментарии")),
    m_id(data.GetId()),
    m_md5sum(GetMd5sum(m_id)),
    m_type(data.file_type)
{
	CreateControls();
	InfoCash::UpdateInfo(this, m_id, m_type, false);
}

void FbFrameHtml::Load(const wxString & html)
{
	m_info.SetPage(html);
    m_info.SetFocus();
}

void FbFrameHtml::CreateControls()
{
	SetMenuBar(new FbMainMenu);

	wxBoxSizer * sizer = new wxBoxSizer(wxVERTICAL);
	SetSizer(sizer);

	wxSplitterWindow * splitter = new wxSplitterWindow(this, wxID_ANY, wxDefaultPosition, wxSize(500, 400), wxSP_3D);
	splitter->SetMinimumPaneSize(80);
	splitter->SetSashGravity(1);
	sizer->Add(splitter, 1, wxEXPAND);

	m_info.Create(splitter, wxID_ANY);

	wxPanel * panel = new wxPanel( splitter, wxID_ANY, wxDefaultPosition, wxSize(-1, 80), wxTAB_TRAVERSAL );
	wxBoxSizer * bSizerComment = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizerSubject;
	bSizerSubject = new wxBoxSizer( wxHORIZONTAL );

	wxStaticText * staticText = new wxStaticText( panel, wxID_ANY, wxT("Комментарий:"), wxDefaultPosition, wxDefaultSize, 0 );
	staticText->Wrap( -1 );
	bSizerSubject->Add( staticText, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_Caption = new wxTextCtrl( panel, ID_HTML_CAPTION, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizerSubject->Add( m_Caption, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	wxToolBar * toolbar = new wxToolBar( panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTB_FLAT|wxTB_HORIZONTAL|wxTB_NODIVIDER|wxTB_NOICONS|wxTB_TEXT );
	toolbar->AddTool( ID_HTML_SUBMIT, wxT("Добавить"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString );
	toolbar->Realize();

	bSizerSubject->Add( toolbar, 0, wxALIGN_CENTER_VERTICAL, 5 );

	bSizerComment->Add( bSizerSubject, 0, wxEXPAND, 5 );

	m_Comment = new wxTextCtrl( panel, ID_HTML_COMMENT, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_WORDWRAP );
	bSizerComment->Add( m_Comment, 1, wxEXPAND|wxBOTTOM|wxRIGHT|wxLEFT, 5 );

	panel->SetSizer( bSizerComment );
	panel->Layout();
	bSizerComment->Fit( panel );

	splitter->SplitHorizontally(&m_info, panel, GetClientRect().y - 150);

	SetSizer(sizer);
	Layout();
}

void FbFrameHtml::OnSave(wxCommandEvent& event)
{
    wxFileDialog dlg (
		this,
		_("Выберите файл для экспорта отчета"),
		wxEmptyString,
		wxT("lib_info.html"),
		_("Файы HTML (*.html; *.htm)|*.html;*.HTML;*.HTM;*.htm|Все файлы (*.*)|*.*"),
		wxFD_SAVE | wxFD_OVERWRITE_PROMPT
    );

	if (dlg.ShowModal() == wxID_OK) {
   		wxString html = * m_info.GetParser()->GetSource();
        wxFileOutputStream stream(dlg.GetPath());
        wxTextOutputStream text(stream);
		text.WriteString(html);
	}

}

void FbFrameHtml::OnInfoUpdate(wxCommandEvent& event)
{
	if (event.GetInt() == m_id) {
		wxString html = event.GetString() + GetComments();
		m_info.SetPage(html);
//		wxMessageBox(html);
	}
}

wxString FbFrameHtml::GetComments()
{
	wxString sql = wxT("SELECT id, posted, caption, comment FROM comments WHERE md5sum=? ORDER BY id");

	FbDatabase & database = wxGetApp().GetConfigDatabase();
	wxSQLite3Statement stmt = database.PrepareStatement(sql);
	stmt.Bind(1, m_md5sum);
	wxSQLite3ResultSet res = stmt.ExecuteQuery();

	wxString html;
	html += wxT("<TR><TD>");
	html += wxT("<TABLE>");

	while (res.NextRow()) {
		html += wxString::Format(wxT("<TR><TD><B>%s: %s</B></TD></TR>"), res.GetString(1).c_str(), res.GetString(2).c_str());
		html += wxString::Format(wxT("<TR><TD>%s</TD></TR>"), res.GetString(3).c_str());
	}

	html += wxT("</TR></TD>");
	html += wxT("</TABLE></TABLE></BODY></HTML>");
	return html;
}

void FbFrameHtml::OnComment(wxCommandEvent& event)
{
	wxString caption = m_Caption->GetValue();
	wxString comment = m_Comment->GetValue();
	if ( caption.IsEmpty() && comment.IsEmpty() ) return;

	wxString sql = wxT("INSERT INTO comments(id, md5sum, posted, caption, comment) VALUES (?,?,?,?,?)");

	FbDatabase & database = wxGetApp().GetConfigDatabase();
	int id = database.NewId(FB_NEW_COMMENT);
	wxSQLite3Statement stmt = database.PrepareStatement(sql);
	stmt.Bind(1, id);
	stmt.Bind(2, m_md5sum);
	stmt.Bind(3, wxDateTime::Now().FormatISODate() + wxT(" ") + wxDateTime::Now().FormatISOTime());
	stmt.Bind(4, caption);
	stmt.Bind(5, comment);
	stmt.ExecuteUpdate();

	m_Caption->SetValue(wxEmptyString);
	m_Comment->SetValue(wxEmptyString);

	InfoCash::UpdateInfo(this, m_id, m_type, false);
}
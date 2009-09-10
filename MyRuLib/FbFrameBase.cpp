#include "FbFrameBase.h"
#include <wx/artprov.h>
#include "FbConst.h"

FbFrameBase::FbFrameBase()
{
}

FbFrameBase::FbFrameBase(wxAuiMDIParentFrame * parent, wxWindowID id, const wxString & title)
{
	Create(parent, id, title);
}

bool FbFrameBase::Create(wxAuiMDIParentFrame * parent, wxWindowID id, const wxString & title)
{
	bool res = wxAuiMDIChildFrame::Create(parent, id, title);
	if (res) CreateControls();
	return res;
}

wxMenuBar * FbFrameBase::CreateMenuBar()
{
	wxMenuBar * menuBar = new wxMenuBar;
	wxMenuItem * tempItem;
	wxMenu * menu;

	menu = new wxMenu;
	(tempItem = menu->Append(wxID_ANY, wxT("X")))->SetBitmap(wxArtProvider::GetBitmap(wxART_NEW));
	menu->Append(wxID_NEW, _("Добавить файл"))->SetBitmap(wxArtProvider::GetBitmap(wxART_NEW));
	menu->Append(wxID_OPEN, _("Добавить директорию"))->SetBitmap(wxArtProvider::GetBitmap(wxART_FOLDER_OPEN));
	menu->AppendSeparator();
	menu->Append(wxID_SAVE, _("Записать на устройство"))->SetBitmap(wxArtProvider::GetBitmap(wxART_FILE_SAVE));
	menu->AppendSeparator();
	menu->Append(wxID_EXIT, _("Выход\tAlt+F4"))->SetBitmap(wxArtProvider::GetBitmap(wxART_QUIT));
	menu->Delete(tempItem);
	menuBar->Append(menu, _("&Файл"));

	menu = new wxMenu;
	(tempItem = menu->Append(wxID_ANY, wxT("X")))->SetBitmap(wxArtProvider::GetBitmap(wxART_NEW));
	menu->Append(wxID_FIND, _("Расширенный"))->SetBitmap(wxArtProvider::GetBitmap(wxART_FIND));
	menu->AppendSeparator();
	menu->Append(ID_MENU_AUTHOR, _("по Автору"));
	menu->Append(ID_MENU_TITLE, _("по Заголовку"));
	menu->Delete(tempItem);
	menuBar->Append(menu, _("&Поиск"));

	menu = new wxMenu;
	(tempItem = menu->Append(wxID_ANY, wxT("X")))->SetBitmap(wxArtProvider::GetBitmap(wxART_NEW));
	menu->Append(wxID_SELECTALL, _("Выделить все\tCtrl+A"));
	menu->Append(ID_UNSELECT_ALL, _("Отменить выделение"));
	menu->Delete(tempItem);
	menuBar->Append(menu, _("&Книги"));

	menu = new wxMenu;
	(tempItem = menu->Append(wxID_ANY, wxT("X")))->SetBitmap(wxArtProvider::GetBitmap(wxART_NEW));
	menu->Append(wxID_ANY, _("Параметры базы данных"));
	menu->Append(wxID_ANY, _("Реструктуризация БД"));
	menu->AppendSeparator();
	menu->Append(wxID_PREFERENCES, _("Настройки"));
	menu->Delete(tempItem);
	menuBar->Append(menu, _("&Сервис"));

	menu = new wxMenu;
	tempItem = menu->AppendRadioItem(wxID_ANY, wxT("X"));
	menu->AppendCheckItem(ID_SPLIT_VERTICAL, _("&Просмотр справа"));
	menu->AppendCheckItem(ID_SPLIT_HORIZONTAL, _("&Просмтр снизу"));
	menu->AppendSeparator();
	menu->Append(ID_LOG_TEXTCTRL, _("Скрыть окно сообщений\tCtrl+Z"));
	menu->Delete(tempItem);
	menuBar->Append(menu, _("&Вид"));

	menu = new wxMenu;
	(tempItem = menu->Append(wxID_ANY, wxT("X")))->SetBitmap(wxArtProvider::GetBitmap(wxART_NEW));
	menu->Append(ID_OPEN_WEB, _("Официальный сайт"));
	menu->Append(wxID_ABOUT, _("О программе…"))->SetBitmap(wxArtProvider::GetBitmap(wxART_HELP_PAGE));
	menu->Delete(tempItem);
	menuBar->Append(menu, _("&?"));

	return menuBar;
}

void FbFrameBase::OnActivated(wxActivateEvent & event)
{
    /*
	AUIDocViewMainFrame * frame = wxDynamicCast(GetMDIParentFrame(),
		AUIDocViewMainFrame);
	if(frame)
	{
		frame->GetLOGTextCtrl()->SetValue(wxString::Format(
			_("Some help text about '%s'"),	GetTitle().GetData()));
	}
	*/
}

#ifndef __FBCONST_H__
#define __FBCONST_H__

#include <wx/wx.h>

enum {
	ID_MASTER_LIST = wxID_HIGHEST + 1,
	ID_BOOKS_LISTCTRL,
	ID_BOOKS_INFO_PANEL,
	ID_PROGRESSBAR,
	ID_FIND_AUTHOR,
	ID_FIND_TITLE,
	ID_PROGRESS_UPDATE,
	ID_MODE_TREE,
	ID_MODE_LIST,
	ID_SPLIT_HORIZONTAL,
	ID_SPLIT_VERTICAL,
	ID_FILTER_USE,
	ID_FILTER_NOT,
	ID_FILTER_LIB,
	ID_FILTER_USR,
	ID_FILTER_FB2,
	ID_ERROR,
	ID_LOG_TEXTCTRL,
	ID_FULLSCREEN,
	ID_BOOKINFO_UPDATE,
	ID_UPDATE_BOOK,
	ID_SEARCH_BOOK,
	ID_OPEN_WEB,
	ID_FRAME_AUTHOR,
	ID_FRAME_GENRES,
	ID_FRAME_FOLDER,
	ID_FRAME_SEARCH,
	ID_FRAME_DOWNLD,
	ID_FRAME_SEQUEN,
	ID_FRAME_INFO,
	ID_FRAME_HTML,
	ID_FRAME_DATE,
	ID_FRAME_ARCH,
	ID_UNSELECTALL,
	ID_UPDATE_FONTS,
	ID_OPEN_BOOK,
	ID_MENU_SEARCH,
	ID_MENU_AUTHOR,
	ID_MENU_DB_INFO,
	ID_MENU_DB_OPEN,
	ID_MENU_VACUUM,
	ID_MENU_CONFIG,
	ID_EMPTY_AUTHORS,
	ID_EMPTY_BOOKS,
	ID_APPEND_BOOK,
	ID_APPEND_AUTHOR,
	ID_APPEND_SEQUENCE,
	ID_AUTHOR_INFO,
	ID_SEQUENCE_TXT,
	ID_SEQUENCE_BTN,
	ID_FOUND_NOTHING,
	ID_EDIT_COMMENTS,
	ID_APPEND_FOLDER,
	ID_MODIFY_FOLDER,
	ID_DELETE_FOLDER,
	ID_UPDATE_FOLDER,
	ID_HTML_DOCUMENT,
	ID_HTML_CAPTION,
	ID_HTML_COMMENT,
	ID_HTML_SUBMIT,
	ID_HTML_MODIFY,
	ID_BOOK_PAGE,
	ID_BOOK_AUTHOR,
	ID_BOOK_SEQUENCE,
	ID_DOWNLOAD_BOOK,
	ID_SYSTEM_DOWNLOAD,
	ID_DELETE_DOWNLOAD,
	ID_DATABASE_INFO,
	ID_FAVORITES_DEL,
	ID_START,
	ID_PAUSE,
	ID_MASTER_APPEND,
	ID_MASTER_MODIFY,
	ID_MASTER_REPLACE,
	ID_MASTER_DELETE,
	ID_MASTER_PAGE,
	ID_BOOKS_COUNT,
	ID_RATING_0,
	ID_RATING_1,
	ID_RATING_2,
	ID_RATING_3,
	ID_RATING_4,
	ID_RATING_5,
	ID_RECENT_0,
	ID_RECENT_1,
	ID_RECENT_2,
	ID_RECENT_3,
	ID_RECENT_4,
	ID_RECENT_5,
	ID_ART_DEFAULT,
	ID_ART_SIMPLE,
	ID_WINDOW_CLOSE,
	ID_WINDOW_CLOSEALL,
	ID_WINDOW_NEXT,
	ID_WINDOW_PREV,
	ID_DIRECTION,
	ID_ORDER_MENU,
	ID_ORDER_AUTHOR,
	ID_ORDER_TITLE,
	ID_ORDER_RATING,
	ID_ORDER_GENRE,
	ID_ORDER_SIZE,
	ID_ORDER_DATE,
	ID_ORDER_TYPE,
	ID_ORDER_LANG,
	ID_LETTER_RU = wxID_HIGHEST + 200,
	ID_LETTER_EN = wxID_HIGHEST + 250,
	ID_FAVORITES_ADD = wxID_HIGHEST + 300,
};

extern const wxString strProgramName;
extern const wxString strVersionInfo;
extern const wxString strHomePage;

extern const wxString alphabetRu;
extern const wxString alphabetEn;
extern const wxString strAlphabet;
extern const wxString strNobody;
extern const wxString strRusJE;
extern const wxString strRusJO;
extern const wxString strOtherSequence;
extern const wxString strBookNotFound;

extern const int ciNoAuthor;
extern const int ciMaxImageWidth;

extern const wxString strRating [];

extern const wxString strUpdateAuthorCount;
extern const wxString strUpdateSequenCount;

#endif // __FBCONST_H__

#ifndef __FBPARAMS_H__
#define __FBPARAMS_H__

#include <wx/wx.h>
#include <DatabaseLayer.h>
#include "Params.h"

enum {
	DB_LIBRARY_TITLE = 1,
	DB_LIBRARY_VERSION = 2,
	DB_LIBRARY_TYPE,
	DB_NEW_ARCHIVE,
	DB_NEW_AUTHOR,
	DB_NEW_BOOK,
	DB_NEW_SEQUENCE,
	FB_LIBRARY_DIR,
	FB_EXTRACT_DIR,
	FB_EXEC_COMMAND,
};

class FbParams {
public:
    static void InitParams(DatabaseLayer *database)
    {
        database->RunQuery(wxT("CREATE TABLE params(id integer primary key, value integer, text text);"));
        database->RunQuery(_("INSERT INTO params(text) VALUES ('Test Library');"));
        database->RunQuery(_("INSERT INTO params(value) VALUES (1);"));
    };
private:
    DatabaseLayer *m_database;
    wxCriticalSectionLocker m_locker;
public:
    FbParams();
    FbParams(DatabaseLayer *database, wxCriticalSection &section);
    int GetValue(int param);
    wxString GetText(int param);
};

#endif // __FBPARAMS_H__

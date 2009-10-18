/////////////////////////////////////////////////////
// Generated By wxActiveRecordGenerator v 1.2.0-rc3
/////////////////////////////////////////////////////

#include "Bookseq.h"

/** ACTIVE_RECORD **/
Bookseq::Bookseq():wxSqliteActiveRecord(){
}

Bookseq::Bookseq(const wxString& name,const wxString& server,const wxString& user,const wxString& password,const wxString& table):wxSqliteActiveRecord(name,server,user,password,table){
}

Bookseq::Bookseq(DatabaseLayer* database,const wxString& table):wxSqliteActiveRecord(database,table){
}

bool Bookseq::Create(const wxString& name,const wxString& server,const wxString& user,const wxString& password,const wxString& table){
	return wxSqliteActiveRecord::Create(name,server,user,password,table);
}

BookseqRow* Bookseq::RowFromResult(DatabaseResultSet* result){
	BookseqRow* row=new BookseqRow(this);

	row->GetFromResult(result);

	return row;
}

BookseqRow* Bookseq::New(){
	BookseqRow* newRow=new BookseqRow(this);
	garbageRows.Add(newRow);
	return newRow;
}
bool Bookseq::Delete(int key){
	try{
		PreparedStatement* pStatement=m_database->PrepareStatement(wxString::Format(wxT("DELETE FROM %s WHERE id_book=?"),m_table.c_str()));
		pStatement->SetParamInt(1,key);
		pStatement->ExecuteUpdate();
		return true;
	}
	catch(DatabaseLayerException& e){
		throw(e);
		return false;
	}
}



BookseqRow* Bookseq::IdBook(int key){
	try{
		PreparedStatement* pStatement=m_database->PrepareStatement(wxString::Format(wxT("SELECT * FROM %s WHERE id_book=?"),m_table.c_str()));
		pStatement->SetParamInt(1,key);
		DatabaseResultSet* result= pStatement->ExecuteQuery();

		result->Next();
		BookseqRow* row=RowFromResult(result);
		garbageRows.Add(row);
		m_database->CloseResultSet(result);
		m_database->CloseStatement(pStatement);
		return row;
	}
	catch (DatabaseLayerException& e)
	{
		ProcessException(e);
		return NULL;
	}
}




BookseqRow* Bookseq::Where(const wxString& whereClause){
	try{
		wxString prepStatement = wxString::Format(wxT("SELECT * FROM %s WHERE %s"),m_table.c_str(),whereClause.c_str());
		PreparedStatement* pStatement=m_database->PrepareStatement(prepStatement);
		DatabaseResultSet* result= pStatement->ExecuteQuery();

		if(!result->Next())
			return NULL;
		BookseqRow* row=RowFromResult(result);

		garbageRows.Add(row);
		m_database->CloseResultSet(result);
		m_database->CloseStatement(pStatement);
		return row;
	}
	catch (DatabaseLayerException& e)
	{
		ProcessException(e);
		return 0;
	}
}

BookseqRowSet* Bookseq::WhereSet(const wxString& whereClause,const wxString& orderBy){
	BookseqRowSet* rowSet=new BookseqRowSet();
	try{
		wxString prepStatement=wxString::Format(wxT("SELECT * FROM %s WHERE %s"),m_table.c_str(),whereClause.c_str());
		if(!orderBy.IsEmpty())
			prepStatement+=wxT(" ORDER BY ")+orderBy;
		PreparedStatement* pStatement=m_database->PrepareStatement(prepStatement);
		DatabaseResultSet* result= pStatement->ExecuteQuery();

		if(result){
			while(result->Next()){
				rowSet->Add(RowFromResult(result));
			}
		}

		garbageRowSets.Add(rowSet);
		m_database->CloseResultSet(result);
		m_database->CloseStatement(pStatement);
		return rowSet;

	}
	catch (DatabaseLayerException& e)
	{
		ProcessException(e);
		return 0;
	}
}


BookseqRowSet* Bookseq::All(const wxString& orderBy){
	BookseqRowSet* rowSet=new BookseqRowSet();
	try{
		wxString prepStatement=wxString::Format(wxT("SELECT * FROM %s"),m_table.c_str());
		if(!orderBy.IsEmpty())
			prepStatement+=wxT(" ORDER BY ")+orderBy;
		PreparedStatement* pStatement=m_database->PrepareStatement(prepStatement);

		DatabaseResultSet* result= pStatement->ExecuteQuery();

		if(result){
			while(result->Next()){
				rowSet->Add(RowFromResult(result));
			}
		}
		garbageRowSets.Add(rowSet);
		m_database->CloseResultSet(result);
		m_database->CloseStatement(pStatement);
		return rowSet;

	}
	catch (DatabaseLayerException& e)
	{
		ProcessException(e);
		return 0;
	}
}

/** END ACTIVE RECORD **/

/** ACTIVE RECORD ROW **/

BookseqRow::BookseqRow():wxActiveRecordRow(){
	newRow=true;
}

BookseqRow::BookseqRow(Bookseq* activeRecord):wxActiveRecordRow(activeRecord){
	newRow=true;
}

BookseqRow::BookseqRow(const BookseqRow& src){
	if(&src==this)
		return;
	newRow=src.newRow;

	level=src.level;
	number=src.number;
	id_book=src.id_book;
	id_seq=src.id_seq;
	id_author=src.id_author;

}

BookseqRow::BookseqRow(DatabaseLayer* database,const wxString& table):wxActiveRecordRow(database,table){
	newRow=true;
}


BookseqRow& BookseqRow::operator=(const BookseqRow& src){
	if(&src==this)
		return *this;
	newRow=src.newRow;

	level=src.level;
	number=src.number;
	id_book=src.id_book;
	id_seq=src.id_seq;
	id_author=src.id_author;


	return *this;
}

bool BookseqRow::GetFromResult(DatabaseResultSet* result){

	newRow=false;
		level=result->GetResultInt(wxT("level"));
	number=result->GetResultInt(wxT("number"));
	id_book=result->GetResultInt(wxT("id_book"));
	id_seq=result->GetResultInt(wxT("id_seq"));
	id_author=result->GetResultInt(wxT("id_author"));


	return true;
}


bool BookseqRow::Save(){
	try{
		if(newRow){
			PreparedStatement* pStatement=m_database->PrepareStatement(wxString::Format(wxT("INSERT INTO %s (level,number,id_book,id_seq,id_author) VALUES (?,?,?,?,?)"),m_table.c_str()));
			pStatement->SetParamInt(1,level);
			pStatement->SetParamInt(2,number);
			pStatement->SetParamInt(3,id_book);
			pStatement->SetParamInt(4,id_seq);
			pStatement->SetParamInt(5,id_author);
			pStatement->RunQuery();
			m_database->CloseStatement(pStatement);


			newRow=false;
		}
		else{
			PreparedStatement* pStatement=m_database->PrepareStatement(wxString::Format(wxT("UPDATE %s SET level=?,number=?,id_seq=?,id_author=? WHERE id_book=?"),m_table.c_str()));
			pStatement->SetParamInt(1,level);
			pStatement->SetParamInt(2,number);
			pStatement->SetParamInt(5,id_book);
			pStatement->SetParamInt(3,id_seq);
			pStatement->SetParamInt(4,id_author);
			pStatement->RunQuery();
			m_database->CloseStatement(pStatement);

		}

		return true;
	}
	catch (DatabaseLayerException& e)
	{
		wxActiveRecord::ProcessException(e);
		return false;
	}
}

bool BookseqRow::Delete(){
	try{
		PreparedStatement* pStatement=m_database->PrepareStatement(wxString::Format(wxT("DELETE FROM %s WHERE id_book=?"),m_table.c_str()));
		pStatement->SetParamInt(1,id_book);
		pStatement->ExecuteUpdate();
		return true;
	}
	catch(DatabaseLayerException& e){
		throw(e);
		return false;
	}
}





/** END ACTIVE RECORD ROW **/

/** ACTIVE RECORD ROW SET **/

BookseqRowSet::BookseqRowSet():wxActiveRecordRowSet(){
}

BookseqRowSet::BookseqRowSet(wxActiveRecord* activeRecord):wxActiveRecordRowSet(activeRecord){
}

BookseqRowSet::BookseqRowSet(DatabaseLayer* database,const wxString& table):wxActiveRecordRowSet(database,table){
}

BookseqRow* BookseqRowSet::Item(unsigned long item){
	return (BookseqRow*)wxActiveRecordRowSet::Item(item);
}


bool BookseqRowSet::SaveAll(){
	try{
		m_database->BeginTransaction();
		for(unsigned long i=0;i<Count();i++)
			Item(i)->Save();
		m_database->Commit();
		return true;
	}
	catch (DatabaseLayerException& e)
	{
		m_database->RollBack();
		wxActiveRecord::ProcessException(e);
		return false;
	}
}


int BookseqRowSet::CMPFUNC_level(wxActiveRecordRow** item1,wxActiveRecordRow** item2){
	BookseqRow** m_item1=(BookseqRow**)item1;
	BookseqRow** m_item2=(BookseqRow**)item2;
	if((*m_item1)->level<(*m_item2)->level)
		return -1;
	else if((*m_item1)->level>(*m_item2)->level)
		return 1;
	else
		return 0;
}

int BookseqRowSet::CMPFUNC_number(wxActiveRecordRow** item1,wxActiveRecordRow** item2){
	BookseqRow** m_item1=(BookseqRow**)item1;
	BookseqRow** m_item2=(BookseqRow**)item2;
	if((*m_item1)->number<(*m_item2)->number)
		return -1;
	else if((*m_item1)->number>(*m_item2)->number)
		return 1;
	else
		return 0;
}

int BookseqRowSet::CMPFUNC_id_book(wxActiveRecordRow** item1,wxActiveRecordRow** item2){
	BookseqRow** m_item1=(BookseqRow**)item1;
	BookseqRow** m_item2=(BookseqRow**)item2;
	if((*m_item1)->id_book<(*m_item2)->id_book)
		return -1;
	else if((*m_item1)->id_book>(*m_item2)->id_book)
		return 1;
	else
		return 0;
}

int BookseqRowSet::CMPFUNC_id_seq(wxActiveRecordRow** item1,wxActiveRecordRow** item2){
	BookseqRow** m_item1=(BookseqRow**)item1;
	BookseqRow** m_item2=(BookseqRow**)item2;
	if((*m_item1)->id_seq<(*m_item2)->id_seq)
		return -1;
	else if((*m_item1)->id_seq>(*m_item2)->id_seq)
		return 1;
	else
		return 0;
}

int BookseqRowSet::CMPFUNC_id_author(wxActiveRecordRow** item1,wxActiveRecordRow** item2){
	BookseqRow** m_item1=(BookseqRow**)item1;
	BookseqRow** m_item2=(BookseqRow**)item2;
	if((*m_item1)->id_author<(*m_item2)->id_author)
		return -1;
	else if((*m_item1)->id_author>(*m_item2)->id_author)
		return 1;
	else
		return 0;
}

int BookseqRowSet::CMPFUNC_order(wxActiveRecordRow** item1,wxActiveRecordRow** item2){
	BookseqRow** m_item1=(BookseqRow**)item1;
	BookseqRow** m_item2=(BookseqRow**)item2;
	if((*m_item1)->order<(*m_item2)->order)
		return -1;
	else if((*m_item1)->order>(*m_item2)->order)
		return 1;
	else
		return 0;
}

CMPFUNC_proto BookseqRowSet::GetCmpFunc(const wxString& var) const{
	if(var==wxT("level"))
		return (CMPFUNC_proto)CMPFUNC_level;
	else if(var==wxT("number"))
		return (CMPFUNC_proto)CMPFUNC_number;
	else if(var==wxT("id_book"))
		return (CMPFUNC_proto)CMPFUNC_id_book;
	else if(var==wxT("id_seq"))
		return (CMPFUNC_proto)CMPFUNC_id_seq;
	else if(var==wxT("id_author"))
		return (CMPFUNC_proto)CMPFUNC_id_author;
	else if(var==wxT("order"))
		return (CMPFUNC_proto)CMPFUNC_order;
	else
	return (CMPFUNC_proto)CMPFUNC_default;
}



/** END ACTIVE RECORD ROW SET **/

////@@begin custom implementations

////@@end custom implementations

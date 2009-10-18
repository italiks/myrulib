/////////////////////////////////////////////////////
// Generated By wxActiveRecordGenerator v 1.2.0-rc3
/////////////////////////////////////////////////////

#include "Sequences.h"

/** ACTIVE_RECORD **/
Sequences::Sequences():wxSqliteActiveRecord(){
}

Sequences::Sequences(const wxString& name,const wxString& server,const wxString& user,const wxString& password,const wxString& table):wxSqliteActiveRecord(name,server,user,password,table){
}

Sequences::Sequences(DatabaseLayer* database,const wxString& table):wxSqliteActiveRecord(database,table){
}

bool Sequences::Create(const wxString& name,const wxString& server,const wxString& user,const wxString& password,const wxString& table){
	return wxSqliteActiveRecord::Create(name,server,user,password,table);
}

SequencesRow* Sequences::RowFromResult(DatabaseResultSet* result){
	SequencesRow* row=new SequencesRow(this);

	row->GetFromResult(result);

	return row;
}

SequencesRow* Sequences::New(){
	SequencesRow* newRow=new SequencesRow(this);
	garbageRows.Add(newRow);
	return newRow;
}
bool Sequences::Delete(int key){
	try{
		PreparedStatement* pStatement=m_database->PrepareStatement(wxString::Format(wxT("DELETE FROM %s WHERE id=?"),m_table.c_str()));
		pStatement->SetParamInt(1,key);
		pStatement->ExecuteUpdate();
		return true;
	}
	catch(DatabaseLayerException& e){
		throw(e);
		return false;
	}
}



SequencesRow* Sequences::Id(int key){
	try{
		PreparedStatement* pStatement=m_database->PrepareStatement(wxString::Format(wxT("SELECT * FROM %s WHERE id=?"),m_table.c_str()));
		pStatement->SetParamInt(1,key);
		DatabaseResultSet* result= pStatement->ExecuteQuery();

		result->Next();
		SequencesRow* row=RowFromResult(result);
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

SequencesRow* Sequences::Name(const wxString& name){
	try{
		PreparedStatement* pStatement=m_database->PrepareStatement(wxString::Format(wxT("SELECT * FROM %s WHERE value=?"),m_table.c_str()));
		pStatement->SetParamString(1, name);
		DatabaseResultSet* result= pStatement->ExecuteQuery();

		if(!result->Next())
			return NULL;
		SequencesRow* row=RowFromResult(result);
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

SequencesRow* Sequences::Where(const wxString& whereClause){
	try{
		wxString prepStatement = wxString::Format(wxT("SELECT * FROM %s WHERE %s"),m_table.c_str(),whereClause.c_str());
		PreparedStatement* pStatement=m_database->PrepareStatement(prepStatement);
		DatabaseResultSet* result= pStatement->ExecuteQuery();

		if(!result->Next())
			return NULL;
		SequencesRow* row=RowFromResult(result);

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

SequencesRowSet* Sequences::WhereSet(const wxString& whereClause,const wxString& orderBy){
	SequencesRowSet* rowSet=new SequencesRowSet();
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


SequencesRowSet* Sequences::All(const wxString& orderBy){
	SequencesRowSet* rowSet=new SequencesRowSet();
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

SequencesRow::SequencesRow():wxActiveRecordRow(){
	newRow=true;
}

SequencesRow::SequencesRow(Sequences* activeRecord):wxActiveRecordRow(activeRecord){
	newRow=true;
}

SequencesRow::SequencesRow(const SequencesRow& src){
	if(&src==this)
		return;
	newRow=src.newRow;

	value=src.value;
	id=src.id;

}

SequencesRow::SequencesRow(DatabaseLayer* database,const wxString& table):wxActiveRecordRow(database,table){
	newRow=true;
}


SequencesRow& SequencesRow::operator=(const SequencesRow& src){
	if(&src==this)
		return *this;
	newRow=src.newRow;

	value=src.value;
	id=src.id;


	return *this;
}

bool SequencesRow::GetFromResult(DatabaseResultSet* result){

	newRow=false;
		value=result->GetResultString(wxT("value"));
	id=result->GetResultInt(wxT("id"));


	return true;
}


bool SequencesRow::Save(){
	try{
		if(newRow){
			PreparedStatement* pStatement=m_database->PrepareStatement(wxString::Format(wxT("INSERT INTO %s (value,id) VALUES (?,?)"),m_table.c_str()));
			pStatement->SetParamString(1,value);
			pStatement->SetParamInt(2,id);
			pStatement->RunQuery();
			m_database->CloseStatement(pStatement);


			newRow=false;
		}
		else{
			PreparedStatement* pStatement=m_database->PrepareStatement(wxString::Format(wxT("UPDATE %s SET value=? WHERE id=?"),m_table.c_str()));
			pStatement->SetParamString(1,value);
			pStatement->SetParamInt(2,id);
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

bool SequencesRow::Delete(){
	try{
		PreparedStatement* pStatement=m_database->PrepareStatement(wxString::Format(wxT("DELETE FROM %s WHERE id=?"),m_table.c_str()));
		pStatement->SetParamInt(1,id);
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

SequencesRowSet::SequencesRowSet():wxActiveRecordRowSet(){
}

SequencesRowSet::SequencesRowSet(wxActiveRecord* activeRecord):wxActiveRecordRowSet(activeRecord){
}

SequencesRowSet::SequencesRowSet(DatabaseLayer* database,const wxString& table):wxActiveRecordRowSet(database,table){
}

SequencesRow* SequencesRowSet::Item(unsigned long item){
	return (SequencesRow*)wxActiveRecordRowSet::Item(item);
}


bool SequencesRowSet::SaveAll(){
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


int SequencesRowSet::CMPFUNC_value(wxActiveRecordRow** item1,wxActiveRecordRow** item2){
	SequencesRow** m_item1=(SequencesRow**)item1;
	SequencesRow** m_item2=(SequencesRow**)item2;
	return (*m_item1)->value.Cmp((*m_item2)->value);
}

int SequencesRowSet::CMPFUNC_id(wxActiveRecordRow** item1,wxActiveRecordRow** item2){
	SequencesRow** m_item1=(SequencesRow**)item1;
	SequencesRow** m_item2=(SequencesRow**)item2;
	if((*m_item1)->id<(*m_item2)->id)
		return -1;
	else if((*m_item1)->id>(*m_item2)->id)
		return 1;
	else
		return 0;
}

CMPFUNC_proto SequencesRowSet::GetCmpFunc(const wxString& var) const{
	if(var==wxT("value"))
		return (CMPFUNC_proto)CMPFUNC_value;
	else if(var==wxT("id"))
		return (CMPFUNC_proto)CMPFUNC_id;
	else
	return (CMPFUNC_proto)CMPFUNC_default;
}



/** END ACTIVE RECORD ROW SET **/

////@@begin custom implementations

////@@end custom implementations

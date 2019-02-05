#include "stdafx.h"
#include "DBManager.h"


DBManager::DBManager()
{
	_database = shared_ptr<database>(new database("dbfile.db"));
	this->CreateDataBase();
}

DBManager::~DBManager()
{
}

void DBManager::Insert(string sql)
{
	try
	{
		*_database << sql;
	}
	catch (const std::exception&)
	{
	
	}
}

void DBManager::CreateDataBase()
{
	try
	{
		*_database <<
			"create table if not exists clients ("
			"   _id integer primary key autoincrement not null,"
			"   name text"
			");";

		*_database <<
			"insert into clients (age) values (?)"
			<< "teste";
	}
	catch (const std::exception&)
	{

	}
}

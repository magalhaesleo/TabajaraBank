#include "stdafx.h"
#include "DBManager.h"


DBManager::DBManager(shared_ptr<database> database):_database(database)
{
	this->CreateDataBase();
}

DBManager::~DBManager()
{
}

int DBManager::Insert(string sql)
{
	try
	{
		*_database << sql;

		return _database->last_insert_rowid();
	}
	catch (const std::exception& ex)
	{
		printf("exception: %s", ex.what());
	}
}

bool DBManager::Update(string sql)
{
	return false;
}

bool DBManager::Delete(string sql)
{
	return false;
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
	}
	catch (const std::exception& ex)
	{

	}
}


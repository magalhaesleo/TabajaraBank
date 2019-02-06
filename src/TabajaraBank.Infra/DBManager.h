#pragma once

#include <memory>
#include<iostream>
#include <sqlite_modern_cpp.h>
#include "Export.h"

using namespace sqlite;
using namespace std;

class TABAJARABANKINFRA_API DBManager
{
	shared_ptr<database> _database;
	void CreateDataBase();
public:
	DBManager(shared_ptr<database> database);
	~DBManager();
	virtual int Insert(string sql);
	virtual bool Update(string sql);
	template<typename T>
	void GetById(string sql);
	bool Delete(string sql);
};

template<typename T>
void DBManager::GetById(string sql)
{
	try
	{
		ostream output(nullptr);
		*_database << "select * from clients"
			>> output;
	}
	catch (const std::exception& ex)
	{
	}
}

#pragma once

#include <memory>
#include<iostream>
#include <sqlite_modern_cpp.h>
#include "Export.h"
#include "Builder.h"

using namespace sqlite;
using namespace std;

class TABAJARABANKINFRA_API DBManager
{
	shared_ptr<database> _database;
	void CreateDataBase();
public:
	DBManager(shared_ptr<database> database);
	virtual ~DBManager();
	virtual int Insert(string sql);
	virtual bool Update(string sql);
	template<typename Target, typename... AttrTypes>
	Target GetById(string sql);
	bool Delete(string sql);
};

template<typename Target, typename... AttrTypes>
Target DBManager::GetById(string sql)
{
	try
	{
		builder<Target, AttrTypes&&...> builder;
		*_database << sql >> builder;

		return builder.results.front();
	}
	catch (const std::exception& ex)
	{
		printf("Exception: %s", ex.what());
	}
}
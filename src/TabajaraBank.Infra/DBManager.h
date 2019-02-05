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
	DBManager();
	~DBManager();
	void Insert(string sql);		
};


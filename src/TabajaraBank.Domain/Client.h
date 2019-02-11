#pragma once

#include "Export.h"
#include <string>

using namespace std;

class TABAJARABANKDOMAIN_API Client
{
	int _id;
	string _name;
	
public:
	Client();
	Client(int id, string name);
	~Client();

	virtual string get_name() { return this->_name; }
	virtual void set_name(string name) { this->_name = name; }

	virtual int get_id() { return this->_id; }
	virtual void set_id(int id) { this->_id = id; }
};


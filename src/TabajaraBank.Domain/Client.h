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

	string get_name() { return this->_name; }
	void set_name(string name) { this->_name = name; }

	int get_id() { return this->_id; }
	void set_id(int id) { this->_id = id; }
};


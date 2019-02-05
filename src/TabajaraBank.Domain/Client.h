#pragma once

#include "Export.h"
#include <string>

using namespace std;

class TABAJARABANKDOMAIN_API Client
{
	string _name;
public:
	Client();
	~Client();

	void Set_Name(string name) { this->_name = name; }
	string Get_Name() { return this->_name; }
};


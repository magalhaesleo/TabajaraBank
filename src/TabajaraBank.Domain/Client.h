#pragma once

#include "Export.h"
#include <string>

using namespace std;

class TABAJARABANKDOMAIN_API Client
{
	int _id;
	string _name;
	string _cpf;
	string _birthdate;
	string _rg;
	
public:
	Client();
	Client(int id, string name, string cpf, string birthdate, string rg);
	~Client();

	virtual string get_name() { return this->_name; }
	virtual void set_name(string name) { this->_name = name; }

	virtual int get_id() { return this->_id; }
	virtual void set_id(int id) { this->_id = id; }

	virtual string get_cpf() { return this->_cpf; }
	virtual void set_cpf(string cpf) { this->_cpf = cpf; }

	virtual string get_birthdate() { return this->_birthdate; }
	virtual void set_birthdate(string birthdate) { this->_birthdate = birthdate; }

	virtual string get_rg() { return this->_rg; }
	virtual void set_rg(string rg) { this->_rg = rg; }

	virtual void Validate();

};


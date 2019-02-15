#include "stdafx.h"
#include "Client.h"
#include "ShortNameException.h"

Client::Client()
{
}

Client::Client(int id, string name, string cpf, string birthdate, string rg)
	: _id(id), _name(name), _cpf(cpf), _birthdate(birthdate), _rg(rg)
{
}

Client::~Client()
{
}

void Client::Validate()
{
	if (this->_name.length() < 3)
		throw ShortNameException();

	if (this->_cpf.length() != 14)
		throw exception("O CPF deve possuir 14 dígitos");

	if (this->_rg.empty() == true)
		throw exception("RG inválido");

	if (this->_birthdate.length() != 10)
		throw exception("Data de nascimento inválida");

	if (this->_id == 0)
		throw exception("ID invalido");
}
#pragma once
#include <iostream>
#include "Export.h"

class TABAJARABANKDOMAIN_API ShortNameException : public std::exception
{
public:
	ShortNameException(); /*: base("O nome deve possuir no minimo 3 caracteres")*/


	~ShortNameException();
};


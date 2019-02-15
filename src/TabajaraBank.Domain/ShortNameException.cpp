#include "stdafx.h"
#include "ShortNameException.h"


ShortNameException::ShortNameException() : exception("O nome deve possuir no minimo 3 caracteres")
{
}


ShortNameException::~ShortNameException()
{
}

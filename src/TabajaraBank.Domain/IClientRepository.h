#pragma once

#include "Client.h"
#include "IRepository.h"

struct TABAJARABANKDOMAIN_API IClientRepository : public IRepository<Client>
{
	virtual ~IClientRepository();
};
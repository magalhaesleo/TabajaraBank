#pragma once

#include "Export.h"
#include "..\TabajaraBank.Domain\Client.h"
#include <vector>

struct TABAJARABANKAPPLICATION_API IClientService
{
	virtual ~IClientService() = default;
	virtual int Add(Client client) = 0;
	virtual bool Update(Client client) = 0;
	virtual Client GetById(int id) = 0;
	virtual std::vector<Client> GetAll() = 0;
	virtual bool Remove(int clientId) = 0;
};
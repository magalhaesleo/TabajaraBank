#pragma once

#include "IClientService.h"

class TABAJARABANKAPPLICATION_API ClientService : public IClientService
{
public:
	ClientService();
	~ClientService();

	virtual int Add(Client client) override;
	virtual bool Update(Client client) override;
	virtual Client GetById(int id) override;
	virtual std::vector<Client> GetAll() override;
	virtual bool Remove(int clientId) override;
};


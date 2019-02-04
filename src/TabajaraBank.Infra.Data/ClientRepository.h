#pragma once

#include "Export.h"
#include "..\TabajaraBank.Domain\IClientRepository.h"

class TABAJARABANKINFRADATA_API ClientRepository : public IClientRepository
{
public:
	ClientRepository();
	~ClientRepository();

	virtual int Add(Client client) override;
	virtual bool Update(Client client) override;
	virtual Client GetById(int id) override;
	virtual std::vector<Client> GetAll() override;
	virtual bool Remove(int clientId) override;
};


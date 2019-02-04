#pragma once

#include "IClientService.h"
#include "..\TabajaraBank.Domain\IClientRepository.h"
#include <memory>

using namespace std;

class TABAJARABANKAPPLICATION_API ClientService : public IClientService
{
	shared_ptr<IClientRepository> _clientRepository;
public:
	ClientService(shared_ptr<IClientRepository> clientRepository);
	~ClientService();

	virtual int Add(Client client) override;
	virtual bool Update(Client client) override;
	virtual Client GetById(int id) override;
	virtual vector<Client> GetAll() override;
	virtual bool Remove(int clientId) override;
};


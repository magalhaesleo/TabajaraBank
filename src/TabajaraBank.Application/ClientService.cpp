#include "stdafx.h"
#include "ClientService.h"

ClientService::ClientService(shared_ptr<IClientRepository> clientRepository) : _clientRepository(clientRepository)
{
}

ClientService::~ClientService()
{
}

int ClientService::Add(Client& client)
{
	client.Validate();
	return _clientRepository->Add(client);
}

bool ClientService::Update(Client& client)
{
	client.Validate();
	return _clientRepository->Update(client);
}

Client ClientService::GetById(int id)
{
	if (id > 0)
	{
		return _clientRepository->GetById(id);
	}
	else
		throw exception();
}

vector<Client> ClientService::GetAll()
{
	return _clientRepository->GetAll();
}

bool ClientService::Remove(int clientId)
{
	if (clientId < 1)
		return false;

	return _clientRepository->Remove(clientId);
}
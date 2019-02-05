#include "stdafx.h"
#include "ClientService.h"

ClientService::ClientService(shared_ptr<IClientRepository> clientRepository) : _clientRepository(clientRepository)
{
}

ClientService::~ClientService()
{
}

int ClientService::Add(Client client)
{
	return _clientRepository->Add(client);
}

bool ClientService::Update(Client client)
{
	return false;
}

Client ClientService::GetById(int id)
{
	return _clientRepository->GetById(id);
}

vector<Client> ClientService::GetAll()
{
	return vector<Client>();
}

bool ClientService::Remove(int clientId)
{
	return false;
}
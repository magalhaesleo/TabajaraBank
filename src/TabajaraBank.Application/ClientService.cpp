#include "stdafx.h"
#include "ClientService.h"

ClientService::ClientService()
{
}

ClientService::~ClientService()
{
}

int ClientService::Add(Client client)
{
	return 0;
}

bool ClientService::Update(Client client)
{
	return false;
}

Client ClientService::GetById(int id)
{
	return Client();
}

std::vector<Client> ClientService::GetAll()
{
	return std::vector<Client>();
}

bool ClientService::Remove(int clientId)
{
	return false;
}

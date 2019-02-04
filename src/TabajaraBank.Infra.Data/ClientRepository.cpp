#include "stdafx.h"
#include "ClientRepository.h"


ClientRepository::ClientRepository()
{
}


ClientRepository::~ClientRepository()
{
}

int ClientRepository::Add(Client client)
{
	return 0;
}

bool ClientRepository::Update(Client client)
{
	return false;
}

Client ClientRepository::GetById(int id)
{
	return Client();
}

std::vector<Client> ClientRepository::GetAll()
{
	return std::vector<Client>();
}

bool ClientRepository::Remove(int clientId)
{
	return false;
}

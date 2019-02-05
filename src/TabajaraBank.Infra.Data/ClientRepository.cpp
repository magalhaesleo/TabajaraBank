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
	return 50;
}

bool ClientRepository::Update(Client client)
{
	return false;
}

Client ClientRepository::GetById(int id)
{
	Client c;
	c.Set_Name("Teste");

	return c;
}

std::vector<Client> ClientRepository::GetAll()
{
	return std::vector<Client>();
}

bool ClientRepository::Remove(int clientId)
{
	return false;
}

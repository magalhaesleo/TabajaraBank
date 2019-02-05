#include "stdafx.h"
#include "ClientRepository.h"


ClientRepository::ClientRepository(shared_ptr<DBManager> dbManager) :_dbManager(dbManager)
{
}


ClientRepository::~ClientRepository()
{
}

int ClientRepository::Add(Client client)
{
	std::string sql;

	_dbManager->Insert(sql);

	return 50;
}

bool ClientRepository::Update(Client client)
{
	return false;
}

Client ClientRepository::GetById(int id)
{
	Client c;
	c.Name = "Teste";

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

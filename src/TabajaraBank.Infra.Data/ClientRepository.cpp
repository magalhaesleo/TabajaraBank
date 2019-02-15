#include "stdafx.h"
#include "ClientRepository.h"
#include <string>

ClientRepository::ClientRepository(shared_ptr<DBManager> dbManager) :_dbManager(dbManager)
{
}

ClientRepository::~ClientRepository()
{
}

int ClientRepository::Add(Client client)
{
	std::string sql = "insert into clients (name) values (\"" + client.get_name() + "\");";

	return _dbManager->Insert(sql);
}

bool ClientRepository::Update(Client client)
{
	return false;
}

Client ClientRepository::GetById(int id)
{
	string sql = "select _id, name from clients where _id=" + to_string(id) + ";";
	
	return _dbManager->GetById<Client, int, std::string, std::string, std::string, std::string>(sql);
}

std::vector<Client> ClientRepository::GetAll()
{
	return std::vector<Client>();
}

bool ClientRepository::Remove(int clientId)
{
	return false;
}
#include "stdafx.h"
#include "ClientMapperJson.h"

Value ClientMapperJson::Serialize(Client client)
{
	Value root;
	//root["Name"] = client.Get_Name();
	root["Name"] = client.Name;

	return root;
}

Client ClientMapperJson::Deserialize(Value input)
{
	Client client;

	//client.Set_Name(input["Name"].asString());
	client.Name = input["Name"].asString();

	return client;
}

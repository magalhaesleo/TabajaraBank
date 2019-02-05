#include "stdafx.h"
#include "ClientMapperJson.h"

Value ClientMapperJson::Serialize(Client client)
{
	Value root;
	root["Name"] = client.Get_Name();

	return root;
}

Client ClientMapperJson::Deserialize(Value input)
{
	Client client;

	client.Set_Name(input["Name"].asString());

	return client;
}

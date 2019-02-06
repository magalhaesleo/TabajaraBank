#include "stdafx.h"
#include "ClientMapperJson.h"

Value ClientMapperJson::Serialize(Client client)
{
	Value root;
	root["Id"] = client.get_id();
	root["Name"] = client.get_name();

	return root;
}

Client ClientMapperJson::Deserialize(Value input)
{
	Client client;

	client.set_name(input["Name"].asString());
	client.set_id(input["Id"].asInt());

	return client;
}

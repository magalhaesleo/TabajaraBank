#include "pch.h"
#include "TabajaraBankAPI.h"
#include "IClientResourceAPI.h"

TabajaraBankAPI::TabajaraBankAPI(shared_ptr<IClientResourceAPI> clientResource) : _clientResource(clientResource)
{
}

void TabajaraBankAPI::Initialize()
{
	this->RegisterResources();

	auto settings = make_shared< Settings >();
	settings->set_port(1984);
	settings->set_default_header("Connection", "close");

	Service service;

	for (auto &resource : _resources)
	{
		service.publish(resource);
	}

	service.start(settings);
}

void TabajaraBankAPI::RegisterResources()
{
	auto clientResource = make_shared< Resource >();
	std::set<std::string> paths;
	paths.insert("/client");
	paths.insert("/client/{id: .*}");
	clientResource->set_method_handler("POST", bind(&IClientResourceAPI::Post, _clientResource, std::placeholders::_1));
	clientResource->set_method_handler("GET", bind(&IClientResourceAPI::Get, _clientResource, std::placeholders::_1));
	clientResource->set_paths(paths);


	this->_resources.push_back(clientResource);
}
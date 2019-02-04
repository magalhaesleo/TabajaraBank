#include "pch.h"
#include "TabajaraBankAPI.h"
#include "corvusoft/restbed.hpp"

using namespace std;
using namespace restbed;

TabajaraBankAPI::TabajaraBankAPI(shared_ptr<IClientService> clientService) :_clientService(clientService)
{
}

TabajaraBankAPI::~TabajaraBankAPI()
{
}

void TabajaraBankAPI::Initialize()
{
	auto resource = make_shared< Resource >();
	resource->set_path("/client");

	resource->set_method_handler("POST", bind(&TabajaraBankAPI::Post, this, std::placeholders::_1));
	resource->set_method_handler("GET", bind(&TabajaraBankAPI::Get, this, std::placeholders::_1));

	auto settings = make_shared< Settings >();
	settings->set_port(1984);
	settings->set_default_header("Connection", "close");

	Service service;
	service.publish(resource);
	service.start(settings);
}

void TabajaraBankAPI::Post(const shared_ptr< Session > session)
{
	const auto request = session->get_request();

	int content_length = request->get_header("Content-Length", 0);

	session->fetch(content_length, [](const shared_ptr< Session > session, const Bytes & body)
	{
		fprintf(stdout, "%.*s\n", (int)body.size(), body.data());
		session->close(OK, "Hello, World!", { { "Content-Length", "13" } });
	});
}

void TabajaraBankAPI::Get(const shared_ptr<Session> session)
{
	const auto request = session->get_request();

	int content_length = request->get_header("Content-Length", 0);

	session->fetch(content_length, [](const shared_ptr< Session > session, const Bytes & body)
	{
		fprintf(stdout, "%.*s\n", (int)body.size(), body.data());
		session->close(OK, "Hello, World!", { { "Content-Length", "13" } });
	});
}

void TabajaraBankAPI::Put(const shared_ptr<Session> session)
{
}

void TabajaraBankAPI::Delete(const shared_ptr<Session> session)
{
}

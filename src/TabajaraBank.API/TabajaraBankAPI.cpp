#include "pch.h"
#include "TabajaraBankAPI.h"
#include "corvusoft/restbed.hpp"

using namespace std;
using namespace restbed;

TabajaraBankAPI::TabajaraBankAPI(shared_ptr<IClientService> clientService, ClientMapperJson & mapper) :_clientService(clientService), _mapper(mapper)
{
}

TabajaraBankAPI::~TabajaraBankAPI()
{
}

void TabajaraBankAPI::Initialize()
{
	auto resource = make_shared< Resource >();
	std::set<std::string> paths;
	paths.insert("/client");
	paths.insert("/client/{id: .*}");

	resource->set_paths(paths);

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

	session->fetch(content_length, [&](const shared_ptr< Session > session, const Bytes & body)
	{
		string bodyStr = string(body.begin(), body.end());
		CharReaderBuilder rbuilder;
		std::unique_ptr<Json::CharReader> const reader(rbuilder.newCharReader());
		Json::Value root;
		std::string errs;

		bool ok = reader->parse(
			bodyStr.c_str(),
			bodyStr.c_str() + bodyStr.size(),
			&root, &errs);

		if (ok)
		{
			Client client = _mapper.Deserialize(root);
			int id = this->_clientService->Add(client);

			session->close(OK, std::to_string(id));
		}
		else
		{
			session->close(FORBIDDEN);
		}
	});
}

void TabajaraBankAPI::Get(const shared_ptr<Session> session)
{
	const auto request = session->get_request();

	const string body = request->get_path_parameter("id");



	session->close(OK, "Hello, World!", { { "Content-Length", "13" } });
}

void TabajaraBankAPI::Put(const shared_ptr<Session> session)
{
}

void TabajaraBankAPI::Delete(const shared_ptr<Session> session)
{
}

#include "pch.h"
#include "ClientResourceAPI.h"

ClientResourceAPI::ClientResourceAPI(shared_ptr<IClientService> clientService, shared_ptr<IClientMapper> mapper) :_clientService(clientService), _mapper(mapper)
{
}

ClientResourceAPI::~ClientResourceAPI()
{
}

void ClientResourceAPI::Post(const shared_ptr<Session> session)
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
			Client client = _mapper->Deserialize(root);
			int id = this->_clientService->Add(client);

			session->close(OK, std::to_string(id));
		}
		else
		{
			session->close(FORBIDDEN);
		}
	});
}

void ClientResourceAPI::Get(const shared_ptr<Session> session)
{
	const auto request = session->get_request();

	const string body = request->get_path_parameter("id");

	Client client = this->_clientService->GetById(stoi(body));

	Value clientJson = _mapper->Serialize(client);

	string jsonStr = clientJson.toStyledString();

	session->close(OK, jsonStr, { { "Content-Length", to_string(jsonStr.size()) }, { "Content-Type", "application/json"} });
}

void ClientResourceAPI::Put(const shared_ptr<Session> session)
{
}

void ClientResourceAPI::Delete(const shared_ptr<Session> session)
{
}

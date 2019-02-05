#pragma once

#include <memory>
#include "corvusoft\restbed.hpp"
#include "..\TabajaraBank.Application\IClientService.h"
#include "..\TabajaraBank.Infra\ClientMapperJson.h"

using namespace std;
using namespace restbed;

class TabajaraBankAPI
{
	void Post(const shared_ptr<Session> session);
	void Get(const shared_ptr<Session> session);
	void Put(const shared_ptr<Session> session);
	void Delete(const shared_ptr<Session> session);
	shared_ptr<IClientService> _clientService;
	ClientMapperJson & _mapper;
public:
	TabajaraBankAPI(shared_ptr<IClientService> clientService, ClientMapperJson & mapper);
	~TabajaraBankAPI();
	void Initialize();
};


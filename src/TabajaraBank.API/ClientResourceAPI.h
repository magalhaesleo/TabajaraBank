#pragma once

#include "IClientResourceAPI.h"
#include "..\TabajaraBank.Application\IClientService.h"
#include "..\TabajaraBank.Infra\IClientMapper.h"
#include "Export.h"

class TABAJARABANKAPI_API ClientResourceAPI : public IClientResourceAPI
{
	shared_ptr<IClientService> _clientService;
	shared_ptr<IClientMapper> _mapper;

public:
	ClientResourceAPI(shared_ptr<IClientService> clientService, shared_ptr<IClientMapper> mapper);
	~ClientResourceAPI();
	/*virtual void Post(const shared_ptr<Session> session) override;
	virtual void Get(const shared_ptr<Session> session) override;
	virtual void Put(const shared_ptr<Session> session) override;
	virtual void Delete(const shared_ptr<Session> session) override;*/

	virtual void Post(const shared_ptr<Session> session) override;
	virtual void Get(const shared_ptr<Session> session) override;
	virtual void Put(const shared_ptr<Session> session) override;
	virtual void Delete(const shared_ptr<Session> session) override;
};


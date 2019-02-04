#pragma once

#include "boost/di.hpp"
#include "TabajaraBankAPI.h"
#include "..\TabajaraBank.Application\ClientService.h"
#include "..\TabajaraBank.Domain\IClientRepository.h"
#include "..\TabajaraBank.Infra.Data\ClientRepository.h"

namespace di = boost::di;

class BoostDIContainer
{
public:
	BoostDIContainer();
	~BoostDIContainer();

	auto MakeInjector()
	{
		auto injector = di::make_injector
		(
			di::bind<TabajaraBankAPI>(),
			di::bind<IClientService>().to<ClientService>(),
			di::bind<IClientRepository>().to<ClientRepository>()
		);

		return injector;
	}
};


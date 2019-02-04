#pragma once

#include "boost/di.hpp"
#include "TabajaraBankAPI.h"
#include "..\TabajaraBank.Application\ClientService.h"

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
			di::bind<IClientService>().to<ClientService>()
		);

		return injector;
	}
};


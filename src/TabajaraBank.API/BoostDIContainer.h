#pragma once

#include "boost/di.hpp"
#include "TabajaraBankAPI.h"
#include "..\TabajaraBank.Application\ClientService.h"
#include "..\TabajaraBank.Domain\IClientRepository.h"
#include "..\TabajaraBank.Infra.Data\ClientRepository.h"
#include "..\TabajaraBank.Infra\ClientMapperJson.h"
#include "ClientResourceAPI.h"

namespace di = boost::di;

const auto MakeInjector = []
{
	return di::make_injector
	(
		di::bind<IClientRepository>().to<ClientRepository>(),
		di::bind<IClientService>().to<ClientService>(),
		di::bind<IClientMapper>().to< ClientMapperJson>(),
		di::bind<IClientResourceAPI>().to<ClientResourceAPI>(),
		di::bind<TabajaraBankAPI>()
	);
};
#pragma once

#include "Export.h"
#include "..\TabajaraBank.Domain\Client.h"
#include "IService.h"

struct TABAJARABANKAPPLICATION_API IClientService : public IService<Client>
{
	virtual ~IClientService() = default;
};
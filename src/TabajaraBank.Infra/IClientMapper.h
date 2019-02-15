#pragma once

#include "IMapper.h"
#include "..\TabajaraBank.Domain\Client.h"

struct TABAJARABANKINFRA_API IClientMapper : public IMapper<Client>
{
	virtual ~IClientMapper() = default;
};
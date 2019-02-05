#pragma once

#include "..\TabajaraBank.Domain\Client.h"
#include "IMapper.h"

class TABAJARABANKINFRA_API ClientMapperJson :  public IMapper<Client>
{
public:

	virtual Value Serialize(Client entity) override;

	virtual Client Deserialize(Value input) override;

};


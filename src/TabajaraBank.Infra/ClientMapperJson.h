#pragma once

#include "IClientMapper.h"

class TABAJARABANKINFRA_API ClientMapperJson :  public IClientMapper
{
public:

	virtual Value Serialize(Client entity) override;

	virtual Client Deserialize(Value input) override;

};


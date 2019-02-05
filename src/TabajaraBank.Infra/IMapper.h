#pragma once

#include "Export.h"
#include "json\json.h"

using namespace Json;

template <class T>
struct TABAJARABANKINFRA_API IMapper
{
	virtual Value Serialize(T entity) = 0;
	virtual T Deserialize(Value input) = 0;
};
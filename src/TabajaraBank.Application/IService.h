#pragma once

#include "Export.h"
#include <vector>

template <class T>
struct TABAJARABANKAPPLICATION_API IService
{
	virtual ~IService() = default;
	virtual int Add(T & entity) = 0;
	virtual bool Update(T & entity) = 0;
	virtual T GetById(int id) = 0;
	virtual std::vector<T> GetAll() = 0;
	virtual bool Remove(int entityId) = 0;
};
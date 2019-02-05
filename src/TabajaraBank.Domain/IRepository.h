#pragma once
#include "Export.h"
#include <vector>

using namespace std;

template<class T>
struct TABAJARABANKDOMAIN_API IRepository
{
	virtual ~IRepository() = default;

	virtual int Add(T entity) = 0;
	virtual bool Update(T entity) = 0;
	virtual T GetById(int id) = 0;
	virtual vector<T> GetAll() = 0;
	virtual bool Remove(int clientId) = 0;
};


#pragma once
#include <memory>
#include "corvusoft\restbed.hpp"

using namespace std;
using namespace restbed;

struct IResourceAPI
{
	virtual ~IResourceAPI() = default;
	virtual void Post(const shared_ptr< Session > session) = 0;
	virtual void Get(const shared_ptr< Session > session) = 0;
	virtual void Put(const shared_ptr< Session > session) = 0;
	virtual void Delete(const shared_ptr< Session > session) = 0;
};
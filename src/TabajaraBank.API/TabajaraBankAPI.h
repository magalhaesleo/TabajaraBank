#pragma once

#include <memory>
#include "corvusoft/restbed.hpp"
#include "IClientResourceAPI.h"
#include <vector>

using namespace std;
using namespace restbed;

class TabajaraBankAPI
{
	vector<shared_ptr<Resource>> _resources;
	shared_ptr<IClientResourceAPI> _clientResource;
	void RegisterResources();
public:
	TabajaraBankAPI(shared_ptr<IClientResourceAPI> clientResource);
	void Initialize();
};


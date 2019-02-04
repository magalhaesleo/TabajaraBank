// TabajaraBank.API.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "TabajaraBankAPI.h"
#include "BoostDIContainer.h"

using namespace std;

int main()
{
	BoostDIContainer container;
	auto injector = container.MakeInjector();
	
	std::unique_ptr<TabajaraBankAPI> api = injector.create<std::unique_ptr<TabajaraBankAPI>>();
	api->Initialize();
}
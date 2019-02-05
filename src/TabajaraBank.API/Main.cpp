// TabajaraBank.API.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "BoostDIContainer.h"

using namespace std;

int main()
{
	auto injector = MakeInjector();
	
	std::unique_ptr<TabajaraBankAPI> api = injector.create<std::unique_ptr<TabajaraBankAPI>>();
	api->Initialize();
}
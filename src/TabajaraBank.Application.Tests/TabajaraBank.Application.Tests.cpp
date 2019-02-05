// TabajaraBank.Application.Tests.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "gtest/gtest.h"
#include <iostream>
#include "../TabajaraBank.Application/ClientService.h"
#include "fakeit.hpp"

using namespace std;
using namespace fakeit;

class Application_Client_Service : public ::testing::Test
{
protected:
	Mock<IClientRepository> _clientRepositoryMock;
	shared_ptr<IClientService> _clientService;

	void SetUp() override
	{
		 _clientService = shared_ptr<IClientService>(new ClientService(_clientRepositoryMock.get()));
	}
};

TEST_F(Application_Client_Service, Add_Client_Should_Be_Ok)
{
	When(Method(_clientRepositoryMock, Add)).Return(1);
	Client client;

	int result = _clientService->Add(client);
	int idExpected = 1;

	ASSERT_EQ(result, idExpected);
	Verify(Method(_clientRepositoryMock, Add)).AtLeast(1);
	VerifyNoOtherInvocations(_clientRepositoryMock);
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
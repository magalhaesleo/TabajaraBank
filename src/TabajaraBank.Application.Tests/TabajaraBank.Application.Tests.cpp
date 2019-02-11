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
		Fake(Dtor(_clientRepositoryMock));
		 _clientService = shared_ptr<IClientService>(new ClientService(shared_ptr<IClientRepository>(&_clientRepositoryMock.get())));
	}
};

TEST_F(Application_Client_Service, Add_Client_Should_Be_Ok)
{
	int idExpected = 1;
	When(Method(_clientRepositoryMock, Add)).Return(idExpected);
	Mock<Client> client;

	int result = _clientService->Add(client.get());

	ASSERT_EQ(result, idExpected);
	Verify(Method(_clientRepositoryMock, Add).Using(Any<Client>())).AtLeast(1);
	VerifyNoOtherInvocations(_clientRepositoryMock);
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
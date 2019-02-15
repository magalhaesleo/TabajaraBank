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
	When(Method(client, Validate)).Return();
	
	int result = _clientService->Add(client.get());

	ASSERT_EQ(result, idExpected);
	Verify(Method(_clientRepositoryMock, Add).Using(Any<Client>())).AtLeast(1);
	VerifyNoOtherInvocations(_clientRepositoryMock);
}

TEST_F(Application_Client_Service, Add_Client_Should_Fail)
{
	Client client;

	ASSERT_ANY_THROW(_clientService->Add(client));

	VerifyNoOtherInvocations(_clientRepositoryMock);
}

TEST_F(Application_Client_Service, Update_Client_Should_Ok)
{
	
	Client client;
	client.set_name("Leonardo");
	client.set_id(1);
	client.set_birthdate("10/04/1996");
	client.set_rg("8843");
	client.set_cpf("011.851.169.66");
	bool idExpected = true;
	When(Method(_clientRepositoryMock, Update)).Return(idExpected);

	bool idreturned = _clientService->Update(client);

	ASSERT_TRUE(idreturned);

	Verify(Method(_clientRepositoryMock, Update).Using(Any<Client>())).AtLeast(1);
	VerifyNoOtherInvocations(_clientRepositoryMock);
}

TEST_F(Application_Client_Service, Update_Client_Should_Fail)
{
	Client client;

	ASSERT_ANY_THROW(_clientService->Update(client));

	VerifyNoOtherInvocations(_clientRepositoryMock);
}


TEST_F(Application_Client_Service, Remove_Client_Should_Ok)
{
	bool expected = true;
	When(Method(_clientRepositoryMock, Remove)).Return(expected);

	int clientId = 1;
	bool result = _clientService->Remove(clientId);

	ASSERT_TRUE(result);

	Verify(Method(_clientRepositoryMock, Remove).Using(Any<int>())).AtLeast(1);
	VerifyNoOtherInvocations(_clientRepositoryMock);
}

TEST_F(Application_Client_Service, Remove_Client_Should_Fail)
{
	int clientId = -5;
	bool result = _clientService->Remove(clientId);

	ASSERT_FALSE(result);

	VerifyNoOtherInvocations(_clientRepositoryMock);
}

TEST_F(Application_Client_Service, Get_Client_Should_Be_Ok)
{
	int clientId = 1;
	Client expected;
	expected.set_id(1);

	When(Method(_clientRepositoryMock, GetById)).Return(expected);

	Client clientReturned = _clientService->GetById(clientId);
	
	ASSERT_EQ(clientReturned.get_id(), expected.get_id());

	Verify(Method(_clientRepositoryMock, GetById).Using(Any<int>())).AtLeast(1);
	VerifyNoOtherInvocations(_clientRepositoryMock);
}

TEST_F(Application_Client_Service, Get_Client_Should_Fail)
{
	int clientId = -5;

	ASSERT_ANY_THROW(_clientService->GetById(clientId));

	VerifyNoOtherInvocations(_clientRepositoryMock);
}

TEST_F(Application_Client_Service, Get_All_Should_Be_Ok)
{
	int clientId = 1;
	vector<Client> expected;
	Mock<Client> client;
	expected.push_back(client.get());

	When(Method(_clientRepositoryMock, GetAll)).Return(expected);

	vector<Client> clientReturned = _clientService->GetAll();

	int total = 1;
	ASSERT_EQ(clientReturned.size(), total);

	Verify(Method(_clientRepositoryMock, GetAll)).AtLeast(1);
	VerifyNoOtherInvocations(_clientRepositoryMock);
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
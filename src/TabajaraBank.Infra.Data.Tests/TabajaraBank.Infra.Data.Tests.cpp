// TabajaraBank.Infra.Data.Tests.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "gtest\gtest.h"
#include "fakeit.hpp"
#include "..\TabajaraBank.Domain\IClientRepository.h"
#include "..\TabajaraBank.Infra.Data\ClientRepository.h"

using namespace fakeit;

class InfraData_ClientRepository_Test : public ::testing::Test
{
protected:

	shared_ptr<IClientRepository> _clientRepository;
	shared_ptr<DBManager> _dbManager;
	void SetUp() override
	{
		_dbManager = make_shared(new DBManager());
		//Fake(Dtor(_dbManager));
		_clientRepository = shared_ptr<IClientRepository>(new ClientRepository());
	}

};

TEST_F(InfraData_ClientRepository_Test, Client_Add_Should_Be_Ok)
{
	/*Mock<Client> clientMock;
	int idExpected = 1;
	When(Method(_dbManager, Insert)).Return(idExpected);

	int result = _clientRepository->Add(clientMock.get());


	ASSERT_EQ(idExpected, result);

	Verify(Method(_dbManager, Insert).Using(Any<string>())).AtLeast(1);
	VerifyNoOtherInvocations(_dbManager);*/
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
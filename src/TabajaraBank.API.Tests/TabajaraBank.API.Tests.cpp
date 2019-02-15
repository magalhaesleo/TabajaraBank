// TabajaraBank.API.Tests.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "gtest\gtest.h"
#include "fakeit.hpp"
#include "..\TabajaraBank.API\ClientResourceAPI.h"
#include "..\TabajaraBank.Domain\IClientRepository.h"
#include "corvusoft\restbed.hpp"
#include "..\TabajaraBank.Infra\IClientMapper.h"
#include "json\json.h"

using namespace std;
using namespace fakeit;

class API_ClientResource_Test : public ::testing::Test
{
protected:
	shared_ptr<IClientResourceAPI> _clientResourceAPI;
	Mock<IClientService>  _clientServiceMock;
	Mock<IClientMapper> _clientMapperMock;

	void SetUp() override
	{
		Fake(Dtor(_clientServiceMock));
		Fake(Dtor(_clientMapperMock));
		_clientResourceAPI = shared_ptr<IClientResourceAPI>(new ClientResourceAPI( shared_ptr<IClientService >(&_clientServiceMock.get()), shared_ptr<IClientMapper>(&_clientMapperMock.get())));

	}

};

TEST_F(API_ClientResource_Test, Get_Client_Should_Be_Ok)
{
	Mock<Client> clientMock;
	Json::Value root;
	When(Method(_clientServiceMock, GetById)).Return(clientMock.get());
	When(Method(_clientMapperMock, Serialize)).Return(root);
	string id = "teste";
	Session session(id);
	
	_clientResourceAPI->Get(shared_ptr<Session>(&session));



	Verify(Method(_clientServiceMock, GetById).Using(Any<int>())).AtLeast(1);
	VerifyNoOtherInvocations(_clientServiceMock);
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
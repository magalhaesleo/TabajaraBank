// TabajaraBank.Domain.Tests.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "gtest\gtest.h"
#include "..\TabajaraBank.Domain\Client.h"
#include "..\TabajaraBank.Domain\ShortNameException.h"

class Domain_Client_Service_Test : public ::testing::Test
{
protected:
	Client* client;
	void SetUp() override
	{
		client = new Client();
	}
	void TearDown() override
	{
		delete client;
	}
};

TEST_F(Domain_Client_Service_Test, Create_Client_should_be_ok)
{
	client->set_id(1);
	client->set_name("Khristian");
	client->set_cpf("999.999.999-10");
	client->set_rg("9.999.999-99");
	client->set_birthdate("19/06/1987");

	ASSERT_NO_THROW(client->Validate());
}

TEST_F(Domain_Client_Service_Test, Create_Client_should_fail_name)
{
	client->set_id(1);
	client->set_name("ab");
	client->set_cpf("999.999.999-10");
	client->set_rg("9.999.999-99");
	client->set_birthdate("19/06/1987");

	ASSERT_THROW(client->Validate(), ShortNameException);
}

TEST_F(Domain_Client_Service_Test, Create_Client_should_fail_id)
{
	client->set_name("leonardo");
	client->set_cpf("999.999.999-10");
	client->set_rg("9.999.999-99");
	client->set_birthdate("19/06/1987");
	client->set_id(0);

	ASSERT_ANY_THROW(client->Validate());
}

TEST_F(Domain_Client_Service_Test, Create_Client_should_fail_cpf)
{
	client->set_id(1);
	client->set_cpf("0");
	client->set_name("Khristian");
	
	ASSERT_ANY_THROW(client->Validate());
}

TEST_F(Domain_Client_Service_Test, Create_Client_should_fail_rg)
{
	client->set_id(1);
	client->set_name("Khristian");
	client->set_cpf("999.999.999-10");
	client->set_rg("0");


	ASSERT_ANY_THROW(client->Validate());
}

TEST_F(Domain_Client_Service_Test, Create_Client_should_fail_birthdate)
{
	client->set_id(1);
	client->set_cpf("0");

	ASSERT_ANY_THROW(client->Validate());
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
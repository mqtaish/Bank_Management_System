#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include <iomanip>
#include "clsInputValidate.h"
class clsFindClientScreen : protected clsScreen
{
private:
	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << Client.FirstName;
		cout << "\nLastName    : " << Client.LastName;
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nEmail       : " << Client.Email;
		cout << "\nPhone       : " << Client.Phone;
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nPassword    : " << Client.PinCode;
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";

	}
public:
	static void ShowFindClientScreen() {

		if (!CheckAccessRights(clsUser::enPermissions::pFindClient)) {
			return;
		}

		string AccountNumber = "";
		_DrawScreenHeader("\t  Find Client Screen");

		cout << "\nEnter Account Number: ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber, FileName)) {
			cout << "Account number isn't found, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}


		clsBankClient Client = clsBankClient::Find(AccountNumber, FileName);
		
		if (!Client.IsEmpty()) {
			cout << "\nClient Found\n";
		}
		else {
			cout << "\n Client Wan't Found\n";
		}

		_PrintClient(Client);

	}
};


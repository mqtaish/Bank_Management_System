#pragma once


#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include <iomanip>
#include "clsInputValidate.h"

class clsDeleteClientScreen : public clsScreen
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

	static void ShowDelteClientScreen() {

		if (!CheckAccessRights(clsUser::enPermissions::pDeleteClient)) {
			return;
		}

			string AccountNumber = "";
			_DrawScreenHeader("\t  Delete Client Screen");

			cout << "\nEnter Account Number: ";
			AccountNumber = clsInputValidate::ReadString();

			while (!clsBankClient::IsClientExist(AccountNumber, FileName)) {
				cout << "Account number isn't found, choose another one: ";
				AccountNumber = clsInputValidate::ReadString();
			}


			clsBankClient Client = clsBankClient::Find(AccountNumber, FileName);

			_PrintClient(Client);
			clsBankClient::enSaveResults SaveResult;

			char Answer = 'n';

			cout << "\n\nAre you sure you want delete this client? y/n ? ";
			cin >> Answer;

			if (Answer == 'y' || Answer == 'Y')
			{
				if (Client.Delete()) {
					cout << "\nClient Deleted Successfully\n";
					_PrintClient(Client);
				}
				else
				{
					cout << "Error Client wasn't Deleted\n";
				}

			}

	}

};


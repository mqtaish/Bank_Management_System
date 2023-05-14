#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include <iomanip>
#include "clsInputValidate.h"
#include "clsMainScreen.h"

class clsDepositClientScreen : protected clsScreen
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

	static string _ReadAccountNumber()
	{
		string AccountNumber = "";
		cout << "\nPlease enter AccountNumber? ";
		cin >> AccountNumber;
		return AccountNumber;
	}

public:

	static void ShowDepositClientScreen() {
		_DrawScreenHeader("\t  Deposit Client Screen");

		cout << "\nEnter Account Number: ";
		string AccountNumber = _ReadAccountNumber();

		while (!clsBankClient::IsClientExist(AccountNumber, FileName)) {
			cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
			AccountNumber = _ReadAccountNumber();
		}

		
		clsBankClient Client = clsBankClient::Find(AccountNumber, FileName);
		_PrintClient(Client);

		double Amount = 0;
		cout << "Enter Deposit Amount: ";
		Amount = clsInputValidate::ReadDblNumber();

		cout << "Are You Sure Do You Want To Perform this Operation? Y/N: ";
		char Answer = 'N';
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y') {
			Client.Deposit(Amount);
			cout << "\nAmount Deposited Successfully\n";
			cout << "\nNew Balance is: " << Client.AccountBalance;
		}
		else {
			cout << "Operation was canelled.\n";
		}

	}

};


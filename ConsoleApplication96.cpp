#include <iostream>
#include "clsCurrency.h"
#include "clsLoginScreen.h"
int main()

{
	while (true) {


		if (!clsLoginScreen::ShowLoginScreen())
			break;

	}
	system("pause>0");
	return 0;


}





/*void ReadClientInfo(clsBankClient& Client)
{
	cout << "\nEnter FirstName: ";
	Client.FirstName = clsInputValidate::ReadString();

	cout << "\nEnter LastName: ";
	Client.LastName = clsInputValidate::ReadString();

	cout << "\nEnter Email: ";
	Client.Email = clsInputValidate::ReadString();

	cout << "\nEnter Phone: ";
	Client.Phone = clsInputValidate::ReadString();

	cout << "\nEnter PinCode: ";
	Client.PinCode = clsInputValidate::ReadString();

	cout << "\nEnter Account Balance: ";
	Client.AccountBalance = clsInputValidate::ReadFloatNumber();
}

void UpdateClient() {

	string AccountNumber = "";
	cout << "Enter Account Number: \n";
	AccountNumber = clsInputValidate::ReadString();

	while (!clsBankClient::IsClientExist(AccountNumber, FileName))
	{
		cout << "Account number isn't found, choose another one: ";
		AccountNumber = clsInputValidate::ReadString();
	}

	clsBankClient Client = clsBankClient::Find(AccountNumber, FileName);

	Client.Print();
	ReadClientInfo(Client);
	clsBankClient::enSaveResults SaveResult;

	SaveResult =Client.Save();

	switch (SaveResult)
	{
	case clsBankClient::enSaveResults::svSucceeded:
	{
		cout << "\nAccount Upldated Successfully\n";
		Client.Print();
		break;
	}
	case clsBankClient::enSaveResults::svFaildEmptyObject:
		cout << "Account isn't upldated\n";
		break;

	}

}

void AddNewClient() {

	string AccountNumber = "";

	while (clsBankClient::IsClientExist(AccountNumber,FileName)) {
		cout << "Account number isn't found, choose another one: ";
		AccountNumber = clsInputValidate::ReadString();
	}

	clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

	ReadClientInfo(NewClient);

	clsBankClient::enSaveResults SaveResult;

	SaveResult = NewClient.Save();

}

void DeleteClient() {

	string AccountNumber = "";


	cout << "\nEnter Account Number: \n";
	AccountNumber = clsInputValidate::ReadString();

	while (!clsBankClient::IsClientExist(AccountNumber, FileName)) {
		cout << "Account number isn't found, choose another one: ";
		AccountNumber = clsInputValidate::ReadString();
	}


	clsBankClient Client = clsBankClient::Find(AccountNumber, FileName);

	Client.Print();

	//clsBankClient::enSaveResults SaveResult;

	char Answer = 'n';

	cout << "\n\nAre you sure you want delete this client? y/n ? ";
	cin >> Answer;

	if (Answer == 'y' || Answer == 'Y')
	{
		if (Client.Delete()) {
			cout << "\nClient Deleted Successfully\n";
			Client.Print();
		}
		else
		{
			cout << "Error Client wasn't Deleted\n";
		}

	}
}

void PrintClientRecordLine(clsBankClient Client)
{

	cout << "| " << setw(15) << left << Client.AccountNumber();
	cout << "| " << setw(10) << left << Client.PinCode;
	cout << "| " << setw(40) << left << Client.FullName();
	cout << "| " << setw(12) << left << Client.Phone;
	cout << "| " << setw(12) << left << Client.AccountBalance;

}

void ListClient() {
	vector <clsBankClient> vClients = clsBankClient::GetClientList();

	cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;

	cout << "| " << left << setw(15) << "Accout Number";
	cout << "| " << left << setw(10) << "Pin Code";
	cout << "| " << left << setw(40) << "Client Name";
	cout << "| " << left << setw(12) << "Phone";
	cout << "| " << left << setw(12) << "Balance";
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;

	if (vClients.size() == 0)
		cout << "\t\t\t\tNo Clients Available In the System!";
	else

		for (clsBankClient Client : vClients)
		{

			PrintClientRecordLine(Client);
			cout << endl;
		}

	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;

}

void PrintClientRecordBalanceLine(clsBankClient Client)
{

	cout << "| " << setw(15) << left << Client.AccountNumber();
	cout << "| " << setw(40) << left << Client.FullName();
	cout << "| " << setw(12) << left << Client.AccountBalance;

}

void ShowTotalBalances()
{

	vector <clsBankClient> vClients = clsBankClient::GetClientList();

	cout << "\n\t\t\t\t\tBalances List (" << vClients.size() << ") Client(s).";
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;

	cout << "| " << left << setw(15) << "Accout Number";
	cout << "| " << left << setw(40) << "Client Name";
	cout << "| " << left << setw(12) << "Balance";
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;

	double TotalBalances = 0;

	if (vClients.size() == 0)
		cout << "\t\t\t\tNo Clients Available In the System!";
	else

		for (clsBankClient Client : vClients)
		{

			PrintClientRecordBalanceLine(Client);
			TotalBalances += Client.AccountBalance;

			cout << endl;
		}

	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
	cout << "\t\t\t\t\t   Total Balances = " << TotalBalances << endl;
	cout << "\t\t\t\t\t "<< clsUtil::NumberToText(TotalBalances);
} */

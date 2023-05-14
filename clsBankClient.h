#pragma once

#pragma warning(disable : 4996)

#include <string>
#include<iostream>
#include "clsString.h"
#include "clsPerson.h"
#include <fstream>
using namespace std;

const string FileName = "Clients.txt";



class clsBankClient : public clsPerson
{
private:
	struct stTrnsferLogRecord;
	enum enMode{Empty= 0 , UpdateMode = 1, AddNewMode= 2, DeleteClient = 3};
	 enMode _Mode;
	 string _AccountNumber;
	 string _Pincode;
	 float _Balance = 0;
	 bool MarkForDelete = false;


	 static clsBankClient _ConvertLinetoClientObject(string Line, string Seperator = "#//#")
	{
		vector<string> vClientData;
		vClientData = clsString::Split(Line, Seperator);

		return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
			vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));

	}

	 static clsBankClient _GetEmptyClientObject()
	 {
		 return clsBankClient(enMode::Empty, "", "", "", "", "", "", 0);
	 }

	 static  vector <clsBankClient> _LoadCleintsDataFromFile(string FileName)
	 {

		 vector <clsBankClient> vClients;

		 fstream MyFile;
		 MyFile.open(FileName, ios::in);//read Mode

		 if (MyFile.is_open())
		 {

			 string Line;

			 while (getline(MyFile, Line))
			 {

				 clsBankClient Client = _ConvertLinetoClientObject(Line);

				 vClients.push_back(Client);
			 }

			 MyFile.close();

		 }

		 return vClients;

	 }

	 static void _SaveCleintsDataToFile(vector <clsBankClient> vClients)
	 {

		 fstream MyFile;
		 MyFile.open("Clients.txt", ios::out);//overwrite

		 string DataLine;

		 if (MyFile.is_open())
		 {

			 for (clsBankClient C : vClients)
			 {
				 DataLine = _ConverClientObjectToLine(C);
				 MyFile << DataLine << endl;

			 }

			 MyFile.close();

		 }

	 }

	 static string _ConverClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
	 {

		 string stClientRecord = "";
		 stClientRecord += Client.FirstName + Seperator;
		 stClientRecord += Client.LastName + Seperator;
		 stClientRecord += Client.Email + Seperator;
		 stClientRecord += Client.Phone + Seperator;
		 stClientRecord += Client._AccountNumber + Seperator;
		 stClientRecord += Client._Pincode + Seperator;
		 stClientRecord += to_string(Client._Balance);

		 return stClientRecord;

	 }

	 vector <clsBankClient> _SaveCleintsDataToFile(string FileName, vector <clsBankClient> vClients)
	 {

		 fstream MyFile;
		 MyFile.open(FileName, ios::out);//overwrite

		 string DataLine;

		 if (MyFile.is_open())
		 {

			 for (clsBankClient C : vClients)
			 {

				 if (C.MarkForDelete == false)
				 {
					 //we only write records that are not marked for delete.  
					 DataLine = _ConverClientObjectToLine(C);
					 MyFile << DataLine << endl;

				 }

			 }

			 MyFile.close();

		 }

		 return vClients;
	 }

	 void _Update()
	 {
		vector <clsBankClient> _vClients;
		_vClients =  _LoadCleintsDataFromFile("Clients.txt");
		 for (clsBankClient & C : _vClients)
		 {
			 if ( C._AccountNumber == AccountNumber())
			 {
				 C = *this;
				 break;
			 }

		 }

		 _SaveCleintsDataToFile("Clients.txt", _vClients);

	 }

	 void AddDataLineToFile(string FileName, string  stDataLine)
	 {
		 fstream MyFile;
		 MyFile.open(FileName, ios::out | ios::app);

		 if (MyFile.is_open())
		 {

			 MyFile << stDataLine << endl;

			 MyFile.close();
		 }

	 }

	 void _AddNew() {
		 AddDataLineToFile( FileName,_ConverClientObjectToLine(*this));
	 }

	 string _PrepareTransferLogRecord(float Amount, clsBankClient DestinationClient,string UserName, string Seperator = "#//#")
	 {
		 string TransferLogRecord = "";
		 TransferLogRecord += clsDate::GetSystemDateTimeString() + Seperator;
		 TransferLogRecord += AccountNumber() + Seperator;
		 TransferLogRecord += DestinationClient.AccountNumber() + Seperator;
		 TransferLogRecord += to_string(Amount) + Seperator;
		 TransferLogRecord += to_string(AccountBalance) + Seperator;
		 TransferLogRecord += to_string(DestinationClient.AccountBalance) + Seperator;
		 TransferLogRecord += UserName;
		 return TransferLogRecord;
	 }



	  void _RegisterTransferLog(float Amount, clsBankClient DestinationClient, string UserName) {

		 string stDataLine = _PrepareTransferLogRecord(Amount, DestinationClient, UserName);

		 fstream MyFile;

		 MyFile.open("TransferLog.txt", ios::out | ios::app);

		 if (MyFile.is_open())
		 {

			 MyFile << stDataLine << endl;

			 MyFile.close();
		 }

	 }

	  static stTrnsferLogRecord _ConvertTransferLogLineToRecord(string Line, string Seperator = "#//#")
	  {
		  stTrnsferLogRecord TrnsferLogRecord;

		  vector <string> vTrnsferLogRecordLine = clsString::Split(Line, Seperator);
		  TrnsferLogRecord.DateTime = vTrnsferLogRecordLine[0];
		  TrnsferLogRecord.SourceAccountNumber = vTrnsferLogRecordLine[1];
		  TrnsferLogRecord.DestinationAccountNumber = vTrnsferLogRecordLine[2];
		  TrnsferLogRecord.Amount = stod(vTrnsferLogRecordLine[3]);
		  TrnsferLogRecord.srcBalanceAfter = stod(vTrnsferLogRecordLine[4]);
		  TrnsferLogRecord.destBalanceAfter = stod(vTrnsferLogRecordLine[5]);
		  TrnsferLogRecord.UserName = vTrnsferLogRecordLine[6];

		  return TrnsferLogRecord;

	  }

public:

	struct stTrnsferLogRecord
	{
		string DateTime;
		string SourceAccountNumber;
		string DestinationAccountNumber;
		float Amount;
		float srcBalanceAfter;
		float destBalanceAfter;
		string UserName;

	};

	//clsBankClient():clsPerson("","","","") {}

	clsBankClient(enMode Mode, string FirstName, string LastName,
		string Email, string Phone, string AccountNumber, string PinCode,
		float AccountBalance) :
		clsPerson(FirstName, LastName, Email, Phone)

	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_Pincode = PinCode;
		_Balance = AccountBalance;

	}

	bool IsEmpty() {
		return (_Mode == enMode::Empty);
	}


	string AccountNumber()
	{
		return _AccountNumber;
	}

	void SetPinCode(string PinCode)
	{
		_Pincode = PinCode;
	}

	string GetPinCode()
	{
		return _Pincode;
	}
	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

	void SetAccountBalance(float AccountBalance)
	{
		_Balance = AccountBalance;
	}

	float GetAccountBalance()
	{
		return _Balance;
	}

	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

	static clsBankClient Find(string AccountNumber, string FileName)
	{

		vector <clsBankClient> vClients;

		fstream MyFile;
		MyFile.open(FileName, ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLinetoClientObject(Line);

				if (Client._AccountNumber == AccountNumber)
				{
					MyFile.close();
					return Client;
				}
			}

			MyFile.close();

		}
		return _GetEmptyClientObject();
	}

	static clsBankClient Find(string AccountNumber, string Pincode, string FileName)
	{

		vector <clsBankClient> vClients;

		fstream MyFile;
		MyFile.open(FileName, ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))

			{
				clsBankClient Client = _ConvertLinetoClientObject(Line);

				if ((Client._AccountNumber == AccountNumber) && (Client._Pincode == Pincode))
				{
					MyFile.close();
					return Client;
				}

			}

			MyFile.close();

		}
		return _GetEmptyClientObject();

	}

	static bool IsClientExist(string AccountNumber, string FileName)
	{
		clsBankClient Client = Find(AccountNumber, FileName);
		return (!Client.IsEmpty());
	}

	void Print()
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << FirstName;
		cout << "\nLastName    : " << LastName;
		cout << "\nFull Name   : " << FullName();
		cout << "\nEmail       : " << Email;
		cout << "\nPhone       : " << Phone;
		cout << "\nAcc. Number : " << _AccountNumber;
		cout << "\nPassword    : " << _Pincode;
		cout << "\nBalance     : " << _Balance;
		cout << "\n___________________\n";

	}

	enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1 , svFailedAccountNumberExists = 2};

	enSaveResults Save()
	{

		switch (_Mode)
		{
		case enMode::Empty:
		{

			return enSaveResults::svFaildEmptyObject;
		}

		case enMode::UpdateMode:
		{

			_Update();

			return enSaveResults::svSucceeded;

			break;
		}

		case enMode::AddNewMode:
		{

			if (clsBankClient::IsClientExist(_AccountNumber, "Clients.txt")) {
				return enSaveResults::svFailedAccountNumberExists;
			}
			else {
				_AddNew();
				_Mode = enMode::UpdateMode;
				return enSaveResults::svSucceeded;
			}
		}

		case enMode::DeleteClient:
		{

		}
		}
	}


	static clsBankClient GetAddNewClientObject(string AccountNumber) {
		return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber,"", 0);
	}

	bool Delete() {


		vector <clsBankClient> vClients = _LoadCleintsDataFromFile(FileName);
		for (clsBankClient& C : vClients)
		{
			if (C.AccountNumber() == _AccountNumber)
			{
				C.MarkForDelete = true;
			}
		}

		_SaveCleintsDataToFile(FileName, vClients);

		*this = _GetEmptyClientObject();

		return true;
	}


	static vector< clsBankClient> GetClientList() {
		return _LoadCleintsDataFromFile(FileName);
	}

	void Deposit(double Amount) {
		_Balance += Amount;
		Save();
	}

	bool Withdraw(double Amount) {
		if (Amount > _Balance) {
			return false;
		}
		else {
			_Balance -= Amount;
			Save();
			return true;
		}
	}

	static double GetTotalBalances() {
		vector <clsBankClient> vClients = clsBankClient::GetClientList();
		double TotalBalances = 0;
		for (clsBankClient& Client : vClients) {
			TotalBalances += Client.AccountBalance;
		}
		return TotalBalances;
	}

	bool Transfer(float Amount, clsBankClient& DestinationClient, string UserName) {
		if (Amount > AccountBalance) {
			return false;
		}

		Withdraw(Amount);
		DestinationClient.Deposit(Amount);
		_RegisterTransferLog(Amount, DestinationClient, UserName);
		return true;

	}

	static  vector <stTrnsferLogRecord> GetTransfersLogList()
	{
		vector <stTrnsferLogRecord> vTransferLogRecord;

		fstream MyFile;
		MyFile.open("TransfersLog.txt", ios::in);//read Mode
		if (MyFile.is_open())
		{

			string Line;

			stTrnsferLogRecord TransferRecord;

			while (getline(MyFile, Line))
			{

				TransferRecord = _ConvertTransferLogLineToRecord(Line);

				vTransferLogRecord.push_back(TransferRecord);

			}

			MyFile.close();

		}

		return vTransferLogRecord;

	}
};


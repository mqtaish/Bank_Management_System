#pragma once
#include <string>
#include<iostream>
#include "clsString.h"
#include "clsPerson.h"
#include <fstream>
#include "clsBankClient.h"

class clsTransferLogScreen : protected clsScreen
{

private:


	static void PrintTransferLogRecordLine(clsBankClient::stTrnsferLogRecord TransferLogRecord)
	{

		cout << setw(8) << left << "" << "| " << setw(23) << left << TransferLogRecord.DateTime;
		cout << "| " << setw(8) << left << TransferLogRecord.SourceAccountNumber;
		cout << "| " << setw(8) << left << TransferLogRecord.DestinationAccountNumber;
		cout << "| " << setw(8) << left << TransferLogRecord.Amount;
		cout << "| " << setw(10) << left << TransferLogRecord.srcBalanceAfter;
		cout << "| " << setw(10) << left << TransferLogRecord.destBalanceAfter;
		cout << "| " << setw(8) << left << TransferLogRecord.UserName;


	}



	



	/*static void _LoadDataFromFileToRecord() { To Remember Code What Code You Written;
		clsBankClient::stTransferLog TransferLog;

		fstream file;
		string Record;
		vector < clsBankClient::stTransferLog> vTransferLog;
		clsBankClient::stTransferLog TransferLog;
		file.open("TransferLog.txt", ios::in);
		if (file.is_open()) {
			while (getline(file, Record)) {
				TransferLog = _ConvertRecordToTransferLog(Record);
				_PrintRecordLine(TransferLog);
				vTransferLog.push_back(TransferLog);
			}
		}
			
	}*/
public:
	static void ShowTransferLogScreen()
	{


		vector <clsBankClient::stTrnsferLogRecord> vTransferLogRecord = clsBankClient::GetTransfersLogList();

		string Title = "\tTransfer Log List Screen";
		string SubTitle = "\t    (" + to_string(vTransferLogRecord.size()) + ") Record(s).";

		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(23) << "Date/Time";
		cout << "| " << left << setw(8) << "s.Acct";
		cout << "| " << left << setw(8) << "d.Acct";
		cout << "| " << left << setw(8) << "Amount";
		cout << "| " << left << setw(10) << "s.Balance";
		cout << "| " << left << setw(10) << "d.Balance";
		cout << "| " << left << setw(8) << "User";

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (vTransferLogRecord.size() == 0)
			cout << "\t\t\t\tNo Transfers Available In the System!";
		else

			for (clsBankClient::stTrnsferLogRecord Record : vTransferLogRecord)
			{

				PrintTransferLogRecordLine(Record);
				cout << endl;
			}

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

	}
};


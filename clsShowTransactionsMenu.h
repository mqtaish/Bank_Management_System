
#pragma once
#include "clsScreen.h"
#include "clsMainScreen.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogScreen.h"
class clsShowTransactionsMenu : protected clsScreen 
{

private:


	enum enTransactionsMenueOptions { eDeposit = 1, eWithdraw = 2, eShowTotalBalance = 3, eTransfer = 4, eTransferLogs = 5, eShowMainMenue = 6};

    static short ReadTransactionsMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number between 1 to 6? ");
        return Choice;
    }

   static void _GoBackToTransactionsMenue()
    {
        cout << "\n\nPress any key to go back to Transactions Menue...";
       system("pause>0");
      //  clsMainScreen::ShowMainMenu();
        //do nothing here the main screen will handle it :-) ;

    }

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
   static void _ShowDepositScreen()
   {
       clsDepositClientScreen::ShowDepositClientScreen();
    
   }
   static void _ShowWithDrawScreen(){
       clsWithdrawScreen::ShowWithdrawScreen();
   }

   static void _ShowTotalBalancesScreen() {
       clsTotalBalancesScreen::ShowTotalBalances();
   }

   static void _ShowTransferScreen() {
       clsTransferScreen::ShowTransferScreen();
   }

   static void _ShowTransferLogScreen() {
       clsTransferLogScreen::ShowTransferLogScreen();
   }


   static void _PerfromTranactionsMenueOption(enTransactionsMenueOptions TransactionMenueOption)
   {
       switch (TransactionMenueOption)
       {
       case enTransactionsMenueOptions::eDeposit:
       {
           system("cls");
           _ShowDepositScreen();
           _GoBackToTransactionsMenue();
           break;
       }

       case enTransactionsMenueOptions::eWithdraw:
       {
           system("cls");
           _ShowWithDrawScreen();
           _GoBackToTransactionsMenue();
           break;
       }


       case enTransactionsMenueOptions::eShowTotalBalance:
       {
           system("cls");
           _ShowTotalBalancesScreen();
           _GoBackToTransactionsMenue();
           break;
       }

       case enTransactionsMenueOptions::eTransfer:
       {
           system("cls");
           _ShowTransferScreen();
           _GoBackToTransactionsMenue();
           break;
       }

       case enTransactionsMenueOptions::eTransferLogs:
       {
           system("cls");
           _ShowTransferLogScreen();
           _GoBackToTransactionsMenue();
           break;
       }
       case enTransactionsMenueOptions::eShowMainMenue:
       {

           //   ShowMainMenue();
           _GoBackToTransactionsMenue();

       }
       }

   }

public:

    static void ShowTransactionsMenue()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pTranactions)) {
            return;
        }

        system("cls");
        _DrawScreenHeader("\t  Transactions Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Transactions Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
        cout << setw(37) << left << "" << "\t[4] Transfer.\n";
        cout << setw(37) << left << "" << "\t[5] Transfer Logs.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromTranactionsMenueOption((enTransactionsMenueOptions)ReadTransactionsMenueOption());
    }



};


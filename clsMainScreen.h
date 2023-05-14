#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsShowTransactionsMenu.h"
#include "clsMangeUsersScreen.h"
#include "Global.h"
#include "clsRegisterLoginMenue.h"
#include "clsCurrencyExchangeMainScreen.h"
using namespace std;

class clsMainScreen : protected clsScreen
{
 

    enum enMainMenueOptions {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
        eManageUsers = 7, RegisterLogin = 8 , eCurrencyExchange = 9 , eExit = 10
    };

    static short _ReadMainMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 10]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 9, "Enter Number between 1 to 10? ");
        return Choice;
    }

    static  void _GoBackToMainMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

        system("pause>0");
        ShowMainMenu();
    }

    static void _ShowAllClientsScreen()
    {

        //cout << "\nClient List Screen Will be here...\n";
        clsClientListScreen::ShowClientsList();
    }


    static void _ShowAddNewClientsScreen()
    {
        clsAddNewClientScreen::ShowAddNewClientScreen();

    }

    static void _ShowDeleteClientScreen()
    {
        clsDeleteClientScreen::ShowDelteClientScreen();
    }

    static void _ShowUpdateClientScreen()
    {
        clsUpdateClientScreen::ShowUpdateClientScreen();

    }

    static void _ShowFindClientScreen()
    {
        //cout << "\nFind Client Screen Will be here...\n";
        clsFindClientScreen::ShowFindClientScreen();
    }

    static void _ShowTransactionsMenue()
    {
        clsShowTransactionsMenu::ShowTransactionsMenue();

    }

    static void _ShowManageUsersMenue()
    {
        /*cout << "\nUsers Menue Will be here...\n";*/
        clsManageUsersScreen::ShowManageUsersMenue();
        ShowMainMenu();

    }


    static void _ShowLogoutUsersMenue() {
        CurrentUser = clsUser::Find("", "");
    }


    static void _ShowRegisterLoginMenue() {
        clsRegisterLoginMenue::ShowLoginRegisterScreen();
    }

    static void  _ShowCurrencyExchangeMainScreen() {
        clsCurrencyExchangeMainScreen::ShowCurrenciesMenue();
    }



    static void _PerfromMainMenueOption(enMainMenueOptions  MainMenueOption)
    {

     
       
        switch (MainMenueOption)
        {
        case enMainMenueOptions::eListClients:
        {
            system("cls");
            _ShowAllClientsScreen();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOptions::eAddNewClient:
            system("cls");
            _ShowAddNewClientsScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eDeleteClient:
            system("cls");
            _ShowDeleteClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eUpdateClient:
            system("cls");
            _ShowUpdateClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eFindClient:
            system("cls");
            _ShowFindClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eShowTransactionsMenue:
            system("cls");
            _ShowTransactionsMenue();
            break;

        case enMainMenueOptions::eManageUsers:
            system("cls");
            _ShowManageUsersMenue();
            break;

        case enMainMenueOptions::RegisterLogin:
            system("cls");
            _ShowRegisterLoginMenue();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eCurrencyExchange:
            system("cls");
            _ShowCurrencyExchangeMainScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eExit:
            system("cls");
            _ShowLogoutUsersMenue();


            break;
        }

    }



public:

    static void ShowMainMenu()
    {
        system("cls");

        _DrawScreenHeader("\t\tMain Screen\n");
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8] Register Login.\n";
        cout << setw(37) << left << "" << "\t[9] Currency Exchange.\n";
        cout << setw(37) << left << "" << "\t[10] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";


        _PerfromMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());
    }



};


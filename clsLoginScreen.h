#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "Global.h"

 class clsLoginScreen :protected clsScreen
{

private:
   

     

    static  bool _Login()
    {
        bool LoginFaild = false;
        short FaildLoginCount = 0 ;
        string Username, Password;
        do
        {
            if (LoginFaild) {
                FaildLoginCount++;
                cout << "\nYou Are Locked After 3 trails\n";
                cout << "You Have " << 3 - FaildLoginCount << " Trails to Login\n";

                //system("pause >0");            }
            }
            if (FaildLoginCount == 3)
            {
                return false;
            }

            cout << "Enter Username? ";
            cin >> Username;

            cout << "Enter Password? ";
            cin >> Password;

            CurrentUser = clsUser::Find(Username ,Password);

            LoginFaild = CurrentUser.IsEmpty();

        } while (LoginFaild);
        CurrentUser.RegisterLogIn();
        clsMainScreen::ShowMainMenu();

    }

public:


    static bool ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\t  Login Screen");
       return _Login();

    }

};


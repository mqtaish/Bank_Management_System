#pragma once

#include<iostream>
#include<string>
#include "clsString.h"
#include "InterfaceCommunication.h"
using namespace std;

class clsPerson : public InterfaceCommunication
{
private:
//	string _AccountNumber;
	string _FirstName;
	string _LastName;
	string _Phone;
	string _Email;
//	string _Pincode;
//	double _Balance;

public:
	clsPerson( string FirstName, string LastName, string Phone, string Email)
	{
		_FirstName = FirstName;
		_LastName = LastName;
		_Phone = Phone;
		_Email = Email;
	}

	void SetFirstName(string FirstName) {
		_FirstName = FirstName;
	}

	string GetFirstName() {
		return _FirstName;
	}

	__declspec(property(get = GetFirstName, put = SetFirstName)) string FirstName;

	void SetLastName(string LastName) {
		_LastName = LastName;
	}
	string GetLastName() {
		return _LastName;
	}

	__declspec(property(get = GetLastName, put = SetLastName)) string LastName;

	void SetPhone(string Phone) {
		_Phone = Phone;
	}
	string GetPhone() {
		return _Phone;
	}

	__declspec(property(get = GetPhone, put = SetPhone)) string Phone;

	void SetEmail(string Email) {
		_Email = Email;
	}
	string GetEmail() {
		return _Email;
	}

	__declspec(property(get = GetEmail, put = SetEmail)) string Email;

	string FullName()
	{
		return _FirstName + " " + _LastName;
	}

	 void SendEmail(string Title, string Body) {};
	 void SendFax(string Title, string Body) {};
	 void SendSMS(string Title, string Body) {};

};


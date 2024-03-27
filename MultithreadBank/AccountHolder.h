#pragma once
#include <string>
#include <iostream>
using namespace std;

class AccountHolder
{
private:
	string name, surname;
	int credit_rate;
	string registration_date;
	
public:
	AccountHolder();
	AccountHolder(string, string, int);
	~AccountHolder();
	string getName()const;
	string getSurname()const;
	int getCreditRate()const;
	string getRegistrationDate()const;
};


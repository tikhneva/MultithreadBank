#pragma once
#include "AccountHolder.h"
#include <vector>
class Account
{
private:
	AccountHolder user;
	string account_date,account_time;
	double accountMoney;
	
public:
	Account(AccountHolder);
	Account(AccountHolder,double);
	void setMoney(double);
	double getMoney() const; 
	string getUserName()const;
};


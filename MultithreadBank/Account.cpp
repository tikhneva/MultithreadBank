#define _CRT_SECURE_NO_WARNINGS

#include "Account.h"
#include <iostream>
#include <ctime>


Account::Account(AccountHolder holder):user(holder) {


    time_t now; 
    time(&now); 
    struct tm timeinfo;
    localtime_s(&timeinfo, &now); 
    char formatted_date[11];
    strftime(formatted_date, sizeof(formatted_date), "%Y-%m-%d", &timeinfo);
    account_date = formatted_date;

    char formatted_time[11];
    strftime(formatted_time, sizeof(formatted_time), "%H:%M:%S", &timeinfo);
    account_time = formatted_time;

    accountMoney = 10000;

}

Account::Account(AccountHolder holder,double money) : user(holder),accountMoney(money) {

    this->user = user;

    time_t now;
    time(&now);
    struct tm timeinfo;
    localtime_s(&timeinfo, &now);
    char formatted_date[11];
    strftime(formatted_date, sizeof(formatted_date), "%Y-%m-%d", &timeinfo);
    account_date = formatted_date;

    char formatted_time[11];
    strftime(formatted_time, sizeof(formatted_time), "%H:%M:%S", &timeinfo);
    account_time = formatted_time;


}

void Account:: setMoney(double money) {
    if (money > 0)
        this->accountMoney = money;
    else
        return;
}

double Account::getMoney() const {
    return this->accountMoney;
}

string Account::getUserName()const {
    return this->user.getName();
}




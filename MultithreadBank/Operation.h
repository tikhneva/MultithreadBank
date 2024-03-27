#pragma once
#include "Account.h"

#include <iostream>
#include <string>
using namespace std;


class Operation
{
private:
    string date, status;
    static vector<string>operationHistory;
public:
    Operation();
    void sendMoney(Account&, Account&, double money); 
    void printOperationHistory()const;
};

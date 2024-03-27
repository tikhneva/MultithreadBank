#include "Operation.h"
#include <Windows.h>
#include "Account.h"
Operation::Operation() {
    time_t now;
    time(&now);
    struct tm timeinfo;
    localtime_s(&timeinfo, &now);
    char formatted_date[50]; 
    strftime(formatted_date, sizeof(formatted_date), "%Y-%m-%d %H:%M:%S", &timeinfo);
    this->date = formatted_date;
    status = "";
}
void Operation::sendMoney(Account& sender, Account& recipient, double money) {
    if (sender.getMoney() >= money) {
        this->status = "In process...";
        Sleep(3000);
        cout << this->status << endl;
        sender.setMoney(sender.getMoney() - money);
        recipient.setMoney(recipient.getMoney() + money);
        this->status = "Operation completed";
        cout << this->status << endl;
        string strOperation = "Sender " + sender.getUserName() + " sent " + to_string((int)money) + "$ " + "to recipient " + recipient.getUserName() + " at " + this->date;
        this->operationHistory.push_back(strOperation);
    }
    else {
        Sleep(3000);
        this->status = "Canceled";
        cout << this->status << endl;
    }
}

void Operation::printOperationHistory()const {
    for (int i = 0; i < operationHistory.size(); i++) {
        cout << operationHistory[i] << endl;
    }
}


// MultithreadBank.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//“Реалізувати багатопотокову роботу з банківськими рахунками. 1. Створити клас AccountHolder (власник рахунку).
//Поля: прізвище, ім'я, кредитний рейтинг, дата першої реєстрації в банку. 2. Створити клас Account (рахунок).
//Поля: власник рахунку, дата і час відкриття рахунку, дата і час закриття, залишок, список усіх операцій, що проводяться над цим рахунком.
//3. Створити клас Operation (банківська операція). Поля: тип операції (прихід, витрата), дата і час створення, статус (виконується, виконана, скасована).
//Клас має переказувати гроші з одного рахунку на інший в окремому потоці. У разі нестачі коштів під час витрат, чекати появи грошей на рахунку 3 секунди,
//і якщо гроші не прийдуть - викидати виняткову ситуацію і відзначати операцію скасованою. Забезпечити механізм, за якого б не губилися гроші.”
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <chrono>
#include <thread>
#include "Account.h"
#include "AccountHolder.h"
#include "Operation.h"
vector<std::string> Operation::operationHistory;
using namespace std;

int main() {
    AccountHolder user1("Ivan", "Petrov", 6);
    Account account1(user1, 6000);

    AccountHolder user2("Anastasiya", "Shvets", 7);
    Account account2(user2, 2000);

    Operation a;

    thread bankThread([&]() {
        a.sendMoney(account1, account2, 300.00);
        });

    bankThread.join();

    cout << "Account 1 balance: " << account1.getMoney() << endl;
    cout << "Account 2 balance: " << account2.getMoney() << endl;

    a.printOperationHistory();

    return 0;
}



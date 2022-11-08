#include <iostream>
#include "BankAccount.h"
#include "Bank.h"
using namespace std;

void BankAccount::createAccount()
{
    cout << "Enter Customer ID:" << endl;
    cin >> customerId;
    this->accArrayOfId[i] = customerId;
    cout << "Enter owner name:" << endl;
    cin >> ownerName;
    accArrayOfName[i] = ownerName;
    cout << "Enter balance:" << endl;
    cin >> balance;
    accArrayOfBalance[i] = balance;
    
    i = i + 1;
    
}

void BankAccount::topUpBalance()
{
    float a;
    cout << "Enter top up amount:" << endl;
    cin >> a;
    balance = balance + a;
    cout << "Your balance: " << balance << endl;
}

void BankAccount::withdrawCash()
{
    float b;
    cout << "Enter withdraw amount:" << endl;
    cin >> b;
    balance = balance - b;
    cout << "Your balance: " << balance << endl;
}

void BankAccount::showAccount()
{
    cout << "Customer ID: " << customerId << endl;
    cout << "Owner name: " << ownerName << endl;
    cout << "Balance: " << balance << endl;
}

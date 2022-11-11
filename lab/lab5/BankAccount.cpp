#include <iostream>
#include "BankAccount.h"
#include "Bank.h"
using namespace std;

void BankAccount::createAccount()
{
    cout << "Enter Customer ID:" << endl;
    cin >> customerId;
    cout << "Enter owner name:" << endl;
    cin >> ownerName;
    cout << "Enter balance:" << endl;
    cin >> balance;
    
    
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

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <iostream>
#include "string.h"
#include "Bank.h"
using namespace std;

class BankAccount
{
private:
    int i=0;
    int customerId;
    string ownerName;
    float balance;
    int accArrayOfId[30];
    string accArrayOfName[30];
    float accArrayOfBalance[30];
    
public:
    void createAccount();
    void topUpBalance();
    void withdrawCash();
    void showAccount();
    BankAccount();
    ~BankAccount();
    friend class Bank;
};

BankAccount::BankAccount()
{
}

BankAccount::~BankAccount()
{
}
#endif
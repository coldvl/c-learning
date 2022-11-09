#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <iostream>
#include "string.h"
#include "Bank.h"
using namespace std;

class BankAccount
{
private:
    int customerId;
    string ownerName;
    float balance;
    
public:
    void createAccount();
    void topUpBalance();
    void withdrawCash();
    void showAccount();
    float getBalance();
    int getId();
    string getName();
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
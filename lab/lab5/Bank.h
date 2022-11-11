#ifndef BANK_H
#define BANK_H
#include <iostream>
#include "string.h"
#include "BankAccount.h"
using namespace std;

class Bank
{
    friend class BankAccount;
private:
    BankAccount account[2];
public:
    Bank();
    ~Bank();
    void sortAccounts(int n);    
    void bubbleSort(int n);
    void accountCreation();
};

Bank::Bank()
{
}

Bank::~Bank()
{
}
#endif
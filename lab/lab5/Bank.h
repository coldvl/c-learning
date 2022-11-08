#ifndef BANK_H
#define BANK_H
#include <iostream>
#include "string.h"
#include "BankAccount.h"
using namespace std;

class Bank
{
private:
    int arrayOfId[30];
    string arrayOfName[30];
    float arrayOfBalance[30];
public:
    Bank();
    ~Bank();
    void sortAccounts();
    void bubbleSort(float arr[], int n);
    void swap(float *xp, float *yp);
    void swapStr(string *xp, string *yp);
    void swapInt(int *xp, int *yp);
    friend class BankAccount;
};

Bank::Bank()
{
}

Bank::~Bank()
{
}
#endif
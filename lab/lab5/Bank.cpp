#include <iostream>
#include "Bank.h"
#include "BankAccount.h"
using namespace std;


  
void Bank::bubbleSort(int n) 
{ 
   int i, j; 
   for (i = 0; i < n-1; i++)         
       for (j = 0; j < n-i-1; j++)  
           if (account[j].balance > account[j+1].balance) {
              float temp = account[j].balance;
              account[j].balance = account[j+1].balance;
              account[j+1].balance = temp; 
           }
} 

void Bank::accountCreation()
{
    account[0].createAccount();
    account[1].createAccount();
    account[0].topUpBalance();
    account[1].withdrawCash();
    account[0].showAccount();
    cout << endl;
    account[1].showAccount();
}

void Bank::sortAccounts(int n)
{
    int i; 
    bubbleSort(n);
    for (i=0; i < n; i++) 
        cout << account[i].balance << "\n";
}


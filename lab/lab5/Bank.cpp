#include <iostream>
#include "Bank.h"
#include "BankAccount.h"
using namespace std;


void Bank::swap(float *xp, float *yp) 
{ 
    float temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

void Bank::swapStr(string *xp, string *yp) 
{ 
    string temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

void Bank::swapInt(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
  
void Bank::bubbleSort(float arr[], int n) 
{ 
   int i, j; 
   for (i = 0; i < n-1; i++)         
       for (j = 0; j < n-i-1; j++)  
           if (arr[j] > arr[j+1]) 
              swap(&arr[j], &arr[j+1]); 
} 

/*void Bank::printArray(float arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%f ", arr[i]); 
    printf("\n"); 
} 
*/

void Bank::sortAccounts(class BankAccount arr[], int n)
{
    int i, j; 
    float arrayOfBalance[n];
    int arrayOfId[n];
    string arrayOfName[n];

    for (i = 0; i < n; i++)
        arrayOfBalance[i]=arr[i].getBalance();
    
    bubbleSort(arrayOfBalance, n);
    for (i=0; i < n; i++) 
        cout << arrayOfBalance[i] << "\n";
 /*   for (i = 0; i < n-1; i++)         
       for (j = 0; j < n-1; j++)  
           if (temp[j] == arrayOfBalance[i]) 
              swapInt(&arrayOfId[j], &arrayOfId[i]);
              swapStr(&arrayOfName[j], &arrayOfName[i]);
    // printArray(arrayOfBalance, 30);
    // printArray(arrayOfId, 30);
    // printArray(arrayOfName, 30);

}

*/
}
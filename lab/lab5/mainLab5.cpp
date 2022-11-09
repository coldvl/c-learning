#include "bankAccount.cpp"
#include "Bank.cpp"

int main() {
    BankAccount account[2];
    account[0].createAccount();
    account[1].createAccount();
    account[0].topUpBalance();
    account[1].withdrawCash();
    account[0].showAccount();
    cout << endl;
    account[1].showAccount();
    Bank list;
    list.sortAccounts(account, 2);

}
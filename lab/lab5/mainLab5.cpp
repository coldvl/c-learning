#include "bankAccount.cpp"

int main() {
    BankAccount account1;
    account1.createAccount();
    account1.topUpBalance();
    account1.withdrawCash();
    account1.showAccount();

}
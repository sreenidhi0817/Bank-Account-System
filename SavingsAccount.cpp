#include "SavingsAccount.h"
#include <iostream>
using namespace std;

SavingsAccount::SavingsAccount() : BankAccount() {}

void SavingsAccount::addInterest(double rate) {
    double earned = getBalance() * rate;
    setBalance(getBalance() + earned);
    cout << "Interest added: $" << earned << ". New balance: $" << getBalance() << endl;
} 
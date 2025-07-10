#include "CheckingAccount.h"
#include <iostream>
using namespace std;


CheckingAccount::CheckingAccount() : BankAccount() {}

CheckingAccount::CheckingAccount(string em, string pw, string rt, string n, string d, int cs, double b)
    : BankAccount(em, pw, rt, n, d, cs, b) {}

void CheckingAccount::swipeCard(double amt) {
    if (getBalance() >= amt) {
        setBalance(getBalance() - amt);
        cout << "Card swiped for $" << amt << ". Remaining: $" << getBalance() << endl;
    } else {
        cout << "Swipe failed: Not enough funds.\n";
    }
}
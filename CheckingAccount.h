#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

#include "BankAccount.h"
#include <string>
using namespace std;

class CheckingAccount : public BankAccount {
public:
    CheckingAccount(); 
    CheckingAccount(string em, string pw, string rt, string n, string d, int cs, double b); 

    void swipeCard(double amt);
};

#endif
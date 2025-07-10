#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "BankAccount.h"
#include <string>
using namespace std;

class SavingsAccount : public BankAccount {
public:
    SavingsAccount();  
    SavingsAccount(string em, string pw, string rt, string n, string d, int cs, double b); 

    void addInterest(double rate);
};

#endif 

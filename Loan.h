#ifndef LOAN_H
#define LOAN_H

#include "BankAccount.h"

class Loan {
private:
    double total;
    double rate;
    int monthsLeft;
    double currentBal;

public:
    Loan(double t, double r, int m);
    
    //for pointer based interaction
    void payLoan(BankAccount* payer, double amt);
    
    double getRemaining();
};

#endif

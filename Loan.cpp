#include "Loan.h"
#include <iostream>
using namespace std;

Loan::Loan(double t, double r, int m) {
    total = t;
    rate = r;
    monthsLeft = m;
    currentBal = t;
}

// for pointer-based interaction
void Loan::payLoan(BankAccount* payer, double amt) {
    if (payer->getBalance() >= amt) {
        currentBal -= amt;
        payer->setBalance(payer->getBalance() - amt);
        cout << "Loan payment of $" << amt << " made.\n";
    } else {
        cout << "Loan payment failed - not enough in account.\n";
    }
}

double Loan::getRemaining() {
    return currentBal;
}

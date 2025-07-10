#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include "Loan.h"
#include "TransactionQueue.h"
#include <iostream>
using namespace std;

int main() {
    TransactionQueue log;

    // Create accounts dynamically
    CheckingAccount* ca = new CheckingAccount();
    SavingsAccount* sa = new SavingsAccount();

    cout << "Checking Account Setup:\n";
    ca->createAccount();
    log.logTransaction("Created Checking Account");

    cout << "\nSavings Account Setup:\n";
    sa->createAccount();
    log.logTransaction("Created Savings Account");

    // Swipe card
    ca->swipeCard(40);
    log.logTransaction("Swiped $40 on Checking Account");

    // Add interest
    sa->addInterest(0.04);
    log.logTransaction("Added 4% interest to Savings Account");

    // Transfer money from Checking to Savings
    ca->transferMoney(sa, 100);
    log.logTransaction("Transferred $100 from Checking to Savings");

    // Create loan and make a payment
    Loan* carLoan = new Loan(1200, 0.05, 10);
    carLoan->payLoan(ca, 200);
    log.logTransaction("Paid $200 from Checking to Car Loan");

    // Print summaries
    cout << "\n--- Final Info ---\n";
    cout << "\n--- Checking Account ---\n";
    ca->printInfo();

    cout << "\n--- Savings Account ---\n";
    sa->printInfo();

    cout << "\n--- Loan ---\n";
    cout << "Loan Remaining: $" << carLoan->getRemaining() << endl;

    // Print all logged transactions
    cout << "\n--- Transaction Log ---\n";
    log.printAll();

    // Free memory
    delete ca;
    delete sa;
    delete carLoan;

    return 0;
}
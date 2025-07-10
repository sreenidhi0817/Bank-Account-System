#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>
#include <vector>
using namespace std;

struct Payment {
    double amount;
    string toWho;
    string date;
    string method;
    string status;
};

class BankAccount {
protected:
    string email;
    string password;
    string routingNum;
    string name;
    string openDate;
    double sent;
    double received;
    double bal;
    int creditScore;
    double monthlySpend;
    vector<Payment> history;

public:
    BankAccount();
    BankAccount(string em, string pw, string rt, string n, string d, int cs, double b);

    void createAccount();
    void printInfo();
    
    // to use a pointer for interaction
    void transferMoney(BankAccount* other, double amt);

    string getName();
    double getBalance();
    void setBalance(double newBal);

    // for transactional logging
    void addPaymentToHistory(Payment p);
    vector<Payment> getHistory();
};

#endif

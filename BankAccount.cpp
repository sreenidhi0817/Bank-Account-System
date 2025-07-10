#include "BankAccount.h"
#include <iostream>
using namespace std;

BankAccount::BankAccount() {
    email = "";
    password = "";
    routingNum = "";
    name = "";
    openDate = "";
    sent = 0;
    received = 0;
    bal = 0;
    creditScore = 0;
    monthlySpend = 0;
}

BankAccount::BankAccount(string em, string pw, string rt, string n, string d, int cs, double b) {
    email = em;
    password = pw;
    routingNum = rt;
    name = n;
    openDate = d;
    creditScore = cs;
    bal = b;
    sent = 0;
    received = 0;
    monthlySpend = 0;
}

void BankAccount::createAccount() {
    cout << "Name: ";
    getline(cin, name);
    cout << "Email: ";
    getline(cin, email);
    cout << "Password: ";
    getline(cin, password);
    cout << "Routing #: ";
    getline(cin, routingNum);
    cout << "Date opened (yyyy-mm-dd): ";
    getline(cin, openDate);
    cout << "Credit score: ";
    cin >> creditScore;
    cout << "Starting balance: ";
    cin >> bal;
    cin.ignore();
}

void BankAccount::printInfo() {
    cout << "Name: " << name << "\n";
    cout << "Email: " << email << "\n";
    cout << "Balance: $" << bal << "\n";
    cout << "Credit Score: " << creditScore << "\n";

    if (!history.empty()) {
        Payment last = history.back();
        cout << "Last Payment: $" << last.amount << " to " << last.toWho << " on " << last.date << "\n";
    }
}

// for pointer-based interaction
void BankAccount::transferMoney(BankAccount* other, double amt) {
    if (bal >= amt) {
        bal -= amt;
        sent += amt;
        other->bal += amt;
        other->received += amt;

        Payment p = {amt, other->getName(), "2025-06-03", "Bank Transfer", "Success"};
        history.push_back(p);

        cout << name << " sent $" << amt << " to " << other->getName() << endl;
    } else {
        cout << "Not enough balance to send money.\n";
    }
}

string BankAccount::getName() { return name; }
double BankAccount::getBalance() { return bal; }
void BankAccount::setBalance(double newBal) { bal = newBal; }

// For external transaction logging or testing
void BankAccount::addPaymentToHistory(Payment p) {
    history.push_back(p);
}

vector<Payment> BankAccount::getHistory() {
    return history;
}
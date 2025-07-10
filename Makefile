Makefile
all: main

main: main.cpp BankAccount.cpp CheckingAccount.cpp SavingsAccount.cpp Loan.cpp TransactionQueue.cpp
	g++ -std=c++11 main.cpp BankAccount.cpp CheckingAccount.cpp SavingsAccount.cpp Loan.cpp TransactionQueue.cpp -o main

clean:
	rm -f main
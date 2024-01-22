#include "DebitCard.h"
#include <iostream>
#include <iomanip>

using namespace std;
//cout << fixed << setprecision(2);

DebitCard::DebitCard()
{
	totalTransactions = 0;
	accountBalance = 0;
	totalDeposits = 0;

}

DebitCard::~DebitCard()
{
	
}

double DebitCard::Deposit(double deposit)
{
   totalDeposits += deposit;
   accountBalance = totalDeposits;
	return totalDeposits;
}

double DebitCard::PostTransaction(int idNumber, std::string date, std::string description, double amount)
{
	Transaction newTrans(idNumber, date, description, amount);
	this->transactions.push_back(newTrans);
	totalTransactions++;
	return accountBalance -= amount;
}

bool DebitCard::ClearTransaction(int idNumber)
{
   return transactions.at(idNumber - 1).cleared = true;
}

void DebitCard::DisplayActivity()
{
   cout << fixed << setprecision(2);
	cout << "total transactions: " << this->totalTransactions << endl;
	cout << "total deposits: $" << this->totalDeposits << endl;
	cout << "account balance: $" << this->accountBalance << endl;

	cout << "\nList of cleared Transactions: " << endl;
	for (int i = 0; i < transactions.size(); i++) {
		if (transactions.at(i).cleared) {
			cout << transactions.at(i).date << "\t$" << transactions.at(i).amount << "\t" << transactions.at(i).description << endl;
		}
	}
	cout << "List of pending transactions:" << endl << endl;
	for (int i = 0; i < transactions.size(); i++) {
		if (!transactions.at(i).cleared) {
			cout << transactions.at(i).date << "\t$" << transactions.at(i).amount << "\t" << transactions.at(i).description << endl;
		}
	}
}
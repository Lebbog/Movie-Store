//---------------------------------------------------------------------------
// customer.h
// Geoffrey Lebbos CSS 343 C
// 3/10/2017
// Last Modified: 3/15/2017
//---------------------------------------------------------------------------
#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <string>
#include <queue>
#include "transaction.h"
using namespace std;
class Transaction;
class Customer
{
	friend ostream& operator<<(ostream &, const Customer &);
public:

	Customer();
	Customer(int, string, string);
	~Customer();

	int getID() const;
	string getName() const;
	bool setData(ifstream&);
	void setTransactionHistory(Transaction*);
	void printHistory();
	
private:

	int customerID;
	string name;
	
	queue<Transaction*> historyQueue; //for H command
};
#endif
#ifndef TRANSACTION_H
#define TRANSACTION_H
//#include <iostream>
//#include <fstream>
//#include <string>
#include "customer.h"
#include "movie.h"
#include "binarysearchtree.h"
using namespace std;
class Customer;
class Transaction
{
public:
	Transaction();
	virtual ~Transaction();
	virtual bool setData(ifstream& infile);
	virtual char getType() const;
	virtual bool doTransaction(BinarySearchTree&, BinarySearchTree&, BinarySearchTree&, Movie*, Customer*);
	virtual int getCustomerID() const;
	virtual char getMovieType() const;
	virtual string getMajorActor() const;
	virtual int getYear() const;
	virtual int getMonth() const;
	virtual string getTitle() const;
	virtual string getDirector() const;

protected:
	char transactionType;
	char mediaType; 
	char movieType; 
	int customerID;
	string director;
	string title;
	int year;
	int month;
	string majorActor;
	virtual void print(ostream&) const;
	friend ostream& operator<< (ostream&, const Transaction&);
};
#endif
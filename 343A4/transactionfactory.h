//---------------------------------------------------------------------------
// transactionfactory.h
// Geoffrey Lebbos CSS 343 C
// 3/10/2017
// Last Modified: 3/15/2017
//---------------------------------------------------------------------------
#ifndef TRANSACTIONFACTORY_H
#define TRANSACTIONFACTORY_H
#include "inventory.h"
#include "borrow.h"
#include "history.h"
#include "return.h"

using namespace std;

class TransactionFactory
{
public:
	TransactionFactory();
	~TransactionFactory();
	// instantiate a transaction object of a certain type
	static Transaction* createTransaction(const char&);
};
#endif

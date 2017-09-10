//---------------------------------------------------------------------------
// transactionfactory.cpp
// Geoffrey Lebbos CSS 343 C
// 3/10/2017
// Last Modified: 3/15/2017
//---------------------------------------------------------------------------
#include "transactionfactory.h"
//---------------------------------------------------------------------------
// constructor
TransactionFactory::TransactionFactory()
{

}
//---------------------------------------------------------------------------
// destructor
TransactionFactory::~TransactionFactory()
{

}
//---------------------------------------------------------------------------
// createTransaction
Transaction* TransactionFactory::createTransaction(const char& type)
{
	switch (type)
	{
	case 'I':
	{
		return new Inventory();
	}
	case 'H':
	{
		return new History();
	}
	case 'B':
	{
		return new Borrow();
	}
	case 'R':
	{
		return new Return();
	}
	default:
		cout << "Unkown transaction type " << type << endl;
		return NULL;
	}
}
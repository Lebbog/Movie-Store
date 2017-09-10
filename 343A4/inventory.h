//---------------------------------------------------------------------------
// inventory.h
// Geoffrey Lebbos CSS 343 C
// 3/10/2017
// Last Modified: 3/15/2017
//---------------------------------------------------------------------------
#ifndef INVENTORY_H
#define INVENTORY_H
#include "transaction.h"

class Inventory : public Transaction
{
public:
	Inventory();
	virtual ~Inventory();
	virtual bool doTransaction(BinarySearchTree&, BinarySearchTree&,
		BinarySearchTree&, Movie*, Customer*);
	virtual bool setData(ifstream&);
	virtual char getType() const;
	virtual void print(ostream&) const;
	//for printing

private:
	static const char type = 'I';
};
#endif

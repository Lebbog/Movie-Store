//---------------------------------------------------------------------------
// borrow.h
// Geoffrey Lebbos CSS 343 C
// 3/10/2017
// Last Modified: 3/15/2017
//---------------------------------------------------------------------------
#ifndef BORROW_H
#define BORROW_H
#include "transaction.h"
class Borrow : public Transaction
{
public:
	Borrow();
	virtual ~Borrow(); //virtual destructor
	virtual bool setData(ifstream&);
	virtual bool doTransaction(BinarySearchTree&, BinarySearchTree&,
		BinarySearchTree&, Movie*, Customer*);
	virtual char getType() const;
	virtual void print(ostream&) const;
private:
	static const char type = 'B'; 
};
#endif

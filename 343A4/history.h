//---------------------------------------------------------------------------
// history.h
// Geoffrey Lebbos CSS 343 C
// 3/10/2017
// Last Modified: 3/15/2017
//---------------------------------------------------------------------------
#ifndef HISTORY_H
#define HISTORY_H
#include "transaction.h"

class History : public Transaction
{
public:
	History();
	virtual ~History();//virtual destructor
	virtual bool doTransaction(BinarySearchTree&, BinarySearchTree&,
		BinarySearchTree&, Movie*, Customer*);
	virtual bool setData(ifstream&);
	virtual char getType() const;
	virtual void print(ostream&) const; //for printing

private:
	static const char type = 'H';
};
#endif

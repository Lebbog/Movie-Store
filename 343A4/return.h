//---------------------------------------------------------------------------
// return.h
// Geoffrey Lebbos CSS 343 C
// 3/10/2017
// Last Modified: 3/15/2017
//---------------------------------------------------------------------------
#ifndef RETURN_H
#define RETURN_H
#include "transaction.h"

class Return : public Transaction
{
public:
	Return();
	virtual ~Return();
	virtual bool setData(ifstream&);
	virtual void print(ostream&) const;
	virtual char getType() const;
	virtual bool doTransaction(BinarySearchTree&, BinarySearchTree&, 
		BinarySearchTree&, Movie*, Customer*);
private:
	static const char type = 'R';
};
#endif

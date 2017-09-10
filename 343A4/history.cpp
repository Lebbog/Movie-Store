//---------------------------------------------------------------------------
// history.cpp
// Geoffrey Lebbos CSS 343 C
// 3/10/2017
// Last Modified: 3/15/2017
//---------------------------------------------------------------------------
#include "history.h"
//---------------------------------------------------------------------------
//constructor
History::History()
{

}
//---------------------------------------------------------------------------
//destructor
History::~History()
{

}
//---------------------------------------------------------------------------
//getType
char History::getType() const
{
	return type;
}
//---------------------------------------------------------------------------
//setData
bool History::setData(ifstream& infile)
{
	infile >> customerID;
	infile.ignore(1, '\n');
	return true;
	
}
//---------------------------------------------------------------------------
//doTransaction
bool History::doTransaction(BinarySearchTree& f, BinarySearchTree& d,
	BinarySearchTree& c, Movie* movie, Customer* customer)
{
	cout << "Printing hisory for Customer ID " << customerID << ":" << endl;
	customer->printHistory();
	return true;
}
//---------------------------------------------------------------------------
//print
void History::print(ostream& output) const
{
	output << type << " " << customerID;
}
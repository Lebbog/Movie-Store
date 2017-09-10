//---------------------------------------------------------------------------
// inventory.cpp
// Geoffrey Lebbos CSS 343 C
// 3/10/2017
// Last Modified: 3/15/2017
//---------------------------------------------------------------------------
#include "inventory.h"
//---------------------------------------------------------------------------
//constructor
Inventory::Inventory()
{

}
//---------------------------------------------------------------------------
//destructor
Inventory::~Inventory()
{

}
//---------------------------------------------------------------------------
//getType
char Inventory::getType() const
{
	return type;
}
//---------------------------------------------------------------------------
//setData
bool Inventory::setData(ifstream& infile)
{
	infile.ignore(1, '\n');
	return true;
}
//---------------------------------------------------------------------------
//doTransaction
bool Inventory::doTransaction(BinarySearchTree& f, BinarySearchTree& d,
	BinarySearchTree& c, Movie* movie, Customer* customer)
{
	cout << f;
	cout << d;
	cout << c;
	return false;
}
//---------------------------------------------------------------------------
//print
void Inventory::print(ostream& output) const
{
	output << type;
}

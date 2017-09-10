//---------------------------------------------------------------------------
// transaction.cpp
// Geoffrey Lebbos CSS 343 C
// 3/10/2017
// Last Modified: 3/15/2017
//---------------------------------------------------------------------------
#include "transaction.h"
//---------------------------------------------------------------------------
//Constructor
Transaction::Transaction()
{
	transactionType = 'z';
	mediaType = 'z';
	movieType = 'z';
	customerID = 0000;
	director = "defaultDirector";
	title = "defualtTitle";
	year = 0000;
	month = 0000;
	majorActor = "defaultActor";
}
//---------------------------------------------------------------------------
//destructor
Transaction::~Transaction()
{

}
//---------------------------------------------------------------------------
//setData
bool Transaction::setData(ifstream& infile)
{
	return false;
}
//---------------------------------------------------------------------------
//getType
char Transaction::getType() const
{
	return transactionType;
}
//---------------------------------------------------------------------------
//getMovieType
char Transaction::getMovieType() const
{
	return movieType;
}
//---------------------------------------------------------------------------
//doTransaction
bool Transaction::doTransaction(BinarySearchTree& f, BinarySearchTree& d, 
	BinarySearchTree& c, Movie* movie, Customer* customer)
{
	return true;
}
//---------------------------------------------------------------------------
//getCustomerID
int Transaction::getCustomerID() const
{
	return customerID;
}
//---------------------------------------------------------------------------
//getMajorActor
string Transaction::getMajorActor() const
{
	return majorActor;
}
//---------------------------------------------------------------------------
//getYear
int Transaction::getYear() const
{
	return year;
}
//---------------------------------------------------------------------------
//getMonth
int Transaction::getMonth() const
{
	return month;
}
//---------------------------------------------------------------------------
//getTitle
string Transaction::getTitle() const
{
	return title;
}
//---------------------------------------------------------------------------
//getDirector
string Transaction::getDirector() const
{
	return director;
}
//---------------------------------------------------------------------------
//print
void Transaction::print(ostream& output) const
{
	output << "generic movie";
}
//---------------------------------------------------------------------------
//operator<<
ostream& operator<<(ostream& output, const Transaction& right)
{
	right.print(output);
	return output;
}

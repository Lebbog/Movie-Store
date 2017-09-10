//---------------------------------------------------------------------------
// borrow.cpp
// Geoffrey Lebbos CSS 343 C
// 3/10/2017
// Last Modified: 3/15/2017
//---------------------------------------------------------------------------
#include "borrow.h"
//---------------------------------------------------------------------------
//constructor
Borrow::Borrow()
{

}
//---------------------------------------------------------------------------
//destructor
Borrow::~Borrow()
{

}
//---------------------------------------------------------------------------
//setData
bool Borrow::setData(ifstream& infile)
{
	infile >> customerID;
	infile >> mediaType;
	if (mediaType != 'D')
	{
		cout << "Unknown media type " << mediaType << endl;
		return false;
	}
	infile >> movieType;
	switch (movieType)
	{
	case 'F':
	{
		getline(infile, title, ',');
		infile >> year;
		infile.ignore(1,'\n');
		break;
	}
	case 'D':
	{
		getline(infile, director, ',');
		getline(infile, title, ',');
		infile.ignore(1,'\n');
		break;
	}
	case 'C':
	{
		infile >> month;
		infile >> year;
		string first = "";
		string last = "";
		infile >> first;
		infile >> last;
		majorActor = first + " " + last;
		infile.ignore(1,'\n');
		break;
	}
	default:
	{
		cout << "Unkown movie type " << movieType << endl;
		return false;
	}
	}
	return true;
}
//---------------------------------------------------------------------------
//doTransaction
bool Borrow::doTransaction(BinarySearchTree& f, BinarySearchTree& d,
	BinarySearchTree& c, Movie* movie, Customer* customer)
{
	return movie->reduceStock();
}
//---------------------------------------------------------------------------
//getType()
char Borrow::getType() const
{
	return type;
}
//---------------------------------------------------------------------------
//Print
void Borrow::print(ostream& output) const
{
	output << type << " " << mediaType << " " << movieType << " ";
	switch (movieType)
	{
	case 'F':
	{
		output << title << ", " << year;
		break;
	}
	case 'D':
	{
		output << director << ", " << title;
		break;
	}
	case 'C':
	{
		output << month << " " << year << " " << majorActor;
		break;
	}
	default:
	{
		break;
	}
	}
}

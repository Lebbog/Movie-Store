//---------------------------------------------------------------------------
// return.cpp
// Geoffrey Lebbos CSS 343 C
// 3/10/2017
// Last Modified: 3/15/2017
//---------------------------------------------------------------------------
#include "return.h"
//---------------------------------------------------------------------------
// constructor
Return::Return()
{

}
//---------------------------------------------------------------------------
// destructor
Return::~Return()
{

}
//---------------------------------------------------------------------------
// getType
char Return::getType() const
{
	return type;
}
//---------------------------------------------------------------------------
// setData
bool Return::setData(ifstream& infile)
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
		infile.ignore(1, '\n');
		break;
	}
	case 'D':
	{
		getline(infile, director, ',');
		getline(infile, title, ',');
		infile.ignore(1, '\n');
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
		infile.ignore(1, '\n');
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
// print
void Return::print(ostream& output) const
{
	output << type << " " << mediaType << " " << movieType << " ";
	switch (movieType)
	{
	case 'F':
	{
		output << title << "," << year;
		break;
	}
	case 'D':
	{
		output << director << "," << title;
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
//---------------------------------------------------------------------------
// doTransaction
bool Return::doTransaction(BinarySearchTree& f, BinarySearchTree& d,
	BinarySearchTree& c, Movie* movie, Customer* customer)
{
	return movie->increaseStock();
	// increase movie stock by 1

}
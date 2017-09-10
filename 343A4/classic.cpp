//---------------------------------------------------------------------------
// clasisc.cpp
// Geoffrey Lebbos CSS 343 C
// 3/10/2017
// Last Modified: 3/15/2017
//---------------------------------------------------------------------------
#include "classic.h"
//---------------------------------------------------------------------------
//constructor
Classic::Classic()
{
}
//---------------------------------------------------------------------------
//destrcutor
Classic::~Classic()
{

}
//---------------------------------------------------------------------------
//getType()
char Classic::getType() const
{
	return type;
}
//---------------------------------------------------------------------------
//getMonth()
int Classic::getMonth() const
{
	return month;
}
//---------------------------------------------------------------------------
//getMajorActor()
string Classic::getMajorActor() const
{
	return majorActor;
}
//---------------------------------------------------------------------------
//operator==
bool Classic::operator==(const Movie& right) const
{
	const Classic* right2 = dynamic_cast<const Classic*>(&right);
	return (year == right2->year && majorActor == right2->majorActor);
}
//---------------------------------------------------------------------------
//operator<<
bool Classic::operator<(const Movie& right) const
{
	const Classic* right2 = dynamic_cast<const Classic*>(&right);
	if ((title == right2->title && year == right2->year) && (month == right2->month))
	{
		return false;
	}

	if (year < right2->year)
	{
		return true;
	}
	else if (year == right2->year)
	{
		if (month < right2->month)
		{
			return true;
		}
		if (month == right2->month)
		{
			return false;
		}
	}
	 return false;
}
//---------------------------------------------------------------------------
//Operator>
bool Classic::operator>(const Movie& right) const
{
	const Classic* right2 = dynamic_cast<const Classic*>(&right);
	if ((title == right2->title && year == right2->year) && (month == right2->month))
	{
		return false;
	}
	if (year > right2->year)
	{
		return true;
	}
	else if (year == right2->year)
	{
		if (month > right2->month)
		{
			return true;
		}
		if (month == right2->month)
		{
			return false;
		}
	}
	return false;
}
//---------------------------------------------------------------------------
//setData
void Classic::setData(ifstream& infile)
{
	//May need the initial getline to be here before checking for eof()
	if (!infile.eof())
	{
		string stStock = "";
		string majorFirst = "", majorSecond = "";
		getline(infile, stStock, ',');
		stock = stoi(stStock);
		getline(infile, director, ',');
		getline(infile, title, ',');
		//major actor
		infile >> majorFirst >> majorSecond >> month >> year;
		majorActor = majorFirst + " " + majorSecond; //Combine two strings
		infile.ignore(1, '\n');
	}
	//return !infile.eof();
}
//---------------------------------------------------------------------------
//print
void Classic::print(ostream& output) const
{
	output << type << ", " << stock << ", " << director << ", " << title << ", " << majorActor << " " << month << " " << year << endl;
}
//---------------------------------------------------------------------------
//addToStock
void Classic::addToStock(int amount)
{
	stock += amount;
}
//---------------------------------------------------------------------------
//setMajorActor
void Classic::setMajorActor(string act)
{
	majorActor = act;
}
//---------------------------------------------------------------------------
// comedy.cpp
// Geoffrey Lebbos CSS 343 C
// 3/10/2017
// Last Modified: 3/15/2017
//---------------------------------------------------------------------------
#include "comedy.h"
//---------------------------------------------------------------------------
//constructor
Comedy::Comedy()
{

}
//---------------------------------------------------------------------------
//destructor
Comedy::~Comedy()
{

}
//---------------------------------------------------------------------------
//getType
char Comedy::getType() const
{
	return type;
}
//---------------------------------------------------------------------------
//operator==
bool Comedy::operator==(const Movie& right) const
{
	return (title == right.getTitle() && year == right.getYear());
}
//---------------------------------------------------------------------------
//operator<
bool Comedy::operator<(const Movie& right) const
{
	if (title < right.getTitle())
	{
		return true;
	}
	if (title == right.getTitle())
	{
		return (year < right.getYear());
	}
	return false;
}
//---------------------------------------------------------------------------
//operator>
bool Comedy::operator>(const Movie& right) const
{
	return !(*this < right);
}
//---------------------------------------------------------------------------
//print
void Comedy::print(ostream& output) const
{
	output << type << ", " << stock << ", " << director << ", " << title << ", " << year << endl;
}

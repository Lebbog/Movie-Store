//---------------------------------------------------------------------------
// drama.cpp
// Geoffrey Lebbos CSS 343 C
// 3/10/2017
// Last Modified: 3/15/2017
//---------------------------------------------------------------------------
#include "drama.h"
//---------------------------------------------------------------------------
//drama
Drama::Drama()
{
}
//---------------------------------------------------------------------------
//destructor
Drama::~Drama()
{

}
//---------------------------------------------------------------------------
//getType
char Drama::getType() const
{
	return type;
}
//---------------------------------------------------------------------------
//operator
bool Drama::operator==(const Movie& right) const
{
	return (title == right.getTitle() && director == right.getDirector());
}
//---------------------------------------------------------------------------
//operator<
bool Drama::operator<(const Movie& right) const
{
	if (director < right.getDirector())
	{
		return true;
	}
	if (director == right.getDirector())
	{
		return (title < right.getTitle());
	}
	return false;
}
//---------------------------------------------------------------------------
//operator>
bool Drama::operator>(const Movie& right) const
{
	return !(*this < right);
}
//---------------------------------------------------------------------------
//print
void Drama::print(ostream& output) const
{
	output << type << ", " << stock << ", " << director 
		<< ", " << title << ", " << year << endl;
}

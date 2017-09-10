//---------------------------------------------------------------------------
// movie.cpp
// Geoffrey Lebbos CSS 343 C
// 3/10/2017
// Last Modified: 3/15/2017
//---------------------------------------------------------------------------
#include "movie.h"
//---------------------------------------------------------------------------
// Destructor
Movie::~Movie()
{

}
//---------------------------------------------------------------------------
// Constructor
Movie::Movie()
{
	stock = 0;
	year = 0;
	title = "defaultTitle";
	director = "defaultDirector";
	type = 'z';
}
//---------------------------------------------------------------------------
// getYear
int Movie::getYear() const
{
	return year;
}
//---------------------------------------------------------------------------
// getStock
int Movie::getStock() const
{
	return stock;
}
//---------------------------------------------------------------------------
// getDirector
string Movie::getDirector() const
{
	return director;
}
//---------------------------------------------------------------------------
// getTitle
string Movie::getTitle() const
{
	return title;
}
//---------------------------------------------------------------------------
// getType
char Movie::getType() const
{
	return type;
}
//---------------------------------------------------------------------------
// setData
void Movie::setData(ifstream& infile)
{
	if (!infile.eof())
	{
		string stStock = "";
		getline(infile, stStock, ',');
		getline(infile, director, ',');
		getline(infile, title, ',');
		infile >> year;
		stock = stoi(stStock);
		infile.ignore(1, '\n');
	}
}
//---------------------------------------------------------------------------
// operator==
bool Movie::operator==(const Movie& right) const
{
	return false;
}
//---------------------------------------------------------------------------
// operator>
bool Movie::operator>(const Movie& right) const
{
	return false;
}
//---------------------------------------------------------------------------
// operator<
bool Movie::operator<(const Movie& right) const
{
	return false;
}
//---------------------------------------------------------------------------
// print
void Movie::print(ostream& output) const
{
	output << type << ", " << stock << ", " << director << ", " << title << ", " << year << endl;
}
//---------------------------------------------------------------------------
// operator<<
ostream& operator<<(ostream& output, const Movie& right)
{
	right.print(output);
	return output;
}
//---------------------------------------------------------------------------
// addToStock
void Movie::addToStock(int amount)
{
	
}
//---------------------------------------------------------------------------
// reduceStock
bool Movie::reduceStock()
{
	
	stock -= 1;
	if (stock < 0)
	{
		stock = 0;
		cout << "Movie " << title << "is Out of stock, cannot borrow" << endl;
		return false;
	}
	return true;
}
//---------------------------------------------------------------------------
// increaseStock
bool Movie::increaseStock()
{
	stock += 1;
	return true;
}
//---------------------------------------------------------------------------
// setTitle
void Movie::setTitle(string t)
{
	title = t;
}
//---------------------------------------------------------------------------
// setYear
void Movie::setYear(int y)
{
	year = y;
}
//---------------------------------------------------------------------------
// setDirector
void Movie::setDirector(string d)
{
	director = d;
}
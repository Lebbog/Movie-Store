//---------------------------------------------------------------------------
// movie.h
// Geoffrey Lebbos CSS 343 C
// 3/10/2017
// Last Modified: 3/15/2017
//---------------------------------------------------------------------------
#ifndef MOVIE_H
#define MOVIE_H
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

class Movie
{
public:
	Movie();
	virtual ~Movie();
	virtual void setData(ifstream&);
	int getStock() const;
	int getYear() const;
	string getTitle() const;
	string getDirector() const;
	virtual char getType() const;
	virtual void addToStock(int);
	//overloaded comparison operators
	virtual bool operator==(const Movie&) const;
	virtual bool operator<(const Movie&) const;
	virtual bool operator>(const Movie&) const;
	void setTitle(string);
	void setYear(int);
	void setDirector(string);

	virtual bool reduceStock();
	virtual bool increaseStock();
protected:
	int stock, year;
	string title, director;
	char type;
	virtual void print(ostream& ) const;
	friend ostream& operator<< (ostream&, const Movie&);	
};
#endif

//---------------------------------------------------------------------------
// comedy.h
// Geoffrey Lebbos CSS 343 C
// 3/10/2017
// Last Modified: 3/15/2017
//---------------------------------------------------------------------------
#ifndef COMEDY_H
#define COMEDY_H
#include "movie.h"
using namespace std;

class Comedy : public Movie

{
public:
	Comedy();
	virtual  ~Comedy(); //virtual destructor
    virtual char getType() const;
	//overloaded comparison operators
	virtual bool operator==(const Movie&) const;
	virtual bool operator<(const Movie&) const;
	virtual bool operator>(const Movie&) const;
	virtual void print(ostream&) const;


private:
	static const char type = 'F';
};
#endif

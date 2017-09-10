//---------------------------------------------------------------------------
// drama.h
// Geoffrey Lebbos CSS 343 C
// 3/10/2017
// Last Modified: 3/15/2017
//---------------------------------------------------------------------------
#ifndef DRAMA_H
#define DRAMA_H
#include "movie.h"
using namespace std;

class Drama : public Movie
{

public:
	Drama();
	virtual ~Drama();
	//overloaded comparison operators
	virtual bool operator==(const Movie&) const;
	virtual bool operator<(const Movie&) const;
	virtual bool operator>(const Movie&) const;
	
	virtual char getType() const;
	virtual void print(ostream&) const;
private:

	static const char type = 'D';
};
#endif

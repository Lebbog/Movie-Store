//---------------------------------------------------------------------------
// classic.h
// Geoffrey Lebbos CSS 343 C
// 3/10/2017
// Last Modified: 3/15/2017
//---------------------------------------------------------------------------
#ifndef CLASSIC_H
#define CLASSIC_H
#include "movie.h"
using namespace std;

class Classic : public Movie

{
public:
	Classic();
	virtual ~Classic(); //virtual destructor

	//overloaded comparison operators
	virtual bool operator==(const Movie&) const;
	virtual bool operator<(const Movie&) const;
	virtual bool operator>(const Movie&) const;
	virtual void setData(ifstream&);

	virtual char getType() const;
	int getMonth() const;
	string getMajorActor() const;
	virtual void print(ostream&) const;
	virtual void addToStock(int);
	void setMajorActor(string);
private:
	int month;
	string majorActor;
	static const char type = 'C';
	
};
#endif

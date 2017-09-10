//---------------------------------------------------------------------------
// moviefactory.h
// Geoffrey Lebbos CSS 343 C
// 3/10/2017
// Last Modified: 3/15/2017
//---------------------------------------------------------------------------
#ifndef MOVIEFACTORY_H
#define MOVIEFACTORY_H
#include "comedy.h"
#include "classic.h"
#include "drama.h"
using namespace std;

class MovieFactory
{
public:
	MovieFactory();
	~MovieFactory();
	// instantiate a transaction object of a certain type
	static Movie* createMovie( const char&);
};
#endif

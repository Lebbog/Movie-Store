//---------------------------------------------------------------------------
// moviefactory.cpp
// Geoffrey Lebbos CSS 343 C
// 3/10/2017
// Last Modified: 3/15/2017
//---------------------------------------------------------------------------
#include "moviefactory.h"
//---------------------------------------------------------------------------
//constructor
MovieFactory::MovieFactory()
{

}
//---------------------------------------------------------------------------
//destructor
MovieFactory::~MovieFactory()
{

}
//---------------------------------------------------------------------------
//createMovie
Movie* MovieFactory::createMovie(const char& type)
{
	switch (type)
	{
	case 'F':
	{
		return new Comedy();
	}
	case 'C':
	{
		return new Classic();
	}
	case 'D':
	{
		return new Drama();
	}
	default :
		cout << "Unkown Movie type " << type << endl;
		return NULL;
	}
}
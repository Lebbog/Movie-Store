//---------------------------------------------------------------------------
// main.cpp
// Geoffrey Lebbos CSS 343 C
// 3/10/2017
// Last Modified: 3/15/2017
//---------------------------------------------------------------------------
#include <iostream>
#include "store.h"
using namespace std;
int main()
{
	Store s;
	s.initialize();
	s.processTransactions();
	return 0;
}
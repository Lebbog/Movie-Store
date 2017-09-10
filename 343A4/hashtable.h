//---------------------------------------------------------------------------
// hashtable.h
// Geoffrey Lebbos CSS 343 C
// 3/10/2017
// Last Modified: 3/15/2017
//---------------------------------------------------------------------------
#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "customer.h"

using namespace std;
static const int SIZE= 661; 
static const int R = 7; 

class HashTable
{
public:
	HashTable();
	~HashTable(); //destructor
	void insert(Customer* customer); //to hash customers
	Customer* getCustomer(int); //returns a customer*
	
private:
	int key, step;
	int firstHash(int ); // Hash customer in
	int collisionHash(int , int );//For collisions
	Customer* table[SIZE]; //array to hold customers
	
};
#endif

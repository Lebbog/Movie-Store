//---------------------------------------------------------------------------
// hashtable.cpp
// Geoffrey Lebbos CSS 343 C
// 3/10/2017
// Last Modified: 3/15/2017
//---------------------------------------------------------------------------
#include "hashtable.h"

//---------------------------------------------------------------------------
//Constructor
HashTable::HashTable()
{
	for (int i = 0; i < SIZE; i++)
	{
		table[i] = NULL;
	}
}
//---------------------------------------------------------------------------
//destructor
HashTable::~HashTable()
{
	for (int i = 0; i < SIZE; i++)
	{
		delete table[i];
		table[i] = NULL;
	}
}
//---------------------------------------------------------------------------
//insert a customer into table
void HashTable::insert(Customer* customer)
{
	key = customer->getID();
	int hash = firstHash(key);

	if (table[hash] == NULL)
	{
		table[hash] = customer;
	}
	else
	{
		int i = 1;
		while (table[hash] != NULL)
		{
			hash = collisionHash(hash, i);
			i++;
		}
		table[hash] = customer;
	}
}
//---------------------------------------------------------------------------
//firstHash
int HashTable::firstHash(int key)
{
	return (key % SIZE);
}
//---------------------------------------------------------------------------
//collisionHash
int HashTable::collisionHash(int key, int i)
{
	step = i*(R - (key % R)); 
									   
	return ((key + step) % SIZE);
}
//---------------------------------------------------------------------------
//getCustomer
Customer * HashTable::getCustomer(int key)
{

	int hash = firstHash(key);
	if (table[hash] == NULL)
	{
		return NULL;
	}

	if (table[hash]->getID() == key)
	{
		return table[hash];
	}
	else
	{
		int collisions = 1; 
		while ((table[hash]->getID() != key) && (table[hash] != NULL))
		{
			hash = collisionHash(hash, collisions); 
			collisions++;
		}
		if (table[hash] == NULL) return NULL; 

		else return table[hash]; 
	}
}


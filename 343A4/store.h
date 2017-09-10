//---------------------------------------------------------------------------
// store.h
// Geoffrey Lebbos CSS 343 C
// 3/10/2017
// Last Modified: 3/15/2017
//---------------------------------------------------------------------------
#ifndef STORE_H
#define STORE_H
#include "hashtable.h"
#include "binarysearchtree.h"
#include "moviefactory.h"
#include "transactionfactory.h"
#include <queue>
using namespace std;
static const int TRANSIZE = 1000;
class Store
{
public:

	Store(); //Constructor
	~Store();//Destructor
	void processTransactions(); //Processes transactions
	void readCustomers(ifstream &); //Builds customer objects
	void readMovies(ifstream &);   //Builds movie objects
	void readCommands(ifstream &); //Builds transaction objects
	void initialize(); //populates trees, queue and hashtable

private:
	BinarySearchTree dramaBST, comedyBST, classicBST; //for storing movies
	HashTable customerDatabase; //for storing customers
	queue<Transaction*> tranQueue; //for storing commands
	Transaction* tranPtr[TRANSIZE]; //for keeping track of transactions
};

#endif

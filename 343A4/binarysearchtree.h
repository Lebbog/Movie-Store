//---------------------------------------------------------------------------
// binarysearchtree.h
// Geoffrey Lebbos CSS 343 C
// 3/10/2017
// Last Modified: 3/15/2017
//---------------------------------------------------------------------------
#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include <string>
#include <list>
#include <vector>
#include "movie.h"
using namespace std;

class BinarySearchTree
{
	//Overloaded << operator
	//Displays contents of entire BST inorder
	friend ostream& operator<<(ostream&, const BinarySearchTree&);

public:
	BinarySearchTree(); // constructor
	~BinarySearchTree(); // destructor, calls makeEmpty

	bool insert(Movie*);
	bool isEmpty() const; // true if tree is empty, otherwise false
	void makeEmpty(); // make the tree empty 
	void retrieve(const Movie&, Movie*&) const;
	

private:
	
	//Struct holds pointers to data and left/right ancestors
	struct Node
	{
		Movie* data; //Pointer to Movie
		Node* left, *right; //Left & Right child pointers 
							
	};

	Node *root; // root of the tree

	void retrieveHelper(const Movie&, Movie*&, Node*) const;

	bool insertHelper(Node*, Node*&);

	void inorderHelper(ostream &, Node*) const;

	void makeEmptyHelper(Node *&);

};
#endif

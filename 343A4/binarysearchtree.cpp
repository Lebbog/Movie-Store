#include "binarysearchtree.h"
//---------------------------------------------------------------------------
// binarysearchtree.cpp
// Geoffrey Lebbos CSS 343 C
// 3/10/2017
// Last Modified: 3/15/2017
//---------------------------------------------------------------------------
// Default constructor
BinarySearchTree::BinarySearchTree()
{
	root = NULL;
}
//---------------------------------------------------------------------------
BinarySearchTree::~BinarySearchTree()
{
	makeEmpty();
}
//---------------------------------------------------------------------------
//isEmpty
bool BinarySearchTree::isEmpty() const
{
	return (root == NULL);
}
//---------------------------------------------------------------------------
//Public insert
bool BinarySearchTree::insert(Movie* movie)
{
	Node* ptr = new Node;
	ptr->left = ptr->right = NULL;
	ptr->data = movie;

	if (isEmpty())
	{
		root = ptr;
		return true;
	}
	return insertHelper(ptr, root);
}
//---------------------------------------------------------------------------
//Recursive insert
bool BinarySearchTree::insertHelper(Node* movie, Node*& current)
{
	if (current == NULL)
	{
		current = movie;
		return true;
	}
    if (*movie->data < *current->data)
	{
		return insertHelper(movie, current->left);
	}
	else if (*movie->data > *current->data)
	{
		return insertHelper(movie, current->right);
	}
	else
	{
		current->data->addToStock(movie->data->getStock());
		delete movie;
		movie = NULL;
		return false;
	}
}
//---------------------------------------------------------------------------
//Retrieve
void BinarySearchTree::retrieve(const Movie& target, Movie*& found) const
{
	if (isEmpty())
	{
		found = NULL;
		return;
	}
	if (target == *root->data)
	{
		found = root->data;
		return;
	}
	retrieveHelper(target, found, root);
}
//---------------------------------------------------------------------------
//	retrieve helper
void BinarySearchTree::retrieveHelper(const Movie & target, Movie*& found,
	Node* current) const
{
	if (current->left != NULL)
	{
		retrieveHelper(target, found, current->left);
	}
	if (*current->data == target)
	{
		found = current->data;
	}
	if (current->right != NULL)
	{
		retrieveHelper(target, found, current->right);
	}
}
//---------------------------------------------------------------------------
//makeEmpty
void BinarySearchTree::makeEmpty()
{
	if (isEmpty()) return;
	makeEmptyHelper(root);
}
//---------------------------------------------------------------------------
//	MakEmptyHelper
void BinarySearchTree::makeEmptyHelper(Node*& current)
{
	if (current != NULL)
	{
		makeEmptyHelper(current->left);
		makeEmptyHelper(current->right);
		delete current->data;
		delete current;
		current = NULL;
	}
}
//---------------------------------------------------------------------------
//overloaded << operator
ostream& operator<<(ostream& output, const BinarySearchTree &right)
{
	// tree is empty
	if (right.isEmpty())
	{
		output << "";
	}
	else
	{
		right.inorderHelper(output, right.root);
	}
	output << endl;
	return output;
}
//-------------------------- inorderHelper ----------------------------------
// Helper method for operator<<
// First parameter is output, second parameter is used to traverse tree
// Uses in-order traversal to assign data into ostream
void BinarySearchTree::inorderHelper(ostream& output, Node* current) const
{
	if (current->left != NULL)
	{
		inorderHelper(output, current->left);
	}
	output << *current->data;
	if (current->right != NULL)
	{
		inorderHelper(output, current->right);
	}
}

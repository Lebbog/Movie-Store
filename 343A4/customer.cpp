//---------------------------------------------------------------------------
// customer.cpp
// Geoffrey Lebbos CSS 343 C
// 3/10/2017
// Last Modified: 3/15/2017
//---------------------------------------------------------------------------
#include "customer.h"
//---------------------------------------------------------------------------
//default constructor
Customer::Customer()
{
	name = "defaultName";
	customerID = 0000;

}
//---------------------------------------------------------------------------
//Constructor
Customer::Customer(int ID, string first, string last)
{
	customerID = ID;
	name = first + " " + last;
}
//---------------------------------------------------------------------------
//destructor
Customer::~Customer()
{

}
//---------------------------------------------------------------------------
//getID
int Customer::getID() const
{
	return customerID;
}
//---------------------------------------------------------------------------
//setData
bool Customer::setData(ifstream& infile)
{
	
		string numberLength = "";
		infile >> numberLength;
		if (!infile.eof())
		{
			if (numberLength.length() != 4)
			{
				cout << "Invalid ID length" << endl;
				return false;
			}
			customerID = stoi(numberLength);
			if (customerID < 0)
			{
				cout << "Cannot have a negative ID" << endl;
				return false;
			}
			string first = "", last = "";
			infile >> last >> first;
			name = first + " " + last;
			return true;
		}
		return false;
}
//---------------------------------------------------------------------------
//getName
string Customer::getName() const
{
	return name;
}
//---------------------------------------------------------------------------
//setTransactionHistory
void Customer::setTransactionHistory(Transaction* t)
{
	historyQueue.push(t);
}
void Customer::printHistory() 
{
	cout << "Printing history for customer ID " << customerID << ":" << endl;
	if (historyQueue.empty())
	{
		cout << "Empty History" << endl;
		return;
	}
	while (!historyQueue.empty())
	{
		cout << *historyQueue.front() << endl;
		historyQueue.pop();
	}
}
//---------------------------------------------------------------------------
//operator<<
ostream& operator<<(ostream &output, const Customer& right)
{
	output << right.getID() << " " << right.getName();
	return output;
}

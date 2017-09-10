//---------------------------------------------------------------------------
// store.cpp
// Geoffrey Lebbos CSS 343 C
// 3/10/2017
// Last Modified: 3/15/2017
//---------------------------------------------------------------------------
#include "store.h"
//-----------------------------------------------------------------------------
//Constructor
Store::Store()
{
	
	for (int i = 0; i < TRANSIZE; i++)
	{
		tranPtr[i] = NULL;
	}

}
//-----------------------------------------------------------------------------
//Destructor
Store::~Store()
{
	for (int i = 0; i < TRANSIZE; i++)
	{
		if (tranPtr[i] != NULL)
		{
			delete tranPtr[i];
		}
		else
		{
			break;
		}
	}
}
//-----------------------------------------------------------------------------
// Reads a txt file and creates movie objects
// Movies that are successfully read are inserted into a tree
void Store::readMovies(ifstream& infile)
{
	MovieFactory mf;

	string type = "";
	bool inserted = false;
	getline(infile, type, ',');
	while (!infile.eof())
	{
		Movie* m = mf.createMovie(type.at(0));
		if (m == NULL)
		{
			string badInput = "";
			getline(infile, badInput);
		}
		else //(m != NULL)
		{
			m->setData(infile);
			switch (type.at(0))
			{
			case 'F':
			{
				inserted = comedyBST.insert(m);
				break;
			}
			case 'D':
			{
				inserted = dramaBST.insert(m);
				break;
			}
			case 'C':
			{
				inserted = classicBST.insert(m);
				break;
			}
			default:
			{
				break;
			}

			}
			// Duplicate movie, don't insert
			if (!inserted)
			{
				delete m;
				m = NULL;
			}
		}
		if (!infile.eof())
		{
			getline(infile, type, ',');
		}
	}
}
//-----------------------------------------------------------------------------
//Reads a txt file and builds transaction objects
//Transactions that are successfully read are placed in a queue
void Store::readCommands(ifstream& infile)
{
	TransactionFactory tf;
	bool successfulRead = false;
	char type;
	infile >> type;
	while (!infile.eof())
	{
		Transaction* t = tf.createTransaction(type);
		if (t == NULL)
		{
			string badInput = "";
			getline(infile, badInput);
		}
		else
		{
			successfulRead = t->setData(infile);
			if (successfulRead)
			{
				// Put  transaction queue
				tranQueue.push(t);
			}
			else
			{
				delete t;
				t = NULL;
			}
		}
		if (!infile.eof())
		{
			infile >> type;
		}
	}
}
//-----------------------------------------------------------------------------
//Reads a txt file and builds customer objects
//customers that are successfully read are placed in a hashtable
void Store::readCustomers(ifstream& infile)
{
	bool successfulRead;

	for (;;)
	{
		Customer* ptr = new Customer();
		successfulRead = ptr->setData(infile);
		if (infile.eof())
		{
			delete ptr;
			break;
		}
		if (successfulRead)
		{
			customerDatabase.insert(ptr);
		}
		else
		{
			delete ptr;
			ptr = NULL;
		}
	}

}
//-----------------------------------------------------------------------------
// Initializes the transaction queue, hashtable, and 3 Bstrees
void Store::initialize()
{
	ifstream movieInfile("data4movies.txt");
	if (!movieInfile) 
	{
		cout << "File could not be opened." << endl;
		return;
	}
	readMovies(movieInfile);

	ifstream commandInfile("data4commands.txt");
	if (!commandInfile) 
	{
		cout << "File could not be opened." << endl;
		return;
	}
	readCommands(commandInfile);

	ifstream customerInfile("data4customers.txt");
	if (!customerInfile)
	{
		cout << "File could not be opened." << endl;
		return;
	}
	readCustomers(customerInfile);
}
//-----------------------------------------------------------------------------
//Loops on items contained in transactionQueue
//Processes Transactions
void Store::processTransactions()
{
	int tranCounter = 0;
	while (!tranQueue.empty())
	{
		Transaction* temp = tranQueue.front();
		if (temp->getType() == 'I')
		{
			cout << "SHOWING INVENTORY" << endl;
			cout << comedyBST;
			cout << dramaBST;
			cout << classicBST;
		}
		if (temp->getType() == 'H')
		{
			Customer* foundCustomer = customerDatabase.
				getCustomer(temp->getCustomerID());
			if (foundCustomer != NULL)
			{
				foundCustomer->printHistory();
			}
		}
		//To find out which tree to retrieve from
		switch (temp->getMovieType())  
		{
		case 'F': //Comedy tree
		{
			Movie* foundMovie = NULL;
			Movie* tempMovie = NULL;
			Comedy* tempComedy = new Comedy();
			tempComedy->setTitle(temp->getTitle());
			tempComedy->setYear(temp->getYear());
			tempMovie = tempComedy;
			comedyBST.retrieve(*tempMovie, foundMovie);
			if (foundMovie != NULL)
			{
				//If movie exists
				Customer* foundCustomer = customerDatabase.
					getCustomer(temp->getCustomerID());
				if (foundCustomer != NULL)
				{
					//If customer exists
					bool successfulTransaction = temp->doTransaction(comedyBST, 
						dramaBST, classicBST, foundMovie, foundCustomer);
					if (successfulTransaction)
					{
						//set history
						foundCustomer->setTransactionHistory(temp);
					}
				}
			}
			delete tempMovie;
			tempMovie = NULL;
			break;

		}
		case 'D': //Drama tree
		{
			Movie* foundMovie = NULL;
			Movie* tempMovie = NULL;
			Drama* tempDrama = new Drama();
			tempDrama->setDirector(temp->getDirector());
			tempDrama->setTitle(temp->getTitle());
			tempMovie = tempDrama;
			dramaBST.retrieve(*tempMovie, foundMovie);

			if (foundMovie != NULL)
			{
				//If movie exists
				Customer* foundCustomer = customerDatabase.getCustomer(temp->getCustomerID());
				if (foundCustomer != NULL)
				{
					//If customer exists
					bool successfulTransaction = temp->doTransaction(comedyBST, 
						dramaBST, classicBST, foundMovie, foundCustomer);
					if (successfulTransaction)
					{
						//set history
						foundCustomer->setTransactionHistory(temp);
					}
				}
			}
			delete tempMovie;
			tempMovie = NULL;
			break;
		}
		case 'C': //Classic tree
		{
			Movie* foundMovie = NULL;
			Movie* tempMovie = NULL;
			Classic* tempClassic = new Classic();
			tempClassic->setYear(temp->getYear());
			tempClassic->setMajorActor(temp->getMajorActor());
			tempMovie = tempClassic;
			classicBST.retrieve(*tempMovie, foundMovie);
			if (foundMovie != NULL)
			{
				//If movie exists
				Customer* foundCustomer = customerDatabase.
					getCustomer(temp->getCustomerID());
				if (foundCustomer != NULL)
				{
					//If customer exists
					bool successfulTransaction = temp->doTransaction(comedyBST, 
						dramaBST, classicBST, foundMovie, foundCustomer);
					if (successfulTransaction)
					{
						//set history
						foundCustomer->setTransactionHistory(temp);
					}
				}
			}
			//Don't need movie anymore
			delete tempMovie;
			tempMovie = NULL;
			break;

		}
		default:
		{
			break;
		}
		}
		
		if (tranCounter < TRANSIZE)
		{
			tranPtr[tranCounter] = tranQueue.front();
		}
		tranCounter++;
		tranQueue.pop();
	}
}
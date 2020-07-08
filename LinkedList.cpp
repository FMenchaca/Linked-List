#include "LinkedList.h"

LinkedList :: LinkedList()
{
	first = NULL;
}

LinkedList :: LinkedList(const LinkedList & orgList)
{
	first = 0;
	*this = orgList;
}

void LinkedList::clear()
{
	ptr = first;

	while (ptr != 0)
	{
		ptr = ptr->next;
		delete first;
		first = ptr;
	}
}

LinkedList :: ~LinkedList()
{
	clear();
}

bool LinkedList :: empty() const
{
	return first == NULL;
}

const void LinkedList :: traverse() 
{
	ptr = first;
	while (ptr != NULL)
	{
		cout << ptr->value;
		ptr = ptr->next;
		//listSize;
	}
	cout << endl;
}

void LinkedList::insert(const int & value)
{
	newPtr = new Node(value);
	ptr = first;
	predPtr = NULL;
	
	// Set predptr to insert location
	while (ptr != NULL && value >= ptr->value)
	{
		predPtr = ptr;
		ptr = ptr->next;
	}

	if (predPtr != NULL)
	{
		newPtr->next = predPtr->next;
		predPtr->next = newPtr;
	}
	else
	{
		newPtr->next = first;
		first = newPtr;
	}
}

void LinkedList::remove(const int & deleteValue)
{
	ptr = first;
	while ((ptr != 0) && (ptr->value != deleteValue))
	{
		predPtr = ptr;
		ptr = ptr->next;
	}

	if (predPtr != 0)
	{
		ptr = predPtr->next;
		predPtr->next = ptr->next;
	}
	else
	{
		ptr = first;
		first = ptr->next;
	}

	delete ptr;
}

const void LinkedList::locate(const int & itemSought)
{
	ptr = first;
	while ((ptr != 0) && (ptr->value != itemSought))
	{
		predPtr = ptr;
		ptr = ptr->next;
	}
}

const LinkedList & LinkedList:: operator= (const LinkedList & rightHandSide)
{
	if (this != &rightHandSide)
	{
		if (empty())
		{
			Node * copyPtr = 0;
			Node * orgPtr = rightHandSide.first;

			while (orgPtr != 0)
			{
				if (first == 0)
				{
					first = copyPtr = new Node(orgPtr->value);
					orgPtr = orgPtr->next;
				}
				else
				{
					copyPtr->next = new Node(orgPtr->value);
					orgPtr = orgPtr->next;
				}
			}
		}
	}
	return *this;
}

// Node Class Definitions 
LinkedList::Node::Node()
{
	value = 0;
	next = NULL;
}

LinkedList::Node::Node(int num)
{
	value = num;
	next = NULL;
}

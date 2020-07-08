#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream> 
#include <new>
using namespace std;

class LinkedList
{
private:
	class Node
	{
	public:
		int value;
		Node * next;
		Node();
		Node(int num);
	private:
	};
	
	Node * first;
	Node * ptr;
	Node * predPtr;
	Node * newPtr;
	int listSize;

public:
	LinkedList();
	LinkedList(const LinkedList & orgList);
	~LinkedList();
	void clear();
	bool empty() const;
	const void traverse();
	const void locate(const int & itemSought);
	void insert(const int & value);
	void remove (const int & deleteValue);     
	const LinkedList & operator= (const LinkedList & rightHandSide);
};

#endif
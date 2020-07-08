#include "LinkedList.h"
#include <iostream>
//#include <new> //needed?
using namespace std;

int main()
{
	LinkedList list;
	LinkedList list2;
	list2 = list;
	LinkedList list3(list2);
	
	list.insert(10);
	list.insert(30);
	list.insert(50);
	list.insert(20);
	list.traverse();
	list.insert(70);
	list.insert(60);
	list.insert(40);
	list.insert(80);
	list.traverse();
	list.remove(10);
	list.traverse();
	list.remove(80);
	list.traverse();
	list.remove(50);
	list.traverse();
	list.remove(70);
	list.traverse();
	
	system("pause");
	return (0);

}
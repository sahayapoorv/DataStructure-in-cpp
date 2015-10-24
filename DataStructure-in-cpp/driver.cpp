#include <iostream>
#include "LinkedList.h"

int main()
{
	LinkedList<int> myLinkedList;
	int a;

	int count;
	std::cout << "Enter count:";
	std::cin >> count;
	while (count)
	{
		std::cin >> a;
		myLinkedList.Insert(a);
		count--;
	}

	std::cin >> a;
	myLinkedList.Insert(a, 2);

	myLinkedList.Print();
	myLinkedList.Remove();
	myLinkedList.Print();
	myLinkedList.Remove(2);
	myLinkedList.Print();
	return  0;
}
#include <iostream>

template <typename T>
class Node
{
public :
	T data;
	Node* next;
	Node(T& a) : data(a), next(NULL){}
};

template <typename T>
class LinkedList
{
	Node<T>* head;
	int size;

public:
	LinkedList() : head(NULL), size(0){}
	~LinkedList()
	{
		Node<T>* curr = head;
		Node<T>* temp;
		while (curr)
		{
			temp = curr;
			curr = curr->next;
			delete temp;
		}
	}
	/**
	* Inserts element at index. If the value of index is -1 then inserts element at end.
	*/
	void Insert(T& element, int index = -1);

	/**
	* Removes element at end. But if the value of index is provided then removes element at that index
	*/
	void Remove(int index = -1);

	/**
	* Prints all the elements in the List. Overload << for the typename for T.
	*/
	void Print();
};

template <typename T>
void LinkedList<T>::Remove(int index)
{
	Node<T>* curr = head;
	int currIndex = 1;
	if (index >= size)
	{
		return;
	}

	if (size == 1 && index == -1)
	{
		//delete the head
		delete head;
	}

	//size is not 1
	while (curr->next->next)
	{
		if (currIndex == index - 1)
		{
			break;
		}
		curr = curr->next;
		currIndex++;
	}


	Node<T>* temp = curr->next;
	if (curr->next->next)
	{
		curr->next = curr->next->next;
	}
	else
	{
		curr->next = NULL;
	}
	
	delete temp;
}

template <typename T>
void LinkedList<T>::Insert(T& element, int index)
{
	Node<T>* newNode = new Node<T>(element);
	Node<T>* curr = head;
	int currIndex = 0;
	if (index > size)
	{
		return;
	}

	if (!head)
	{
		head = newNode;
	}
	else
	{
		while (curr->next)
		{
			//index -2  as we want to stop one index before where we want to add new node
			if (index > -1 && currIndex == (index - 2))
			{
				break;
			}
			curr = curr->next;
			currIndex++;
		}

		if (curr->next)
		{
			newNode->next = curr->next;
		}

		curr->next = newNode;
	}
	size++;
}

template<typename T>
void LinkedList<T>::Print()
{
	Node<T>* curr = head;
	while (curr)
	{
		std::cout << curr->data << "\t";
		curr = curr->next;
	}

	std::cout << std::endl;
}


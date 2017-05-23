#pragma once
#include <iostream>

template<typename T>
class LinkListNode
{
public:

	T data; //T data
	LinkListNode* next;
	LinkListNode* prev; //doubly linked list

	LinkListNode()
	{
		data = T();
		next = nullptr;
		prev = nullptr;
	}
	LinkListNode(T a_data)
	{
		data = a_data;
		next = nullptr;
		prev = nullptr;
	}
	~LinkListNode()
	{

	}
	void Print()
	{
		std::cout << data << std::endl;
	}

};

template<typename T>
class LinkedList
{
public:
	LinkedList()
	{
		start = nullptr;
		count = 0;
		srand(unsigned int(time(NULL)));
	}

	~LinkedList()
	{
	}

	int GetCount()
	{
		return count;
	}

	void PushBack(T a_value)
	{
		//add our first node
		if (start == nullptr)
		{
			//create the node, setting it's data to "value" and using default pointer data (nullptr)
			LinkListNode<T>* newNode = new LinkListNode<T>(a_value);

			//point start node at new node
			start = newNode; // copies address
			last = newNode;
		}
		else //if there is already a start node
		{
			//create our node
			LinkListNode<T>* newNode = new LinkListNode<T>(a_value);

			//create a current node pointer - this just holds the address
			LinkListNode<T>* currentNode = start;

			//while our currentNode's next is not nullptr (not the end)
				//look at the node attached to this one
			while (currentNode->next != nullptr)
			{
				currentNode = currentNode->next;
			}

			//add it to the end of the list
			currentNode->next = newNode; //connect currentNode to newNode
			newNode->prev = currentNode;
			last = newNode;
		}

		//increment count
		count++;
		
	}

	void PushFront(T a_value)
	{
		if (start == nullptr)
		{
			//create the node, setting it's data to "value" and using default pointer data (nullptr)
			LinkListNode<T>* newNode = new LinkListNode<T>(a_value);

			//point start node at new node
			start = newNode; // copies address
			last = start;
		}
		else
		{
			//create the node, setting it's data to "value" and using default pointer data (nullptr)
			LinkListNode<T>* newNode = new LinkListNode<T>(a_value);

			start->prev = newNode; //connect start to newNode
			newNode->next = start;

			//point start node at new node
			start = newNode; // copies address

			//increment count
			count++;
		}
	}

	void Insert(T a_value, unsigned int a_index)
	{
		if (a_index == 0 || a_index == 1)
		{
			PushFront(a_value);
			return;

		}
		if (a_index == count)
		{
			PushBack(a_value);
			return;
		}
			//create our node
			LinkListNode<T>* newNode = new LinkListNode<T>(a_value);

			//create a current node pointer - this just holds the address
			LinkListNode<T>* currentNode = start;

			//while our currentNode's next is not nullptr (not the end)
			//look at the node attached to this one

			int index = 0;

			while (currentNode->next != nullptr)
			{
				index++;
					if (index == a_index - 1)
					{
						break;
					}
					currentNode = currentNode->next;
			}

			newNode->next = currentNode->next;
			currentNode->next = newNode;

			newNode->next->prev = newNode;
			newNode->prev = currentNode;



		count++;
	}

	void Remove(int a_index)
	{

		//create a current node pointer - this just holds the address
		LinkListNode<T>* currentNode = start;

		if (a_index == 0 || a_index == 1)
		{
			PopFront();
			return;
		}

		if (a_index == count)
		{
			PopBack();
			return;
		}

	//while our currentNode's next is not nullptr (not the end)
	//look at the node attached to this one

	int index = 0;

	while (currentNode->next != nullptr)
	{
		currentNode = currentNode->next;
		index++;

		if (index == a_index - 1)
		{
			break;
		}
	}

	currentNode->prev->next = currentNode->next;
	currentNode->next->prev = currentNode->prev;
	delete currentNode;

	count--;
	}

	void PopFront()
	{
		start = start->next;
		delete start->prev;
		start->prev = nullptr;
		count--;
	}

	void PopBack()
	{
		last = last->prev;
		delete last->next;
		last->next = nullptr;
		count--;
	}

	LinkListNode<T>* begin()
	{
		return start;
	}

	LinkListNode<T>* end()
	{
		return last;
	}

	LinkListNode<T>* Find(T a_value)
	{

		//create a current node pointer - this just holds the address
		LinkListNode<T>* currentNode = start;

		//while our currentNode's next is not nullptr (not the end)
		//look at the node attached to this one

		while (currentNode->data != a_value)
		{
			if (currentNode == last)
			{
				return nullptr;
			}
			
			currentNode = currentNode->next;
		}
		return currentNode;
	
	}

	void SortD()
	{
		//create a current node pointer - this just holds the address
		LinkListNode<T>* currentNode = start;
		bool hasSwapped = true;

		while (hasSwapped)
		{
			//reset swap
			hasSwapped = false;

			while (currentNode->next != nullptr)
			{
				if (currentNode->data > currentNode->next->data)
				{
					//swap them
					T temp = currentNode->data;
					currentNode->data = currentNode->next->data;
					currentNode->next->data = temp;
					hasSwapped = true;
				}
				currentNode = currentNode->next;
			}
			currentNode = start;
		}
	}

	void SortA()
	{
		//create a current node pointer - this just holds the address
		LinkListNode<T>* currentNode = start;
		bool hasSwapped = true;

		while (hasSwapped)
		{
			//reset swap
			hasSwapped = false;

			while (currentNode->next != nullptr)
			{
				if (currentNode->data < currentNode->next->data)
				{
					//swap them
					T temp = currentNode->data;
					currentNode->data = currentNode->next->data;
					currentNode->next->data = temp;
					hasSwapped = true;
				}
				currentNode = currentNode->next;
			}
			currentNode = start;
		}
	}

	void Shuffle()
	{
		for (int i = 0; i < count; i++)
		{
			T tempData = NULL;
			LinkListNode<T>* node1 = NULL;
			LinkListNode<T>* node2 = NULL;
			//Gets to random nodes
			int num = rand() % count;
			int countNode1 = 0;
			LinkListNode<T>* currentNode = start;
			while (currentNode != nullptr)
			{
				if (countNode1 == num)
				{
					node1 = currentNode;
					break;
				}
				countNode1++;
				currentNode = currentNode->next;
			}

			num = rand() % count;
			int countNode2 = 0;
			currentNode = start;

			while (currentNode != nullptr)
			{

				if (countNode2 == num)
				{
					node2 = currentNode;
					break;
				}
				countNode2++;
				currentNode = currentNode->next;
			}
			//Swaps two node's data
			tempData = node1->data;
			node1->data = node2->data;
			node2->data = tempData;
		}
	}

	void Reverse()
	{
		if (start == nullptr)
		{
			return;
		}

		LinkListNode<T> *prev = nullptr, *current = nullptr, *next = nullptr;
		current = start;
		while (current != nullptr)
		{
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
		//start point to last node
		start = prev;
	}

	void Print()
	{
		//start at start
		LinkListNode<T>* currNodeAddress = start;

		//keep looking at next node's until we hit the last node
		while (currNodeAddress != nullptr) //while we are looking at a node
		{
			std::cout << "[" << currNodeAddress->data << "]" << std::endl;

			//now look at the next address attached to the one we just printed
			currNodeAddress = currNodeAddress->next;
		}
	}

private:
	//pointer to our first node
	LinkListNode<T>* start;
	LinkListNode<T>* last;
	int count; //size
};


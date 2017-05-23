#pragma once
#include "assert.h"
#include <ctime>


#define DEFAULTCAPACITY 10

template<typename T>

class DynamicArray
{
public:
	//constructs int array with default capacity
	DynamicArray()
	{
		data = new T[10];
		capacity = 10;
		size = 0;
		srand(unsigned int(time(NULL)));
	}

	//constructs int array with start capacity
	DynamicArray(unsigned int startCapacity)
	{
		//create array on the heap
		data = new T[startCapacity];

		//update default capacity
		capacity = startCapacity;

		//update size
		size = 0;

		srand(unsigned int(time(NULL)));
	}

	//deletes memory at data
	~DynamicArray()
	{
		//delete our memory
		delete[] data;
	}

	//adds a value to the array
	void Push(T a_value)
	{
		//check if size == (eg. size = 10, capacity = 10)
		//resize our data array
		if (size == capacity)
		{
			Resize(capacity + a_value);
		}

		//copy a_value into array slot "size"
		data[size] = a_value;

		//increase size by 1
		size++;
	}

	//resize data to new a_capacity
	void Resize(unsigned int a_newCapacity)
	{
		//check newCapacity

		//if newCapacity == 0

		// "I claim that newCapacity != 0
		// If claim isnt true throw error
		assert(!(a_newCapacity == 0));

		//1. make a new array on the heap of newCapacity size
		//store its pointer in newData;
		T* newData = new T[a_newCapacity];

		//2. copy data from old array to new array
		//if size > newCapacity
		//loop to newCapacity when copying (allows resizing to smaller capacity) 
		//else 
		//loop to size (prevents copying unused memory)

		if (size > a_newCapacity)
		{
			for (unsigned int i = 0; i < a_newCapacity; i++)
			{
				newData[i] = data[i];
			}
		}
		else
		{
			for (unsigned int i = 0; i < size; i++)
			{
				newData[i] = data[i];
			}
		}

		//3. delete old data at data*
		delete[] data;

		//4. copy pointer from newData into data
		//data = newData;
		data = newData;

		capacity = a_newCapacity;
		if (size >= capacity)
		{
			size = capacity;
		}
	}

	//remove at index
	void RemoveAt(unsigned int a_index)
	{
		for (unsigned int i = a_index + 1; i < size; i++)
		{
			data[i - 1] = data[i];
		}

		size--;
	}

	//find first instance of a_value and remove that value
	void Remove(T a_value) 
	{
		for (unsigned int i = 0; i < size; i++)
		{
			if (data[i] == a_value)
			{
				for (unsigned int j = i + 1; j < size; j++)
				{
					data[j - 1] = data[j];
				}
			}
		}
		size--;
	}

	//returns index of first a_value
	int Find(T a_value) 
	{
		for (unsigned int i = 0; i < size; i++)
		{
			if (data[i] == a_value)
			{
				return i;
			}
		}
		return -1;
	}

	//finds and returns index of specified value
	int Find(T a_value, unsigned int a_index)
	{
		for (unsigned int i = a_index + 1; i < size; i++)
		{
			if (data[i] == a_value)
			{
				return i;
			}
		}
		return -1;
	}

	//inserts value into specified in
	void Insert(T a_value, unsigned int a_index)
	{
		//Checks if array is full or not
		if (size == capacity)
		{
			Resize(capacity + 1);
		}
		//Move each object to the right by one from the back
		for (unsigned int i = size; i >= a_index; i--)
		{
			data[i] = data[i - 1];
		}
		data[a_index - 1] = a_value;
		size++;
	}

	//sets all values in the array to default
	void Clear()
	{
		for (unsigned int i = 0; i < capacity; i++)
		{
			data[i] = NULL;
		}
	}

	void SortD()
	{
		bool hasSwapped = true;

		while (hasSwapped)
		{
			//reset swap
			hasSwapped = false;

			for (unsigned int i = 0; i < size - 1; i++)
			{
				if (data[i] > data[i+1])
				{
					//swap them
					T temp = data[i];
					data[i] = data[i + 1];
					data[i + 1] = temp;
					hasSwapped = true;
				}
			}
		}
	}

	void SortA()
	{
		bool hasSwapped = true;

		while (hasSwapped)
		{
			//reset swap
			hasSwapped = false;

			for (unsigned int i = 0; i < size; i++)
			{
				if (data[i] < data[i + 1])
				{
					//swap them
					T temp = data[i];
					data[i] = data[i + 1];
					data[i + 1] = temp;
					hasSwapped = true;
				}
			}
		}
	}

	//randomise the array
	void Shuffle()
	{
		for (unsigned int i = 0; i < size; i++)
		{
			int randomIndex = std::rand() % size;
			
			//swap them
			T temp = data[i];
			data[i] = data[randomIndex];
			data[randomIndex] = temp;
		}
		
	}

	void Reverse()
	{
		for (unsigned int i = 0; i < (size / 2); i++)
		{
			T temp = data[i];
			data[i] = data[(size - 1) - i];
			data[(size - 1) - i] = temp;
		}
	}

	void Print()
	{
		for (unsigned int i = 0; i < size; i++)
		{
			std::cout << data[i] << " ";
		}
	}

	T& operator[](int a_index)
	{
		return data[a_index];
	}

private:
	//contents/data
	T* data;
	//Used items
	unsigned int size;
	//how much space do we have
	unsigned int capacity;

};


#pragma once

template<typename T>
class Stack
{
public:
	Stack()
	{
		data = new T[10];
		capacity = 10;
		size = 0;
	}

	~Stack()
	{
		//delete our memory
		delete[] data;
	}

	//returns true if size == 0
	bool isEmpty() const
	{
		return(size == 0);
	}

	//returns the size (how many used spots)
	int GetSize() const
	{
		return size;
	}

	//add a_value to the top of our stack (end of array)
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

	//removes the last value from the array
	T Pop()
	{
		//decrement size (now our stack is technically one less)

		size--;
		//return data at size
		return data[size];
	}

	//returns data of last value in the array
	T Peek()
	{
		return data[size - 1];
	}

	void Print()
	{
		for (unsigned int i = 0; i < size; i++)
		{
			std::cout << data[i] << " ";
		}
	}

private:
	int* data;
	unsigned int capacity; //how much room
	unsigned int size; //how many used elements
};
#include "DynamicArray.h"
#include "LinkedList.h"
#include "Stack.h"
#include <iostream>

void TestDynamicArray();
void TestLinkedList();
void TestStack();

void main()
{
	TestStack();
	TestLinkedList();
	TestDynamicArray();

	system("pause");
}

void TestStack()
{
	Stack<int> testStack1;

	for (int i = 0; i < 12; i++)
	{
		testStack1.Push(i);
	}
	testStack1.Print();
	std::cout << "\n";
}

void TestLinkedList()
{
	LinkedList<int> numbers;

	numbers.PushBack(1);
	numbers.PushBack(3);
	numbers.PushFront(2);
	numbers.PushFront(8);
	numbers.Insert(4, 2);
	//numbers.Remove(5);
	//numbers.PopFront();
	//numbers.PopBack();
	numbers.SortD();
	numbers.SortA();
	//numbers.Shuffle();
	numbers.Reverse();
	numbers.Print();

	std::cout << "Count: " << numbers.GetCount() << std::endl;
	std::cout << "Start: ";
	numbers.begin()->Print();
	std::cout << "End: ";
	numbers.end()->Print();
	//numbers.Find(2)->Print();
}

void TestDynamicArray()
{
	//test construction
	DynamicArray<int> testArray1;
	std::cout << "--testArray1--\n";

	//test pushing values to our dynamic array
	std::cout << "\nPush 11 values into the array \n";
	for (int i = 0; i < 11; i++)
	{
		testArray1.Push(i);	

		if (testArray1[i] != i)
		{
			std::cout << "\nFail\n";
		}
	}
	testArray1.Print();
	std::cout << "\n";

	//test resize of array
	std::cout << "\nResize to  5 spaces\n";
	testArray1.Resize(5);
	testArray1.Print();
	std::cout << "\n";

	//test remove of the first instance of a_value
	std::cout << "\nRemove the value ""\"3\" \n";
	testArray1.Remove(3);
	testArray1.Print();
	std::cout << "\n";

	//test remove at the specified index
	std::cout << "\nRemove at an index of 2\n";
	testArray1.RemoveAt(2);
	testArray1.Print();
	std::cout << "\n";


	//test overloaded constructer - capacity should be 20
	DynamicArray<int> testArray2(20);
	std::cout << "\n--testArray2--";

	//test pushing values to our dynamic array
	std::cout << "\n\nPush 25 values into an array of 20\n";
	for (int i = 0; i < 25; i++)
	{
		testArray2.Push(i);
	}
	testArray2.Print();
	std::cout << "\n";

	//test inserting 1 at 3rd position
	
	std::cout << "\nInsert value 1 at 3rd index\n";
	testArray2.Insert(1, 3);
	testArray2.Print();
	std::cout << "\n";

	std::cout << "\nSort Ascending\n";
	testArray2.SortA();
	testArray2.Print();
	std::cout << "\n";

	std::cout << "\nSort Descending\n";
	testArray2.SortD();
	testArray2.Print();
	std::cout << "\n";

	int foundIndex = testArray2.Find(13);
	std::cout << "\nFinds first instance of the value 13 and returns index\n";
	std::cout << "index of 13: " << foundIndex << "\n";
	if (foundIndex == -1)
	{
		std::cout << "No value found\n";
	}

	int foundIndex2 = testArray2.Find(13, 15);
	std::cout << "\nFinds first instance of the value 13 starting from index of 15\n";
	std::cout << "index of 13: " << foundIndex2 << "\n";
	if (foundIndex2 == -1)
	{
		std::cout << "No value found\n";
	}

	std::cout << "\nReverse\n";
	testArray2.Reverse();
	testArray2.Print();
	std::cout << "\n";

	std::cout << "\nShuffle\n";
	testArray2.Shuffle();
	testArray2.Print();
	std::cout << "\n";

	std::cout << "\nClear\n";
	testArray2.Clear();
	testArray2.Print();
	std::cout << "\n";

}
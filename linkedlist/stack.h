// Created by Gregory Brisebois
// for CS-124 Data Structures,
// Professor Kamran Eftekari

// Reminder:
// The HEAD is the top of the queue!
// The TAIL is the bottom of the queue!

#ifndef LINKEDLIST
#include "linkedlist.h"
#endif

template <class T>
class Stack
{
	private:
		LinkedList<T> * list;
		
	public:
		bool push(const T);
		bool pop(T & item);
		bool getTop(T & item);
		bool isEmpty();
		void print();
		
		Stack();
		~Stack();
};

// Constructor
template <typename T>
Stack<T>::Stack()
{
	list = new LinkedList<T>;
}

// Destructor
template <typename T>
Stack<T>::~Stack()
{
	delete list;
}

// Convert input to element and push to stack
template <typename T>
bool Stack<T>::push(const T item)
{
	if(list != NULL)
	{
		return list->addToHead(item);
	}
	
	return false;
}

// Dereference top of stack and delete pointer
template <typename T>
bool Stack<T>::pop(T & item)
{
	if(list->isEmpty()) return false;
	item = list->getHead();
	return list->removeHead();
}

// Get value of top of stack
template <typename T>
bool Stack<T>::getTop(T & item)
{
	item = list->getHead();
	return true;
}

// Check if stack is empty
template <typename T>
bool Stack<T>::isEmpty()
{
	return list->isEmpty();
}

// Print out all elements in the stack from top to bottom
template <typename T>
void Stack<T>::print()
{
	list->printForwards();
}

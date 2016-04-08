// Created by Gregory Brisebois
// for CS-124 Data Structures,
// Professor Kamran Eftekari

// Reminder:
// The HEAD is the entrance/start of the queue!
// The TAIL is the end of the queue!

#ifndef LINKEDLIST
#include "linkedlist.h"
#endif

template <class T>
class Queue
{
	private:
		LinkedList<T> * list;
		
	public:
		bool enqueue(T item);
		T dequeue();
		bool isEmpty();
		void print();
		
		Queue();
		~Queue();
		
		void printHead()
		{
			std::cout << list->getHead() << std::endl;
		}
};

// Constructor
template <typename T>
Queue<T>::Queue()
{
	list = new LinkedList<T>;
}

// Destructor
template <typename T>
Queue<T>::~Queue()
{
	delete list;
}

// enqueue
// Put a new object at the start of the queue
template <typename T>
bool Queue<T>::enqueue(T item)
{
	list->addToHead(item);
	return true;
}

// dequeue
// Put a new object at the start of the queue
template <typename T>
T Queue<T>::dequeue()
{
	T item = list->getTail();
	list->removeTail();
	return item;
}

// Check if queue is empty
template <typename T>
bool Queue<T>::isEmpty()
{
	return list->isEmpty();
}

// Print out all elements in the queue from Entrance/Start to Exit/End
template <typename T>
void Queue<T>::print()
{
	list->printBackwards();
}













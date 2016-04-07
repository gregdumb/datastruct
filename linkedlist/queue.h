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
		bool enqueue(const T & item);
		bool dequeue(T & item);
		bool isEmpty();
		void print();
		
		Queue();
		~Queue();
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
bool Queue<T>::enqueue(const T & item)
{
	list->addToHead(item);
	return true;
}

// dequeue
// Put a new object at the start of the queue
template <typename T>
bool Queue<T>::dequeue(T & item)
{
	item = list->getTail();
	list->removeTail();
}

// Check if queue is empty
template <typename T>
bool Queue<T>::isEmpty()
{
	return list->isEmpty();
}

// Print out all elements in the queue from Exit/End to Entrance/Start
template <typename T>
void Queue<T>::print()
{
	list->printBackwards();
}













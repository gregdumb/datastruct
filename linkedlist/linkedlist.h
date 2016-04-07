// Created by Gregory Brisebois
// for CS-124 Data Structures,
// Professor Kamran Eftekari

// REMEMBER:
// T 		= AN INT
// ELEMENT 	= THE OBJECT/POINTER

#define LINKEDLIST
#include "element.h"

template <class T>
class LinkedList
{
	private:
		Element<T>* head;
		Element<T>* tail;
		
		Element<T>* toElem(const T & item);
		
	public:
		T getHead();
		T getTail();
		
		bool addToHead(const T & item);
		bool addToTail(T&);
		
		bool removeHead();
		bool removeTail();
		
		void printForwards();
		void printBackwards();
		
		bool isEmpty();
		
		LinkedList();
		~LinkedList();
};

// Constructor
template <typename T>
LinkedList<T>::LinkedList()
{
	head = NULL;
	tail = NULL;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
	while(head != NULL) removeHead();
}

template <typename T>
Element<T>* LinkedList<T>::toElem(const T & item)
{
	return new Element<T>(item);
}

// getHead
// Get a reference to the head element
template <typename T>
T LinkedList<T>::getHead()
{
	return head->getValue();
}

// getTail
// Get a reference to the tail element
template <typename T>
T LinkedList<T>::getTail()
{
	return tail->getValue();
}

// addToHead
// Adds a new element to the list, replacing the HEAD
template <typename T>
bool LinkedList<T>::addToHead(const T & item)
{
	Element<T>* newHead = toElem(item);
	
	if(head != NULL)
	{
		head->setPrevious(newHead);
		newHead->setNext(head);
	}
	else
	{
		tail = newHead;
	}
	
	head = newHead;
	
	return true;
}

// addToTail
// Adds new element to the list, replacing the TAIL
template <typename T>
bool LinkedList<T>::addToTail(T & item)
{
	Element<T>* newTail = toElem(item);
	
	if(tail != NULL)
	{
		tail->setNext(newTail);
		newTail->setPrevious(tail);
	}
	else
	{
		head = newTail;
	}
	
	tail = newTail;
	
	return true;
}

// removeHead
// Deletes the head element
template <typename T>
bool LinkedList<T>::removeHead()
{
	if(head == tail)
	{
		delete head;
		head = NULL;
		tail = NULL;
	}
	else
	{
		Element<T>* newHead = head->getNext();
		delete head;
		head = newHead;
	}
	
	return true;
}

// removeTail
// Deletes the tail element
template <typename T>
bool LinkedList<T>::removeTail()
{
	if(tail == NULL)
	{
		return false;
	}
	else if(head == tail)
	{
		head = NULL;
		tail = NULL;
	}
	else
	{
		Element<T>* newTail = tail->getPrevious();
		delete tail;
		tail = newTail;
	}
	
	return true;
}
	
// printForwards
// Prints out all elements, from HEAD TO TAIL
template <typename T>
void LinkedList<T>::printForwards()
{
	if(head != NULL) head->printRemaining();
}

// printBackwards
// Prints out all elements, from TAIL TO HEAD
template <typename T>
void LinkedList<T>::printBackwards()
{
	if(tail != NULL) tail->printPrevious();
}

// Checks if the list is empty or not
template <typename T>
bool LinkedList<T>::isEmpty()
{
	return head == NULL;
}



















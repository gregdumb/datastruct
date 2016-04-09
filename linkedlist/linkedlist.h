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
		
		bool addToHead(T item);
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

// Destructor
template <typename T>
LinkedList<T>::~LinkedList()
{
	while(head != NULL) removeHead();
}

// Convert T to an element of type T
template <typename T>
Element<T>* LinkedList<T>::toElem(const T & item)
{
	return new Element<T>(item);
}

// Get a reference to the head element
template <typename T>
T LinkedList<T>::getHead()
{
	return head->getValue();
}

// Get a reference to the tail element
template <typename T>
T LinkedList<T>::getTail()
{
	return tail->getValue();
}

// Adds a new element to the list, replacing the HEAD
template <typename T>
bool LinkedList<T>::addToHead(T item)
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
		head->setPrevious(NULL);
	}
	
	return true;
}

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
		tail->setNext(NULL);
	}
	
	return true;
}

// Prints out all elements, from HEAD TO TAIL
template <typename T>
void LinkedList<T>::printForwards()
{
	if(head != NULL) head->printRemaining();
	else std::cout << std::endl;
}

// Prints out all elements, from TAIL TO HEAD
template <typename T>
void LinkedList<T>::printBackwards()
{
	if(tail != NULL) tail->printPrevious();
	else std::cout << std::endl;
}

// Checks if the list is empty or not
template <typename T>
bool LinkedList<T>::isEmpty()
{
	return head == NULL;
}



















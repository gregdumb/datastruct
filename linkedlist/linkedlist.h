template <class T>
class LinkedList
{
	private:
		Element<T>* head;
		Element<T>* tail;
		
	public:
		bool addToHead(Element<T>*);
		bool addToTail(Element<T>*);
		
		void printForwards();
		void printBackwards();
		
	LinkedList();
};

template <typename T>
LinkedList<T>::LinkedList()
{
	head = NULL;
	tail = NULL;
}

// Adds a new element to the list, replacing the HEAD
template <typename T>
bool LinkedList<T>::addToHead(Element<T>* newHead)
{
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
bool LinkedList<T>::addToTail(Element<T>* newTail)
{
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

// Prints out all elements, from HEAD TO TAIL
template <typename T>
void LinkedList<T>::printForwards()
{
	if(head != NULL) head->printRemaining();
}

// Prints out all elements, from TAIL TO HEAD
template <typename T>
void LinkedList<T>::printBackwards()
{
	if(tail != NULL) tail->printPrevious();
}





















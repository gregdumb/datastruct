template <class T>
class LinkedList
{
	private:
		Element<T>* head;
		Element<T>* tail;
		
	public:
		Element<T>* getHead();
		Element<T>* getTail();
		
		bool addToHead(Element<T>*);
		bool addToTail(Element<T>*);
		
		bool removeHead();
		bool removeTail();
		
		void printForwards();
		void printBackwards();
		
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
	if(head != NULL) head->deleteElems();
}

// getHead
// Get a reference to the head element
template <typename T>
Element<T>* LinkedList<T>::getHead()
{
	return head;
}

// getTail
// Get a reference to the tail element
template <typename T>
Element<T>* LinkedList<T>::getTail()
{
	return tail;
}

// addToHead
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

// addToTail
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

// removeHead
// Deletes the head element
template <typename T>
bool LinkedList<T>::removeHead()
{
	if(head == tail)
	{
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





















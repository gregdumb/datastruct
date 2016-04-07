// Created by Gregory Brisebois
// for CS-124 Data Structures,
// Professor Kamran Eftekari

// REMEMBER:
// T 		= AN INT
// ELEMENT 	= THE OBJECT/POINTER

template <class T>
class Element
{
	private:
		T value;
		Element* next;
		Element* previous;
	
	public:
		T getValue();
		Element* getNext();
		Element* getPrevious();
		
		bool setValue(T);
		bool setNext(Element*);
		bool setPrevious(Element*);
		
		void printRemaining(); // prints out all elements after this one, inclusive
		void printPrevious(); // prints all elements before this one, inclusive
		
		void deleteElems();
		
		Element();
		Element(T);
};

template <typename T>
Element<T>::Element()
{
}

template <typename T>
Element<T>::Element(T newVal)
{
	setValue(newVal);
}

// Returns the next item in the list of elements
template <typename T>
Element<T>* Element<T>::getNext()
{
	return next;
}

// Returns the previous item in the list of elements
template <typename T>
Element<T>* Element<T>::getPrevious()
{
	return previous;
}

template <typename T>
inline
bool Element<T>::setValue(T newVal)
{
	value = newVal;
	return true;
}

template <typename T>
bool Element<T>::setNext(Element* newNext)
{
	next = newNext;
	return true;
}

template <typename T>
bool Element<T>::setPrevious(Element* newPrevious)
{
	previous = newPrevious;
	return true;
}

template <typename T>
T Element<T>::getValue()
{
	return value;
}

// Print all elements AFTER this one, inclusive
template <typename T>
void Element<T>::printRemaining()
{
	std::cout << value << std::endl;
	if(next != NULL) next->printRemaining();
}

// Print all elements BEFORE this one, inclusive
template <typename T>
void Element<T>::printPrevious()
{
	std::cout << value << std::endl;
	if(previous != NULL) previous->printPrevious();
}

template <typename T>
void Element<T>::deleteElems()
{
	if(getNext() != NULL)
		getNext()->deleteElems();
		
	// delete this; //was causing crash
}













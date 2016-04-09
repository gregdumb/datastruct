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
		
		void printRemaining();
		void printPrevious();
		
		Element();
		Element(T);
};

// Default constructor
template <typename T>
Element<T>::Element()
{
	next = NULL;
	previous = NULL;
}

// Custom constructor
template <typename T>
Element<T>::Element(T newVal)
{
	setValue(newVal);
	next = NULL;
	previous = NULL;
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

// Set the T value of the element
template <typename T>
inline
bool Element<T>::setValue(T newVal)
{
	value = newVal;
	return true;
}

// Set the pointer to the next in the chain
template <typename T>
bool Element<T>::setNext(Element* newNext)
{
	next = newNext;
	return true;
}

// Set the pointer to the next in the chain
template <typename T>
bool Element<T>::setPrevious(Element* newPrevious)
{
	previous = newPrevious;
	return true;
}

// Get the T value of the element
template <typename T>
T Element<T>::getValue()
{
	return value;
}

// Print all elements AFTER this one, inclusive
template <typename T>
void Element<T>::printRemaining()
{
	std::cout << value << " ";
	if(next != NULL) next->printRemaining();
	else std::cout << std::endl;
}

// Print all elements BEFORE this one, inclusive
template <typename T>
void Element<T>::printPrevious()
{
	std::cout << value << " ";
	if(previous != NULL) previous->printPrevious();
	else std::cout << std::endl;
}













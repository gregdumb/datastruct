template <class T>
class Element
{
	public:
		T value;
		Element* next;
		Element* previous;
	
	public:
		T getValue();
		T getNext();
		T getPrevious();
		
		bool setValue(T);
		bool setNext(Element*);
		bool setPrevious(Element*);
		
		void printRemaining(); // prints out all elements after this one, inclusive
		void printPrevious(); // prints all elements before this one, inclusive
};

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












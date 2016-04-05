#include <iostream>

#include "element.h"
#include "linkedlist.h"


int main()
{
	//element * E = new element<int>();
	Element<int> * elem1 = new Element<int>;
	elem1->setValue(420);
	
	Element<int> * elem2 = new Element<int>;
	elem2->setValue(69);
	
	Element<int> * elem3 = new Element<int>;
	elem3->setValue(360);
	
	LinkedList<int> * list = new LinkedList<int>;
	list->addToHead(elem1);
	list->addToHead(elem2);
	
	list->printForwards();
	
	list->addToHead(elem3);
	list->printForwards();
	
	//std::cout << elem1->getValue() << std::endl;
}

// Created by Gregory Brisebois
// for CS-124 Data Structures,
// Professor Kamran Eftekari

#include <iostream>

#include "stack.h"
#include "queue.h"


int main()
{	
	Stack<int> * stack = new Stack<int>;
	Queue<int> * queue = new Queue<int>;
	
	queue->enqueue(1);
	queue->enqueue(2);
	queue->enqueue(3);
	queue->enqueue(4);
	
	queue->print();
	
	std::cout << "Dequeued: " << std::endl;
	int deq;
	queue->dequeue(deq);
	std::cout << deq << std::endl;
	
	std::cout << "The rest: " << std::endl;
	queue->print();
	
	delete queue;
	
	
	int popped;
	stack->pop(popped);
	
	stack->push(1);
	stack->push(2);
	stack->push(3);
	stack->push(4);
	
	std::cout << "All of them: " << std::endl;
	stack->print();
	
	std::cout << "Pop top: " << std::endl;
	
	stack->pop(popped);
	std::cout << popped << std::endl;
	
	std::cout << "The rest: " << std::endl;
	stack->print();
	
	
	/*
	LinkedList<int> * list = new LinkedList<int>;
	list->addToHead(elem1);
	list->addToHead(elem2);
	list->addToHead(elem3);
	std::cout << "Forward: " << std::endl;
	list->printForwards();
	
	list->removeHead();
	std::cout << "Removed head: " << std::endl;
	list->printForwards();*/
	
	//std::cout << elem1->getValue() << std::endl;
}

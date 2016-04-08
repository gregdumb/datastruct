#include <iostream>
#include <string>
#include "stack.h"
#include "queue.h"


std::string getInput()
{
	std::cout << "Please enter the expression to be evaluated: ";
	std::string input = "";
	std::getline(std::cin, input);
	
	return input;
}

bool isOperand(char ch)
{
	return !(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '(' || ch == ')');
	//return true;
}

int isp(char ch)
{
	switch(ch)
	{
		case '^':
			return 3;
		case '*':
			return 2;
		case '/':
			return 2;
		case '+':
			return 1;
		case '-':
			return 1;
		case '(':
			return 0;
		default:
			return -1;
	}
}

int icp(char ch)
{
	switch(ch)
	{
		case '^':
			return 4;
		case '*':
			return 2;
		case '/':
			return 2;
		case '+':
			return 1;
		case '-':
			return 1;
		case '(':
			return 4;
		default:
			return -1;
	}
}

void infixToPostfix(Queue<char>* Q1, Queue<char>* Q2, Stack<char>* S1)
{
	char op;
	char c;
	
	c = Q1->dequeue();
	
	while(c != '#')
	{
		if(isOperand(c))
		{
			Q2->enqueue(c);
		}
	}
}



int main()
{
	// Get input
	std::string input = getInput();
	
	// Create stacks & queues
	Queue<char> * Q1 = new Queue<char>; // Original expression
	Stack<char> * S1 = new Stack<char>; 
	
	
	// Enqueue original expression in Q1
	for(int i = 0; i < input.length(); i++)
	{
		if(input.at(i) != ' ')
		{
			Q1->enqueue(input.at(i));
		}
	}
	Q1->enqueue('#');
	
	S1->push('#');
	
	std::cout << "Original Q1: ";
	Q1->print();
	
	char c;
	c = Q1->dequeue();
	std::cout << "!!! Did first dequeue from Q1: " << c << std::endl;
	
	char sTop;
	S1->getTop(sTop);
	
	char op;
	
	Queue<char> * Q2 = new Queue<char>;
	
	while(c != '#')
	{
		std::cout << "===================================" << std::endl;
		
		if(isOperand(c))
		{
			Q2->enqueue(c);
			std::cout << "Enqueued " << c << std::endl;
			std::cout << "Queue 2:";
			Q2->print();
			std::cout << "Queue 2 Head: ";
			Q2->printHead();
		}
		else if(c == ')')
		{
			S1->getTop(sTop);
			while(!S1->isEmpty() && sTop != '(')
			{
				S1->pop(op);
				Q2->enqueue(op);
				std::cout << "--- 2nd while: Popped and enqueued " << op << std::endl;
				S1->getTop(sTop);
			}
			S1->pop(op);
		}
		else
		{
			S1->getTop(sTop);
			while(!S1->isEmpty() && isp(sTop) >= icp(c))
			{
				S1->pop(op);
				Q2->enqueue(op);
				S1->getTop(sTop);
			}
			S1->push(c);
		}
		
		std::cout << "%% LOOP RESULTS %%" << std::endl;
		std::cout << "Q1: "; 
		Q1->print();
		std::cout << "Q2: ";
		Q2->print();
		std::cout << "S1: ";
		S1->print();
		std::cout << "%% END OF LOOP %%" << std::endl;
		
		c = Q1->dequeue();
	}
	
	std::cout << "THE STACK:";
	S1->print();
	
	if(!S1->isEmpty())
	{
		S1->getTop(sTop);
		while(!S1->isEmpty() && sTop != '#')
		{
			S1->pop(op);
			Q2->enqueue(op);
			S1->getTop(sTop);
		}
	}	
	
	std::cout << "Queue 2 FINAL: ";
	Q2->print();
	
}

























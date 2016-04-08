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
	
	Q1->dequeue(c);
	
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
	Queue<char> * Q2 = new Queue<char>; // Postfix expression
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
	
	std::cout << "Original Expression:" << std::endl;
	Q1->print();
	
	char X;
	Q1->dequeue(X);
	std::cout << "!!! Dequeued: " << X << std::endl;
	
	char c = X;
	
	while(c != '#')
	{
		
		
		if(isOperand(c))
		{
			std::cout << "Queue 2 BEFORE c was an operand: ";
			Q2->print();
			std::cout << std::endl;
			
			std::cout << "Queue 1 BEFORE c was an operand: ";
			Q1->print();
			std::cout << std::endl;
			
			Q2->enqueue(c);
			
			std::cout << "C: \"" << c << "\" was an operand!" << std::endl;
			std::cout << "Queue 2 after c was an operand: ";
			Q2->print();
			std::cout << std::endl;
			
			std::cout << "Queue 1 BEFORE c was an operand: ";
			Q1->print();
			std::cout << std::endl;
		}
		else if(c == ')')
		{
			char s1top;
			S1->getTop(s1top);
			while(!S1->isEmpty() && s1top != '(')
			{
				char op;
				S1->pop(op);
				Q2->enqueue(op);
				S1->getTop(s1top);
			}
			char op;
			S1->pop(op); // Remove last '('
		}
		else
		{
			char s1top;
			S1->getTop(s1top);
			while(!S1->isEmpty() && isp(s1top) >= icp(c))
			{
				char op;
				S1->pop(op);
				Q2->enqueue(op);
			}
			S1->push(c);
		}
		
		std::cout << "Queue 2 LOOP AFTER c = " << c << ": ";
		Q2->print();
		std::cout << "------------------------------------------" << std::endl << std::endl;
		
		Q1->dequeue(c);
		std::cout << "!!! Dequeued: " << c << std::endl;
		
		
	}
	
	std::cout << "Queue 2 BEFORE SECOND THING: ";
	Q2->print();
	std::cout << std::endl;
	
	if(!S1->isEmpty())
	{
		char op;
		S1->getTop(op);
		while(!S1->isEmpty() && op != '#')
		{
			S1->pop(op);
			Q2->enqueue(op);
			S1->getTop(op);
		}
	}
	
	std::cout << "Queue 1:" << std::endl;
	Q1->print();
	
	std::cout << "Queue 2:" << std::endl;
	Q2->print();
	
	std::cout << "Stack 1:" << std::endl;
	S1->print();
}

























#include <iostream>
#include <string>
#include <math.h>
#include "stack.h"
#include "queue.h"

// Gets the input of the user
std::string getInput()
{
	std::cout << "Please enter the expression to be evaluated: ";
	std::string input = "";
	std::getline(std::cin, input);
	
	return input;
}

// Returns true if ch is an operand, +-*/^()
bool isOperand(char ch)
{
	return !(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '(' || ch == ')');
}

// Get in-stack priorety of operator
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

// Get incoming priorety of operator
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

int main()
{
	// Get input
	std::string input = getInput();
	std::cout << "You entered: " << input << std::endl;
	
	// Create stacks & queues
	Queue<char> * Q1 = new Queue<char>; // Original expression
	Queue<char> * Q2 = new Queue<char>; // Postfix expression
	Stack<char> * S1 = new Stack<char>; // Stack for operators
	
	// Enqueue original expression string in Q1
	for(int i = 0; i < input.length(); i++)
	{
		if(input.at(i) != ' ')
		{
			Q1->enqueue(input.at(i));
		}
	}
	
	// Add a stop character
	Q1->enqueue('#');
	
	// Add a stop character to the bottom of the stack
	S1->push('#');
	
	// Print out the infix queue
	std::cout << "Contents of queue: ";
	Q1->print();
	
	// Character to whole the current character we are analyzing
	char c;
	c = Q1->dequeue();
	
	// Character to hold the top of the stack
	char sTop;
	S1->getTop(sTop);
	
	// Placeholder character to use for popping and pushing
	char op;
	
	// Main infix-to-postfix loop:
	while(c != '#')
	{
		// Enqueue numbers straightaway
		if(isOperand(c))
		{
			Q2->enqueue(c);
		}
		// If we have reached the end of a set of brackets:
		else if(c == ')')
		{
			// Put the collected operators into the queue
			S1->getTop(sTop);
			while(!S1->isEmpty() && sTop != '(')
			{
				S1->pop(op);
				Q2->enqueue(op);
				S1->getTop(sTop);
			}
			// Remove the '('
			S1->pop(op);
		}
		// If c is an operator
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
		
		// Get new value for c:
		c = Q1->dequeue();
	}
	
	// There will be some operators leftover in the stack,
	// now we will move these over.
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
	
	// Print out the postfix:
	std::cout << "Postfix Queue: ";
	Q2->print();
	
	// Stack that will hold our actual numbers during evaluation
	Stack<int> * S2 = new Stack<int>;
	
	bool error = false;
	
	// Evaluation loop
	while(!Q2->isEmpty() && !error)
	{
		op = Q2->dequeue();
		
		// If we have a number, put it on the number stack
		if(isOperand(op))
		{
			int opint = op - '0';
			S2->push(opint);
		}
		// If we have an operator, perform the operation
		else
		{
			int op2, op1, result;
			
			S2->pop(op2);
			S2->pop(op1);
			
			switch(op)
			{
				case '^':
					result = pow(op1, op2);
					break;
				case '*':
					result = op1 * op2;
					break;
				case '/':
					if(op2 != 0)
					{
						result = op1 / op2;
					}
					else
					{
						std::cout << "Error! Division by zero not allowed!" << std::endl;
						error = true;
						result = 0;
					}
					break;
				case '+':
					result = op1 + op2;
					break;
				case '-':
					result = op1 - op2;
					break;
				default:
					result = 0;
					std::cout << "An error happened!" << std::endl;
					break;
			}
			
			// Put the result of the operation back on the stack
			S2->push(result);
		}
		
		// For debugging purposes: show contents of stack and queue every loop
		std::cout << "Contents of queue: ";
		Q2->print();
		std::cout << "Contents of stack: ";
		S2->print();
		
	}
	
	// Print out the result
	if(!error)
	{
		std::cout << "The result is: ";
		S2->print();
	}
	else
	{
		std::cout << "Program terminated due to division by zero!" << std::endl;
	}
	
	delete Q1;
	delete Q2;
	delete S1;
	delete S2;
}

























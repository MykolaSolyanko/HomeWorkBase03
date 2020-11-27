#include <iostream>

const int n = 3;
struct Stack
{
	int A[n];
	int count{};
};

void Creation(Stack* p)
{
	p->count = 0;
}

int Full(Stack* p)
{
	if (p->count == 0) {
		return 1;
	}
	else if (p->count == n) {
		return -1;
	}
	else {
		return 0;
	}
}

void Add(Stack* p)
{
	int value{};
	std::cout << "Please enter your element  "; 
	std::cin >> value;
	p->A[p->count] = value;
	p->count++;
}

void Delete(Stack* p)
{
	p->count--;
}

int Top(Stack* p)
{
	return p->A[p->count - 1];
}

int Size(Stack* p)
{
	return p->count;
}

int main()
{
	Stack s;
	Creation(&s);
	char number;
	while(true)
	{
		std::cout << "1. Add the element" << std::endl;
		std::cout << "2. Delete the element" <<std:: endl;
		std::cout << "3. Top element" << std::endl;
		std::cout << "4. Size of the Stack" <<std:: endl;
		std::cout << "0. Exit" << std::endl;
		std::cout << "Number of command ";
		std:: cin >> number;
		switch (number)
		{
		case '1':
			if (Full(&s) == -1) {
				std::cout << std::endl << "Stack is full\n";
			}
			else
			{
				Add(&s);
				std::cout << std::endl << "The element was added to the stack\n";
			} break;
			
		case '2':
			if (Full(&s) == 1) {
				std::cout << std::endl << "Stack is empty\n";
			}
			else
			{
				Delete(&s);
				std::cout << std::endl << "The element was deleted from the Stack\n";
			} break;
			
		case '3':
			if (Full(&s) == 1) {
				std::cout <<std:: endl << "Stack is empty\n";
			}
			else {
				std::cout << "\nTop element: " << Top(&s) << "\n\n";
			}
			break;
			
		case '4':
			if (Full(&s) == 1) {
				std::cout << std::endl << "Stack is empty\n";
			}
			else {
				std::cout << "\nSize of the Stack: " << Size(&s) << "\n\n";
			}
				break;
			
		case '0': break;
		default:
			std::cout << std::endl << "Command is not defined\n";
			break;
		}
	} 

	return 0;
}

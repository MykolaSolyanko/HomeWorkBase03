#include <iostream>

struct DoubleList 
{
	int data{};
	DoubleList* next; 
	DoubleList* prev; 
};
DoubleList* head; 

void AddList(int value, int position)
{
	DoubleList* node = new DoubleList; 
	node->data = value; 
	if (head == NULL) 
	{
		node->next = node; 
		node->prev = node; 
		head = node; 
	}
	else
	{
		DoubleList* p = head;
		for (int i = position; i > 1; i--) p = p->next;
		p->prev->next = node;
		node->prev = p->prev;
		node->next = p;
		p->prev = node;
	}
	std::cout << "\nThe element was added\n";
}

int DeleteList(int position)
{
	if (head == NULL) {
		std::cout << "\nList is empty\n"; return 0;
	}
	if (head == head->next)
	{
		delete head;
		head = NULL;
	}
	else
	{
		DoubleList* a = head;
		for (int i = position; i > 1; i--) a = a->next;
		if (a == head) head = a->next;
		a->prev->next = a->next;
		a->next->prev = a->prev;
		delete a;
	}
	std::cout << "\nThe element was deleted\n";
}

void PrintList()
{
	if (head == NULL) {
		std::cout << "\nList is empty\n";
	}
	else
	{
		DoubleList* a = head;
		std::cout << "\nList elements:";
		do
		{
			std::cout << a->data << " ";
			a = a->next;
		} while (a != head); 
		std::cout << "\n\n";
	}
}

int main()
{
	int value, position, number;
	while(true)
	{
		std::cout << "1. Add the element" <<std:: endl;
		std::cout << "2. Delete the element" << std::endl;
		std::cout << "3. Display list" <<std:: endl;
		std::cout << "0. Exit" <<std:: endl;
		std::cout << "\nCommand number";
		std::cin >> number;
		switch (number)
		{
		case 1:
			std::cout << "Value = > ";
			std::cin >> value;
			std::cout << "Position = > "; 
			std::cin >> position;
			AddList(value, position); 
			break;
		case 2:
			std::cout << "Position =  ";
			std::cin >> position;
			DeleteList(position); 
			break;
		case 3: PrintList();
			break;
		}
	} 
	return 0;
}

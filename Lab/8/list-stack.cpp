#include "list-stack.h"
#include <string>

node::~node()
{
	delete next;
}

list_stack::~list_stack()
{
	delete head;
}

list_stack::list_stack(const list_stack &l)
{
	*this = l;
}

list_stack& list_stack::operator=(const list_stack &l)
{
	node* tempN = l.head;
	while (tempN != nullptr)
	{
		(*this).push(tempN->data);
		tempN = tempN->next;
	}
	return *this;
}

void list_stack::push(char c)
{
	if (is_empty())
	{
		head = new node(c);
		tail = head;
	}
	else
	{
		tail->next = new node(c, tail);
		tail = tail->next;
	}
}

char list_stack::pop()
{
	char tempC;
	if (tail->previous == nullptr)
	{
		char tempC = tail->data;
		delete tail;
		head = tail = nullptr;
	}
	else
	{
		tail = tail->previous;
		tempC = tail->next->data;
		delete tail->next;
		tail->next = nullptr;
	}
	return tempC;
}

bool list_stack::is_empty() const
{
	return head == nullptr ? true : false;
}
#include "vector-stack.h"

void vector_stack::push(char c)
{
	data.push_back(c);
}

char vector_stack::pop()
{
	char temp = data[data.size() - 1];
	data.pop_back();
	return temp;
}

bool vector_stack::is_empty() const { return data.empty(); }
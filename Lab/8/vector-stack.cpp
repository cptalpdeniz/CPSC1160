/*
* Assignment 8
* Author: Alp Deniz Senyurt
* Student ID: 100342433
* Self explanatory variables and parameters will not be commented as they are, "self-explanatory".
*/

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
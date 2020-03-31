/*
* Assignment 8
* Author: Alp Deniz Senyurt
* Student ID: 100342433
* Self explanatory variables and parameters will not be commented as they are, "self-explanatory".
*/

#ifndef VECTOR_STACK_H
#define VECTOR_STACK_H 

#include <vector>

class vector_stack
{
	std::vector<char> data;
public:
	vector_stack() : data(0) { };
	void push(char);
	char pop();
	bool is_empty() const;
};

#endif
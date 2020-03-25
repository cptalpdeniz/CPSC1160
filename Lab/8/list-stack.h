/*
* Assignment 8
* Author: Alp Deniz Senyurt
* Student ID: 100342433
* Self explanatory variables and parameters will not be commented as they are, "self-explanatory".
*/

#ifndef LIST_STACK_H
#define LIST_STACK_H 

#include <string>

class node
{
	char data;
	node* previous;
	node* next;
	friend class list_stack;
public:
	node(char data, node* p = nullptr, node* n = nullptr) : data(data), previous(p), next(n) {}
	~node();
};


class list_stack
{
	node* head;
	node* tail;
public:
	list_stack() : head(nullptr), tail(head) { }

	~list_stack();
	list_stack(const list_stack&);
	list_stack& operator=(const list_stack &);

	void push(char);
	char pop();
	bool is_empty() const;
};

#endif
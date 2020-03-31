#include "list.h"

template <class T> node<T>::node(node<T> const &n)
{
	(*this) = n;
}

template <class T> node<T> &node<T>::operator=(node const &n)
{
	data = n.data;
	return (*this);
}


template <class T> list<T>::list(const list& l)
{
	(*this) = l;
}

template <class T> list<T>& list<T>::operator=(const list &l)
{
	delete head;
	head = new node<T>(l.head->data, nullptr, nullptr);
	tail = head;
	l.head = l.head->next;
	while (l.head)
	{
		tail->next = new node<T>(l.head->data, nullptr, tail);
		tail = tail->next;
		l.head = l.head->next;
	}
	return (*this);
}

template <class T> list<T>& list<T>::operator+=(const T d)
{
	if (!tail)
	{
		head = new node<T>(d, nullptr, nullptr);
		tail = head;
	}
	else
	{
		tail->next = new node<T>(d, tail, nullptr);
		tail = tail->next;
	}
	return (*this);
}

//Note for self
//set the next to nullptr then delete so rest of the list doesn't get deleted
template <class T> list<T>& list<T>::operator-=(const T d)
{
	node<T>* temp = head;
	while (temp)
	{
		if (temp->data == d)
		{
			temp->previous->next = temp->next;
			temp->next->previous = temp->previous;
			delete temp;
		}
		else
		{
			temp = temp->next;
			continue;
		}
	}
	return (*this);
}

template <class T> T list<T>::biggest() const
{
	if (!head)
		return nullptr;
	else
	{
		node<T>* temp = head;
		T max = temp->data;
		while(temp->next)
		{
			if (temp->data > max)
				max = temp->data;
			else
				temp = temp->next;
		}
		return max;
	}
}

template class node<long long>;
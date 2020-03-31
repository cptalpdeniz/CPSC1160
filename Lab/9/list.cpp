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
	node<T> *temp = l.head;
	delete head;
	head = new node<T>(temp->data, nullptr, nullptr);
	tail = head;
	temp = temp->next;
	while (temp)
	{
		tail->next = new node<T>(temp->data, nullptr, tail);
		tail = tail->next;
		temp = temp->next;
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
		return 0;
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
template class list<long long>;
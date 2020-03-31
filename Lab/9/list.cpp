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

template<class T> node<T>& node<T>::operator+=(const T d)
{
	this->next = new node<T>(d, this, nullptr);
	return (*this->next);
}

template<class T> node<T>& node<T>::operator-=(const T d)
{
	node<T>* temp = this;
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

template <class T> T node<T>::biggest()
{
	if (!next)
		return biggest();
	T var = next->biggest();
	return (data < var) ? data : var;
}

// LIST implementation

template <class T> list<T>::list(const list& l)
{
	(*this) = l;
}

template <class T> list<T> &list<T>::operator=(const list<T> &l)
{ 
	delete head; 
	delete tail; 
	head = new node<T>(*l.head); 
	tail = head; 
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
		tail = tail += d;
	}
	return (*this);
}

//Note for self
//set the next to nullptr then delete so rest of the list doesn't get deleted
template <class T> list<T>& list<T>::operator-=(const T d)
{
	head = head -= d;
	return (*this);
}

template <class T> T list<T>::biggest() const
{
	return head->biggest();
}

template class node<long long>;
template class list<long long>;
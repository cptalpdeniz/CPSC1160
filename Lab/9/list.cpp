#include "list.h"

template <class T, class V> node<T, V>::~node()
{  
	if (!next)
		delete next; 
}

template <class T, class V> node<T, V>::node(node<T, V> const &n)
{
	(*this) = n;
}

template <class T, class V> node<T, V> &node<T, V>::operator=(node const &n)
{
	data = n.data;
	return (*this);
}

template<class T, class V> node<T, V>& node<T, V>::operator+=(const T d)
{
	this->next = new node<T, V>(d, this, nullptr);
	return  *(this->next);
}

template<class T, class V> node<T, V>& node<T, V>::operator-=(const T d)
{
	node<T, V>* temp = this;
	while (temp)
	{
		if (temp->data == d)
		{	
			if (temp->previous && !(temp->next))
			{
				temp->previous->next = nullptr;
				temp->previous = nullptr;
				delete temp;
				break;
			}
			else if (temp->previous)
			{
				temp->previous->next = temp->next;
				temp->next->previous = temp->previous;
				temp->next = nullptr;
				temp->previous = nullptr;
				delete temp;
				break;
			}
			else
			{
				temp = this->next;
				this->next = nullptr;
				delete this;
				temp->previous = nullptr;
				return (*temp);
			}
		}
		else
		{
			temp = temp->next;
			continue;
		}
	}
	return (*this);
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
	head = new node<T, list<T>>(*l.head); 
	tail = head; 
	return (*this); 
}

template <class T> list<T>& list<T>::operator+=(const T d)
{
	if (!tail)
	{
		head = new node<T, list<T>>(d, nullptr, nullptr);
		tail = head;
	}
	else
	{
		tail = &(*tail += d);
	}
	return (*this);
}

//Note for self
//set the next to nullptr then delete so rest of the list doesn't get deleted
template <class T> list<T>& list<T>::operator-=(const T d)
{
	head = &(*head -= d);
	if (!tail)
	{
		tail = head;
		while (tail->next)
		{
			tail = tail->next;
		}
	}
	return (*this);
}

template <class T> T list<T>::biggest() const
{
	if (!head)
		return 0;
	node<T, list<T>>* temp = head;
	T TVar = temp->data;
	while (temp)
	{
		if (temp->data > TVar)
			TVar = temp->data;
		temp = temp->next;
	}
	return TVar;
}

template class node<long long, list <long long>> ;
template class list<long long>;
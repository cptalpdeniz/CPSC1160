#include "tree.h"

template <class T> node<T>::node(node<T> const &n) : data(n.data) 
	{
		left = n.left ? new	node(*n.left) : nullptr;
		right = n.right ? new node(*n.right) : nullptr;
	}

//find the minimum value in the subtree
template <class T> node<T>* node<T>::findMinnode(const node<T> &node) const
{
	T max = node->data;
	while (node->left)
	{
		node = node->left;
	}
	return node;
}

//find the maximum value in the subtree
template <class T> node<T>* node<T>::findMaxnode(const node<T> &node) const
{
	T max = node->data;
	while (node->right)
	{
		node = node->right;
	}
	return node;
}


template <class T> node<T> &node<T>::operator=(node const &n) 
{
	delete left;
	delete right;
	data = n.data;
	left = n.left ? new node(*n.left) : nullptr;
	right = n.right ? new node(*n.right) : nullptr;
	return (*this);
}

template <class T> node<T> &node<T>::operator+=(const T value)
{
	node<T> **side = value < data ? &left: &right;
	if (*side)
		**side += value;
	else
		*side = new node<T>(value);
	return (*this);
}

template<class T> node<T>* node<T>::operator-=(const T d)
{
	if (d < data && left)
	{
		left = *left -= d;
		return this;
	}
	else if (d > data && right)
	{
		right = *right -= d;
		return this;
	}
	if (d == data && !(left) && !(right))
	{
		delete this;
		return nullptr;
	}
	else if (d == data && left && !(right))
	{
		const node<T> *temp = left;
		left = nullptr;
		*this = *temp;
		temp->left = nullptr;
		temp->right = nullptr;
		delete temp;
		return this;
	}
	else if (d == data && !(left) && right)
	{
		const node<T> *temp = right;
		right = nullptr;
		*this = *temp;
		temp->left = nullptr;
		temp->right = nullptr;
		delete temp;
		return this;
	}
	else if (d == data && left && right)
	{
		node<T> *temp;
		if ((d - this->left->data) < (this->right->data - d))
		{
			temp = findMaxnode(temp->left);
			data = temp->data;
			right = (*right) -= d;
		}
		else
		{
			temp = findMinnode(temp->right)
			data = temp->data;
			left = (*left) -= d;
		}
	}
	else
	{
		return this;
	}
}


template <class T> tree<T> &tree<T>::operator+=(const T d)
{
	if (root)
		*root += d;
	else
		root = new node<T>(d);
	return (*this);
}


// NOTE TO SELF FOR OPTIMIZATION
//count subtrees by finding the difference between the node data and right node->data and left node->data
//depending on the difference, get max in left, else, get min in right

template <class T> tree<T> &tree<T>::operator-=(const T d)
{
	root = *root -= d;
	return (*this);
	/*
	Another implementation with m_delete(const Node<T> n, const T d) which deletes the node recursively.
		if (!root)
			return n;
		else if (d < n->data && left)
			n->left = m_delete(n->left, d);
		else if (d > n->data && right)
			n->right = m_delete(n->right, d);
		else
		{
			if (!(n->left) && !(n->right))
			{
				delete n;
				n = nullptr;
			}
			else if (root->left == nullptr)
			{
				node<T> *temp = n;
				n = n->right;
				delete temp;
			}
			else if (root->right == nullptr)
			{
				node<T> *temp = n;
				n = n->left;
				delete temp;
			}
			else
			{
				node<T> *temp;
				if ((d - temp->left->data) < (temp->right->data - d))
					temp = findMaxnode(temp->right);
				else
					temp = findMinnode(temp->left);
				n->data = temp->data;
				n->right = m_delete(n->right, temp->data);
			}
		}
		return n;
	*/

	/*
	This is the first code that I've written. However, after spending some time, I've added another implemention which is cleaner and deletes recursively. But does it using another function.

	if (!root)
		return (*this);

	node<T> *temp = root->data < value ? root->right : root->left;
	node<T> *parentnode = temp;
	while (value != temp->data)
	{
		if (temp->left == nullptr && temp->right == nullptr)
		{
			return (*this);
		}
		if (value < temp->data)
		{
			if (! temp->left)
				return (*this);
			else
			{
				parentnode = temp;
				temp = temp->left;
			}
		}
		else if (value > temp->data)
		{
			if (! temp->right)
				return (*this);
			else
			{
				parentnode = temp;
				temp = temp->right;
			}
		}
	}

	if (temp->left == nullptr && temp->right == nullptr)
	{
		delete temp;
	}	
	else if (temp->left == nullptr && temp->right)
	{
		if (temp->data >= parentnode->data)
			parentnode->right = temp->right;
		else
			parentnode->left = temp->right;
	}
	else if (temp->right == nullptr && temp->left)
	{
		if (temp->data >= parentnode->data)
			parentnode->right = temp->right;
		else
			parentnode->left = temp->right;
	}
	else
	{
		node<T> *replacement;
		if ((value - temp->left->data) < (temp->right->data - value))
			replacement = findMaxnode(temp->right);
		else
			replacement = findMinnode(temp->left);
		temp->data = replacement->data;
		delete replacement;
	}

	*/
}

template <class T> T tree<T>::biggest() const
{
	node<T> *temp = root;
	T max = root->data;
	while (temp->right)
	{
		temp = temp->right;
	}
	return temp->data;
}

template class node<long long>;
template class tree<long long>;
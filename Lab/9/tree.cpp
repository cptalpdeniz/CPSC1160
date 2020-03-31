#include "tree.h"

template <class T> Node<T>::Node(Node<T> const &n) : data(n.data) 
	{
		left = n.left ? new	Node(*n.left) : nullptr;
		right = n.right ? new Node(*n.right) : nullptr;
	}

template <class T> Node<T> &Node<T>::operator=(Node const &n) 
{
	delete left;
	delete right;
	data = n.data;
	left = n.left ? new Node(*n.left) : nullptr;
	right = n.right ? new Node(*n.right) : nullptr;
	return (*this);
}

template <class T> Node<T> &Node<T>::operator+=(const T value)
{
	Node<T> **side = value < data ? &left: &right;
	if (*side)
		**side += value;
	else
		*side = new Node<T>(value);
	return (*this);
}

template <class T> Tree<T> &Tree<T>::operator+=(const T value)
{
	if (root)
		*root += value;
	else
		root = new Node<T>(value);
	return (*this);
}

//find the minimum value in the subTree
template <class T> Node<T>* Tree<T>::findMinNode(const Node<T> &node) const
{
	T max = node->data;
	while (node->left)
	{
		node = node->left;
	}
	return node ;
}

template <class T> Node<T>* Tree<T>::findMaxNode(const Node<T> &node) const
{
	T max = node->data;
	while (node->right)
	{
		node = node->right;
	}
	return node;
}

//count subtrees by finding the difference between the node data and right node->data and left node->data
//if right side has smaller amount of subtrees, get max in left, else, get min in right

template <class T> Node<T> Tree<T>::m_delete(const Node<T> &n, const T d)
{
	if (!root)
		return n;
	else if (d < n->data)
		n->left = m_delete(n->left, d);
	else if (d > n->data)
		n->right = m_delete(n->right, d);
	else
	{
		if (n->left == nullptr && n->right == nullptr)
		{
			delete n;
			n = nullptr;
		}
		else if (root->left == nullptr)
		{
			Node<T> *temp = n;
			n = n->right;
			delete temp;
		}
		else if (root->right == nullptr)
		{
			Node<T> *temp = n;
			n = n->left;
			delete temp;
		}
		else 
		{
			Node<T> *temp;
			if ((d - temp->left->data) < (temp->right->data - d))
				temp = findMaxNode(temp->right);
			else
				temp = findMinNode(temp->left);
			n->data = temp->data;
			n->right = m_delete(n->right, temp->data);
		}
	}
	return n;
}

// can be rewritten, pretty inefficient however no time due to finals.
template <class T> Tree<T> &Tree<T>::operator-=(const T value)
{
	root = m_delete(root,value);
	return (*this);

	/*
	This is the first code that I've written. However, after spending some time, I've added another implemention which is cleaner and deletes recursively. 

	if (!root)
		return (*this);

	Node<T> *temp = root->data < value ? root->right : root->left;
	Node<T> *parentNode = temp;
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
				parentNode = temp;
				temp = temp->left;
			}
		}
		else if (value > temp->data)
		{
			if (! temp->right)
				return (*this);
			else
			{
				parentNode = temp;
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
		if (temp->data >= parentNode->data)
			parentNode->right = temp->right;
		else
			parentNode->left = temp->right;
	}
	else if (temp->right == nullptr && temp->left)
	{
		if (temp->data >= parentNode->data)
			parentNode->right = temp->right;
		else
			parentNode->left = temp->right;
	}
	else
	{
		Node<T> *replacement;
		if ((value - temp->left->data) < (temp->right->data - value))
			replacement = findMaxNode(temp->right);
		else
			replacement = findMinNode(temp->left);
		temp->data = replacement->data;
		delete replacement;
	}

	*/
}

template <class T> T Tree<T>::biggest() const
{
	Node<T> *temp = root;
	T max = root->data;
	while (temp->right)
	{
		temp = temp->right;
	}
	return temp->data;
}

template class Node<long long>;
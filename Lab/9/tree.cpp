#include "tree.h"

template <class T> Node<T>::Node(Node<T> const &n) : data(n.data) 
	{
		left = n.left ? new	Node(*n.left) : nullptr;
		right = n.right ? new Node(*n.right) : nullptr;
	}

//find the minimum value in the subtree
template <class T> Node<T>* Node<T>::findMinNode(Node<T> *n) const
{
	while (n->left)
	{
		n = n->left;
	}
	return n;
}

//find the maximum value in the subtree
template <class T> Node<T>* Node<T>::findMaxNode(Node<T> *n) const
{
	while (n->right)
	{
		n = n->right;
	}
	return n;
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

template<class T> Node<T>* Node<T>::operator-=(const T d)
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
		Node<T> *temp = left;
		left = nullptr;
		*this = *temp;
		temp->left = nullptr;
		temp->right = nullptr;
		delete temp;
		return this;
	}
	else if (d == data && !(left) && right)
	{
		Node<T> *temp = right;
		right = nullptr;
		*this = *temp;
		temp->left = nullptr;
		temp->right = nullptr;
		delete temp;
		return this;
	}
	else if (d == data && left && right)
	{
		Node<T> *temp = this;
		if ((d - temp->left->data) < (temp->right->data - d))
		{
			temp = findMaxNode(temp->left);
			data = temp->data;
			right = (*right) -= d;
		}
		else
		{
			temp = findMinNode(temp->right);
			data = temp->data;
			left = (*left) -= d;
		}
	}
	else
	{
		return this;
	}
}

template <class T> T Node<T>::biggest() const
{
	const Node<T> *temp = this;
	T max = temp->data;
	while (temp->right)
	{
		temp = temp->right;
	}
	return (temp->data);
}


/*
	Tree implementation
*/

template <class T> tree<T> &tree<T>::operator+=(const T d)
{
	if (root)
		*root += d;
	else
		root = new Node<T>(d);
	return (*this);
}


// NOTE TO SELF FOR OPTIMIZATION
//count subtrees by finding the difference between the Node data and right Node->data and left Node->data
//depending on the difference, get max in left, else, get min in right

template <class T> tree<T> &tree<T>::operator-=(const T d)
{
	root = *root -= d;
	return (*this);
	/*
	Another implementation with m_delete(const Node<T> n, const T d) which deletes the Node recursively.
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
	*/

	/*
	This is the first code that I've written. However, after spending some time, I've added another implemention which is cleaner and deletes recursively. But does it using another function.

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

template <class T> T tree<T>::biggest() const
{
	return root->biggest();
}

template class Node<long long>;
template class tree<long long>;
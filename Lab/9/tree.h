#ifndef TREE_H
#define TREE_H 

template <class T> class Node
{
	T data;
	Node<T> *left, *right;
public:
	Node(T data = 0, Node<T>* l = nullptr, Node<T>* r = nullptr) : data(data), left(l), right(r) { }

	~Node() { delete left; delete right; }
	Node(Node<T> const &);
	Node<T> &operator=(Node const &);
	Node<T> &operator+=(const T);
	Node<T> m_delete(const Node<T> &, const T);
};

template <class T> class Tree
{
	Node<T> *root;
	Node<T> *findMaxNode(const Node<T> &) const;
	Node<T> *findMinNode(const Node<T> &) const;
	Node<T> m_delete(const Node<T> &, const T);
public:
	Tree() : root(nullptr) { }

	~Tree() { delete root; }
	Tree(const Tree& t) : root(t.root) { }
	Tree &operator=(const Tree &t) { delete root; root = new Node<T>(*t.root); }

	Tree &operator+=(const T);
	Tree &operator-=(const T);

	T biggest() const;
};

#endif
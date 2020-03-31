#ifndef tree_H
#define tree_H 

template <class T> class Node
{
	T data;
	Node<T> *left, *right;
	Node<T>* findMaxNode(Node<T> *) const;
	Node<T>* findMinNode(Node<T> *) const;
public:
	Node(T data = 0, Node<T>* l = nullptr, Node<T>* r = nullptr) : data(data), left(l), right(r) { }

	~Node() { delete left; delete right; }
	Node(Node<T> const &);
	Node<T> &operator=(Node const &);

	Node<T> &operator+=(const T);
	Node<T> *operator-=(const T);
};

template <class T> class tree
{
	Node<T> *root;
public:
	tree() : root(nullptr) { }

	~tree() { delete root; }
	tree(const tree& t) : root(t.root) { }
	tree &operator=(const tree &t) { delete root; root = new Node<T>(*t.root); }

	tree &operator+=(const T);
	tree &operator-=(const T);

	T biggest() const;
};

#endif
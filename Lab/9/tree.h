#ifndef tree_H
#define tree_H 

template <class T> class node
{
	T data;
	node<T> *left, *right;
	node<T> *findMaxnode(const node<T> &) const;
	node<T> *findMinnode(const node<T> &) const;
public:
	node(T data = 0, node<T>* l = nullptr, node<T>* r = nullptr) : data(data), left(l), right(r) { }

	~node() { delete left; delete right; }
	node(node<T> const &);
	node<T> &operator=(node const &);
	node<T> &operator+=(const T);
	node<T> *operator-=(const T);
};

template <class T> class tree
{
	node<T> *root;
public:
	tree() : root(nullptr) { }

	~tree() { delete root; }
	tree(const tree& t) : root(t.root) { }
	tree &operator=(const tree &t) { delete root; root = new node<T>(*t.root); }

	tree &operator+=(const T);
	tree &operator-=(const T);

	T biggest() const;
};

#endif
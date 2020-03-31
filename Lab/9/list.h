#ifndef LIST_H
#define LIST_H 

template <class T> class node
{
	T data;
	node<T> *previous, *next;
public:
	node(T data = 0, node<T>* p = nullptr, node<T>* n = nullptr) : data(data), previous(p), next(n) { }
	~node() { delete previous; delete next; }

	//still can't understand why we need these in linked list?
	node(node<T> const &);
	node<T> &operator=(node const &);
};

template <class T> class list
{
	node<T>* head;
	node<T>* tail;
	node<T>* valueFind(T) const;

public:
	list() : head(nullptr), tail(nullptr) { }
	
	~list() { delete head; delete tail; }
	list(const list&);
	list &operator=(const list &);

	list &operator+=(const T);
	list &operator-=(const T);

	T biggest() const;

};


#endif
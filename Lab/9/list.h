#ifndef LIST_H
#define LIST_H 

template <class T> class node
{
	T data;
	node<T> *previous, *next;
public:
	node(T data = 0, node<T>* p = nullptr, node<T>* n = nullptr) : data(data), previous(p), next(n) { }
	~node() { delete previous; delete next; }

	node(node<T> const &);
	node<T> &operator=(node const &);
	node<T> &operator+=(const T);
	node<T> &operator-=(const T);

	T biggest();
};

template <class T> class list
{
	node<T>* head;
	node<T>* tail;

public:
	list() : head(nullptr), tail(nullptr) { }
	
	~list() { delete head; delete tail; }
	list(const list<T> &);
	list &operator=(const list<T> &);

	list &operator+=(const T);
	list &operator-=(const T);

	T biggest() const;

};


#endif
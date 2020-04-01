#ifndef LIST_H
#define LIST_H 

template <class T, class V> class node
{
	T data;
	node<T, V> *previous, *next;
	friend V;
public:
	node(T data = 0, node<T, V>* p = nullptr, node<T, V>* n = nullptr) : data(data), previous(p), next(n) { }
	~node();

	node(node<T, V> const &);
	node<T, V> &operator=(node const &);
	node<T, V> &operator+=(const T);
	node<T, V> &operator-=(const T);

};

template <class T> class list
{
	node<T, list<T>>* head;
	node<T, list<T>>* tail;

public:
	list() : head(nullptr), tail(nullptr) { }
	
	~list() { delete head; }
	list(const list<T> &);
	list &operator=(const list<T> &);

	list &operator+=(const T);
	list &operator-=(const T);

	T biggest() const;

};


#endif
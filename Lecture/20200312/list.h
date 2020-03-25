#include <iostream>

class node {
    int data;
    node *next, *prev;
public:
    node(int d, node *n=nullptr, node *p=nullptr) : data(d), next(n), prev(p) {}
    ~node() { delete next; }
    friend class list;
    friend std::ostream &operator<<(std::ostream &out, node const *n) {
        if (!n) {
            return out;
        } else {
            return out << n->data << " " << n->next;
        }
    }
};

class list {
    node *head, *tail;
public:
    list() : head(nullptr), tail(nullptr) {}
    ~list() { delete head; }
    void add_to_beginning(int d) {
        node *new_node = new node(d, head);
        if (head)   head->prev = new_node;
        head = new_node;
        if (!tail)  tail = head;
    }
    void add_to_end(int d) {
        if (!head)  add_to_beginning(d);
        else {
            node *new_node = new node(d, nullptr, tail);
            tail->next = new_node;
            tail = new_node;
        }
    }
    void remove_from_beginning() {
        if (head->next) {
            head = head->next;
            head->prev->next = nullptr;
            delete head->prev;
            head->prev = nullptr;
        } else {
            delete head;
            head = tail = nullptr;
        }
    }
    void remove_from_end() {
        if (head->next) {
            tail = tail->prev;
            delete tail->next;
            tail->next = nullptr;
        } else {
            delete head;
            head = tail = nullptr;
        }
    }
    friend std::ostream &operator<<(std::ostream &out, list const &l) {
        return out << l.head;
    }
};
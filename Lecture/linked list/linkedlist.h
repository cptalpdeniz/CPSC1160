class node {
    int data;
    node *next;
public:
    node(int d, node *n=nullptr) : data(d), next(n) {}
    ~node();
    int count() const;
    friend class list;
};

class list {
    node *head;
public:
    list() : head(nullptr) {}
    ~list();
    void insert_at_head(int);
    int remove_from_head();
    int count() const;
};
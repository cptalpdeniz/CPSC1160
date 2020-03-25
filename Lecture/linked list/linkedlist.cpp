#include "linkedlist.h"

void list::insert_at_head(int new_data) {
    head = new node(new_data, head);
}

int list::remove_from_head() {
    node * const old_head = head;
    int old_data = old_head->data;
    head = head->next;
    old_head->next = nullptr;
    delete old_head;
    return old_data;
}

int list::count() const {
    return head ? head->count() : 0;
}

int node::count() const {
    if (next == nullptr) {
        return 1;
    } else {
        return 1 + next->count();
    }
}

list::~list() {
    delete head;
}

node::~node() {
    delete next;
}

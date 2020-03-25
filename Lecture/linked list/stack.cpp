#include <iostream>
#include <vector>

using namespace std;

enum class pancake { smooth, lumpy, buttered, blueberry };

template <class THING> class stack {
    THING *things;
    size_t num_things;
    size_t capacity;
public:
    stack() : things(nullptr), num_things(0), capacity(0) {}
    stack(stack<THING> const &o)
            : things(new THING[o.num_things]), num_things(o.num_things), capacity(num_things)
    {
        for (size_t i = 0; i < num_things; i++) {
            things[i] = o.things[i];
        }
    }
    stack<THING> &operator=(stack<THING> const &o) {
        delete [] things;
        things = new THING[num_things = capacity = o.num_things];
        for (size_t i = 0; i < num_things; i++) {
            things[i] = o.things[i];
        }
        return *this;
    }
    ~stack() { delete [] things; }
    
    void push(THING t) {
        if (num_things >= capacity) {
            THING *new_arr = new THING[capacity = (num_things + 1)];
            for (size_t i = 0; i < num_things; i++) {
                new_arr[i] = things[i];
            }
            delete [] things;
            things = new_arr;
        }
        things[num_things++] = t;
    }
    THING pop() {
        return things[--num_things];
    }
};

int main()
{
    stack<pancake> pancakes;
    pancakes.push(pancake::smooth);
    pancakes.push(pancake::blueberry);
    cout << (int)pancakes.pop() << endl;
    return 0;
}

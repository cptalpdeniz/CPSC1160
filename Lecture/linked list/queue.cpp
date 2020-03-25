#include <iostream>
#include <vector>

using namespace std;

enum class pancake { smooth, lumpy, buttered, blueberry };

template <class THING> class queue {
    vector<THING> things;
public:
    queue() : things() {}
    void enqueue(THING t) { things.push_back(t); }
    THING dequeue() {
        THING first = things[0];
        things.erase(things.begin());
        return first;
    }
};

int main()
{
    queue<pancake> ps;
    ps.enqueue(pancake::smooth);
    ps.enqueue(pancake::blueberry);
    cout << (int)ps.dequeue() << endl;
    return 0;
}

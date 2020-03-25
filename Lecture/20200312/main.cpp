#include <iostream>
#include "list.h"

using namespace std;

int main()
{
    list l;
    l.add_to_end(2);
    l.add_to_beginning(4);
    l.add_to_end(6);
    l.add_to_beginning(8);
    l.remove_from_beginning();
    l.remove_from_end();
    cout << l << endl;
    return 0;
}

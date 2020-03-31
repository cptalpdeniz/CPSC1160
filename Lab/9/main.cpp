#include "list.h"	// you should make a List.h for a linked-List implementation
#include "tree.h"	// you should make a Tree.h for a BST implementation
#include <iostream>
#include <chrono>

/*
 * Include one of the following 3 include-lines for testing. You
 * should probably start with the smallest one
 */
//#include "100000-50000.h"
//#include "10000-5000.h"
//#include "1000-500.h"
#include "10-5.h"

static unsigned long long current_millis()
{
	// code stolen from https://stackoverflow.com/a/56107709
	using namespace std::chrono;
	return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}

template <class T> static void time_data_structure()
{
	unsigned long long const start = current_millis();
	T d;
	for (size_t i = 0; i < sizeof to_add / sizeof to_add[0]; i++) {
		d += to_add[i];
	}
	for (size_t i = 0; i < sizeof to_subtract / sizeof to_subtract[0]; i++) {
		d -= to_subtract[i];
	}
	std::cout << d.biggest();
	unsigned long long const end = current_millis();
	std::cout << " (finished in " << (end - start) << "ms)" << std::endl;
}

int main()
{
	std::cout << "Tree: ";
	time_data_structure<Tree<long long>>();
	std::cout << "List: ";
	time_data_structure<list<long long>>();
	return 0;
}

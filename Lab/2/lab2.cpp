#include <iostream>
#include "functions.h"

int main()
{
	int k;
	do
	{
		std::cin.clear();
		std::cout << "Please write a positive integer number: ";
		std::cin >> k;
	} while (k < 0 && k > 12);
	int n = 1;
	std::cout << std::fixed;
	std::cout.precision(7);
	while (k <= 12 && n <= k)
	{
		std::cout << n << "\t" << prob(n, k) * 100 << std::endl;
		n++;
	}
	std::cout.flush();
	std::cin.clear();
}
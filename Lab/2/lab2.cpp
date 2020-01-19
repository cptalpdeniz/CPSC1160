#include <iostream>
#include <string>
#include "functions.h"

int main()
{
	std::string str;
	int k;
	do
	{
		std::cin.clear();
		std::cout << "Please write a positive integer number: ";
		std::cin >> str;
		k = strToInt(str);
	} while (k < 0 || k > 12 || !std::cin);
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
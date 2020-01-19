/*
* Assignment 2
* @author Alp Deniz Senyurt
* Student ID: 100342433
* Self explanatory variables and parameters will not be commented as they are, "self-explanatory".
*/

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
	} while (k == -1 || !std::cin);
	
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
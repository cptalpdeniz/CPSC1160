/*
*	ASSIGNMENT 1
*	CPSC1160
*	Alp Deniz Senyurt
*	100342433
*/


#include <iostream>

int main()
{
	std::cout << "Basic Fahrenheit to Celsius Converter" << std::endl;
	double n;
	std::cout << "Please write the fahrenheit: ";
	std::cin >> n;
	std::cout << std::endl;
	std::cout << "The result is: " << (n - 32) * 5 / 9 << std::endl;
	return 0;
}
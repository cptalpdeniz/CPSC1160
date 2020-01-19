#include "functions.h"
#include <cmath>
#include <string>

int fact(int n)
{
	int a = 1;

	for (int i = 1; i <= n; i++) 
	{
		a *= i;
	}
	return a;
}

double prob(int n, int k)
{
	return (1 - (fact(k)/(std::pow(k, n)*fact(k-n))));
}

int strToInt(std::string str) //-1 means conversion failed.
{
	if (str.empty() || str[0] == '\0' || str[0] == '-' || str.length() > 2)
		return -1;
	for (int i = str.length() -1; i < str.length(); ++i)
	{
		if (str[i] < '0' || str[i] > '9')
			return -1;
	}
	int result = std::stoi(str);
	if (result > 12)
		return -1;
	else
		return result;
}
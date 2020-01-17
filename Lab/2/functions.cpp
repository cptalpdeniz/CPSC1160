#include "functions.h"
#include <cmath>

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
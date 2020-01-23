/*
* Assignment 2
* @author Alp Deniz Senyurt
* Student ID: 100342433
* Self explanatory variables and parameters will not be commented as they are, "self-explanatory".
*/

#include "functions.h"
#include <cmath>
#include <string>

//factorial function
int fact(int n)
{
	int a = 1;

	for (int i = 1; i <= n; i++) 
	{
		a *= i;
	}
	return a;
}

//probability function
double prob(int n, int k)
{
	return (1 - (fact(k)/(std::pow(k, n)*fact(k-n))));
}

//I could have just used stoi however i wanted to have full control over whats returned and whats not so I wrote my own wrapper.
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
	if (result < 0 || result > 12)
		return -1;
	else
		return result;
}
#include <iostream>

static void change_value(int* x)
{
	(*x)++;
}

double* maximum_value(double* arr, size_t n)
{
	double* max = arr;
	for (int i = 1; i < n; ++i)
	{
		if (*max < arr[i])
			max = arr + i - 1;
		else
			continue;
	}
	return max;
}

int main()
{
	int x = 2;
/*	std::cout << x << std::endl;
	change_value(&x);
	std::cout << x << std::endl;*/

	double vals[] = { 7.5, 3e-6, 1.234e2, 117.555 };
	for (int i = 0; i < 4; ++i)
	{
		std::cout << vals[i] << std::endl;
	}
	double* max = maximum_value(vals, sizeof vals / sizeof vals[0]);
	std::cout << "The maximum is " << *max << std::endl;
}
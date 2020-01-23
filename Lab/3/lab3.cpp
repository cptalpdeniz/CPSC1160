#include <iostream>
#include <cmath>

const double calculateMean(const double* arr, const size_t n)
{
	double mean = arr[0];
	int count = 1;
	for (int i = 1; i < n; ++i)
	{
		if (!std::isnan(arr[i]))
		{
			mean += arr[i];
			count++;
		}
	}
	return mean / count;
}

double* maximum_value(double* arr, const size_t n)
{
	double* max = arr;
	for (int i = 1; i < n; ++i)
	{
		if (*max < arr[i])
			max = arr + i;
		else
			continue;
	}
	return max;
}

int main()
{
	std::cout << "Assingmnet 3\n" << std::endl;
	size_t n;

	//doesn't give error if the user inputs 10a or a10. FIX THIS
	do
	{
		std::cout << "How many times would you like to enter a temperature?" << std::endl;
		std::cin >> n;
		if (!std::cin)
		{
			std::cout << "ERROR! Wrong input. Please restart the program." << std::endl;
			return 1;
		}
		else
			continue;
	} while (!std::cin);
	std::cin.clear();

	double arr[n]; 
	for (int i = 0; i < n; ++i)
	{
		std::cout << "Please enter a number: ";
		std::cin >> arr[i];
		if (!std::cin)
		{
			arr[i] = std::nan("");
			std::cin.clear();
		}
	}

	double* max = maximum_value(arr, n);
	*max = std::nan("");

	double mean = calculateMean(arr, n);
	std::cout << "\n\nThe mean is : " << mean;

}
/*
* Assignment 6
* Author: Alp Deniz Senyurt
* Student ID: 100342433
* Self explanatory variables and parameters will not be commented as they are, "self-explanatory".
*/

#include <iostream>
#include "line.h"
#include "point.h"

int main()
{	
	std::cout << "Assignment 6\n" << std::endl;
	Line lineArr[3];
	Point p1, p2;
	for (int i = 0; i < 4; ++i)
	{
		std::cout << "Please enter the x1 coordinate of Line " << i+1 << ": ";
		std::cin >> p1.x;
		std::cout << "Please enter the y1 coordinate of Line " << i+1 << ": ";
		std::cin >> p1.y;
		std::cout << "Please enter the x2 coordinate of Line " << i+1 << ": ";
		std::cin >> p2.x;
		std::cout << "Please enter the y2 coordinate of Line " << i+1 << ": ";
		std::cin >> p2.y;
		lineArr[i] = Line(p1,p2);
		std::cout << std::endl;
	}

	std::cout << "Lines are: " << std::endl;
	for (int i = 0; i < 4; ++i)
	{
		std::cout << "- " << lineArr[i] << std::endl;
	}
	std::cout << std::endl;
	// [SLOPE] Test case 1
	std::cout << "Slope of Line 1: " << lineArr[0].slope() << std::endl;

	// [SLOPE] Test case 2
	std::cout << "Slope of Line 2: " << lineArr[1].slope() << std::endl;

	// [SLOPE] Test case 3
	std::cout << "Slope of Line 4: " << lineArr[3].slope() << std::endl << std::endl;

	// [INTERSECT] Test case 1
	Point p = lineArr[0].intersect_with(lineArr[1]);
	std::cout << "Intersect point between Line 1 and 2: (" <<  p.x << ", " << p.y << ")" << std::endl;

	// [INTERSECT] Test case 2
	p = lineArr[1].intersect_with(lineArr[2]);
	std::cout << "Intersect between Line 2 and 3: (" <<  p.x << ", " << p.y << ")" << std::endl;

	// [INTERSECT] Test case 3
	p = lineArr[3].intersect_with(lineArr[0]);
	std::cout << "Intersect between Line 4 and 1: (" <<  p.x << ", " << p.y << ")" << std::endl;
}
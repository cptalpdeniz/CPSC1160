/*
* Assignment 6
* Author: Alp Deniz Senyurt
* Student ID: 100342433
* Self explanatory variables and parameters will not be commented as they are, "self-explanatory".
*/

#include "point.h"
#include "line.h"
#include <cmath>
#include <iostream>

Line::Line()
{
	Point temp_P = {0, 0};
	point1 = point2 = temp_P;
}

double Line::slope() const
{
	return (point1.x == point2.x) ? std::nan("") : (point2.y - point1.y) / (point2.x - point1.x);
}

Point Line::intersect_with(Line const line) const
{
	double m1 = slope();
	double m2 = line.slope();
	Point p;
	if (m1 == m2)
	{
		p.x = std::nan("");
		p.y = std::nan("");
		return p;
	}
	else if (std::isnan(m1))
	{
		double b2 = point2.y - m2 * point2.x;
		p.x = b2 / m2;
		p.y = m2*point2.x + b2;
		return p;
	}
	else if (std::isnan(m2))
	{
		double b1 = point1.y - m1 * point1.x;
		p.x = b1 / m1;
		p.y = m1*point1.x + b1;
		return p;
	}
	else
	{
		double b1 = point1.y - m1*point1.x; 
		double b2 = line.point1.y - m2*line.point1.x;
		p.x = (b2 - b1) / (m2 - m1);
		p.y = m1 * point1.x + b1;
		return p;
	}
}

//this is just for testing and practising operator overloading of <<
std::ostream &operator<<(std::ostream &out, const Line &line)
{
	out << "Line passing through points: (" << line.point1.x << ", " << line.point1.y << ") and (" << line.point2.x << ", " << line.point2.y << ")";
	return out;
}
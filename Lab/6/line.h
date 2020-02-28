/*
* Assignment 6
* Author: Alp Deniz Senyurt
* Student ID: 100342433
* Self explanatory variables and parameters will not be commented as they are, "self-explanatory".
*/

#ifndef LINE_H
#define LINE_H

#include "point.h"
#include <iostream>

class Line {
	Point point1;
	Point point2;
public:
	Line();
	Line(Point p1, Point p2) : point1(p1), point2(p2) {}
	double slope() const;
	Point intersect_with(Line const) const;
	friend std::ostream &operator<<(std::ostream &, const Line &);
};

#endif
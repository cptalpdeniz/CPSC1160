/*
* Assignment 7
* Author: Alp Deniz Senyurt
* Student ID: 100342433
* Self explanatory variables and parameters will not be commented as they are, "self-explanatory".
*/

#ifndef SET_H
#define SET_H

/*
 * A 'set' as a collection of positive integers in which
 * order doesn't matter and duplicates are not considered.
 * We represent a 'set' as an array of booleans. If a number
 * is in the set, its position in the array will be true; if
 * it is not in the set, its position in the array will be
 * false.
 */

#include <iostream>

class set {
private:										//private by default...
	bool *elems;
	size_t num_elems;
public:
	set() { elems = new bool[0]; }
	set(size_t n);
	set(set const &s);
	~set();
	set &operator=(set const &s);					//assignment operator
	set &operator+=(set const &s);					//addition assignment operator
	set operator+(set const &s) const;				//addition operator
	set &operator-=(set const &s);					//subtraction assignment operator
	set operator-(set const &s) const;				//subtraction operator
	set &operator*=(set const &s);					//multiplication assignment operator
	set operator*(set const &s) const;				//multiplication operator
	set operator~() const;							//negation operator
	bool &operator[](size_t i);						//index operator
	friend std::ostream &operator<<(std::ostream &, set const &);					//left-shift operator overloading to print
};

#endif
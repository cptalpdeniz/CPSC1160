/*
* Assignment 7
* Author: Alp Deniz Senyurt
* Student ID: 100342433
* Self explanatory variables and parameters will not be commented as they are, "self-explanatory".
*/

#include "set.h"


set::set(size_t n)
		: elems(new bool(n)), num_elems(n)
{
	for (int i = 0; i < num_elems; ++i)
	{
		elems[i] = false;
	}
}

/*
* Copy constructor. Makes *this a copy of s
* 's' the set to copy
*/
set::set(set const &s)
		: elems(new bool(s.num_elems)),  num_elems(s.num_elems)
{
	*this = s;
}

/*
* Deallocates any dynamically-allocated memory
*/
set::~set()
{
	delete elems;
}

/*
* Assignment set::operator. Makes *this a copy of s
* 's' the set to copy
*/
set &set::operator=(set const &s)
{
	if (num_elems != s.num_elems)
	{
		delete elems;
		elems = new bool(s.num_elems);
	}
	for (int i = 0; i < s.num_elems; ++i)
	{
		elems[i] = s.elems[i];
	}
	return *this;
}

/*
* Mutates the current set by doing a set union
* with s. All numbers set in s will be added to
* this set.
* 's' the set to union with
*/
set &set::operator+=(set const &s)
{
	bool* new_arr = new bool[s.num_elems];
	for (int i = 0; i < s.num_elems; ++i)
	{
		if (elems[i] || s.elems[i])
		{
			new_arr[i] = 1;
		}
	}
	delete elems;
	elems = new_arr;
	num_elems = s.num_elems;
	return *this;
}

/*
* As +=, but constructs and returns a new set
*/
set set::operator+(set const &s) const
{
	set tempSet = *this;

	tempSet += s;
	return tempSet;
}

/*
* Mutates the current set by doing a set removal.
* All numbers set in s will be removed.
* 's' the set to do a removal with
*/
set &set::operator-=(set const &s)
{
	for (int i = 0; i < num_elems; ++i)
	{
		if (elems[i] && s.elems[i])
			elems[i] = false;
	}
	return *this;
}

/*
* As -=, but constructs and returns a new set
*/
set set::operator-(set const &s) const
{
	set tempSet = *this;			//using copy constructor to copy this to tempSet

	tempSet -= s;				//call overloaded -= 
	return tempSet;
}

/*
* Mutates the current set by doing a set
* intersection. All numbers not set in s will
* be removed.
* 's' the set to intersect with

SET INTERSECTION DEFINITION:
A = {1, 2, 3, 4, 5} and B = {3, 4, 5, 6, 7, 8}. To find the intersection of these two sets, we need to find out what elements they have in common. 
The numbers 3, 4, 5 are elements of both sets, therefore the intersections of A and B is {3. 4. 5].
*/
set &set::operator*=(set const &s)
{
	for (int i = 0; i < num_elems; ++i)
	{
		if (!(elems[i] &&  s.elems[i]))
			elems[i] = false;
	}
	return *this;
}

/*
* As *=, but constructs and returns a new set
*/
set set::operator*(set const &s) const
{
	set tempSet = *this;

	tempSet *= s;
	return tempSet;
}

/*
* Negates the set. All numbers set will become
* unset, and vice versa. Constructs and returns
* a new set.
*/
set set::operator~() const
{
	for (int i = 0; i < num_elems; ++i)
	{
		elems[i] = !elems[i];
	}
	return *this;
}

/*
* Returns a reference to the given number in the
* set.
* 'i' the number to return a reference to
*/
bool &set::operator[](size_t i)
{
	return elems[i];
}

std::ostream &operator<<(std::ostream &out, set const &s)
{
	out << " {" << s.elems[0];
	for (int i = 1; i < s.num_elems; ++i)
	{
		if (s.elems[i])
		{
			out << ", " << i;
		}
		else
			continue;
	}
	out << "}" << std::endl;
	return out;
}
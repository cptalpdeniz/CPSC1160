/*
* Midterm 2
* Author: Alp Deniz Senyurt
* Student ID: 100342433
* Self explanatory variables and parameters will not be commented as they are, "self-explanatory".
*/

#include "card.h"
#include <sstream>

int main()
{
	int total = 0, passed = 0;
// a macro to determine if two values are equal
#define EQ(x, y)	if ((x) != (y)) { \
						std::cerr << "line " << __LINE__ << ": " <<\
							#x << " == " << #y << " failed" << std::endl;\
						std::cerr << "line " << __LINE__ << ": " <<\
							"expected " << y << " but got " << x << std::endl;\
					} else	\
						passed++;	\
					total++;
// a macro to determine if printing out a value yields the correct result
#define EQS(x, y)	{ std::stringstream ss; ss << x; EQ(ss.str(), y); }
	card cs[] = {
		{ 4, colour::red },		// 0
		{ 3, colour::black },	// 1
		{ 4, colour::black },	// 2
		{ 5, colour::red },		// 3
		{ 2, colour::red },		// 4
		{ 2, colour::black },	// 5
	};

	EQS(cs[0], "4R");




	pile p(&cs[2], 2, &cs[0], 2);
	EQS(p, "[ 4B 5R ],[ 4R 3B ]");
	EQ(p.can_add_card(cs[5]), false);
	EQ(p.can_add_card(cs[4]), true);
	EQ(p.can_add_card(cs[2]), false);
	EQS(p + cs[4], "[ 4B 5R ],[ 4R 3B 2R ]");
	p += cs[4];
	EQS(p, "[ 4B 5R ],[ 4R 3B 2R ]");
	EQ(p.can_add_card(cs[4]), false);
	EQ(p.can_remove(), false);




	p = pile(&cs[2], 2, &cs[0], 1);
	EQ(p.can_remove(), true);
	card c = p.remove_top();
	EQ(c.value, 4);
	EQ((int)c.c, (int)colour::red);
	EQS(p, "[ 4B ],[ 5R ]");
	EQ(p.can_remove(), true);
	c = p.remove_top();
	EQ(c.value, 5);
	EQ((int)c.c, (int)colour::red);
	EQ(p.can_remove(), false);
	EQS(p, "[ ],[ 4B ]");


	std::cout << passed << " / " << total << " test cases passed" << std::endl;
	return 0;
}

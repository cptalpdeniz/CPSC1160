/*
*	Assignment 5
*	ALP DENIZ SENYURT
*	100342433
*/

#include <iostream>
#include <bitset>

//can be done using another method however using the 'for' loop and the following code makes sure that the most 4 bits (in a byte) are set to 0.
unsigned char pack(int x, int y)
{
	for (int i = 4; i < 8; ++i)
	{
		y &= ~(1 << i);
	}
	return (x << 4) | y;
}

void unpack(unsigned char const * ans, int* ans1, int* ans2)
{
	*ans2 = *ans1 = *ans;
	*ans1 >>= 4;

	for (int i = 4; i < 8; ++i)
	{
		*ans2 &= ~(1 << i);
	}
}

// This code is very garbaj. Works but can be improved tbh
// try to write this recursively later
unsigned char add_2_4bit_ints(unsigned char x, unsigned char y)
{
	unsigned char first = ((x >> 4) << 4);
	unsigned char second = ((y >> 4) << 4);
	unsigned char firstBits = first;


	while (second != 0)
	{
		int carry = first & second;
		first ^= second;
		second = carry << 1;
	}

	for (int i = 4; i < 8; ++i)
	{
		x &= ~(1 << i);
		y &= ~(1 << i);
	}

	while (y != 0)
	{
		int carry = x & y;

		x ^= y;
		y = carry << 1;
	}

	return pack((first >> 4), x);
}

//Can be done without calling the unpack function to optimize the code.
unsigned char div_2_4bit_int(unsigned char number)
{
	int first, second;
	unpack(&number, &first, &second);
	return pack(first / second, (first % second) * 8 / second);

}


int main()
{
	std::cout << "Assignment 5\n\nTest cases for add_2_4bit_ints() are as follows:\n(6,-2) + (1,7)\n(1,7) + (7,3)\n(7,3) + (6,-2)\n\n" << std::endl;
	//Addition test cases
	unsigned char t = pack(6, -2);
	unsigned char u = pack(1, 7);
	unsigned char v = pack(7, 3);
	int ans1, ans2;
	
	//Test case 1
	unsigned char ans = add_2_4bit_ints(t, u);
	unpack(&ans, &ans1, &ans2);
	std::cout << ans1 << ", " << ans2 << std::endl;
	
	//Test case 2
	ans = add_2_4bit_ints(u, v);
	unpack(&ans, &ans1, &ans2);
	std::cout << ans1 << ", " << ans2 << std::endl;
	
	//Test case 3
	ans = add_2_4bit_ints(v, t);
	unpack(&ans, &ans1, &ans2);
	std::cout << ans1 << ", " << ans2 << std::endl;

	//Division test cases
	std::cout << "\n\nTest cases for div_2_4bit_int() are as follows:\n(7,3)\n(6,4)\n(10,3)" << std::endl;
	unsigned char w = pack(7, 3);
	unsigned char x = pack(6, 4);
	unsigned char y = pack(10, 3);
	int integer_part, fractional_part;

	//Test case 1
	ans = div_2_4bit_int(w);
	unpack(&ans, &integer_part, &fractional_part);
	std::cout << integer_part << ", " << fractional_part << std::endl;
	
	//Test case 2
	ans = div_2_4bit_int(x);
	unpack(&ans, &integer_part, &fractional_part);
	std::cout << integer_part << ", " << fractional_part << std::endl;
	
	//Test case 3
	ans = div_2_4bit_int(y);
	unpack(&ans, &integer_part, &fractional_part);
	std::cout << integer_part << ", " << fractional_part << std::endl;
}
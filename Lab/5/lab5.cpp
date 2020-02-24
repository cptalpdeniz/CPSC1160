#include <iostream>
#include <cmath>
#include <bitset>

unsigned char pack(int x, int y)
{
	for (int i = 4; i < 8; ++i)
	{
		y &= ~(1 << i);
	}
	return (x << 4) | y;
}

// not sure if this is working, check it
void unpack(unsigned char const * ans, int* ans1, int* ans2)
{
	*ans1 = (*ans >> 4);
	*ans2 = 0;
	*ans2 |= (*ans << 4) >> 4;
}

// This code is very garbage. Works but can be improved tbh
// try to write this recursively later
unsigned char add_2_4bit_ints(unsigned char x, unsigned char y)
{
	unsigned char first = ((x >> 4) << 4);
	unsigned char second = ((y >> 4) << 4);
	unsigned char firstBits = first;

	while (second != 0)
	{
		int carry = first & second;

		firstBits ^= second;
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

	return pack((firstBits >> 4), x);
}

/*
unsigned char div_2_4bit_ints(unsigned char)
{

}
*/

int main()
{
	unsigned char x = pack(6, -2);
	//std::cout << std::bitset<8>(x) << std::endl;
	//std::cout << static_cast<unsigned>(x) << std::endl;
	unsigned char y = pack(1, 7);
	//std::cout << std::bitset<8>(y) << std::endl;
	unsigned char ans = add_2_4bit_ints(x, y);
	std::cout << "\nAnswer is: " << std::bitset<8>(ans) << std::endl;
	//int ans1, ans2;
	//unpack(ans, &ans1, &ans2);
	//std::cout << ans1 << endl << ans2 << std::endl;
}
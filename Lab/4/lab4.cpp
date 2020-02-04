/*
* Assignment 4
* Author Alp Deniz Senyurt
* Student ID: 100342433
* NOTE: Self explanatory variables and parameters will not be commented as they are, "self-explanatory".
*/

#include <iostream>

bool can_reach(int start_c, int start_r, int finish_c, int finish_r, int num_moves)
{
	if (start_c < 0 || start_c > 7 || start_r < 0 || start_r > 7)
		return false;
	if (num_moves == 0 && (start_c == finish_c && start_r == finish_r))
		return true;
	if (! num_moves)
		return num_moves;
	if (can_reach(start_c + 2, start_r + 1, finish_r, finish_c, num_moves - 1))
		return true;
	else if (can_reach(start_c + 2, start_r - 1, finish_r, finish_c, num_moves - 1))
		return true;
	else if (can_reach(start_c + 1, start_r + 2, finish_r, finish_c, num_moves - 1))
		return true;
	else if (can_reach(start_c + 1, start_r - 2, finish_r, finish_c, num_moves - 1))
		return true;
	else if (can_reach(start_c - 2, start_r + 1, finish_r, finish_c, num_moves - 1))
		return true;
	else if (can_reach(start_c - 2, start_r - 1, finish_r, finish_c, num_moves - 1))
		return true;
	else if (can_reach(start_c - 1, start_r + 2, finish_r, finish_c, num_moves - 1))
		return true;
	else if (can_reach(start_c - 1, start_r - 2, finish_r, finish_c, num_moves - 1))
		return true;
	else
		return false;
}

int main()
{
	std::cout << "Assingment 4.\n\nYou are going to be asked to enter 5 numbers, which are for \"column start\", \"row start\", \"column finish\", \"row finish\" and \"number of moves\" variables, respectively. Enter using integers and, in the range [0-7]. Please enter the numbers in order. Press enter after writing each number." << std::endl;
	int tempArr[5];
	for (int i = 0; i < 5; ++i)
	{
		std::cin.clear();
		std::cin >> tempArr[i];
		if (!std::cin)
		{
			std::cout << "Please restart this program as you entered invalid value" << std::endl;
			std::exit(0);
		}
	}

	can_reach(tempArr[0], tempArr[1], tempArr[2], tempArr[3], tempArr[4]) ? std::cout << "The given poisition is indeed reachable in given # of moves" << std::endl : std::cout << "The given position is NOT reachable in given # of moves" << std::endl;
}

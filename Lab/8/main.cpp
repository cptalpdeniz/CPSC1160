/*
* Assignment 8
* Author: Alp Deniz Senyurt
* Student ID: 100342433
* Self explanatory variables and parameters will not be commented as they are, "self-explanatory".
*/

#include <iostream>
#include <string>
#include "vector-stack.h"
#include "list-stack.h"

template <class STACK> bool is_matched(std::string s)
{
	STACK stack;
	for (char c : s)
	{
		if (c == '(' || c == '{' || c == '[')
		{
			stack.push(c);
		}
		else if (c == ')' || c == '}' || c == ']')
		{
			if (stack.is_empty())
				return false;
			char t = stack.pop();
			switch (c)
			{
				case ')':	if (t != '(')
								return false;
							break;
				case '}':	if (t != '{')
								return false;
							break;
				case ']':	if (t != '[')
								return false;
							break;
			}
		}
		else
		{
			std::cerr << "Wrong character found in the string. Please only use brackets" << std::endl;
			return false;
		}
	}
	return stack.is_empty();
}

int main()
{
	std::cout << "Assignment 8. \nTest cases are \"([][(({[]})()[])])\", \"([][)]\", \"(((){})\" respectively. First vector stack for all conditions then linked list stack thereafter." << std::endl;
	std::cout << is_matched<vector_stack>("([][(({[]})()[])])") << std::endl;
	std::cout << is_matched<vector_stack>("([][)]") << std::endl;
	std::cout << is_matched<vector_stack>("(((){})") << std::endl;

	std::cout << is_matched<list_stack>("([][(({[]})()[])])") << std::endl;
	std::cout << is_matched<list_stack>("([][)]") << std::endl;
	std::cout << is_matched<list_stack>("(((){})") << std::endl;

	std::string s;
	std::cout << "\nIf you would like to test your own input, please write a bracket string: ";
	std::cin >> s;
	
	std::cout << is_matched<list_stack>(s) << std::endl;
	std::cout << is_matched<vector_stack>(s) << std::endl;
	
}
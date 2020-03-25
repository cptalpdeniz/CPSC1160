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
			char t = stack.pop();
			switch(c)
			{
				case ')' :	if (t != '(')
								return false;
							break;
				case '}' :	if (t != '{')
								return false;
							break;
				case ']' :	if (t != '[')
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

}
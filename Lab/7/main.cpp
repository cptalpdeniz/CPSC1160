/*
* Assignment 7
* Author: Alp Deniz Senyurt
* Student ID: 100342433
* Self explanatory variables and parameters will not be commented as they are, "self-explanatory".
*/

#include <iostream>
#include "set.h"

//print function macro to save time writing few more characters lol
//I wonder if the marker reads the comments at all
#define printSet(s) std::cout << "Printing set: " << s << std::endl

int main()
{
	set set1(5);
	set set2(8);
	set set3(4);

	set1[1] = true;
	set1[3] = true;
	set1[4] = true;

	set2[1] = true;
	set2[2] = true;
	set2[4] = true;
	set2[6] = true;
	set2[7] = true;

	set3[0] = true;
	set3[2] = true;
	set3[3] = true;

	std::cout << "Sets are: " << std::endl;
	printSet(set1);
	printSet(set2);
	printSet(set3);


	//Testing copy constructor
	std::cout << "Testing copy constructor" << std::endl;
	set setTemp = set1;
	printSet(setTemp);

	//Testing assignment operator
	std::cout << "Testing assignment operator" << std::endl;
	setTemp = set2;
	printSet(setTemp);

	//Testing addition Assignment operator
	std::cout << "Testing addition Assignment operator" << std::endl;
	setTemp += set3;
	set2+= set1;
	set1+=setTemp;
	printSet(setTemp);
	printSet(set1);
	printSet(set2);

	//Testing addition operator
	std::cout << "Testing addition operator" << std::endl;
	printSet(set1 + setTemp);
	printSet(set2 + set1);
	printSet(set3 + set1);

	//Testing subtraction assignment operator
	std::cout << "Testing subtraction assignment operator" << std::endl;
	set1 -= setTemp;
	setTemp -= set2;
	set3 -= set1;
	printSet(set1);
	printSet(setTemp);
	printSet(set3);

	//Testing subtraction operator
	std::cout << "Testing subtraction operator" << std::endl;
	printSet(set2 - set1);
	printSet(set3 - set1);
	printSet(set3 - set2);

	//Testing multiplication assignment operator
	std::cout << "Testing multiplication assignment operator" << std::endl;
	set1 *= setTemp;
	setTemp *= set2;
	set3 *= set1;
	printSet(set1);
	printSet(setTemp);
	printSet(set3);

	//Testing multiplication operator
	std::cout << "Testing multiplication operator" << std::endl;
	printSet(set1 * setTemp);
	printSet(set2 * set1);
	printSet(setTemp * set3);

	//Testing negation operator
	std::cout << "Testing negation operator" << std::endl;
	printSet(~set1);
	printSet(~set2);
	printSet(~set3);

	return 0;
}

#undef printSet
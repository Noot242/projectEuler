// Main Function - Prints answers to the listed Project Euler Questions.

#include"Q1.h"
#include"Q2.h"
#include"Q3.h"
#include"Q4.h"
#include"Q5.h"
#include"Q6.h"
#include"Q7.h"
#include"Q8.h"
#include"Q9.h"
#include <chrono> // for std::chrono functions & Timer Class
#include<iostream> // for std::cout functions

void printAnswer(int question, int result)
{
	std::cout << "Q" << question << ": " << result << '\n';
}

int main()
{
	printAnswer(1, Q1());
	printAnswer(2, Q2());
	printAnswer(3, Q3());
	printAnswer(4, Q4());
	printAnswer(5, Q5());
	printAnswer(6, Q6());
	printAnswer(7, Q7());
	printAnswer(8, Q8());
	printAnswer(9, Q9());
	return 0;
}

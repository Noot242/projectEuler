/*
Multiples of 3 or 5

Problem 1
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.
*/

// Function Q1:
// Iterates from 0 to nth Element (not inclusive) and returns the sum of all numbers that are multiples of firstFactor or secondFactor.

#include "Q1.h"

int Q1(int nthElement, int firstFactor, int secondFactor)
{
	int sum{};

	for (int i{}; i < nthElement; i++) {
		if ((i % firstFactor == 0) || (i % secondFactor == 0)) {
			sum += i;
		}
	}
	return sum;
}
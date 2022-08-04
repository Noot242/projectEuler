/*
Sum square difference

Problem 6
The sum of the squares of the first ten natural numbers is, 1^2 + 2^2 + ... 10^2 = 385

The square of the sum of the first ten natural numbers is, (1 + 2 + ... + 10)^2 = 3025

Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 2640.

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
*/

#include"Q6.h"

int Q6(int nthTerm)
{
	int sumOfProducts{};

	for(int i{ 1 }; i < nthTerm; ++i)
	{
		for (int j{ i + 1 }; j <= nthTerm; ++j)
		{
			sumOfProducts += i * j;
		}
	}

	int diffSquareSum{ 2 * sumOfProducts };
	return diffSquareSum;
}


/* Notes
The sum of squares of (a+b)^2 expands to a^2 + 2ab + b^2 so maybe there's a smart way we can exploit that when calculating difference between sum of squares and square of sum.
i.e. (a+b)^2 - (a^2 + b^2) = 2ab

(a + b + c)^2 = a^2 + 2ab + b^2 + 2ac + c^2	+ 2bc

(a + b + c + d)^2 = a^2 + 2ab + b^2 + 2bc + c^2 + 2cd + d^2 + 2da + 2ac + 2bd

SquareOfSum - SumOfSquare = 2 * (Sum of Products a*b where a != b)

When looping:
i loops from 1 to 99
On each i iteration
j loops from i+1 to 100

This will make sure we get every unique product that excludes square numbers EXACTLY once. - Then can multiple by 2 to get final result
*/
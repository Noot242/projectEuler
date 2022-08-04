/*
Smallest multiple

Problem 5
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/

#include"Q5.h"
#include<cmath>
#include<iostream>

int GCD(int firstValue, int secondValue)
{
	int dividend{ firstValue };
	int quotient{ secondValue };
	int remainder{ dividend % quotient };

	while (remainder != 0)
	{
		dividend = quotient;
		quotient = remainder;
		remainder = dividend % quotient;
		//std::cout << '\t' << quotient << ' ' << remainder << '\n';
	}
	return quotient;
}

int LCM(int firstValue, int secondValue)
{
	int LCM{ firstValue * secondValue / GCD(firstValue, secondValue) };
	return LCM;
}

int Q5(int largestDivisor)
{
	int smallestMultiple{ 1 };
	for (int divisor{ 2 }; divisor < largestDivisor; ++divisor)
	{
		//std::cout << smallestMultiple << ' ' << divisor << '\n';
		if (smallestMultiple % divisor != 0)
		{
			smallestMultiple *= LCM(smallestMultiple, divisor) / smallestMultiple;
		}
	}
	return smallestMultiple;
}




/* Notes
My gut says the answer is 232792560 since it's factorisation would include every number less 20 --> 2^4 * 3^2 * 5 * 7 * 11 * 13 * 17 * 19
and I don't see how you can get any smallest than that.

Ignoring intuition, absolute worst case upper bound would be 20!

Maybe could generate all the primes up to 20 and then multiple together (seem grossly inefficent)

Maybe we could start at 1 check modulo 20 and if equal to 0, check 19 otherwise multiple by 20 - This seems like the most promising approach I can think of right now.
^ The above approach has the issue that if we hit say 16 and modulo is 0, but our number is 20 * 19 * 18 * 17 then when we multiple by 16 
we've inadvertantly multiplied by more factors of 2 than intended (since we've already got two factors of 2 from 20 and 18)

Therefore we need to be using the Lowest Common Multiple between our running total and our divisor to determine the smallest additional factor we can multiple by
that avoids including additional unintended factors;

LCM = (x * y) / GCD(x, y) where GCD is the Greatest Common Divisor (we can determine this using the Euclidian Algorithm)

Approach above starts at a smallestMuliple of 1 and divisor of 1 --> 20. SmallestMultiple is progressively multiplied by LCM(SmallestMultiple, divisor) / SmallestMultiple.
This guarantees it will include all factors up to divisor.
*/
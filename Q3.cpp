/*
Largest prime factor

Problem 3
The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?
*/

#include"Q3.h"
#include<cmath>
#include<iostream>
#include<vector>

void printFactors(const std::vector<int>& factors)
{
	for (int factor : factors) {
		std::cout << factor << ' ';
	}
	std::cout << '\n';
}

int Q3(long long int numberToBeFactored)
{
	long long int targetNumber{ numberToBeFactored };
	// Vector to save factors
	std::vector<int> factors{ };
	int divisor{ 2 };

	while (targetNumber != 1) {
		if ( (targetNumber % divisor) == 0) {
			factors.push_back(divisor);
			targetNumber /= divisor;
		}
		else {
			divisor += 1;
		}
	}
	return divisor;
}

/* Notes

Largest factor that needs to be checked is sqrt(number) since larger factors pair up with a small factor 
e.g. 24 --> 1, 2, 3, 4, 6, 8, 12, 24 (sqrt(24) floors to 4) --> Prime Factors: 1, 2, 3
e.g. 56 (sqrt(56) floors to 7) --> 1, 7, 8, 56 --> Prime Factors: 1, 2, 7

Ideally I only would check prime numbers < target number
- Not sure the best way to generate primes up to a particular number.
- This comes up in Q7 so can cross that bridge there.

*/
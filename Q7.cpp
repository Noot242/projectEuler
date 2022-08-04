/*
10001st prime

Problem 7
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10 001st prime number?
*/

#include"Q7.h"
#include<vector>

int Q7(int nthPrime)
{
	const int targetPrime{ nthPrime };
	const int targetPrimeIndex{ targetPrime - 1 };
	std::vector<int> myPrimes{ 2 };

	int candidate{ 3 };
	int prime{ myPrimes[0] };
	int primeIndexCounter{ 0 };

	while (myPrimes.size() != targetPrime)
	{
		while ( (candidate % prime != 0) && (prime <= static_cast<int>(sqrt(candidate))) )
		{
			++primeIndexCounter;
			prime = myPrimes[ primeIndexCounter ];
		}
		if ( prime > static_cast<int>(sqrt(candidate)) )
		{
			myPrimes.push_back(candidate);
		}
		
		candidate += 2;
		prime = myPrimes[0];
		primeIndexCounter = 0;
	}

	return myPrimes[targetPrimeIndex];
}


/* Notes
If we're looking for primes we only need to check if a candidate prime is divisible by numbers up to sqrt(candidate prime) 
	- Since if it isn't prime at least one factor will be less than or equal to this
We also only need to check the previous prime numbers since all composite numbers are a product of primes 
	- We'll round up so when we check 3 it will check it by dividing by 2.
	- We should also only check odd numbers.

So if the number is not divisible by any numbers in our list of primes then we should add it to our list of primes and move to the next number.
We terminate once we reach the 10001th prime.

Final code is messy and hard to read - not sure best way to restructure
*/
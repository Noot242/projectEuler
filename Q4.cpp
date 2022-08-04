/*
Largest palindrome product

Problem 4
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.
*/

#include"Q4.h"
#include<cmath>

int getDigitSize(int checkValue)
{
	// Ensures the One's position is the 0th position digit.
	int size{ -1 };
	while (checkValue)
	{
		++size;
		checkValue /= 10;
	}
	return size;
}

int getDigit(int checkValue, int position)
{
	int inputValue{ checkValue / static_cast<int>(pow(10, position)) };
	int dividedValue{ checkValue / static_cast<int>(pow(10, position + 1)) };

	return inputValue - dividedValue * 10;
}

bool checkPalindrome(int checkValue, int digitSize)
{
	// Add 1 since the One's position is the 0th digit.
	int numberOfDigits{ digitSize + 1 };

	for (int digit{ 0 }; digit < numberOfDigits / 2; ++digit) {
		if (getDigit(checkValue, digit) != getDigit(checkValue, digitSize - digit)) {
			return false;
		}
	}
	return true;
}

void decrementMultipliers(int& firstMultiple, int& secondMultiple, int smallestMultiple)
{
	if (firstMultiple == smallestMultiple)
	{
		--secondMultiple;
		firstMultiple = constantQ4::largestMultiple;
	}
	else
	{
		--firstMultiple;
	}
}

int Q4()
{
	int firstMultiple{ constantQ4::largestMultiple };
	int secondMultiple{ constantQ4::largestMultiple };
	int checkValue{ };
	int digitSize{ };
	int smallestMultiple{ constantQ4::smallestMultiple };
	bool palindromeFound{ false };
	int largestPalindrome{};

	while (!(firstMultiple == smallestMultiple && secondMultiple == smallestMultiple))
	{
		checkValue = firstMultiple * secondMultiple;
		digitSize = getDigitSize(checkValue);
		palindromeFound = checkPalindrome(checkValue, digitSize);
		if (palindromeFound)
		{
			largestPalindrome = (largestPalindrome > checkValue) ? largestPalindrome : checkValue;
			smallestMultiple = largestPalindrome / constantQ4::largestMultiple;
		}
		decrementMultipliers(firstMultiple, secondMultiple, smallestMultiple);
		palindromeFound = false;
	}

	return largestPalindrome;
}




/* Notes

Basic approach: Just start at 999 x 999 and work my way down until I find a palindrome?
Note since 999 x 998 is same as 998 x 999 need to consider how to increment each variable to avoid wasting operations

Need to guarentee we're incrementing down from largest to smallest (don't want to go calculate 999 x 994 first if 997 x 997 is larger)

Need some way to determine the length/number of digits in the returned number

Need some way of returning each digit for comparisons to check palindrome-iness


The above code feels bad - I don't like relying on static_casts and integer division to manipulate the digits.
Brute force approach (checking all possible multiples from 999 to 100) is definitely bad - Aggressively brute forces the situation.

New approach: If we find a palindrome for two multiples say 968 * 916 = 886688, then instead of checking all multiples from 999 to 100
we now only need to check numbers from 999 to floor(886688 / 999) = 887. - This will significantly increase performance

Code is generally messy and should be rewritten but the approach isn't too bad in principle.
Need to work out a better way to manage passing largestMultiple and smallestMultiple around - passing as function parameters, global variables, etc.
*/
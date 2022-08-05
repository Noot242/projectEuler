/*
Special Pythagorean triplet

Problem 9
A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,

a^2 + b^2 = c^2
For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.
*/

#include"Q9.h"

int Q9(int sumConstraint)
{
	int a{ 1 };
	int b{ 2 };
	bool pythagoreanTripleFound{ sumConstraint * (2 * (a + b - sumConstraint)) - 2 * a * b == 0 };
	while (!pythagoreanTripleFound)
	{
		if ((a + 1) == b || (b + 1) == 1000 - a - b)
		{
			a = 1;
			++b;
		}
		else
		{
			++a;
		}
		pythagoreanTripleFound = sumConstraint*(2*(a + b) - sumConstraint) - 2*a*b == 0;
	}
	int c{ 1000 - a - b };

	return a*b*c;
}

/* Notes
Maybe we can do some clever math stuff with the below:
- A pythagorean Triple	-->	a^2 + b^2						= c^2 
						--> a^2 + b^2 - c^2					= 0
						--> (a+b)^2 - 2ab - c^2				= 0		[ Definition of (a+b)^2 ]
						--> (a+b+c)(a+b-c) - 2ab			= 0		[ Difference of Two Squares ((a+b)^2 - c^2) ]
						--> 1000 * (a+b-c) - 2ab			= 0		[ Ensures we only find for a+b+c = 1000 ]
						--> 1000 * (2a + 2b - 1000) - 2ab	= 0		[ Substitute c = 1000 - a - b ]
						
When iterating we need to work out how to iterate through all the various sums of 1000 intelligently
Maybe we can start at c = 998, b = 2, a = 1 and then have some logic to update?
- Just realised when we set the (a+b+c) term equal to 1000 we're baking that constraint into our search if we use the equation above.
- Maybe we can find a similar constraint for a < b < c that deals with the (a+b-c) term?
- Using c = 1000 - a - b will at least reduce to just a and b
- As long as a < b and b < 1000 - a - b we should be searching the correct cases - not sure how performant it is though..
*/
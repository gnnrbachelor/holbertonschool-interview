#include "palindrome.h"


int is_palindrome(unsigned long n)
{
	if (n == reverse(n))
		return (1);
	else
		return (0);
}

unsigned long reverse(unsigned long n)
{
	unsigned long reversed = 0, remainder = 0, copy = n;

	while (copy != 0)
	{
		remainder = copy % 10;
		reversed = reversed * 10 + remainder;
		copy = copy / 10;
	}
	return (reversed);
}

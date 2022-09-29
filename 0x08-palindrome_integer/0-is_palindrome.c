#include "palindrome.h"

/**
 * is_palindrome - checks whether or not a given unsigned int is a plaindrome
 * @n : unsigned int to check
 * Return: int
 */
int is_palindrome(unsigned long n)
{
	unsigned long rev = 0, remainder, original;

	original = n;
	while (n != 0)
	{
		remainder = n % 10;
		rev = rev * 10 + remainder;
		n /= 10;
	}
	if (original == rev)
		return (1);
	return (0);
}

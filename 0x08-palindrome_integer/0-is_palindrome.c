#include <stdlib.h>
#include <stdio.h>

#include "palindrome.h"

/**
* is_palindrome - check if an integer is palindrome
*
* @n: unsigned int to check
*
* Return: 1 if palindrome 0 otherwise
*/
int is_palindrome(unsigned long n)
{
unsigned long x = 0, rev = 0, tmp = n;


while (tmp > 0)
{
x = tmp % 10;
rev = rev * 10 + x;
tmp /= 10;

}
if (n == rev)
return (1);
else
return (0);
}

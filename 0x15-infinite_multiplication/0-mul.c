#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "holberton.h"


/**
* _strlen - Determines the length of the string manually
* @s: Pointer to array of characters
* Return: Value of length
*/

int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;
	return (i);
}

/**
 * is_number - prints Error
 * @s: string passed for testing
 * Return: 1 or 0 on failure
 */
int is_number(char *s)
{
  int i;
  for (i = 0; s[i] != '\0'; i++)
  {
    if (s[i] > '9' || s[i] < '0')
    return 0;
  }
  return 1;
}

/**
 * to_int - converts string to int
 * @s: string to convert
 * Return: int
 */
int to_int(char *s)
{
  int i = 0, len = 0;
  long res = 0;

  while(s[len])
  {
    len++;
  }
  while (i < len)
  {
    res = res * 10 + s[i] - '0';
    // printf("res = %li\ns[i]= %c\n", res, s[i]);
    i++;
  }
return (res);
}

/**
 * multiply - multiplies two numbers
 * @a: first "number"
 * @b: second "number"
 **/
void multiply(int a, int b, int len_a, int len_b)
{
	int i, total, res = 0, tmp;
	int *ptr;


	tmp = len_b;
	total = len_a + len_b;

	ptr = malloc(sizeof(int) * total);
	if (!ptr)
	{
		return;
	}


	for (len_a--; len_a >= 0; len_a--)
	{
		res = 0;
		len_b = tmp;
		for (len_b--; len_b >= 0; len_b--)
		{
			res += ptr[len_b + len_a + 1] + (a * b);
			ptr[len_a + len_b + 1] = res % 10;
			res /= 10;
		}
		if (res)
			ptr[len_a + len_b + 1] = res % 10;
	}
	while (*ptr == 0)
	{
		ptr++;
		total--;
	}
	for (i = 0; i < total; i++)
		_putchar(ptr[i]);
	_putchar('\n');

}

/**
 * main - multiplies two positive numbers
 * @argc: argument counter
 * @argv: argument vector
 * Return: 0
 */
 int main(int argc, char **argv)
 {
   long a, b, len_a, len_b;
	 int i;
	 char *err = "Error\n";

   if (argc != 3 || !is_number(argv[1]) || !is_number(argv[2]))
   {
	   for (i = 0; err[i] != '\0'; i++)
	     _putchar(err[i]);
     exit(98);
   }

   a = to_int(argv[1]);
   b = to_int(argv[2]);
	 len_a = _strlen(argv[1]);
 	 len_b = _strlen(argv[2]);
   multiply(a, b, len_a, len_b);
  return 0 ;

 }

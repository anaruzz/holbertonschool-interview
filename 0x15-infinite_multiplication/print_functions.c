#include <unistd.h>
#include "holberton.h"
/**
* print_array - prints array
* @a: The array to print
* @size: size of The array to print
* Return: void
*/
void print_array(int *a, int size)
{
int i = 0;
while (a[i] == 0)
i++;
for (; i < size; i++)
_putchar(a[i] + '0');
_putchar('\n');
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
* print_error - Prints the word Error
*
* Return: void
*/
void print_error(void)
{
int i;
char *err = "Error\n";
for (i = 0; err[i] != '\0'; i++)
{
_putchar(err[i]);
}
}

/**
* _strlen - returns length of a string
* @s: The string
*
* Return: int
*/
int _strlen(char *s)
{
int i = 0;
while (s[i])
i++;
return (i);
}

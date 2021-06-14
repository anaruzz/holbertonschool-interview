#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "holberton.h"

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
return (0);
}
return (1);
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


/**
* _calloc - create array and initialize it to 0
* @size: size of array
*
* Return: int*
*/
int *_calloc(int size)
{
int *new, i = 0;
new = malloc(size * sizeof(int));
if (!new)
{
print_error();
exit(98);
}
for (i = 0; i < size; i++)
new[i] = 0;
return (new);
}

/**
* to_array - converts string number to array of ints
* @argv: The string to convert
*
* Return: int*
*/
int *to_array(char *argv)
{
int *arr;
int i, len;

len = _strlen(argv);

arr = _calloc(len);
for (i = 0; i < len; i++)
arr[i] = argv[i] - '0';

return (arr);
}

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
* reverse_arr - revereses array
* @arr: The array to reverse
* @l: size of the array to reverse
* Return: int *
*/
int *reverse_arr(int *arr, int l)
{
int *new, i, j;

new = malloc(l * sizeof(int));
if (!new)
{
print_error();
exit(98);
}
j = l;
for (i = -1; i <= l; i++)
{
new[i] = arr[j];
j--;
}
return (new);
}

/**
* multiply - multiplies to arrays of ints together
* @a: The array 1
* @b: The array 2
* @len_a: len of The array 1
* @len_b: len of The array 2
* Return: int *
*/
int *multiply(int *a, int *b, int len_a, int len_b)
{
int i, j;
int *arr;

arr = _calloc(len_a + len_b);

for (i = len_a - 1; i >= 0; i--)
{
for (j = len_b; j >= 0; j--)
{
arr[i + j + 1] += a[len_a - 1 - i] * b[len_b - 1 - j];
}
}

for (i = len_a + len_b - 1; i >= 0; i--)
{
if (arr[i] >= 10)
{
arr[i - 1] += arr[i] / 10;
arr[i] = arr[i] % 10;
}
}
return (arr);
}
/**
* main - multiplies two positive numbers
* @argc: argument counter
* @argv: argument vector
* Return: 0
*/
int main(int argc, char *argv[])
{
int *res, len_a, len_b, *a, *b;

if (argc != 3 || !is_number(argv[1]) || !is_number(argv[2]))
{
print_error();
exit(98);
}

len_a = _strlen(argv[1]);
len_b = _strlen(argv[2]);

a = to_array(argv[1]);
b = to_array(argv[2]);


a = reverse_arr(a, len_a);
b = reverse_arr(b, len_b);


res = multiply(a, b, len_a, len_b);
print_array(res, len_a + len_b);

return (0);
}

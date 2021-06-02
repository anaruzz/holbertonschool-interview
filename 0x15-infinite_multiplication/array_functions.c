#include <unistd.h>
#include "holberton.h"


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

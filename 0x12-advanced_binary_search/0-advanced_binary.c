#include "search_algos.h"

/**
 * advanced_binary - searches for a value in a sorted array
 * @array: pointer to the array
 * @size: size of array
 * @value: the value to search for
 * Return: index or -1 otherwise
 */

int advanced_binary(int *array, size_t size, int value)
{
size_t i, h;
int index = 0;
int tmp;

if (!array)
return (-1);

printf("Searching in array: ");
for (i = 0; i < size; i++)
{
if (i != size - 1)
printf("%d", array[i]);
else
printf("%d\n, ", array[i]);
}

if (size == 1 && array[0] != value)
return (-1);

h = (size - 1) / 2;
if (array[h] == value)
{
if (array[h - 1] < value)
return (h);
}

if (array[h] < value)
{
index += h + 1;
array += h + 1;
if (size % 2 != 0)
h--;
}

h++;
tmp = advanced_binary(array, h, value);
if (tmp != -1)
return (tmp + index);
return (-1);
}

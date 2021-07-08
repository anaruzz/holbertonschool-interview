#include "sort.h"

/**
* _max - finds max in an array
* @array: the array to look in
* @size: Size of @array
* Return: int
*/
int _max(int *array, int size)
{
int i, max;

for (max = array[0], i = 1; i < size; i++)
{
if (array[i] > max)
max = array[i];
}
return (max);
}

/**
* radix_count - Sort the array depending on exp
* @array: Array to sort
* @size: Size of @array
* @exp: Int to divide array for the specific digit.
* Return: void
*/

void radix_count(int *array, int size, int exp)
{
int i, *output, count[10] = {0};

output = malloc(sizeof(int) * size);
if (!output)
return;

for (i = 0; i < size; i++)
count[(array[i] / exp) % 10]++;

for (i = 1; i < 10; i++)
count[i] += count[i - 1];

for (i = size - 1; i >= 0; i--)
{
output[count[(array[i] / exp) % 10] - 1] = array[i];
count[(array[i] / exp) % 10]--;
}

for (i = 0; i < size; i++)
array[i] = output[i];
free(output);
}


/**
* radix_sort - Sorts an array of integers with radix sort
* @array: Array to be sorted
* @size: Size of @array
* Return: void
*/
void radix_sort(int *array, size_t size)
{
int x, max;

if (size < 2)
return;

max = _max(array, size);
for (x = 1; max / x > 0; x *= 10)
{
radix_count(array, size, x);
print_array(array, size);
}
}

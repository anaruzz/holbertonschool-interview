#include "search_algos.h"

/**
* rec_search - search recursive for vzlue in array
* @array: sorted array
* @begin: begining index of the subarray
* @end: ending index of the subarray
* @value: value we are looking for
*
* Return: index, -1 if doesn't find it.
*/
int rec_search(int *array, int begin, int end, int value)
{
int i, mid;

mid = begin + (end - begin) / 2;
if (begin == end)
{
if (value < array[begin] || value > array[end])
{
printf("Searching in array: %d\n", array[mid]);
return (-1);
}
return (begin);
}
printf("Searching in array:");
for (i = begin; i <= end; i++)
{
if (i != end)
printf(" %d,", array[i]);
else
printf(" %d\n", array[i]);
}

if (array[mid] < value)
return (rec_search(array, mid + 1, end, value));
else
return (rec_search(array, begin, mid, value));
}

/**
* advanced_binary - searches for a value in a sorted array
* @array: pointer to the array
* @size: size of the array.
* @value: value we are looking for.
* Return: index of the fist value or -1 otherwhie
*/
int advanced_binary(int *array, size_t size, int value)
{
if (!array)
return (-1);
return (rec_search(array, 0, size - 1, value));
}

#include "sort.h"

/**
* merge - merges left and rigth arrays
* @size:	size of the array
* @array: original array
* @left:	left array
* @right: right array
* Return: void
**/
void merge(size_t size, int *array, int *left, int *right)
{
int i, j, k;
int l_size, r_size;


l_size = size / 2;
r_size = size - l_size;

printf("Merging...\n");
printf("[left]: ");
print_array(left, l_size);
printf("[right]: ");
print_array(right, r_size);

i = 0;
j = 0;
k = 0;
while (i < l_size && j < r_size)
{
array[k] = (left[i] < right[j]) ? left[i++] : right[j++];
k++;
}
while (i < l_size)
{
array[k] = left[i++];
k++;
}
while (j < r_size)
{
array[k] = right[j++];
k++;
}

printf("[Done]: ");
print_array(array, size);
}

/**
* merge_sort - sorts in ascending order using Merge Sort method.
* @array: pointer to the array
* @size:	size of the array
**/
void merge_sort(int *array, size_t size)
{
size_t middle, i;
int left[1000], right[1000];

if (!array || size < 2)
return;

middle = size / 2;
for (i = 0; i < middle; i++)
left[i] = array[i];

for (i = middle; i < size; i++)
right[i - middle] = array[i];

merge_sort(left, middle);
merge_sort(right, size - middle);
merge(size, array, left, right);
}

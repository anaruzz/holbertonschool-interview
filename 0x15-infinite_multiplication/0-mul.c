#include <unistd.h>
#include "holberton.h"

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

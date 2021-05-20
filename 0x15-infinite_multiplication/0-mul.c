#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

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
    return 0;
  }
  return 1;
}

/**
 * error_print - prints Error
 *
 * Return: Void
 */
void error_print()
{
  int i;
  char *err = "Error\n";
  for (i = 0; err[i] != '\0'; i++)
  {
    _putchar(err[i]);
  }
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
void _print(long res)
{
  if (res / 10)
    _print(res / 10);
  _putchar(res % 10 + '0');
}
/**
 * main - multiplies two positive numbers
 * @argc: argument counter
 * @argv: argument vector
 * Return: 0
 */
 int main(int argc, char **argv)
 {
   long a, b, res;

   if (argc != 3 || !is_number(argv[1]) || !is_number(argv[2]))
   {
     error_print();
     exit(98);
   }

   a = to_int(argv[1]);
   b = to_int(argv[2]);
   res = a * b;
   _print(res);
   _putchar('\n');

 }

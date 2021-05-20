#include <stdio.h>
#include <stdlib.h>

int main ()
{
  int i = 0, len = 0;
  int res = 0;
  char *s = "452";
  while(s[len])
  {
    len++;
  }
  // printf("%i\n", res);

  i = 0;
  while (i < len)
  {
    res = res * 10 + s[i] - '0';
    printf("res = %i\ns[i]= %c\n", res, s[i]);
    i++;
  }
  printf("%i\n", res);
  return 0 ;
}

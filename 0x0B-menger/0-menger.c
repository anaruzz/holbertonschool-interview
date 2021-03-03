#include "stdio.h"
#include "math.h"

char Character(int i, int j)
{
  for (; i && j; i /= 3, j /= 3)
  {
    if ((i % 3 == 1) && (j % 3 == 1))
      return (' ');
  }
  return ('#');
}
/**
* menger - draws a 2D menger sponge
* @level - level of the menger sponge to draw
*/

void menger(int level)
{
  int dim, i, j;
  char c;

if (level >= 0)
{
  dim = pow(3, level);

  for (i = 0; i < dim; i++)
  {
    for (j = 0; j < dim; j++)
    {
      c = Character(i, j);
      printf("%c", c);
    }
    printf("\n");
  }


}
}

#include <stdlib.h>
#include <stdio.h>

int check_stable(int grid[3][3])
{
  int i = 0, j = 0;
  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 3; j++)
    {
      if (grid[i][j] > 3)
      return 0;
    }
  }
  return 1;
}

void print_grid(int grid[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (j)
                printf(" ");
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
}

void basic_sum(int grid1[3][3], int grid2[3][3])
{
  int i, j;
  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 3; j++)
    {
      grid1[i][j] += grid2[i][j];
    }
  }
}

void topple(int grid[3][3])
{
int i = 0, j = 0;

for (i = 0; i < 3; i++)
{
  for (j = 0; j < 3; j++)
  {
    if (grid[i][j] > 3)
    {
    grid[i][j] -= 4;
    if (i > 0)
    grid[i - 1][j] += 1;
    if (i < 2)
    grid[i + 1][j] += 1;
    if (j > 0)
    grid[i][j - 1] += 1;
    if (j < 2)
    grid[i][j + 1] += 1;
    }
  }
}
}


void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{

basic_sum(grid1, grid2);
while (check_stable(grid1) == 0)
{
  printf("=\n");
  print_grid(grid1);
  topple(grid1);
}

}

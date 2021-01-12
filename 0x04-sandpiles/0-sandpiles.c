#include <stdlib.h>
#include <stdio.h>
#include "sandpiles.h"

/**
* check_stable - check if grid is stable.
* @grid: matrix 3x3.
* Return: int
*/
int check_stable(int grid[3][3])
{
int i = 0, j = 0;
for (i = 0; i < 3; i++)
{
for (j = 0; j < 3; j++)
{
if (grid[i][j] > 3)
return (0);
}
}
return (1);
}

/**
* copy_grid - copy grid2 into grid 1
* @grid1: matrix 3x3.
* @grid2: matrix 3x3.
* Return: void
*/
void copy_grid(int grid1[3][3], int grid2[3][3])
{
int i, j;

for (i = 0; i < 3; i++)
{
for (j = 0; j < 3; j++)
{
grid1[i][j] = grid2[i][j];
}
}
}

/**
* topple - the toppling of a grid
* @grid: matrix 3x3.
* Return: void
*/
void topple(int grid[3][3])
{
int i, j, tmp[3][3];
copy_grid(tmp, grid);

for (i = 0; i < 3; i++)
{
for (j = 0; j < 3; j++)
{
if (grid[i][j] > 3)
{
tmp[i][j] -= 4;
if (i - 1 >= 0)
tmp[i - 1][j] += 1;
if (i + 1 < 3)
tmp[i + 1][j] += 1;
if (j - 1 >= 0)
tmp[i][j - 1] += 1;
if (j + 1 < 3)
tmp[i][j + 1] += 1;
}
}
}
copy_grid(grid, tmp);
}

/**
* print_gridd - print grid.
* @grid: matrix 3x3.
* Return: void
*/
void print_gridd(int grid[3][3])
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

/**
* sandpiles_sum - Sum of 2 sandpiles
* @grid1: matrix 3x3.
* @grid2: matrix 3x3.
* Return: void
*/
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{

int i, j;
for (i = 0; i < 3; i++)
{
for (j = 0; j < 3; j++)
{
grid1[i][j] += grid2[i][j];
}
}
while (check_stable(grid1) == 0)
{
printf("=\n");
print_gridd(grid1);
topple(grid1);
}

}

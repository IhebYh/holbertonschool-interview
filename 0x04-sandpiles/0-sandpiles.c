#include "sandpiles.h"

/**
 * isUnstable - checks if sandpile is unstable
 * @grid: the sandpile to check
 * Return: 1 if unstable else 0
 */
int isUnstable(int grid[3][3])
{
	size_t i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (grid[i][j] > 3)
				return (1);
	return (0);
}

/**
 * topple - topples a sandpile, dispersing all cells > 3
 * @grid1: the sandpile to topple
 * @grid2: the 'buffer' pile which stores the dispersions
 */
void topple(int grid1[3][3], int grid2[3][3])
{
	size_t i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (grid1[i][j] > 3)
				(i > 0) ? grid2[i - 1][j] += 1 : 0,
				(j > 0) ? grid2[i][j - 1] += 1 : 0,
				(i < 2) ? grid2[i + 1][j] += 1 : 0,
				(j < 2) ? grid2[i][j + 1] += 1 : 0,
				grid1[i][j] -= 4;
	calculate(grid1, grid2);
}

/**
 * calculate - adds two sandpiles, nulling the 2nd as a buffer
 * @grid1: first sandpile, stores sum
 * @grid2: second sandpile, gets nulled
 */
void calculate(int grid1[3][3], int grid2[3][3])
{

	size_t i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid1[i][j] += grid2[i][j], grid2[i][j] = 0;
}

/**
 * print_sandpile - prints the sandpile
 * @grid: the sandpile to print
 */
void print_sandpile(int grid[3][3])
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
 * sandpiles_sum -  a function that computes the sum of two sandpiles
 * WARNING -> NOT ALLOWED TO ALLOCATE MEMORY DYNAMICALLLY
 * @grid1: first sandpile
 * @grid2: second sandpile
 * Return: void
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	calculate(grid1, grid2);
	while (isUnstable(grid1))
	{
		printf("=\n");
		print_sandpile(grid1);
		topple(grid1, grid2);
	}
}

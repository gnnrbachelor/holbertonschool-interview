#include "sandpiles.h"
/**
 * sandpiles_sum - Sums sandpiles
 * @grid1: Grid 1
 * @grid2: Grid 2
 * Return : Void
 *
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i = 0;
	int j = 0;
	int tip_it = 0;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
			grid2[i][j] = (grid1[i][j] > 3);
			tip_it += (grid1[i][j] > 3);
		}

	while (tip_it)
	{
		printf("=\n");
		print_grid(grid1);

		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
				if (grid2[i][j])
				{
					grid1[i][j] -= 4;
					if (i + 1 < 3)
						grid1[i + 1][j] += 1;
					if (i - 1 >= 0)
						grid1[i - 1][j] += 1;
					if (j + 1 < 3)
						grid1[i][j + 1] += 1;
					if (j - 1 >= 0)
						grid1[i][j - 1] += 1;
				}
		for (tip_it = 0, i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
			{
				grid2[i][j] = (grid1[i][j] > 3);
				tip_it += (grid1[i][j] > 3);
			}
	}

}


/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
static void print_grid(int grid[3][3])
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











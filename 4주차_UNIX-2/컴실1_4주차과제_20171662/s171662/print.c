#include "header.h"

void print(int** arr, int num)
{
	int i, j;

	for (i = 0;i < num;i++)
	{
		for (j = 0;j < 10;j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}
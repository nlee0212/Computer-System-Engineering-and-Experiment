#include "header.h"

int main(void)
{
	int num, i,j;
	int** num_array;
	int input;

	scanf("%d", &num);

	num_array = (int**)malloc(sizeof(int*)*num);

	for (i = 0;i < num;i++)
	{
		num_array[i] = (int*)malloc(sizeof(int) * 10);
		scanf("%d", &input);
		for (j = 0;j < 10;j++)
			num_array[i][j] = count(input)[j];
	}

	print(num_array, num);

	return 0;
}
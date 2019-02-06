#include "header.h"

int* count(int input)
{
	int i;
	int numcount[10];
	int* temp;

	for (i = 0;i < 10;i++)
	{
		numcount[i] = 0;
	}

	for (i = 1;i <= input;i++)
		eachnum(i, &numcount);
	
	temp = numcount;

	return temp;
}

void eachnum(int input, int(*arr)[10])
{
	int digit, i, init = 1;
	int test[10];

	for (i = 0;i < 10;i++)
	{
		test[i] = '\0';
	}

	digit = find_digit(input);

	for (i = 0;i < digit - 1;i++)
	{
		init = init * 10;
	}

	for (i = 0;i < digit;i++)
	{
		test[i] = input / init;
		input = input % init;
		init = init / 10;
		(*arr)[test[i]]+=1;
	}
}

int find_digit(int input)
{
	int temp, i;

	temp = input;

	for (i = 0;temp / 10 != 0;i++)
		temp = temp / 10;

	return i + 1;
}

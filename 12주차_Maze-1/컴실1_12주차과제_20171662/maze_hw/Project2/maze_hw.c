#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define TRUE 1
#define FALSE 0

void V_Print(int* v_wall);
void H_Print(int* h_wall);
void V_Connect(int* h_wall);
void H_Connect(int* v_wall);

int num = 0, WIDTH, HEIGHT, Id = 0;
int** h_wall, **v_wall;
int* Room;

FILE* file;

int main()
{
	int i, j, k, prev_Id;
	int currwall = -1;
	file = fopen("mazeGen.maz", "wt");
	scanf("%d", &WIDTH);
	scanf("%d", &HEIGHT);

	h_wall = (int**)malloc(sizeof(int*)*(HEIGHT - 1));
	v_wall = (int**)malloc(sizeof(int*)*(HEIGHT));

	for (i = 0; i < HEIGHT - 1; i++)
	{
		h_wall[i] = (int*)malloc(sizeof(int)*WIDTH);
		v_wall[i] = (int*)malloc(sizeof(int)*WIDTH - 1);
	}

	v_wall[i] = (int*)malloc(sizeof(int)*WIDTH - 1);
	Room = (int*)malloc(sizeof(int)*WIDTH);
	memset(Room, 0, sizeof(Room));

	for (i = 0; i<WIDTH; i++) fprintf(file, "+-");
	fprintf(file, "+\n");
	srand(time(NULL));

	for (i = 0; i<WIDTH - 1; i++) {
		v_wall[0][i] = rand() % 2;
		if (v_wall[0][i] == TRUE)
		{
			for (j = currwall + 1; j <= i; j++) Room[j] = Id;
			Id = Id + 1;
			currwall = i;
		}
	}
	for (i = currwall + 1; i<WIDTH; i++)
		Room[i] = Id;
	Id = Id + 1;


	for (k = 1; k<HEIGHT - 1; k++) {
		V_Connect(h_wall[k - 1]);
		H_Connect(v_wall[k]);
	}
	V_Connect(h_wall[HEIGHT - 2]);

	for (i = 0; i<WIDTH - 1; i++)
	{
		if (Room[i] != Room[i + 1])
		{
			v_wall[HEIGHT - 1][i] = FALSE;
			currwall = Room[i + 1];
			Room[i + 1] = Room[i];
			for (j = 0; j<WIDTH; j++)
			{
				if (Room[j] == currwall)
					Room[j] = Room[i];
			}
		}
		else
		{
			v_wall[HEIGHT - 1][i] = TRUE;
		}
	}
	num = WIDTH;
	if (WIDTH > HEIGHT) num = HEIGHT;
	num = num / 2;

	for (i = 1; i <= num; )
	{
		j = rand() % (HEIGHT - 1);
		k = rand() % (WIDTH - 1);

		if (v_wall[j][k] == TRUE)
		{
			v_wall[j][k] = FALSE;
			i++;
		}
		else if (h_wall[j][k] == TRUE)
		{
			h_wall[j][k] = FALSE;
			i++;
		}
	}

	for (i = 0; i < HEIGHT - 1; i++)
	{
		V_Print(v_wall[i]);
		H_Print(h_wall[i]);
	}
	V_Print(v_wall[i]);

	for (i = 0; i<WIDTH; i++) {
		fprintf(file, "+-");
	}
	fprintf(file, "+\n");
	return 0;
}

void V_Print(int* v_wall)
{
	fprintf(file, "|");
	for (int i = 0; i<WIDTH - 1; i++) {
		fprintf(file, " ");
		if (v_wall[i] == TRUE) fprintf(file, "|");
		else fprintf(file, " ");
	}
	fprintf(file, " |\n");
}

void H_Print(int* h_wall)
{
	fprintf(file, "+");
	for (int i = 0; i<WIDTH; i++) {
		if (h_wall[i] == TRUE) fprintf(file, "-+");
		else fprintf(file, " +");
	}
	fprintf(file, "\n");
}

void V_Connect(int* h_wall)
{
	int  CurrId = Room[0], switch1 = FALSE;
	for (int i = 0; i<WIDTH; i++)
	{
		h_wall[i] = rand() % 2;
		if (h_wall[i] == FALSE) switch1 = TRUE;
		if (i<WIDTH - 1)
		{
			if (CurrId != Room[i + 1])
			{
				if (switch1 == FALSE) h_wall[i] = FALSE;
				switch1 = FALSE;
				CurrId = Room[i + 1];
			}
		}
		if ((i == WIDTH - 1) && (switch1 == FALSE)) h_wall[i] = FALSE;
		if (h_wall[i] == TRUE) {
			Room[i] = Id;
			Id = Id + 1;
		}
	}

}

void H_Connect(int* v_wall)
{
	int i, j, CurrId, prev_wall = -1;
	for (i = 0; i<WIDTH - 1; i++)
	{
		if (Room[i] != Room[i + 1])
		{
			v_wall[i] = rand() % 2;
			if (v_wall[i] == FALSE)
			{
				CurrId = Room[i + 1];
				Room[i + 1] = Room[i];
				for (j = 0; j<WIDTH; j++)
				{
					if (Room[j] == CurrId) Room[j] = Room[i];
				}

			}
			else v_wall[i] = TRUE;
		}
		else v_wall[i] = TRUE;
	}
}


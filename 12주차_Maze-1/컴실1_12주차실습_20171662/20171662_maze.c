#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define NAMELEN 15

void vprint();
void hprint();
void connect();
void join();
void draw_outline();

int* h_wall;
int* v_wall;
int* nummaze;
int N, M, curnum=0;
char filename[NAMELEN]="maze01.maz";
FILE* fp;

int main() {

	int i, j;
	int wall = -1;

	srand(time(NULL));

	fp = fopen(filename, "wt");

	scanf("%d", &N);
	scanf("%d", &M);

	h_wall = (int*)malloc(sizeof(int)*(N));//horizontal line array
	v_wall = (int*)malloc(sizeof(int)*(N - 1));//vertical line array

	nummaze = (int*)malloc(sizeof(int)*N);//room array
	memset(nummaze, 0, sizeof(nummaze));//initializing the room numbers to 0

	draw_outline();

	//for the first line
	for (i = 0; i<N - 1; i++) {
		v_wall[i] = rand() % 2;

		//if 1, then delete the line
		if (v_wall[i])
		{
			//set the room no.s to curnum
			for (j = wall + 1; j <= i; j++)
				nummaze[j] = curnum;

			//for the next room
			curnum++;
			wall = i;
		}
	}

	//setting the room no.s according to the preceded step
	for (i = wall + 1; i<N; i++)
		nummaze[i] = curnum;

	curnum++;

	vprint();

	//for the middle lines
	for (i = 1; i<M - 1; i++) 
	{
		connect();
		hprint();
		join();
		vprint();
	}

	//for the last line
	connect();
	hprint();

	for (i = 0; i<N - 1; i++)
	{
		if (nummaze[i] != nummaze[i + 1])
		{
			v_wall[i] = 0;
			wall = nummaze[i + 1];
			nummaze[i + 1] = nummaze[i];

			for (j = 0; j<N; j++)
				if (nummaze[j] == wall)
					nummaze[j] = nummaze[i];
		}

		else
			v_wall[i] = 1;
	}

	vprint();

	draw_outline();

	fclose(fp);

	return 0;
}

void vprint() 
{
	//drawing the walls according to the v_wall
	int i;

	fprintf(fp, "|");

	for (i = 0; i<N - 1; i++) 
	{
		fprintf(fp, " ");

		if (v_wall[i]) 
			fprintf(fp, "|");
		
		else 
			fprintf(fp, " ");
		
	}

	fprintf(fp, " |\n");
}
void hprint() 
{
	//drawing the walls according to the h_wall
	int i;

	fprintf(fp, "+");

	for (i = 0; i<N; i++) 
	{
		if (h_wall[i]) 
			fprintf(fp, "-+");

		else 
			fprintf(fp, " +");
	}

	fprintf(fp, "\n");
}

void connect() 
{
	//connecting the rooms
	//set the room no.s according to the walls
	//if no wall -> flag check
	//if no wall deleted -> delete & set the room no.
	//if last room with one num -> delete the wall
	//if different wall -> set the room no. to curnum
	//VERTICAL
	int i,num=nummaze[0], check=0;
	
	for (i = 0; i<N; i++) 
	{
		h_wall[i] = rand() % 2;
		
		if (!h_wall[i]) 
			check = 1;

		if (i<N - 1) 
		{
			if (num != nummaze[i + 1]) 
			{
				if (!check) 
					h_wall[i] = 0;

				check = 0;
				num = nummaze[i + 1];
			}
		}

		if ((i == N - 1) && (check == 0))
			h_wall[i] = 0;

		if (h_wall[i]) 
		{
			nummaze[i] = curnum;
			curnum++;
		}
	}
}

void join()
{
	//randomly joining the rooms
	//check if the rooms are different and choose to delete the wall or not
	int i, j;
	int num;

	for (i = 0; i<N - 1; i++)
	{
		if (nummaze[i] != nummaze[i + 1])
		{
			v_wall[i] = rand() % 2;

			if (v_wall[i])
			{
				num = nummaze[i + 1];
				nummaze[i + 1] = nummaze[i];

				for (j = 0; j<N; j++)
				{
					if (nummaze[j] == num)
						nummaze[j] = nummaze[i];
				}

				v_wall[i] = 0;
			}

			else
				v_wall[i] = 1;
		}

		else
			v_wall[i] = 1;
	}
}

void draw_outline()
{
	int i;
	
	for (i = 0; i<N; i++) 
		fprintf(fp, "+-");
	
	fprintf(fp, "+\n");
}
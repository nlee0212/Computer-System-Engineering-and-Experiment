#include "StdAfx.h"
#include "MyHeader.h"

CASES *testcases;
int testCaseNum;
int currentCase;
char *resultString;

int P[NODE_MAX_NUM];

//�ʱ�ȭ ���ִ� �Լ�
void F1()
{
	int i;

	//parent �����ϴ� �迭 �ʱ�ȭ
	for (i = 0 ; i < NODE_MAX_NUM ; i++ ) 
		P[i] = -1;
	
	currentCase = 0;
	testCaseNum = 0;
	
	if (resultString != NULL)
	{
		delete[] resultString;
		resultString = NULL;
	}

	resultString = new char[256];

	if( testcases != NULL )
	{
		delete [] testcases;
		testcases = NULL;
	}
}

//���� �о ���� �����ϴ� �Լ�
void F2(const char* fn)
{
	int i,j,n;
	FILE *fp;
	fp= fopen(fn, "r");

	//���� �ҷ����� ���� 
	if (fp==NULL) 
		return;

	//�׽�Ʈ ���̽� ���� �ޱ�
	fscanf(fp,"%d",&testCaseNum);

	//�׽�Ʈ ���̽� ������ŭ �Ҵ�
	testcases = new CASES[testCaseNum];

	for ( i = 0 ; i < testCaseNum ; i++ ) 
	{
		fscanf(fp,"%d",&n);
		testcases[i].k = n;
		
		for ( j = 0 ; j < n ; j++ ) 
		{
			fscanf(fp,"%d %d", &testcases[i].x[j],&testcases[i].y[j]);
		}
	}

	fclose(fp);
}

char* F3(int n)
{
	int i,count;
	if( resultString == NULL )
		return NULL;

	for ( i = 0 ; i < NODE_MAX_NUM ; i++ ) 
	{
		P[i] = -1;
	}

	sprintf(resultString, "Case %d is not a tree.", n);

	for ( i = 0 ; i < testcases[n-1].k ; i++ ) 
	{
		int x = testcases[n-1].x[i];
		int y = testcases[n-1].y[i];

		if ( P[x] == -1 ) 
			P[x] = 0;
		
		if ( P[y] <= 0 ) 
			P[y] = x;
		
		else 
			return resultString;
	}
	
	count = 0;

	for (i = 0 ; i < NODE_MAX_NUM ; i++ ) 
	{
		if ( P[i] == 0 ) 
			count++;
	}

	if ( count >= 2 ) 
		return resultString;

	if ( !Cycle_check(P))
		sprintf(resultString, "Case %d is a tree.", n);

	return resultString;
}

//Cycle�� �ִ��� Ȯ���ϴ� �Լ�
bool Cycle_check( int p[])
{
	int flag[NODE_MAX_NUM], i, j;

	for(i = 0; i< NODE_MAX_NUM; i++)
	{
		if (P[i] <= 0 )
			continue;

		for(j = 0; j < NODE_MAX_NUM; j++)
			flag[j] = -1;

		if ( dfs ( P, flag, i ) == true )
			return true; 
	}

	return false;
}

//��Ʈ���� ������ �� ����Ǿ� �ִ��� Ȯ���ϴ� �Լ�
bool dfs(int p[], int flag[], int c)
{
	flag[c] = 1;
	
	if ( P[c] == 0 ) 
		return false;	
	else if ( flag[P[c]] == 1 )
		return true;	
	else
		return dfs(P, flag, P[c]);
}
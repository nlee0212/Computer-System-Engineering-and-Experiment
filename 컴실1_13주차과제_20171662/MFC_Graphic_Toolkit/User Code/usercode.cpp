#include <stdlib.h>
#include "..\ExternDoc.h"
#include "..\UI\Zoom.h"
#include "..\UI\MsgView.h"
#include "..\Graphics\DrawFunc.h"
#include "..\Example\Example.h"

#define ERROR_NUMBER -1
#define TRUE 1
#define FALSE 0

//function prototype

static void drawDirect(CDC *pDC);
static void drawBuffered();

//Start of user code
#include <float.h>

/*****************************************************************
* function	: bool readFile(const char* filename)
* argument	: cons char* filename - filename to be opened
* return	: true if success, otherwise flase
* remark	: After read data file, phisycal view must be set;
*			  otherwise drawing will not be executed correctly.
*			  The window will be invalidated after readFile()
*			  returns true.
******************************************************************/

typedef struct maze {
	int up;
	int down;
	int right;
	int left;
}maze;

maze** check;
char** realmaze;
int M, N;
int i, j;

bool readFile(const char* filename)
{
	//start of the user code
	FILE* fp;
	int height, width;
	char tmp;

	fp = fopen(filename, "r");
	if (!fp)
		return false;
	N=0;
	M=0;

	while (fscanf(fp, "%c", &tmp) != EOF) //���� width �ľ�!
	{
		if (tmp == '+'|| tmp == '-')
			N++;

		else//���� �б� ������ �ݺ������� ������
			break; 
	}

	M++;
	//������ ���� �о����Ƿ� �ϴ� height 1 ���� ��Ŵ(M=1)

	while (fscanf(fp, "%c", &tmp) != EOF)  //enter�� ���̶�� �� ���� �����ٴ� ���̹Ƿ� height �ľ�
	{
		if (tmp != '+'&& tmp != '-' && tmp != ' '&& tmp != '|')
			M++;
	}

	fclose(fp); 
	//������ ó������ �ٽ� �о�� ��. ������ ���� �ٽ� �����ν� ������ ���������� ó������ �а� �Ѵ�.

	fp = fopen(filename, "r"); 

	realmaze = (char**)malloc(sizeof(char*)*(M + 2)); //���������� N, M���� 2���� �迭 realmaze ����
	for (i = 0; i < M + 2; i++)
		realmaze[i] = (char*)malloc(sizeof(char)*(N + 2));
	
	for (i = 0; i < M + 2; i++) //������ ���� N�� M���� ���� for loop���� ���پ� �о�ͼ� realmaze �迭�� character�� ����
	{
		for (j = 0; j < N + 2; j++) 
		{
			fscanf(fp, "%c", &tmp);
			realmaze[i][j] = tmp;

			if (tmp == '\0' || tmp == '\n')
			{
				realmaze[i][j] = '\0';
				break;
			}
		}

		if (tmp == '\0') break;
	}
	
	N--;
	//width/height ��� ���ϱ�
	height = M / 2; 
	width = N / 2; 

	check = (maze**)malloc(sizeof(maze*)*height); 
	for (i = 0; i < height; i++)  //2���� �迭 ���� �� struct�� ��� ���ҵ� 0���� �ʱ�ȭ
	{
		check[i] = (maze*)malloc(sizeof(maze)*width);

		for (j = 0; j < width; j++)
		{
			check[i][j].up = FALSE;
			check[i][j].down = FALSE;
			check[i][j].left = FALSE;
			check[i][j].right = FALSE; 
		}
	}
	
	for (i = 0; i < M; i++) //���� for loop�� ���� �̷��� �� 'ĭ'����(i/j�� Ȧ���� ��) �����¿� Ȯ�� �� ���� �����ϴ� ������ 1�� ǥ��
	{
		if (i % 2) 
		{
			for (j = 0; j < N; j++) 
			{
				if (j % 2) 
				{
					if (realmaze[i][j - 1] == '|')
						check[i / 2][j / 2].left = TRUE; 
					if (realmaze[i][j + 1] == '|') 
						check[i / 2][j / 2].right = TRUE;
					if (realmaze[i - 1][j] == '-') 
						check[i / 2][j / 2].up = TRUE;
					if (realmaze[i + 1][j] == '-') 
						check[i / 2][j / 2].down = TRUE;
				}
			}
		}
	}
	
	setWindow(0, 0, N / 2, M / 2, 1);
	fclose(fp);

	return true;
	//end of usercode
}

/******************************************************************
* function	: bool FreeMemory()
*
* remark	: Save user data to a file
*******************************************************************/
void freeMemory()
{
	//start of the user code
	for (i = 0; i<M / 2; i++)
	{
		free(check[i]);
		free(realmaze[i]);
	}

	free(check);
	free(realmaze);
	//end of usercode
}

/**************************************************************
* function	: bool writeFile(const char* filename)
*
* argument	: const char* filename - filename to be written
* return	: true if success, otherwise false
* remark	: Save user data to a file
****************************************************************/
bool writeFile(const char* filename)
{
	//start of the user code
	bool flag;

	flag = 0;

	return flag;
	//end of usercode
}

/************************************************************************
* fucntion	: void drawMain(CDC* pDC)
*
* argument	: CDC* pDC - device context object pointer
* remark	: Main drawing function. Called by CMFC_MainView::OnDraw()
*************************************************************************/
void drawMain(CDC *pDC)
{
	//if direct drawing is defined
#if defined(GRAPHICS_DIRECT)
	drawDirect(pDC);
	//if buffered drawing is defined
#elif defined(GRAPHICS_BUFFERED)
	drawBuffered();
#endif
}

/************************************************************************
* function	: static void drawDirect(CDC *pDC
*
* argument	: CDC* pDC - device context object pointer
* remark	: Direct drawing routines here.
*************************************************************************/
static void drawDirect(CDC *pDC)
{
	//begin of user code
	//Nothing to write currently.
	//end of user code
}

/***********************************************************************
* function	: static void drawBuffered()
*
* argument	: CDC* pDC -0 device object pointer
* remark	: Buffered drawing routines here.
************************************************************************/
static void drawBuffered()
{
	//start of the user code
	DrawBox_I(0, 0, N / 2, M / 2, 3, RGB(100, 0, 0)); 

	for (i = 0; i < M; i++)
	{
		if (i % 2&&i/2<M/2)
		{
			for (j = 0; j < N; j++)
			{
				if (j % 2&&j/2<N/2)
				{
					if (check[i / 2][j / 2].down&&i/2+1<M/2)//DrawBox�� �� ��ġ�� �ʰ�!
						DrawLine_I(j / 2, i / 2 + 1, j / 2 + 1, i / 2 + 1, 3, RGB(100, 0, 0));
					
					if (check[i / 2][j / 2].right&&j/2+1<N/2)//DrawBox�� �� ��ġ�� �ʰ�!
						DrawLine_I(j / 2 + 1, i / 2, j / 2 + 1, i / 2 + 1, 3, RGB(100, 0, 0));
				}
			}
		}
	}
	//end of the user code
}

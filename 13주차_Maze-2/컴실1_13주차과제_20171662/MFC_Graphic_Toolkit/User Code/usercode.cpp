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

	while (fscanf(fp, "%c", &tmp) != EOF) //먼저 width 파악!
	{
		if (tmp == '+'|| tmp == '-')
			N++;

		else//한줄 읽기 끝나면 반복문에서 나가기
			break; 
	}

	M++;
	//위에서 한줄 읽었으므로 일단 height 1 증가 시킴(M=1)

	while (fscanf(fp, "%c", &tmp) != EOF)  //enter나 끝이라면 한 줄이 끝났다는 뜻이므로 height 파악
	{
		if (tmp != '+'&& tmp != '-' && tmp != ' '&& tmp != '|')
			M++;
	}

	fclose(fp); 
	//파일을 처음부터 다시 읽어야 함. 파일을 끄고 다시 엶으로써 파일을 정상적으로 처음부터 읽게 한다.

	fp = fopen(filename, "r"); 

	realmaze = (char**)malloc(sizeof(char*)*(M + 2)); //위에서구한 N, M으로 2차원 배열 realmaze 생성
	for (i = 0; i < M + 2; i++)
		realmaze[i] = (char*)malloc(sizeof(char)*(N + 2));
	
	for (i = 0; i < M + 2; i++) //위에서 구한 N과 M으로 이중 for loop으로 한줄씩 읽어와서 realmaze 배열에 character들 저장
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
	//width/height 모두 구하기
	height = M / 2; 
	width = N / 2; 

	check = (maze**)malloc(sizeof(maze*)*height); 
	for (i = 0; i < height; i++)  //2차원 배열 생성 후 struct의 모든 원소들 0으로 초기화
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
	
	for (i = 0; i < M; i++) //이중 for loop를 통해 미로의 각 '칸'에서(i/j가 홀수일 때) 상하좌우 확인 후 선이 존재하는 방향은 1로 표시
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
					if (check[i / 2][j / 2].down&&i/2+1<M/2)//DrawBox와 선 겹치지 않게!
						DrawLine_I(j / 2, i / 2 + 1, j / 2 + 1, i / 2 + 1, 3, RGB(100, 0, 0));
					
					if (check[i / 2][j / 2].right&&j/2+1<N/2)//DrawBox와 선 겹치지 않게!
						DrawLine_I(j / 2 + 1, i / 2, j / 2 + 1, i / 2 + 1, 3, RGB(100, 0, 0));
				}
			}
		}
	}
	//end of the user code
}

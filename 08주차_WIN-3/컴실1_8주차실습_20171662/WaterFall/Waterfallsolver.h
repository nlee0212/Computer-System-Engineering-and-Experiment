#include "stdafx.h"

#define gXmin 100
#define gYmin 100
#define gXmax 600
#define gYmax 500
#define wWeight gXmax + gXmin
#define wHeight gYmax + gYmin + gYmin/2
#define lineSize 20
#define cirsize 2

void F1(void);
void F2(LPCTSTR fname);
void F3(void);
void F4(CDC* pDC);
void F5(CDC* pDC);
void F6(CDC* pDC);

typedef struct{
	float spx, spy;
	float epx, epy;
}line;

typedef struct{
	float x;
	float y;
}startp;

extern int which;
extern int num_p;
extern int good;
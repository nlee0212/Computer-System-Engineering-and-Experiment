#include "stdafx.h"
#include "Waterfallsolver.h"
#include <list>

int num_l;
int num_p;
int which=0;
int good=0;
int good2=0;
int good3=0;

std::list<startp> path;

line *pole;
startp *zum;

void F1(void){
	if(good==0){
		num_l = 0;
		num_p = 0;
	}

	if(good2==1){
		good2 = 0;
		path.clear();
		good3=0;
	}

}

void F2(LPCTSTR fname){
	int i;

	FILE* fp = fopen(fname,"r");

	fscanf(fp,"%d",&num_l);
	pole = new line[num_l];
	for(i=0;i<num_l;i++)
		fscanf(fp,"%f %f %f %f",&pole[i].spx, &pole[i].spy, &pole[i].epx, &pole[i].epy);
	
	fscanf(fp,"%d",&num_p);
	zum = new startp[num_p];
	for(i=0;i<num_p;i++)
		fscanf(fp,"%f %f",&zum[i].x, &zum[i].y);
	good = 1;
	fclose(fp);
}

void F3(void){
	int i=0, j=0, last, init=0, LF=0;
	startp wow, temp;
	float k;

	path.clear();

	wow.x = zum[which].x;
	wow.y = zum[which].y;
	
	path.push_back(wow);
		
	good2=1;
	
	while(1){
		for(i=0;i<num_l;i++){
			if((wow.x>pole[i].epx && wow.x<pole[i].spx) || (wow.x>pole[i].spx && wow.x<pole[i].epx)){
				k = (pole[i].epy-pole[i].spy)/(pole[i].epx-pole[i].spx)*(wow.x-pole[i].spx) + pole[i].spy;
				if(k<=wow.y){
					if(init==0){
						temp.y = k;
						temp.x = wow.x;
						last=i;
						init++;
					}
					else{
						if(k>=temp.y){
							temp.y = k;
							last=i;
						}
					}
					LF=1;
				}
			}
		}

		if(LF==0){
			temp.x = wow.x;
			temp.y = 0;
			path.push_back(temp);
			break;
		}
	
		else{
			path.push_back(temp);
		
			if(pole[last].epy>pole[last].spy){
				wow.x = pole[last].spx;
				wow.y = pole[last].spy;
			}	
			else{
				wow.x = pole[last].epx;
				wow.y = pole[last].epy;
			}
			path.push_back(wow);
			init=0;		LF=0;
		}
	}
}

void F4(CDC* pDC){
	int i;
	CPen MyPen;
	
	
	if(good==1){
		MyPen.CreatePen(PS_SOLID, 10, RGB(0,0,154));
		pDC->SelectObject(MyPen);
		pDC->MoveTo(gXmin, gYmin);	pDC->LineTo(gXmax, gYmin);
		pDC->MoveTo(gXmin, gYmax);	pDC->LineTo(gXmax, gYmax);
		MyPen.DeleteObject();

		MyPen.CreatePen(PS_SOLID, 5, RGB(100, 0 ,0));
		pDC->SelectObject(MyPen);
		for(i=0;i<num_l;i++){
			pDC->MoveTo(gXmin + pole[i].spx*lineSize, gYmax - pole[i].spy*lineSize); 
			pDC->LineTo(gXmin + pole[i].epx*lineSize, gYmax - pole[i].epy*lineSize);
		}
		MyPen.DeleteObject();

		MyPen.CreatePen(PS_SOLID, 10, RGB(0, 0 ,0));
		pDC->SelectObject(MyPen);
		for(i=0;i<num_p;i++){
			pDC->Ellipse(gXmin + (int)zum[i].x*lineSize - cirsize,
						gYmax - (int)zum[i].y*lineSize - cirsize,
						gXmin + (int)zum[i].x*lineSize + cirsize,
						gYmax - (int)zum[i].y*lineSize + cirsize);
		}
		MyPen.DeleteObject();
	}
}

void F5(CDC* pDC){
	int i;
	CPen MyPen;

	if(good==1){
		for(i=0;i<num_p;i++){
				
			if(i==which){
				MyPen.CreatePen(PS_SOLID, 10, RGB(217, 22 ,22));
				pDC->SelectObject(MyPen);
		
				pDC->Ellipse(gXmin + (int)zum[i].x*lineSize - cirsize,
							gYmax - (int)zum[i].y*lineSize - cirsize,
							gXmin + (int)zum[i].x*lineSize + cirsize,
							gYmax - (int)zum[i].y*lineSize + cirsize);
				
				MyPen.DeleteObject();
			}
			else{
				MyPen.CreatePen(PS_SOLID, 10, RGB(0, 0 ,0));
				pDC->SelectObject(MyPen);
		
				pDC->Ellipse(gXmin + (int)zum[i].x*lineSize - cirsize,
							gYmax - (int)zum[i].y*lineSize - cirsize,
							gXmin + (int)zum[i].x*lineSize + cirsize,
							gYmax - (int)zum[i].y*lineSize + cirsize);
				
				MyPen.DeleteObject();
			}	
		}
	}
}

void F6(CDC* pDC){
	
	CPen MyPen;
	std::list<startp>::iterator idx;
	
	if(good==1 && good2==1){
		MyPen.CreatePen(PS_SOLID, 5, RGB(0,0,154));
		pDC->SelectObject(MyPen);

		pDC->MoveTo(gXmin + (path.begin()->x)*lineSize, gYmax - (path.begin()->y)*lineSize);				
		for(idx=path.begin();idx!=path.end();idx++){
			pDC->LineTo(gXmin + (idx->x)*lineSize, gYmax - (idx->y)*lineSize);
		}
		MyPen.DeleteObject();
		path.clear();
	}
}
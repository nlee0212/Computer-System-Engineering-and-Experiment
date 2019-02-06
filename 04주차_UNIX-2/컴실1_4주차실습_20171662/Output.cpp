#include "Header.h"

void Print_Line( char *line, int *Count, int *B_Flag ) {
	int i, N_Blanks, N_Chars=0, Start=0;//N_Chars 와 Start 변수가 초기화되지 않았음. 0으로 초기값을 설정해야함.

	Get_Blanks_Chars( line, Start, &N_Blanks, &N_Chars );
	while ( N_Chars != 0 ) {
		if ( (*B_Flag == 1) && ((*Count + N_Chars + 1) <= LIMIT) ) {

			/* In this part, N_Blanks == 0 in order that L1 and L2 should be merged.
			* "N_Blanks != 0" means that L2 is written at the next line.
			*/
			if ( N_Blanks != 0 ) {
				printf("Something Wrong!\n");
				exit(-1);
			}

			putchar(' ');
			*B_Flag = 0;
			for ( i = Start; i < Start + N_Chars; i++ ) {//반복문 제한 설정이 잘못됨.
				putchar(line[i]);
			}
			Start = Start + N_Chars;
			*Count = *Count + N_Chars + 1;
			Get_Blanks_Chars( line, Start, &N_Blanks, &N_Chars );
		}
		else if ( (*Count + N_Blanks + N_Chars) <= LIMIT ) {
			for ( i = Start; i < Start + N_Blanks + N_Chars; i++ ) {//반복문 제한 설정이 잘못됨.
				putchar(line[i]);
			}
			Start = Start + N_Blanks + N_Chars;
			*Count = *Count + N_Blanks + N_Chars;
			Get_Blanks_Chars( line, Start, &N_Blanks, &N_Chars );
		}
		else {
			if ( *Count == 0 ) {
				for ( i = Start; i < Start + N_Blanks + N_Chars; i++ ) {//반복문 제한 설정이 잘못됨.
					putchar(line[i]);
				}
				Start = Start + N_Blanks + N_Chars;
				putchar('\n');
				Get_Blanks_Chars( line, Start, &N_Blanks, &N_Chars );
			}
			else {
				putchar('\n');
				*B_Flag = 0;
				for ( i = Start + N_Blanks; i < Start + N_Blanks + N_Chars ; i++ ) {//반복문 제한 설정이 잘못됨.
					putchar(line[i]);
				}
				Start = Start + N_Blanks + N_Chars;
				*Count = N_Chars;
				Get_Blanks_Chars( line, Start, &N_Blanks, &N_Chars );
			}
		}
	}
}

#include "Header.h"

void Remove_Blanks_At_The_End( char *line ) {
	int i, k, newline_flag = 0;

	for ( k = 0; ; k++ ) {
		if ( line[k] == '\n' ) {
			newline_flag = 1;
			break;
		}
		else if ( line[k] == '\0' ) {
			break;
		}
	}
	for ( i = k-1; i >= 0; i-- ) {//i의 초기값 설정이 잘못됨.
		if ( line[i] != ' ' ) {
			break;
		}
	}
	if ( newline_flag == 1 ) {
		line[i+1] = '\n';//엔터의 삽입 지점의 설정이 잘못됨.
		line[i+2] = '\0';//NULL의 삽입 지점의 설정이 잘못됨.
	}
	else {
		line[i+1] = '\0';//NULL의 삽입 지점의 설정이 잘못됨.
	}
}

void Get_Blanks_Chars( char *line, int Start, int *N_Blanks, int *N_Chars ) {
	int i, blank_flag=0;//blank_flag 변수의 초기화가 되어있지 않음. 0으로 초기값 설정을 해야함.
	
	*N_Blanks=0;//변수의 초기화 과정 필요.
	*N_Chars=0;//변수의 초기화 과정 필요.

	for ( i = Start; ; i++ ) {
		if ( (line[i] == '\n') || (line[i] == '\0') ) {
			break;
		}
		else if ( line[i] == ' ' ) {
			if ( blank_flag == 0 ) {
				++(*N_Blanks);
			}
			else {
				break;
			}
		}
		else {
			blank_flag = 1;
			++(*N_Chars);
		}
	}
}


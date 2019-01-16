#include <iostream>
#include "str.h"
#include <string.h>
#include <stdlib.h>

using namespace std;

/*
private
char *str; // string의 내용.
int len; // string의 길이.

public
Str(int leng); // leng 은 string의 길이.
Str(const char *neyong); // neyong은 초기화할 내용이 들어감.
~Str(); // 소멸자.
int length(void); // string의 길이를 리턴하는 함수.
char *contents(void); // string의 내용을 리턴하는 함수.
int compare(class Str& a); // a의 내용과 strcmp.
int compare(const char *a); // a의 내용과 strcmp.
void operator=(const char *a); // string의 값을 대입.
void operator=(class Str& a); // Str의 내용을 대입.
*/


Str::Str(int leng) {
	if (leng < 0)
		cout << "ERROR!" << endl;

	else
	{
		str = new char(leng+1);
		len = leng;
	}
}

Str::Str(const char *neyong) {

	if (strlen(neyong) < 0)
		cout << "ERROR!" << endl;

	else
	{
		len = strlen(neyong);
		str = new char[len+1];
		strcpy(str, neyong);
	}
}

Str::~Str() {
	delete (str);
}

int Str::length(void) {
	return len;
}

char* Str::contents(void) {
	return str;
}

int Str::compare(class Str& a) {
	return strcmp(str,a.contents());
}

int Str::compare(const char *a) {
	return strcmp(str, a);
}

void Str::operator=(const char *a) {
	if (strlen(a) >= 0)
	{
		delete[] str;
		len = strlen(a);
		str = new char[len+1];
		strcpy(str, a);
	}

	else
		cout << "ERROR!" << endl;
}

void Str::operator=(class Str& a) {
	if (a.length() >= 0)
	{
		delete(str);
		len = a.length();
		str = new char[len+1];
		strcpy(str, a.contents());
	}

	else
		cout << "ERROR!" << endl;
}
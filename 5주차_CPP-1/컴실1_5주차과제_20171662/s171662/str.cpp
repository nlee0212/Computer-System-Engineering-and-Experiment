#include <iostream>
#include "str.h"
#include <string.h>
#include <stdlib.h>

using namespace std;

/*
private
char *str; // string�� ����.
int len; // string�� ����.

public
Str(int leng); // leng �� string�� ����.
Str(const char *neyong); // neyong�� �ʱ�ȭ�� ������ ��.
~Str(); // �Ҹ���.
int length(void); // string�� ���̸� �����ϴ� �Լ�.
char *contents(void); // string�� ������ �����ϴ� �Լ�.
int compare(class Str& a); // a�� ����� strcmp.
int compare(const char *a); // a�� ����� strcmp.
void operator=(const char *a); // string�� ���� ����.
void operator=(class Str& a); // Str�� ������ ����.
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
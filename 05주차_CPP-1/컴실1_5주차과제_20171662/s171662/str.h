#ifndef __STR__
#define __STR__

class Str
{
	private:
		char *str; // string�� ����.
		int len; // string�� ����.

	public:
		Str(int leng); // leng �� string�� ����.
		Str(const char *neyong); // neyong�� �ʱ�ȭ�� ������ ��.
		~Str(); // �Ҹ���.
		int length(void); // string�� ���̸� �����ϴ� �Լ�.
		char *contents(void); // string�� ������ �����ϴ� �Լ�.
		int compare(class Str& a); // a�� ����� strcmp.
		int compare(const char *a); // a�� ����� strcmp.
		void operator=(const char *a); // string�� ���� ����.
		void operator=(class Str& a); // Str�� ������ ����.
};

#endif
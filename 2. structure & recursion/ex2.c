#pragma warning(disable: 4996)
#include <stdio.h>

struct st
{
	int a;
	char ch;
};

int main()
{
	printf("�й� 201520908 �̸� ������\n\n");

	struct st obj;
	struct st *stobj = &obj;

	stobj->a = 5;
	stobj->ch = 'a';

	printf("\n [%d] [%c]\n", stobj->a, stobj->ch);

	getchar();

	return 0;
}
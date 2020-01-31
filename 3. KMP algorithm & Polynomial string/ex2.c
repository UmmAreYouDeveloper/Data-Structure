#include <stdio.h>
#include <string.h>

int failure[100] = { 0, };
void fail(char *pat);
int pmatch(char *string, char*pat);

void main()
{
	char string[] = "Ajou university is the best in the world.";
	char pat[] = "abc";

	fail(pat);
	int matched_count = pmatch(string, pat);

	if (matched_count == -1)
	{
		printf("No pattern found");
	}
	else
	{
		printf("Index of the first pattern found : %d", matched_count);
	}

	getchar();
}

void fail(char *pat)
{
	int i, j;
	int n = strlen(pat);
	failure[0] = -1;

	for (j = 1; j < n; j++)
	{
		i = failure[j - 1];
		if(pat[j] != pat[i + 1] && i >= 0) i = failure[i]; // while() -> if() �� ��� // f(18)=8 �̸� f(8) = �� �� ���� �ؼ� ���� if���� �̿��
		if (pat[j] != pat[i + 1]) failure[j] = i + 1; // f(8)�� �� pat[19]�� pat[8] �� ���ؼ� pat[8] =-1�̸� �տ� �� �ʿ����, pat[8]=x��� ���ϰ� ���ڿ��� 0 ~ x+1 �� 19-x ~ 19 �� ���ϸ�Ī �ٽý��� 
		else failure[j] = -1;
	}
}

int pmatch(char *string, char*pat)
{
	int i = 0;
	int j = 0;
	int lens = strlen(string);
	int lenp = strlen(pat);

	while (i < lens && j < lenp)
	{
		if (string[i] == pat[j]) { i++; j++;}
		else if (j == 0) i++; // string[i] != pat[j] �� if���� ���� �ʰ� string �̵�
		else j = failure[j - 1] + 1; // string[i] == pat[j] �϶� �����Լ��� +1 = ��ġ�� ��
	}
	return (j == lenp ? i - lenp : -1);
}
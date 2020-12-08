#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void fun(char *st, int size, char *str) {
	int j = 0;

	for (int i = size - 1; i >= 0; i--) {
		str[j] = st[i];
		j++;
	}
	str[size] = '\n';

	for (int i = 0; i < size; i++)
		printf("%c", str[i]);
	printf("\n");
}

void main() {
	char *st[100];
	char *str[100];
	printf("영문자 입력 : ");
	gets(st);

	int size = strlen(st);

	printf("변환된 문자 : ");

	fun(&st, size, &str);
	/*for (int i = 0; i < size; i++)
		printf("%c", str[i]);
	printf("\n");
	*/

	return;
}
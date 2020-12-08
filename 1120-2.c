#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n, n2, temp;

	printf("천만이하의 수 입력 : ");
	scanf("%d", &n);

	temp = (int)n / 10000;
	n2 =n % 10000;
	printf("%d만 ", temp);

	if (n2 != 0) {
		temp = (int)n2 / 1000;
		n2 = n % 1000;
		printf("%d천 ", temp);
	}
	if (n2 != 0) {
		temp = (int)n2 / 100;
		n2 = n % 100;
		printf("%d백 ", temp);
	}
	if (n2 != 0) {
		temp = (int)n2 / 10;
		n2 = n % 10;
		printf("%d십 ", temp);
	}
	if (n2 != 0) {
		printf("%d입니다. ", n2);
	}
	printf("\n");

	return;
}
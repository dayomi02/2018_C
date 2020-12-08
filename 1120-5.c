#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int f(int n) {
	return (n - 32) * 5 / 9;
}

int main() {
	int n;
	printf("È­¾¾ ÀÔ·Â : ");
	scanf("%d", &n);
	printf("¼·¾¾ ¿Âµµ : %d\n", f(n));
}
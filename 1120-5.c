#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int f(int n) {
	return (n - 32) * 5 / 9;
}

int main() {
	int n;
	printf("ȭ�� �Է� : ");
	scanf("%d", &n);
	printf("���� �µ� : %d\n", f(n));
}
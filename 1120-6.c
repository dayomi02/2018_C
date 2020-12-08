#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int pi(int n);
int fac(int n);

int pi(int n) {
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += fac(i);
	}
	return sum;
}

int fac(int n) {
	int sum = 1;
	for (int i = 1; i <= n; i++)
		sum *= i;
	return sum;
}

int main() {
	int n,sum=0;

	printf("마지막 수 입력 : ");
	scanf("%d", &n);

	sum = pi(n);

	printf("1!");
	for (int i = 2; i <= n; i++) {
		printf(" + %d!", i);
	}
	printf(" = %d \n",sum);
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int two(int s,int n) {
	int ten;
	if (s == 0)
		return 0;
	else {
		ten = pow(2.0, n);
		return ten;
	}
}
int main() {
	int n, n2, temp, sum=0;

	printf("2진수 입력(8자리) : ");
	scanf("%d", &n);

	temp = n / 10000000;
	n2 = n % 10000000;
	sum += two(temp,7);

	temp = n2 / 1000000;
	n2 = n % 1000000;
	sum += two(temp,6);

	temp = n2 / 100000;
	n2 = n % 100000;
	sum += two(temp,5);

	temp = n2 / 10000;
	n2 = n % 10000;
	sum += two(temp,4);
	
	temp = n2 / 1000;
	n2 = n % 1000;
	sum += two(temp,3);
		
	temp = n2 / 100;
	n2 = n % 100;
	sum += two(temp,2);

	temp = n2 / 10;
	n2 = n % 10;
	sum += two(temp,1);
	
	sum += two(n2,0);

	printf("10진수 : %d\n", sum);
}
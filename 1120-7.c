#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int fun(int n) {
	int j;
	for (j = 2; j < n; j++) {
		if ((n % j) == 0)
			break;
	}
	if (n == j)
		return n;
	else
		return 0;
}
void main() {
	int n, sum = 0;

	printf("소수를 구하려는 최종 숫자를 입력하세요. ");
	scanf("%d", &n);

	for (int i = 2; i <= n; i++) {
		int k = 0;
		k = fun(i);
		if (k != 0) {
			printf("%d ", k);
			sum++;
		}
		else
			continue;

	}
	printf("\n2 ~ %d까지의 소수 갯수 : %d\n", n, sum);

}
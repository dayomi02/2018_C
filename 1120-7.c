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

	printf("�Ҽ��� ���Ϸ��� ���� ���ڸ� �Է��ϼ���. ");
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
	printf("\n2 ~ %d������ �Ҽ� ���� : %d\n", n, sum);

}
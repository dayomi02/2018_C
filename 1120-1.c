#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main() {
	int n, max = 0, min = 100, a = 0, b = 0, c = 0, d = 0, e = 0;

	printf("���� �Է� : ");
	while (1) {
		scanf("%d", &n);
		if (n >= 0 && n <= 100) {
			switch ((int)n / 10) {
			case 10:case 9 :
				a++; break;
			case 8:
				b++; break;
			case 7:
				c++; break;
			case 6:
				d++; break;
			default:
				e++;
			}
			if (max < n)
				max = n;
			else if (min > n)
				min = n;
		}
		else
			break;
	}
	
	printf("90�� �̻� : ");
	for (int i = 1; i <= a; i++) printf("*"); printf("\n");
	printf("80�� �� : ");
	for (int i = 1; i <= b; i++) printf("*"); printf("\n");
	printf("70�� �� : ");
	for (int i = 1; i <= c; i++) printf("*"); printf("\n");
	printf("60�� �� : ");
	for (int i = 1; i <= d; i++) printf("*"); printf("\n");
	printf("60�� �̸� : ");
	for (int i = 1; i <= e; i++) printf("*"); printf("\n");
	printf("�ְ����� : %d\n", max);
	printf("�������� : %d\n", min);

	return;
}
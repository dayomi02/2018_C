#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main() {
	int n, max = 0, min = 100, a = 0, b = 0, c = 0, d = 0, e = 0;

	printf("점수 입력 : ");
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
	
	printf("90점 이상 : ");
	for (int i = 1; i <= a; i++) printf("*"); printf("\n");
	printf("80점 대 : ");
	for (int i = 1; i <= b; i++) printf("*"); printf("\n");
	printf("70점 대 : ");
	for (int i = 1; i <= c; i++) printf("*"); printf("\n");
	printf("60점 대 : ");
	for (int i = 1; i <= d; i++) printf("*"); printf("\n");
	printf("60점 미만 : ");
	for (int i = 1; i <= e; i++) printf("*"); printf("\n");
	printf("최고점수 : %d\n", max);
	printf("최저점수 : %d\n", min);

	return;
}
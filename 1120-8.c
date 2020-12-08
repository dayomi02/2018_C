#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//#define STU_NUM
struct Student {
	int score[3];
	int max;
	int lank;
};

int main() {
	int num = 0;

	printf("학생수 입력 : ");
	scanf("%d", &num);

	struct Student *st = (struct Student *)malloc(sizeof(struct Student)*num);
	
	for (int i = 0; i < num; i++) {
		st[i].max = 0;
		for (int j = 0; j < 3; j++) {
			st[i].score[j] = 0;
			while (1) {
				printf("점수 %d 입력: ", j + 1);
				scanf("%d", &st[i].score[j]);
				if (st[i].score[j] < 0 || st[i].score[j] > 100)
					printf("다시 입력하세요.====> ");
				else 
					break;
			}
		}
		printf("\n");
	}
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < 3; j++) {
			if (st[i].score[j] > st[i].score[j+1]) {
				st[i].max = st[i].score[j];
			}
		}
	}
			for (int k = 0; k < num; k++) {
				switch ((int)st[k].max / 10) {
					case 10: case 9:
						st[k].lank = 5; break;
					case 8:
						st[k].lank = 4; break;
					case 7:
						st[k].lank = 3; break;
					case 6:
						st[k].lank = 2; break;
					default:
						st[k].lank = 1;
				}
			}
	for (int i = 0; i < num; i++) {
		printf("%3d", i + 1);
		for (int j = 0; j < 3; j++) {
			printf("%6d", st[i].score[j]);
		}
		printf("%4d\n",st[i].lank);
	}
}
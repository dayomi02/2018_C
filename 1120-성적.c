//#define stu 2 //#define(상수처리), const(상수처리)
#define subj 2
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

char sub[5][6] = { "국어","영어","수학","C언어","JAVA" };
int sum_sum=0;          //총점의 총점
float sum_avg=0;          //총점의 평균
int score_sum[subj] = { 0 };  //과목별 총점
float score_avg[subj]={0};  //과목별 평균
FILE *fp;

struct Student {
	char id[5];
	char name[11];
	int score[subj + 1]; //점수+총점
	float avg;
	char level;
	int lank;//순위
};

void print(struct Student ss) {  //내용을 출력하는 구조체 함수
	printf("%-10s %-6s", ss.id, ss.name);
	fprintf(fp, "%-10s %-6s", ss.id, ss.name);
	for (int i = 0; i < subj; i++) {
		printf("%7d", ss.score[i]);
		fprintf(fp, "%7d", ss.score[i]);
	}
		
	printf("%7d%8.2f%7c%7d\n", ss.score[subj], ss.avg, ss.level, ss.lank);
	fprintf(fp,"%7d%8.2f%7c%7d\n", ss.score[subj], ss.avg, ss.level, ss.lank);
}

void printTotal() {
	printf("                ");
	fprintf(fp,"                ");
	for (int i = 0; i < subj; i++) {
		printf("%7d", score_sum[i]);
		fprintf(fp,"%7d", score_sum[i]);
	}
	printf("%7d\n", sum_sum);
	fprintf(fp,"%7d\n", sum_sum);

	printf("                ");
	fprintf(fp, "                ");
	for (int i = 0; i < subj; i++) {
		printf("%8.2f", score_avg[i]);	
		fprintf(fp,"%8.2f", score_avg[i]);
	}
	printf("%8.2f\n", sum_avg);
	fprintf(fp,"%8.2f\n", sum_avg);
}

void line(int data) { //구분 줄 만들기
	for (int i = 1; i <= data + 20; i++) {
		printf("-"); fprintf(fp,"-");
	}
	printf("\n"); fprintf(fp,"\n");
}

void input(struct Student *sttemp) {
	sttemp->score[subj] = 0;
	printf("\n학번 입력 : ");
	scanf("%s", sttemp->id);
	printf("이름 입력 : ");
	scanf("%s", sttemp->name);

	for (int j = 0; j < subj; j++) {
		while (1) {
			sttemp->score[j] = 0;
			printf("%s점수 입력 : ", sub[j]);
			scanf("%d", &sttemp->score[j]);
			score_sum[j] += sttemp->score[j];  //과목별 총점

			if (sttemp->score[j] > 100 || sttemp->score[j] < 0)//(!(점수>=0 && 점수<=100))
				printf("%s 에러\n", sub[j]);
			else {
				sttemp->score[subj] += sttemp->score[j];  //총점
				break;
			}
		}
	}
	sum_sum += sttemp->score[subj];          //총점의 총점
}

void process (struct Student *pro) {
	(*pro).avg = (float)(*pro).score[subj] / subj;

	switch ((int)((*pro).avg / 10)) {
	case 10: case 9:
		(*pro).level = 'A'; break;
	case 8:
		(*pro).level = 'B'; break;
	case 7:
		(*pro).level = 'C'; break;
	case 6:
		(*pro).level = 'D'; break;
	default:
		(*pro).level = 'F';
	}//switch
}

void main() {
	
	fp = fopen("F:/Studentpro.text", "w");
	if (fp == NULL) {
		printf("파일을 열 수 없습니다.");
		exit(1);
	}

	int stu;
	printf("몇 명을 입력하세겠습니까?\n->");
	scanf("%d", &stu);

	struct Student *st;

	st = (struct Student *)malloc(sizeof(struct Student)*stu); //동적으로 메모리 할당, (struct Student *)을 써주면 가독성이 높아짐

	float totalavg[subj + 1] = { 0 };
	
	for (int i = 0; i<stu; i++) {
		input(st + i);
		process(st + i);
	}//for(i)    //인원수대로 입력

	for (int i = 0; i < stu; i++) {  
		st[i].lank = 1;
		for (int j = 0; j < stu; j++) {
			if (st[i].avg < st[j].avg)
				st[i].lank++;
		}
	}     //순위
	
	sum_avg = (float)sum_sum/stu;          //총점의 평균

	for (int k=0;k<subj;k++)
		score_avg[k] = (float)score_sum[k]/stu;  //과목별 평균

	printf("====================================================================================\n");
	fprintf(fp, "====================================================================================\n");
	printf("학번       이름     국어   영어   총점   평균      등급   등수\n");
	fprintf(fp,"학번       이름     국어   영어   총점   평균      등급   등수\n");
	printf("====================================================================================\n");
	fprintf(fp,"====================================================================================\n");

	for (int i = 0; i < stu; i++) {
		print(st[i]);
		line(7 * subj + 50);
	}

	printTotal();	
	fclose(fp);
}//main
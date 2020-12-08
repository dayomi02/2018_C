//#define stu 2 //#define(���ó��), const(���ó��)
#define subj 2
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

char sub[5][6] = { "����","����","����","C���","JAVA" };
int sum_sum=0;          //������ ����
float sum_avg=0;          //������ ���
int score_sum[subj] = { 0 };  //���� ����
float score_avg[subj]={0};  //���� ���
FILE *fp;

struct Student {
	char id[5];
	char name[11];
	int score[subj + 1]; //����+����
	float avg;
	char level;
	int lank;//����
};

void print(struct Student ss) {  //������ ����ϴ� ����ü �Լ�
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

void line(int data) { //���� �� �����
	for (int i = 1; i <= data + 20; i++) {
		printf("-"); fprintf(fp,"-");
	}
	printf("\n"); fprintf(fp,"\n");
}

void input(struct Student *sttemp) {
	sttemp->score[subj] = 0;
	printf("\n�й� �Է� : ");
	scanf("%s", sttemp->id);
	printf("�̸� �Է� : ");
	scanf("%s", sttemp->name);

	for (int j = 0; j < subj; j++) {
		while (1) {
			sttemp->score[j] = 0;
			printf("%s���� �Է� : ", sub[j]);
			scanf("%d", &sttemp->score[j]);
			score_sum[j] += sttemp->score[j];  //���� ����

			if (sttemp->score[j] > 100 || sttemp->score[j] < 0)//(!(����>=0 && ����<=100))
				printf("%s ����\n", sub[j]);
			else {
				sttemp->score[subj] += sttemp->score[j];  //����
				break;
			}
		}
	}
	sum_sum += sttemp->score[subj];          //������ ����
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
		printf("������ �� �� �����ϴ�.");
		exit(1);
	}

	int stu;
	printf("�� ���� �Է��ϼ��ڽ��ϱ�?\n->");
	scanf("%d", &stu);

	struct Student *st;

	st = (struct Student *)malloc(sizeof(struct Student)*stu); //�������� �޸� �Ҵ�, (struct Student *)�� ���ָ� �������� ������

	float totalavg[subj + 1] = { 0 };
	
	for (int i = 0; i<stu; i++) {
		input(st + i);
		process(st + i);
	}//for(i)    //�ο������ �Է�

	for (int i = 0; i < stu; i++) {  
		st[i].lank = 1;
		for (int j = 0; j < stu; j++) {
			if (st[i].avg < st[j].avg)
				st[i].lank++;
		}
	}     //����
	
	sum_avg = (float)sum_sum/stu;          //������ ���

	for (int k=0;k<subj;k++)
		score_avg[k] = (float)score_sum[k]/stu;  //���� ���

	printf("====================================================================================\n");
	fprintf(fp, "====================================================================================\n");
	printf("�й�       �̸�     ����   ����   ����   ���      ���   ���\n");
	fprintf(fp,"�й�       �̸�     ����   ����   ����   ���      ���   ���\n");
	printf("====================================================================================\n");
	fprintf(fp,"====================================================================================\n");

	for (int i = 0; i < stu; i++) {
		print(st[i]);
		line(7 * subj + 50);
	}

	printTotal();	
	fclose(fp);
}//main
/* 2151299 信16 苏家铭*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#define number 10

void input(char xuehao[number][8],char xingming[number][9], int grade[number]) {
	int i;
	
	for (i = 0; i < number; i++) {
		printf("请输入第%d个人的学号、姓名、成绩\n", i+1);
		scanf("%s %s %d", &xuehao[i],&xingming[i],&grade[i]);
	}
}
void order_down_xuehao(char xuehao[number][8], char xingming[number][9], int grade[number]) {
	int i,j, temp3;
	char temp1[8],temp2[9];
	for (i = 0; i < number-1; i++) {
		for (j = 0; j < number - (i + 1); j++) {
			if (strcmp(xuehao[j], xuehao[j+1]) < 0) {
				strcpy(temp1, xuehao[j]);
				strcpy(xuehao[j], xuehao[j+1]);
				strcpy(xuehao[j+1], temp1);

				strcpy(temp2, xingming[j]);
				strcpy(xingming[j], xingming[j + 1]);
				strcpy(xingming[j + 1], temp2);

				temp3=grade[j];
				grade[j]=grade[j + 1];
				grade[j + 1]=temp3;
			}
		}
	}
}
void output(char xuehao[number][8], char xingming[number][9], int grade[number]) {
	printf("\n及格名单(学号降序):\n");
	int i;
	for (i = 0; i < number; i++) {
		if (grade[i]>=60) {
			printf("%s %s %d\n", &xingming[i], &xuehao[i], grade[i]);
		}
	}
}
int main() {

	char xuehao[number][8], xingming[number][9];
	int grade[number];
	input(xuehao, xingming, grade);
	order_down_xuehao(xuehao, xingming, grade);
	output(xuehao, xingming, grade);
	return 0;
}
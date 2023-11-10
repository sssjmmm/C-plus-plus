/* 信16 2151299 苏家铭 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int zeller(int y, int m, int d)
{
	int c, w;
	if (m != 1 && m != 2) {
		c = y / 100;
		y = y - c * 100;
	}
	if (m == 1) {
		m = 13;
		y = y - 1;
		c = y / 100;
		y = y - c * 100;
	}
	if (m == 2) {
		m = 14;
		y = y - 1;
		c = y / 100;
		y = y - c * 100;
	}
	w = y + y / 4 + c / 4 - 2 * c + (13 * (m + 1) / 5) + d - 1;
	if (w < 0)
		w = w % 7 + 7;
	else if (w > 0)
		w = w % 7;
	return w;
}

void daxie(int w)
{
	switch (w) {
		case 0:
			printf("日");
			break;
		case 1:
			printf("一");
			break;
		case 2:
			printf("二");
			break;
		case 3:
			printf("三");
			break;
		case 4:
			printf("四");
			break;
		case 5:
			printf("五");
			break;
		case 6:
			printf("六");
			break;
	}
}

int main()
{
	int year, month, day, a, k,ret;
	while (1) {
		a = 1;
		printf("请输入年[1900-2100]、月、日：\n");
		ret=scanf("%d %d %d",&year,&month,&day);
		while (ret!=3) {
			while (getchar() != '\n');
			printf("输入错误，请重新输入\n");
			printf("请输入年[1900-2100]、月、日：\n");
			scanf("%d %d %d", &year, &month, &day);
		}
		if (year < 1900 || year>2100) {//year
			printf("年份不正确，请重新输入\n");
			a = 0;
		}
		else if ((year >= 1900 && year <= 2100) && (month < 1 || month > 12)) {//month
			printf("月份不正确，请重新输入\n");
			a = 0;
		}
		else if ((year >= 1900 && year <= 2100) && (month >= 1 || month <= 12)) {//day
			if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
				if (month == 2 && day > 29) {
					printf("日不正确，请重新输入\n");
					a = 0;
				}
			}
			if (month == 1 && (day <= 0 || day > 31)) {
				printf("日不正确，请重新输入\n");
				a = 0;
			}
			else if (month == 2 && !(year % 4 == 0 && year % 100 != 0 || year % 400 == 0) && (day <= 0 || day > 28)) {
				printf("日不正确，请重新输入\n");
				a = 0;
			}
			else if (month == 3 && (day <= 0 || day > 31)) {
				printf("日不正确，请重新输入\n");
				a = 0;
			}
			else if (month == 4 && (day <= 0 || day > 30)) {
				printf("日不正确，请重新输入\n");
				a = 0;
			}
			else if (month == 5 && (day <= 0 || day > 31)) {
				printf("日不正确，请重新输入\n");
				a = 0;
			}
			else if (month == 6 && (day <= 0 || day > 30)) {
				printf("日不正确，请重新输入\n");
				a = 0;
			}
			else if (month == 7 && (day <= 0 || day > 31)) {
				printf("日不正确，请重新输入\n");
				a = 0;
			}
			else if (month == 8 && (day <= 0 || day > 31)) {
				printf("日不正确，请重新输入\n");
				a = 0;
			}
			else if (month == 9 && (day <= 0 || day > 30)) {
				printf("日不正确，请重新输入\n");
				a = 0;
			}
			else if (month == 10 && (day <= 0 || day > 31)) {
				printf("日不正确，请重新输入\n");
				a = 0;
			}
			else if (month == 11 && (day <= 0 || day > 30)) {
				printf("日不正确，请重新输入\n");
				a = 0;
			}
			else if (month == 12 && (day <= 0 || day > 31)) {
				printf("日不正确，请重新输入\n");
				a = 0;
			}
		}
		if (a == 1 && (year >= 1900 && year <= 2100) && (month >= 1 || month <= 12))
			break;
	}
	k = zeller(year, month, day);
	printf("星期");
	daxie(k);
	printf("\n");
	return 0;
}
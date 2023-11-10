/* 信16 2151299 苏家铭 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int retx,ret,year, month, day, y, x, n, a;
	y = 1;
	n = 1;
	a = 0;
	day = 0;
	while (1) {
		printf("请输入年份(2000-2030)和月份(1-12) :");
		ret = scanf("%d %d", &year,&month); 
		while (ret != 2) {
			while (getchar() != '\n');
			printf("输入非法，请重新输入\n请输入年份(2000-2030)和月份(1-12) :");
			ret = scanf("%d %d", &year, &month);
		}
		if (year < 2000 || year>2030 || month > 12 || month < 1) 
			printf("输入非法，请重新输入\n");
		if (year >= 2000 && year <= 2030 && month >= 1 && month <= 12)
			break;	
	}
	while (1) {
		printf("请输入%d年%d月1日的星期(0 - 6表示星期日 - 星期六) :",year,month);
		retx=scanf("%d", &day);
		while (retx != 1) {
			while (getchar() != '\n');
			printf("输入非法，请重新输入\n请输入%d年%d月1日的星期(0 - 6表示星期日 - 星期六) :",year,month);
			retx = scanf("%d", &day);
		}
		if (day > 6 || day < 0)
			printf("输入非法，请重新输入\n");
		if (day >= 0 && day <= 6)
			break;
	}
	printf("\n");
	printf("%d年%d月的月历为:\n", year, month);
	printf("星期日  星期一  星期二  星期三  星期四  星期五  星期六\n");

	if (month == 1)
		n = 31;
	else if (month == 2)
		n = 28;
	else if (month == 3)
		n = 31;
	else if (month == 4)
		n = 30;
	else if (month == 5)
		n = 31;
	else if (month == 6)
		n = 30;
	else if (month == 7)
		n = 31;
	else if (month == 8)
		n = 31;
	else if (month == 9)
		n = 30;
	else if (month == 10)
		n = 31;
	else if (month == 11)
		n = 30;
	else if (month == 12)
		n = 31;
	if ((year % 4 == 0 && year % 100 != 0 || year % 400 == 0) && month == 2)
		n = 29;

	if (day == 0) {

		x = 0;
		while (n >= 1) {
			if ((a > 1 && a < 8) || (a > 8 && a < 15) || (a > 15 && a < 22) || (a > 22 && a < 29) || (a > 29 && a < 36) || (a > 36 && a < 42)) {
				printf("%8d",y);
			}
			else if ((a % 8 == 0 || a % 15 == 0 || a % 22 == 0 || a % 29 == 0 || a % 36 == 0 || a % 43 == 0) && (y != 1)) {
				printf("\n");
				printf("%4d",y);
			}
			else if (y == 1)
				printf("%4d",y);
			n--;
			y++;
			a = y + x;
		}
	}
	else if (day == 1) {
		printf("        ");
		x = 1;
		while (n >= 1) {
			if ((a > 1 && a < 8) || (a > 8 && a < 15) || (a > 15 && a < 22) || (a > 22 && a < 29) || (a > 29 && a < 36) || (a > 36 && a < 42)) {
				printf("%8d",y);
			}
			else if ((a % 8 == 0 || a % 15 == 0 || a % 22 == 0 || a % 29 == 0 || a % 36 == 0 || a % 43 == 0) && (y != 1)) {
				printf("\n");
				printf("%4d",y);
			}
			else if (y == 1)
				printf("%4d",y);
			n--;
			y++;
			a = y + x;
		}
	}
	else if (day == 2) {
		printf("                ");
		x = 2;
		while (n >= 1) {
			if ((a > 1 && a < 8) || (a > 8 && a < 15) || (a > 15 && a < 22) || (a > 22 && a < 29) || (a > 29 && a < 36) || (a > 36 && a < 42)) {
				printf("%8d",y);
			}
			else if ((a % 8 == 0 || a % 15 == 0 || a % 22 == 0 || a % 29 == 0 || a % 36 == 0 || a % 43 == 0) && (y != 1)) {
				printf("\n");
				printf("%4d",y);
			}
			else if (y == 1)
				printf("%4d",y);
			n--;
			y++;
			a = y + x;
		}
	}
	else if (day == 3) {
		printf("                        ");
		x = 3;
		while (n >= 1) {
			if ((a > 1 && a < 8) || (a > 8 && a < 15) || (a > 15 && a < 22) || (a > 22 && a < 29) || (a > 29 && a < 36) || (a > 36 && a < 42)) {
				printf("%8d",y);
			}
			else if ((a % 8 == 0 || a % 15 == 0 || a % 22 == 0 || a % 29 == 0 || a % 36 == 0 || a % 43 == 0) && (y != 1)) {
				printf("\n");
				printf("%4d",y);
			}
			else if (y == 1)
				printf("%4d",y);
			n--;
			y++;
			a = y + x;
		}
	}
	else if (day == 4) {
		printf("                                ");
		x = 4;
		while (n >= 1) {
			if ((a > 1 && a < 8) || (a > 8 && a < 15) || (a > 15 && a < 22) || (a > 22 && a < 29) || (a > 29 && a < 36) || (a > 36 && a < 42)) {
				printf("%8d",y);
			}
			else if ((a % 8 == 0 || a % 15 == 0 || a % 22 == 0 || a % 29 == 0 || a % 36 == 0 || a % 43 == 0) && (y != 1)) {
				printf("\n");
				printf("%4d",y);
			}
			else if (y == 1)
				printf("%4d",y);
			n--;
			y++;
			a = y + x;
		}
	}
	else if (day == 5) {
		printf("                                        ");
		x = 5;
		while (n >= 1) {
			if ((a > 1 && a < 8) || (a > 8 && a < 15) || (a > 15 && a < 22) || (a > 22 && a < 29) || (a > 29 && a < 36) || (a > 36 && a < 42)) {
				printf("%8d",y);
			}
			else if ((a % 8 == 0 || a % 15 == 0 || a % 22 == 0 || a % 29 == 0 || a % 36 == 0 || a % 43 == 0) && (y != 1)) {
				printf("\n");
				printf("%4d",y);
			}
			else if (y == 1)
				printf("%4d",y);
			n--;
			y++;
			a = y + x;
		}
	}
	else if (day == 6) {
		printf("                                                ");
		x = 6;
		while (n >= 1) {
			if ((a > 1 && a < 8) || (a > 8 && a < 15) || (a > 15 && a < 22) || (a > 22 && a < 29) || (a > 29 && a < 36) || (a > 36 && a < 42)) {
				printf("%8d",y);
			}
			else if ((a % 8 == 0 || a % 15 == 0 || a % 22 == 0 || a % 29 == 0 || a % 36 == 0 || a % 43 == 0) && (y != 1)) {
				printf("\n");
				printf("%4d",y);
			}
			else if (y == 1)
				printf("%4d",y);
			n--;
			y++;
			a = y + x;
		}
	}
	printf("\n");
	return 0;
}

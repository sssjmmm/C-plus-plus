/* 2151299 苏家铭 信16 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int i = 1;//计数用的
int s[3];//top，盘数,三个数字，代表sjm三个top
int ss[3][10] = { 0 };//二维数组表示三个柱子里的盘子数字，ss jj mm 

void output(int d, int n, char qs, char zj, char mb, int a[], int b[], int c[], char src, char tmp, char dst);
void hanoi(int d, int n, char qs, char zj, char mb, int a[], int b[], int c[], char src, char tmp, char dst);
void hanoi(int d, int n, char qs, char zj, char mb, int a[], int b[], int c[], char src, char tmp, char dst)
{
	if (n == 1) {
		output(d,n,qs,zj,mb,a,b,c,src,tmp,dst);
	}
	else if (n > 1) {
		hanoi(d, n - 1, qs,mb, zj, a, c, b,src,tmp,dst);
		output(d, n, qs, zj, mb, a, b, c, src, tmp, dst);
		hanoi(d, n - 1, zj, qs, mb, b, a, c, src,tmp,dst);
	}
}

void input()
{
	int c, ret,p;
	char qs, zj = 0, mb;
	while (1) {
		printf("请输入汉诺塔的层数(1-10)：\n");
		ret = scanf("%d", &c);
		while (ret != 1) {
			while (getchar() != '\n');

			printf("请输入汉诺塔的层数(1-10)：\n");
			ret = scanf("%d", &c);
		}
		if (c <= 0 || c >= 17) {
			while (getchar() != '\n');

		}
		if (c >= 1 && c <= 16) {
			while (getchar() != '\n');

			break;
		}
	}
	while (1) {
		printf("请输入起始柱(A-C)：\n");
		scanf("%c", &qs);
		if (qs == 'a' || qs == 'b' || qs == 'c' || qs == 'A' || qs == 'B' || qs == 'C') {
			while (getchar() != '\n');

			break;
		}
		if (qs != 'a' && qs != 'b' && qs != 'c' && qs != 'A' && qs != 'B' && qs != 'C') {
			while (getchar() != '\n');

		}
	}
	while (1) {
		printf("请输入目标柱(A-C)：\n");;
		scanf("%c", &mb);
		if ((mb == 'a' || mb == 'b' || mb == 'c' || mb == 'A' || mb == 'B' || mb == 'C') && mb != qs) {
			while (getchar() != '\n');

			break;
		}
		if (mb != 'a' && mb != 'b' && mb != 'c' && mb != 'A' && mb != 'B' && mb != 'C') {
			while (getchar() != '\n');

		}
		if ((mb == 'a' || mb == 'b' || mb == 'c' || mb == 'A' || mb == 'B' || mb == 'C') && mb == qs) {
			if (mb == 97 || mb == 65) {
				printf("目标柱(A)不能与起始柱(A)相同\n");
				while (getchar() != '\n');

			}
			if (mb == 98 || mb == 66) {
				printf("目标柱(B)不能与起始柱(B)相同\n");
				while (getchar() != '\n');

			}
			if (mb == 99 || mb == 67) {
				printf("目标柱(C)不能与起始柱(C)相同\n");
				while (getchar() != '\n');

			}
		}
	}
	if ((qs == 'a' || qs == 'A') && (mb == 'b' || mb == 'B')) {
		qs = 'A';
		zj = 'C';
		mb = 'B';
	}
	else if ((qs == 'a' || qs == 'A') && (mb == 'c' || mb == 'C')) {
		qs = 'A';
		zj = 'B';
		mb = 'C';
	}
	else if ((qs == 'b' || qs == 'B') && (mb == 'c' || mb == 'C')) {
		qs = 'B';
		zj = 'A';
		mb = 'C';
	}
	else if ((qs == 'b' || qs == 'B') && (mb == 'a' || mb == 'A')) {
		qs = 'B';
		zj = 'C';
		mb = 'A';
	}
	else if ((qs == 'c' || qs == 'C') && (mb == 'b' || mb == 'B')) {
		qs = 'C';
		zj = 'A';
		mb = 'B';
	}
	else if ((qs == 'c' || qs == 'C') && (mb == 'a' || mb == 'A')) {
		qs = 'C';
		zj = 'B';
		mb = 'A';
	}

	for (int o = 0; o < c; o++) {
		ss[0][o] = o + 1;
		ss[1][o] = 0;
		ss[2][o] = 0;
	}
	s[0] = c; s[1] = 0; s[2] = 0;
	printf("初始:               ");
	printf(" A:");
	if (qs == 'A' || qs == 'a') {
		for (p = c - 1; p >= 0; p--) {
			if (ss[0][p] != 0) {
				printf("%2d", ss[0][p]);
			}
			else if (ss[0][p] == 0) {
				printf("  ");
			}
		}
		for (p = 10 - c; p > 0; p--) {
			printf("  ");
		}
		printf(" B:");
		for (p = c - 1; p >= 0; p--) {
			if (ss[1][p] != 0) {
				printf("%2d", ss[1][p]);
			}
			else if (ss[1][p] == 0) {
				printf("  ");
			}
		}
		for (p = 10 - c; p > 0; p--) {
			printf("  ");
		}
		printf(" C:");
		for (p = c - 1; p >= 0; p--) {
			if (ss[2][p] != 0) {
				printf("%2d", ss[2][p]);
			}
			else if (ss[2][p] == 0) {
				printf("  ");
			}
		}
		for (p = 10 - c; p > 0; p--) {
			printf("  ");
		}
		printf("\n");
	}


	else if (qs == 'B' || qs == 'b') {
		for (p = c - 1; p >= 0; p--) {
			if (ss[1][p] != 0) {
				printf("%2d", ss[1][p]);
			}
			else if (ss[1][p] == 0) {
				printf("  ");
			}
		}
		for (p = 10 - c; p > 0; p--) {
			printf("  ");
		}
		printf(" B:");
		for (p = c - 1; p >= 0; p--) {
			if (ss[0][p] != 0) {
				printf("%2d", ss[0][p]);
			}
			else if (ss[0][p] == 0) {
				printf("  ");
			}
		}
		for (p = 10 - c; p > 0; p--) {
			printf("  ");
		}
		printf(" C:");
		for (p = c - 1; p >= 0; p--) {
			if (ss[2][p] != 0) {
				printf("%2d", ss[2][p]);
			}
			else if (ss[2][p] == 0) {
				printf("  ");
			}
		}
		for (p = 10 - c; p > 0; p--) {
			printf("  ");
		}
		printf("\n");
	}

	else if (qs == 'C' || qs == 'c') {
		for (p = c - 1; p >= 0; p--) {
			if (ss[1][p] != 0) {
				printf("%2d", ss[1][p]);
			}
			else if (ss[1][p] == 0) {
				printf("  ");
			}
		}
		for (p = 10 - c; p > 0; p--) {
			printf("  ");
		}
		printf(" B:");
		for (p = c - 1; p >= 0; p--) {
			if (ss[2][p] != 0) {
				printf("%2d", ss[2][p]);
			}
			else if (ss[2][p] == 0) {
				printf("  ");
			}
		}
		for (p = 10 - c; p > 0; p--) {
			printf("  ");
		}
		printf(" C:");
		for (p = c - 1; p >= 0; p--) {
			if (ss[0][p] != 0) {
				printf("%2d", ss[0][p]);
			}
			else if (ss[0][p] == 0) {
				printf("  ");
			}
		}
		for (p = 10 - c; p > 0; p--) {
			printf("  ");
		}
		printf("\n");
	}
	hanoi(c, c, qs, zj, mb, ss[0], ss[1], ss[2], qs, zj, mb);
}

int main()
{

	input();

	return 0;
}
void output(int d, int n, char qs, char zj, char mb, int a[], int b[], int c[], char src, char tmp, char dst) {
	int  ka, kc, p;
	if (a == ss[0] && b == ss[1] && c == ss[2]) {
		ka = d - s[0];
		kc = d - s[2];
		c[kc - 1] = a[ka];
		a[ka] = 0;
		s[2]++;
		s[0]--;
	}
	else if (a == ss[0] && b == ss[2] && c == ss[1]) {
		ka = d - s[0];
		kc = d - s[1];
		c[kc - 1] = a[ka];
		a[ka] = 0;
		s[1]++;
		s[0]--;
	}
	else if (a == ss[1] && b == ss[2] && c == ss[0]) {
		ka = d - s[1];
		kc = d - s[0];
		c[kc - 1] = a[ka];
		a[ka] = 0;
		s[0]++;
		s[1]--;
	}
	else if (a == ss[1] && b == ss[0] && c == ss[2]) {
		ka = d - s[1];
		kc = d - s[2];
		c[kc - 1] = a[ka];
		a[ka] = 0;
		s[2]++;
		s[1]--;
	}
	else if (a == ss[2] && b == ss[0] && c == ss[1]) {
		ka = d - s[2];
		kc = d - s[1];
		c[kc - 1] = a[ka];
		a[ka] = 0;
		s[1]++;
		s[2]--;
	}
	else if (a == ss[2] && b == ss[1] && c == ss[0]) {
		ka = d - s[2];
		kc = d - s[0];
		c[kc - 1] = a[ka];
		a[ka] = 0;
		s[0]++;
		s[2]--;
	}
	printf("第%4d 步(", i++);
	printf("%2d): %c-->%c ", n, qs, mb);
	printf("A:");
	if ((src == 'a' || src == 'A') && (dst == 'b' || dst == 'B')) {
		for (p = d - 1; p >= 0; p--) {
			if (ss[0][p] != 0) {
				printf("%2d", ss[0][p]);
			}
			else if (ss[0][p] == 0) {
				printf("  ");
			}
		}
		for (p = 10 - d; p > 0; p--) {
			printf("  ");
		}
		printf(" B:");
		for (p = d - 1; p >= 0; p--) {
			if (ss[2][p] != 0) {
				printf("%2d", ss[2][p]);
			}
			else if (ss[2][p] == 0) {
				printf("  ");
			}
		}
		for (p = 10 - d; p > 0; p--) {
			printf("  ");
		}
		printf(" C:");
		for (p = d - 1; p >= 0; p--) {
			if (ss[1][p] != 0) {
				printf("%2d", ss[1][p]);
			}
			else if (ss[1][p] == 0) {
				printf("  ");
			}
		}
		for (p = 10 - d; p > 0; p--) {
			printf("  ");
		}
		printf("\n");
	}


	else if ((src == 'a' || src == 'A') && (dst == 'c' || dst == 'C')) {
		for (p = d - 1; p >= 0; p--) {
			if (ss[0][p] != 0) {
				printf("%2d", ss[0][p]);
			}
			else if (ss[0][p] == 0) {
				printf("  ");
			}
		}
		for (p = 10 - d; p > 0; p--) {
			printf("  ");
		}
		printf(" B:");
		for (p = d - 1; p >= 0; p--) {
			if (ss[1][p] != 0) {
				printf("%2d", ss[1][p]);
			}
			else if (ss[1][p] == 0) {
				printf("  ");
			}
		}
		for (p = 10 - d; p > 0; p--) {
			printf("  ");
		}
		printf(" C:");
		for (p = d - 1; p >= 0; p--) {
			if (ss[2][p] != 0) {
				printf("%2d", ss[2][p]);
			}
			else if (ss[2][p] == 0) {
				printf("  ");
			}
		}
		for (p = 10 - d; p > 0; p--) {
			printf("  ");
		}
		printf("\n");
	}



	else if ((src == 'b' || src == 'B') && (dst == 'c' || dst == 'C')) {
		for (p = d - 1; p >= 0; p--) {
			if (ss[1][p] != 0) {
				printf("%2d", ss[1][p]);
			}
			else if (ss[1][p] == 0) {
				printf("  ");
			}
		}
		for (p = 10 - d; p > 0; p--) {
			printf("  ");
		}
		printf(" B:");
		for (p = d - 1; p >= 0; p--) {
			if (ss[0][p] != 0) {
				printf("%2d", ss[0][p]);
			}
			else if (ss[0][p] == 0) {
				printf("  ");
			}
		}
		for (p = 10 - d; p > 0; p--) {
			printf("  ");
		}
		printf(" C:");
		for (p = d - 1; p >= 0; p--) {
			if (ss[2][p] != 0) {
				printf("%2d", ss[2][p]);
			}
			else if (ss[2][p] == 0) {
				printf("  ");
			}
		}
		for (p = 10 - d; p > 0; p--) {
			printf("  ");
		}
		printf("\n");
	}
	else if ((src == 'b' || src == 'B') && (dst == 'a' || dst == 'A')) {
		for (p = d - 1; p >= 0; p--) {
			if (ss[2][p] != 0) {
				printf("%2d", ss[2][p]);
			}
			else if (ss[2][p] == 0) {
				printf("  ");
			}
		}
		for (p = 10 - d; p > 0; p--) {
			printf("  ");
		}
		printf(" B:");
		for (p = d - 1; p >= 0; p--) {
			if (ss[0][p] != 0) {
				printf("%2d", ss[0][p]);
			}
			else if (ss[0][p] == 0) {
				printf("  ");
			}
		}
		for (p = 10 - d; p > 0; p--) {
			printf("  ");
		}
		printf(" C:");
		for (p = d - 1; p >= 0; p--) {
			if (ss[1][p] != 0) {
				printf("%2d", ss[1][p]);
			}
			else if (ss[1][p] == 0) {
				printf("  ");
			}
		}
		for (p = 10 - d; p > 0; p--) {
			printf("  ");
		}
		printf("\n");
	}


	else if ((src == 'c' || src == 'C') && (dst == 'a' || dst == 'A')) {
		for (p = d - 1; p >= 0; p--) {
			if (ss[2][p] != 0) {
				printf("%2d", ss[2][p]);
			}
			else if (ss[2][p] == 0) {
				printf("  ");
			}
		}
		for (p = 10 - d; p > 0; p--) {
			printf("  ");
		}
		printf(" B:");
		for (p = d - 1; p >= 0; p--) {
			if (ss[1][p] != 0) {
				printf("%2d", ss[1][p]);
			}
			else if (ss[1][p] == 0) {
				printf("  ");
			}
		}
		for (p = 10 - d; p > 0; p--) {
			printf("  ");
		}
		printf(" C:");
		for (p = d - 1; p >= 0; p--) {
			if (ss[0][p] != 0) {
				printf("%2d", ss[0][p]);
			}
			else if (ss[0][p] == 0) {
				printf("  ");
			}
		}
		for (p = 10 - d; p > 0; p--) {
			printf("  ");
		}
		printf("\n");
	}


	else if ((src == 'c' || src == 'C') && (dst == 'b' || dst == 'B')) {
		for (p = d - 1; p >= 0; p--) {
			if (ss[1][p] != 0) {
				printf("%2d", ss[1][p]);
			}
			else if (ss[1][p] == 0) {
				printf("  ");
			}
		}
		for (p = 10 - d; p > 0; p--) {
			printf("  ");
		}
		printf(" B:");
		for (p = d - 1; p >= 0; p--) {
			if (ss[2][p] != 0) {
				printf("%2d", ss[2][p]);
			}
			else if (ss[2][p] == 0) {
				printf("  ");
			}
		}
		for (p = 10 - d; p > 0; p--) {
			printf("  ");
		}
		printf(" C:");
		for (p = d - 1; p >= 0; p--) {
			if (ss[0][p] != 0) {
				printf("%2d", ss[0][p]);
			}
			else if (ss[0][p] == 0) {
				printf("  ");
			}
		}
		for (p = 10 - d; p > 0; p--) {
			printf("  ");
		}
		printf("\n");
	}
}
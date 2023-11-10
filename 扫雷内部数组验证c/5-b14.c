/* 2151299 信16 苏家铭 */
/* 2052750 陈莫之 2153410 刘金硕 2151792 张翔 2153686 张启翔 2154301 黄昱翔 2150267 裘子涵 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

# define row 10
# define column 26
int main()
{

	int leishu = 50;

	int x = 0, y = 0, sjm[row][column];
	char c;

	for (int i = 0; i < row; i++) {//把文件赋给sjm[][]
		for (int j = 0; j < column; j++) {
			while (!(sjm[i][j] == 42 ||
				(sjm[i][j] >= 0 && sjm[i][j] <= 8) ||
				(sjm[i][j] >= 48 && sjm[i][j] <= 56))) {
				scanf("%c", &c);
				if ((int)c == 42 ||
					((int)c >= 0 && (int)c <= 8) ||
					((int)c >= 48 && (int)c <= 56)) {//过滤空格等其他字符
					sjm[i][j] = (int)c;
				}
			}
		}
	}

	int num = 0;
	for (int i = 0; i < row; i++) {//检查够不够50颗雷
		for (int j = 0; j < column; j++) {
			if (sjm[i][j] == 42)
				num++;
		}
	}
	if (num != 50) {
		printf("错误1\n");
		return 0;
	}

	int sum = 0;//周围8个位置的雷数
	for (int i = 0; i < row; i++) {//检查雷
		for (int j = 0; j < column; j++) {
			if (sjm[i][j] !=42) {
				if (i - 1 >= 0) {
					if (sjm[i - 1][j] == '*')
						sum++;
					if ((j + 1) < column) {
						if (sjm[i - 1][j + 1] == '*')
							sum++;
					}
				}
				if (j - 1 >= 0) {
					if (sjm[i][j - 1] == '*')
						sum++;
					if ((i + 1) < row) {
						if (sjm[i + 1][j - 1] == '*')
							sum++;
					}
				}
				if (j - 1 >= 0 && i - 1 >= 0) {
					if (sjm[i - 1][j - 1] == '*')
						sum++;
				}
				if ((j + 1) < column) {
					if (sjm[i][j + 1] == '*')
						sum++;
					if ((i + 1) < row) {
						if (sjm[i + 1][j + 1] == '*')
							sum++;
					}
				}
				if ((i + 1) < row) {
					if (sjm[i + 1][j] == '*')
						sum++;
				}
				if (sjm[i][j] != sum+48) {
					printf("错误2\n");
					return 0;
				}
				sum = 0;
			}
		}
	}

	printf("正确\n");
	return 0;
}

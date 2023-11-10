/* 信16 2151299 苏家铭 */
#include <iostream>
#include <stdlib.h>
#include <time.h> 

using namespace std;

int main()
{
	const int row = 10;
	const int column = 26;
	int leishu = 50;

	int x = 0, y = 0;
	int sjm[row][column];

	for (int i=0; i < row; i++) {//先每个标记为1
		for (int j=0; j < column; j++) {
			sjm[i][j] = 1;
		}
	}

	srand((unsigned int)time(NULL));  //随机设雷
	while (leishu>0) {//if leishu==0 跳出循环 else 继续
		x = rand() % row + 1;
		y = rand() % column + 1;
		if (sjm[x-1][y-1] == 1){
			sjm[x-1][y-1] = '*';
			leishu--;
		}
	}
	int sum = 0;//周围8个位置的雷数
	for (int i=0; i < row; i++) {//记录雷
		for (int j=0; j < column; j++) {
			if (sjm[i][j] == 1) {
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
				sjm[i][j] = sum;
				sum = 0;
			}
		}
	}
	
	for (int i=0; i < row; i++) {//输出盘
		for (int j=0; j < column; j++) {
			if (sjm[i][j] == 42) {
				cout << char(sjm[i][j]) << " ";
			}
			else
				cout << sjm[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}

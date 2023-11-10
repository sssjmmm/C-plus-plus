/* 2151299 信16 苏家铭 */
#include<iostream>
#include <cmath>
using namespace std;

int main() {

	int x[10][10],error=0;

	cout << "请输入9*9的矩阵，值为1-9之间" << endl;
	for (int i = 1; i < 10; i++) {// line
		for (int j = 1; j < 10; j++) {//column
			while (1) {
				cin >> x[i][j];
				while (cin.fail()) {
					cin.clear();
					cin.ignore(65535, '\n');
					cout << "请重新输入第"<<i<<"行"<<j<<"列(行列均从1开始计数)的值" << endl;
					cin >> x[i][j];
				}
				if (x[i][j] >= 1 && x[i][j] <= 9)
					break;
				else if (x[i][j] < 1 || x[i][j] > 9) {
					cout << "请重新输入第" << i << "行" << j << "列(行列均从1开始计数)的值" << endl;
				}
			}
		}
	}

	for (int i = 1; i < 10; i++) {// 行有重复数字吗
		for (int j = 1; j < 9; j++) {
			for (int k = j+1; k < 10; k++) {
				if (x[i][j] == x[i][k]) {
					error++;
					break;
				}
			}
		}
	}

	for (int i = 1; i < 10; i++) {// 列有重复数字吗
		for (int j = 1; j < 9; j++) {
			for (int k = j + 1; k < 10; k++) {
				if (x[j][i] == x[k][i]) {
					error++;
					break;
				}
			}
		}
	}


	for (int i = 1; i < 4; i++) {// 九宫格1有重复数字吗
		for (int j = 1; j < 4; j++) {
			for (int k = j + 1; k < 4; k++) {//本行比较
				if (x[i][j] == x[i][k]) {
					error++;
					break;
				}
			}
			for (int m = 1; m < 4; m++) {//和下面的行比较
				for (int l=i+1; l < 4; l++) {
					if (x[i][j] == x[l][m]) {
						error++;
						break;
					}
				}
			}	
		}
	}

	for (int i = 1; i < 4; i++) {// 九宫格2有重复数字吗
		for (int j = 1+3; j < 4+3; j++) {
			for (int k = j + 1; k < 4 + 3; k++) {//本行比较
				if (x[i][j] == x[i][k]) {
					error++;
					break;
				}
			}
			for (int m = 1 + 3; m < 4+3; m++) {//和下面的行比较 m是列 l是行
				for (int l = i + 1; l < 4; l++) {
					if (x[i][j] == x[l][m]) {
						error++;
						break;
					}
				}
			}
		}
	}

	for (int i = 1; i < 4; i++) {// 九宫格3有重复数字吗
		for (int j = 1 + 3+3; j < 4 + 3 + 3; j++) {
			for (int k = j + 1; k < 4 + 3 + 3; k++) {//本行比较
				if (x[i][j] == x[i][k]) {
					error++;
					break;
				}
			}
			for (int m = 1 + 3 + 3; m < 4 + 3 + 3; m++) {//和下面的行比较 m是列 l是行
				for (int l = i + 1; l < 4; l++) {
					if (x[i][j] == x[l][m]) {
						error++;
						break;
					}
				}
			}
		}
	}

	for (int i = 1+3; i < 4 + 3; i++) {// 九宫格4有重复数字吗
		for (int j = 1 ; j < 4 ; j++) {
			for (int k = j + 1; k < 4; k++) {//本行比较
				if (x[i][j] == x[i][k]) {
					error++;
					break;
				}
			}
			for (int m = 1; m < 4 ; m++) {//和下面的行比较 m是列 l是行
				for (int l = i + 1; l < 4 + 3; l++) {
					if (x[i][j] == x[l][m]) {
						error++;
						break;
					}
				}
			}
		}
	}

	for (int i = 1+3; i < 4 + 3; i++) {// 九宫格5有重复数字吗
		for (int j = 1 + 3; j < 4 + 3; j++) {
			for (int k = j + 1; k < 4 + 3; k++) {//本行比较
				if (x[i][j] == x[i][k]) {
					error++;
					break;
				}
			}
			for (int m = 1 + 3; m < 4 + 3; m++) {//和下面的行比较 m是列 l是行
				for (int l = i + 1; l < 4 + 3; l++) {
					if (x[i][j] == x[l][m]) {
						error++;
						break;
					}
				}
			}
		}
	}

	for (int i = 1 + 3; i < 4 + 3; i++) {// 九宫格6有重复数字吗
		for (int j = 1 + 3 + 3; j < 4 + 3 + 3; j++) {
			for (int k = j + 1; k < 4 + 3 + 3; k++) {//本行比较
				if (x[i][j] == x[i][k]) {
					error++;
					break;
				}
			}
			for (int m = 1 + 3 + 3; m < 4 + 3 + 3; m++) {//和下面的行比较 m是列 l是行
				for (int l = i + 1; l < 4+3 ; l++) {
					if (x[i][j] == x[l][m]) {
						error++;
						break;
					}
				}
			}
		}
	}

	for (int i = 1 + 3 + 3; i < 4 + 3 + 3; i++) {// 九宫格7有重复数字吗
		for (int j = 1; j < 4; j++) {
			for (int k = j + 1; k < 4; k++) {//本行比较
				if (x[i][j] == x[i][k]) {
					error++;
					break;
				}
			}
			for (int m = 1; m < 4; m++) {//和下面的行比较 m是列 l是行
				for (int l = i + 1; l < 4 + 3 + 3; l++) {
					if (x[i][j] == x[l][m]) {
						error++;
						break;
					}
				}
			}
		}
	}

	for (int i = 1 + 3 + 3; i < 4 + 3 + 3; i++) {// 九宫格8有重复数字吗
		for (int j = 1 + 3; j < 4+3; j++) {
			for (int k = j + 1; k < 4 + 3; k++) {//本行比较
				if (x[i][j] == x[i][k]) {
					error++;
					break;
				}
			}
			for (int m = 1 + 3; m < 4 + 3; m++) {//和下面的行比较 m是列 l是行
				for (int l = i + 1; l < 4 + 3 + 3; l++) {
					if (x[i][j] == x[l][m]) {
						error++;
						break;
					}
				}
			}
		}
	}

	for (int i = 1 + 3 + 3; i < 4 + 3 + 3; i++) {// 九宫格9有重复数字吗
		for (int j = 1 + 3 + 3; j < 4 + 3+3; j++) {
			for (int k = j + 1; k < 4 + 3 + 3; k++) {//本行比较
				if (x[i][j] == x[i][k]) {
					error++;
					break;
				}
			}
			for (int m = 1 + 3 + 3; m < 4 + 3+3; m++) {//和下面的行比较 m是列 l是行
				for (int l = i + 1; l < 4 + 3 + 3; l++) {
					if (x[i][j] == x[l][m]) {
						error++;
						break;
					}
				}
			}
		}
	}

	if (error == 0)
		cout << "是数独的解" << endl;
	else if (error != 0)
		cout << "不是数独的解" << endl;


	return 0;
}
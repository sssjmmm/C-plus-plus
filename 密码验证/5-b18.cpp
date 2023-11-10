/* 2151299 信16 苏家铭*/
#include<iostream>
using namespace std;
#define len 10
#define max 16
static const char other[] = "~!@#$%^&*()-_=+[],.?";

int main() {
	int num[5];
	char checkcode[len][max + 1] = {" "}, sentence[5][18];
	for (int i = 0; i < 5; i++) {//存第一句
		cin >> sentence[i];
	}
	for (int i = 0; i < 5; i++) {//存5个数字
		cin >> num[i];
	}
	for (int i = 0; i < len; i++) {//存密码
		for (int k = 0; k < num[0]; k++) {
			if (checkcode[i][k] == '\0'|| checkcode[i][k] == ' ') {
				cin>> checkcode[i][k];
			}
		}
	}
	//密码总长是否符合要求

	for (int i = 0; i < len; i++) {
		if (strlen(checkcode[i]) != num[0]) {
			cout << "错误" << endl;
			return 0;
		}
	}

	//各种类型的字符数量是否符合各自的最小要求
	
	for (int i = 0, sum = 0; i < len; i++) {//LETTER
		for (int k = 0; k < num[0]; k++) {
			if (checkcode[i][k] >= 'A' && checkcode[i][k] <= 'Z') {
				sum++;
			}
		}
		if (sum < num[1]) {
			cout << "错误" << endl;
			return 0;
		}
		else
			sum = 0;
	}
	for (int i = 0, sum = 0; i < len; i++) {//letter
		for (int k = 0; k < num[0]; k++) {
			if (checkcode[i][k] >= 'a' && checkcode[i][k] <= 'z') {
				sum++;
			}
		}
		if (sum < num[2]) {
			cout << "错误" << endl;
			return 0;
		}
		else
			sum = 0;
	}
	for (int i = 0, sum = 0; i < len; i++) {//digit
		for (int k = 0; k < num[0]; k++) {
			if (checkcode[i][k] >= '0' && checkcode[i][k] <= '9') {
				sum++;
			}
		}
		if (sum < num[3]) {
			cout << "错误" << endl;
			return 0;
		}
		else
			sum = 0;
	}
	for (int i = 0, sum = 0; i < len; i++) {//other
		for (int k = 0; k < num[0]; k++) {
			for (int j = 0; j < 20; j++) {
				if (checkcode[i][k] ==other[j]) {
					sum++;
				}
			}
		}
		if (sum < num[4]) {
			cout << "错误" << endl;
			return 0;
		}
		else
			sum = 0;
	}

	//各种类型字符数量的总和是否等于总长

	int sumx;
	sumx = num[0];
	for (int i = 0, sum = 0; i < len; i++) {//和
		for (int k = 0; k < num[0]; k++) {
			for (int j = 0; j < 20; j++) {
				if (checkcode[i][k] == other[j]) {
					sum++;
				}
			}
			if (checkcode[i][k] >= '0' && checkcode[i][k] <= '9') {
				sum++;
			}
			else if(checkcode[i][k] >= 'a' && checkcode[i][k] <= 'z') {
				sum++;
			}
			else if (checkcode[i][k] >= 'A' && checkcode[i][k] <= 'Z') {
				sum++;
			}
		}
		if (sum != sumx) {
			cout << "错误" << endl;
			return 0;
		}
		else
			sum=0;
	}


	cout << "正确" << endl;
	return 0;
}
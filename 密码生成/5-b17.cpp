/* 2151299 信16 苏家铭*/
#include<iostream>
#include <time.h> 
using namespace std;
#define len 10
#define max 16
static const char other[] = "~!@#$%^&*()-_=+[],.?";

int main() {
	int code, LETTER, letter, digit, othern;
	char mycode[len][max+1];
	cout << "请输入密码长度(12-16)， 大写字母个数(≥2)， 小写字母个数(≥2)， 数字个数(≥2)， 其它符号个数(≥2)" << endl;
	cin >> code;
	if (cin.fail()) {
		cout << "输入非法" << endl;
		return 0;
	}
	if (code <= 11 || code >max) {
		cout << "密码长度[" << code << "]不正确" << endl;
		return 0;
	}
	cin >> LETTER;
	if (cin.fail()) {
		cout << "输入非法" << endl;
		return 0;
	}
	if (LETTER <= 1 || LETTER > code) {
		cout << "大写字母个数[" << LETTER << "]不正确" << endl;
		return 0;
	}
	cin >> letter;
	if (cin.fail()) {
		cout << "输入非法" << endl;
		return 0;
	}
	if (letter <= 1 || letter > code) {
		cout << "小写字母个数[" << letter << "]不正确" << endl;
		return 0;
	}
	cin >> digit;
	if (cin.fail()) {
		cout << "输入非法" << endl;
		return 0;
	}
	if (digit <= 1 || digit > code) {
		cout << "数字个数[" << digit << "]不正确" << endl;
		return 0;
	}
	cin >> othern;
	if (cin.fail()) {
		cout << "输入非法" << endl;
		return 0;
	}
	if (othern <= 1 || othern > code) {
		cout << "其它符号个数[" << othern << "]不正确" << endl;
		return 0;
	}
	if (LETTER + letter + digit + othern > code) {
		cout << "所有字符类型之和[" << LETTER << "+" << letter << "+" << digit << "+" << othern << "]大于总密码长度[" << code << "]" << endl;
		return 0;
	}
	cout << code << " " << LETTER << " " << letter << " " << digit << " " << othern << endl;
	srand((unsigned int)time(NULL));//48-57digit big65-90 small 97-122
	int random1, random2, random3;
	for (int i = 0; i < len; i++){//LETTER
		for (int k=0; k < LETTER;) {
			random1 = rand() % 26;//随机字符
			random2 = rand() % 16;//随机位置
			if (mycode[i][random2] == -52) {
				mycode[i][random2] = random1 + 'A';
				k++;
			}
		}
	}
	for (int i = 0; i < len; i++) {//letter
		for (int k = 0; k < letter;) {
			random1 = rand() % 26;//随机字符[0,26)
			random2 = rand() % 16;//随机位置[0,16)
			if (mycode[i][random2] == -52) {
				mycode[i][random2] = random1 + 'a';
				k++;
			}
		}
	}
	for (int i = 0; i < len; i++) {//digit
		for (int k = 0; k < digit;) {
			random1 = rand() % 10;//随机字符[0,10)
			random2 = rand() % 16;//随机位置[0,16)
			if (mycode[i][random2] == -52) {
				mycode[i][random2] = random1 + '0';
				k++;
			}
		}
	}
	for (int i = 0; i < len; i++) {//othern
		for (int k = 0; k < othern;) {
			random1 = rand() % 20;//随机字符[0,20)
			random2 = rand() % 16;//随机位置[0,16)
			if (mycode[i][random2] == -52) {
				mycode[i][random2] = other[random1];
				k++;
			}
		}
	}
	for (int i = 0; i < len; i++) {//补齐
		for (int k = LETTER+letter+othern+digit; k < code;) {
			random2 = rand() % 16;//随机位置[0,16)
			random3 = rand() % 4;//随机数[0,4)
			if (random3 == 0) {
				random1 = rand() % 20;//随机字符[0,20)
				if (mycode[i][random2] == -52) {
					mycode[i][random2] = other[random1];
					k++;
				}
			}
			else if (random3 == 1) {
				random1 = rand() % 26;//随机字符[0,26)
				if (mycode[i][random2] == -52) {
					mycode[i][random2] = random1 + 'a';
					k++;
				}
			}
			else if (random3 == 2) {
				random1 = rand() % 26;//随机字符[0,26)
				if (mycode[i][random2] == -52) {
					mycode[i][random2] = random1 + 'A';
					k++;
				}
			}
			else if (random3 == 3) {
				random1 = rand() % 10;//随机字符[0,10)
				if (mycode[i][random2] == -52) {
					mycode[i][random2] = random1 + '0';
					k++;
				}
			}
		}
	}
	
	for (int i = 0; i < len; i++) {//cout
		for (int k = 0; k < max;k++) {
			if (mycode[i][k] != -52) {
				cout << mycode[i][k];
			}
		}
		cout << endl;
	}
	return 0;
}

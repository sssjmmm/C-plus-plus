/*2151299 苏家铭 信16*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;
#define COL 16

char change(char ch) {
	if (ch >= 65 && ch <= 90)
		ch += 32;
	return ch;
}
void change8(int n) {
	char b[8];
	for (int i = 0; i < 8; i++) {
		b[i] = '0';
	}
	for (int i = 7; n != 0; i--) {
		if (n % 16 == 10)b[i] = 'a';
		else if (n % 16 == 11)b[i] = 'b';
		else if (n % 16 == 12)b[i] = 'c';
		else if (n % 16 == 13)b[i] = 'd';
		else if (n % 16 == 14)b[i] = 'e';
		else if (n % 16 == 15)b[i] = 'f';
		else b[i] = (n % 16) + '0';
		n = n / 16;
	}
	for (int i = 0; i < 8; i++) {
		cout << b[i];
	}
	cout << "  ";
}
void change2(int n) {
	char a[2];
	for (int i = 0; i < 2; i++) {
		a[i] = '0';
	}
	if (n < 0 )
		n += 256;
	for (int i = 1; n != 0; i--) {
		if (n % 16 == 10)a[i] = 'A';
		else if (n % 16 == 11)a[i] = 'B';
		else if (n % 16 == 12)a[i] = 'C';
		else if (n % 16 == 13)a[i] = 'D';
		else if (n % 16 == 14)a[i] = 'E';
		else if (n % 16 == 15)a[i] = 'F';
		else a[i] = int((n % 16) + '0');
		n = n / 16;
	}
	for (int i = 0; i < 2; i++) {
		a[i]=change(a[i]);
		cout << a[i];
	}
	cout << " ";
}

int main()
{
	char way[100];
	cerr << "文件名以下形式均可以:" << endl;
	cerr << "    a.txt                    : 不带路径形式" << endl;
	cerr << "    ..\\data\\b.dat          : 相对路径形式" << endl;
	cerr << "    C:\\Windows\\System32\\c.dat : 绝对相对路径形式" << endl;
	cerr << "请输入文件名 :";
	cin.getline(way, 100);
	int LEN = strlen(way);

	ifstream infile;
	infile.open(way, ios::in|ios::binary);
	if (!infile.is_open()) {
		cout << "输入文件";
		for (int i = 0; i < LEN; i++) {
			cout << way[i];
		}
		cout<< "打开失败!" << endl;
		return -1;
	}
	//此时输入文件已经打开成功
	char arr[COL] = { 0 }, ch;
	char* p;
	int row = 0;
	int sum=0;

	for (int r = 0; infile.peek()!=EOF; r++) {//r=row
		//记录
		for (int c = 0; (c < COL) && (infile.peek() != EOF); c++) {//c=column
			arr[c] = infile.get();
			sum++;
		}
		//第一部分
		change8(row);
		//为换行做准备
		if (sum == 16)
			row+=16;
		//第二部分
		bool F = false, X = false;//为了补齐
		int now = 0;
		for (p=arr; p-arr<sum; p++) {//c=column
			int M = 0;		
			//"-"
			if (now == 8) {
					cout << "- ";
					X = true;
			}	
				change2(*p);
				now++;
		}//end of for
		if (X == false) {
			cout << "  ";
		}
		for (int i = 0; i < 16 - sum+F; i++) {//补齐宽度
			cout << "   ";
		}
		//第三部分
		cout << "    ";
		for (p = arr; p - arr < sum; p++) {//c=column
			if (*p >= 33 && *p <= 126) {
				cout << char(*p);
			}
			else  {
				cout << ".";
			}
		}
		sum = 0;
		if (infile.peek() != EOF) {
			cout << endl;//进入下一行
		}
		else
			break;

	}
	cout << endl;

	infile.close();             //关闭文件输入流 

	return 0;
}

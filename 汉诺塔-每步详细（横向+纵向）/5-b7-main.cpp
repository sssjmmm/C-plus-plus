/* 2151299 苏家铭 信16 */
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include<conio.h>
#include"5-b7.h"
using namespace std;

int i = 1;//计数用的
int s, j, m;//top，盘数
int ss[10] = { 0 }, jj[10] = { 0 }, mm[10] = { 0 };//数组表示三个柱子里的盘子数字
int xs;//显示用的
static int v;//延时

void output(int d, int n, char qs, char zj, char mb, int a[], int b[], int c[], char src, char tmp, char dst);
void hanoi(int d, int n, char qs, char zj, char mb, int a[], int b[], int c[], char src, char tmp, char dst);
void shuchu2(int d, int a[], int with);
void shuchu1(int d, int a[]);
void hanoi(int d, int n, char qs, char zj, char mb, int a[], int b[], int c[], char src, char tmp, char dst)
{
	if (n == 1) {
		output(d, n, qs, zj, mb, a, b, c, src, tmp, dst);
	}
	else if (n > 1) {
		hanoi(d, n - 1, qs, mb, zj, a, c, b, src, tmp, dst);
		output(d, n, qs, zj, mb, a, b, c, src, tmp, dst);
		hanoi(d, n - 1, zj, qs, mb, b, a, c, src, tmp, dst);
	}
}
void input()
{
	int c;
	char qs, zj=0, mb;
	while (1) {
		cout << "请输入汉诺塔的层数(1-10)：" << endl;
		cin >> c;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(65535, '\n');
			cout << "请输入汉诺塔的层数(1-10)：" << endl;
			cin >> c;
		}
		if (c <= 0 || c >= 17) {
			cin.clear();
			cin.ignore(65535, '\n');
		}
		if (c >= 1 && c <= 16) {
			cin.clear();
			cin.ignore(65535, '\n');
			break;
		}
	}
	while (1) {
		cout << "请输入起始柱(A-C)：" << endl;
		cin >> qs;
		if (qs == 'a' || qs == 'b' || qs == 'c' || qs == 'A' || qs == 'B' || qs == 'C') {
			cin.clear();
			cin.ignore(65535, '\n');
			break;
		}
		if (qs != 'a' && qs != 'b' && qs != 'c' && qs != 'A' && qs != 'B' && qs != 'C') {
			cin.clear();
			cin.ignore(65535, '\n');
		}
	}
	while (1) {
		cout << "请输入目标柱(A-C)：" << endl;;
		cin >> mb;
		if ((mb == 'a' || mb == 'b' || mb == 'c' || mb == 'A' || mb == 'B' || mb == 'C') && mb != qs) {
			cin.clear();
			cin.ignore(65535, '\n');
			break;
		}
		if (mb != 'a' && mb != 'b' && mb != 'c' && mb != 'A' && mb != 'B' && mb != 'C') {
			cin.clear();
			cin.ignore(65535, '\n');
		}
		if ((mb == 'a' || mb == 'b' || mb == 'c' || mb == 'A' || mb == 'B' || mb == 'C') && mb == qs) {
			if (mb == 97 || mb == 65) {
				cout << "目标柱(A)不能与起始柱(A)相同" << endl;
				cin.clear();
				cin.ignore(65535, '\n');
			}
			if (mb == 98 || mb == 66) {
				cout << "目标柱(B)不能与起始柱(B)相同" << endl;
				cin.clear();
				cin.ignore(65535, '\n');
			}
			if (mb == 99 || mb == 67) {
				cout << "目标柱(C)不能与起始柱(C)相同" << endl;
				cin.clear();
				cin.ignore(65535, '\n');
			}
		}
	}
	cout << "请输入移动速度(0-5: 0-按回车单步演示 1-延时最长 5-延时最短)" << endl;

	cin >> v;
	cout << "请输入是否显示内部数组值(0-不显示 1-显示)" << endl;
	cin >> xs;
	// 输入


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
		ss[o] = o + 1;
		jj[o] = 0;
		mm[o] = 0;
	}
	s = c; j = 0; m = 0;
	cct_cls();
	cout << "从 " << qs << " 移动到 " << mb << "，共 " << c << " 层，延时设置为 " << v << "，";
	if (xs == 0)
		cout << "不显示内部数组值" << endl;
	else if (xs == 1)
		cout << "显示内部数组值" << endl;


	if (xs == 1) {
		cct_gotoxy(1, 17);
		cout << "初始:               ";
		cct_gotoxy(21, 17);
		cout << " A:";
		if (qs == 'A' || qs == 'a') {
			shuchu1(c, ss);
			cout << " B:";
			shuchu1(c, jj);
			cout << " C:";
			shuchu1(c, mm);
			cout << endl;
		}
	    else if (qs == 'B' || qs == 'b') {
		    shuchu1(c, jj);
	    	cout << " B:";
		    shuchu1(c, ss);
		    cout << " C:";
		    shuchu1(c, mm);
		    cout << endl;
	    }
	    else if (qs == 'C' || qs == 'c') {	   
			shuchu1(c, jj);
			cout << " B:";
			shuchu1(c, mm);
			cout << " C:";
			shuchu1(c, ss);
			cout << endl;
		}
	}
		if ((qs == 'a' || qs == 'A') ) {// 1
			shuchu2(c, ss, 0);
			shuchu2(c, mm, 10);
			shuchu2(c, jj, 20);
		}
		else if ((qs == 'b' || qs == 'B') ) {//2
			shuchu2(c, jj, 0);
			shuchu2(c, ss, 10);
			shuchu2(c, mm, 20);
		}
		else if ((qs == 'c' || qs == 'C') ) {//3
			shuchu2(c, jj, 0);
			shuchu2(c, mm, 10);
			shuchu2(c, ss, 20);
		}	
		cct_gotoxy(1, 26);

		hanoi(c, c, qs, zj, mb, ss, jj, mm, qs, zj, mb);
	}
int main()
{

	input();

	return 0;
}
int panduan1(int a[]) {
	if (a == ss) {//1
		s--;
		return (s + 1);
	}
	else if (a == jj) {//2
		j--;
		return (j + 1);
	}
	else if (a == mm) {//3
		m--;
		return (m + 1);
	}
	else
		return 0;
}
int panduan2(int c[]) {
	if (c == ss) {//1
		s++;
		return (s - 1);
	}
	else if (c == jj) {//2
		j++;
		return (j - 1);
	}
	else if (c == mm) {//3
		m++;
		return (m - 1);
	}
	else
		return 0;
}
void shuchu1(int d, int a[]) {
	for (int p = d - 1; p >= 0; p--) {
		if (a[p] != 0) {
			cout << setw(2) << a[p];
		}
		else if (a[p] == 0) {
			cout << "  ";
		}
	}
	for (int p = 10 - d; p > 0; p--) {
		cout << "  ";
	}
}
void jisuan1(int d, int a[], int b[], int c[]) {
	int  ka, kc, j, k;
	ka = d - (j = panduan1(a));
	kc = d - (k = panduan2(c));
	c[kc - 1] = a[ka];
	a[ka] = 0;
}
void shuchu2(int d, int a[],int with) {
	for (int p = d - 1; p >= 0; p--) {
		if (a[p] != 0) {
			cct_gotoxy(11+with, 12 - (d - p));
			cout << setw(2) << a[p];
		}
		else if (a[p] == 0) {
			cct_gotoxy(11+with, 12 - (d - p));
			cout << "  ";
		}
	}
}
void output(int d, int n, char qs, char zj, char mb, int a[], int b[], int c[], char src, char tmp, char dst) {
	int  w;
	cct_gotoxy(10, 12);
	cout << "=========================";
	cct_gotoxy(12, 13);
	cout << "A         B         C" << endl;
	jisuan1(d, a, b, c);
	if (v == 1)
		Sleep(1000);
	else if (v == 2)
		Sleep(500);
	else if (v == 3)
		Sleep(200);
	else if (v == 4)
		Sleep(25);
	else if (v == 5)
		Sleep(0);
	else if (v == 0)
		w = _getch();

	cct_gotoxy(1, 17);
	cout << "第" << setw(4) << i++ << " 步(";
	cout << n << "#: " << qs << "-- > " << mb << ")";


	if (xs == 1) {
		cct_gotoxy(21, 17);
		if ((src == 'a' || src == 'A') && (dst == 'b' || dst == 'B')) {//1
			cout << " A:";
			shuchu1(d, ss);
			cout << " B:";
			shuchu1(d, mm);
			cout << " C:";
			shuchu1(d, jj);
			cout << endl;
		}
		else if ((src == 'a' || src == 'A') && (dst == 'c' || dst == 'C')) {//2
			cout << " A:";
			shuchu1(d, ss);
			cout << " B:";
			shuchu1(d, jj);
			cout << " C:";
			shuchu1(d, mm);
			cout << endl;
		}
		else if ((src == 'b' || src == 'B') && (dst == 'c' || dst == 'C')) {//3
			cout << " A:";
			shuchu1(d, jj);
			cout << " B:";
			shuchu1(d, ss);
			cout << " C:";
			shuchu1(d, mm);
			cout << endl;
		}
		else if ((src == 'b' || src == 'B') && (dst == 'a' || dst == 'A')) {//4
			cout << " A:";
			shuchu1(d, mm);
			cout << " B:";
			shuchu1(d, ss);
			cout << " C:";
			shuchu1(d, jj);
			cout << endl;
		}
		else if ((src == 'c' || src == 'C') && (dst == 'b' || dst == 'B')) {//5
			cout << " A:";
			shuchu1(d, jj);
			cout << " B:";
			shuchu1(d, mm);
			cout << " C:";
			shuchu1(d, ss);
			cout << endl;
		}
		else if ((src == 'c' || src == 'C') && (dst == 'a' || dst == 'A')) {//6
			cout << " A:";
			shuchu1(d, mm);
			cout << " B:";
			shuchu1(d, jj);
			cout << " C:";
			shuchu1(d, ss);
			cout << endl;
		}
	}
	if (v == 0)
		w = _getch();
	if ((src == 'a' || src == 'A') && (dst == 'b' || dst == 'B')) {// 1
		shuchu2(d, ss, 0);
		shuchu2(d, mm, 10);
		shuchu2(d, jj, 20);
	}
	else if ((src == 'a' || src == 'A') && (dst == 'c' || dst == 'C')) {// 2
		shuchu2(d, ss, 0);
		shuchu2(d, jj, 10);
		shuchu2(d, mm, 20);
	}
	else if ((src == 'b' || src == 'B') && (dst == 'c' || dst == 'C')) {//3
		shuchu2(d, jj, 0);
		shuchu2(d, ss, 10);
		shuchu2(d, mm, 20);
	}
	else if ((src == 'b' || src == 'B') && (dst == 'a' || dst == 'A')) {//4
		shuchu2(d, mm, 0);
		shuchu2(d, ss, 10);
		shuchu2(d, jj, 20);
	}
	else if ((src == 'c' || src == 'C') && (dst == 'b' || dst == 'B')) {//5
		shuchu2(d, jj, 0);
		shuchu2(d, mm, 10);
		shuchu2(d, ss, 20);
	}
	else if ((src == 'c' || src == 'C') && (dst == 'a' || dst == 'A')) {//6
		shuchu2(d, mm, 0);
		shuchu2(d, jj, 10);
		shuchu2(d, ss, 20);
	}
	cct_gotoxy(1, 26);
}
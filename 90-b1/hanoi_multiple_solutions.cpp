/* 信16 2151299 苏家铭 */
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include<conio.h>
#include"cmd_console_tools.h"
#include"hanoi.h"
using namespace std;

static int i = 1;//计数用的
static int s, j, m;//top，盘数
static int ss[10] = { 0 }, jj[10] = { 0 }, mm[10] = { 0 };//数组表示三个柱子里的盘子数字
//s是起始柱，不一定是A柱，m是目标柱
static int v=6;//延时

/* ----------------------------------------------------------------------------------1

     本文件功能：
	1、存放被 hanoi_main.cpp 中根据菜单返回值调用的各菜单项对应的执行函数

     本文件要求：
	1、不允许定义外部全局变量（const及#define不在限制范围内）
	2、允许定义静态全局变量（具体需要的数量不要超过文档显示，全局变量的使用准则是：少用、慎用、能不用尽量不用）
	3、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
	4、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------------------------------------------------- */

/*输入参数*/
void input(int *d,char *qs,char *zj,char *mb,int choice) {

	while (1) {
		cout << "请输入汉诺塔的层数(1-10)：" << endl;
		cin >> *d;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(65535, '\n');
			cout << "请输入汉诺塔的层数(1-10)：" << endl;
			cin >> *d;
		}
		if (*d <= 0 || *d >= 17) {
			cin.clear();
			cin.ignore(65535, '\n');
		}
		if (*d >= 1 && *d <= 16) {
			cin.clear();
			cin.ignore(65535, '\n');
			break;
		}
	}
	while (1) {
		cout << "请输入起始柱(A-C)：" << endl;
		cin >> *qs;
		if (*qs == 'a' || *qs == 'b' || *qs == 'c' || *qs == 'A' || *qs == 'B' || *qs == 'C') {
			cin.clear();
			cin.ignore(65535, '\n');
			break;
		}
		if (*qs != 'a' && *qs != 'b' && *qs != 'c' && *qs != 'A' && *qs != 'B' && *qs != 'C') {
			cin.clear();
			cin.ignore(65535, '\n');
		}
	}
	while (1) {
		cout << "请输入目标柱(A-C)：" << endl;;
		cin >> *mb;
		if ((*mb == 'a' || *mb == 'b' || *mb == 'c' || *mb == 'A' || *mb == 'B' || *mb == 'C') && *mb != *qs) {
			cin.clear();
			cin.ignore(65535, '\n');
			break;
		}
		if (*mb != 'a' && *mb != 'b' && *mb != 'c' && *mb != 'A' && *mb != 'B' && *mb != 'C') {
			cin.clear();
			cin.ignore(65535, '\n');
		}
		if ((*mb == 'a' || *mb == 'b' || *mb == 'c' || *mb == 'A' || *mb == 'B' || *mb == 'C') && mb == qs) {
			if (*mb == 97 || *mb == 65) {
				cout << "目标柱(A)不能与起始柱(A)相同" << endl;
				cin.clear();
				cin.ignore(65535, '\n');
			}
			if (*mb == 98 || *mb == 66) {
				cout << "目标柱(B)不能与起始柱(B)相同" << endl;
				cin.clear();
				cin.ignore(65535, '\n');
			}
			if (*mb == 99 || *mb == 67) {
				cout << "目标柱(C)不能与起始柱(C)相同" << endl;
				cin.clear();
				cin.ignore(65535, '\n');
			}
		}
	}
	if (choice == 4 || choice == 8) {
		cout << "请输入移动速度(0-5: 0-按回车单步演示 1-延时最长 5-延时最短)" << endl;
		cin >> v;
	}
	*qs = change(*qs);
	*zj = change(*zj);
	*mb = change(*mb);
	*zj = 'A' + 'B' + 'C' - *qs - *mb;

	for (int o = 0; o < *d; o++) {
		ss[o] = o + 1;
		jj[o] = 0;
		mm[o] = 0;
	}
	s = *d; j = 0; m = 0;
	// 输入
}
/*hanoi递归函数*/
void hanoi1(int d, int n, char qs, char zj, char mb, int a[], int b[], int c[], char src, char tmp, char dst,int choice){
	if (n == 1) {
		if (choice == 1||choice == 2 || choice == 3 || choice == 4 || choice == 8||choice==7)
			choice_output(d, n, qs, zj, mb, a, b, c, src, tmp, dst,choice);
	}
	else if (n > 1) {
		hanoi1(d, n - 1, qs, mb, zj, a, c, b, src, tmp, dst,choice);
		if (choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 8)
			choice_output(d, n, qs, zj, mb, a, b, c, src, tmp, dst, choice);
		if(choice!=7)
		hanoi1(d, n - 1, zj, qs, mb, b, a, c, src, tmp, dst, choice);
	}
}

/*choice_output 选择输出方式*/
void choice_output(int d, int n, char qs, char zj, char mb, int a[], int b[], int c[], char src, char tmp, char dst,int choice) {
	if (choice == 1)
		output1(n, qs, zj, mb);
	else if (choice == 2)
		output2(n, qs, zj, mb);
	else if (choice == 3)
		output3(d, n, qs, zj, mb, a, b, c, src, tmp, dst);
	else if (choice == 4)
		output4(d, n, qs, zj, mb, a, b, c, src, tmp, dst, choice);
	else if (choice == 8)
		output8(d, n, qs, zj, mb, a, b, c, src, tmp, dst, choice);
	else if (choice == 7) {
		jisuan1(d, a, b, c);
		move(n, qs, mb, src, dst);
	}
}
/*选项1输出格式*/
void output1(int n, char qs, char zj, char mb) {
	cout << setw(2) << n << "# " << qs << "-->" << mb << endl;
 }
/*选项2输出格式*/
void output2(int n, char qs, char zj, char mb) {
	cout << "第" << setw(5) << i++ << "步: ";
	cout << setw(2) << n << "# " << qs << "-->" << mb << endl;
}
/*选项3输出格式*/
void output3(int d, int n, char qs, char zj, char mb, int a[], int b[], int c[], char src, char tmp, char dst) {
	jisuan1(d, a, b, c);
	cout << "第" << setw(4) << i++ << " 步(";
	cout << setw(2) << n << "): " << qs << "-->" << mb;

	heng_shuchu(d, src, dst);
}
/*选项4输出格式*/
void output4(int d, int n, char qs, char zj, char mb, int a[], int b[], int c[], char src, char tmp, char dst,int choice) {
	int w;
	cct_gotoxy(0, 0);
	zuoshangjiao(d, src, dst,choice);
	cct_gotoxy(10, 12);
	cout << "=========================";
	cct_gotoxy(12, 13);
	cout << "A         B         C" << endl;
	jisuan1(d, a, b, c);
	sleep(v);
	if (v == 0)
		w = _getch();
	cct_gotoxy(0, 17);
	cout << "第" << setw(4) << i++ << " 步(";
	cout << n << ": " << qs << "--> " << mb << ")";
	cct_gotoxy(23, 17);
	heng_shuchu(d,src, dst);
	
	zong_shuchu(d,src,dst,4);
	cct_gotoxy(1, 26);
}
/*选项8输出格式*/
void output8(int d, int n, char qs, char zj, char mb, int a[], int b[], int c[], char src, char tmp, char dst, int choice) {
	int w;
	cct_gotoxy(10, 27);
	cout << "=========================";
	cct_gotoxy(12, 28);
	cout << "A         B         C" << endl;

	int x = 0;//找起始柱栈顶值
	for (int p = 0; p < d; p++) {
		if (a[p] != 0) {
			x = a[p];
			break;
		}
	}
	if (x) {
		int  ka=0, kc=0, l = 0, k = 0;
		if (a == ss) {//1
			l = s;
		}
		else if (a == jj) {//2
			l = j;
		}
		else if (a == mm) {//3
			l = m ;
		}

		if (c == ss) {//1
			k = s;
		}
		else if (c == jj) {//2
			k = j;
		}
		else if (c == mm) {//3
			k = m;
		}
		ka = d - l;
		kc = d - k;
		if ((c[kc] < a[ka])&& c[kc]!=0&& a[ka]!=0) {
			cct_gotoxy(0, 35);
			cout << "大盘压小盘，非法输入！" << endl;
			Sleep(2000);
			cct_showch(0, 35, ' ', COLOR_BLACK, COLOR_WHITE, 25);
			return;
		}
		jisuan1(d, a, b, c);//top 变化
	}
	else {
		cct_gotoxy(0, 35);
		cout << "柱源为空！" << endl;
		Sleep(2000);
		cct_showch(0, 35, ' ', COLOR_BLACK, COLOR_WHITE,11);
		return;
	}


	sleep(v);
	if (v == 0)
		w = _getch();
	cct_gotoxy(0, 32);
	cout << "第" << setw(4) << i++ << " 步(";
	cout << n << ": " << qs << "--> " << mb << ")";
	cct_gotoxy(23, 32);
	heng_shuchu(d, src, dst);

	zong_shuchu(d, src, dst,8);

	move(n, qs, mb,src,dst);
	/* 恢复为初始颜色 */
	cct_setcolor();
	if (choice == 9 && m == d) {
		cct_gotoxy(0, 35);
		cout << "CONGRATULATIONS!!! YOU WIN!!! GAME OVER." << endl;
		Sleep(200);
		return;
	}
}

/*选项1*/
void no_1(int n,char qs,char zj, char mb,int choice) {
	i = 1;
	hanoi1(n, n, qs, zj, mb, ss, jj, mm, qs, zj, mb, choice);
}
void no_2(int n, char qs, char zj, char mb, int choice) {
	i = 1;
	hanoi1(n, n, qs, zj, mb, ss, jj, mm, qs, zj, mb, choice);
}
void no_3(int n, char qs, char zj, char mb, int choice) {
	i = 1;
	hanoi1(n, n, qs, zj, mb, ss, jj, mm, qs, zj, mb, choice);
}
void no_4(int n, char qs, char zj, char mb, int choice) {
	chushi_all(n, qs, choice);
	i = 1;
	hanoi1(n, n, qs, zj, mb, ss, jj, mm, qs, zj, mb, choice);
	v = 6;
}
/*真 横向输出盘子*/
void heng_shuchu(int d,char src, char dst) {

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
/*真 纵向输出盘子*/
void zong_shuchu(int d, char src, char dst,int choice) {
	if ((src == 'a' || src == 'A') && (dst == 'b' || dst == 'B')) {// 1
		shuchu2(d, ss, 0, choice);
		shuchu2(d, mm, 10,choice);
		shuchu2(d, jj, 20, choice);
	}
	else if ((src == 'a' || src == 'A') && (dst == 'c' || dst == 'C')) {// 2
		shuchu2(d, ss, 0, choice);
		shuchu2(d, jj, 10, choice);
		shuchu2(d, mm, 20, choice);
	}
	else if ((src == 'b' || src == 'B') && (dst == 'c' || dst == 'C')) {//3
		shuchu2(d, jj, 0, choice);
		shuchu2(d, ss, 10, choice);
		shuchu2(d, mm, 20, choice);
	}
	else if ((src == 'b' || src == 'B') && (dst == 'a' || dst == 'A')) {//4
		shuchu2(d, mm, 0, choice);
		shuchu2(d, ss, 10, choice);
		shuchu2(d, jj, 20, choice);
	}
	else if ((src == 'c' || src == 'C') && (dst == 'b' || dst == 'B')) {//5
		shuchu2(d, jj, 0, choice);
		shuchu2(d, mm, 10, choice);
		shuchu2(d, ss, 20, choice);
	}
	else if ((src == 'c' || src == 'C') && (dst == 'a' || dst == 'A')) {//6
		shuchu2(d, mm, 0, choice);
		shuchu2(d, jj, 10, choice);
		shuchu2(d, ss, 20, choice);
	}
}


/*计算空格数并赋值栈顶（3、4中的）*/
void jisuan1(int d, int a[], int b[], int c[]) {
	int  ka, kc, j, k;
	ka = d - (j = panduan1(a));
	kc = d - (k = panduan2(c));
	c[kc - 1] = a[ka];
	a[ka] = 0;
}
/*3、4中的两个小判断，看看哪个对应哪个，得的值给jisuan1,改变top*/
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

/*横向输出盘子*/
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
/*纵向输出盘子，也就是柱子*/
void shuchu2(int d, int a[], int with,int choice) {
	if (choice == 8||choice==9)
		choice = 15;
	else
		choice = 0;
	for (int p = d - 1; p >= 0; p--) {
		if (a[p] != 0) {
			cct_gotoxy(11 + with, 12 - (d - p)+ choice);
			cout << setw(2) << a[p];
		}
		else if (a[p] == 0) {
			cct_gotoxy(11 + with, 12 - (d - p)+ choice);
			cout << "  ";
		}
	}
}

//qs zj mb转大写
char change(char ch) {
	if (ch >= 97 && ch <= 99)
		ch -= 32;
	return ch;
}
/*开搞选项5,画柱子*/ 
void no_5() {
	cct_setcursor(CURSOR_INVISIBLE);
	const int LENGTH = 23;
	const int bg_color = COLOR_HYELLOW;	//背景为亮蓝色
	const int fg_color = COLOR_HYELLOW;		//前景为亮黄色
	cct_showstr(1, 15, " ", bg_color, fg_color, LENGTH);//第一个底座
	cct_showstr(1 + LENGTH + 9, 15, " ", bg_color, fg_color, LENGTH);//第二个底座
	cct_showstr(1 + 2 * (LENGTH + 9), 15, " ", bg_color, fg_color, LENGTH);//第三个底座

	for (int y = 14; y > 2; y--) {

		cct_showstr(12, y, " ", bg_color, fg_color, 1);
		cct_showstr(12 + 32, y, " ", bg_color, fg_color, 1);
		cct_showstr(12 + 32 + 32, y, " ", bg_color, fg_color, 1);

		/* 延时0.1秒 */
		Sleep(100);

	} //end

	/* 恢复为初始颜色 */
	cct_setcolor();
	cct_setcursor(CURSOR_VISIBLE_NORMAL);
}
/*开搞选项6，画圆盘*/
void no_6(int d,char qs,char mb,int choice) {
	cct_setcursor(CURSOR_INVISIBLE);
	zuoshangjiao(d, qs, mb, choice);
	no_5();//先弄出三根柱子
	int LENGTH;
	int bg_color, fg_color;
	for (int k = d, w = 14; k >= 1; k--) {//竖直打印起始柱子
		LENGTH = 2 * k + 1;
		bg_color = k;
		fg_color = k;
		cct_showstr(12 + (qs - 65) * 32 - k, w--, " ", bg_color, fg_color, LENGTH);
		Sleep(300);
	}
	/* 恢复为初始颜色 */
	cct_setcolor();
		
}
/*左上角一行字*/
void zuoshangjiao(int d,char src,char dst,int choice) {
	/* 恢复为初始颜色 */
	cct_setcolor();
	cout << "从 " << src << " 到 " << dst << "，共 " << d << " 层";
	if (choice == 4 || choice == 8)
		cout << "，延时设置为 " << v;
}
void continue1() {
	char ch;
	cout << endl;
	cout << "按回车键继续";
	ch=_getch();
}

/*圆盘向上移动*/  //a是原top
void up_move(int n,int a,char ch) {//n是变化的盘数,就是特指我要移动的盘盘
								   //a是top1，盘数，也就是s、j、m

	/* 将一串字符从下向上移动 */
	for (int y = 14 - a; y >= 1; y--) {
		//12 + (ch - 65) * 32表示ch柱的中心位置
		cct_showstr(12 + (ch - 65) * 32 - n, y, " ", n, n, 2 * n + 1);

		if (v > 0 && v <= 5) {
			sleep(v);
		}
		else if (v == 0) {
			Sleep(1500);
		}
		else {
			/* 延时0.05秒 */
			Sleep(50);
		}
		if (y > 1) {
			/* 清除显示(最后一次保留)，清除方法为用正常颜色+空格重画一遍刚才的位置 */
			cct_showch(12 + (ch - 65) * 32 - n, y, ' ', COLOR_BLACK, COLOR_WHITE, 2 * n + 1);
		}

		if (y >= 3 && y <= 14) {//柱子被涂掉了要再画上去
			cct_showch(12 + (ch - 65) * 32, y, ' ', COLOR_HYELLOW, COLOR_HYELLOW, 1);
		}
	} //end of for
}//
/*圆盘向下移动*/  //c是后top
void down_move(int n, int c, char ch) {//n是变化的盘数,就是特指我要移动的盘盘
								   //a是top1，盘数，也就是s、j、m
	int y;
	/* 将一串字符从上向下移动 */
	for (y = 1; y <= 15 - c; y++) {
		//12 + (ch - 65) * 32表示ch柱的中心位置
		cct_showstr(12 + (ch - 65) * 32 - n, y, " ", n, n, 2 * n + 1);

		if (v > 0 && v <= 5) {
			sleep(v);
		}
		else if (v == 0) {
			Sleep(1500);
		}
		else {
			/* 延时0.05秒 */
			Sleep(50);
		}
		if (y <= 14 - c) {
			/* 清除显示(最后一次保留)，清除方法为用正常颜色+空格重画一遍刚才的位置 */
			cct_showch(12 + (ch - 65) * 32 - n, y, ' ', COLOR_BLACK, COLOR_WHITE, 2 * n + 1);
		}
		if (y >= 3 && y < 15 - c) {//柱子被涂掉了要再画上去
			cct_showch(12 + (ch - 65) * 32, y, ' ', COLOR_HYELLOW, COLOR_HYELLOW, 1);
		}
	} //end of for

}
/*圆盘向右移动*/
void right_move(int n, char from, char to) {//n限制盘大小 
	/* 将一串字符从左向右移动 */
	int x;
	for (x = 12 + (from - 65) * 32; x < 12 + (to - 65) * 32; x++) {
	
		cct_showch(x - n, 1, ' ', n, n, 2*n+1);

		if (v > 0 && v <= 5) {
			sleep(v);
		}
		else if (v == 0) {
			Sleep(1500);
		}
		else {
			/* 延时0.05秒 */
			Sleep(50);
		}

		if (x < 12 + (to - 65) * 32) {
			/* 清除显示(最后一次保留)，清除方法为用正常颜色+空格重画一遍刚才的位置 */
			cct_showch(x - n, 1, ' ', COLOR_BLACK, COLOR_WHITE, 2 * n + 1);
		}
	} //end of for
}
/*圆盘向左移动*/
void left_move(int n, char from, char to) {//n限制盘大小 
	/* 将一串字符从右向左移动 */
	int x;
	for (x = 12 + (from - 65) * 32; x > 12 + (to - 65) * 32; x--) {

		cct_showch(x - n, 1, ' ', n, n, 2 * n + 1);
		if (v > 0 && v <= 5) {
			sleep(v);
		}
		else if (v == 0) {
			Sleep(1500);
		}
		else {
			/* 延时0.05秒 */
			Sleep(50);
		}

		if (x > 12 + (to - 65) * 32) {
			/* 清除显示(最后一次保留)，清除方法为用正常颜色+空格重画一遍刚才的位置 */
			cct_showch(x - n, 1, ' ', COLOR_BLACK, COLOR_WHITE, 2 * n + 1);
		}
	} //end of for
}
void before_heng_move(int n,char from,char to) {
	if (from == 'A')
		right_move(n,from,to );
	else if (from == 'C')
		left_move(n, from, to);
	else if (from == 'B' && to == 'A')
		left_move(n, from, to);
	else if (from == 'B' && to == 'C')
		right_move(n, from, to);
}
/*圆盘移动，组合起来*/ //第n个盘，从from柱栈顶a移动到to柱栈顶c
void all_move(int n, int a, int c, char from, char to) {
	cct_setcursor(CURSOR_INVISIBLE);
	up_move(n, a, from);
	before_heng_move(n, from,to);
	down_move(n, c, to);
	cct_setcursor(CURSOR_VISIBLE_NORMAL);
}

void move(int n, char from, char to, char src, char dst) {
	if ((src == 'a' || src == 'A') && (dst == 'b' || dst == 'B')) {//1
		move2(n, from, to, src, dst);
	}
	else if ((src == 'a' || src == 'A') && (dst == 'c' || dst == 'C')) {//2
		move1(n, from, to, src, dst);
	}
	else if ((src == 'b' || src == 'B') && (dst == 'c' || dst == 'C')) {//3
		move3(n, from, to, src, dst);
	}
	else if ((src == 'b' || src == 'B') && (dst == 'a' || dst == 'A')) {//4
		move4(n, from, to, src, dst);

	}
	else if ((src == 'c' || src == 'C') && (dst == 'b' || dst == 'B')) {//5
		move6(n, from, to, src, dst);
	}
	else if ((src == 'c' || src == 'C') && (dst == 'a' || dst == 'A')) {//6
		move5(n, from, to, src, dst);
	}
}
/*ACworld*/
void move1(int n, char from, char to, char src, char dst) {
	if (from == 'A' && to == 'B')
		all_move(n, s, j, 'A', 'B');
	else if (from == 'A' && to == 'C')
		all_move(n, s, m, 'A', 'C');
	else if (from == 'C' && to == 'B')
		all_move(n, m, j, 'C', 'B');
	else if (from == 'C' && to == 'A')
		all_move(n, m, s, 'C', 'A');
	else if (from == 'B' && to == 'A')
		all_move(n, j, s, 'B', 'A');
	else if (from == 'B' && to == 'C')
		all_move(n, j, m, 'B', 'C');
}
/*ABworld*/
void move2(int n, char from, char to, char src, char dst) {
	if (from == 'A' && to == 'B')
		all_move(n, s, m, 'A', 'B');
	else if (from == 'A' && to == 'C')
		all_move(n, s,j, 'A', 'C');
	else if (from == 'C' && to == 'B')
		all_move(n, j, m, 'C', 'B');
	else if (from == 'C' && to == 'A')
		all_move(n, j, s, 'C', 'A');
	else if (from == 'B' && to == 'A')
		all_move(n, m, s, 'B', 'A');
	else if (from == 'B' && to == 'C')
		all_move(n, m, j, 'B', 'C');
}
/*BCworld*/
void move3(int n, char from, char to, char src, char dst) {
	if (from == 'A' && to == 'B')
		all_move(n, j, s, 'A', 'B');
	else if (from == 'A' && to == 'C')
		all_move(n, j, m, 'A', 'C');
	else if (from == 'C' && to == 'B')
		all_move(n, m, s, 'C', 'B');
	else if (from == 'C' && to == 'A')
		all_move(n, m, j, 'C', 'A');
	else if (from == 'B' && to == 'A')
		all_move(n, s, j, 'B', 'A');
	else if (from == 'B' && to == 'C')
		all_move(n, s, m, 'B', 'C');
}
/*BAworld*/
void move4(int n, char from, char to, char src, char dst) {
	if (from == 'A' && to == 'B')
		all_move(n, m, s, 'A', 'B');
	else if (from == 'A' && to == 'C')
		all_move(n, m, j, 'A', 'C');
	else if (from == 'C' && to == 'B')
		all_move(n, j, s, 'C', 'B');
	else if (from == 'C' && to == 'A')
		all_move(n, j, m, 'C', 'A');
	else if (from == 'B' && to == 'A')
		all_move(n, s, m, 'B', 'A');
	else if (from == 'B' && to == 'C')
		all_move(n, s, m, 'B', 'C');
}
/*CAworld*/
void move5(int n, char from, char to, char src, char dst) {
	if (from == 'A' && to == 'B')
		all_move(n, m, j, 'A', 'B');
	else if (from == 'A' && to == 'C')
		all_move(n, m, s, 'A', 'C');
	else if (from == 'C' && to == 'B')
		all_move(n, s, j, 'C', 'B');
	else if (from == 'C' && to == 'A')
		all_move(n, s, m, 'C', 'A');
	else if (from == 'B' && to == 'A')
		all_move(n, j, m, 'B', 'A');
	else if (from == 'B' && to == 'C')
		all_move(n, j, m, 'B', 'C');
}
/*CBworld*/
void move6(int n, char from, char to, char src, char dst) {
	if (from == 'A' && to == 'B')
		all_move(n, j, m, 'A', 'B');
	else if (from == 'A' && to == 'C')
		all_move(n, j, s, 'A', 'C');
	else if (from == 'C' && to == 'B')
		all_move(n, s, m, 'C', 'B');
	else if (from == 'C' && to == 'A')
		all_move(n, s, j, 'C', 'A');
	else if (from == 'B' && to == 'A')
		all_move(n, m, j, 'B', 'A');
	else if (from == 'B' && to == 'C')
		all_move(n, m, j, 'B', 'C');
}

/*延时*/
void sleep(int v) {
	
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

}
/*开搞选项7，第一次移动*/
void no_7(int d, char qs, char mb,int choice) {
	v = 6;
	char zj;
	zj = 'A' + 'B' + 'C' - qs - mb;
	no_6(d, qs, mb,choice);//先弄三根柱子和起始的盘子
	hanoi1(d, d, qs, zj, mb, ss, jj, mm, qs, zj, mb, choice);
	/* 恢复为初始颜色 */
	cct_setcolor();
}
/*选项8，普适性*/
void no_8(int d, char qs,char zj, char mb, int choice) {
	i = 1;
	no_6(d, qs, mb, choice);//先弄三根柱子和起始的盘子
	cct_setcursor(CURSOR_VISIBLE_NORMAL);
	chushi_all(d, qs, choice);

	hanoi1(d, d, qs, zj, mb, ss, jj, mm, qs, zj, mb, choice);
	v = 6;
}
/*感天动地，最后一个*/
void no_9(int d, char qs, char zj, char mb, int choice) {
	i = 1;
	no_6(d, qs, mb, choice);//先弄三根柱子和起始的盘子
	cct_setcursor(CURSOR_VISIBLE_NORMAL);
	chushi_all(d, qs, choice);//初始
	input_9(d,qs, mb,choice);//起始两个盘
	
}
/*初始化，选项4,8,9*/
void chushi_heng(int d, char src,int choice) {
	int t;
	if (choice == 8 || choice == 9)
		t = 15;
	else
		t = 0;
	cct_gotoxy(0, 17+t);
	cout << "初始：";
	cct_gotoxy(23, 17 + t);
	if (src == 'a' || src == 'A'){//1
		cout << " A:";
		shuchu1(d, ss);
		cout << " B:";
		shuchu1(d, mm);
		cout << " C:";
		shuchu1(d, jj);
		cout << endl;
	}
	else if (src == 'b' || src == 'B') {//2
		cout << " A:";
		shuchu1(d, jj);
		cout << " B:";
		shuchu1(d, ss);
		cout << " C:";
		shuchu1(d, mm);
		cout << endl;
	}
	else if (src == 'c' || src == 'C') {//3
		cout << " A:";
		shuchu1(d, jj);
		cout << " B:";
		shuchu1(d, mm);
		cout << " C:";
		shuchu1(d, ss);
		cout << endl;
	}
}
void chushi_zong(int d, char src,int choice) {
	int t;
	if (choice == 8||choice==9)
		t = 15;
	else
		t = 0;
	cct_gotoxy(10, 12+t);
	cout << "=========================";
	cct_gotoxy(12, 13+t);
	cout << "A         B         C" << endl;
	if (src == 'a' || src == 'A') {// 1
		shuchu2(d, ss, 0, choice);
		shuchu2(d, mm, 10, choice);
		shuchu2(d, jj, 20, choice);
	}
	else if (src == 'b' || src == 'B') {// 2
		shuchu2(d,jj , 0, choice);
		shuchu2(d, ss, 10, choice);
		shuchu2(d, mm, 20, choice);
	}
	else if (src == 'c' || src == 'C'){//3
		shuchu2(d, jj, 0, choice);
		shuchu2(d, mm, 10, choice);
		shuchu2(d, ss, 20, choice);
	}
}
void chushi_all(int d, char src, int choice) {
	chushi_heng(d, src,choice);
	chushi_zong(d, src, choice);
}

void input_9(int n,char src, char dst, int choice) {
	cct_setcursor(CURSOR_VISIBLE_NORMAL);
	char qs,mb,zj=0,tmp,ch[20],kg;//手写的两个盘
	
	while (1) {
		if (m == n)
			return;
		cct_gotoxy(0, 34);
		cout << "请输入移动的柱号(命令形式：AC=A顶端的盘子移动到C，Q=退出) ：";
		for (int k=0; k < 20; k++) {
			if((ch[k] = _getche()) == '\r')
				break;
		}
		cct_showch(58, 34, ' ', COLOR_BLACK, COLOR_WHITE, 24);
		qs = ch[0];
		mb = ch[1];
		kg = ch[2];
		if ((ch[0] == 'q' || ch[0] == 'Q') && ch[1] == '\r') {
			cout << endl;
			cout << "游戏中止！！！";
			cout << endl;
			return;
		}
		if (ch[2] != '\r')
			continue;
		qs = change(qs);
		mb = change(mb);
		zj = 'A' + 'B' + 'C' - qs - mb;
		tmp = 'A' + 'B' + 'C' - src - dst;
		

		if ((src == 'a' || src == 'A') && (dst == 'b' || dst == 'B')) {// 1
			choiceAB(n, qs, zj, mb, src, tmp, dst, choice);
		}
		else if ((src == 'a' || src == 'A') && (dst == 'c' || dst == 'C')) {// 2
			choiceAC(n, qs, zj, mb, src, tmp, dst, choice);
		}
		else if ((src == 'b' || src == 'B') && (dst == 'c' || dst == 'C')) {//3
			choiceBC(n, qs, zj, mb, src, tmp, dst, choice);
		}
		else if ((src == 'b' || src == 'B') && (dst == 'a' || dst == 'A')) {//4
			choiceBA(n, qs, zj, mb, src, tmp, dst, choice);
		}
		else if ((src == 'c' || src == 'C') && (dst == 'b' || dst == 'B')) {//5
			choiceCB(n, qs, zj, mb, src, tmp, dst, choice);
		}
		else if ((src == 'c' || src == 'C') && (dst == 'a' || dst == 'A')) {//6
			choiceCA(n, qs, zj, mb, src, tmp, dst, choice);
		}
		
	}
}
void choiceAC(int n, char qs, char zj, char mb, char src, char tmp, char dst, int choice) {
	int x=0;
	if ((qs == 'a' || qs == 'A') && (mb == 'b' || mb == 'B')) {
		for (int p=0; p <n; p++) {
			if (ss[p] != 0) {
				x = ss[p];
				break;
			}
		}
		output8(n, x, qs, zj, mb, ss, mm, jj, src, tmp, dst, choice);
	}
	else if ((qs == 'a' || qs == 'A') && (mb == 'c' || mb == 'C')) {
		for (int p = 0; p < n; p++) {
			if (ss[p] != 0) {
				x = ss[p];
				break;
			}
		}
		output8(n, x, qs, zj, mb, ss, jj, mm, src, tmp, dst, choice);
	}
	else if ((qs == 'b' || qs == 'B') && (mb == 'c' || mb == 'C')) {
		for (int p = 0; p < n; p++) {
			if (jj[p] != 0) {
				x = jj[p];
				break;
			}
		}
		output8(n, x, qs, zj, mb, jj, ss, mm, src, tmp, dst, choice);
	}
	else if ((qs == 'b' || qs == 'B') && (mb == 'a' || mb == 'A')) {
		for (int p = 0; p < n; p++) {
			if (jj[p] != 0) {
				x = jj[p];
				break;
			}
		}
		output8(n, x, qs, zj, mb, jj, mm, ss, src, tmp, dst, choice);
	}
	else if ((qs == 'c' || qs == 'C') && (mb == 'b' || mb == 'B')) {
		for (int p = 0; p < n; p++) {
			if (mm[p] != 0) {
				x = mm[p];
				break;
			}
		}
		output8(n, x, qs, zj, mb, mm, ss, jj, src, tmp, dst, choice);
	}
	else if ((qs == 'c' || qs == 'C') && (mb == 'a' || mb == 'A')) {
		for (int p = 0; p < n; p++) {
			if (mm[p] != 0) {
				x = mm[p];
				break;
			}
		}
		output8(n, x, qs, zj, mb, mm, jj, ss, src, tmp, dst, choice);
	}
}
void choiceAB(int n, char qs, char zj, char mb, char src, char tmp, char dst, int choice) {//ssmmjj
	int x = 0;
	if ((qs == 'a' || qs == 'A') && (mb == 'b' || mb == 'B')) {
		for (int p = 0; p < n; p++) {
			if (ss[p] != 0) {
				x = ss[p];
				break;
			}
		}
		output8(n,x, qs, zj, mb, ss, jj, mm, src, tmp, dst, choice);
	}
	else if ((qs == 'a' || qs == 'A') && (mb == 'c' || mb == 'C')) {
		for (int p = 0; p < n; p++) {
			if (ss[p] != 0) {
				x = ss[p];
				break;
			}
		}
		output8(n, x, qs, zj, mb, ss, mm, jj, src, tmp, dst, choice);
	}
	else if ((qs == 'b' || qs == 'B') && (mb == 'c' || mb == 'C')) {
		for (int p = 0; p < n; p++) {
			if (mm[p] != 0) {
				x = mm[p];
				break;
			}
		}
		output8(n, x, qs, zj, mb, mm, ss, jj, src, tmp, dst, choice);
	}
	else if ((qs == 'b' || qs == 'B') && (mb == 'a' || mb == 'A')) {
		for (int p = 0; p < n; p++) {
			if (mm[p] != 0) {
				x = mm[p];
				break;
			}
		}
		output8(n, x, qs, zj, mb, mm, jj, ss, src, tmp, dst, choice);
	}
	else if ((qs == 'c' || qs == 'C') && (mb == 'b' || mb == 'B')) {
		for (int p = 0; p < n; p++) {
			if (jj[p] != 0) {
				x = jj[p];
				break;
			}
		}
		output8(n, x, qs, zj, mb, jj, ss, mm, src, tmp, dst, choice);
	}
	else if ((qs == 'c' || qs == 'C') && (mb == 'a' || mb == 'A')) {
		for (int p = 0; p < n; p++) {
			if (jj[p] != 0) {
				x = jj[p];
				break;
			}
		}
		output8(n, x, qs, zj, mb, jj, mm, ss, src, tmp, dst, choice);
	}
}
void choiceBA(int n, char qs, char zj, char mb, char src, char tmp, char dst, int choice) {//
	int x = 0;
	if ((qs == 'a' || qs == 'A') && (mb == 'b' || mb == 'B')) {
		for (int p = 0; p < n; p++) {
			if (mm[p] != 0) {
				x = mm[p];
				break;
			}
		}
		output8(n, x, qs, zj, mb, mm, jj, ss, src, tmp, dst, choice);
	}
	else if ((qs == 'a' || qs == 'A') && (mb == 'c' || mb == 'C')) {
		for (int p = 0; p < n; p++) {
			if (mm[p] != 0) {
				x = mm[p];
				break;
			}
		}
		output8(n, x, qs, zj, mb, mm, ss, jj, src, tmp, dst, choice);
	}
	else if ((qs == 'b' || qs == 'B') && (mb == 'c' || mb == 'C')) {
		for (int p = 0; p < n; p++) {
			if (ss[p] != 0) {
				x = ss[p];
				break;
			}
		}
		output8(n, x, qs, zj, mb, ss, mm, jj, src, tmp, dst, choice);
	}
	else if ((qs == 'b' || qs == 'B') && (mb == 'a' || mb == 'A')) {
		for (int p = 0; p < n; p++) {
			if (ss[p] != 0) {
				x = ss[p];
				break;
			}
		}
		output8(n, x, qs, zj, mb, ss, jj, mm, src, tmp, dst, choice);
	}
	else if ((qs == 'c' || qs == 'C') && (mb == 'b' || mb == 'B')) {
		for (int p = 0; p < n; p++) {
			if (jj[p] != 0) {
				x = jj[p];
				break;
			}
		}
		output8(n, x, qs, zj, mb, jj, mm, ss, src, tmp, dst, choice);
	}
	else if ((qs == 'c' || qs == 'C') && (mb == 'a' || mb == 'A')) {
		for (int p = 0; p < n; p++) {
			if (jj[p] != 0) {
				x = jj[p];
				break;
			}
		}
		output8(n, x, qs, zj, mb, jj, ss, mm, src, tmp, dst, choice);
	}
}
void choiceBC(int n, char qs, char zj, char mb, char src, char tmp, char dst, int choice) {//
	int x = 0;
	if ((qs == 'a' || qs == 'A') && (mb == 'b' || mb == 'B')) {
		for (int p = 0; p < n; p++) {
			if (jj[p] != 0) {
				x = jj[p];
				break;
			}
		}
		output8(n, x, qs, zj, mb, jj, mm, ss, src, tmp, dst, choice);
	}
	else if ((qs == 'a' || qs == 'A') && (mb == 'c' || mb == 'C')) {
		for (int p = 0; p < n; p++) {
			if (jj[p] != 0) {
				x = jj[p];
				break;
			}
		}
		output8(n, x, qs, zj, mb, jj, ss, mm, src, tmp, dst, choice);
	}
	else if ((qs == 'b' || qs == 'B') && (mb == 'c' || mb == 'C')) {
		for (int p = 0; p < n; p++) {
			if (ss[p] != 0) {
				x = ss[p];
				break;
			}
		}
		output8(n, x, qs, zj, mb, ss, jj, mm, src, tmp, dst, choice);
	}
	else if ((qs == 'b' || qs == 'B') && (mb == 'a' || mb == 'A')) {
		for (int p = 0; p < n; p++) {
			if (ss[p] != 0) {
				x = ss[p];
				break;
			}
		}
		output8(n, x, qs, zj, mb, ss, mm, jj, src, tmp, dst, choice);
	}
	else if ((qs == 'c' || qs == 'C') && (mb == 'b' || mb == 'B')) {
		for (int p = 0; p < n; p++) {
			if (mm[p] != 0) {
				x = mm[p];
				break;
			}
		}
		output8(n, x, qs, zj, mb, mm, jj, ss, src, tmp, dst, choice);
	}
	else if ((qs == 'c' || qs == 'C') && (mb == 'a' || mb == 'A')) {
		for (int p = 0; p < n; p++) {
			if (mm[p] != 0) {
				x = mm[p];
				break;
			}
		}
		output8(n, x, qs, zj, mb, mm, ss, jj, src, tmp, dst, choice);
	}
}
void choiceCB(int n, char qs, char zj, char mb, char src, char tmp, char dst, int choice) {//
	int x=0;
	if ((qs == 'a' || qs == 'A') && (mb == 'b' || mb == 'B')) {
		for (int p = 0; p < n; p++) {
			if (jj[p] != 0) {
				x =jj[p];
				break;
			}
		}
		output8(n, x, qs, zj, mb, jj, ss, mm, src, tmp, dst, choice);
	}
	else if ((qs == 'a' || qs == 'A') && (mb == 'c' || mb == 'C')) {
		for (int p = 0; p < n; p++) {
			if (jj[p] != 0) {
				x = jj[p];
				break;
			}
		}
		output8(n, x, qs, zj, mb, jj, mm, ss, src, tmp, dst, choice);
	}
	else if ((qs == 'b' || qs == 'B') && (mb == 'c' || mb == 'C')) {
		for (int p = 0; p < n; p++) {
			if (mm[p] != 0) {
				x = mm[p];
				break;
			}
		}
		output8(n, x, qs, zj, mb, mm, jj, ss, src, tmp, dst, choice);
	}
	else if ((qs == 'b' || qs == 'B') && (mb == 'a' || mb == 'A')) {
		for (int p = 0; p < n; p++) {
			if (mm[p] != 0) {
				x = mm[p];
				break;
			}
		}
		output8(n, x, qs, zj, mb, mm, ss, jj, src, tmp, dst, choice);
	}
	else if ((qs == 'c' || qs == 'C') && (mb == 'b' || mb == 'B')) {
		for (int p = 0; p < n; p++) {
			if (ss[p] != 0) {
				x = ss[p];
				break;
			}
		}
		output8(n, x, qs, zj, mb, ss, jj, mm, src, tmp, dst, choice);
	}
	else if ((qs == 'c' || qs == 'C') && (mb == 'a' || mb == 'A')) {
		for (int p = 0; p < n; p++) {
			if (ss[p] != 0) {
				x = ss[p];
				break;
			}
		}
		output8(n, x, qs, zj, mb, ss, mm, jj, src, tmp, dst, choice);
	}
}
void choiceCA(int n, char qs, char zj, char mb, char src, char tmp, char dst, int choice) {//
	int x = 0;
	if ((qs == 'a' || qs == 'A') && (mb == 'b' || mb == 'B')) {
		for (int p = 0; p < n; p++) {
			if (mm[p] != 0) {
				x = mm[p];
				break;
			}
		}
		output8(n, x, qs, zj, mb, mm, ss, jj, src, tmp, dst, choice);
	}
	else if ((qs == 'a' || qs == 'A') && (mb == 'c' || mb == 'C')) {
		for (int p = 0; p < n; p++) {
			if (mm[p] != 0) {
				x = mm[p];
				break;
			}
		}
		output8(n, n -m + 1, qs, zj, mb, mm, jj, ss, src, tmp, dst, choice);
	}
	else if ((qs == 'b' || qs == 'B') && (mb == 'c' || mb == 'C')) {
		for (int p = 0; p < n; p++) {
			if (jj[p] != 0) {
				x = jj[p];
				break;
			}
		}
		output8(n, x, qs, zj, mb, jj, mm, ss, src, tmp, dst, choice);
	}
	else if ((qs == 'b' || qs == 'B') && (mb == 'a' || mb == 'A')) {
		for (int p = 0; p < n; p++) {
			if (jj[p] != 0) {
				x = jj[p];
				break;
			}
		}
		output8(n, x, qs, zj, mb, jj, ss, mm, src, tmp, dst, choice);
	}
	else if ((qs == 'c' || qs == 'C') && (mb == 'b' || mb == 'B')) {
		for (int p = 0; p < n; p++) {
			if (ss[p] != 0) {
				x = ss[p];
				break;
			}
		}
		output8(n, x, qs, zj, mb, ss, mm, jj, src, tmp, dst, choice);
	}
	else if ((qs == 'c' || qs == 'C') && (mb == 'a' || mb == 'A')) {
		for (int p = 0; p < n; p++) {
			if (ss[p] != 0) {
				x = ss[p];
				break;
			}
		}
		output8(n, x, qs, zj, mb, ss, jj, mm, src, tmp, dst, choice);
	}
}

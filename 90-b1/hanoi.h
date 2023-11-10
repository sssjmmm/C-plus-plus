/* 信16 2151299 苏家铭 */
#pragma once

/* ------------------------------------------------------------------------------------------------------

     本文件功能：
	1、为了保证 hanoi_main.cpp/hanoi_menu.cpp/hanoi_multiple_solutions.cpp 能相互访问函数的函数声明
	2、一个以上的cpp中用到的宏定义（#define）或全局只读（const）变量，个数不限
	3、可以参考 cmd_console_tools.h 的写法（认真阅读并体会）
   ------------------------------------------------------------------------------------------------------ */
void hanoi1(int d, int n, char qs, char zj, char mb, int a[], int b[], int c[], char src, char tmp, char dst, int choice);
void choice_output(int d, int n, char qs, char zj, char mb, int a[], int b[], int c[], char src, char tmp, char dst, int choice);
void output1(int n, char qs, char zj, char mb);
void output2(int n, char qs, char zj, char mb);
void output3(int d, int n, char qs, char zj, char mb, int a[], int b[], int c[], char src, char tmp, char dst);
void output4(int d, int n, char qs, char zj, char mb, int a[], int b[], int c[], char src, char tmp, char dst,int choice);
void output8(int d, int n, char qs, char zj, char mb, int a[], int b[], int c[], char src, char tmp, char dst, int choice);
void jisuan1(int d, int a[], int b[], int c[]);
int panduan1(int a[]);
int panduan2(int c[]);
void shuchu1(int d, int a[]);
void shuchu2(int d, int a[], int with, int choice);
void input(int* d, char* qs, char* zj, char* mb, int choice);
int hanoi_menu();
char change(char ch);
void up_move(int n, int a, char ch);
void down_move(int n, int a, char ch);
void right_move(int n, char from, char to);
void left_move(int n, char from, char to);
void sleep(int v);
void continue1();
void heng_shuchu(int d, char src, char dst);
void zong_shuchu(int d, char src, char dst, int choice);
void before_heng_move(int n, char from, char to);
void all_move(int n, int a, int c, char from, char to);
void zuoshangjiao(int d, char src, char dst, int choice);
void no_1(int n, char qs, char zj, char mb, int choice);
void no_2(int n, char qs, char zj, char mb, int choice);
void no_3(int n, char qs, char zj, char mb, int choice);
void no_4(int n, char qs, char zj, char mb, int choice);
void no_5();
void no_6(int d, char qs, char mb, int choice);
void no_7(int d, char qs, char mb, int choice);
void no_8(int d, char qs, char zj, char mb, int choice);
void no_9(int d, char qs, char zj, char mb, int choice);
void continue1();
void move(int n, char from, char to, char src, char dst);
void move1(int n, char from, char to, char src, char dst);
void move2(int n, char from, char to, char src, char dst);
void move3(int n, char from, char to, char src, char dst);
void move4(int n, char from, char to, char src, char dst);
void move5(int n, char from, char to, char src, char dst);
void move6(int n, char from, char to, char src, char dst);
void chushi_heng(int d, char src,int choice);
void chushi_zong(int d, char src, int choice);
void chushi_all(int d, char src, int choice);
void input_9(int n, char src, char dst, int choice);
void choiceAC(int n, char qs, char zj, char mb, char src, char tmp, char dst, int choice);
void choiceAB(int n, char qs, char zj, char mb, char src, char tmp, char dst, int choice);
void choiceBC(int n, char qs, char zj, char mb, char src, char tmp, char dst, int choice);
void choiceBA(int n, char qs, char zj, char mb, char src, char tmp, char dst, int choice);
void choiceCA(int n, char qs, char zj, char mb, char src, char tmp, char dst, int choice);
void choiceCB(int n, char qs, char zj, char mb, char src, char tmp, char dst, int choice);
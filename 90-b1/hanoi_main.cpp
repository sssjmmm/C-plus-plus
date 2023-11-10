/* 信16 2151299 苏家铭 */
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include<conio.h>
#include"cmd_console_tools.h"
#include"hanoi.h"
using namespace std;

/* ----------------------------------------------------------------------------------

     本文件功能：
	1、放main函数
	2、初始化屏幕
	3、调用菜单函数（hanoi_menu.cpp中）并返回选项
	4、根据选项调用菜单各项对应的执行函数（hanoi_multiple_solutions.cpp中）

     本文件要求：
	1、不允许定义全局变量（含外部全局和静态全局，const及#define不在限制范围内）
	2、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
	3、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------------------------------------------------- */

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
	while (1) {
		int n = 0, choice;
		char qs = 0, zj = 0, mb = 0;
		/* demo中首先执行此句，将cmd窗口设置为40行x120列（缓冲区宽度120列，行数9000行，即cmd窗口右侧带有垂直滚动杆）*/
		cct_setconsoleborder(120, 40, 120, 9000);
		cct_cls();
		choice = hanoi_menu();
		cct_gotoxy(0, 14);
		cout << endl;
		if (choice == 1) {
			input(&n, &qs, &zj, &mb, choice);
			no_1(n, qs, zj, mb, choice);
			continue1();
		}
		else if (choice == 2) {
			input(&n, &qs, &zj, &mb, choice);
			no_2(n, qs, zj, mb, choice);
			continue1();
		}
		else if (choice == 3) {
			input(&n, &qs, &zj, &mb, choice);
			no_3(n, qs, zj, mb, choice);
			continue1();
		}
		else if (choice == 4) {
			input(&n, &qs, &zj, &mb, choice);
			cct_cls();
			no_4(n, qs, zj, mb, choice);
			continue1();
		}
		else if (choice == 5) {
			cct_cls();
			no_5();
			cct_gotoxy(0, 36);
			continue1();
		}
		else if (choice == 6) {
			input(&n, &qs, &zj, &mb, choice);
			cct_cls();
			no_6(n, qs, mb, choice);
			cct_gotoxy(0, 36);
			continue1();
		}
		else if (choice == 7) {
			input(&n, &qs, &zj, &mb, choice);
			cct_cls();
			no_7(n, qs, mb, choice);
			cct_gotoxy(0, 36);
			continue1();
		}
		else if (choice == 8) {
			input(&n, &qs, &zj, &mb, choice);

			cct_cls();
			no_8(n, qs, zj, mb, choice);
			cct_gotoxy(0, 36);
			continue1();
		}
		else if (choice == 9) {
			input(&n, &qs, &zj, &mb, choice);
			cct_cls();
			no_9(n, qs, zj, mb, choice);
			continue1();
		}
		else if (choice == 0) {
			break;
		}
	}

	return 0;
}

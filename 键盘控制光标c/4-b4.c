/* 2151299 苏家铭 信16 */
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

const int MAX_X = 69;	//定义*组成的边框的宽度
const int MAX_Y = 17;	//定义*组成的边框的高度

/***************************************************************************
  函数名称：
  功    能：完成与system("cls")一样的功能，但效率高
  输入参数：
  返 回 值：
  说    明：清除整个屏幕缓冲区，不仅仅是可见窗口区域(使用当前颜色)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* 取当前缓冲区信息 */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* 填充字符 */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* 填充属性 */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* 光标回到(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  函数名称：gotoxy
  功    能：将光标移动到指定位置
  输入参数：HANDLE hout：输出设备句柄
			int X      ：指定位置的x坐标
			int Y      ：指定位置的y坐标
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  函数名称：showch
  功    能：在指定位置处打印一个指定的字符
  输入参数：HANDLE hout：输出设备句柄
			int X      ：指定位置的x坐标
			int Y      ：指定位置的y坐标
			char ch    ：要打印的字符
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  函数名称：init_border
  功    能：显示初始的边框及随机字符
  输入参数：HANDLE hout：输出设备句柄
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//光标移回左上角(0,0)
	printf("***********************************************************************\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("***********************************************************************\n");

	/* 随机显示20个大写字母，字母的值、XY坐标都随机显示
	   rand()函数的功能：随机生成一个在 0-32767 之间的整数
	   思考：在什么情况下，下面这个循环执行生成后，你看到的实际字母个数不足20个？ */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}


void menu();
void move_by_ijkl(int i) {
	int ch;
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄

	/* 显示初始的边框及其中的随机字符 */
	init_border(hout);

	/*初始光标位置*/
	int x, y;
	x = 35;
	y = 9;
	gotoxy(hout, x, y);

	while (i == 1) {
		ch = _getch();
		if (ch == 73 || ch == 105) {//I i
			if (y > 1) {
				gotoxy(hout, x, --y);
				continue;
			}

		}

		else if (ch == 74 || ch == 106) {//J j
			if (x > 1) {
				gotoxy(hout, --x, y);
				continue;
			}

		}

		else if (ch == 75 || ch == 107) {//K k
			if (y < 17) {
				gotoxy(hout, x, ++y);
				continue;
			}

		}

		else if (ch == 76 || ch == 108) {//L l
			if (x < 69) {
				gotoxy(hout, ++x, y);
				continue;
			}

		}

		else if (ch == 32) {//空格
			showch(hout, x, y, ' ');
			gotoxy(hout, x, y);
			continue;
		}

		else if (ch == 113 || ch == 81) {//q Q 退出
			break;
		}

	}

	while (i == 2) {
		ch = _getch();
		if (ch == 73 || ch == 105) {//I i
			if (y > 1) {
				gotoxy(hout, x, --y);
				continue;
			}
			else if (y == 1) {
				y = 17;
				gotoxy(hout, x, y);
				continue;
			}
		}

		else if (ch == 74 || ch == 106) {//J j
			if (x > 1) {
				gotoxy(hout, --x, y);
				continue;
			}
			else if (x == 1) {
				x = 69;
				gotoxy(hout, x, y);
				continue;
			}

		}

		else if (ch == 75 || ch == 107) {//K k
			if (y < 17) {
				gotoxy(hout, x, ++y);
				continue;
			}
			else if (y == 17) {
				y = 1;
				gotoxy(hout, x, y);
				continue;
			}

		}

		else if (ch == 76 || ch == 108) {//L l
			if (x < 69) {
				gotoxy(hout, ++x, y);
				continue;
			}
			else if (x == 69) {
				x = 1;
				gotoxy(hout, x, y);
				continue;
			}

		}

		else if (ch == 32) {//空格
			showch(hout, x, y, ' ');
			gotoxy(hout, x, y);
			continue;
		}

		else if (ch == 113 || ch == 81) {//q Q 退出
			break;
		}

	}

	x = 0; y = 23;
	gotoxy(hout, x, y);
	printf("游戏结束，按回车键返回菜单.");
	x = 27;
	gotoxy(hout, x, y);

	while (1) {//回车 返回菜单
		char k;
		k = _getch();
		if (k == '\r') {
			cls(hout);
			break;
		}
	}
}



void move_by_ijkl2(int i) {
	int ch;
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄

	/* 显示初始的边框及其中的随机字符 */
	init_border(hout);

	/*初始光标位置*/
	int x, y;
	x = 35;
	y = 9;
	gotoxy(hout, x, y);

	while (i == 1) {
		ch = _getch();
		if (ch == 224) {
			ch = _getch();
			ch = 12345;
		}
		if (ch == 73 || ch == 105) {//I i
			if (y > 1) {
				gotoxy(hout, x, --y);
				continue;
			}

		}

		else if (ch == 74 || ch == 106) {//J j
			if (x > 1) {
				gotoxy(hout, --x, y);
				continue;
			}

		}

		else if (ch == 75 || ch == 107) {//K k
			if (y < 17) {
				gotoxy(hout, x, ++y);
				continue;
			}

		}

		else if (ch == 76 || ch == 108) {//L l
			if (x < 69) {
				gotoxy(hout, ++x, y);
				continue;
			}

		}

		else if (ch == 32) {//空格
			showch(hout, x, y, ' ');
			gotoxy(hout, x, y);
			continue;
		}

		else if (ch == 113 || ch == 81) {//q Q 退出
			break;
		}


	}

	while (i == 2) {
		ch = _getch();
		if (ch == 224) {
			ch = _getch();
			ch = 12345;
		}
		if (ch == 73 || ch == 105) {//I i
			if (y > 1) {
				gotoxy(hout, x, --y);
				continue;
			}
			else if (y == 1) {
				y = 17;
				gotoxy(hout, x, y);
				continue;
			}
		}

		else if (ch == 74 || ch == 106) {//J j
			if (x > 1) {
				gotoxy(hout, --x, y);
				continue;
			}
			else if (x == 1) {
				x = 69;
				gotoxy(hout, x, y);
				continue;
			}

		}

		else if (ch == 75 || ch == 107) {//K k
			if (y < 17) {
				gotoxy(hout, x, ++y);
				continue;
			}
			else if (y == 17) {
				y = 1;
				gotoxy(hout, x, y);
				continue;
			}

		}

		else if (ch == 76 || ch == 108) {//L l
			if (x < 69) {
				gotoxy(hout, ++x, y);
				continue;
			}
			else if (x == 69) {
				x = 1;
				gotoxy(hout, x, y);
				continue;
			}

		}

		else if (ch == 32) {//空格
			showch(hout, x, y, ' ');
			gotoxy(hout, x, y);
			continue;
		}

		else if (ch == 113 || ch == 81) {//q Q 退出
			break;
		}

	}

	x = 0; y = 23;
	gotoxy(hout, x, y);
	printf("游戏结束，按回车键返回菜单.");
	x = 27;
	gotoxy(hout, x, y);

	while (1) {//回车 返回菜单
		char k;
		k = _getch();
		if (k == '\r') {
			cls(hout);
			break;
		}
	}
}






void move_by_arrow(int i) {
	int ch;
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄

	/* 显示初始的边框及其中的随机字符 */
	init_border(hout);

	/*初始光标位置*/
	int x, y;
	x = 35;
	y = 9;
	gotoxy(hout, x, y);

	while (i == 1) {
		ch = _getch();
		while (ch == 224) {
			ch = _getch();
			if (ch == 72) {//上
				if (y > 1) {
					gotoxy(hout, x, --y);
					continue;
				}
			}

			else if (ch == 75) {//左
				if (x > 1) {
					gotoxy(hout, --x, y);
					continue;
				}
			}

			else if (ch == 80) {//下
				if (y < 17) {
					gotoxy(hout, x, ++y);
					continue;
				}
			}
			else if (ch == 77) {//右
				if (x < 69) {
					gotoxy(hout, ++x, y);
					continue;
				}
			}
		}
		if (ch == 32) {//空格
			showch(hout, x, y, ' ');
			gotoxy(hout, x, y);
			continue;
		}

		if (ch == 113 || ch == 81) {//q Q 退出
			break;
		}
	}

	while (i == 2) {
		ch = _getch();
		while (ch == 224) {
			ch = _getch();
			if (ch == 72) {//上
				if (y > 1) {
					gotoxy(hout, x, --y);
					continue;
				}
				else if (y == 1) {
					y = 17;
					gotoxy(hout, x, y);
					continue;
				}
			}
			else if (ch == 75) {//左
				if (x > 1) {
					gotoxy(hout, --x, y);
					continue;
				}
				else if (x == 1) {
					x = 69;
					gotoxy(hout, x, y);
					continue;
				}
			}
			else if (ch == 80) {//下
				if (y < 17) {
					gotoxy(hout, x, ++y);
					continue;
				}
				else if (y == 17) {
					y = 1;
					gotoxy(hout, x, y);
					continue;
				}
			}
			else if (ch == 77) {//右
				if (x < 69) {
					gotoxy(hout, ++x, y);
					continue;
				}
				else if (x == 69) {
					x = 1;
					gotoxy(hout, x, y);
					continue;
				}
			}
		}
		if (ch == 32) {//空格
			showch(hout, x, y, ' ');
			gotoxy(hout, x, y);
			continue;
		}
		if (ch == 113 || ch == 81) {//q Q 退出
			break;
		}
	}


	x = 0; y = 23;
	gotoxy(hout, x, y);
	printf("游戏结束，按回车键返回菜单.");
	x = 27;
	gotoxy(hout, x, y);

	while (1) {//回车 返回菜单
		char k;
		k = _getch();
		if (k == '\r') {
			cls(hout);
			break;
		}
	}
}

void menu() {
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄

	char ch;
	while (1) {
		printf("1.用I、J、K、L键控制上下左右(大小写均可，边界停止\n");
		printf("2.用I、J、K、L键控制上下左右(大小写均可，边界回绕\n");
		printf("3.用箭头键控制上下左右，边界停止\n");
		printf("4.用箭头键控制上下左右，边界回绕\n");
		printf("5.用I、J、K、L键控制上下左右(大小写均可，边界停止,按左键头不准向下移动\n");
		printf("6.用I、J、K、L键控制上下左右(大小写均可，边界回绕,按左键头不准向下移动\n");
		printf("0.退出\n");
		printf("[请选择0 - 6] \n");
		ch = _getch();
		cls(hout);
		if (ch == '1')
			move_by_ijkl(1);
		else if (ch == '2')
			move_by_ijkl(2);
		else if (ch == '3')
			move_by_arrow(1);
		else if (ch == '4')
			move_by_arrow(2);
		else if (ch == '5')
			move_by_ijkl2(1);
		else if (ch == '6')
			move_by_ijkl2(2);
		else if (ch == '0')
			break;
	}
}
/* -- 按需增加的若干函数可以放在此处 --*/

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数仅用于初始演示，可以按题目要求全部推翻重写
***************************************************************************/
int main()
{
	menu();

	return 0;
}
/*思考1：我的程序可以重现这个问题，只要把条件
if (ch == 224) {
	ch = _getch();
	ch = 12345;
}
给省去就会出现按左箭头向下的情况，因为方向键有两个返回值，先返回224后返回方向键对应的键码，
其中左箭头的键码和k的ASCII码一致，所以出现按左箭头会向下的情况。

思考2：有可能达不到20个字母
*/
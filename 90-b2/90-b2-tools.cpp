/*2151299 苏家铭 信16*/
/*放一些内部数组/图形方式公用的函数，如判断结果等*/
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include<conio.h>
#include <time.h> 
#include"cmd_console_tools.h"
#include"90-b2.h"
using namespace std;

#define ROW 8
#define COL 10

/*0、输入map的行和列*/
void input_row_col(int* row, int* col, int* goal, int choice) 
{
	while (1) {
		cout << "请输入行数(5-8)：" << endl;
		cin >> *row;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(65535, '\n');
			cout << "请输入行数(5-8)：" << endl;
			cin >> *row;
		}
		if (*row <= 4 || *row >= 9) {
			cin.clear();
			cin.ignore(65535, '\n');
		}
		if (*row >= 5 && *row <= 8) {
			cin.clear();
			cin.ignore(65535, '\n');
			break;
		}
	}
	while (1) {
		cout << "请输入列数(5-10)：" << endl;
		cin >> *col;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(65535, '\n');
			cout << "请输入行数(5-10)：" << endl;
			cin >> *col;
		}
		if (*col <= 4 || *col >= 11) {
			cin.clear();
			cin.ignore(65535, '\n');
		}
		if (*col >= 5 && *col <= 10) {
			cin.clear();
			cin.ignore(65535, '\n');
			break;
		}
	}
	if (choice == 3||choice==4 || choice == 9) {
		while (1) {
			cout << "请输入合成目标(5-20)：" << endl;
			cin >> *goal;
			while (cin.fail()) {
				cin.clear();
				cin.ignore(65535, '\n');
				cout << "请输入行数(5-10)：" << endl;
				cin >> *goal;
			}
			if (*goal <= 4 || *goal >= 21) {
				cin.clear();
				cin.ignore(65535, '\n');
			}
			if (*goal >= 5 && *goal <= 20) {
				cin.clear();
				cin.ignore(65535, '\n');
				break;
			}
		}
	}

}
/*创造初始内部数组*/
void create_begin_arr(int map[ROW][COL], int row, int col)
{
	srand((unsigned int)time(NULL));
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			map[i][j] = 1+rand()%3;//[1,max]随机值
		}
	}
}
/*1、创造随机数*/
int  create_random(int max) 
{
	int k = 0;
	if (max == 3) {
		k = 1 + rand() % 3;
		return k;
	}
	else if (max == 4) {
		k = 1 + rand() % 10;
		if (k >= 1 && k <= 3)
			return 1;
		else if (k >= 4 && k <= 6)
			return 2;
		else if (k >= 7 && k <= 9)
			return 3;
		else if (k == 10)
			return 4;
		else
			return -1;
	}
	else if (max == 5) {
		k = 1 + rand() % 20;
		if (k >= 1 && k <= 5)
			return 1;
		else if (k >= 6 && k <= 10)
			return 2;
		else if (k >= 11 && k <= 15)
			return 3;
		else if (k >= 16 && k <= 18)
			return 4;
		else if (k == 19 || k == 20)
			return 5;
		else
			return -1;
	}
	else if (max == 6) {
		k = 1 + rand() % 20;
		if (k >= 1 && k <= 4)
			return 1;
		else if (k >= 5 && k <= 8)
			return 2;
		else if (k >= 9 && k <= 12)
			return 3;
		else if (k >= 13 && k <= 16)
			return 4;
		else if (k >= 17 && k <= 19)
			return 5;
		else if (k == 20)
			return 6;
		else
			return -1;
	}
	else if (max > 6) {
		k = 1 + rand() % 20;
		if (k >= 1 && k <= 16) {
			return (1 + rand() % (max - 3));
		}
		else if (k == 17 || k == 18)
			return max - 2;
		else if (k == 19)
			return max - 1;
		else if (k == 20)
			return max;
		else
			return -1;
	}
	else
		return -1;
}
/*2、小写英文字母转大写*/
char change(char ch) 
{
	if (ch >= 97 && ch <= 122)
		ch -= 32;
	return ch;
}
/*3、输入矩阵坐标*/
void cin1(int row, int col,char *map_x,char*map_y, int map[ROW][COL]) 
{
	int X, Y;//get x,y address
	cout << "请以字母+数字形式[例：c2]输入矩阵坐标：";
	while (1) {
		cct_getxy(X, Y);
		cin >> *map_x >> *map_y;
		*map_x=change(*map_x);
		*map_y=change(*map_y);
		if ((*map_x < ('A' + row - 1)) && (*map_x > ('A' - 1))) {
			if (*map_y >='0' && *map_y < '0'+col) {
				cct_gotoxy(0, Y + 1);
				cout <<"输入为" << *map_x << "行" << *map_y << "列";
				if (judge_neighbor(map, *map_x - 'A', *map_y-'0', row, col) == true) {
					break;
				}
				else {
					cout <<endl<< "输入的矩阵坐标位置处无连续相同值，请重新输入" << endl;
					cout << "请以字母+数字形式[例：c2]输入矩阵坐标：";
				}

			}
			else {
				cin.clear();
				cin.ignore(65535, '\n');
				cct_showch(X, Y, ' ', COLOR_BLACK, COLOR_WHITE, 18);//清除显示c2
				cct_showch(0, Y+1, ' ', COLOR_BLACK, COLOR_WHITE, 22);//清除显示下面一行话
				cct_gotoxy(0, Y + 1);
				cout <<"输入错误，请重新输入.";
				cct_gotoxy(X, Y);
				continue;
			}
		}
		else {
			cin.clear();
			cin.ignore(65535, '\n');
			cct_showch(X, Y, ' ', COLOR_BLACK, COLOR_WHITE, 18);//清除显示c2
			cct_showch(0, Y + 1, ' ', COLOR_BLACK, COLOR_WHITE, 22);//清除显示下面一行话
			cct_gotoxy(0, Y + 1);
			cout << "输入错误，请重新输入.";
			cct_gotoxy(X, Y);
			continue;
		}
	}
}
/*4、判断周围是否有相同字符*/
bool judge_neighbor(int map[ROW][COL],int i,int j, int row, int col) 
{
	if (i - 1 >= 0) {
		if (map[i - 1][j] == map[i][j]) {
			return true;
		}
	}
	if (j - 1 >= 0) {
		if (map[i][j - 1] == map[i][j]) {
			return true;
		}
	}
	if ((j + 1) < col) {
		if (map[i][j + 1] == map[i][j]) {
			return true;
		}
	}
	if ((i + 1) < row) {
		if (map[i + 1][j] == map[i][j]) {
			return true;
		}
	}
	return false;

}
/*用for循环找上下左右相同数字*/
void find_neighbor_for(int row, int col, int map[ROW][COL], char mark[ROW][COL]) 
{
	bool BREAK = true;
	while (BREAK) {
		BREAK = false;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {

				if (mark[i][j] == '*') {//
					if (i - 1 >= 0) {
						if (map[i - 1][j] == map[i][j]&& mark[i - 1][j] != '*') {
							mark[i - 1][j] = '*';
							BREAK = true;
						}
					}
					if (j - 1 >= 0) {
						if (map[i][j - 1] == map[i][j] && mark[i][j-1] != '*'){
							mark[i][j - 1] = '*';
							BREAK = true;
						}
					}
					if ((j + 1) < col) {
						if (map[i][j + 1] == map[i][j] && mark[i][j+1] != '*'){
							mark[i][j + 1] = '*';
							BREAK = true;
						}
					}
					if ((i + 1) < row) {
						if (map[i + 1][j] == map[i][j] && mark[i + 1][j] != '*'){
							mark[i + 1][j] = '*';
							BREAK = true;
						}
					}
				}

			}//end of for
		}//end of for
	}
}
/*用递归找上下左右相同数字*/
void find_neighbor_dg(int i,int j,int row, int col, int map[ROW][COL], char mark[ROW][COL]) {
	if (i - 1 >= 0) {
		if (map[i - 1][j] == map[i][j] && mark[i - 1][j] != '*') {
			mark[i - 1][j] = '*';
			find_neighbor_dg(i-1,j,row, col, map, mark);
		}
	}
	if (j - 1 >= 0) {
		if (map[i][j - 1] == map[i][j] && mark[i][j-1] != '*') {
			mark[i][j - 1] = '*';
			find_neighbor_dg(i, j-1, row, col, map, mark);
		}
	}
	if ((j + 1) < col) {
		if (map[i][j + 1] == map[i][j] && mark[i][j+1] != '*') {
			mark[i][j + 1] = '*';
			find_neighbor_dg(i, j+1, row, col, map, mark);

		}
	}
	if ((i + 1) < row) {
		if (map[i + 1][j] == map[i][j] && mark[i + 1][j] != '*') {
			mark[i + 1][j] = '*';
			find_neighbor_dg(i + 1, j, row, col, map, mark);

		}
	}
}
/*找相邻位置相同数并标记在另一个数组*/ 
void find_same_num_and_mark(int row, int col, int map[ROW][COL], char mark[ROW][COL], char map_x, char map_y,int choice){
	//把mark全置成'0'
	renew_mark(row, col, mark);
	mark[map_x - 'A'][map_y - '0'] = '*';
	if(choice==2)
	find_neighbor_dg(map_x - 'A', map_y - '0',row, col, map,mark);
	else
		find_neighbor_for(row, col, map, mark);

	
}
/*mark重新置0*/
void renew_mark(int row, int col, char mark[ROW][COL]) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			mark[i][j] = '0';
		}
	}
}
/*分数加和*/
void add_score(int row, int col, int map[ROW][COL], char mark[ROW][COL], char map_x, char map_y, int goal,int *all) {
	int sum = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if(mark[i][j] == '*')
			sum++;
		}
	}
	int now_num = 0,score=0;
	now_num = map[map_x - 'A'][map_y - '0']-1;
	score = now_num * sum * 3;
	*all = *all + score;
	cout << "本次得分：" << score << " 总得分：" << *all << " 合成目标：" << goal << endl;

}
/*绘画当前数组（最开始的内部数组）*/
void paint_now(int map[ROW][COL],  char mark[ROW][COL], int row, int col) {
	cout <<endl<< "当前数组：" << endl;
	paint_arr(row, col, map, mark);
}

/*输入end结束本小题*/
void wait_for_end_enter(){
	cout << endl;
	int s = 0, j = 0;
	cct_getxy(s, j);
	cct_showch(s, j-1, ' ', COLOR_BLACK, COLOR_WHITE, 50);//清除显示
	cct_gotoxy(s, j);
	cout << "本小题结束，请输入End继续...";
	int X=0, Y=0;
	while (1) {
		cct_getxy(X, Y);
		char wait[4];
		cin >> wait[0] >> wait[1] >> wait[2];
		wait[0] = change(wait[0]);
		wait[1] = change(wait[1]);
		wait[2] = change(wait[2]);
		if (wait[0] == 'E' && wait[1] == 'N' && wait[2] == 'D') {
			cin.clear();
			cin.ignore(65535, '\n');
			return;
		}
		else {
			cin.clear();
			cin.ignore(65535, '\n');
			cct_showch(X, Y, ' ', COLOR_BLACK, COLOR_WHITE, 18);//清除显示c2
			cct_showch(0, Y + 1, ' ', COLOR_BLACK, COLOR_WHITE, 22);//清除显示下面一行话
			cct_gotoxy(0, Y + 1);
			cout << "输入错误，请重新输入.";
			cct_gotoxy(X, Y);
			continue;
		}
	}
	
}
/*请确认是否把相邻的相同值合并到XX中(Y/N/Q)：*/
char wait_for_mix_enter(char map_x, char map_y) {
	cout <<endl<< "请确认是否把相邻的相同值合并到"<< map_x<< map_y<<"中(Y / N / Q)：";
	int X = 0, Y = 0;
	while (1) {
		cct_getxy(X, Y);
		char ch;
		ch = _getch();
		ch = change(ch);
		if (ch == 'N'||ch=='Q') {
			cin.clear();
			cin.ignore(65535, '\n');
			return ch;
		}
		else if(ch=='Y') {
			cin.clear();
			cin.ignore(65535, '\n');
			return ch;
		}
		else {
			cin.clear();
			cin.ignore(65535, '\n');
			cct_showch(X, Y, ' ', COLOR_BLACK, COLOR_WHITE, 18);//清除显示c2
			cct_showch(0, Y + 1, ' ', COLOR_BLACK, COLOR_WHITE, 22);//清除显示下面一行话
			cct_gotoxy(0, Y + 1);
			cout << "输入错误，请重新输入.";
			cct_gotoxy(X, Y);
			continue;
		}
	}
	cout << endl;

}

/*按回车键进行数组下落除0操作...*/
void wait_for_enter_eliminate_zero(const char* const prompt )
{
	if ((prompt == NULL) || (strlen(prompt) == 0)) 
		cout << endl << "按回车键进行数组下落除0操作...";
	else
		cout << endl << prompt << "按回车键进行数组下落除0操作...";

	while (_getch() != '\r')
		;
	cout << endl << endl;
}

/*按回车键进行新值填充...*/
void wait_for_enter_fill_new_value(const char* const prompt )
{
	if ((prompt == NULL) || (strlen(prompt) == 0))
		cout << endl << "按回车键进行新值填充...";
	else
		cout << endl << prompt << "按回车键进行新值填充...";

	while (_getch() != '\r')
		;
	cout << endl << endl;
}

/*找此时内部数组中最大数字max*/
int find_max_num(int map[ROW][COL], int row, int col) {
	int max=0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (map[i][j] > max) {
				max=map[i][j];
			}
		}
	}
	return max;
}
/*本次合成结束，按回车键继续新一次的合成...*/
void wait_for_mix_again(const char* const prompt){
	if ((prompt == NULL) || (strlen(prompt) == 0))
		cout << endl << "本次合成结束，按回车键继续新一次的合成...";
	else
		cout << endl << prompt << "本次合成结束，按回车键继续新一次的合成...";

	while (_getch() != '\r')
		;
	cout << endl << endl;
}


/*选项七*/
void select_7(int map[ROW][COL],char mark[ROW][COL], int row, int col,int choice,int *goal) {
	int X = 0, Y = 0,all=0;
	int ret, maction;
	int keycode1, keycode2;
	int loop = 1;
	char hang='A';
	int lie=0;
	int xx = 4, yy = 3;
	int rexx=4,  reyy=3;
	bool shine = true;
	bool shine2 = true;
	bool shine3 = false;
	cct_enable_mouse();
	cct_setcursor(CURSOR_INVISIBLE);	//关闭光标
	
	while (loop) {
		shine = true;
		/* 读鼠标/键盘，返回值为下述操作中的某一种, 当前鼠标位置在<X,Y>处 */
		ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);
		rexx = xx;
		reyy = yy;
		paint_9_num(map[hang - 'A'][lie], &rexx, &reyy, COLOR_BLACK);
		cct_setcolor(); //恢复初始颜色
		if (ret == CCT_MOUSE_EVENT) {
			if (Y >= 3 && Y <= 4 * row && Y % 4 != 2 && X >= 4 && X <= 8 * col - 1 && X % 8 != 2 && X % 8 != 3) {
				int a = 0;
				if ((Y + 1) % 4 == 0)
					a = Y + 1;
				else if (Y % 4 == 0)
					a = Y;
				else if ((Y - 1) % 4 == 0) {
					a = Y - 1;
				}
				if (!shine3) {
					/* 转到第4 * row + 3行进行打印 */
					cct_gotoxy(0, 4 * row + 3);
					cout << "[当前鼠标] ";
					cct_showch(11, 4 * row + 3, ' ', COLOR_BLACK, COLOR_WHITE, 50);//清除显示
					cct_gotoxy(11, 4 * row + 3);
					cout << char(a / 4 + 'A' - 1) << "行" << setw(2) << (X - 2) / 8 << "列";
					hang = a / 4 + 'A' - 1;
					lie = (X - 2) / 8;
					cct_gotoxy(11, 4 * row + 3);
				}
			}
			else {
				cct_showch(0, 4 * row + 3, ' ', COLOR_BLACK, COLOR_WHITE, 60);//清除显示
				cct_gotoxy(0, 4 * row + 3);
				cout << "[当前鼠标] ";
				cct_gotoxy(11, 4 * row + 3);
				cout << "位置非法";
				shine = false;
				cct_gotoxy(11, 4 * row + 3);
				shine3 = false;
			}

			if (choice == 7) {
				if (maction == MOUSE_LEFT_BUTTON_CLICK || maction == MOUSE_RIGHT_BUTTON_CLICK ||
					maction == MOUSE_LEFT_BUTTON_DOUBLE_CLICK || maction == MOUSE_RIGHT_BUTTON_DOUBLE_CLICK
					|| maction == MOUSE_LEFTRIGHT_BUTTON_CLICK) {
					/* 转到第4 * row + 3行进行打印 */
					cct_showch(0, 4 * row + 3, ' ', COLOR_BLACK, COLOR_WHITE, 50);//清除显示
					cct_gotoxy(0, 4 * row + 3);
					cout << "选中了第" << hang << "行" << lie << "列";
					break;
				}
			}
			else if (choice == 8|| choice == 9) {
				if (maction == MOUSE_LEFT_BUTTON_CLICK && shine3 == true&& (judge_neighbor(map, hang - 'A', lie, row, col) == true)) {
					thelast_paint_colour_aftermix(map, mark, row, col, hang, char(lie + '0'), choice,goal,&all);
					if (choice == 8)
						return;
					if (choice == 9 && map[hang - 'A'][lie] == *goal) {
						cct_showch(0, 4 * row + 3, ' ', COLOR_BLACK, COLOR_WHITE, 50);//清除显示
						cct_gotoxy(0, 4 * row + 3);
						cct_setcolor(0, 14);
						cout << "已经合成到"<<*goal<<"，";
						cct_setcolor();
						cout << "按回车键/单击左键继续向更高目标进发";
						wait_for_what(row, 0);
						cct_enable_mouse();
						(*goal)++;
						cct_showch(36, 0, ' ', COLOR_BLACK, COLOR_WHITE, 2);//清除显示
						cct_setcolor();
						cct_gotoxy(36, 0);
						cout << *goal;
					}
				}
				if (maction == MOUSE_RIGHT_BUTTON_CLICK ||
					maction == MOUSE_RIGHT_BUTTON_DOUBLE_CLICK
					) {
					cct_gotoxy(0, 4 * row + 3);
					break;
				}
				else if (maction == MOUSE_LEFT_BUTTON_CLICK ||
					maction == MOUSE_LEFT_BUTTON_DOUBLE_CLICK) {
					/* 转到第4 * row + 3行进行打印 */
					cct_showch(0, 4 * row + 3, ' ', COLOR_BLACK, COLOR_WHITE, 50);//清除显示
					cct_gotoxy(0, 4 * row + 3);
					if((judge_neighbor(map, hang - 'A', lie, row, col)==true))
					cout << "箭头键/鼠标移动取消当前选择，回车键/左键单击合成";
					else {
						cout<<"周围无相邻值";
						shine3 = true;
						xx = 8 * (lie + 1) - 4;
						yy = 4 * (hang - 'A' + 1) - 1;
						if (shine)
							paint_9_num(map[hang - 'A'][lie], &xx, &yy, COLOR_WHITE);
						else
							xx += 6;
						cct_setcolor(); //恢复初始颜色
						xx -= 6;
							continue;
					}
					if ((judge_neighbor(map, hang - 'A', lie, row, col) == true)) {
						//标记函数
						find_same_num_and_mark(row, col, map, mark, hang, char(lie + '0'),choice);
						mark_highlight(map, mark, row, col);
						shine3 = true;
					}			
				}
			}//end of if choice==8/9
			if (shine == false)
				mark_return_highlight(map, mark, row, col);
		} //end of if (CCT_MOUSE_EVENT)
		else if (ret == CCT_KEYBOARD_EVENT) {
			/* 转到第4 * row + 3行进行打印 */
			cct_gotoxy(0, 4 * row + 3);
			cout << "[当前键盘] ";

			switch (keycode1) {
			case 13:
				if (shine3 == true&& (judge_neighbor(map, hang - 'A', lie, row, col) == true)) {
					thelast_paint_colour_aftermix(map,mark,row,col,hang,char(lie+'0'), choice,goal,&all);
					if (choice == 8)
						return;
					if (choice == 9 && map[hang - 'A'][lie] == *goal) {
						cct_showch(0, 4 * row + 3, ' ', COLOR_BLACK, COLOR_WHITE, 50);//清除显示
						cct_gotoxy(0, 4 * row + 3);
						cct_setcolor(0, 14);
						cout << "已经合成到" << *goal << "，";
						cct_setcolor();
						cout << "按回车键/单击左键继续向更高目标进发";
						wait_for_what(row, 0);
						cct_enable_mouse();
						(*goal)++;
						cct_showch(36, 0, ' ', COLOR_BLACK, COLOR_WHITE, 2);//清除显示
						cct_setcolor();
						cct_gotoxy(36, 0);
						cout <<  *goal;
					}
				}
			case 224:
				shine2 = false;
				shine3 = false;
				switch (keycode2) {
				case KB_ARROW_UP:
					if (hang == 'A')
						hang = 'A' + row - 1;
					else
						hang--;
					break;
				case KB_ARROW_DOWN:
					if (hang == 'A' + row - 1)
						hang = 'A';
					else
						hang++;
					break;
				case KB_ARROW_LEFT:
					if (lie == 0)
						lie = col - 1;
					else
						lie--;
					break;
				case KB_ARROW_RIGHT:
					if (lie == col - 1)
						lie = 0;
					else
						lie++;
					break;
				}
			}//end of swicth(keycode1)
			if (shine2 == false)
				mark_return_highlight(map, mark, row, col);
			if (shine3 == false) {
				cct_showch(11, 4 * row + 3, ' ', COLOR_BLACK, COLOR_WHITE, 50);//清除显示
				cct_gotoxy(11, 4 * row + 3);
				cout << hang << "行" << setw(2) << lie << "列";
			}
		}//end of else if(ret == CCT_KEYBOARD_EVENT）

		xx = 8 * (lie+1) - 4;
		yy = 4 * (hang - 'A'+1) - 1;
		if (shine)
			paint_9_num(map[hang - 'A'][lie], &xx, &yy, COLOR_WHITE);
		else
			xx += 6;
		cct_setcolor(); //恢复初始颜色
		xx -= 6;

	} //end of while(1)

	cct_disable_mouse();	//禁用鼠标
	cct_setcursor(CURSOR_VISIBLE_NORMAL);	//打开光标
}
/*让相邻数字高光*/
void mark_highlight(int map[ROW][COL], char mark[ROW][COL], int row, int col) {
	int X=0, Y=0;
	cct_gotoxy(4, 3);//开始弄数字
	cct_getxy(X, Y);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (mark[i][j] == '*')
				paint_9_num(map[i][j], &X, &Y, COLOR_WHITE);
			else
				X += 6;
			X += 2;
		}
		X = X - 8 * col;
		Y += 4;
	}
	cct_setcolor(COLOR_BLACK, COLOR_WHITE);
}
/*不要让相邻数字高光*/
void mark_return_highlight(int map[ROW][COL], char mark[ROW][COL], int row, int col) {
	int X = 0, Y = 0;
	cct_gotoxy(4, 3);//开始弄数字
	cct_getxy(X, Y);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (mark[i][j] == '*')
				paint_9_num(map[i][j], &X, &Y, COLOR_BLACK);
			else
				X += 6;
			X += 2;
		}
		X = X - 8 * col;
		Y += 4;
	}
	cct_setcolor(COLOR_BLACK, COLOR_WHITE);
}
/*终极合成，此时我有map_x,y和map和mark*/
void thelast_paint_colour_aftermix(int map[ROW][COL], char mark[ROW][COL], int row, int col, char map_x, char map_y,int choice,int *goal,int *all) 
{
	int X = 0, Y = 0,a=100;
	map[map_x - 'A'][map_y - '0']++;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (mark[i][j] == '*' && !(i == map_x - 'A' && j == map_y - '0')) {
				map[i][j] = 0;
				cls_paint_9_num(8 * j + 4, 4 * (i+1) - 1);
			}
		}
	}
	X = 8 * (map_y - '0') + 4;
	Y = 4 * (map_x - 'A' + 1) - 1;
	while (a) {
		paint_9_num(map[map_x - 'A'][map_y - '0'], &X, &Y, COLOR_WHITE);
		X -= 6;
		paint_9_num(map[map_x - 'A'][map_y - '0'], &X, &Y, COLOR_BLACK);
		X -= 6;
		a--;
	}
	if(choice==9)
	add_score2(row, col, map, mark, map_x, map_y, goal, all);
	if(choice==8)
	wait_for_what(row,1);
	
	thelast_paint_colour_fall(map, mark, row, col, map_x, map_y, choice);
}
/*清空九宫格颜色数字*/
void cls_paint_9_num(int X, int Y) {
	
	for (int i = 0; i < 3; i++) {
		cct_showstr(X, Y+i, "   ", COLOR_HWHITE, COLOR_HWHITE, 2);
	}
	cct_setcolor(COLOR_BLACK, COLOR_WHITE);
}
/*合成完成，单击左键/回车键下落0
下落0完成，单击左键/回车键填充新值*/
void wait_for_what(int row,int step) {
	int X = 0, Y = 0;
	int ret, maction;
	int keycode1, keycode2;
	int loop = 1;
	if (step != 0) {
		/* 转到第4 * row + 3行进行打印 */
		cct_showch(0, 4 * row + 3, ' ', COLOR_BLACK, COLOR_WHITE, 50);//清除显示
		cct_gotoxy(0, 4 * row + 3);
	}
	if (step == 1) {
		cout << "合成完成，单击左键/回车键下落0";
	}
	else if (step == 2) {
		cout << "下落0完成，单击左键/回车键填充新值";
	}
	else if (step == 3) {
		cct_setcolor(0, 14);
		cout << "本次合成结束，按c/单击左键继续一次新的合成";
		cct_setcolor();
	}
	cct_enable_mouse();
	while (loop) {
		/* 读鼠标/键盘，返回值为下述操作中的某一种, 当前鼠标位置在<X,Y>处 */
		ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);

		if (ret == CCT_MOUSE_EVENT&& maction== MOUSE_LEFT_BUTTON_CLICK) {
				break;
		} //end of if (CCT_MOUSE_EVENT)
		else if (ret == CCT_KEYBOARD_EVENT&& keycode1==13) {//回车
			if(step==2||step==0||step==1)
				break;
		}
		else if (ret == CCT_KEYBOARD_EVENT && keycode1 == 99) {//c
			if(step==3)
			    break;
		}//end of else if(ret == CCT_KEYBOARD_EVENT）
	} //end of while(1)

	cct_disable_mouse();	//禁用鼠标
}

/*输入end结束本小题*/
void wait_for_end_enter7() 
{
	cout <<endl<< "本小题结束，请输入End继续...";
	int X = 0, Y = 0;
	while (1) {
		cct_getxy(X, Y);
		char wait[4];
		cin >> wait[0] >> wait[1] >> wait[2];
		wait[0] = change(wait[0]);
		wait[1] = change(wait[1]);
		wait[2] = change(wait[2]);
		if (wait[0] == 'E' && wait[1] == 'N' && wait[2] == 'D') {
			cin.clear();
			cin.ignore(65535, '\n');
			return;
		}
		else {
			cin.clear();
			cin.ignore(65535, '\n');
			cct_showch(X, Y, ' ', COLOR_BLACK, COLOR_WHITE, 18);//清除显示c2
			cct_showch(0, Y + 1, ' ', COLOR_BLACK, COLOR_WHITE, 22);//清除显示下面一行话
			cct_gotoxy(0, Y + 1);
			cout << "输入错误，请重新输入.";
			cct_gotoxy(X, Y);
			continue;
		}
	}

}


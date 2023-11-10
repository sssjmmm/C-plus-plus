/*2151299 苏家铭 信16*/
/*主函数及菜单部分函数*/
#include <iostream>
#include <iomanip>
#include<conio.h>
#include"cmd_console_tools.h"
#include "lib_mto10_net_tools.h"
#include"90-b2.h"
#include <Windows.h>
using namespace std;
#define ROW 8
#define COL 10
#define		MAX_ROW_NUM		8
#define		MAX_COL_NUM		10
void find_A_row_and_col(int map0[8][10], char* row, int* col, int what_row, int what_col);
int menu() 
{
	char ch;
	cout << "---------------------------------------" << endl;
	cout << "1.命令行找出可合成项并标识（非递归）" << endl;
	cout << "2.命令行找出可合成项并标识（递归）" << endl;
	cout << "3.命令行完成一次合成（分步骤显示）" << endl;
	cout << "4.命令行完整版（分步骤显示）" << endl;
	cout << "5.伪图形界面显示初始数组（无分隔线）" << endl;
	cout << "6.伪图形界面显示初始数组（有分隔线）" << endl;
	cout << "7.伪图形界面下用箭头键/鼠标选择当前色块" << endl;
	cout << "8.伪图形界面完成一次合成（分步骤）" << endl;
	cout << "9.伪图形界面完整版(支持鼠标)" << endl;
	cout << "---------------------------------------" << endl;
	cout << "A.命令行界面（网络自动解-基本版）" << endl;
	cout << "B.伪图形界面（网络自动解-基本版）" << endl;
	cout << "0.退出" << endl;
	cout << "---------------------------------" << endl;
	cout << "[请选择:]";
	while (1) {
		ch = _getch();
		if (ch >= '0' && ch <= '9') {
			cout << ch - '0';
			cout << endl;
			cout << endl;
			cout << endl;
			break;
		}
		else if (cin.fail()) {
			cin.clear();
			cin.ignore(65535, '\n');
		}
		else if (ch == 65||ch==97) {
			if (ch == 97)
				ch = 65;
			cout << ch;
			cout << endl;
			cout << endl;
			cout << endl;
			return ch;
		}
		else if (ch == 66||ch==98) {
			if (ch == 98)
				ch = 66;
			cout << ch ;
			cout << endl;
			cout << endl;
			cout << endl;
			return ch;
		}
	}//end of while
	return (ch - '0');



}
int game_progress(mto10_net_tools& client,int what_row,int what_col,int choice)
{
	char svrpack[RECVBUF_LEN];	//存放从Server端收到的数据
	char row='Z';
	int col=11;
	int all=0;
	char mark[ROW][COL];
	const char *p;//8 row 10 col
	int map0[8][10];
	while (1) {
		/* -------------------
			Client=>Server
		   ------------------- */
		   /* 根据服务端发来的地图，返回一个解坐标（目前为手工输入形式，需要改为自动求最佳解坐标）
			  提示：可以将client.get_map()的返回值复制到字符数组中，再还原为你自己的二维数组后求解
		   */
		if(choice==65)
		client.print_map(); //本函数仅为示意，图形界面中不能调用，要自己写转换函数
		else if (choice == 66) {
			//看看下面这两个要不要放后面
			if (row != 'Z' && col != 11) {
				//记录到map0中
				p = client.get_map();
				for (int i = 0; i < what_row; i++) {
					for (int j = 0; j < what_col; j++) {
						map0[i][j] = *p - '0';
						p++;
					}
				}
				for (int i = 0; i < what_row; i++) {
					for (int j = 0; j < what_col; j++) {
						if (mark[i][j] == '*') {
							int X = 8 * j + 4;
							int Y = 4 * (i + 1) - 1;
							paint_9_num(map0[i][j], &X, &Y, COLOR_BLACK);
							Sleep(1);
						}
					}
				}
				cct_setcolor();
				cct_showstr(0, 4 * what_row + 4, " ", COLOR_BLACK, COLOR_WHITE, 28);
				cct_gotoxy(0, 4 * what_row + 4);
			}
			//此时是空白的，根据新的不同数字填充相应的值
		}

		/* 游戏已结束则不再读键*/
		if (client.is_gameover())
			break;

		cout << "行(A-J)列(0-9)坐标 : ";
		//记录到map0中
		p = client.get_map();
		for (int i = 0; i < what_row; i++) {
			for (int j = 0; j < what_col; j++) {
				map0[i][j] = *p-'0';
				p++;
			}
		}
		//在map0中找row和col
		//函数
		find_A_row_and_col(map0, &row, &col, what_row, what_col);
		cout << row << col << endl;
		//cin >> row >> col; //此处未判断正确性，需要自行处理

		/* 清空后续的缓冲区 */
		//cin.clear();
		//cin.ignore(INT_MAX, '\n');

		if (row >= 'a' && row <= 'j')
			row -= 32; //如果是小写则转为大写
		//输入row和col后就高光、闪、、消失变空白
		if (choice == 66) {
			find_same_num_and_mark(what_row, what_col, map0, mark, row, char(col + '0'), choice);
			mark_highlight(map0, mark, what_row, what_col);
			thelast_paint_colour_aftermix(map0, mark, what_row, what_col, row, char(col + '0'), choice, 0, &all);
		}
		client.send_coordinate(row, col);

		/* -------------------
			Server=>Client
		   ------------------- */
		   /* 等待Server端的gameprogress */
		if (client.get_gameprogress_string(svrpack) < 0) {
			return -1;
		}

		/* 打印出 svrpack 的内容，自行处理，并向Server端继续反馈
		   根据 Content 的内容，解释如下：
			"InvalidCoordinate" : 非法坐标
				GameID		：本次游戏ID
				Step		：目前步数
				Score		：目前分数
				MaxValue	：目前合成的最大值
			"MergeFailed" : 选择的坐标周围无可合成项
				GameID		：本次游戏ID
				Step		：目前步数
				Score		：目前分数
				MaxValue	：目前合成的最大值
			"MergeSucceeded" : 本次合成成功
				GameID		：本次游戏ID
				Step		：目前步数
				Score		：目前分数
				MaxValue	：目前合成的最大值
				OldMap		：消除选择坐标后的地图
				NewMap		：消除选择坐标后再次填充的地图
			"GameOver" : 地图上无消除项，游戏结束
				GameID			：本次游戏ID
				FinalStep		：最终步数
				FinalScore		：最终分数
				FinalMaxValue	：最终合成的最大值
			"GameFinished" : 已合成到设置上限（16），游戏完成
				GameID			：本次游戏ID
				FinalStep		：最终步数
				FinalScore		：最终分数
				FinalMaxValue	：最终合成的最大值 */


				/* 打印收到的原始字符串 */
		if(choice==65)
		cout << "Server应答 : " << endl << svrpack << endl;
	}//end of while(1)

	return 0;
}
void find_A_row_and_col(int map0[8][10],char *row,int *col,int what_row,int what_col) {
	
	for (int i = 0; i < what_row; i++) {
		for (int j = 0; j < what_col; j++) {
			if (judge_neighbor(map0, i, j, what_row, what_col)) {//周围有相同值
				*row = i + 'A';
				*col = j;
				return;
			}
		}
	}
}
int main()
{
	while (1) {
		int choice;
		int row, col, goal;
		int map[ROW][COL];
		char mark[ROW][COL];
		char map_x = '0', map_y = '0';
		int all = 0;
		choice = menu();
		cct_cls();
		if (choice == 1) {
			char map_x, map_y;
			input_row_col(&row, &col, &goal, 1);
			create_begin_arr(map, row, col);
			paint_now(map, mark, row, col);
			cin1(row, col, &map_x, &map_y, map);
			find_same_num_and_mark(row, col, map, mark, map_x, map_y, choice);
			paint_find_arr(mark, row, col);
			paint_colour_now(map, mark, row, col);
			renew_mark(row, col, mark);
			wait_for_end_enter();
			cct_cls();
		}
		else if (choice == 2) {
			char map_x, map_y;
			input_row_col(&row, &col, &goal, 1);
			create_begin_arr(map, row, col);
			paint_now(map, mark, row, col);
			cin1(row, col, &map_x, &map_y, map);
			find_same_num_and_mark(row, col, map, mark, map_x, map_y, choice);
			paint_find_arr(mark, row, col);
			paint_colour_now(map, mark, row, col);
			renew_mark(row, col, mark);
			wait_for_end_enter();
			cct_cls();
		}
		else if (choice == 3) {
			input_row_col(&row, &col, &goal, 3);
			create_begin_arr(map, row, col);
			paint_now(map, mark, row, col);
			cin1(row, col, &map_x, &map_y, map);
			find_same_num_and_mark(row, col, map, mark, map_x, map_y, choice);
			paint_find_arr(mark, row, col);
			paint_colour_now(map, mark, row, col);
			if (wait_for_mix_enter(map_x, map_y) == 'Y') {
				paint_colour_aftermix(map, mark, row, col, map_x, map_y);
				add_score(row, col, map, mark, map_x, map_y, goal, &all);
				wait_for_enter_eliminate_zero();
				paint_colour_after_eliminate_zero(map, mark, row, col, map_x, map_y);
				wait_for_enter_fill_new_value();
				paint_colour_fill_new_value(map, mark, row, col);
				renew_mark(row, col, mark);
				wait_for_end_enter();
			}
			else {
				renew_mark(row, col, mark);
				wait_for_end_enter();
			}
			cct_cls();
		}
		else if (choice == 4) {
			input_row_col(&row, &col, &goal, 4);
			create_begin_arr(map, row, col);
			while (1) {
				paint_now(map, mark, row, col);
				cin1(row, col, &map_x, &map_y, map);
				find_same_num_and_mark(row, col, map, mark, map_x, map_y, choice);
				paint_find_arr(mark, row, col);
				paint_colour_now(map, mark, row, col);
				char ch = wait_for_mix_enter(map_x, map_y);
				if (ch == 'Y') {
					paint_colour_aftermix(map, mark, row, col, map_x, map_y);
					add_score(row, col, map, mark, map_x, map_y, goal, &all);
					wait_for_enter_eliminate_zero();
					paint_colour_after_eliminate_zero(map, mark, row, col, map_x, map_y);
					wait_for_enter_fill_new_value();
					paint_colour_fill_new_value(map, mark, row, col);
					renew_mark(row, col, mark);
					wait_for_mix_again();
				}
				else if (ch == 'N') {
					renew_mark(row, col, mark);
					continue;
				}
				else {
					renew_mark(row, col, mark);
					wait_for_end_enter();
					break;
				}
			}
			cct_cls();
		}
		else if (choice == 5) {
			input_row_col(&row, &col, &goal, 5);
			create_begin_arr(map, row, col);
			paint_background_5(map, row, col);
			wait_for_end_enter();
			cct_cls();
		}
		else if (choice == 6) {
			input_row_col(&row, &col, &goal, 6);
			create_begin_arr(map, row, col);
			paint_background_6(map, row, col);
			wait_for_end_enter();
			cct_cls();
		}
		else if (choice == 7) {
			input_row_col(&row, &col, &goal, 7);
			create_begin_arr(map, row, col);
			paint_background_6(map, row, col);
			select_7(map, mark, row, col, 7, &goal);
			wait_for_end_enter7();
			cct_cls();
		}
		else if (choice == 8) {
			input_row_col(&row, &col, &goal, 8);
			create_begin_arr(map, row, col);
			paint_background_6(map, row, col);
			select_7(map, mark, row, col, 8, &goal);
			wait_for_end_enter();
			cct_cls();
		}
		else if (choice == 9) {
			input_row_col(&row, &col, &goal, 9);
			create_begin_arr(map, row, col);
			paint_background_6(map, row, col);
			select_7(map, mark, row, col, 9, &goal);
			wait_for_end_enter();
			cct_cls();
		}
		else if (choice == 0) {
			break;
		}
		else if (choice == 65||choice==66) {
		const char* my_no = "2151299";		//本人学号
		const char* my_pwd = "sujiaming.123";	//本人密码

		int wanted_row, wanted_col, wanted_id, wanted_delay;

#if 0//条件编译，此处改为 #if 0 则表示启用下面 #else 中的语句
		input_row_col(&wanted_row, &wanted_col, &goal,65);
		//wanted_row = 8;			//此处按需修改为键盘输入等形式
		//wanted_col = 10;			//此处按需修改为键盘输入等形式
		wanted_id = 22345;		//id为本次请求的游戏序号，如果置-1，表示服务器随机产生，[0..2^31-1]则表示想固定序号（序号固定，则每次给出的初始矩阵及后续填充均相同，方便调试）
		wanted_delay = 60 * 1000;	//delay为请求的每步应答的最长时延，单位ms
#else
		//wanted_row = 5;
		//wanted_col = 7;
		input_row_col(&wanted_row, &wanted_col, &goal, 65);
		wanted_id = -1;
		wanted_delay = 60 * 1000;
#endif
		mto10_net_tools client;

		/* 打开client类对象中的debug开关（调试时可打开，到图形界面时需关闭） */
		if(choice==65)
		client.set_debug_switch(true);
		else if(choice==66)
			client.set_debug_switch(false);


		/* 连接服务器 */
		if (client.connect() < 0) {
			/* 连接失败信息，有没有debug_switch都打印 */
			cout << "连接服务器失败!" << endl;
			return -1;
		}

		/* 向Server端发送认证信息及参数 */
		if (client.send_parameter(my_no, '*', my_pwd, wanted_row, wanted_col, wanted_id, wanted_delay) < 0) {
			cout << "发送认证及参数信息失败!" << endl;
			return -1;
		}

		/* 等待Server端下发参数（游戏开始）*/
		if (client.wait_for_game_start() < 0) {
			cout << "等待GameStart失败!" << endl;
			return -1;
		}

		/* 打印从服务器收到的参数，本次游戏以此参数为准（例：发送6行6列，返回8行10列，则本次游戏以8行10列为准）
		下面打印的信息，图形化界面可以自行去除 */
		if (choice == 65) {
			cout << "服务器返回信息 : " << endl;
			cout << "  行数 : " << client.get_row() << endl;
			cout << "  列数 : " << client.get_col() << endl;
			cout << "  ID号 : " << client.get_gameid() << endl;
			cout << "  超时 : " << client.get_delay() / 1000.0 << "(秒)" << endl;
			cout << "  地图 : " << client.get_map() << endl;
		}
		else if (choice == 66) {
			int map1[8][10];
			const char* p;
			p = client.get_map();
			for (int i = 0; i < client.get_row(); i++) {
				for (int j = 0; j < client.get_col(); j++) {
					map1[i][j] = *p-'0';
					p++;
				}
			}
			paint_background_66(map1, client.get_row(), client.get_col());
		}
		/* 地图串中的值为1-9，A-F，分别表示1-15的值，
			   例如：
				 服务器返回行=3
				 服务器返回列=4
				 服务器返回地图=123A85CF2123
			   则表示当前地图为(本例仅仅是示例)
				 1 2 3  10
				 8 5 12 15
				 2 1 2  3
				游戏结束的条件为：合成到16或无任何可合成元素 */

				/* 进入游戏交互环节
				   1、收到Server的GameOver则返回0，游戏结束
				   2、其它错误均返回-1（报文信息不正确等错误），重连，再次重复	*/
		if (game_progress(client,wanted_row,wanted_col,choice) < 0) {
			client.close();
			return -1;
		}

		client.close();
		cout << "游戏结束" << endl;
		wait_for_end_enter();
		cct_cls();
		
}//if choice==65 66
	}//end of while
	return 0;
}
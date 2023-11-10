/* 2151299 信16 苏家铭 */
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

/* -----------------------------------------------------------------------------------
		允许   ：1、按需增加一个或多个函数，但是所有增加的函数中不允许任何形式的循环
				 2、定义符号常量
				 3、定义const型变量

		不允许 ：1、定义全局变量
   ----------------------------------------------------------------------------------- */


   /***************************************************************************
	 函数名称：
	 功    能：打印菱形
	 输入参数：
	 返 回 值：
	 说    明：
   ***************************************************************************/
void print_zmkg1(int j, int n);
void print_zmkg2(int i,int j, int n);
void print_diamond2(char start_ch,int b, char end_ch);
void print_diamond(char start_ch, char end_ch)
{
	static int n,i=1;
	int j=1;
	n = end_ch - 'A';
	if (i <= n + 1) {//上三角
		print_zmkg1(i, n);
		print_zmkg2(i,j, n);
		++i;
		cout << endl;
		print_diamond('A', end_ch);

	}	
	if (i > n + 1) {//进入diamond2弄下三角
		i--;
		i--;
		print_diamond2('A',i, end_ch);
	}
}

void print_diamond2(char start_ch,int b, char end_ch)
{
	static int n, i=b ;
	int j = 1;
	n = end_ch - 'A';
	if (i >= 1) {
		print_zmkg1(i, n);
		print_zmkg2(i, j, n);
		--i;
		cout << endl;
		print_diamond2('A',i, end_ch);
	}
	
}

void print_zmkg1(int a, int n) {//空格
	int j=a;
	if (j < n + 1) {
		printf(" ");
		j++;
		print_zmkg1(j,n);
	}
}
void print_zmkg2 (int i,int j, int n) {//i是第i行 j是第j个字母 

	if (j <= 2*i-1) {
		if (i == j) {
			cout << char(65);
		}
		else if (i > j) {
			cout << char(65 + (i-j));
		}
		else if (i < j) {
			cout << char(65 + (j-i));
		}
		j++;
		print_zmkg2(i,j, n);
	}
}



/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数中两处...允许修改，其余位置不准修改
***************************************************************************/
int main()
{
	char end_ch;

	/* 键盘输入结束字符(仅大写有效) */
	cout << "请输入结束字符(A~Z)" << endl;
	end_ch = getchar();

	/* 菱形(中间为A) */
	cout <<setfill('=')<< setw(2*(double(end_ch)-64)-1) << '=' << endl; /* 按菱形最大宽度输出=(不允许用循环) */
	cout << "菱形(" << end_ch << "->A)" << endl;
	cout << setfill('=') << setw(2 * (double(end_ch) - 64) - 1) << '=' << endl; /* 按菱形最大宽度输出=(不允许用循环) */
	print_diamond('A', end_ch);
	cout << endl;

	return 0;
}
/* 信16 2151299 苏家铭 */
#include <iostream>
using namespace std;
template<typename T>

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：给出fun函数的定义及实现
 ***************************************************************************/
T fun(T n) {
	int i,sum;
	for (i = 1,sum=0; i <= n; i++) {
		sum = sum + i;
	}
	return sum;
}

 /***************************************************************************
   函数名称：
   功    能：
   输入参数：
   返 回 值：
   说    明：main函数不准修改
  ***************************************************************************/
int main()
{
	short          s1 = 255, s2 = s1 + 1;
	unsigned short us1 = 255, us2 = us1 + 1;
	int            i1 = 65535, i2 = i1 + 1;
	unsigned int   ui1 = 65535, ui2 = ui1 + 1;

	cout << fun(s1) << endl; //期望输出 32640
	cout << fun(s2) << endl; //期望输出 -32640
	cout << fun(us1) << endl; //期望输出 32640
	cout << fun(us2) << endl; //期望输出 32896
	cout << fun(i1) << endl; //期望输出 2147450880
	cout << fun(i2) << endl; //期望输出 -2147450880
	cout << fun(ui1) << endl; //期望输出 2147450880
	cout << fun(ui2) << endl; //期望输出 2147516416

	return 0;
}
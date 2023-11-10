/* 2151299 苏家铭 信16 */
#include <iostream>
using namespace std;

#define  N  10	/* 假设最多转换10个数字 */

/* 不允许再定义其它函数、全局变量 */

int main()
{
	/* 如果有不需要的变量，允许删除，但不允许添加或替换为其它类型的变量 */
	char str[256], * p;
	int  a[N] = { 0 }, * pnum, * pa;
	bool is_num;

	/* 上面的定义不准动(删除不需要的变量除外)，下面为程序的具体实现，要求不得再定义任何变量、常量、常变量 */
	cout << "请输入间隔含有若干正负数字的字符串" << endl;

	gets_s(str);
	for (p = str,pa = a,is_num=false; *p != '\0'; p++){

		if (*p >= '0' && *p <= '9')
			is_num = true;		
		else
			is_num = false;

		if (is_num) {//这个字符是数字
			*pa = *pa * 10 + *p - '0';			
		}	
		//看看下一个字符是不是数字
		p++;
		if (!(*p >= '0' && *p <= '9')) {
			pa++;
		}
		p--;//减回来		
	}

	cout << "共有" << pa - a  << "个整数" << endl;
	pnum = a;
	while (pa > pnum)
		cout << *pnum++ << " ";
	cout << endl;
	return 0;
}

/* 2151299 苏家铭 信16 */
#include <iostream>
#include <iomanip>
using namespace std;

/* ----具体要求----
   1、不允许添加其它头文件
   2、不允许定义全局变量、静态局部变量
   3、允许添加用于输入层数、起始/目标柱的函数，函数中允许使用循环处理错误输入
   4、如果输入用函数进行，则main中不允许出现任何形式的循环
      如果输入在main中进行，则main中允许出现循环
   --------------------------------------------------------------------- */

   /***************************************************************************
     函数名称：
     功    能：打印n层汉诺塔的移动顺序
     输入参数：int n：层数
               char src：起始柱
               char tmp：中间柱
               char dst：目标柱
     返 回 值：
     说    明：1、函数名、形参、返回类型均不准动
               2、本函数不允许出现任何形式的循环
   ***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
	if (n == 1) {
		cout << setw(2) << n << "# " << src << "-->" << dst << endl; 
	}
	else if(n>1){
		hanoi(n - 1, src, dst, tmp); 
		cout << setw(2) << n << "# " << src << "-->" << dst << endl;
		hanoi(n - 1, tmp, src, dst);
	}

}

void input()
{
	int c;
	char qs,zj=0, mb;
	while (1) {
		cout << "请输入汉诺塔的层数(1-16)"<<endl;
		cin >> c;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(65535, '\n');
			cout << "请输入汉诺塔的层数(1-16)" << endl;
			cin >>c;
		}
		if (c<=0||c>=17) {
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
		cout << "请输入起始柱(A-C)" << endl;
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
		cout << "请输入目标柱(A-C)" << endl;;
		cin >> mb;
		if ((mb == 'a' || mb == 'b' || mb == 'c' || mb == 'A' || mb == 'B' || mb == 'C')&&mb!=qs) {
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
	if ((qs == 'a' || qs == 'A') &&( mb == 'b' || mb == 'B')) {
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
		
	cout << "移动步骤为:" << endl;
	hanoi(c, qs, zj, mb);
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：完成输入(或调用输入函数)、调用递归函数
***************************************************************************/
int main()
{
	input();

	return 0;
}
/* 信16 2151299 苏家铭*/
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <windows.h> //取系统时间
using namespace std;

int main()
{
	LARGE_INTEGER tick, begin, end;

	QueryPerformanceFrequency(&tick);	//获得计数器频率
	QueryPerformanceCounter(&begin);	//获得初始硬件计数器计数

	/* 此处是你的程序开始 */
	int a,b,c,a1, b1,c1,a2,b2,c2,a3,b3,c3,sum,i;
	i = 0;
	for (a = 123; a <= 987; a++) {
		a1 = a / 100;
		b1 = (a - a1 * 100) / 10;
		c1 = a - a1 * 100 - b1 * 10;
		if (a1 != b1&&a1 != c1&&b1!=c1&&a1!=0&&b1!=0&&c1!=0) {
			for (b = 123; b <= 987; b++) {
				a2 = b / 100;
				b2 = (b - a2 * 100) / 10;
				c2 = b - a2 * 100 - b2 * 10;
				if (a1 != b1 &&a1!= c1 &&a1!= a2 &&a1!= b2&&a1 != c2&&
					b1 != c1 && b1 != a2 && b1 != b2 && b1 != c2&&
					c1 != a2 && c1 != b2 && c1 != c2&&
					a2 != b2 && a2 != c2&&
					b2 != c2&&
					a<b&& 
					a1 != 0 && b1 != 0 && c1 != 0&& a2 != 0 && b2 != 0 && c2 != 0) {
					for (c = 123; c <= 987; c++) {
						a3 = c / 100;
						b3 = (c - a3 * 100) / 10;
						c3 = c - a3 * 100 - b3 * 10;
						if (c3 != b1 && c3 != c1 && c3 != a2 && c3 != b2 && c3 != c2 && c3 != a1 && c3 != a3 &&c3!=b3&&
							b3 != b1 && b3 != c1 && b3 != a2 && b3 != b2 && b3 != c2 && b3 != a1 &&b3!=a3&&
							a3 != b1 && a3 != c1 && a3 != a2 && a3 != b2 && a3 != c2 &&a3!=a1&&
							a1 != b1 && a1 != c1 && a1 != a2 && a1 != b2 && a1 != c2 &&
							b1 != c1 && b1 != a2 && b1 != b2 && b1 != c2 &&
							c1 != a2 && c1 != b2 && c1 != c2 &&
							a2 != b2 && a2 != c2 &&
							b2 != c2&&
							b<c&&a<b&&a<c&&
							a1 != 0 && b1 != 0 && c1 != 0 && a2 != 0 && b2 != 0 && c2 != 0 && a3 != 0 && b3 != 0 && c3 != 0) {
							sum = a + b + c;
							if (sum == 1953) {
								i = i + 1;
								cout << "No." <<setiosflags(ios::right) << setw(3) << i << " : " << a << "+" << b << "+" << c << "=1953" << endl;
							}
						}
					}
				}
			}
		}
		
	}

	/* 此处是你的程序结束 */

	QueryPerformanceCounter(&end);		//获得终止硬件计数器计数

	cout << "计数器频率 : " << tick.QuadPart << "Hz" << endl;
	cout << "计数器计数 : " << end.QuadPart - begin.QuadPart << endl;
	cout << setiosflags(ios::fixed) << setprecision(6) << double(end.QuadPart - begin.QuadPart) / tick.QuadPart << "秒" << endl;

	return 0;
}
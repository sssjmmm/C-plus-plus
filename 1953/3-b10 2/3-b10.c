/* 信16 2151299 苏家铭*/
#include <stdio.h>
#include <windows.h> //取系统时间

int main()
{
	LARGE_INTEGER tick, begin, end;

	QueryPerformanceFrequency(&tick);	//获得计数器频率
	QueryPerformanceCounter(&begin);	//获得初始硬件计数器计数

	/* 此处是你的程序开始 */
	int a, b, c, a1, b1, c1, a2, b2, c2, a3, b3, c3, sum, i;
	i = 0;
	for (a = 123; a <= 987; a++) {
		a1 =(int)( a / 100);
		b1 = (int)((a - a1 * 100) / 10);
		c1 = (int)(a - a1 * 100 - b1 * 10);
		if (a1 != b1 && a1 != c1 && b1 != c1 && a1 != 0 && b1 != 0 && c1 != 0) {
			for (b = 123; b <= 987; b++) {
				a2 = (int)(b / 100);
				b2 = (int)((b - a2 * 100) / 10);
				c2 = (int)(b - a2 * 100 - b2 * 10);
				if (a1 != b1 && a1 != c1 && a1 != a2 && a1 != b2 && a1 != c2 &&
					b1 != c1 && b1 != a2 && b1 != b2 && b1 != c2 &&
					c1 != a2 && c1 != b2 && c1 != c2 &&
					a2 != b2 && a2 != c2 &&
					b2 != c2 &&
					a < b &&
					a1 != 0 && b1 != 0 && c1 != 0 && a2 != 0 && b2 != 0 && c2 != 0) {
					for (c = 123; c <= 987; c++) {
						a3 = (int)(c / 100);
						b3 = (int)((c - a3 * 100) / 10);
						c3 = (int)(c - a3 * 100 - b3 * 10);
						if (c3 != b1 && c3 != c1 && c3 != a2 && c3 != b2 && c3 != c2 && c3 != a1 && c3 != a3 && c3 != b3 &&
							b3 != b1 && b3 != c1 && b3 != a2 && b3 != b2 && b3 != c2 && b3 != a1 && b3 != a3 &&
							a3 != b1 && a3 != c1 && a3 != a2 && a3 != b2 && a3 != c2 && a3 != a1 &&
							a1 != b1 && a1 != c1 && a1 != a2 && a1 != b2 && a1 != c2 &&
							b1 != c1 && b1 != a2 && b1 != b2 && b1 != c2 &&
							c1 != a2 && c1 != b2 && c1 != c2 &&
							a2 != b2 && a2 != c2 &&
							b2 != c2 &&
							b < c && a < b && a < c &&
							a1 != 0 && b1 != 0 && c1 != 0 && a2 != 0 && b2 != 0 && c2 != 0 && a3 != 0 && b3 != 0 && c3 != 0) {
							sum = a + b + c;
							if (sum == 1953) {
								i = i + 1;
								printf("No.%3d : %d+%d+%d=1953\n", i, a, b,c);
							}
						}
					}
				}
			}
		}

	}

	/* 此处是你的程序结束 */

	QueryPerformanceCounter(&end);		//获得终止硬件计数器计数

	printf("计数器频率 : %lldHz\n", tick.QuadPart);
	printf("计数器计数 : %lld\n", end.QuadPart - begin.QuadPart);
	printf("%.6f秒\n", (double)(end.QuadPart - begin.QuadPart) / tick.QuadPart);

	return 0;
}
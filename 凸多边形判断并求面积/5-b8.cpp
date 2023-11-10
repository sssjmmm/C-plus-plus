/* 2151299 信16 苏家铭 */
#include<iostream>
#include <cmath>
using namespace std;


double calculatethree(double x1, double x2, double x3, double y1, double y2, double y3);
//海伦公式
double calculatethree(double x1, double x2, double x3, double y1, double y2, double y3) {
	double a, b, c, p;
	double area;
	a = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	b = sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1));
	c = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
	p = (a + b + c) / 2;
	area = sqrt(p * (p - a) * (p - b) * (p - c));
	return area;
}
int main() {
	double mj = 0.0;
	int num, s;
	double x[10], y[10];


	while (1) {
		cout << "请输入多边形的顶点数量(4-7)" << endl;
		cin >> num;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(65535, '\n');
			cout << "请输入多边形的顶点数量(4-7)" << endl;
			cin >> num;
		}
		if (num >= 4 && num <= 7)
			break;
	}
	cout << "请按顺时针/逆时针方向输入4个顶点的x,y坐标：" << endl;
	for (s = 0; s < num; s++) {
		cout << "请输入第" << s + 1 << "个顶点的坐标：" << endl;
		cin >> x[s] >> y[s];
		while (cin.fail()) {
			cin.clear();
			cin.ignore(65535, '\n');
			cout << "请输入第" << s + 1 << "个顶点的坐标：" << endl;
			cin >> x[s] >> y[s];
		}
	}

	x[s] = x[0];
	y[s] = y[0];
	x[s+1] = x[1];
	y[s+1] = y[1];

	int num1 = 0;
	int num2 = 0;
	for (int i = 0; i < s; i++) {//向量叉乘 用符号判断
		if ((x[i + 1] - x[i]) * (y[i + 2] - y[i + 1]) -
			                 (x[i + 2] - x[i + 1]) * (y[i + 1] - y[i]) > 0) {
			num1++;
		}
		else if (fabs((x[i + 1] - x[i]) * (y[i + 2] - y[i + 1]) -
			                 (y[i + 1] - y[i]) * (x[i + 2] - x[i + 1])) < 1e-8) {
			cout << "不是凸" << num << "边形" << endl;
			break;
		}
		else if((x[i + 1] - x[i]) * (y[i + 2] - y[i + 1]) -
			                  (x[i + 2] - x[i + 1]) * (y[i + 1] - y[i]) < 0) {
			num2++;
		}
	}

	for (int i = 1; i < num - 1; i++) {
		mj = mj + calculatethree(x[0], x[i], x[i + 1], y[0], y[i], y[i + 1]);
	}

	if (num1 == num || num2 == num) {
		cout << "凸" << num << "边形的面积=" << mj << endl;
	}

	return 0;
}
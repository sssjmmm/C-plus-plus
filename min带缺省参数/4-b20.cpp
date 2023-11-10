/* 2151299 信16 苏家铭 */
#include <iostream>
using namespace std;

int min();
int main() {
	min();
	return 0;
}
int min() {
	int num, a, b, c, d, m;
	m = 0;
	while (1) {
		cout << "请输入个数num及num个正整数：" << endl;
		cin >> num;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(65535, '\n');
			cout << "请输入个数num及num个正整数：" << endl;
			cin >> num;
		}
		if (num == 2) {
			cin >> a >> b;
			if (cin.fail()) {
				while (cin.fail()) {
					cin.clear();
					cin.ignore(65535, '\n');
				}
				continue;
			}
			int e = (a < b ? a : b);
			cout << "min=" << e << endl;
			return e;
		}
		else if (num == 3) {
			cin >> a >> b >> c;
			if (cin.fail()) {
				while (cin.fail()) {
					cin.clear();
					cin.ignore(65535, '\n');
				}
				continue;
			}
			int e = (a < b ? a : b);
			int f = (e < c ? e : c);
			cout << "min=" << f << endl;
			return f;
		}
		else if (num == 4) {
			cin >> a >> b >> c >> d;
			if (cin.fail()) {
				while (cin.fail()) {
					cin.clear();
					cin.ignore(65535, '\n');
				}
				continue;
			}
			int e = (a < b ? a : b);
			int f = (e < c ? e : c);
			int g = (f < d ? f : d);
			cout << "min=" << g << endl;
			return g;
		}
		else
			cout << "个数输入错误" << endl;
		return 0;
	}

}


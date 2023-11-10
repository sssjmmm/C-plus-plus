/* 信16 2151299 苏家铭 */
#include <iostream>
using namespace std;
#define n 1001
int main() {
	cout << "请输入成绩（最多1000个），以-1结束" << endl;
	int a[n], k, sum = 0,m=0,s=1,f=-1;
	for (f = 1; f < n - 1; f++) {
		a[f] = -f;
	}
	for (int i = 0; i < n - 1; i++) {
		cin >> k;
		if (k < 0)
			break;
		else {
			a[i] = k;
			sum++;
		}
	}
	cin.clear();
	cin.ignore(65535, '\n');
	if (a[0] < 0) {
		cout << "无有效输入" << endl;
		return 0;
	}
	else {
		cout << "输入的数组为:" << endl;
		for (int i = 0; i < sum; i++) {
			cout << a[i] << " ";
			m++;
			if (m % 10 == 0)
				cout << endl;
		}
	}
	cout << endl;
	cout << "分数与人数的对应关系为:" << endl;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - (i + 1); j++) {
			if (a[j] < a[j + 1]) {
				int t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
	}
	for (int i = 0; i < sum; i++) {
		if (a[i] == a[i + 1]) {
			s++;
		}
		else {
			cout << a[i] << " " << s << endl;
			s = 1;
		}
	}
	return 0;
}
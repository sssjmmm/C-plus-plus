/* 信16 2151299 苏家铭 */
#include <iostream>
using namespace std;
#define n 21
int main() {
	cout << "请输入任意个正整数（升序，最多20个），以-1结束" << endl;
	int a[n] = {0}, k,sum=0;
	for (int i = 0; i < n-1; i++) {
		cin >> k;
		if (k <0)
			break;
		else {
			a[i] = k;
			sum++;
		}
	}
	cin.clear();
	cin.ignore(65535, '\n');
	if (a[0] <= 0) {
		cout << "无有效输入" << endl;
		return 0;
	}
	else {
		cout << "原数组为：" << endl;
		for (int i = 0; i < sum; i++) {
			cout << a[i] << " ";
		}
	}
	cout << endl;
	cout << "请输入要插入的正整数" << endl;
	cin >> a[n-1];
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < n - (i+1); j++) {
			if (a[j] > a[j + 1]) {
				int t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
	}
	cout << "插入后的数组为：" << endl;
	for (int i = n-sum-1; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}
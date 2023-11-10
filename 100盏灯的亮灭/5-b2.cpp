/* ĞÅ16 2151299 ËÕ¼ÒÃú */
#include <iostream>
using namespace std;
#define n 101
int main() {

	int a[n] = { 0 };//0Ãğ 1ÁÁ
	int p, d;//pupil deng 

	for (p = 1; p < n; p++) {
		for (d = 1; d < n; d++) {
			if (d % p == 0)
				a[d] == 0 ? a[d] = 1 : a[d] = 0;
		}
	}

	cout << "1";
	for (p = 2; p <= 100; p++) {
		if (a[p] == 1) {
			cout<<" " << p;
		}
	}
	cout << endl;
	return 0;

}
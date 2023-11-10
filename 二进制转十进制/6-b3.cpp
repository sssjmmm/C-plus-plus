/* 2151299 苏家铭 信16 */
#include <iostream>
#include<cmath>
using namespace std;
#define N 32
int main() {
	cout << "请输入一个0/1组成的字符串，长度不超过32" << endl;
	char bin[N + 1], * p1=bin;
	unsigned int oct=0;

	cin >> p1;
	while (*p1 != '\0')
		p1++;
	p1 -= 1;//将pb指向最后一个字符
	for (int k=0; p1>=bin; p1--,k++) {
		oct = (*p1 - 48) *int (pow(2, k)) + oct;
	}
	cout << oct << endl;
	return 0;
}

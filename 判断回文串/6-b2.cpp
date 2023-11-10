/* 2151299 苏家铭 信16 */
#include <iostream>
#include <cstdio>
using namespace std;
#define N 80

bool judge(char *a) {
	char *pa=a,*pb=a;
	while (*pb != '\0')
		pb++;
	pb -= 2;//将pb指向最后一个非回车字符
	for (int k=0;k<(int(strlen(a))/2); k++) {
		if (*pa != *pb) {
			return false;
		}
		else {
			pa++;
			pb--;
		}
	}
	return true;

}
int main() {
	char str[N+2];
	bool out;
	cout << "请输入一个长度小于80的字符串（回文串）" << endl;
	fgets(str, N, stdin);
	out=judge(str);
	if (out)
		cout << "yes" << endl;
	else if (!out)
		cout << "no" << endl;
	return 0;
}
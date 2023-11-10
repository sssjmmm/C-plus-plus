/*2151299 ĞÅ16 ËÕ¼ÒÃú*/
#include<iostream>
#include <iomanip>
using namespace std;
int main()
{
	int a = 0, b = 0, j = 0;
	for (a = 1; a <= 9; a++){
		for (b = 1; b <= a; b++){
			j = b*a;
			cout << b << "x" << a << "=" << setiosflags(ios::left) << setw(4) << j;
		}
		cout << endl;
	}
	cout << endl;
	return 0;
}
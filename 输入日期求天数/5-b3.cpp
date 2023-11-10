/*2151299 信16 苏家铭*/
#include<iostream>
using namespace std;

int judgeleap(int month, int year);
int sum(int year, int month, int day);
int judgeleap(int month,int year) {

	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
	return 1;
	else
	return 0;
}
int sum(int year, int month, int day) {
	int sum=0,i;
	int monthx[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	for (i = 0; i < month-1; i++) {
		sum = sum + monthx[i];
	}
	if (month > 2) {
		sum = sum + day + judgeleap(month, year);
		return sum;
	}
	else {
		sum = sum + day ;
		return sum;
	}
	
}
int main()
{
	int year, month, day,sumx,a=1,b;
	sumx = 0;
	cout << "请输入年，月，日" << endl;
	cin >> year >> month >> day;
	sumx = sum(year, month, day);
	cout << "第" << sumx << "天" << endl;
	


	return 0;
}
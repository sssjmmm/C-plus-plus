/*2151299 信16 苏家铭*/
#include<iostream>
using namespace std;
int main()
{
	int year, month, day,x,r,a=1;
	day = 0;
	x = 0;
	r = 28;
	cout << "请输入年，月，日" << endl;
	cin >> year >> month >> day;
	if (month >= 13 || month <= 0) {
		cout << "输入错误-月份不正确" << endl;
		a = 0;
	}
	else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 ||month == 12 ) {
		if (day > 31 || day < 1) {
			cout << "输入错误-日与月的关系非法" << endl;
			a = 0;
		}		
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11) {
		if (day > 30 || day < 1) {
			cout << "输入错误-日与月的关系非法" << endl;
			a = 0;
		}
	}
	else if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
			if (month == 2 && day > 29) {
				cout << "输入错误-日与月的关系非法" << endl;
				a = 0;
			 }
		     else
			 r = 29;
	}
	else if (!(year % 4 == 0 && year % 100 != 0 || year % 400 == 0)) {
		if (month == 2 && day > 28) {
			printf("输入错误-日与月的关系非法");
			a = 0;
		}
	}
	if (a == 1) {
		if (month == 1)
			x = day;
		else if (month == 2)
			x = 31 + day;
		else if (month == 3)
			x = 31 + r + day;
		else if (month == 4)
			x = 31 + r + 31 + day;
		else if (month == 5)
			x = 31 + r + 31 + 30 + day;
		else if (month == 6)
			x = 31 + r + 31 + 30 + +31 + day;
		else if (month == 7)
			x = 31 + r + 31 + 30 + +31 + 30 + day;
		else if (month == 8)
			x = 31 + r + 31 + 30 + +31 + 30 + 31 + day;
		else if (month == 9)
			x = 31 + r + 31 + 30 + +31 + 30 + 31 + 31 + day;
		else if (month == 10)
			x = 31 + r + 31 + 30 + +31 + 30 + 31 + 31 + 30 + day;
		else if (month == 11)
			x = 31 + r + 31 + 30 + +31 + 30 + 31 + 31 + 30 + 31 + day;
		else if (month == 12)
			x = 31 + r + 31 + 30 + +31 + 30 + 31 + 31 + 30 + 31 + +30 + day;
		cout << year << "-" << month << "-" << day << "是" << year << "年的第" << x << "天" << endl;
	}
	return 0;
}
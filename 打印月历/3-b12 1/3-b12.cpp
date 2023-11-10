/* 信16 2151299 苏家铭 */
#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;
int main() {
	int year,month,day,y,x,n,a;
	y= 1;
	n = 1;
	a = 0;
	while (1) {
		cout << "请输入年份(2000-2030)和月份(1-12) :";
		cin >> year>>month;   
		while (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<int>::max(), '\n');
			cout << "输入非法，请重新输入"<<endl;
			cout << "请输入年份(2000-2030)和月份(1-12) :";
			cin >> year >> month;
		}
		if (year < 2000 || year>2030 || month > 12 || month < 1) {
			cout << "输入非法，请重新输入" << endl;
		}
		if (year >= 2000 && year <= 2030&&month>=1&&month<=12)
			break;
	}
	while (1) {
		cout << "请输入"<<year<<"年"<<month<<"月1日的星期(0 - 6表示星期日 - 星期六) :";
		cin >> day;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<int>::max(), '\n');
			cout << "输入非法，请重新输入"<<endl;
			cout << "请输入" << year << "年" << month << "月1日的星期(0 - 6表示星期日 - 星期六) :";
			cin >> day;
		}
		if (day > 6 || day < 0)
			cout << "输入非法，请重新输入" << endl;
		if (day>=0&&day<=6)
			break;
	}
	cout << endl;
	cout << year << "年" << month << "月的月历为:" << endl;
	cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六" << endl;
	
	if (month == 1)
		n = 31;
	else if (month == 2)
		n = 28;
	else if (month == 3)
		n = 31;
	else if (month == 4)
		n = 30;
	else if (month == 5)
		n = 31;
	else if (month == 6)
		n = 30;
	else if (month == 7)
		n = 31;
	else if (month == 8)
		n = 31;
	else if (month == 9)
		n = 30;
	else if (month == 10)
		n = 31;
	else if (month == 11)
		n = 30;
	else if (month == 12)
		n = 31;
	if ((year % 4 == 0 && year % 100 != 0 || year % 400 == 0) && month == 2)
		n = 29;

	if (day == 0) {
		
		x = 0;
		while (n >= 1) {
			if ((a > 1 && a < 8) || (a > 8 && a < 15) || (a > 15 && a < 22) || (a > 22 && a < 29) || (a > 29 && a < 36) || (a > 36 && a < 42)) {
				cout << setw(8) << y;
			}
			else if ((a % 8 == 0 || a % 15 == 0 || a % 22 == 0 || a % 29 == 0 || a % 36 == 0||a%43==0) && (y != 1)) {
				cout << endl;
				cout << setw(4) << y;
			}
			else if (y == 1)
				cout << setw(4) << y;
			n--;
			y++;
			a = y + x;
		}
	}
	else if (day == 1) {
		cout << "        ";
		x = 1;
		while (n >= 1) {
			if ((a > 1 && a < 8) || (a > 8 && a < 15) || (a > 15 && a < 22) || (a > 22 && a < 29) || (a > 29 && a < 36) || (a > 36 && a < 42)) {
				cout << setw(8) << y;
			}
			else if ((a % 8 == 0 || a % 15 == 0 || a % 22 == 0 || a % 29 == 0 || a % 36 == 0 || a % 43 == 0) && (y != 1)) {
				cout << endl;
				cout << setw(4) << y;
			}
			else if (y == 1)
				cout << setw(4) << y;
			n--;
			y++;
			a = y + x;
		}
	}
	else if (day == 2) {
		cout << "                ";
		x = 2;
		while (n >= 1) {
			if ((a > 1 && a < 8) || (a > 8 && a < 15) || (a > 15 && a < 22) || (a > 22 && a < 29) || (a > 29 && a < 36) || (a > 36 && a < 42)) {
				cout << setw(8) << y;
			}
			else if ((a % 8 == 0 || a % 15 == 0 || a % 22 == 0 || a % 29 == 0 || a % 36 == 0 || a % 43 == 0) && (y != 1)) {
				cout << endl;
				cout << setw(4) << y;
			}
			else if (y == 1)
				cout << setw(4) << y;
			n--;
			y++;
			a = y + x;
		}
	}
	else if (day == 3) {
		cout << "                        ";
		x = 3;
		while (n >= 1) {
			if ((a > 1 && a < 8) || (a > 8 && a < 15) || (a > 15 && a < 22) || (a > 22 && a < 29) || (a > 29 && a < 36)||(a > 36 && a < 42)) {
				cout << setw(8) << y;
			}
			else if ((a % 8 == 0 || a % 15 == 0 || a % 22 == 0 || a % 29 == 0||a%36==0 || a % 43 == 0) && ( y != 1)) {
				cout << endl;
				cout << setw(4) << y;
			}
			else if (y == 1)
				cout << setw(4) << y;
			n--;
			y++;
			a = y + x;
		}
	}
	else if (day == 4) {
		cout << "                                ";
		x = 4;
		while (n >= 1) {
			if ((a > 1 && a < 8) || (a > 8 && a < 15) || (a > 15 && a < 22) || (a > 22 && a < 29) || (a > 29 && a < 36) || (a > 36 && a < 42)) {
				cout << setw(8) << y;
			}
			else if ((a % 8 == 0 || a % 15 == 0 || a % 22 == 0 || a % 29 == 0 || a % 36 == 0 || a % 43 == 0) && (y != 1)) {
				cout << endl;
				cout << setw(4) << y;
			}
			else if (y == 1)
				cout << setw(4) << y;
			n--;
			y++;
			a = y + x;
		}
	}
	else if (day == 5) {
		cout << "                                        ";
		x = 5;
		while (n >= 1) {
			if ((a > 1 && a < 8) || (a > 8 && a < 15) || (a > 15 && a < 22) || (a > 22 && a < 29) || (a > 29 && a < 36) || (a > 36 && a < 42)) {
				cout << setw(8) << y;
			}
			else if ((a % 8 == 0 || a % 15 == 0 || a % 22 == 0 || a % 29 == 0 || a % 36 == 0 || a % 43 == 0) && (y != 1)) {
				cout << endl;
				cout << setw(4) << y;
			}
			else if (y == 1)
				cout << setw(4) << y;
			n--;
			y++;
			a = y + x;
		}
	}
	else if (day == 6) {
		cout << "                                                ";
		x = 6;
		while (n >= 1) {
			if ((a > 1 && a < 8) || (a > 8 && a < 15) || (a > 15 && a < 22) || (a > 22 && a < 29) || (a > 29 && a < 36) || (a > 36 && a < 42)) {
				cout << setw(8) << y;
			}
			else if ((a % 8 == 0 || a % 15 == 0 || a % 22 == 0 || a % 29 == 0 || a % 36 == 0 || a % 43 == 0) && (y != 1)) {
				cout << endl;
				cout << setw(4) << y;
			}
			else if (y == 1)
				cout << setw(4) << y;
			n--;
			y++;
			a = y + x;
		}
	}
	cout << endl;
	return 0;
}

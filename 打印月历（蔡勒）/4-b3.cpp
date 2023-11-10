/* 信16 2151299 苏家铭 */
#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

int zeller(int y, int m, int d)
{
	int c, w;
	if (m != 1 && m != 2) {
		c = y / 100;
		y = y - c * 100;
	}
	if (m == 1) {
		m = 13;
		y = y - 1;
		c = y / 100;
		y = y - c * 100;
	}
	if (m == 2) {
		m = 14;
		y = y - 1;
		c = y / 100;
		y = y - c * 100;
	}
	w = y + y / 4 + c / 4 - 2 * c + (13 * (m + 1) / 5) + d - 1;
	if (w < 0)
		w = w % 7 + 7;
	else if (w > 0)
		w = w % 7;
	return w;
}

void calendar(int year,int month,int day)
{
	int n, x, y, a;
	y = 1;
	n = 1;
	a = 0;
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
			else if ((a % 8 == 0 || a % 15 == 0 || a % 22 == 0 || a % 29 == 0 || a % 36 == 0 || a % 43 == 0) && (y != 1)) {
				cout << "    " << endl;
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
				cout << "    " << endl;
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
				cout << "    " << endl;
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
			if ((a > 1 && a < 8) || (a > 8 && a < 15) || (a > 15 && a < 22) || (a > 22 && a < 29) || (a > 29 && a < 36) || (a > 36 && a < 42)) {
				cout << setw(8) << y;
			}
			else if ((a % 8 == 0 || a % 15 == 0 || a % 22 == 0 || a % 29 == 0 || a % 36 == 0 || a % 43 == 0) && (y != 1)) {
				cout << "    " << endl;
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
				cout << "    " << endl;
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
				cout << "    " << endl;
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
				cout << "    " << endl;
				cout << setw(4) << y;
			}
			else if (y == 1)
				cout << setw(4) << y;
			n--;
			y++;
			a = y + x;
		}
	}
	cout << "    ";
}

int main() {
	int year, month, day,k;
	while (1) {
		cout << "请输入年[1900-2100]、月"<<endl;
		cin >> year >> month;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<int>::max(), '\n');
			cout << "输入错误，请重新输入" << endl;
			cout << "请输入年[1900-2100]、月"<<endl;
			cin >> year >> month;
		}
		if (year < 1900 || year>2100) {//year
			cout << "年份不正确，请重新输入" << endl;
		}
		else if ((year >= 1900 && year <= 2100) && (month < 1 || month > 12)) {//month
			cout << "月份不正确，请重新输入" << endl;
		}
		if ((year >= 1900 && year <= 2100) && (month >= 1 && month <= 12))
			break;
	}
	cout << endl;
	cout << year << "年" << month << "月" << endl;
	cout << "======================================================"<<endl;
	cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六" << endl;
	cout << "======================================================"<<endl;
	day = 1;
	k = zeller(year, month, day);
	calendar(year, month, k);
	cout << endl;
	cout << endl;
	return 0;
}

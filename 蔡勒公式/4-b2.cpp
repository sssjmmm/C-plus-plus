/* 信16 2151299 苏家铭 */
#include <iostream>
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
		w = w%7+7;
	else if (w > 0)
		w = w % 7;
	return w;
}

void daxie(int w)
{
	switch (w) {
		case 0:
			cout << "日";
			break;
		case 1:
			cout << "一";
			break;
		case 2:
			cout << "二";
			break;
		case 3:
			cout << "三";
			break;
		case 4:
			cout << "四";
			break;
		case 5:
			cout << "五";
			break;
		case 6:
			cout << "六";
			break;
	}
}

int main()
{
	int year, month, day,a,k;
 	while (1) {
		a = 1;
		cout << "请输入年[1900-2100]、月、日："<<endl;
		cin >> year >> month >> day;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<int>::max(), '\n');
			cout << "输入错误，请重新输入" << endl;
			cout << "请输入年[1900-2100]、月、日："<<endl;
			cin >> year >> month >> day;
		}
		if (year < 1900 || year>2100) {//year
			cout << "年份不正确，请重新输入" << endl;
			a = 0;
		}
		else if ((year >= 1900 && year <= 2100) && (month < 1 || month > 12)) {//month
			cout << "月份不正确，请重新输入" << endl;
			a = 0;
		}
		else if ((year >= 1900 && year <= 2100) && (month >= 1 || month <= 12)) {//day
			if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
				if (month == 2 && day > 29) {
					cout << "日不正确，请重新输入" << endl;
					a = 0;
				}				
			}		
			if (month == 1 && (day <= 0 || day > 31)) {
				cout << "日不正确，请重新输入" << endl;
				a = 0;
			}				
			else if (month == 2 && !(year % 4 == 0 && year % 100 != 0 || year % 400 == 0) && (day <= 0 || day > 28)) {
                cout << "日不正确，请重新输入" << endl;
				a = 0;
			}				
			else if (month == 3 && (day <= 0 || day > 31)) {
				cout << "日不正确，请重新输入" << endl;
				a = 0;
			}				
			else if (month == 4 && (day <= 0 || day > 30)) {
				cout << "日不正确，请重新输入" << endl;
				a = 0;
			}			
			else if (month == 5 && (day <= 0 || day > 31)) {
				cout << "日不正确，请重新输入" << endl;
				a = 0;
			}				
			else if (month == 6 && (day <= 0 || day > 30)) {
				cout << "日不正确，请重新输入" << endl;
				a = 0;
			}				
			else if (month == 7 && (day <= 0 || day > 31)) {
				cout << "日不正确，请重新输入" << endl;
				a = 0;
			}				
			else if (month == 8 && (day <= 0 || day > 31)) {
				cout << "日不正确，请重新输入" << endl;
				a = 0;
			}				
			else if (month == 9 && (day <= 0 || day > 30)) {
				cout << "日不正确，请重新输入" << endl;
				a = 0;
			}				
			else if (month == 10 && (day <= 0 || day > 31)) {
				cout << "日不正确，请重新输入" << endl;
				a = 0;
			}				
			else if (month == 11 && (day <= 0 || day > 30)) {
				cout << "日不正确，请重新输入" << endl;
				a = 0;
			}				
			else if (month == 12 && (day <= 0 || day > 31)) {
				cout << "日不正确，请重新输入" << endl;
				a = 0;
			}
		}
	    if(a == 1&& (year >= 1900 && year <= 2100) && (month >= 1 && month <= 12))
		    break;
	}
	k = zeller(year, month, day);
	cout << "星期";
	daxie(k);
	cout << endl;
	return 0;
}
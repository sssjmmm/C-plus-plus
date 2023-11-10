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

void recordcalendar(int year, int month1, int month2, int month3, int day1, int day2, int day3)
{
	int n1,n2,n3;
	n1 = 1;
	n2 = 1;
	n3 = 1;
	if (month1 == 1)
		n1 = 31;
	else if (month1 == 2)
		n1 = 28;
	else if (month1 == 3)
		n1 = 31;
	else if (month1 == 4)
		n1 = 30;
	else if (month1 == 5)
		n1 = 31;
	else if (month1 == 6)
		n1 = 30;
	else if (month1 == 7)
		n1 = 31;
	else if (month1 == 8)
		n1 = 31;
	else if (month1 == 9)
		n1 = 30;
	else if (month1 == 10)
		n1 = 31;
	else if (month1 == 11)
		n1 = 30;
	else if (month1 == 12)
		n1 = 31;
	if ((year % 4 == 0 && year % 100 != 0 || year % 400 == 0) && month1 == 2)
		n1 = 29;

	if (month2 == 1)
		n2 = 31;
	else if (month2 == 2)
		n2 = 28;
	else if (month2 == 3)
		n2 = 31;
	else if (month2 == 4)
		n2 = 30;
	else if (month2 == 5)
		n2 = 31;
	else if (month2 == 6)
		n2 = 30;
	else if (month2 == 7)
		n2 = 31;
	else if (month2 == 8)
		n2 = 31;
	else if (month2 == 9)
		n2 = 30;
	else if (month2 == 10)
		n2 = 31;
	else if (month2 == 11)
		n2 = 30;
	else if (month2 == 12)
		n2 = 31;
	if ((year % 4 == 0 && year % 100 != 0 || year % 400 == 0) && month2 == 2)
		n2 = 29;

	if (month3 == 1)
		n3 = 31;
	else if (month3 == 2)
		n3 = 28;
	else if (month3 == 3)
		n3 = 31;
	else if (month3 == 4)
		n3 = 30;
	else if (month3 == 5)
		n3 = 31;
	else if (month3 == 6)
		n3 = 30;
	else if (month3 == 7)
		n3 = 31;
	else if (month3 == 8)
		n3 = 31;
	else if (month3 == 9)
		n3 = 30;
	else if (month3 == 10)
		n3 = 31;
	else if (month3 == 11)
		n3 = 30;
	else if (month3 == 12)
		n3 = 31;
	if ((year % 4 == 0 && year % 100 != 0 || year % 400 == 0) && month3 == 2)
		n3 = 29;

	int record[7][24];//666表示空格
	//第一个月
	int r1 = 1;
	for (int i = 1; i < day1+1; i++) {
		record[1][i] = 666;
	}
	for (int i = 1; i <= n1; i++) {
		record[r1][day1+1] = i;
		if (day1 == 6) {
			record[r1][day1 + 2] = 666;
			r1++;
		}			
		day1 = (++day1) % 7;
	}
	
	//第二个月
	int r2 = 1;
	for (int i = 1; i < day2 + 1; i++) {
		record[1][i + 8] = 666;
	}
	for (int i = 1; i <= n2; i++) {
		record[r2][day2 + 1 + 8] = i;
		if (day2 == 6) {
			record[r2][day2 + 2 + 8] = 666;
			r2++;
		}
		day2 = (++day2) % 7;
	}
	//第三个月
	int r3 = 1;
	for (int i = 1; i < day3 + 1; i++) {
		record[1][i + 8 + 8] = 666;
	}
	for (int i = 1; i <= n3; i++) {
		record[r3][day3 + 1 + 8 + 8] = i;
		if (day3 == 6) {
			r3++;
		}
		day3 = (++day3) % 7;
	}
	//看看第六行有没有数字
	int sjm = 1, num = 0;
	for (; sjm < 24; sjm++) {
		if (record[6][sjm] > 0&&record[6][sjm]<33)
			num++;
	}
	if (num == 0)
		num = 0;
	else
		num = 1;
	//记录三个月的末尾空格
	for (; r1 <= 5+num;) {
		record[r1][day1 + 1] = 666;
		if (day1 == 6) {
			record[r1][day1 + 2] = 666;
			r1++;
		}
		day1 = (++day1) % 7;
	}
	for (; r2 <= 5 + num;) {
		record[r2][day2 + 1 + 8] = 666;
		if (day2 == 6) {
			record[r2][day2 + 2 + 8] = 666;
			r2++;
		}
		day2 = (++day2) % 7;
	}
	for (; r3 <= 5 + num;) {
		record[r3][day3 + 1 + 8 + 8] = 666;
		if (day3 == 6) {
			r3++;
		}
		day3 = (++day3) % 7;
	}
	//record over
	//It is time to cout
	for (int i = 1; i < 6+num; i++) {
		for (int j = 1; j < 24; j++) {
			
				if (record[i][j] == 666||record<0)
					cout << setiosflags(ios::left) << setw(4) << " ";
				else if(record[i][j]<33&& record[i][j]>0)
					cout << setiosflags(ios::left) << setw(4) << record[i][j];
				if (j == 23)
					cout << endl;
			
		}
	}
}

int main() {
	system("mode con cols=120 lines=45");
	int year,day;
	int monthx[13] = {0,1,2,3,4,5,6,7,8,9,10,11,12};
	int week[14] = { 0 };
	while (1) {
		cout << "请输入年份[1900-2100]" << endl;
		cin >> year;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(65535, '\n');
			cout << "请输入年份[1900-2100]" << endl;
			cin >> year;
		}
		if (year < 1900 || year>2100) {//year
			cout << "请输入年份[1900-2100]" << endl;
		}
		else if (year >= 1900 && year <= 2100)
			break;
	}
	cout << year << "年的日历:"<< endl;
	cout<< endl;
	day = 1;
	int i;
	cout << "            1月                             2月                             3月" << endl;
	cout << "Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat" << endl;
	for (i = 1; i < 4; i++) {
		week[i] = zeller(year, monthx[i], day);
	}
	recordcalendar(year, monthx[1], monthx[2], monthx[3], week[1], week[2], week[3]);
	cout << endl;
	cout << "            4月                             5月                             6月" << endl;
	cout << "Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat" << endl;
	for (i = 4; i < 7; i++) {
		week[i] = zeller(year, monthx[i], day);
	}
	recordcalendar(year, monthx[4], monthx[5], monthx[6], week[4], week[5], week[6]);
	cout << endl;
	cout << "            7月                             8月                             9月" << endl;
	cout << "Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat" << endl;
	for (i = 7; i < 10; i++) {
		week[i] = zeller(year, monthx[i], day);
	}
	recordcalendar(year, monthx[7], monthx[8], monthx[9], week[7], week[8], week[9]);
	cout << endl;
	cout << "           10月                            11月                            12月" << endl;
	cout << "Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat" << endl;
	for (i = 10; i < 13; i++) {
		week[i] = zeller(year, monthx[i], day);
	}
	recordcalendar(year, monthx[10], monthx[11], monthx[12], week[10], week[11], week[12]);
	cout << endl;
	cout << endl;
	return 0;
}


/*
for (int i = 0; i < day; i++)
cout << setw(4) << " ";
for (int i = 1; i <= n; i++) {
	cout << setiosflags(ios::left) << setw(4) << i;
	if (day == 6)
		cout << endl;
	day = (++day) % 7;
}

*/
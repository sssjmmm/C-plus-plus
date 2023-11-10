/* 2151299 苏家铭 信16 */
/* 2152503 李荣诚 2153167 杨铠屹 2153686 张启翔 2151773 霍家灏 2153410 刘金硕 2154301 黄昱翔 */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <cmath>
using namespace std;

int main()
{
	char from[100];
	char to[100];
	cerr << "文件名以下形式均可以:" << endl;
	cerr << "    a.hex                    : 不带路径形式" << endl;
	cerr << "    ..\\data\\b.txt          : 相对路径形式" << endl;
	cerr << "    C:\\Windows\\System32\\c.hex : 绝对相对路径形式" << endl;
	cerr << "请输入要转换的hex格式文件名 : ";
	cin.getline(from, 100);
	cerr << "请输入转换后的文件名        :";
	cin.getline(to, 100);

	int LEN = strlen(from);
	int LEN2 = strlen(to);

	ifstream infile;
	ofstream outfile;
	infile.open(from, ios::in | ios::binary);   
	if (!infile.is_open()) {
		cout << "输入文件";
		for (int i = 0; i < LEN; i++) {
			cout << from[i];
		}
		cout << "打开失败!" << endl;
		return -1;
	}
	//此时输入文件已经打开成功
	outfile.open(to, ios::out | ios::binary);
	if (!outfile.is_open()) {
		cout << "输出文件";
		for (int i = 0; i < LEN2; i++) {
			cout << to[i];
		}
		cout << "打开失败!" << endl;
		infile.close();
		return -1;
	}
	//此时输入、输出文件都已经打开成功



	int n = 0;
	int nx = 0;
	for (int r = 0; infile.peek() != EOF; r++) {//r=row
		//记录
		char arr[82] = { 0 };
		for (int c = 0; (c < 82) && (infile.peek() != EOF);c++) {//c=column
			arr[c] = infile.get();
		}
		char b[9],c[9];
		for (int i = 0; i < 8; i++) {
			b[i] = '0';
		}
		for (int i = 0; i < 8; i++) {
			c[i] = arr[i];
		}
		b[8] = '\0';
		c[8] = '\0';
		n = nx;
		for (int i = 7; n != 0; i--) {
			if (n % 16 == 10)b[i] = 'a';
			else if (n % 16 == 11)b[i] = 'b';
			else if (n % 16 == 12)b[i] = 'c';
			else if (n % 16 == 13)b[i] = 'd';
			else if (n % 16 == 14)b[i] = 'e';
			else if (n % 16 == 15)b[i] = 'f';
			else b[i] = (n % 16) + '0';
			n = n / 16;
		}
		nx += 16;
		int x=strcmp(b, c);
		if (x != 0) {
			cout << "最左侧的偏移量0x" << c << "不是期望值0x" << b << endl;
			break;
		}
		//输出
		for (int c = 10; arr[c]!=-52&&c<=58;) {//c=column
	        int sum = 0;
			if ((arr[c] >= '0' && arr[c] <= '9') || (arr[c] >= 'a' && arr[c] <= 'f')) {
				if (arr[c] >= '0' && arr[c] <= '9')
					sum = sum + (arr[c] - '0') * 16;
				else if (arr[c] >= 'a' && arr[c] <= 'f')
					sum = sum + (arr[c] - 'a' + 10) * 16;
				if (arr[c + 1] >= '0' && arr[c + 1] <= '9')
					sum = sum + (arr[c + 1] - '0');
				else if (arr[c + 1] >= 'a' && arr[c + 1] <= 'f')
					sum = sum + (arr[c + 1] - 'a' + 10);
				if (sum > 127) {
					sum -= 256;		
					outfile << char(sum);
				}
				else
				    outfile << char(sum);
				c += 3;
			}
			else
				c += 2;
		}
	}//end of for



	infile.close();             //关闭文件输入流 
	outfile.close();             //关闭文件输出流 

	return 0;
}

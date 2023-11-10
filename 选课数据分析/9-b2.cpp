/* 2151299 信16 苏家铭 */
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
/* 允许按需加入系统的宏定义、需要的头文件等 */
#include <iostream>
#include <iomanip>
using namespace std;

#define MAX_STU_NUM			256	//约定最大人数为256人（两轮的总和，包括退选、补选）
#define MAX_NAME_LEN			32	//学生姓名的最大长度不超过16个汉字
#define MAX_FILENAME_LEN		256	//文件名的最大长度
class stu_list;
/* stu_info 类存放每个学生的信息，包括学号、姓名、其它需要的私有信息，已有内容不准动，可加入符合限制要求的新内容 */
class stu_info {
private:
	int  stu_no=0;			//学号
	char stu_name[MAX_NAME_LEN]="";	//姓名
	char no1 ='/';
	char no2 = '/';
	friend stu_list;
	/* 允许按需加入private数据成员、成员函数以及其它需要的内容 */

public:
	/* 本类不允许定义任何的公有数据成员、成员函数 */
};

/* stu_list 类整个选课信息，已有内容不准动，可加入符合限制要求的新内容 */
class stu_list {
private:
	stu_info stu[MAX_STU_NUM + 1];
	
	/* 允许按需加入private数据成员和成员函数 */

public:
	int read(const char* filename, const int append = 0);	//从文件中读入选课信息并进行处理，第2个参数值为0表示覆盖方式，1表示追加方式
	void print(const char* prompt = NULL);			//打印当前读入的选课名单

	/* 允许按需加入其它public成员函数 */

};

/* --- 此处给出上面两个类的成员函数的体外实现 --- */
int stu_list::read(const char* filename, const int append ) 
{
	int LEN = strlen(filename);

	ifstream infile;
	infile.open(filename, ios::in | ios::binary);
	if (!infile.is_open()) {
		cout << "文件[";
		for (int i = 0; i < LEN; i++) {
			cout << filename[i];
		}
		cout << "]打开失败" << endl;
		return -1;
	}
	//此时已经打开成功
	if (append == 0) {
		int i;
		for (i = 0; infile.peek() != EOF; i++) {//第一次
			infile >> stu[i].stu_no >> stu[i].stu_name;
			stu[i].no1 = 'Y';
		}
		if(i-1>=0)
		stu[i - 1].no1 = '/';
	}
	else if (append == 1) {
		int a = 0;
		while (1) {
			if (stu[a].stu_no > 0)
				a++;
			else if (stu[a].stu_no == 0)
				break;
		}
		int  stu_no2;			//学号
		char stu_name2[MAX_NAME_LEN];	//姓名
		bool U = false;
		for (int i = 0; infile.peek() != EOF;) {//第二次记录
			U = false;
			infile >> stu_no2 >> stu_name2;
			for (int j = 0; j < MAX_STU_NUM; j++) {
				if (stu_no2 == stu[j].stu_no) {//有两个相同学号
					stu[j].no2 = 'Y';
					U = true;
				}
			}
			if (U == false) {//只有第二次来
				stu[i + a].stu_no= stu_no2;
				strncpy(stu[i + a].stu_name, stu_name2, MAX_NAME_LEN);
				stu[i + a].no2 = 'Y';
				i++;
			}
		}

		//如果有两个相同学号，第一次YY，第二次学号清0，如果只有一个学号，第一次是Y，第二次变成退课，
		//第一次是\第二次是Y，则第二次变成补选
		
		//剩下的学号肯定没有相同的了
		//排序
		int  stu_no;			//学号
		char stu_name[MAX_NAME_LEN];	//姓名
		char no;
		for (int j = 0; j < MAX_STU_NUM - 1; j++) {
			for (int i = 0; i < MAX_STU_NUM - (j + 1); i++) {
				if (stu[i].stu_no > stu[i + 1].stu_no) {
					stu_no = stu[i].stu_no;
					stu[i].stu_no = stu[i + 1].stu_no;
					stu[i + 1].stu_no = stu_no;

					strncpy(stu_name, stu[i].stu_name, MAX_NAME_LEN);
					strncpy(stu[i].stu_name, stu[i + 1].stu_name, MAX_NAME_LEN);
					strncpy(stu[i + 1].stu_name, stu_name, MAX_NAME_LEN);

					no = stu[i].no1;
					stu[i].no1 = stu[i + 1].no1;
					stu[i + 1].no1 = no;

					no = stu[i].no2;
					stu[i].no2 = stu[i + 1].no2;
					stu[i + 1].no2 = no;

				}
			}
		}
	}
	return 0;
}
void stu_list::print(const char* prompt) 
{
	cout << "最终选课名单" << endl;
	cout << "===========================================" << endl;
	cout << "序号 学号    姓名             第一轮 第二轮" << endl;
	cout << "===========================================" << endl;
	int a = 1;
	for (int i = 0; i < MAX_STU_NUM; i++) {
		if (stu[i].stu_no > 0) {
			cout << setiosflags(ios::left) << setw(5) << a << setw(8) << stu[i].stu_no << setw(17) << stu[i].stu_name;
			if (stu[i].no1 == 'Y' && stu[i].no2 == 'Y')
				cout << setw(7) << stu[i].no1 << stu[i].no2;
			else if (stu[i].no1 == 'Y' && stu[i].no2 == '/')
				cout << setw(7) << stu[i].no1 << "退课";
			else if (stu[i].no1 == '/' && stu[i].no2 == 'Y')
				cout << setw(7) << stu[i].no1 << "补选";
			a++;
			cout << endl;
		}

	}
	cout << "===========================================" << endl;

}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数不准动
***************************************************************************/
int main()
{
	char file1[MAX_FILENAME_LEN], file2[MAX_FILENAME_LEN];

	cout << "请输入前一轮选课的数据文件 : ";
	cin >> file1;
	cout << "请输入后一轮选课的数据文件 : ";
	cin >> file2;

	stu_list list;

	/* 读入第一个数据文件 */
	if (list.read(file1) < 0)
		return -1;

	/* 读入第二个数据文件，参数2的值为1表示追加方式 */
	if (list.read(file2, 1) < 0)
		return -1;

	list.print("最终选课名单");

	return 0;
}
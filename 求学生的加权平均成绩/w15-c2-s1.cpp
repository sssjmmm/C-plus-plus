/* 2151299 苏家铭 信16 */
#include <iostream>
#include <iomanip>
using namespace std;

/* ----具体要求----
   1、不允许添加其它头文件
   2、不允许定义全局变量、静态局部变量（全局只读变量或宏定义不受此限制）
   3、不允许添加其它函数
   ---------------------------------------------------------------------
*/

#define N	10

struct course {
	float value;	//某课程的成绩（百分制）
	float weight;	//某课程的学分（权重）
};

struct student {
	int   no;               //学号（虽然用int不够合理，此处不考虑）
	char  name[9];          //假设姓名最长4个汉字
	struct course score[3]; //数组放三门课的成绩（未使用宏定义，函数实现时，直接写3即可）
	float fen;                    //可增加其它你认为需要增加的结构体成员（限一个），不要则删除本行
};

/***************************************************************************
  函数名称：
  功    能：输入10个学生的信息
  输入参数：
  返 回 值：
  说    明：不允许出现宏定义N
***************************************************************************/
void input(struct student* stu, int num)
{
	/* 除这两个整型变量外，本函数不再允许定义任何形式的变量
		 如果不用，允许删除，但不得增加或替换为其它形式的变量
		包括for(int i=0; )形式的新变量定义同样禁止 */
	int i, j;
	for (i = 0; i < 10; i++) {
		cout << "请输入第 " << i+1 << "个学生的信息 : ";
		cin >> stu[i].no;
		cin >> stu[i].name;
		for (j = 0; j < 3; j++) {
			cin >> stu[i].score[j].value;
			cin >> stu[i].score[j].weight;
		}
	}
	/* 函数的实现部分 */
}

/***************************************************************************
  函数名称：
  功    能：输出10个学生的基本信息
  输入参数：
  返 回 值：
  说    明：不允许出现宏定义N
***************************************************************************/
void output_base(struct student* stu, int num)
{
	/* 除这两个指针变量外，本函数不再允许定义任何形式的变量
		 如果不用，允许删除，但不得增加或替换为其它形式的变量
		包括for(int i=0; )形式的新变量定义同样禁止 */
	struct student* ps;
	struct course* pc;
	cout << "10个学生的成绩为" << endl;
	cout << "序号 学号    姓名     成绩1 权重1 成绩2 权重2 成绩3 权重3 加权平均成绩" << endl;
	cout << "======================================================================" << endl;
	for (ps = stu; ps - stu < num; ps++) {//一开始为student结构体的首地址
		cout << setw(4) << setiosflags(ios::left) << ps - stu + 1 << " ";//序号
		cout << setw(7) << ps->no << " ";
		cout << setw(8) << ps->name << " ";
		ps->fen = 0;
		for (pc = ps->score; pc - ps->score < 3; pc++) {//一开始为student结构体中的score结构体的首地址
			cout << setw(5) << pc->value << " ";
			cout << setw(5) << pc->weight << " ";
			ps->fen += (pc->value * pc->weight);
		}
		pc = ps->score;

		ps->fen /= (pc->weight + (pc+1)->weight + (pc+2)->weight);
		cout << setw(5) << ps->fen;
		cout << endl;

	}
	/* 函数的实现部分，不允许任何形式的[]出现 */
}

/***************************************************************************
  函数名称：
  功    能：输出绩点最高的学生（可能有并列）
  输入参数：
  返 回 值：
  说    明：不允许出现宏定义N
***************************************************************************/
void output_max(struct student* stu, int num)
{
	/* 本函数中允许定义各种类型的简单变量，但不允许定义数组 */
	cout << "成绩最高的学生为" << endl;
	cout << "序号 学号    姓名     成绩1 权重1 成绩2 权重2 成绩3 权重3 加权平均成绩" << endl;
	cout << "======================================================================" << endl;

	int a = 0, c = 0, d, e, f = 0;
	double y = 0, x = 0;
	for (d = 0; d < num; d++) {
		x = (stu[d].score[0].value * stu[d].score[0].weight + stu[d].score[1].value * stu[d].score[1].weight + stu[d].score[2].value * stu[d].score[2].weight) / (stu[d].score[0].weight + stu[d].score[1].weight + stu[d].score[2].weight) + 0.001;
		for (e = 0; e < num; e++) {
			y = (stu[e].score[0].value * stu[e].score[0].weight + stu[e].score[1].value * stu[e].score[1].weight + stu[e].score[2].value * stu[e].score[2].weight) / (stu[e].score[0].weight + stu[e].score[1].weight + stu[e].score[2].weight) + 0.001;
			if (y > x)
				break;
		}
		if (e == num) {
			a = d + 1;
			break;
		}
	}
	e = a - 1;
	cout << setiosflags(ios::left)<< setw(4) << a;
	cout << setw(7) << stu[e].no;
	cout << setw(8) << stu[e].name;
	cout << setw(5) << stu[e].score[0].value;
	cout << setw(5) << stu[e].score[0].weight;
	cout << setw(5) << stu[e].score[1].value;
	cout << setw(5) << stu[e].score[1].weight;
	cout << setw(5) << stu[e].score[2].value;
	cout << setw(5) << stu[e].score[2].weight;
	cout << setprecision(2) << x << endl;
	for (d = a; d < num; d++) {
		x = (stu[d].score[0].value * stu[d].score[0].weight + stu[d].score[1].value * stu[d].score[1].weight + stu[d].score[2].value * stu[d].score[2].weight) / (stu[d].score[0].weight + stu[d].score[1].weight + stu[d].score[2].weight) + 0.001;
		y = (stu[e].score[0].value * stu[e].score[0].weight + stu[e].score[1].value * stu[e].score[1].weight + stu[e].score[2].value * stu[e].score[2].weight) / (stu[e].score[0].weight + stu[e].score[1].weight + stu[e].score[2].weight) + 0.001;
		if (x == y)
			f = d;
		if (f > 0) {
			cout << setw(4) << f + 1;
			cout << setw(7) << stu[f].no;
			cout << setw(8) << stu[f].name;
			cout << setw(5) << stu[f].score[0].value;
			cout << setw(5) << stu[f].score[0].weight;
			cout << setw(5) << stu[f].score[1].value;
			cout << setw(5) << stu[f].score[1].weight;
			cout << setw(5) << stu[f].score[2].value;
			cout << setw(5) << stu[f].score[2].weight;
			cout << setprecision(2) << x << endl;
		}
		f = 0;
	}
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
	struct student stu[N];

	input(stu, 10);		//输入10个学生的信息
	output_base(stu, 10);	//输出10个学生的基本信息
	output_max(stu, 10);	//输出最高（可能有多个）

	return 0;
}

/*
测试数据，复制到cmd即可（测试时，不限于这一组）

2052708 章政研 76.5 4 82 5 52 2
2053177 官学博 63 4 49 1 87 6
2054176 王轶君 56 3 76 4 69 5
2051973 韩嘉睿 44.5 2 83.5 4 87 6
2053641 韩宇轩 91 4 43.5 1 66 3
2053385 高逸轩 79 6 85.5 3 62 2
2052931 刘一铭 86 3 63 3 77.5 4
2052312 许志康 49.5 3 86 6 93.5 3
2054363 马浩程 68 2 74.5 3 60 5
2053287 陈晗舸 73 3 62 2 85 5

*/
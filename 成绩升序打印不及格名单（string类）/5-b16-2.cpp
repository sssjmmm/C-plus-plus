/* 2151299 信16 苏家铭*/
#include<iostream>
#include<cstring>
using namespace std;
#define number 10

void input(string xuehao[number], string xingming[number], int grade[number]) {
	int i;
	for (i = 0; i < number; i++) {
		cout<<"请输入第"<<i+1<<"个人的学号、姓名、成绩"<<endl;
		cin >> xuehao[i]>>xingming[i]>>grade[i];
	}
}
void order_up_grade(string xuehao[number], string xingming[number], int grade[number]) {
	int i, j, tempx;
	string temp;
	for (i = 0; i < number - 1; i++) {
		for (j = 0; j < number - (i + 1); j++) {
			if (grade[j]>grade[j+1]) {
				temp=xuehao[j];
				xuehao[j]=xuehao[j + 1];
				xuehao[j + 1]=temp;

				temp=xingming[j];
				xingming[j]=xingming[j + 1];
				xingming[j + 1]=temp;

				tempx = grade[j];
				grade[j] = grade[j + 1];
				grade[j + 1] = tempx;
			}
		}
	}
}
void output(string xuehao[number], string xingming[number], int grade[number]) {
	cout << endl << "不及格名单(成绩升序):" << endl;
	int i;
	for (i = 0; i < number; i++) {
		if (grade[i] < 60) {
			cout << xingming[i] <<" "<< xuehao[i] <<" "<< grade[i] << endl;
		}
	}
}
int main() {
	string xuehao[number], xingming[number];
	int grade[number];
	input(xuehao, xingming, grade);
	order_up_grade(xuehao, xingming, grade);
	output(xuehao, xingming, grade);
	return 0;
}
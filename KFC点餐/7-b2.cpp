/*2151299 苏家铭 信16*/
#include <cstdio> 
#include <iomanip>
#include <conio.h>
#include <iostream>
using namespace std;

int jishuqi(char a[], char ch, int len);
int jishuqi2(const char a[], char ch, int len);
struct KFC {
	const char zimu;
	const char name[20];
	double pay;
};
struct SPECIAL {
	const char mix[27];
	const char name[30];
	double pay2;
};
const struct KFC list[] = {
	{'A', "田园鸡腿堡",         18.5},
	{'B', "板烧鸡腿堡",         18.5},
	{'C', "新奥尔良烤鸡腿堡",   19},
	{'D', "老北京鸡肉卷",       17},
	{'E', "川辣嫩牛卷",         19.5},
	{'F', "深海鳕鱼堡",         18.5},
	{'G', "吮指原味鸡(1块)",    11.5},
	{'H', "芝芝肉酥热辣脆皮鸡", 12.5},
	{'I', "新奥尔良烤翅(2块)",  12.5},
	{'J', "骨肉相连",         11.5},
	{'K', "香辣鸡翅(2块)",      12.0},
	{'L', "黄金手枪鸡腿(2块)",12.5},
	{'M', "鲜蔬色拉",           13},
	{'N', "薯条(小)",           9},
	{'O', "薯条(中)",           12},
	{'P', "薯条(大)",           14},
	{'Q', "芙蓉蔬荟汤",         9},
	{'R', "原味花筒冰激凌",     6},
	{'S', "醇香土豆泥",         7},
	{'T', "苹果派",         9.0},
	{'U', "蛋挞",           8.0},
	{'V', "可口可乐(小)",       7.0},
	{'W', "可口可乐(中)",       9.5},
	{'X', "可口可乐(大)",       11.5},
	{'Y', "果汁",       12.5},
	{'Z', "纯纯玉米饮",         11.5},
	{'\0', NULL,                0}
};

const struct SPECIAL special[] = {
	//	{"ANV", "香辣鸡腿堡工作日午餐",  24}, //如果有需要，放开此项，注释掉下一行的“BMV”优惠，观察优惠菜单是否发生了变化
		{"BMV", "劲脆鸡腿堡超值套餐",    26},
		{"ABCGGIIKKOUWWW", "超值全家桶", 115},
		{"KIIRRJUWW", "缤纷小吃桶",      65},
		{"JJ","劲爆鸡米花(2份小)",       12.5},
		{NULL, NULL, 0}
};
void menu() {
	cout << "=============================================================" << endl;
	cout << "                      KFC 2021秋季菜单" << endl;
	cout << "=============================================================" << endl;
	cout << setiosflags(ios::left);
	for (int i = 0; i < 26; i+=2) {
		cout << " " << list[i].zimu << " " << setw(20) << list[i].name << setw(5) << list[i].pay ;
		cout << " | ";
		cout << " " << list[i+1].zimu << " " << setw(20) << list[i+1].name << setw(5) << list[i+1].pay<<endl ;
	}
	cout << endl;
	cout << "【优惠信息】：" << endl;
	for (int i = 0; special[i].pay2 != 0; i++) {
		cout << special[i].name<<"=" ;
		for (int j = 0; j < 26; j++) {
			if ((jishuqi2(special[i].mix, list[j].zimu, strlen(special[i].mix)) >= 2)) {
				cout << list[j].name << "*" << (jishuqi2(special[i].mix, list[j].zimu, strlen(special[i].mix))) << " ";
			}
			else if ((jishuqi2(special[i].mix, list[j].zimu, strlen(special[i].mix))) == 1) {
				cout << list[j].name << " ";
			}
		}
		cout << "只需" << special[i].pay2 << "元！" <<endl;
	}
	cout << endl;
	cout << "【输入规则说明】：" << endl;
	cout << "ANV=香辣鸡腿堡+薯条(小)+百事可乐(小) / akaak=香辣鸡腿堡*3+香辣鸡翅*2" << endl;
	cout << "字母不分大小写，不限顺序，单独输入0则退出程序" << endl << endl;;
	cout << "请点单:";
}
bool input_order (char a[]) {
	char ch;
	cin.getline(a,100);
	for (int i = 0; a[i]!=0; i++) {
		if (a[i] >= 97 && a[i] <= 122)
			a[i] -= 32;
		else if(!(a[i] >= 97 && a[i] <= 122)&&!(a[i] >= 65 && a[i] <= 97)) {
			if (!(a[1] == '\0' && a[0] == '0')) {
				cout << "输入错误，按任意键继续." << endl;
				ch = _getch();
			}
			return false;
		}
	}
	return true;
}
void count(char a[],double *sum,int len) {
	for (int i = 0; i < len; i++) {
		if (a[i] >= 65 && a[i] <= 97) {
			for (int j = 0; j < 26; j++) {
				if (a[i] == list[j].zimu) {
					*sum = *sum + list[j].pay;
					a[i] = 0;
					break;
				}
			}
		}
	}
}

void count0(char a[], double* sum, int len) {
	char temp[100] = { -1 };
	for (int i = 0; i < 100; i++) {
		temp[i] = -1;
	}
	int lenth = 0;
	for (int i = 0; special[i].pay2!=0;i++) {//寻找相同字符，mix
		bool P=true;
		while (P) {
			for (int j = 0; special[i].mix[j] != '\0'; j++) {//mix中的英文字母

				for (int k = 0; k < len; k++) {//a[k]
					if (a[k] == special[i].mix[j]) {
						lenth++;
						temp[k] = a[k];//a置i
						a[k] = i;
						break;
					}
				}
			}
			/*111111111111111111111111111111*/
			if (lenth == strlen(special[i].mix)) {//如果这个优惠真的存在就
				*sum = *sum + special[i].pay2;//sum要加，还要把优惠方案的字母置1
			}//置1结束
			else if (lenth != strlen(special[i].mix)) {//不是所要找的优惠，就把字母还回去
				for (int m = 0; m < 100; m++) {
					if (a[m] == i) {
						a[m] = temp[m];
					}
				}
			}
			/*111111111111111111111111111111*/
			lenth = 0;
			//循环看看这个菜单还有没有二次优惠
			char b[100];
			for (int i = 0; i < len; i++) {
				b[i] = a[i];
			}
			for (int j = 0; special[i].mix[j] != '\0'; j++) {//mix中的英文字母

				for (int k = 0; k < len; k++) {//a[k]
					if (b[k] == special[i].mix[j]) {
						lenth++;
						b[k] = 0;
						break;
					}
				}
			}
			/*111111111111111111111111111111*/
			if (lenth != strlen(special[i].mix)) {//如果这个优惠真的存在就
				lenth = 0;
				break;
			}
			lenth = 0;

		}
		
	}

}
void output1(char a[], int len) {
	cout << "您的点餐=";
	for (int j = 0; j < 26; j++) {
		if ((jishuqi(a, list[j].zimu, len)) >= 2) {
			cout << list[j].name << "*" << (jishuqi(a, list[j].zimu, len))<<" ";
		}
		else if ((jishuqi(a, list[j].zimu, len)) == 1) {
			cout << list[j].name<<" ";
		}
	}
	cout << endl;
}
int jishuqi(char a[],char ch, int len) {
	int count = 0;
	for (int i = 0; i < len; i++) {
		if (a[i] == ch) {
			count++;
		}
	}
	return count;
}
int jishuqi2(const char a[], char ch, int len) {
	int count = 0;
	for (int i = 0; i < len; i++) {
		if (a[i] == ch) {
			count++;
		}
	}
	return count;
}
void wait_for_enter(const char* const prompt = NULL)
{
	if ((prompt == NULL) || (strlen(prompt) == 0)) //思考一下，||的左右两个条件能否互换
		cout << endl << "按回车键继续";
	else
		cout << endl << prompt << "，按回车键继续";

	while (_getch() != '\r')
		;
	cout << endl << endl;
}
int main() {
	while (1) {
		bool T;
		double sum = 0;
		char order[100] = {0};
		int len = 0;
		system("cls");
		system("mode con cols=120 lines=35");//35行 120列
		menu();
		T=input_order(order);
		len = strlen(order);
		if (len == 1 && order[0] == '0')
			return 0;
		if (T) {
			output1(order, len);
			//ok
			count0(order, &sum, len);//优惠方案完了
			count(order, &sum, len);
			cout << "共计：" << sum << "元" << endl;
			wait_for_enter();
		}
	}
	return 0;
}
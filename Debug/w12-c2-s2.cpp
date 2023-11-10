/* 2151299 信16 苏家铭 */
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int hang=0;
	cout << "请输入要打印的行数[3..13]" << endl;
	cin >> hang;
    cout << "--------------------------------------------------------------------------------" << endl;
    for (int k=0; k < 8; k++) {
        cout << setiosflags(ios::left) << setw(10)<<k;
    }
    cout << endl;
    for (int k = 0; k < 8; k++) {
        cout << "0123456789";
    }
    cout << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    
    int sanjiao[13][13] = {0};

    int i,j;
    for (i = 0; i < hang; i++){
        sanjiao[i][0] = 1;
    }
    for (i = 1; i < hang; i++){
        for (j = 1; j <= i; j++){
            sanjiao[i][j] = sanjiao[i - 1][j - 1] + sanjiao[i - 1][j];
        }
    }
    
    for (i = 0; i < hang; i++){
        for (j = 0; j < i+1; j++)
            cout <<resetiosflags(ios::left)<< setw(6) << sanjiao[i][j];
        cout << endl;
    }
    cout << "--------------------------------------------------------------------------------" << endl;
    for (int k = 0; k < 8; k++) {
        cout << "0123456789";
    }
    cout << endl;
    for (int k = 0; k < 8; k++) {
        cout << setiosflags(ios::left) <<setw(10) << k;
    }
    cout << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    cout<<endl;

   
	return 0;
}

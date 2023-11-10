/* 信16 2151299 苏家铭 */
#include <iostream>
#include <string>
//可按需增加需要的头文件
using namespace std;

const char chnstr[] = "零壹贰叁肆伍陆柒捌玖"; /* 所有输出大写 "零" ~ "玖" 的地方，只允许从这个数组中取值 */
string result;  /* 除result外，不再允许定义任何形式的全局变量 */

/* --允许添加需要的函数 --*/
void daxie(int num, int flag_of_zero)
{
    /* 不允许对本函数做任何修改 */
    switch (num) {
    case 0:
        if (flag_of_zero) 	//此标记什么意思请自行思考
            result = result + chnstr[0]+ chnstr[1];
        break;
    case 1:
        result = result + chnstr[2] + chnstr[3];
        break;
    case 2:
        result = result + chnstr[4] + chnstr[5];
        break;
    case 3:
        result = result + chnstr[6] + chnstr[7];
        break;
    case 4:
        result = result + chnstr[8] + chnstr[9];
        break;
    case 5:
        result = result + chnstr[10] + chnstr[11];
        break;
    case 6:
        result = result + chnstr[12] + chnstr[13];
        break;
    case 7:
        result = result + chnstr[14] + chnstr[15];
        break;
    case 8:
        result = result + chnstr[16] + chnstr[17];
        break;
    case 9:
        result = result + chnstr[18] + chnstr[19];
        break;
    default:
        break;
    }
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
    /* --允许添加需要的内容 --*/
        /* --允许添加需要的内容 --*/
    double a, o, h, sy, y, qw, bw, sw, w, q, b, s, g, j, f;
    char shi[] = { "拾" };
    char bai[] = { "佰" };
    char qian[] = { "仟" };
    char wan[] = { "万" };
    char yi[] = { "亿" };
    char yuan[] = { "圆" };
    char jiao[] = { "角" };
    char fen[] = { "分" };
    char zheng[] = { "整" };
    cout << "请输入[0-100亿)之间的数字:" << endl;
    cin >> a;
    cout << "大写结果是:" << endl;
    sy = int(a / 1000000000);
    y = int((a - sy * 1000000000) / 100000000);
    qw = int((a - sy * 1000000000 - y * 100000000) / 10000000);
    bw = int((a - sy * 1000000000 - y * 100000000 - qw * 10000000) / 1000000);
    sw = int((a - sy * 1000000000 - y * 100000000 - qw * 10000000 - bw * 1000000) / 100000);
    w = int((a - sy * 1000000000 - y * 100000000 - qw * 10000000 - bw * 1000000 - sw * 100000) / 10000);
    q = int((a - sy * 1000000000 - y * 100000000 - qw * 10000000 - bw * 1000000 - sw * 100000 - w * 10000) / 1000);
    b = int((a - sy * 1000000000 - y * 100000000 - qw * 10000000 - bw * 1000000 - sw * 100000 - w * 10000 - q * 1000) / 100);
    s = int((a - sy * 1000000000 - y * 100000000 - qw * 10000000 - bw * 1000000 - sw * 100000 - w * 10000 - q * 1000 - b * 100) / 10);
    g = int((a - sy * 1000000000 - y * 100000000 - qw * 10000000 - bw * 1000000 - sw * 100000 - w * 10000 - q * 1000 - b * 100 - s * 10) / 1);
    h = a - sy * 1000000000 - y * 100000000 - qw * 10000000 - bw * 1000000 - sw * 100000 - w * 10000 - q * 1000 - b * 100 - s * 10 - g * 1;
    o = h * 100.001;
    j = int(o / 10);
    f = int(o - j * 10);

    //十亿-亿
    daxie(int(sy), 0);
    if (sy != 0)
        result=result+shi;
    daxie(int(y), 0);
    if (sy != 0 || y != 0)
        result=result+yi;
    //亿结束，万开始
    if (qw == 0 && bw == 0 && sw == 0 && w != 0) { //000* 1
        if (sy != 0 || y != 0)
            daxie(int(qw), 1);
        daxie(int(w), 0);
        result=result+wan;
    }
    if (qw == 0 && bw == 0 && sw != 0 && w == 0) {  //00*0 2
        if (sy != 0 || y != 0)
            daxie(int(qw), 1);
        daxie(int(sw), 0);
        result=result+shi; 
        result=result+wan;
    }
    if (qw == 0 && bw != 0 && sw == 0 && w == 0) {  //0*00 3 
        if (sy != 0 || y != 0)
            daxie(int(qw), 1);
        daxie(int(bw), 0);
        result=result+bai;
        result=result+wan;
    }
    if (qw != 0 && bw == 0 && sw == 0 && w == 0) {  //*000 4 
        daxie(int(qw), 0);
        result=result+qian;
        result=result+wan;
    }
    if (qw == 0 && bw == 0 && sw != 0 && w != 0) {  //00** 5 
        if (sy != 0 || y != 0)
            daxie(int(qw), 1);
        daxie(int(sw), 0);
        result=result+shi;
        daxie(int(w), 0);
        result=result+wan;
    }
    if (qw == 0 && bw != 0 && sw == 0 && w != 0) {  //0*0* 6 
        if (sy != 0 || y != 0)
            daxie(int(qw), 1);
        daxie(int(bw), 0);
        result=result+bai;
        daxie(int(sw), 1);
        daxie(int(w), 0);
        result=result+wan;

    }
    if (qw != 0 && bw == 0 && sw == 0 && w != 0) {  //*00* 7 
        daxie(int(qw), 0);
        result=result+qian;
        daxie(int(bw), 1);
        daxie(int(w), 0);
        result=result+wan;
    }
    if (qw == 0 && bw != 0 && sw != 0 && w == 0) {  //0**0 8 
        if (sy != 0 || y != 0)
            daxie(int(qw), 1);
        daxie(int(bw), 0);
        result=result+bai;
        daxie(int(sw), 0);
        result=result+shi; 
        result=result+wan;
    }
    if (qw != 0 && bw == 0 && sw != 0 && w == 0) {  //*0*0 9 
        daxie(int(qw), 0);
        result=result+qian;
        daxie(int(bw), 1);
        daxie(int(sw), 0);
        result=result+shi;
        result=result+wan;

    }
    if (qw != 0 && bw != 0 && sw == 0 && w == 0) {  //**00 10
        daxie(int(qw), 0);
        result=result+qian;
        daxie(int(bw), 0);
        result=result+bai;
        result=result+wan;
    }
    if (qw != 0 && bw != 0 && sw != 0 && w == 0) {  //***0 11
        daxie(int(qw), 0);
        result=result+qian;
        daxie(int(bw), 0);
        result=result+bai;
        daxie(int(sw), 0);
        result=result+shi;
        result=result+wan;
    }
    if (qw != 0 && bw != 0 && sw == 0 && w != 0) {  //**0* 12
        daxie(int(qw), 0);
        result=result+qian;
        daxie(int(bw), 0);
        result=result+bai;
        daxie(int(sw), 1);
        daxie(int(w), 0);
        result=result+wan;
    }
    if (qw != 0 && bw == 0 && sw != 0 && w != 0) {  //*0** 13
        daxie(int(qw), 0);
        result=result+qian;
        daxie(int(bw), 1);
        daxie(int(sw), 0);
        result=result+shi;
        daxie(int(w), 0);
        result=result+wan;
    }
    if (qw == 0 && bw != 0 && sw != 0 && w != 0) {  //0*** 14
        if (sy != 0 || y != 0)
            daxie(int(qw), 1);
        daxie(int(bw), 0);
        result=result+bai;
        daxie(int(sw), 0);
        result=result+shi;
        daxie(int(w), 0);
        result=result+wan;
    }
    if (qw != 0 && bw != 0 && sw != 0 && w != 0) {  //**** 15
        daxie(int(qw), 0);
        result=result+qian;
        daxie(int(bw), 0);
        result=result+bai;
        daxie(int(sw), 0);
        result=result+shi;
        daxie(int(w), 0);
        result=result+wan;
    }
    //万结束，千开始
    if (q == 0 && b == 0 && s == 0 && g != 0) { //000* 1
        if (sy != 0 || y != 0 || qw != 0 || sw != 0 || bw != 0 || w != 0)
            daxie(int(q), 1);
        daxie(int(g), 0);
    }
    if (q == 0 && b == 0 && s != 0 && g == 0) {  //00*0 2
        if (sy != 0 || y != 0 || qw != 0 || sw != 0 || bw != 0 || w != 0)
            daxie(int(q), 1);
        daxie(int(s), 0);
        result=result+shi;
    }
    if (q == 0 && b != 0 && s == 0 && g == 0) {  //0*00 3 
        if (sy != 0 || y != 0 || qw != 0 || sw != 0 || bw != 0 || w != 0)
            daxie(int(q), 1);
        daxie(int(b), 0);
        result=result+bai;
    }
    if (q != 0 && b == 0 && s == 0 && g == 0) {  //*000 4 
        daxie(int(q), 0);
        result=result+qian;
    }
    if (q == 0 && b == 0 && s != 0 && g != 0) {  //00** 5 
        if (sy != 0 || y != 0 || qw != 0 || sw != 0 || bw != 0 || w != 0)
            daxie(int(q), 1);
        daxie(int(s), 0);
        result=result+shi;
        daxie(int(g), 0);
    }
    if (q == 0 && b != 0 && s == 0 && g != 0) {  //0*0* 6 
        if (sy != 0 || y != 0 || qw != 0 || sw != 0 || bw != 0 || w != 0)
            daxie(int(q), 1);
        daxie(int(b), 0);
        result=result+bai;
        daxie(int(s), 1);
        daxie(int(g), 0);
    }
    if (q != 0 && b == 0 && s == 0 && g != 0) {  //*00* 7 
        daxie(int(q), 0);
        result=result+qian;
        daxie(int(b), 1);
        daxie(int(g), 0);
    }
    if (q == 0 && b != 0 && s != 0 && g == 0) {  //0**0 8 
        if (sy != 0 || y != 0 || qw != 0 || sw != 0 || bw != 0 || w != 0)
            daxie(int(q), 1);
        daxie(int(b), 0);
        result=result+bai;
        daxie(int(s), 0);
        result=result+shi;
    }
    if (q != 0 && b == 0 && s != 0 && g == 0) {  //*0*0 9 
        daxie(int(q), 0);
        result=result+qian;
        daxie(int(b), 1);
        daxie(int(s), 0);
        result=result+shi;

    }
    if (q != 0 && b != 0 && s == 0 && g == 0) {  //**00 10
        daxie(int(q), 0);
        result=result+qian;
        daxie(int(b), 0);
        result=result+bai;
    }
    if (q != 0 && b != 0 && s != 0 && g == 0) {  //***0 11
        daxie(int(q), 0);
        result=result+qian;
        daxie(int(b), 0);
        result=result+bai;
        daxie(int(s), 0);
        result=result+shi;
    }
    if (q != 0 && b != 0 && s == 0 && g != 0) {  //**0* 12
        daxie(int(q), 0);
        result=result+qian;
        daxie(int(b), 0);
        result=result+bai;
        daxie(int(s), 1);
        daxie(int(g), 0);
    }
    if (q != 0 && b == 0 && s != 0 && g != 0) {  //*0** 13
        daxie(int(q), 0);
        result=result+qian;
        daxie(int(b), 1);
        daxie(int(s), 0);
        result=result+shi;
        daxie(int(g), 0);
    }
    if (q == 0 && b != 0 && s != 0 && g != 0) {  //0*** 14
        if (sy != 0 || y != 0 || qw != 0 || sw != 0 || bw != 0 || w != 0)
            daxie(int(q), 1);
        daxie(int(b), 0);
        result=result+bai;
        daxie(int(s), 0);
        result=result+shi;
        daxie(int(g), 0);
    }
    if (q != 0 && b != 0 && s != 0 && g != 0) {  //**** 15
        daxie(int(q), 0);
        result=result+qian;
        daxie(int(b), 0);
        result=result+bai;
        daxie(int(s), 0);
        result=result+shi;
        daxie(int(g), 0);
    }
    if (!sy && !y && !qw && !bw && !w && !sw && !q && !b && !s && !g && !j && !f) {
        daxie(int(g), 1);
        result=result+yuan;
    }
    if (sy != 0 || y != 0 || qw != 0 || sw != 0 || bw != 0 || w != 0 || q != 0 || b != 0 || s != 0 || g != 0)
        result=result+yuan;
    //  千—圆结束，角分开始
    if ((sy || y || qw || bw || w || sw || q || b || s || g) && !j && f)
        daxie(int(j), 1);
    if (!j && !f)
        result=result+zheng;
    if (!j && f) {
        daxie(int(f), 0);
        result=result+fen;
    }
    if (j && !f) {
        daxie(int(j), 0);
        result=result+jiao; 
        result=result+zheng;
    }
    if (j && f) {
        daxie(int(j), 0);
        result=result+jiao;
        daxie(int(f), 0);
        result=result+fen;
    }

    cout << result << endl;  /* 转换得到的大写结果，只允许用本语句输出，之前不允许任何形式的部分输出 */
    return 0;
}
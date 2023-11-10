/* 2151299 苏家铭 信16 */
#include <iostream>
using namespace std;

/* 可根据需要添加相应的内容 */

/***************************************************************************
  函数名称：
  功    能：输出大写的0~9
  输入参数：
  返 回 值：
  说    明：除本函数外，不允许任何函数中输出“零”-“玖”!!!!!!
***************************************************************************/
void daxie(int num, int flag_of_zero)
{
	/* 不允许对本函数做任何修改 */
	switch (num) {
		case 0:
			if (flag_of_zero)	//此标记什么意思请自行思考
				cout << "零";
			break;
		case 1:
			cout << "壹";
			break;
		case 2:
			cout << "贰";
			break;
		case 3:
			cout << "叁";
			break;
		case 4:
			cout << "肆";
			break;
		case 5:
			cout << "伍";
			break;
		case 6:
			cout << "陆";
			break;
		case 7:
			cout << "柒";
			break;
		case 8:
			cout << "捌";
			break;
		case 9:
			cout << "玖";
			break;
		default:
			cout << "error";
			break;
	}
}

/* 可根据需要自定义其它函数(也可以不定义) */

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
	double a, o, h,sy, y, qw, bw, sw, w, q, b, s, g, j, f;

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
	if(sy!=0)
	    cout << "拾";
	daxie(int(y),0);
	if(sy!=0||y!=0)
	    cout << "亿";
	//亿结束，万开始
	if (qw == 0 && bw == 0 && sw == 0 && w != 0) { //000* 1
		if (sy != 0 || y != 0)
			daxie(int(qw), 1);
		daxie(int(w), 0);
        cout << "万";
	}
    if (qw == 0 && bw == 0 && sw != 0 && w == 0) {  //00*0 2
        if (sy != 0 || y != 0)
            daxie(int(qw), 1);
        daxie(int(sw), 0);
        cout << "拾万";
    }
    if (qw == 0 && bw != 0 && sw == 0 && w == 0) {  //0*00 3 
        if (sy != 0 || y != 0)
            daxie(int(qw), 1);
        daxie(int(bw), 0);
        cout << "佰万";
    }
    if (qw != 0 && bw == 0 && sw == 0 && w == 0) {  //*000 4 
        daxie(int(qw), 0);
        cout << "仟万";
    }
    if (qw == 0 && bw == 0 && sw != 0 && w != 0) {  //00** 5 
        if (sy != 0 || y != 0)
            daxie(int(qw), 1);
        daxie(int(sw), 0);
        cout << "拾";
        daxie(int(w), 0);
        cout << "万";
    }
    if (qw == 0 && bw != 0 && sw == 0 && w != 0) {  //0*0* 6 
        if (sy != 0 || y != 0)
            daxie(int(qw), 1);
        daxie(int(bw), 0);
        cout << "佰";
        daxie(int(sw), 1);
        daxie(int(w), 0);
        cout << "万";

    }
    if (qw != 0 && bw == 0 && sw == 0 && w != 0) {  //*00* 7 
        daxie(int(qw), 0);
        cout << "仟";
        daxie(int(bw), 1);
        daxie(int(w), 0);
        cout << "万";
    }
    if (qw == 0 && bw != 0 && sw != 0 && w == 0) {  //0**0 8 
        if (sy != 0 || y != 0)
            daxie(int(qw), 1);
        daxie(int(bw), 0);
        cout << "佰";
        daxie(int(sw), 0);
        cout << "拾万";
    }
    if (qw != 0 && bw == 0 && sw != 0 && w == 0) {  //*0*0 9 
        daxie(int(qw), 0);
        cout << "仟";
        daxie(int(bw), 1);
        daxie(int(sw), 0);
        cout << "拾万";

    }
    if (qw != 0 && bw != 0 && sw == 0 && w == 0) {  //**00 10
        daxie(int(qw), 0);
        cout << "仟";
        daxie(int(bw), 0);
        cout << "佰万";
    }
    if (qw != 0 && bw != 0 && sw != 0 && w == 0) {  //***0 11
        daxie(int(qw), 0);
        cout << "仟";
        daxie(int(bw), 0);
        cout << "佰";
        daxie(int(sw), 0);
        cout << "拾万";
    }
    if (qw != 0 && bw != 0 && sw == 0 && w != 0) {  //**0* 12
        daxie(int(qw), 0);
        cout << "仟";
        daxie(int(bw), 0);
        cout << "佰";
        daxie(int(sw), 1);
        daxie(int(w), 0);
        cout << "万";
    }
    if (qw != 0 && bw == 0 && sw != 0 && w != 0) {  //*0** 13
        daxie(int(qw), 0);
        cout << "仟";
        daxie(int(bw), 1);
        daxie(int(sw), 0);
        cout << "拾";
        daxie(int(w), 0);
        cout << "万";
    }
    if (qw == 0 && bw != 0 && sw != 0 && w != 0) {  //0*** 14
        if (sy != 0 || y != 0)
            daxie(int(qw), 1);
        daxie(int(bw), 0);
        cout << "佰";
        daxie(int(sw), 0);
        cout << "拾";
        daxie(int(w), 0);
        cout << "万";
    }
    if (qw != 0 && bw != 0 && sw != 0 && w != 0) {  //**** 15
        daxie(int(qw), 0);
        cout << "仟";
        daxie(int(bw), 0);
        cout << "佰";
        daxie(int(sw), 0);
        cout << "拾";
        daxie(int(w), 0);
        cout << "万";
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
        cout << "拾";
    }
    if (q == 0 && b != 0 && s == 0 && g == 0) {  //0*00 3 
        if (sy != 0 || y != 0 || qw != 0 || sw != 0 || bw != 0 || w != 0)
            daxie(int(q), 1);
        daxie(int(b), 0);
        cout << "佰";
    }
    if (q != 0 && b == 0 && s == 0 && g == 0) {  //*000 4 
        daxie(int(q), 0);
        cout << "仟";
    }
    if (q == 0 && b == 0 && s != 0 && g != 0) {  //00** 5 
        if (sy != 0 || y != 0 || qw != 0 || sw != 0 || bw != 0 || w != 0)
            daxie(int(q), 1);
        daxie(int(s), 0);
        cout << "拾";
        daxie(int(g), 0);
    }
    if (q == 0 && b != 0 && s == 0 && g != 0) {  //0*0* 6 
        if (sy != 0 || y != 0 || qw != 0 || sw != 0 || bw != 0 || w != 0)
            daxie(int(q), 1);
        daxie(int(b), 0);
        cout << "佰";
        daxie(int(s), 1);
        daxie(int(g), 0);
    }
    if (q != 0 && b == 0 && s == 0 && g != 0) {  //*00* 7 
        daxie(int(q), 0);
        cout << "仟";
        daxie(int(b), 1);
        daxie(int(g), 0);
    }
    if (q == 0 && b != 0 && s != 0 && g == 0) {  //0**0 8 
        if (sy != 0 || y != 0 || qw != 0 || sw != 0 || bw != 0 || w != 0)
            daxie(int(q), 1);
        daxie(int(b), 0);
        cout << "佰";
        daxie(int(s), 0);
        cout << "拾";
    }
    if (q != 0 && b == 0 && s != 0 && g == 0) {  //*0*0 9 
        daxie(int(q), 0);
        cout << "仟";
        daxie(int(b), 1);
        daxie(int(s), 0);
        cout << "拾";

    }
    if (q != 0 && b != 0 && s == 0 && g == 0) {  //**00 10
        daxie(int(q), 0);
        cout << "仟";
        daxie(int(b), 0);
        cout << "佰";
    }
    if (q != 0 && b != 0 && s != 0 && g == 0) {  //***0 11
        daxie(int(q), 0);
        cout << "仟";
        daxie(int(b), 0);
        cout << "佰";
        daxie(int(s), 0);
        cout << "拾";
    }
    if (q != 0 && b != 0 && s == 0 && g != 0) {  //**0* 12
        daxie(int(q), 0);
        cout << "仟";
        daxie(int(b), 0);
        cout << "佰";
        daxie(int(s), 1);
        daxie(int(g), 0);
    }
    if (q != 0 && b == 0 && s != 0 && g != 0) {  //*0** 13
        daxie(int(q), 0);
        cout << "仟";
        daxie(int(b), 1);
        daxie(int(s), 0);
        cout << "拾";
        daxie(int(g), 0);
    }
    if (q == 0 && b != 0 && s != 0 && g != 0) {  //0*** 14
        if (sy != 0 || y != 0 || qw != 0 || sw != 0 || bw != 0 || w != 0)
            daxie(int(q), 1);
        daxie(int(b), 0);
        cout << "佰";
        daxie(int(s), 0);
        cout << "拾";
        daxie(int(g), 0);
    }
    if (q != 0 && b != 0 && s != 0 && g != 0) {  //**** 15
        daxie(int(q), 0);
        cout << "仟";
        daxie(int(b), 0);
        cout << "佰";
        daxie(int(s), 0);
        cout << "拾";
        daxie(int(g), 0);
    }
    if (!sy && !y && !qw && !bw && !w && !sw && !q && !b && !s && !g && !j && !f) {
        daxie(int(g), 1);
        cout << "圆";
    }
    if (sy != 0 || y != 0 || qw != 0 || sw != 0 || bw != 0 || w != 0 || q != 0 || b != 0 || s != 0 || g != 0) 
        cout << "圆";
    //  千—圆结束，角分开始
    if ((sy || y || qw || bw || w || sw || q || b || s || g) && !j && f)
        daxie(int(j), 1);
    if (!j && !f)
        cout << "整";
    if (!j && f) {
        daxie(int(f), 0);
        cout << "分";
    }
    if (j && !f) {
        daxie(int(j), 0);
        cout << "角整";
    }
    if (j && f) {
        daxie(int(j), 0);
        cout << "角";
        daxie(int(f), 0);
        cout << "分";
    }
    cout << endl;

	/* 按需完成 */
	return 0;
}
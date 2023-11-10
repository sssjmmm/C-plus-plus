/*2151299 ĞÅ16 ËÕ¼ÒÃú*/
#include <iostream>
using namespace std;
int main()
{
	double a, sy, y, qw, bw, sw, h, w, q, b, s, g, j, o, f;

	cout << "ÇëÊäÈë[0..100 ÒÚ)Ö®¼äµÄÊı×Ö:" << endl;
	cin >> a;
    cout << "´óĞ´½á¹ûÊÇ:" << endl;
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
	//Ê®ÒÚµ½ÒÚ£º
	if (sy == 1)
		cout << "Ò¼Ê°";
	else if (sy == 2)
		cout << "·¡Ê°";
	else if (sy == 3)
		cout << "ÈşÊ°";
	else if (sy == 4)
		cout << "ËÁÊ°";
	else if (sy == 5)
		cout << "ÎéÊ°";
	else if (sy == 6)
		cout << "Â½Ê°";
	else if (sy == 7)
		cout << "ÆâÊ°";
	else if (sy == 8)
		cout << "°ÆÊ°";
	else if (sy == 9)
		cout << "¾ÁÊ°";
	else if (sy == 0) {
		if (y == 1)
			cout << "Ò¼ÒÚ";
		else if (y == 2)
			cout << "·¡ÒÚ";
		else if (y == 3)
			cout << "ÈşÒÚ";
		else if (y == 4)
			cout << "ËÁÒÚ";
		else if (y == 5)
			cout << "ÎéÒÚ";
		else if (y == 6)
			cout << "Â½ÒÚ";
		else if (y == 7)
			cout << "ÆâÒÚ";
		else if (y == 8)
			cout << "°ÆÒÚ";
		else if (y == 9)
			cout << "¾ÁÒÚ";
	}
	if (y == 1 && sy != 0)
		cout << "Ò¼ÒÚ";
	else if (y == 2 && sy != 0)
		cout << "·¡ÒÚ";
	else if (y == 3 && sy != 0)
		cout << "ÈşÒÚ";
	else if (y == 4 && sy != 0)
		cout << "ËÁÒÚ";
	else if (y == 5 && sy != 0)
		cout << "ÎéÒÚ";
	else if (y == 6 && sy != 0)
		cout << "Â½ÒÚ";
	else if (y == 7 && sy != 0)
		cout << "ÆâÒÚ";
	else if (y == 8 && sy != 0)
		cout << "°ÆÒÚ";
	else if (y == 9 && sy != 0)
		cout << "¾ÁÒÚ";
	else if (y == 0 && sy != 0)
		cout << "ÒÚ";

	//Ê®ÒÚ-ÒÚ½áÊø£¬Íò¿ªÊ¼
    
    if (qw == 0 && bw == 0 && sw == 0 && w != 0) {  //000* 1
        if (sy != 0 || y != 0)
            cout << "Áã";
        if (w == 1)
            cout << "Ò¼";
        else if (w == 2)
            cout << "·¡";
        else if (w == 3)
            cout << "Èş";
        else if (w == 4)
            cout << "ËÁ";
        else if (w == 5)
            cout << "Îé";
        else if (w == 6)
            cout << "Â½";
        else if (w == 7)
            cout << "Æâ";
        else if (w == 8)
            cout << "°Æ";
        else if (w == 9)
            cout << "¾Á";
        cout << "Íò";
       
    }
    if (qw == 0 && bw == 0 && sw != 0 && w == 0) {  //00*0 2
        if (sy != 0 || y != 0)
            cout << "Áã";
        if (sw == 1)
            cout << "Ò¼";
        else if (sw == 2)
            cout << "·¡";
        else if (sw == 3)
            cout << "Èş";
        else if (sw == 4)
            cout << "ËÁ";
        else if (sw == 5)
            cout << "Îé";
        else if (sw == 6)
            cout << "Â½";
        else if (sw == 7)
            cout << "Æâ";
        else if (sw == 8)
            cout << "°Æ";
        else if (sw == 9)
            cout << "¾Á";
        cout << "Ê°Íò";

    }
    if (qw == 0 && bw != 0 && sw == 0 && w == 0) {  //0*00 3 
        if (sy != 0 || y != 0)
            cout << "Áã";
        if (bw == 1)
            cout << "Ò¼";
        else if (bw == 2)
            cout << "·¡";
        else if (bw == 3)
            cout << "Èş";
        else if (bw == 4)
            cout << "ËÁ";
        else if (bw == 5)
            cout << "Îé";
        else if (bw == 6)
            cout << "Â½";
        else if (bw == 7)
            cout << "Æâ";
        else if (bw == 8)
            cout << "°Æ";
        else if (bw == 9)
            cout << "¾Á";
        cout << "°ÛÍò";

    }        
    if (qw != 0 && bw == 0 && sw == 0 && w == 0) {  //*000 4 
        if (qw == 1)
            cout << "Ò¼";
        else if (qw == 2)
            cout << "·¡";
        else if (qw == 3)
            cout << "Èş";
        else if (qw == 4)
            cout << "ËÁ";
        else if (qw == 5)
            cout << "Îé";
        else if (qw == 6)
            cout << "Â½";
        else if (qw == 7)
            cout << "Æâ";
        else if (qw == 8)
            cout << "°Æ";
        else if (qw == 9)
            cout << "¾Á";
        cout << "ÇªÍò";

    }        
    if (qw == 0 && bw == 0 && sw != 0 && w != 0) {  //00** 5 
        if (sy != 0 || y != 0)
            cout << "Áã";
        if (sw == 1)
            cout << "Ò¼";
        else if (sw == 2)
            cout << "·¡";
        else if (sw == 3)
            cout << "Èş";
        else if (sw == 4)
            cout << "ËÁ";
        else if (sw == 5)
            cout << "Îé";
        else if (sw == 6)
            cout << "Â½";
        else if (sw == 7)
            cout << "Æâ";
        else if (sw == 8)
            cout << "°Æ";
        else if (sw == 9)
            cout << "¾Á";
        cout << "Ê°";

        if (w == 1)
            cout << "Ò¼";
        else if (w == 2)
            cout << "·¡";
        else if (w == 3)
            cout << "Èş";
        else if (w == 4)
            cout << "ËÁ";
        else if (w == 5)
            cout << "Îé";
        else if (w == 6)
            cout << "Â½";
        else if (w == 7)
            cout << "Æâ";
        else if (w == 8)
            cout << "°Æ";
        else if (w == 9)
            cout << "¾Á";
        cout << "Íò";

    }
    if (qw == 0 && bw != 0 && sw == 0 && w != 0) {  //0*0* 6 
        if (sy != 0 || y != 0)
            cout << "Áã";
        if (bw == 1)
            cout << "Ò¼";
        else if (bw == 2)
            cout << "·¡";
        else if (bw == 3)
            cout << "Èş";
        else if (bw == 4)
            cout << "ËÁ";
        else if (bw == 5)
            cout << "Îé";
        else if (bw == 6)
            cout << "Â½";
        else if (bw == 7)
            cout << "Æâ";
        else if (bw == 8)
            cout << "°Æ";
        else if (bw == 9)
            cout << "¾Á";
        cout << "°ÛÁã";

        if (w == 1)
            cout << "Ò¼";
        else if (w == 2)
            cout << "·¡";
        else if (w == 3)
            cout << "Èş";
        else if (w == 4)
            cout << "ËÁ";
        else if (w == 5)
            cout << "Îé";
        else if (w == 6)
            cout << "Â½";
        else if (w == 7)
            cout << "Æâ";
        else if (w == 8)
            cout << "°Æ";
        else if (w == 9)
            cout << "¾Á";
        cout << "Íò";

    }
    if (qw != 0 && bw == 0 && sw == 0 && w != 0) {  //*00* 7 

        if (qw == 1)
            cout << "Ò¼";
        else if (qw == 2)
            cout << "·¡";
        else if (qw == 3)
            cout << "Èş";
        else if (qw == 4)
            cout << "ËÁ";
        else if (qw == 5)
            cout << "Îé";
        else if (qw == 6)
            cout << "Â½";
        else if (qw == 7)
            cout << "Æâ";
        else if (qw == 8)
            cout << "°Æ";
        else if (qw == 9)
            cout << "¾Á";
        cout << "ÇªÁã";

        if (w == 1)
            cout << "Ò¼";
        else if (w == 2)
            cout << "·¡";
        else if (w == 3)
            cout << "Èş";
        else if (w == 4)
            cout << "ËÁ";
        else if (w == 5)
            cout << "Îé";
        else if (w == 6)
            cout << "Â½";
        else if (w == 7)
            cout << "Æâ";
        else if (w == 8)
            cout << "°Æ";
        else if (w == 9)
            cout << "¾Á";
        cout << "Íò";

    }
    if (qw == 0 && bw != 0 && sw != 0 && w == 0) {  //0**0 8 
         if (sy != 0 || y != 0)
             cout << "Áã";
         if (bw == 1)
             cout << "Ò¼";
         else if (bw == 2)
             cout << "·¡";
         else if (bw == 3)
             cout << "Èş";
         else if (bw == 4)
             cout << "ËÁ";
         else if (bw == 5)
             cout << "Îé";
         else if (bw == 6)
             cout << "Â½";
         else if (bw == 7)
             cout << "Æâ";
         else if (bw == 8)
             cout << "°Æ";
         else if (bw == 9)
             cout << "¾Á";
         cout << "°Û";
         if (sw == 1)
             cout << "Ò¼";
         else if (sw == 2)
             cout << "·¡";
         else if (sw == 3)
             cout << "Èş";
         else if (sw == 4)
             cout << "ËÁ";
         else if (sw == 5)
             cout << "Îé";
         else if (sw == 6)
             cout << "Â½";
         else if (sw == 7)
             cout << "Æâ";
         else if (sw == 8)
             cout << "°Æ";
         else if (sw == 9)
             cout << "¾Á";
         cout << "Ê°Íò";

    }
    if (qw != 0 && bw == 0 && sw != 0 && w == 0) {  //80*0 9 

         if (qw == 1)
             cout << "Ò¼";
         else if (qw == 2)
             cout << "·¡";
         else if (qw == 3)
             cout << "Èş";
         else if (qw == 4)
             cout << "ËÁ";
         else if (qw == 5)
             cout << "Îé";
         else if (qw == 6)
             cout << "Â½";
         else if (qw == 7)
             cout << "Æâ";
         else if (qw == 8)
             cout << "°Æ";
         else if (qw == 9)
             cout << "¾Á";
         cout << "ÇªÁã";
         if (sw == 1)
             cout << "Ò¼";
         else if (sw == 2)
             cout << "·¡";
         else if (sw == 3)
             cout << "Èş";
         else if (sw == 4)
             cout << "ËÁ";
         else if (sw == 5)
             cout << "Îé";
         else if (sw == 6)
             cout << "Â½";
         else if (sw == 7)
             cout << "Æâ";
         else if (sw == 8)
             cout << "°Æ";
         else if (sw == 9)
             cout << "¾Á";
         cout << "Ê°Íò";

    }
    if (qw != 0 && bw != 0 && sw == 0 && w == 0) {  //**00 10

         if (qw == 1)
             cout << "Ò¼";
         else if (qw == 2)
             cout << "·¡";
         else if (qw == 3)
             cout << "Èş";
         else if (qw == 4)
             cout << "ËÁ";
         else if (qw == 5)
             cout << "Îé";
         else if (qw == 6)
             cout << "Â½";
         else if (qw == 7)
             cout << "Æâ";
         else if (qw == 8)
             cout << "°Æ";
         else if (qw == 9)
             cout << "¾Á";
         cout << "Çª";
         if (bw == 1)
             cout << "Ò¼";
         else if (bw == 2)
             cout << "·¡";
         else if (bw == 3)
             cout << "Èş";
         else if (bw == 4)
             cout << "ËÁ";
         else if (bw == 5)
             cout << "Îé";
         else if (bw == 6)
             cout << "Â½";
         else if (bw == 7)
             cout << "Æâ";
         else if (bw == 8)
             cout << "°Æ";
         else if (bw == 9)
             cout << "¾Á";
         cout << "°ÛÍò";

    }
    if (qw != 0 && bw != 0 && sw != 0 && w == 0) {  //***0 11

         if (qw == 1)
             cout << "Ò¼";
         else if (qw == 2)
             cout << "·¡";
         else if (qw == 3)
             cout << "Èş";
         else if (qw == 4)
             cout << "ËÁ";
         else if (qw == 5)
             cout << "Îé";
         else if (qw == 6)
             cout << "Â½";
         else if (qw == 7)
             cout << "Æâ";
         else if (qw == 8)
             cout << "°Æ";
         else if (qw == 9)
             cout << "¾Á";
         cout << "Çª";
         if (bw == 1)
             cout << "Ò¼";
         else if (bw == 2)
             cout << "·¡";
         else if (bw == 3)
             cout << "Èş";
         else if (bw == 4)
             cout << "ËÁ";
         else if (bw == 5)
             cout << "Îé";
         else if (bw == 6)
             cout << "Â½";
         else if (bw == 7)
             cout << "Æâ";
         else if (bw == 8)
             cout << "°Æ";
         else if (bw == 9)
             cout << "¾Á";
         cout << "°Û";
         if (sw == 1)
             cout << "Ò¼";
         else if (sw == 2)
             cout << "·¡";
         else if (sw == 3)
             cout << "Èş";
         else if (sw == 4)
             cout << "ËÁ";
         else if (sw == 5)
             cout << "Îé";
         else if (sw == 6)
             cout << "Â½";
         else if (sw == 7)
             cout << "Æâ";
         else if (sw == 8)
             cout << "°Æ";
         else if (sw == 9)
             cout << "¾Á";
         cout << "Ê°Íò";
    }
    if (qw != 0 && bw != 0 && sw == 0 && w != 0) {  //**0* 12
         if (qw == 1)
             cout << "Ò¼";
         else if (qw == 2)
             cout << "·¡";
         else if (qw == 3)
             cout << "Èş";
         else if (qw == 4)
             cout << "ËÁ";
         else if (qw == 5)
             cout << "Îé";
         else if (qw == 6)
             cout << "Â½";
         else if (qw == 7)
             cout << "Æâ";
         else if (qw == 8)
             cout << "°Æ";
         else if (qw == 9)
             cout << "¾Á";
         cout << "Çª";
         if (bw == 1)
             cout << "Ò¼";
         else if (bw == 2)
             cout << "·¡";
         else if (bw == 3)
             cout << "Èş";
         else if (bw == 4)
             cout << "ËÁ";
         else if (bw == 5)
             cout << "Îé";
         else if (bw == 6)
             cout << "Â½";
         else if (bw == 7)
             cout << "Æâ";
         else if (bw == 8)
             cout << "°Æ";
         else if (bw == 9)
             cout << "¾Á";
         cout << "°ÛÁã";
         if (w == 1)
             cout << "Ò¼";
         else if (w == 2)
             cout << "·¡";
         else if (w == 3)
             cout << "Èş";
         else if (w == 4)
             cout << "ËÁ";
         else if (w == 5)
             cout << "Îé";
         else if (w == 6)
             cout << "Â½";
         else if (w == 7)
             cout << "Æâ";
         else if (w == 8)
             cout << "°Æ";
         else if (w == 9)
             cout << "¾Á";
         cout << "Íò";
    }
    if (qw != 0 && bw == 0 && sw != 0 && w != 0) {  //*0** 13
         if (qw == 1)
             cout << "Ò¼";
         else if (qw == 2)
             cout << "·¡";
         else if (qw == 3)
             cout << "Èş";
         else if (qw == 4)
             cout << "ËÁ";
         else if (qw == 5)
             cout << "Îé";
         else if (qw == 6)
             cout << "Â½";
         else if (qw == 7)
             cout << "Æâ";
         else if (qw == 8)
             cout << "°Æ";
         else if (qw == 9)
             cout << "¾Á";
         cout << "ÇªÁã";
         if (sw == 1)
             cout << "Ò¼";
         else if (sw == 2)
             cout << "·¡";
         else if (sw == 3)
             cout << "Èş";
         else if (sw == 4)
             cout << "ËÁ";
         else if (sw == 5)
             cout << "Îé";
         else if (sw == 6)
             cout << "Â½";
         else if (sw == 7)
             cout << "Æâ";
         else if (sw == 8)
             cout << "°Æ";
         else if (sw == 9)
             cout << "¾Á";
         cout << "Ê°";
         if (w == 1)
             cout << "Ò¼";
         else if (w == 2)
             cout << "·¡";
         else if (w == 3)
             cout << "Èş";
         else if (w == 4)
             cout << "ËÁ";
         else if (w == 5)
             cout << "Îé";
         else if (w == 6)
             cout << "Â½";
         else if (w == 7)
             cout << "Æâ";
         else if (w == 8)
             cout << "°Æ";
         else if (w == 9)
             cout << "¾Á";
         cout << "Íò";
    }
    if (qw == 0 && bw != 0 && sw != 0 && w != 0) {  //0*** 14
         if (sy != 0 || y != 0)
             cout << "Áã";
         if (bw == 1)
             cout << "Ò¼";
         else if (bw == 2)
             cout << "·¡";
         else if (bw == 3)
             cout << "Èş";
         else if (bw == 4)
             cout << "ËÁ";
         else if (bw == 5)
             cout << "Îé";
         else if (bw == 6)
             cout << "Â½";
         else if (bw == 7)
             cout << "Æâ";
         else if (bw == 8)
             cout << "°Æ";
         else if (bw == 9)
             cout << "¾Á";
         cout << "°Û";
         if (sw == 1)
             cout << "Ò¼";
         else if (sw == 2)
             cout << "·¡";
         else if (sw == 3)
             cout << "Èş";
         else if (sw == 4)
             cout << "ËÁ";
         else if (sw == 5)
             cout << "Îé";
         else if (sw == 6)
             cout << "Â½";
         else if (sw == 7)
             cout << "Æâ";
         else if (sw == 8)
             cout << "°Æ";
         else if (sw == 9)
             cout << "¾Á";
         cout << "Ê°";
         if (w == 1)
             cout << "Ò¼";
         else if (w == 2)
             cout << "·¡";
         else if (w == 3)
             cout << "Èş";
         else if (w == 4)
             cout << "ËÁ";
         else if (w == 5)
             cout << "Îé";
         else if (w == 6)
             cout << "Â½";
         else if (w == 7)
             cout << "Æâ";
         else if (w == 8)
             cout << "°Æ";
         else if (w == 9)
             cout << "¾Á";
         cout << "Íò";
    }
    if (qw != 0 && bw != 0 && sw != 0 && w != 0) {  //**** 15
         if (qw == 1)
             cout << "Ò¼";
         else if (qw == 2)
             cout << "·¡";
         else if (qw == 3)
             cout << "Èş";
         else if (qw == 4)
             cout << "ËÁ";
         else if (qw == 5)
             cout << "Îé";
         else if (qw == 6)
             cout << "Â½";
         else if (qw == 7)
             cout << "Æâ";
         else if (qw == 8)
             cout << "°Æ";
         else if (qw == 9)
             cout << "¾Á";
         cout << "Çª";
         if (bw == 1)
             cout << "Ò¼";
         else if (bw == 2)
             cout << "·¡";
         else if (bw == 3)
             cout << "Èş";
         else if (bw == 4)
             cout << "ËÁ";
         else if (bw == 5)
             cout << "Îé";
         else if (bw == 6)
             cout << "Â½";
         else if (bw == 7)
             cout << "Æâ";
         else if (bw == 8)
             cout << "°Æ";
         else if (bw == 9)
             cout << "¾Á";
         cout << "°Û";
         if (sw == 1)
             cout << "Ò¼";
         else if (sw == 2)
             cout << "·¡";
         else if (sw == 3)
             cout << "Èş";
         else if (sw == 4)
             cout << "ËÁ";
         else if (sw == 5)
             cout << "Îé";
         else if (sw == 6)
             cout << "Â½";
         else if (sw == 7)
             cout << "Æâ";
         else if (sw == 8)
             cout << "°Æ";
         else if (sw == 9)
             cout << "¾Á";
         cout << "Ê°";
         if (w == 1)
             cout << "Ò¼";
         else if (w == 2)
             cout << "·¡";
         else if (w == 3)
             cout << "Èş";
         else if (w == 4)
             cout << "ËÁ";
         else if (w == 5)
             cout << "Îé";
         else if (w == 6)
             cout << "Â½";
         else if (w == 7)
             cout << "Æâ";
         else if (w == 8)
             cout << "°Æ";
         else if (w == 9)
             cout << "¾Á";
         cout << "Íò";
    }
    




     //Íò½áÊø ¿ªÊ¼Ç§
    if (q != 0 && b != 0 && s != 0 && g != 0) {  //**** 15
        if (q == 1)
            cout << "Ò¼";
        else if (q == 2)
            cout << "·¡";
        else if (q == 3)
            cout << "Èş";
        else if (q == 4)
            cout << "ËÁ";
        else if (q == 5)
            cout << "Îé";
        else if (q == 6)
            cout << "Â½";
        else if (q == 7)
            cout << "Æâ";
        else if (q == 8)
            cout << "°Æ";
        else if (q == 9)
            cout << "¾Á";
        cout << "Çª";
        if (b == 1)
            cout << "Ò¼";
        else if (b == 2)
            cout << "·¡";
        else if (b == 3)
            cout << "Èş";
        else if (b == 4)
            cout << "ËÁ";
        else if (b == 5)
            cout << "Îé";
        else if (b == 6)
            cout << "Â½";
        else if (b == 7)
            cout << "Æâ";
        else if (b == 8)
            cout << "°Æ";
        else if (b == 9)
            cout << "¾Á";
        cout << "°Û";
        if (s == 1)
            cout << "Ò¼";
        else if (s == 2)
            cout << "·¡";
        else if (s == 3)
            cout << "Èş";
        else if (s == 4)
            cout << "ËÁ";
        else if (s == 5)
            cout << "Îé";
        else if (s == 6)
            cout << "Â½";
        else if (s == 7)
            cout << "Æâ";
        else if (s == 8)
            cout << "°Æ";
        else if (s == 9)
            cout << "¾Á";
        cout << "Ê°";
        if (g == 1)
            cout << "Ò¼";
        else if (g == 2)
            cout << "·¡";
        else if (g == 3)
            cout << "Èş";
        else if (g == 4)
            cout << "ËÁ";
        else if (g == 5)
            cout << "Îé";
        else if (g == 6)
            cout << "Â½";
        else if (g == 7)
            cout << "Æâ";
        else if (g == 8)
            cout << "°Æ";
        else if (g == 9)
            cout << "¾Á";
    }
    if (q != 0 && b != 0 && s != 0 && g == 0) {  //***0 14
        if (q == 1)
            cout << "Ò¼";
        else if (q == 2)
            cout << "·¡";
        else if (q == 3)
            cout << "Èş";
        else if (q == 4)
            cout << "ËÁ";
        else if (q == 5)
            cout << "Îé";
        else if (q == 6)
            cout << "Â½";
        else if (q == 7)
            cout << "Æâ";
        else if (q == 8)
            cout << "°Æ";
        else if (q == 9)
            cout << "¾Á";
        cout << "Çª";
        if (b == 1)
            cout << "Ò¼";
        else if (b == 2)
            cout << "·¡";
        else if (b == 3)
            cout << "Èş";
        else if (b == 4)
            cout << "ËÁ";
        else if (b == 5)
            cout << "Îé";
        else if (b == 6)
            cout << "Â½";
        else if (b == 7)
            cout << "Æâ";
        else if (b == 8)
            cout << "°Æ";
        else if (b == 9)
            cout << "¾Á";
        cout << "°Û";
        if (s == 1)
            cout << "Ò¼";
        else if (s == 2)
            cout << "·¡";
        else if (s == 3)
            cout << "Èş";
        else if (s == 4)
            cout << "ËÁ";
        else if (s == 5)
            cout << "Îé";
        else if (s == 6)
            cout << "Â½";
        else if (s == 7)
            cout << "Æâ";
        else if (s == 8)
            cout << "°Æ";
        else if (s == 9)
            cout << "¾Á";
        cout << "Ê°";
    }
    if (q != 0 && b != 0 && s == 0 && g == 0) {  //**00 13
        if (q == 1)
            cout << "Ò¼";
        else if (q == 2)
            cout << "·¡";
        else if (q == 3)
            cout << "Èş";
        else if (q == 4)
            cout << "ËÁ";
        else if (q == 5)
            cout << "Îé";
        else if (q == 6)
            cout << "Â½";
        else if (q == 7)
            cout << "Æâ";
        else if (q == 8)
            cout << "°Æ";
        else if (q == 9)
            cout << "¾Á";
        cout << "Çª";
        if (b == 1)
            cout << "Ò¼";
        else if (b == 2)
            cout << "·¡";
        else if (b == 3)
            cout << "Èş";
        else if (b == 4)
            cout << "ËÁ";
        else if (b == 5)
            cout << "Îé";
        else if (b == 6)
            cout << "Â½";
        else if (b == 7)
            cout << "Æâ";
        else if (b == 8)
            cout << "°Æ";
        else if (b == 9)
            cout << "¾Á";
        cout << "°Û";
    }
    if (q != 0 && b == 0 && s == 0 && g == 0) {  //*000 12
        if (q == 1)
            cout << "Ò¼";
        else if (q == 2)
            cout << "·¡";
        else if (q == 3)
            cout << "Èş";
        else if (q == 4)
            cout << "ËÁ";
        else if (q == 5)
            cout << "Îé";
        else if (q == 6)
            cout << "Â½";
        else if (q == 7)
            cout << "Æâ";
        else if (q == 8)
            cout << "°Æ";
        else if (q == 9)
            cout << "¾Á";
        cout << "Çª";
    }
    if (q != 0 && b == 0 && s != 0 && g == 0) {  //*0*0 11
        if (q == 1)
            cout << "Ò¼";
        else if (q == 2)
            cout << "·¡";
        else if (q == 3)
            cout << "Èş";
        else if (q == 4)
            cout << "ËÁ";
        else if (q == 5)
            cout << "Îé";
        else if (q == 6)
            cout << "Â½";
        else if (q == 7)
            cout << "Æâ";
        else if (q == 8)
            cout << "°Æ";
        else if (q == 9)
            cout << "¾Á";
        cout << "ÇªÁã";
        if (s == 1)
            cout << "Ò¼";
        else if (s == 2)
            cout << "·¡";
        else if (s == 3)
            cout << "Èş";
        else if (s == 4)
            cout << "ËÁ";
        else if (s == 5)
            cout << "Îé";
        else if (s == 6)
            cout << "Â½";
        else if (s == 7)
            cout << "Æâ";
        else if (s == 8)
            cout << "°Æ";
        else if (s == 9)
            cout << "¾Á";
        cout << "Ê°";
    }

    if (q != 0 && b != 0 && s == 0 && g != 0) {  //**0* 10
        if (q == 1)
            cout << "Ò¼";
        else if (q == 2)
            cout << "·¡";
        else if (q == 3)
            cout << "Èş";
        else if (q == 4)
            cout << "ËÁ";
        else if (q == 5)
            cout << "Îé";
        else if (q == 6)
            cout << "Â½";
        else if (q == 7)
            cout << "Æâ";
        else if (q == 8)
            cout << "°Æ";
        else if (q == 9)
            cout << "¾Á";
        cout << "Çª";
        if (b == 1)
            cout << "Ò¼";
        else if (b == 2)
            cout << "·¡";
        else if (b == 3)
            cout << "Èş";
        else if (b == 4)
            cout << "ËÁ";
        else if (b == 5)
            cout << "Îé";
        else if (b == 6)
            cout << "Â½";
        else if (b == 7)
            cout << "Æâ";
        else if (b == 8)
            cout << "°Æ";
        else if (b == 9)
            cout << "¾Á";
        cout << "°ÛÁã";
        if (g == 1)
            cout << "Ò¼";
        else if (g == 2)
            cout << "·¡";
        else if (g == 3)
            cout << "Èş";
        else if (g == 4)
            cout << "ËÁ";
        else if (g == 5)
            cout << "Îé";
        else if (g == 6)
            cout << "Â½";
        else if (g == 7)
            cout << "Æâ";
        else if (g == 8)
            cout << "°Æ";
        else if (g == 9)
            cout << "¾Á";
    }

    if (q != 0 && b == 0 && s != 0 && g != 0) {  //*0** 9
        if (q == 1)
            cout << "Ò¼";
        else if (q == 2)
            cout << "·¡";
        else if (q == 3)
            cout << "Èş";
        else if (q == 4)
            cout << "ËÁ";
        else if (q == 5)
            cout << "Îé";
        else if (q == 6)
            cout << "Â½";
        else if (q == 7)
            cout << "Æâ";
        else if (q == 8)
            cout << "°Æ";
        else if (q == 9)
            cout << "¾Á";
        cout << "ÇªÁã";
        if (s == 1)
            cout << "Ò¼";
        else if (s == 2)
            cout << "·¡";
        else if (s == 3)
            cout << "Èş";
        else if (s == 4)
            cout << "ËÁ";
        else if (s == 5)
            cout << "Îé";
        else if (s == 6)
            cout << "Â½";
        else if (s == 7)
            cout << "Æâ";
        else if (s == 8)
            cout << "°Æ";
        else if (s == 9)
            cout << "¾Á";
        cout << "Ê°";
        if (g == 1)
            cout << "Ò¼";
        else if (g == 2)
            cout << "·¡";
        else if (g == 3)
            cout << "Èş";
        else if (g == 4)
            cout << "ËÁ";
        else if (g == 5)
            cout << "Îé";
        else if (g == 6)
            cout << "Â½";
        else if (g == 7)
            cout << "Æâ";
        else if (g == 8)
            cout << "°Æ";
        else if (g == 9)
            cout << "¾Á";
    }
    if (q == 0 && b != 0 && s != 0 && g != 0) {  //0*** 8
        if (sy != 0 || y != 0 || qw != 0 || sw != 0 || bw != 0 || w != 0)
            cout << "Áã";
        if (b == 1)
            cout << "Ò¼";
        else if (b == 2)
            cout << "·¡";
        else if (b == 3)
            cout << "Èş";
        else if (b == 4)
            cout << "ËÁ";
        else if (b == 5)
            cout << "Îé";
        else if (b == 6)
            cout << "Â½";
        else if (b == 7)
            cout << "Æâ";
        else if (b == 8)
            cout << "°Æ";
        else if (b == 9)
            cout << "¾Á";
        cout << "°Û";
        if (s == 1)
            cout << "Ò¼";
        else if (s == 2)
            cout << "·¡";
        else if (s == 3)
            cout << "Èş";
        else if (s == 4)
            cout << "ËÁ";
        else if (s == 5)
            cout << "Îé";
        else if (s == 6)
            cout << "Â½";
        else if (s == 7)
            cout << "Æâ";
        else if (s == 8)
            cout << "°Æ";
        else if (s == 9)
            cout << "¾Á";
        cout << "Ê°";
        if (g == 1)
            cout << "Ò¼";
        else if (g == 2)
            cout << "·¡";
        else if (g == 3)
            cout << "Èş";
        else if (g == 4)
            cout << "ËÁ";
        else if (g == 5)
            cout << "Îé";
        else if (g == 6)
            cout << "Â½";
        else if (g == 7)
            cout << "Æâ";
        else if (g == 8)
            cout << "°Æ";
        else if (g == 9)
            cout << "¾Á";
    }
    if (q != 0 && b == 0 && s == 0 && g != 0) {  //*00* 7
        if (q == 1)
            cout << "Ò¼";
        else if (q == 2)
            cout << "·¡";
        else if (q == 3)
            cout << "Èş";
        else if (q == 4)
            cout << "ËÁ";
        else if (q == 5)
            cout << "Îé";
        else if (q == 6)
            cout << "Â½";
        else if (q == 7)
            cout << "Æâ";
        else if (q == 8)
            cout << "°Æ";
        else if (q == 9)
            cout << "¾Á";
        cout << "ÇªÁã";
        if (g == 1)
            cout << "Ò¼";
        else if (g == 2)
            cout << "·¡";
        else if (g == 3)
            cout << "Èş";
        else if (g == 4)
            cout << "ËÁ";
        else if (g == 5)
            cout << "Îé";
        else if (g == 6)
            cout << "Â½";
        else if (g == 7)
            cout << "Æâ";
        else if (g == 8)
            cout << "°Æ";
        else if (g == 9)
            cout << "¾Á";
    }
    if (q == 0 && b == 0 && s == 0 && g != 0) {  //000* 6
        if (sy != 0 || y != 0 || qw != 0 || sw != 0 || bw != 0 || w != 0)
            cout << "Áã";
        if (g == 1)
            cout << "Ò¼";
        else if (g == 2)
            cout << "·¡";
        else if (g == 3)
            cout << "Èş";
        else if (g == 4)
            cout << "ËÁ";
        else if (g == 5)
            cout << "Îé";
        else if (g == 6)
            cout << "Â½";
        else if (g == 7)
            cout << "Æâ";
        else if (g == 8)
            cout << "°Æ";
        else if (g == 9)
            cout << "¾Á";
    }
    if (q == 0 && b != 0 && s != 0 && g == 0) {  //0**0 5
        if (sy != 0 || y != 0 || qw != 0 || sw != 0 || bw != 0 || w != 0)
            cout << "Áã";
        if (b == 1)
            cout << "Ò¼";
        else if (b == 2)
            cout << "·¡";
        else if (b == 3)
            cout << "Èş";
        else if (b == 4)
            cout << "ËÁ";
        else if (b == 5)
            cout << "Îé";
        else if (b == 6)
            cout << "Â½";
        else if (b == 7)
            cout << "Æâ";
        else if (b == 8)
            cout << "°Æ";
        else if (b == 9)
            cout << "¾Á";
        cout << "°Û";
        if (s == 1)
            cout << "Ò¼";
        else if (s == 2)
            cout << "·¡";
        else if (s == 3)
            cout << "Èş";
        else if (s == 4)
            cout << "ËÁ";
        else if (s == 5)
            cout << "Îé";
        else if (s == 6)
            cout << "Â½";
        else if (s == 7)
            cout << "Æâ";
        else if (s == 8)
            cout << "°Æ";
        else if (s == 9)
            cout << "¾Á";
        cout << "Ê°";
    }
    if (q == 0 && b != 0 && s == 0 && g == 0) {  //0*00 5
        if (sy != 0 || y != 0 || qw != 0 || sw != 0 || bw != 0 || w != 0)
            cout << "Áã";
        if (b == 1)
            cout << "Ò¼";
        else if (b == 2)
            cout << "·¡";
        else if (b == 3)
            cout << "Èş";
        else if (b == 4)
            cout << "ËÁ";
        else if (b == 5)
            cout << "Îé";
        else if (b == 6)
            cout << "Â½";
        else if (b == 7)
            cout << "Æâ";
        else if (b == 8)
            cout << "°Æ";
        else if (b == 9)
            cout << "¾Á";
        cout << "°Û";
    }
    if (q == 0 && b != 0 && s == 0 && g != 0) {  //0*0* 4
        if (sy != 0 || y != 0 || qw != 0 || sw != 0 || bw != 0 || w != 0)
            cout << "Áã";
        if (b == 1)
            cout << "Ò¼";
        else if (b == 2)
            cout << "·¡";
        else if (b == 3)
            cout << "Èş";
        else if (b == 4)
            cout << "ËÁ";
        else if (b == 5)
            cout << "Îé";
        else if (b == 6)
            cout << "Â½";
        else if (b == 7)
            cout << "Æâ";
        else if (b == 8)
            cout << "°Æ";
        else if (b == 9)
            cout << "¾Á";
        cout << "°ÛÁã";
        if (g == 1)
            cout << "Ò¼";
        else if (g == 2)
            cout << "·¡";
        else if (g == 3)
            cout << "Èş";
        else if (g == 4)
            cout << "ËÁ";
        else if (g == 5)
            cout << "Îé";
        else if (g == 6)
            cout << "Â½";
        else if (g == 7)
            cout << "Æâ";
        else if (g == 8)
            cout << "°Æ";
        else if (g == 9)
            cout << "¾Á";
    }
    if (q == 0 && b == 0 && s != 0 && g == 0) {  //00*0 2
        if (sy != 0 || y != 0 || qw != 0 || sw != 0 || bw != 0 || w != 0)
            cout << "Áã";
        if (s == 1)
            cout << "Ò¼";
        else if (s == 2)
            cout << "·¡";
        else if (s == 3)
            cout << "Èş";
        else if (s == 4)
            cout << "ËÁ";
        else if (s == 5)
            cout << "Îé";
        else if (s == 6)
            cout << "Â½";
        else if (s == 7)
            cout << "Æâ";
        else if (s == 8)
            cout << "°Æ";
        else if (s == 9)
            cout << "¾Á";
        cout << "Ê°";
    }
    if (q == 0 && b == 0 && s != 0 && g != 0) {  //00** 1
        if (sy != 0 || y != 0 || qw != 0 || sw != 0 || bw != 0 || w != 0)
            cout << "Áã";
        if (s == 1)
            cout << "Ò¼";
        else if (s == 2)
            cout << "·¡";
        else if (s == 3)
            cout << "Èş";
        else if (s == 4)
            cout << "ËÁ";
        else if (s == 5)
            cout << "Îé";
        else if (s == 6)
            cout << "Â½";
        else if (s == 7)
            cout << "Æâ";
        else if (s == 8)
            cout << "°Æ";
        else if (s == 9)
            cout << "¾Á";
        cout << "Ê°";
        if (g == 1)
            cout << "Ò¼";
        else if (g == 2)
            cout << "·¡";
        else if (g == 3)
            cout << "Èş";
        else if (g == 4)
            cout << "ËÁ";
        else if (g == 5)
            cout << "Îé";
        else if (g == 6)
            cout << "Â½";
        else if (g == 7)
            cout << "Æâ";
        else if (g == 8)
            cout << "°Æ";
        else if (g == 9)
            cout << "¾Á";     
    }

    if (!sy&&!y&& !qw && !bw&&!w&&!sw &&! q &&! b &&! s &&! g&&!j&&!f)
        cout << "ÁãÔ²";


    //Ç§½áÊø£¬½Ç·Ö¿ªÊ¼
    if (sy != 0 || y != 0 || qw != 0 || sw != 0 || bw != 0 || w != 0 || q != 0 || b != 0 || s != 0 || g != 0) {
        cout << "Ô²";
    }
    if (sy&&y&&qw&&bw&&w&&sw&&q&&b&&s&&g&&j == 0 && f != 0)
        cout << "Áã";
    if (j == 1)
        cout << "Ò¼½Ç";
    else if (j == 2)
        cout << "·¡½Ç";
    else if (j == 3)
        cout << "Èş½Ç";
    else if (j == 4)
        cout << "ËÁ½Ç";
    else if (j == 5)
        cout << "Îé½Ç";
    else if (j == 6)
        cout << "Â½½Ç";
    else if (j == 7)
        cout << "Æâ½Ç";
    else if (j == 8)
        cout << "°Æ½Ç";
    else if (j == 9)
        cout << "¾Á½Ç";
    else if (j == 0){
        if (f == 1)
            cout << "Ò¼·Ö";
        else if (f == 2)
            cout << "·¡·Ö";
        else if (f == 3)
            cout << "Èş·Ö";
        else if (f == 4)
            cout << "ËÁ·Ö";
        else if (f == 5)
            cout << "Îé·Ö";
        else if (f == 6)
            cout << "Â½·Ö";
        else if (f == 7)
            cout << "Æâ·Ö";
        else if (f == 8)
            cout << "°Æ·Ö";
        else if (f == 9)
            cout << "¾Á·Ö";
        else if (f == 0)
            cout << "Õû";
    }

    if (f == 1 && j != 0)
        cout << "Ò¼·Ö";
    else if (f == 2 && j != 0)
        cout << "·¡·Ö";
    else if (f == 3 && j != 0)
        cout << "Èş·Ö";
    else if (f == 4 && j != 0)
        cout << "ËÁ·Ö";
    else if (f == 5 && j != 0)
        cout << "Îé·Ö";
    else if (f == 6 && j != 0)
        cout << "Â½·Ö";
    else if (f == 7 && j != 0)
        cout << "Æâ·Ö";
    else if (f == 8 && j != 0)
        cout << "°Æ·Ö";
    else if (f == 9 && j != 0)
        cout << "¾Á·Ö";
    else if (f == 0 && j != 0)
        cout << "Õû";
    cout << endl;
    
	return 0;
}
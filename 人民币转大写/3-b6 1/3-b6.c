/*2151299 ÐÅ16 ËÕ¼ÒÃú*/
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
 int main()
{
     double a, sy, y, qw, bw, sw, h, w, q, b, s, g, j, o, f;

     printf("ÇëÊäÈë[0..100 ÒÚ)Ö®¼äµÄÊý×Ö:\n");
     scanf("%lf", &a);
     printf("´óÐ´½á¹ûÊÇ:\n");
     sy = (int)(a / 1000000000);
     y = (int)((a - sy * 1000000000) / 100000000);
     qw = (int)((a - sy * 1000000000 - y * 100000000) / 10000000);
     bw = (int)((a - sy * 1000000000 - y * 100000000 - qw * 10000000) / 1000000);
     sw = (int)((a - sy * 1000000000 - y * 100000000 - qw * 10000000 - bw * 1000000) / 100000);
     w = (int)((a - sy * 1000000000 - y * 100000000 - qw * 10000000 - bw * 1000000 - sw * 100000) / 10000);
     q = (int)((a - sy * 1000000000 - y * 100000000 - qw * 10000000 - bw * 1000000 - sw * 100000 - w * 10000) / 1000);
     b = (int)((a - sy * 1000000000 - y * 100000000 - qw * 10000000 - bw * 1000000 - sw * 100000 - w * 10000 - q * 1000) / 100);
     s = (int)((a - sy * 1000000000 - y * 100000000 - qw * 10000000 - bw * 1000000 - sw * 100000 - w * 10000 - q * 1000 - b * 100) / 10);
     g = (int)((a - sy * 1000000000 - y * 100000000 - qw * 10000000 - bw * 1000000 - sw * 100000 - w * 10000 - q * 1000 - b * 100 - s * 10) / 1);
     h = a - sy * 1000000000 - y * 100000000 - qw * 10000000 - bw * 1000000 - sw * 100000 - w * 10000 - q * 1000 - b * 100 - s * 10 - g * 1;
     o = h * 100.001;
     j = (int)(o / 10);
     f = (int)(o - j * 10);
    //Ê®ÒÚµ½ÒÚ£º
    if (sy == 1)
        printf("Ò¼Ê°");
    else if (sy == 2)
        printf("·¡Ê°");
    else if (sy == 3)
        printf("ÈþÊ°");
    else if (sy == 4)
        printf("ËÁÊ°");
    else if (sy == 5)
        printf("ÎéÊ°");
    else if (sy == 6)
        printf("Â½Ê°");
    else if (sy == 7)
        printf("ÆâÊ°");
    else if (sy == 8)
        printf("°ÆÊ°");
    else if (sy == 9)
        printf("¾ÁÊ°");
    else if (sy == 0) {
        if (y == 1)
            printf("Ò¼ÒÚ");
        else if (y == 2)
            printf("·¡ÒÚ");
        else if (y == 3)
            printf("ÈþÒÚ");
        else if (y == 4)
            printf("ËÁÒÚ");
        else if (y == 5)
            printf("ÎéÒÚ");
        else if (y == 6)
            printf("Â½ÒÚ");
        else if (y == 7)
            printf("ÆâÒÚ");
        else if (y == 8)
            printf("°ÆÒÚ");
        else if (y == 9)
            printf("¾ÁÒÚ");
    }
    if (y == 1 && sy != 0)
        printf("Ò¼ÒÚ");
    else if (y == 2 && sy != 0)
        printf("·¡ÒÚ");
    else if (y == 3 && sy != 0)
        printf("ÈþÒÚ");
    else if (y == 4 && sy != 0)
        printf("ËÁÒÚ");
    else if (y == 5 && sy != 0)
        printf("ÎéÒÚ");
    else if (y == 6 && sy != 0)
        printf("Â½ÒÚ");
    else if (y == 7 && sy != 0)
        printf("ÆâÒÚ");
    else if (y == 8 && sy != 0)
        printf("°ÆÒÚ");
    else if (y == 9 && sy != 0)
        printf("¾ÁÒÚ");
    else if (y == 0 && sy != 0)
        printf("ÒÚ");

    //Ê®ÒÚ-ÒÚ½áÊø£¬Íò¿ªÊ¼

    if (qw == 0 && bw == 0 && sw == 0 && w != 0) {  //000* 1
        if (sy != 0 || y != 0)
            printf("Áã");
        if (w == 1)
            printf("Ò¼");
        else if (w == 2)
            printf("·¡");
        else if (w == 3)
            printf("Èþ");
        else if (w == 4)
            printf("ËÁ");
        else if (w == 5)
            printf("Îé");
        else if (w == 6)
            printf("Â½");
        else if (w == 7)
            printf("Æâ");
        else if (w == 8)
            printf("°Æ");
        else if (w == 9)
            printf("¾Á");
        printf("Íò");

    }
    if (qw == 0 && bw == 0 && sw != 0 && w == 0) {  //00*0 2
        if (sy != 0 || y != 0)
            printf("Áã");
        if (sw == 1)
            printf("Ò¼");
        else if (sw == 2)
            printf("·¡");
        else if (sw == 3)
            printf("Èþ");
        else if (sw == 4)
            printf("ËÁ");
        else if (sw == 5)
            printf("Îé");
        else if (sw == 6)
            printf("Â½");
        else if (sw == 7)
            printf("Æâ");
        else if (sw == 8)
            printf("°Æ");
        else if (sw == 9)
            printf("¾Á");
        printf("Ê°Íò");

    }
    if (qw == 0 && bw != 0 && sw == 0 && w == 0) {  //0*00 3 
        if (sy != 0 || y != 0)
            printf("Áã");
        if (bw == 1)
            printf("Ò¼");
        else if (bw == 2)
            printf("·¡");
        else if (bw == 3)
            printf("Èþ");
        else if (bw == 4)
            printf("ËÁ");
        else if (bw == 5)
            printf("Îé");
        else if (bw == 6)
            printf("Â½");
        else if (bw == 7)
            printf("Æâ");
        else if (bw == 8)
            printf("°Æ");
        else if (bw == 9)
            printf("¾Á");
        printf("°ÛÍò");

    }
    if (qw != 0 && bw == 0 && sw == 0 && w == 0) {  //*000 4 
        if (qw == 1)
            printf("Ò¼");
        else if (qw == 2)
            printf("·¡");
        else if (qw == 3)
            printf("Èþ");
        else if (qw == 4)
            printf("ËÁ");
        else if (qw == 5)
            printf("Îé");
        else if (qw == 6)
            printf("Â½");
        else if (qw == 7)
            printf("Æâ");
        else if (qw == 8)
            printf("°Æ");
        else if (qw == 9)
            printf("¾Á");
        printf("ÇªÍò");

    }
    if (qw == 0 && bw == 0 && sw != 0 && w != 0) {  //00** 5 
        if (sy != 0 || y != 0)
            printf("Áã");
        if (sw == 1)
            printf("Ò¼");
        else if (sw == 2)
            printf("·¡");
        else if (sw == 3)
            printf("Èþ");
        else if (sw == 4)
            printf("ËÁ");
        else if (sw == 5)
            printf("Îé");
        else if (sw == 6)
            printf("Â½");
        else if (sw == 7)
            printf("Æâ");
        else if (sw == 8)
            printf("°Æ");
        else if (sw == 9)
            printf("¾Á");
        printf("Ê°");

        if (w == 1)
            printf("Ò¼");
        else if (w == 2)
            printf("·¡");
        else if (w == 3)
            printf("Èþ");
        else if (w == 4)
            printf("ËÁ");
        else if (w == 5)
            printf("Îé");
        else if (w == 6)
            printf("Â½");
        else if (w == 7)
            printf("Æâ");
        else if (w == 8)
            printf("°Æ");
        else if (w == 9)
            printf("¾Á");
        printf("Íò");

    }
    if (qw == 0 && bw != 0 && sw == 0 && w != 0) {  //0*0* 6 
        if (sy != 0 || y != 0)
            printf("Áã");
        if (bw == 1)
            printf("Ò¼");
        else if (bw == 2)
            printf("·¡");
        else if (bw == 3)
            printf("Èþ");
        else if (bw == 4)
            printf("ËÁ");
        else if (bw == 5)
            printf("Îé");
        else if (bw == 6)
            printf("Â½");
        else if (bw == 7)
            printf("Æâ");
        else if (bw == 8)
            printf("°Æ");
        else if (bw == 9)
            printf("¾Á");
        printf("°ÛÁã");

        if (w == 1)
            printf("Ò¼");
        else if (w == 2)
            printf("·¡");
        else if (w == 3)
            printf("Èþ");
        else if (w == 4)
            printf("ËÁ");
        else if (w == 5)
            printf("Îé");
        else if (w == 6)
            printf("Â½");
        else if (w == 7)
            printf("Æâ");
        else if (w == 8)
            printf("°Æ");
        else if (w == 9)
            printf("¾Á");
        printf("Íò");

    }
    if (qw != 0 && bw == 0 && sw == 0 && w != 0) {  //*00* 7 

        if (qw == 1)
            printf("Ò¼");
        else if (qw == 2)
            printf("·¡");
        else if (qw == 3)
            printf("Èþ");
        else if (qw == 4)
            printf("ËÁ");
        else if (qw == 5)
            printf("Îé");
        else if (qw == 6)
            printf("Â½");
        else if (qw == 7)
            printf("Æâ");
        else if (qw == 8)
            printf("°Æ");
        else if (qw == 9)
            printf("¾Á");
        printf("ÇªÁã");

        if (w == 1)
            printf("Ò¼");
        else if (w == 2)
            printf("·¡");
        else if (w == 3)
            printf("Èþ");
        else if (w == 4)
            printf("ËÁ");
        else if (w == 5)
            printf("Îé");
        else if (w == 6)
            printf("Â½");
        else if (w == 7)
            printf("Æâ");
        else if (w == 8)
            printf("°Æ");
        else if (w == 9)
            printf("¾Á");
        printf("Íò");

    }
    if (qw == 0 && bw != 0 && sw != 0 && w == 0) {  //0**0 8 
        if (sy != 0 || y != 0)
            printf("Áã");
        if (bw == 1)
            printf("Ò¼");
        else if (bw == 2)
            printf("·¡");
        else if (bw == 3)
            printf("Èþ");
        else if (bw == 4)
            printf("ËÁ");
        else if (bw == 5)
            printf("Îé");
        else if (bw == 6)
            printf("Â½");
        else if (bw == 7)
            printf("Æâ");
        else if (bw == 8)
            printf("°Æ");
        else if (bw == 9)
            printf("¾Á");
        printf("°Û");
        if (sw == 1)
            printf("Ò¼");
        else if (sw == 2)
            printf("·¡");
        else if (sw == 3)
            printf("Èþ");
        else if (sw == 4)
            printf("ËÁ");
        else if (sw == 5)
            printf("Îé");
        else if (sw == 6)
            printf("Â½");
        else if (sw == 7)
            printf("Æâ");
        else if (sw == 8)
            printf("°Æ");
        else if (sw == 9)
            printf("¾Á");
        printf("Ê°Íò");

    }
    if (qw != 0 && bw == 0 && sw != 0 && w == 0) {  //80*0 9 

        if (qw == 1)
            printf("Ò¼");
        else if (qw == 2)
            printf("·¡");
        else if (qw == 3)
            printf("Èþ");
        else if (qw == 4)
            printf("ËÁ");
        else if (qw == 5)
            printf("Îé");
        else if (qw == 6)
            printf("Â½");
        else if (qw == 7)
            printf("Æâ");
        else if (qw == 8)
            printf("°Æ");
        else if (qw == 9)
            printf("¾Á");
        printf("ÇªÁã");
        if (sw == 1)
            printf("Ò¼");
        else if (sw == 2)
            printf("·¡");
        else if (sw == 3)
            printf("Èþ");
        else if (sw == 4)
            printf("ËÁ");
        else if (sw == 5)
            printf("Îé");
        else if (sw == 6)
            printf("Â½");
        else if (sw == 7)
            printf("Æâ");
        else if (sw == 8)
            printf("°Æ");
        else if (sw == 9)
            printf("¾Á");
        printf("Ê°Íò");

    }
    if (qw != 0 && bw != 0 && sw == 0 && w == 0) {  //**00 10

        if (qw == 1)
            printf("Ò¼");
        else if (qw == 2)
            printf("·¡");
        else if (qw == 3)
            printf("Èþ");
        else if (qw == 4)
            printf("ËÁ");
        else if (qw == 5)
            printf("Îé");
        else if (qw == 6)
            printf("Â½");
        else if (qw == 7)
            printf("Æâ");
        else if (qw == 8)
            printf("°Æ");
        else if (qw == 9)
            printf("¾Á");
        printf("Çª");
        if (bw == 1)
            printf("Ò¼");
        else if (bw == 2)
            printf("·¡");
        else if (bw == 3)
            printf("Èþ");
        else if (bw == 4)
            printf("ËÁ");
        else if (bw == 5)
            printf("Îé");
        else if (bw == 6)
            printf("Â½");
        else if (bw == 7)
            printf("Æâ");
        else if (bw == 8)
            printf("°Æ");
        else if (bw == 9)
            printf("¾Á");
        printf("°ÛÍò");

    }
    if (qw != 0 && bw != 0 && sw != 0 && w == 0) {  //***0 11

        if (qw == 1)
            printf("Ò¼");
        else if (qw == 2)
            printf("·¡");
        else if (qw == 3)
            printf("Èþ");
        else if (qw == 4)
            printf("ËÁ");
        else if (qw == 5)
            printf("Îé");
        else if (qw == 6)
            printf("Â½");
        else if (qw == 7)
            printf("Æâ");
        else if (qw == 8)
            printf("°Æ");
        else if (qw == 9)
            printf("¾Á");
        printf("Çª");
        if (bw == 1)
            printf("Ò¼");
        else if (bw == 2)
            printf("·¡");
        else if (bw == 3)
            printf("Èþ");
        else if (bw == 4)
            printf("ËÁ");
        else if (bw == 5)
            printf("Îé");
        else if (bw == 6)
            printf("Â½");
        else if (bw == 7)
            printf("Æâ");
        else if (bw == 8)
            printf("°Æ");
        else if (bw == 9)
            printf("¾Á");
        printf("°Û");
        if (sw == 1)
            printf("Ò¼");
        else if (sw == 2)
            printf("·¡");
        else if (sw == 3)
            printf("Èþ");
        else if (sw == 4)
            printf("ËÁ");
        else if (sw == 5)
            printf("Îé");
        else if (sw == 6)
            printf("Â½");
        else if (sw == 7)
            printf("Æâ");
        else if (sw == 8)
            printf("°Æ");
        else if (sw == 9)
            printf("¾Á");
        printf("Ê°Íò");
    }
    if (qw != 0 && bw != 0 && sw == 0 && w != 0) {  //**0* 12
        if (qw == 1)
            printf("Ò¼");
        else if (qw == 2)
            printf("·¡");
        else if (qw == 3)
            printf("Èþ");
        else if (qw == 4)
            printf("ËÁ");
        else if (qw == 5)
            printf("Îé");
        else if (qw == 6)
            printf("Â½");
        else if (qw == 7)
            printf("Æâ");
        else if (qw == 8)
            printf("°Æ");
        else if (qw == 9)
            printf("¾Á");
        printf("Çª");
        if (bw == 1)
            printf("Ò¼");
        else if (bw == 2)
            printf("·¡");
        else if (bw == 3)
            printf("Èþ");
        else if (bw == 4)
            printf("ËÁ");
        else if (bw == 5)
            printf("Îé");
        else if (bw == 6)
            printf("Â½");
        else if (bw == 7)
            printf("Æâ");
        else if (bw == 8)
            printf("°Æ");
        else if (bw == 9)
            printf("¾Á");
        printf("°ÛÁã");
        if (w == 1)
            printf("Ò¼");
        else if (w == 2)
            printf("·¡");
        else if (w == 3)
            printf("Èþ");
        else if (w == 4)
            printf("ËÁ");
        else if (w == 5)
            printf("Îé");
        else if (w == 6)
            printf("Â½");
        else if (w == 7)
            printf("Æâ");
        else if (w == 8)
            printf("°Æ");
        else if (w == 9)
            printf("¾Á");
        printf("Íò");
    }
    if (qw != 0 && bw == 0 && sw != 0 && w != 0) {  //*0** 13
        if (qw == 1)
            printf("Ò¼");
        else if (qw == 2)
            printf("·¡");
        else if (qw == 3)
            printf("Èþ");
        else if (qw == 4)
            printf("ËÁ");
        else if (qw == 5)
            printf("Îé");
        else if (qw == 6)
            printf("Â½");
        else if (qw == 7)
            printf("Æâ");
        else if (qw == 8)
            printf("°Æ");
        else if (qw == 9)
            printf("¾Á");
        printf("ÇªÁã");
        if (sw == 1)
            printf("Ò¼");
        else if (sw == 2)
            printf("·¡");
        else if (sw == 3)
            printf("Èþ");
        else if (sw == 4)
            printf("ËÁ");
        else if (sw == 5)
            printf("Îé");
        else if (sw == 6)
            printf("Â½");
        else if (sw == 7)
            printf("Æâ");
        else if (sw == 8)
            printf("°Æ");
        else if (sw == 9)
            printf("¾Á");
        printf("Ê°");
        if (w == 1)
            printf("Ò¼");
        else if (w == 2)
            printf("·¡");
        else if (w == 3)
            printf("Èþ");
        else if (w == 4)
            printf("ËÁ");
        else if (w == 5)
            printf("Îé");
        else if (w == 6)
            printf("Â½");
        else if (w == 7)
            printf("Æâ");
        else if (w == 8)
            printf("°Æ");
        else if (w == 9)
            printf("¾Á");
        printf("Íò");
    }
    if (qw == 0 && bw != 0 && sw != 0 && w != 0) {  //0*** 14
        if (sy != 0 || y != 0)
            printf("Áã");
        if (bw == 1)
            printf("Ò¼");
        else if (bw == 2)
            printf("·¡");
        else if (bw == 3)
            printf("Èþ");
        else if (bw == 4)
            printf("ËÁ");
        else if (bw == 5)
            printf("Îé");
        else if (bw == 6)
            printf("Â½");
        else if (bw == 7)
            printf("Æâ");
        else if (bw == 8)
            printf("°Æ");
        else if (bw == 9)
            printf("¾Á");
        printf("°Û");
        if (sw == 1)
            printf("Ò¼");
        else if (sw == 2)
            printf("·¡");
        else if (sw == 3)
            printf("Èþ");
        else if (sw == 4)
            printf("ËÁ");
        else if (sw == 5)
            printf("Îé");
        else if (sw == 6)
            printf("Â½");
        else if (sw == 7)
            printf("Æâ");
        else if (sw == 8)
            printf("°Æ");
        else if (sw == 9)
            printf("¾Á");
        printf("Ê°");
        if (w == 1)
            printf("Ò¼");
        else if (w == 2)
            printf("·¡");
        else if (w == 3)
            printf("Èþ");
        else if (w == 4)
            printf("ËÁ");
        else if (w == 5)
            printf("Îé");
        else if (w == 6)
            printf("Â½");
        else if (w == 7)
            printf("Æâ");
        else if (w == 8)
            printf("°Æ");
        else if (w == 9)
            printf("¾Á");
        printf("Íò");
    }
    if (qw != 0 && bw != 0 && sw != 0 && w != 0) {  //**** 15
        if (qw == 1)
            printf("Ò¼");
        else if (qw == 2)
            printf("·¡");
        else if (qw == 3)
            printf("Èþ");
        else if (qw == 4)
            printf("ËÁ");
        else if (qw == 5)
            printf("Îé");
        else if (qw == 6)
            printf("Â½");
        else if (qw == 7)
            printf("Æâ");
        else if (qw == 8)
            printf("°Æ");
        else if (qw == 9)
            printf("¾Á");
        printf("Çª");
        if (bw == 1)
            printf("Ò¼");
        else if (bw == 2)
            printf("·¡");
        else if (bw == 3)
            printf("Èþ");
        else if (bw == 4)
            printf("ËÁ");
        else if (bw == 5)
            printf("Îé");
        else if (bw == 6)
            printf("Â½");
        else if (bw == 7)
            printf("Æâ");
        else if (bw == 8)
            printf("°Æ");
        else if (bw == 9)
            printf("¾Á");
        printf("°Û");
        if (sw == 1)
            printf("Ò¼");
        else if (sw == 2)
            printf("·¡");
        else if (sw == 3)
            printf("Èþ");
        else if (sw == 4)
            printf("ËÁ");
        else if (sw == 5)
            printf("Îé");
        else if (sw == 6)
            printf("Â½");
        else if (sw == 7)
            printf("Æâ");
        else if (sw == 8)
            printf("°Æ");
        else if (sw == 9)
            printf("¾Á");
        printf("Ê°");
        if (w == 1)
            printf("Ò¼");
        else if (w == 2)
            printf("·¡");
        else if (w == 3)
            printf("Èþ");
        else if (w == 4)
            printf("ËÁ");
        else if (w == 5)
            printf("Îé");
        else if (w == 6)
            printf("Â½");
        else if (w == 7)
            printf("Æâ");
        else if (w == 8)
            printf("°Æ");
        else if (w == 9)
            printf("¾Á");
        printf("Íò");
    }





    //Íò½áÊø ¿ªÊ¼Ç§
    if (q != 0 && b != 0 && s != 0 && g != 0) {  //**** 15
        if (q == 1)
            printf("Ò¼");
        else if (q == 2)
            printf("·¡");
        else if (q == 3)
            printf("Èþ");
        else if (q == 4)
            printf("ËÁ");
        else if (q == 5)
            printf("Îé");
        else if (q == 6)
            printf("Â½");
        else if (q == 7)
            printf("Æâ");
        else if (q == 8)
            printf("°Æ");
        else if (q == 9)
            printf("¾Á");
        printf("Çª");
        if (b == 1)
            printf("Ò¼");
        else if (b == 2)
            printf("·¡");
        else if (b == 3)
            printf("Èþ");
        else if (b == 4)
            printf("ËÁ");
        else if (b == 5)
            printf("Îé");
        else if (b == 6)
            printf("Â½");
        else if (b == 7)
            printf("Æâ");
        else if (b == 8)
            printf("°Æ");
        else if (b == 9)
            printf("¾Á");
        printf("°Û");
        if (s == 1)
            printf("Ò¼");
        else if (s == 2)
            printf("·¡");
        else if (s == 3)
            printf("Èþ");
        else if (s == 4)
            printf("ËÁ");
        else if (s == 5)
            printf("Îé");
        else if (s == 6)
            printf("Â½");
        else if (s == 7)
            printf("Æâ");
        else if (s == 8)
            printf("°Æ");
        else if (s == 9)
            printf("¾Á");
        printf("Ê°");
        if (g == 1)
            printf("Ò¼");
        else if (g == 2)
            printf("·¡");
        else if (g == 3)
            printf("Èþ");
        else if (g == 4)
            printf("ËÁ");
        else if (g == 5)
            printf("Îé");
        else if (g == 6)
            printf("Â½");
        else if (g == 7)
            printf("Æâ");
        else if (g == 8)
            printf("°Æ");
        else if (g == 9)
            printf("¾Á");
    }
    if (q != 0 && b != 0 && s != 0 && g == 0) {  //***0 14
        if (q == 1)
            printf("Ò¼");
        else if (q == 2)
            printf("·¡");
        else if (q == 3)
            printf("Èþ");
        else if (q == 4)
            printf("ËÁ");
        else if (q == 5)
            printf("Îé");
        else if (q == 6)
            printf("Â½");
        else if (q == 7)
            printf("Æâ");
        else if (q == 8)
            printf("°Æ");
        else if (q == 9)
            printf("¾Á");
        printf("Çª");
        if (b == 1)
            printf("Ò¼");
        else if (b == 2)
            printf("·¡");
        else if (b == 3)
            printf("Èþ");
        else if (b == 4)
            printf("ËÁ");
        else if (b == 5)
            printf("Îé");
        else if (b == 6)
            printf("Â½");
        else if (b == 7)
            printf("Æâ");
        else if (b == 8)
            printf("°Æ");
        else if (b == 9)
            printf("¾Á");
        printf("°Û");
        if (s == 1)
            printf("Ò¼");
        else if (s == 2)
            printf("·¡");
        else if (s == 3)
            printf("Èþ");
        else if (s == 4)
            printf("ËÁ");
        else if (s == 5)
            printf("Îé");
        else if (s == 6)
            printf("Â½");
        else if (s == 7)
            printf("Æâ");
        else if (s == 8)
            printf("°Æ");
        else if (s == 9)
            printf("¾Á");
        printf("Ê°");
    }
    if (q != 0 && b != 0 && s == 0 && g == 0) {  //**00 13
        if (q == 1)
            printf("Ò¼");
        else if (q == 2)
            printf("·¡");
        else if (q == 3)
            printf("Èþ");
        else if (q == 4)
            printf("ËÁ");
        else if (q == 5)
            printf("Îé");
        else if (q == 6)
            printf("Â½");
        else if (q == 7)
            printf("Æâ");
        else if (q == 8)
            printf("°Æ");
        else if (q == 9)
            printf("¾Á");
        printf("Çª");
        if (b == 1)
            printf("Ò¼");
        else if (b == 2)
            printf("·¡");
        else if (b == 3)
            printf("Èþ");
        else if (b == 4)
            printf("ËÁ");
        else if (b == 5)
            printf("Îé");
        else if (b == 6)
            printf("Â½");
        else if (b == 7)
            printf("Æâ");
        else if (b == 8)
            printf("°Æ");
        else if (b == 9)
            printf("¾Á");
        printf("°Û");
    }
    if (q != 0 && b == 0 && s == 0 && g == 0) {  //*000 12
        if (q == 1)
            printf("Ò¼");
        else if (q == 2)
            printf("·¡");
        else if (q == 3)
            printf("Èþ");
        else if (q == 4)
            printf("ËÁ");
        else if (q == 5)
            printf("Îé");
        else if (q == 6)
            printf("Â½");
        else if (q == 7)
            printf("Æâ");
        else if (q == 8)
            printf("°Æ");
        else if (q == 9)
            printf("¾Á");
        printf("Çª");
    }
    if (q != 0 && b == 0 && s != 0 && g == 0) {  //*0*0 11
        if (q == 1)
            printf("Ò¼");
        else if (q == 2)
            printf("·¡");
        else if (q == 3)
            printf("Èþ");
        else if (q == 4)
            printf("ËÁ");
        else if (q == 5)
            printf("Îé");
        else if (q == 6)
            printf("Â½");
        else if (q == 7)
            printf("Æâ");
        else if (q == 8)
            printf("°Æ");
        else if (q == 9)
            printf("¾Á");
        printf("ÇªÁã");
        if (s == 1)
            printf("Ò¼");
        else if (s == 2)
            printf("·¡");
        else if (s == 3)
            printf("Èþ");
        else if (s == 4)
            printf("ËÁ");
        else if (s == 5)
            printf("Îé");
        else if (s == 6)
            printf("Â½");
        else if (s == 7)
            printf("Æâ");
        else if (s == 8)
            printf("°Æ");
        else if (s == 9)
            printf("¾Á");
        printf("Ê°");
    }

    if (q != 0 && b != 0 && s == 0 && g != 0) {  //**0* 10
        if (q == 1)
            printf("Ò¼");
        else if (q == 2)
            printf("·¡");
        else if (q == 3)
            printf("Èþ");
        else if (q == 4)
            printf("ËÁ");
        else if (q == 5)
            printf("Îé");
        else if (q == 6)
            printf("Â½");
        else if (q == 7)
            printf("Æâ");
        else if (q == 8)
            printf("°Æ");
        else if (q == 9)
            printf("¾Á");
        printf("Çª");
        if (b == 1)
            printf("Ò¼");
        else if (b == 2)
            printf("·¡");
        else if (b == 3)
            printf("Èþ");
        else if (b == 4)
            printf("ËÁ");
        else if (b == 5)
            printf("Îé");
        else if (b == 6)
            printf("Â½");
        else if (b == 7)
            printf("Æâ");
        else if (b == 8)
            printf("°Æ");
        else if (b == 9)
            printf("¾Á");
        printf("°ÛÁã");
        if (g == 1)
            printf("Ò¼");
        else if (g == 2)
            printf("·¡");
        else if (g == 3)
            printf("Èþ");
        else if (g == 4)
            printf("ËÁ");
        else if (g == 5)
            printf("Îé");
        else if (g == 6)
            printf("Â½");
        else if (g == 7)
            printf("Æâ");
        else if (g == 8)
            printf("°Æ");
        else if (g == 9)
            printf("¾Á");
    }

    if (q != 0 && b == 0 && s != 0 && g != 0) {  //*0** 9
        if (q == 1)
            printf("Ò¼");
        else if (q == 2)
            printf("·¡");
        else if (q == 3)
            printf("Èþ");
        else if (q == 4)
            printf("ËÁ");
        else if (q == 5)
            printf("Îé");
        else if (q == 6)
            printf("Â½");
        else if (q == 7)
            printf("Æâ");
        else if (q == 8)
            printf("°Æ");
        else if (q == 9)
            printf("¾Á");
        printf("ÇªÁã");
        if (s == 1)
            printf("Ò¼");
        else if (s == 2)
            printf("·¡");
        else if (s == 3)
            printf("Èþ");
        else if (s == 4)
            printf("ËÁ");
        else if (s == 5)
            printf("Îé");
        else if (s == 6)
            printf("Â½");
        else if (s == 7)
            printf("Æâ");
        else if (s == 8)
            printf("°Æ");
        else if (s == 9)
            printf("¾Á");
        printf("Ê°");
        if (g == 1)
            printf("Ò¼");
        else if (g == 2)
            printf("·¡");
        else if (g == 3)
            printf("Èþ");
        else if (g == 4)
            printf("ËÁ");
        else if (g == 5)
            printf("Îé");
        else if (g == 6)
            printf("Â½");
        else if (g == 7)
            printf("Æâ");
        else if (g == 8)
            printf("°Æ");
        else if (g == 9)
            printf("¾Á");
    }
    if (q == 0 && b != 0 && s != 0 && g != 0) {  //0*** 8
        if (sy != 0 || y != 0 || qw != 0 || sw != 0 || bw != 0 || w != 0)
            printf("Áã");
        if (b == 1)
            printf("Ò¼");
        else if (b == 2)
            printf("·¡");
        else if (b == 3)
            printf("Èþ");
        else if (b == 4)
            printf("ËÁ");
        else if (b == 5)
            printf("Îé");
        else if (b == 6)
            printf("Â½");
        else if (b == 7)
            printf("Æâ");
        else if (b == 8)
            printf("°Æ");
        else if (b == 9)
            printf("¾Á");
        printf("°Û");
        if (s == 1)
            printf("Ò¼");
        else if (s == 2)
            printf("·¡");
        else if (s == 3)
            printf("Èþ");
        else if (s == 4)
            printf("ËÁ");
        else if (s == 5)
            printf("Îé");
        else if (s == 6)
            printf("Â½");
        else if (s == 7)
            printf("Æâ");
        else if (s == 8)
            printf("°Æ");
        else if (s == 9)
            printf("¾Á");
        printf("Ê°");
        if (g == 1)
            printf("Ò¼");
        else if (g == 2)
            printf("·¡");
        else if (g == 3)
            printf("Èþ");
        else if (g == 4)
            printf("ËÁ");
        else if (g == 5)
            printf("Îé");
        else if (g == 6)
            printf("Â½");
        else if (g == 7)
            printf("Æâ");
        else if (g == 8)
            printf("°Æ");
        else if (g == 9)
            printf("¾Á");
    }
    if (q != 0 && b == 0 && s == 0 && g != 0) {  //*00* 7
        if (q == 1)
            printf("Ò¼");
        else if (q == 2)
            printf("·¡");
        else if (q == 3)
            printf("Èþ");
        else if (q == 4)
            printf("ËÁ");
        else if (q == 5)
            printf("Îé");
        else if (q == 6)
            printf("Â½");
        else if (q == 7)
            printf("Æâ");
        else if (q == 8)
            printf("°Æ");
        else if (q == 9)
            printf("¾Á");
        printf("ÇªÁã");
        if (g == 1)
            printf("Ò¼");
        else if (g == 2)
            printf("·¡");
        else if (g == 3)
            printf("Èþ");
        else if (g == 4)
            printf("ËÁ");
        else if (g == 5)
            printf("Îé");
        else if (g == 6)
            printf("Â½");
        else if (g == 7)
            printf("Æâ");
        else if (g == 8)
            printf("°Æ");
        else if (g == 9)
            printf("¾Á");
    }
    if (q == 0 && b == 0 && s == 0 && g != 0) {  //000* 6
        if (sy != 0 || y != 0 || qw != 0 || sw != 0 || bw != 0 || w != 0)
            printf("Áã");
        if (g == 1)
            printf("Ò¼");
        else if (g == 2)
            printf("·¡");
        else if (g == 3)
            printf("Èþ");
        else if (g == 4)
            printf("ËÁ");
        else if (g == 5)
            printf("Îé");
        else if (g == 6)
            printf("Â½");
        else if (g == 7)
            printf("Æâ");
        else if (g == 8)
            printf("°Æ");
        else if (g == 9)
            printf("¾Á");
    }
    if (q == 0 && b != 0 && s != 0 && g == 0) {  //0**0 5
        if (sy != 0 || y != 0 || qw != 0 || sw != 0 || bw != 0 || w != 0)
            printf("Áã");
        if (b == 1)
            printf("Ò¼");
        else if (b == 2)
            printf("·¡");
        else if (b == 3)
            printf("Èþ");
        else if (b == 4)
            printf("ËÁ");
        else if (b == 5)
            printf("Îé");
        else if (b == 6)
            printf("Â½");
        else if (b == 7)
            printf("Æâ");
        else if (b == 8)
            printf("°Æ");
        else if (b == 9)
            printf("¾Á");
        printf("°Û");
        if (s == 1)
            printf("Ò¼");
        else if (s == 2)
            printf("·¡");
        else if (s == 3)
            printf("Èþ");
        else if (s == 4)
            printf("ËÁ");
        else if (s == 5)
            printf("Îé");
        else if (s == 6)
            printf("Â½");
        else if (s == 7)
            printf("Æâ");
        else if (s == 8)
            printf("°Æ");
        else if (s == 9)
            printf("¾Á");
        printf("Ê°");
    }
    if (q == 0 && b != 0 && s == 0 && g == 0) {  //0*00 5
        if (sy != 0 || y != 0 || qw != 0 || sw != 0 || bw != 0 || w != 0)
            printf("Áã");
        if (b == 1)
            printf("Ò¼");
        else if (b == 2)
            printf("·¡");
        else if (b == 3)
            printf("Èþ");
        else if (b == 4)
            printf("ËÁ");
        else if (b == 5)
            printf("Îé");
        else if (b == 6)
            printf("Â½");
        else if (b == 7)
            printf("Æâ");
        else if (b == 8)
            printf("°Æ");
        else if (b == 9)
            printf("¾Á");
        printf("°Û");
    }
    if (q == 0 && b != 0 && s == 0 && g != 0) {  //0*0* 4
        if (sy != 0 || y != 0 || qw != 0 || sw != 0 || bw != 0 || w != 0)
            printf("Áã");
        if (b == 1)
            printf("Ò¼");
        else if (b == 2)
            printf("·¡");
        else if (b == 3)
            printf("Èþ");
        else if (b == 4)
            printf("ËÁ");
        else if (b == 5)
            printf("Îé");
        else if (b == 6)
            printf("Â½");
        else if (b == 7)
            printf("Æâ");
        else if (b == 8)
            printf("°Æ");
        else if (b == 9)
            printf("¾Á");
        printf("°ÛÁã");
        if (g == 1)
            printf("Ò¼");
        else if (g == 2)
            printf("·¡");
        else if (g == 3)
            printf("Èþ");
        else if (g == 4)
            printf("ËÁ");
        else if (g == 5)
            printf("Îé");
        else if (g == 6)
            printf("Â½");
        else if (g == 7)
            printf("Æâ");
        else if (g == 8)
            printf("°Æ");
        else if (g == 9)
            printf("¾Á");
    }
    if (q == 0 && b == 0 && s != 0 && g == 0) {  //00*0 2
        if (sy != 0 || y != 0 || qw != 0 || sw != 0 || bw != 0 || w != 0)
            printf("Áã");
        if (s == 1)
            printf("Ò¼");
        else if (s == 2)
            printf("·¡");
        else if (s == 3)
            printf("Èþ");
        else if (s == 4)
            printf("ËÁ");
        else if (s == 5)
            printf("Îé");
        else if (s == 6)
            printf("Â½");
        else if (s == 7)
            printf("Æâ");
        else if (s == 8)
            printf("°Æ");
        else if (s == 9)
            printf("¾Á");
        printf("Ê°");
    }
    if (q == 0 && b == 0 && s != 0 && g != 0) {  //00** 1
        if (sy != 0 || y != 0 || qw != 0 || sw != 0 || bw != 0 || w != 0)
            printf("Áã");
        if (s == 1)
            printf("Ò¼");
        else if (s == 2)
            printf("·¡");
        else if (s == 3)
            printf("Èþ");
        else if (s == 4)
            printf("ËÁ");
        else if (s == 5)
            printf("Îé");
        else if (s == 6)
            printf("Â½");
        else if (s == 7)
            printf("Æâ");
        else if (s == 8)
            printf("°Æ");
        else if (s == 9)
            printf("¾Á");
        printf("Ê°");
        if (g == 1)
            printf("Ò¼");
        else if (g == 2)
            printf("·¡");
        else if (g == 3)
            printf("Èþ");
        else if (g == 4)
            printf("ËÁ");
        else if (g == 5)
            printf("Îé");
        else if (g == 6)
            printf("Â½");
        else if (g == 7)
            printf("Æâ");
        else if (g == 8)
            printf("°Æ");
        else if (g == 9)
            printf("¾Á");
    }

    if (!sy && !y && !qw && !bw && !w && !sw && !q && !b && !s && !g && !j && !f)
        printf("ÁãÔ²");


    //Ç§½áÊø£¬½Ç·Ö¿ªÊ¼
    if (sy != 0 || y != 0 || qw != 0 || sw != 0 || bw != 0 || w != 0 || q != 0 || b != 0 || s != 0 || g != 0) {
        printf("Ô²");
    }
    if (sy && y && qw && bw && w && sw && q && b && s && g && j == 0 && f != 0)
        printf("Áã");
    if (j == 1)
        printf("Ò¼½Ç");
    else if (j == 2)
        printf("·¡½Ç");
    else if (j == 3)
        printf("Èþ½Ç");
    else if (j == 4)
        printf("ËÁ½Ç");
    else if (j == 5)
        printf("Îé½Ç");
    else if (j == 6)
        printf("Â½½Ç");
    else if (j == 7)
        printf("Æâ½Ç");
    else if (j == 8)
        printf("°Æ½Ç");
    else if (j == 9)
        printf("¾Á½Ç");
    else if (j == 0) {
        if (f == 1)
            printf("Ò¼·Ö");
        else if (f == 2)
            printf("·¡·Ö");
        else if (f == 3)
            printf("Èþ·Ö");
        else if (f == 4)
            printf("ËÁ·Ö");
        else if (f == 5)
            printf("Îé·Ö");
        else if (f == 6)
            printf("Â½·Ö");
        else if (f == 7)
            printf("Æâ·Ö");
        else if (f == 8)
            printf("°Æ·Ö");
        else if (f == 9)
            printf("¾Á·Ö");
        else if (f == 0)
            printf("Õû");
    }

    if (f == 1 && j != 0)
        printf("Ò¼·Ö");
    else if (f == 2 && j != 0)
        printf("·¡·Ö");
    else if (f == 3 && j != 0)
        printf("Èþ·Ö");
    else if (f == 4 && j != 0)
        printf("ËÁ·Ö");
    else if (f == 5 && j != 0)
        printf("Îé·Ö");
    else if (f == 6 && j != 0)
        printf("Â½·Ö");
    else if (f == 7 && j != 0)
        printf("Æâ·Ö");
    else if (f == 8 && j != 0)
        printf("°Æ·Ö");
    else if (f == 9 && j != 0)
        printf("¾Á·Ö");
    else if (f == 0 && j != 0)
        printf("Õû");

    return 0;
}
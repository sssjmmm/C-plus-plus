/*2151299 信16 苏家铭*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
 int main() 
{
	double a, b, c, d, e, f, g, h, i, j, k;
	int x;
	printf( "请输入找零值：\n");
	scanf("%lf", &a);
	b = (int)(a / 50);
	c = (int)((a - b * 50) / 20);
	d = (int)((a - b * 50 - c * 20) / 10);
	e = (int)((a - b * 50 - c * 20 - d * 10) / 5);
	f = (int)((a - b * 50 - c * 20 - d * 10 - e * 5) / 1);
	g = (int)((a - b * 50 - c * 20 - d * 10 - e * 5 - f * 1) / 0.5);
	h = (int)((a - b * 50 - c * 20 - d * 10 - e * 5 - f * 1 - g * 0.5) / 0.1);
	i = (int)((a - b * 50 - c * 20 - d * 10 - e * 5 - f * 1 - g * 0.5 - h * 0.1) / 0.05);
	j = (int)((a - b * 50 - c * 20 - d * 10 - e * 5 - f * 1 - g * 0.5 - h * 0.1 - i * 0.05) / 0.02);
	k = (int)((a - b * 50 - c * 20 - d * 10 - e * 5 - f * 1 - g * 0.5 - h * 0.1 - i * 0.05 - j * 0.02) / 0.01);
	x = b + c + d + e + f + g + h + i + j + k;
	printf("共%d张找零，具体如下：\n",x);
	if (b)
		printf("50元 : %d张\n" , (int)b);
	if (c)
		printf("20元 : %d张\n" , (int)c);
	if (d)
		printf("10元 : %d张\n" , (int)d);
	if (e)
		printf("5元  : %d张\n" , (int)e);
	if (f)
		printf("1元  : %d张\n" , (int)f);
	if (g)
		printf("5角  : %d张\n" , (int)g);
	if (h)
		printf("1角  : %d张\n" , (int)h);
	if (i)
		printf("5分  : %d张\n" , (int)i);
	if (j)
		printf("2分  : %d张\n" , (int)j);
	if (k)
		printf("1分  : %d张\n" , (int)k);

	return 0;
}

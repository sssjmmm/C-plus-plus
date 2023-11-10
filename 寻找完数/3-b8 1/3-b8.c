/* пе16 2151299 ку╪рцЗ*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
int main() {
	int a, i, sum,k;
	for (a = 2; a <= 1000; a++) {
		sum = 0;
		for (i = 1; i <= a/2; i++) {
			if (a % i == 0) 
				sum = sum + i;	
		}
		if (sum == a) {
			printf("%d,its factors are 1", a);
			for (k = 2; k <= a / 2; k++)
			{
				if (a % k == 0)
				{
					printf(",%d", k);
				}
			}
			printf("\n");
		}
	}
	return 0;
}



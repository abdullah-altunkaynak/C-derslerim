#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//3x^2  3x +10


void denklem()
{
	char p1[20], p2[20], p3[20],denklem[50];
	char *ayirici;
	char bulucu;
	int denklemlenght, a, b, c, delta, i, x1, x2;
	printf("Denklemi +'si ve -'si ile eksiksiz giriniz lütfen:");
	gets(denklem);
	denklemlenght = strlen(denklem);
	puts(denklem);
	ayirici = strtok(denklem," ");
	strcpy(p1,ayirici);
	printf("%s \n",p1);
	ayirici = strtok((char *)NULL, " ");
	strcpy(p2,ayirici);
	printf("%s \n",p2);
	ayirici = strtok((char *)NULL, " ");
	strcpy(p3,ayirici);
	printf("%s \n",p3);
    a = atoi(p1);
    b = atoi(p2);
    c = atoi(p3);
	delta = pow(b, 2) - 4 * a * c;
	printf("%d",a);
	if(delta > 0)
	{
		x1 = (-b + sqrt(delta)) / (2 * a);
		x2 = (-b - sqrt(delta)) / (2 * a);
		printf("\nDenklemin iki farklý kökü vardýr x1 = %d, x2 = %d", x1, x2);
	}
	else if(delta == 0)
	{
		x1 = -b / (2 * a);
		printf("\nDenklemin çakýþýk iki kökü vardýr x1 = x2 = %d", x1);
	}
	else
		printf("\nDenklemin reel kökü yoktur");
}

int main()
{
	setlocale(LC_ALL ,"Turkish");
	denklem();	
}

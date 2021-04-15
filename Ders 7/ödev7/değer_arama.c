#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int ara(int aranan,int *dizi)
{
	int i;
	for(i = 0; i < 10; i++)
	{
		if(*dizi == aranan)
			return 1;
		dizi++;	
	}
	return 0;	
}
void main()
{
	int dizi[10] = {3,7,8,1,9,6,2,4,5,0}; int a;
	setlocale(LC_ALL, "Turkish");
	a = ara(12,dizi);
	printf("Fonksiyon Geridönüþ Deðeri: %d", a);
}

#include <stdio.h>
#include <locale.h>
#include <math.h> // sqrt() için .
#include <stdlib.h>

typedef void (*fonksiyonlar) (int);
int *i;

void asal_mi(int a)
{
	int i, j;
	for(i = 2; i <= a; i++)
	{
		if(a % i == 0 && a != i)
		{
			printf("%d sayýsý asal bir sayý deðildir\n", a);
			break;	
		}
		else if(a == i)
		{
			printf("%d sayýsý asal bir sayýdýr\n ", a);	
		}	
	}
}

void karesi(int a)
{
	printf("%d sayýsýnýn karesi = %d\n", a, (a*a));
}

void karekoku(int a)
{
	printf("%d sayýsýnýn kare kökü = %d\n", a, sqrt(a));
}

void cift_tek(int a)
{
	if( a % 2 == 0)
	{
		printf("%d sayýsý çift bir sayýdýr. \n", a);
	}
	else
    {
    	printf("%d sayýsý tek bir sayýdýr. \n", a);
	} 
}

void main()
{
	int secilen, x;
	setlocale(LC_ALL, "Turkish");
	i = (int*)malloc(sizeof(int));
	fonksiyonlar islemler[4] = {asal_mi , karesi , karekoku , cift_tek};
	while(secilen != 5)
	{
		printf("Ýþleme Tabii Tutmak Ýstediðiniz Sayýyý Giriniz: ");
		scanf("%d", &x);
		printf("ASAL BULMA[1]\nKARESÝNÝ ALMA[2]\nKAREKÖKÜNÜ ALMA[3]\nÇÝFT MÝ TEK MÝ OLDUÐUNU BULMA[4]\nÇIKIÞ[5]\n Seçiminiz: \n");
		scanf("%d", &secilen);
		switch(secilen)
		{
			case 1:
				islemler[0](x);
				break;
			case 2:
				islemler[1](x);
				break;
			case 3:
				islemler[2](x);
				break;
			case 4:
				islemler[3](x);
				break;
			case 5:
				printf("Çýkýþ Yapýlýyor.. \n");
				break;
			default:
				printf("yanlýþ seçim ! \n");
				break;			
		}
	}
}







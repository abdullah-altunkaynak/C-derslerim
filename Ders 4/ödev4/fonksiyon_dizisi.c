#include <stdio.h>
#include <locale.h>
#include <math.h> // sqrt() i�in .
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
			printf("%d say�s� asal bir say� de�ildir\n", a);
			break;	
		}
		else if(a == i)
		{
			printf("%d say�s� asal bir say�d�r\n ", a);	
		}	
	}
}

void karesi(int a)
{
	printf("%d say�s�n�n karesi = %d\n", a, (a*a));
}

void karekoku(int a)
{
	printf("%d say�s�n�n kare k�k� = %d\n", a, sqrt(a));
}

void cift_tek(int a)
{
	if( a % 2 == 0)
	{
		printf("%d say�s� �ift bir say�d�r. \n", a);
	}
	else
    {
    	printf("%d say�s� tek bir say�d�r. \n", a);
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
		printf("��leme Tabii Tutmak �stedi�iniz Say�y� Giriniz: ");
		scanf("%d", &x);
		printf("ASAL BULMA[1]\nKARES�N� ALMA[2]\nKAREK�K�N� ALMA[3]\n��FT M� TEK M� OLDU�UNU BULMA[4]\n�IKI�[5]\n Se�iminiz: \n");
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
				printf("��k�� Yap�l�yor.. \n");
				break;
			default:
				printf("yanl�� se�im ! \n");
				break;			
		}
	}
}







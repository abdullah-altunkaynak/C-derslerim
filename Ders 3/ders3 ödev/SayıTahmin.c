#include <stdio.h>
#include <locale.h>
#include <stdlib.h> // rand() fonksiyonunu kullanabilmek i�in stdlib k�t�phanesi gereklidir.
#include <time.h> // srand(time(NULL)); deyimini kullanmak i�in bu k�t�phaneyi ekledik.

void main()
{
	int rastgele = 0;
	int tahmin = 0;
	int deneme = 0;
	setlocale(LC_ALL, "Turkish");
	srand(time(NULL)); 
	rastgele = rand()%100;
	printf("Merhaba..\nAkl�mdan 0 ile 100 Aras�nda Bir Say� Tuttum\n 10 Hakk�n Var\n Ka� Tuttum Hadi Tahmin Et ?!..\n");
	scanf("%d", &tahmin);
	while(tahmin != rastgele && deneme < 10)
	{
		if(tahmin < rastgele)
		{
			printf("Daha B�y�k Bir Say� S�yle");
			scanf("%d", &tahmin);
			deneme++;
		}
		else if(tahmin > rastgele && tahmin < 101)
		{
			printf("Daha K���k Bir Say� S�yle");
			scanf("%d", &tahmin);
			deneme++;
		}
		else if(tahmin > 100)
		{
			printf("S�yledi�im aral�ktan ba�ka say� s�yl�yorsun dikkat et");
			scanf("%d", &tahmin);
		}	
	}
	if(deneme == 0)
		printf("Tebrikler �lk Seferde Bildiniz");
	else if(deneme > 0 && deneme < 10)
		printf("Tebrikler %d say�s�n� %d defada bildiniz", rastgele, deneme+1);
	else
		printf("Maalesef bilemediniz TEKRAR DENEY�N�Z!");		
}

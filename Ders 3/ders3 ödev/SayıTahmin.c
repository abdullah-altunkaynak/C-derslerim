#include <stdio.h>
#include <locale.h>
#include <stdlib.h> // rand() fonksiyonunu kullanabilmek için stdlib kütüphanesi gereklidir.
#include <time.h> // srand(time(NULL)); deyimini kullanmak için bu kütüphaneyi ekledik.

void main()
{
	int rastgele = 0;
	int tahmin = 0;
	int deneme = 0;
	setlocale(LC_ALL, "Turkish");
	srand(time(NULL)); 
	rastgele = rand()%100;
	printf("Merhaba..\nAklýmdan 0 ile 100 Arasýnda Bir Sayý Tuttum\n 10 Hakkýn Var\n Kaç Tuttum Hadi Tahmin Et ?!..\n");
	scanf("%d", &tahmin);
	while(tahmin != rastgele && deneme < 10)
	{
		if(tahmin < rastgele)
		{
			printf("Daha Büyük Bir Sayý Söyle");
			scanf("%d", &tahmin);
			deneme++;
		}
		else if(tahmin > rastgele && tahmin < 101)
		{
			printf("Daha Küçük Bir Sayý Söyle");
			scanf("%d", &tahmin);
			deneme++;
		}
		else if(tahmin > 100)
		{
			printf("Söylediðim aralýktan baþka sayý söylüyorsun dikkat et");
			scanf("%d", &tahmin);
		}	
	}
	if(deneme == 0)
		printf("Tebrikler Ýlk Seferde Bildiniz");
	else if(deneme > 0 && deneme < 10)
		printf("Tebrikler %d sayýsýný %d defada bildiniz", rastgele, deneme+1);
	else
		printf("Maalesef bilemediniz TEKRAR DENEYÝNÝZ!");		
}

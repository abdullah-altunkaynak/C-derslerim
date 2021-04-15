#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main()
{
	char *bilgi; char isim; char soyisim; char pasaport;
	int secim; int i = -1; int j = 0;
	setlocale(LC_ALL, "Turkish");
	do
	{
		printf("Ekle[1]\nSil[2]\nDüzelt[3]\nÇýkýþ[4]");
		scanf("%d", &secim);
		switch(secim)
		{
			case 1:
				i++;
				printf("Lütfen Ýsim Giriniz: ");
				scanf("%s",isim);
				bilgi[i][j] = isim;
				j++;
				printf("Lütfen Soyisim Giriniz: ");
				scanf("%c",soyisim);
				bilgi[i][j] = soyisim;
				j++;
				printf("Lütfen pasaport no giriniz: ");
				scanf("%c",pasaport);
				bilgi[i][j] = pasaport;
				printf("iþlemler baþarýlý !");
				break;
			case 2:
			
				break;
			case 3:
			
				break;
			default:
				printf("Seçim Hatalý !!");
				break;
		}
				
	}while(secim != 4);
}

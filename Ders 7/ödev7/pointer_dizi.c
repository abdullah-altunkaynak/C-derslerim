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
		printf("Ekle[1]\nSil[2]\nD�zelt[3]\n��k��[4]");
		scanf("%d", &secim);
		switch(secim)
		{
			case 1:
				i++;
				printf("L�tfen �sim Giriniz: ");
				scanf("%s",isim);
				bilgi[i][j] = isim;
				j++;
				printf("L�tfen Soyisim Giriniz: ");
				scanf("%c",soyisim);
				bilgi[i][j] = soyisim;
				j++;
				printf("L�tfen pasaport no giriniz: ");
				scanf("%c",pasaport);
				bilgi[i][j] = pasaport;
				printf("i�lemler ba�ar�l� !");
				break;
			case 2:
			
				break;
			case 3:
			
				break;
			default:
				printf("Se�im Hatal� !!");
				break;
		}
				
	}while(secim != 4);
}

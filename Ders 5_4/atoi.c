#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//*atoi(const char *k1) -> k1 katarý içerisindeki rakamsal karakter olan noktadan baþlayarak içermeyen noktaya veya NULL ile karþýlaþana kadar okur ve geriye int tipinde dönderir.

int cevirici(char *katar)
{
	int n = 0; int deger = 0; int k = 0; int j = 1; char x;
	while(*(katar + n) != '\0')
	{		
		if(isdigit(*(katar + n)))
			deger = deger * 10 + (katar[n] - '0');
		else if(deger != 0)
			break;
		n++;	
	}
	return deger;
}

void main()
{
	setlocale(LC_ALL, "Turkish");
	char *katar =(char *)malloc(sizeof(char) * 10);
	int a;
	printf("Dönüþtürmek istediðiniz katarý giriniz: ");
	scanf("%s", katar);
	katar = (char *)realloc(katar, sizeof(char) * strlen(katar));
	a = cevirici(katar);
	printf("%s Katarý --> %d biçimine çevirildi", katar, a);
	free(katar);
}

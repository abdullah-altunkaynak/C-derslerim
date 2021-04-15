#include <stdio.h>
#include <locale.h>


void main()
{
	int ilk, ikinci, sonuc;
	int a;
	setlocale(LC_ALL, "Turkish");
	printf("Ýki Adet Sayý Giriniz: ");
	scanf("%d %d", &ilk, &ikinci);
	printf("Ýþlem seçeneðini giriniz: ");
	a = getch();// getch deðil.
	printf("%c \n",a);
	switch(a)
	{
		case 43:
			sonuc = ilk + ikinci;
			break;
		case 45:
			sonuc = ilk - ikinci;
			break;
		case 42:
			sonuc = ilk * ikinci;
			break;
		case 47:
			sonuc = ilk / ikinci;
			break;
		default:
			printf("Yanlýþ Seçim");
			break;
	}
	printf("%d", sonuc);
}

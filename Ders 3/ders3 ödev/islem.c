#include <stdio.h>
#include <locale.h>


void main()
{
	int ilk, ikinci, sonuc;
	int a;
	setlocale(LC_ALL, "Turkish");
	printf("�ki Adet Say� Giriniz: ");
	scanf("%d %d", &ilk, &ikinci);
	printf("��lem se�ene�ini giriniz: ");
	a = getch();// getch de�il.
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
			printf("Yanl�� Se�im");
			break;
	}
	printf("%d", sonuc);
}

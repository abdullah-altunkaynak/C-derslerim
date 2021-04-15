#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>

void scan(char *str, ...)
{
	int i = 0; int *sayi; int *sayi_1; int j = 0; int katsayi = 1;
	char temp; char *katar; char harf; char *string;
	va_list argumans;
	va_start(argumans,str);
	while(*(str + i) != '\0') // sona kadar d�ner
	{
		if(*(str + i) == '%') // y�zde i�aretini g�rd�k sonras� gelen elemana g�re tip belirecek
		{
			i++;
			temp = *(str + i);
			switch(temp)
			{
				case 'd':
					katar = (char *)malloc(sizeof(char) * 10);
					gets(katar);
					j = strlen(katar) - 1;
					sayi = va_arg(argumans,int *); //va_arg scan("%d", &a)  a n�n adresni geriye d�nderir.
					*sayi = 0;
					while(j != -1)
					{
						if(isdigit(*(katar + j)) != 0)
						{
							*sayi += (*(katar + j) - '0') * katsayi;
							katsayi *= 10;
							j--;
						}
						else
						{
							puts("Hatal� Giri�: integer de�er girmek zorundas�n�z!!");
							*sayi = 0;	
							break;
						}
					}
					free(katar);
					break;
				case 'c':
					harf = getchar();
					katar = va_arg(argumans,char *); //va_arg scan("%d", &a)  a n�n adresni geriye d�nderir.
					*katar = harf;
					break;
				case 's':
					katar = (char *)malloc(sizeof(char) * 50);
					gets(katar);
					katar = (char *)realloc(katar, sizeof(char) * strlen(katar));
					string = va_arg(argumans,char *);
					strcpy(string,katar);
					free(katar);
					break;		
			}
		}
		i++;
	}
}
				
void main()
{
	setlocale(LC_ALL, "Turkish");
	int veri;
	char *katar;
	char harf;
	katar = (char *)malloc(sizeof(char) * 15);
	printf("int deger gir: ");
	scan("%d", &veri);
	printf("%d\n", veri);
	printf("String De�er Gir: ");
	scan("%s", katar);
	printf("%s\n", katar);
	printf("int string harf gir: ");
	scan("%d %s %c", &veri, katar, &harf);
	printf("int-> %d katar-> %s harf->%c", veri, katar, harf);
	
}		

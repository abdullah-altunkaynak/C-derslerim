#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

void main()
{
	setlocale(LC_ALL, "Turkish");
    FILE *tmp;
    char veri[] = "Selamun Aleyk�m";
    int lenght = strlen(veri);
    int iter = 0; int a; 
   
    tmp = tmpfile();
    printf("%s", strerror(errno)); // HATA
    if(tmp != NULL)
    {
    	puts("tmpfile ile tmp olu�turuldu!\n");
    	while(iter < lenght)
		{
		fputc(veri[iter],tmp);	// karakter karakter yazd�rd�k fputc yard�m� ile.
		}
		rewind(tmp);//dosyan�n ba��na getirdik.
		while(!feof(tmp))// dosya sonunda de�ilse'yi kontrol ettik
		{
			putchar(fgetc(tmp));//ekrana yazd�rm�� olduk putchar ile.fgetc ile ald�k.
		}	
	}	
	else
		puts("tmp olu�turulamad�!\n");
}


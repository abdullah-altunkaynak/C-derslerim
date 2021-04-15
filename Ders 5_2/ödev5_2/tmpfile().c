#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

void main()
{
	setlocale(LC_ALL, "Turkish");
    FILE *tmp;
    char veri[] = "Selamun Aleyküm";
    int lenght = strlen(veri);
    int iter = 0; int a; 
   
    tmp = tmpfile();
    printf("%s", strerror(errno)); // HATA
    if(tmp != NULL)
    {
    	puts("tmpfile ile tmp oluþturuldu!\n");
    	while(iter < lenght)
		{
		fputc(veri[iter],tmp);	// karakter karakter yazdýrdýk fputc yardýmý ile.
		}
		rewind(tmp);//dosyanýn baþýna getirdik.
		while(!feof(tmp))// dosya sonunda deðilse'yi kontrol ettik
		{
			putchar(fgetc(tmp));//ekrana yazdýrmýþ olduk putchar ile.fgetc ile aldýk.
		}	
	}	
	else
		puts("tmp oluþturulamadý!\n");
}


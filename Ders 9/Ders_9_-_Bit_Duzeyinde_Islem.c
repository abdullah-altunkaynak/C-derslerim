#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

/*B�T D�ZEY�NDE �ALI�MA:
	C dilinde her bir bit i�in ayr� �zel durumlar oldu�u durumlar olabilmektedir. �rne�in xxxx 4 bitlik de�erde son hane pozitif ve negatif, 3.bit hata var ve yok, 2.bit yine 0 ve 1 lik
bir durum 1. bit de ayn� �ekilde oldu�u durumlar g�zlenebilmektedir. Genellikle micro i�lemci ve mant�ksal durumlara g�re i�lem g�ren entegre ve entegre olmayan sistemler, USB, seri ve
paralel I/O portlar� �zerinde i�lemler ger�ekle�tirmek i�in bit d�zeyinde �al��ma gereklidir. Yine bir �rnek �zerinden konuya deyinelim. C programlama dilinde mant�ksal kontrolleri yani,
true/false i�lemlerini ger�el say� tutan de�i�kenler haricindeki t�m veri tiplerinde sa�layabiliriz. Fakat en az ram de yer kaplayan veri tipi olan char veri tipinde 8 bit vard�r. Bize
tek bit yeterli oldu�u i�in di�er 7 bit bo�una ram de yer kaplamaktad�r. Bit d�zeyinde �al��ma bunun i�in daha performans�ld�r diyemeyiz ��nk�, struct toplulu�unda bildirilen bit
d�zeyinde �al��mak i�in de�i�ken ram de en az bir tamsay�l�k yer kaplamaktad�r.

�DEVLER
	-Klavyeden girilen 8 bitlik bir verinin bitlerindeki 1'lerin adeti �ift mi tek mi olup olmad���n� ekrana yazan program� yaz�n�z.
	-Klavyeden girilen 16 bitlik bir verinin bitlerinin ba��ndaki 1 ise hata var, sonundaki biti 1 ise aksilik yok her ikisi de 1 ise hatal� veri yazan program� yaz�n�z.
*/

typedef struct
{
	unsigned short int val : 1; /*':' karakterinden sonra gelen tam say� de�eri ram de ka� bit yer tutaca��n�n bildirilmesidir.*/ 
}bool;

void stringtolower(char *string)
{
	register int i;
	for(i = 0; i < strlen(string); i++)
		*(string + i) = tolower(*(string + i));
}

int bytetobit(int size)
{
	return size * 8;
}

void main()
{
	setlocale(LC_ALL, "Turkish");
	bool kont; char *string = (char *)malloc(sizeof(char) * 6); int controller = 0;
	printf("bool size: %d byte = %d bit\nYukarda g�r�ld��� gibi biz 1 bit yer ay�rmam�za ra�men 2 byte yer g�steriliyor.\n\n", sizeof(bool), bytetobit(sizeof(bool)));
	getch();
	do
	{
		printf("Mant�ksal ifadeyi giriniz(true/false): ");
		gets(string);
		string = (char *)realloc(string, sizeof(char) * (strlen(string) + 1)); /*+1 sondaki NULL ifadesi i�in*/
		stringtolower(string);
		printf("%s\n", string);
		if(!strcmp(string, "true")) /*strcmp geriye int bir de�er d�nderir. Dolay�s� ile mant�ksal kontrol de false ise 0 anlam�na gelir.*/
		{
			kont.val = 1;
			controller = 1;
		}
		else if(!strcmp(string, "false"))
		{
			kont.val = 0;
			controller = 1;
		}
		else
		{
			free(string);
			string = (char *)malloc(sizeof(char) * 6);
			puts("Yanl�� de�er girildi !\n");
		}
	}while(controller != 1);
	switch(kont.val)
	{
		case 0:
			puts("Mant�ksal ifade FALSE");
			break;
		case 1:
			puts("Mant�ksal ifade TRUE");
			break;
	}
	free(string);
}

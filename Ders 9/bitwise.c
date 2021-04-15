#include <stdio.h>
#include <locale.h>

typedef struct
{
	unsigned char a : 1;
	unsigned char b : 1;
	unsigned char c : 1;
	unsigned char d : 1;
	unsigned char e : 1;
	unsigned char f : 1;
	unsigned char g : 1;
	unsigned char h : 1;
	unsigned char i : 1;
	unsigned char j : 1;
	unsigned char k : 1;
	unsigned char l : 1;
	unsigned char m : 1;
	unsigned char n : 1;
	unsigned char o : 1;
	unsigned char p : 1;
}data;


void main()
{
	setlocale(LC_ALL, "Turkish");
	data veri;
	printf("Veri giriniz: ");
	scanf("%c", &veri);
	if(veri.a == 1)
		puts("hata var");
	else if(veri.p == 0)
		puts("aksilik yok");
	if(veri.a == 1 && veri.p == 1)
		puts("hatalı veri");		
}

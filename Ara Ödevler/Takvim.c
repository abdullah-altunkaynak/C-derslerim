#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <conio.h>


void otuzbir()
{
	int i; int j; int gun = 0;
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 10; j++)
		{
			gun++;
			printf("%d ",gun);
			
		}
		printf("\n");
	}
	printf("31\n\n");
}
void otuz()
{
	int i; int j; int gun = 0;
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 10; j++)
		{
			gun++;
			printf("%d ",gun);
			
		}
		printf("\n");
	}
	printf("\n");
}
void yirmisekiz()
{
	int i; int j; int gun = 0;
	system("color 5");
	printf("KEKEKE");
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 10; j++)
		{
			gun++;
			if(gun == 29)
				break;
			printf("%d ",gun);	
		}
		printf("\n");
	}
	printf("\n");
}

void main()
{
	setlocale(LC_ALL, "Turkish");
	//system("color 4f");
	printf("RENKKKKs");
	//system("color 35");
	printf("Farkl� Renk");
	textcolor(BLUE+BLINK);
    cprintf("textcolor c example with a blue blinking text");
	printf("*****OCAK*****\n");
	otuzbir();
	printf("*****�UBAT*****\n");
	yirmisekiz();
	printf("*****MART*****\n");
	otuzbir();
	printf("*****N�SAN*****\n");
	otuz();
	printf("*****MAYIS*****\n");
	otuzbir();
	printf("*****HAZ�RAN*****\n");
	otuz();
	printf("*****TEMMUZ*****\n");
	otuzbir();
	printf("*****A�USTOS*****\n");
	otuzbir();
	printf("*****EYL�L*****\n");
	otuz();
	printf("*****EK�M*****\n");
	otuzbir();
	printf("*****KASIM*****\n");
	otuz();
	printf("*****ARALIK*****\n");
	otuzbir();
}

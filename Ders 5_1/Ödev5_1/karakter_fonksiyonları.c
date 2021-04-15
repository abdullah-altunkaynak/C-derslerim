#include <stdio.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void karakter()
{
	char kr;
	printf("��leme Tabii Tutmak istedi�iniz Karakteri Giriniz:");
	kr = getch(); // klavyeden girilen tu�u kr i�erisine att�k.
	printf("%c\n",kr); // getch kelimeyi g�stermez biz g�styerdik.
	if(isalnum(kr)) // (a-z, A-Z, 0-9) mu kontrol� !
	{
		printf("%c -> Alfa Say�sal Bir Karakterdir\n",kr);
		if(isalpha(kr))
		{
			printf("Girilen De�er Harftir\n");
			if(islower(kr)) // K���k harf mi ?
			{
				printf("Girilen karakter %c k���k harftir\n",kr);
				printf("Harf toupper sayesinde b�y�t�ld� -> %c\n",toupper(kr));
			}
			if(isupper(kr)) // B�y�k Harf mi ?
			{
				printf("Girilen karakter %c b�y�k harftir\n",kr);
				printf("Harf tolower sayesinde k���lt�ld� -> %c\n",tolower(kr));
			}
		}
		else
		{
			printf("Girilen De�er Say�sald�r\n");
			if(isdigit(kr)) // 0-9 aras�nda bir rakam m� ?
				printf("0-9 Aras�nda Ondal�k Bir Rakam !\n");
			else
				printf("0-9 Aras�nda Ondal�k Bir Rakam De�il !\n");
			if(isxdigit(kr)) // 16'l�k tabanda bir say� m� ?
				printf("0-9 A-F Aras�nda Onalt�l�k Bir Rakam !\n");
			else
				printf("0-9 A-F Aras�nda Onalt�l�k Bir Rakam De�il !\n");
		}
	} 
	else
	{
		puts("Alfasay�sal Bir Karakter De�ildir !\n");
		if(ispunct(kr)) //Noktalama ��areti mi ?
			printf("Noktalama ��aretidir !\n");
		else
			printf("Noktalama ��areti De�ildir !\n");
	}
	if(isascii(kr))
	{
		puts("Ascii Koddur!\n");
		if(iscntrl(kr)) //Kontrol Karakteri mi?
			printf("Kontrol Karakteridir !\n"); 
		else
		{
			if(isspace(kr)) //Bo�luk Karakterleri mi?
				printf("Bo�luk Karakterleridir !\n");
			else
				printf("Bo�luk Karakterleri De�ildir !\n");
		}
		if(isgraph(kr)) //Kontrol Karakteri de�il mi?
			printf(" isgraph ile -> Kontrol Karakteri De�ildir !\n");
	}
	else
		printf("Ascii Karakter De�ildir !\n");
	if(isprint(kr)) // Yaz�labilir karakter mi?
		printf("%c Karakteri -> Yaz�labilen Bir Karakterdir !\n",kr);
	else
		printf("%c Karakteri -> Yaz�lamayan Bir Karakterdir !\n",kr);
}

void isim_soyisim()
{
	char isim[30], soyisim[30];
	char isim_soyisim[60];
	printf( "�sim : " );
	scanf( "%s", isim);
	printf( "Soy�sim : " );
	scanf( "%s", soyisim);
	strcat( isim_soyisim, isim );
	strcat( isim_soyisim, " " );
	strcat( isim_soyisim, soyisim );
	printf( "Tam �sim: %s\n", isim_soyisim );
}

void keke()
{
	char k1[20];
	char k2[20];
	char *src;
	int i;
	printf("par�alanacak metin: ");
	gets(k1);
	printf("par�alayacak metin: ");
	gets(k2);
	src = strtok(k1,k2);
	i = 1;
	while(src != NULL)
	{
		printf("%d.Par�a: %s\n", i++, src);
		src = strtok((char *)NULL, k2);
	}
}

void parcalama()
{
	char buffer[100];
	char *k1;
	char *k3;
	char *k2;
	int i, buflenght;
	printf("Par�alanacak Metini Giriniz: ");
	gets(buffer);
	buflenght = strlen(buffer);
	k1 = (char *)malloc(sizeof(char) * buflenght);
	strcpy(k1, buffer);
	printf("Par�alama karakterini Giriniz: ");
	gets(buffer);
	buflenght = strlen(buffer);
	k2 = (char *)malloc(buflenght);
	strcpy(k2, buffer);
	k3 = strtok(k1, k2);
	i = 1;
	 while(k3 != NULL)
	{
		printf("%d.Par�a: %s\n", i++, k3);
		k3 = strtok((char *)NULL, k2);
	}
	free(k1);
	free(k2);
	free(k3);
}

int main()
{
	setlocale(LC_ALL, "Turkish");
	//karakter();
	//isim_soyisim();
	//parcalama();
	keke();
}

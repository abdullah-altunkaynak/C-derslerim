#include <stdio.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void karakter()
{
	char kr;
	printf("Ýþleme Tabii Tutmak istediðiniz Karakteri Giriniz:");
	kr = getch(); // klavyeden girilen tuþu kr içerisine attýk.
	printf("%c\n",kr); // getch kelimeyi göstermez biz göstyerdik.
	if(isalnum(kr)) // (a-z, A-Z, 0-9) mu kontrolü !
	{
		printf("%c -> Alfa Sayýsal Bir Karakterdir\n",kr);
		if(isalpha(kr))
		{
			printf("Girilen Deðer Harftir\n");
			if(islower(kr)) // Küçük harf mi ?
			{
				printf("Girilen karakter %c küçük harftir\n",kr);
				printf("Harf toupper sayesinde büyütüldü -> %c\n",toupper(kr));
			}
			if(isupper(kr)) // Büyük Harf mi ?
			{
				printf("Girilen karakter %c büyük harftir\n",kr);
				printf("Harf tolower sayesinde küçültüldü -> %c\n",tolower(kr));
			}
		}
		else
		{
			printf("Girilen Deðer Sayýsaldýr\n");
			if(isdigit(kr)) // 0-9 arasýnda bir rakam mý ?
				printf("0-9 Arasýnda Ondalýk Bir Rakam !\n");
			else
				printf("0-9 Arasýnda Ondalýk Bir Rakam Deðil !\n");
			if(isxdigit(kr)) // 16'lýk tabanda bir sayý mý ?
				printf("0-9 A-F Arasýnda Onaltýlýk Bir Rakam !\n");
			else
				printf("0-9 A-F Arasýnda Onaltýlýk Bir Rakam Deðil !\n");
		}
	} 
	else
	{
		puts("Alfasayýsal Bir Karakter Deðildir !\n");
		if(ispunct(kr)) //Noktalama Ýþareti mi ?
			printf("Noktalama Ýþaretidir !\n");
		else
			printf("Noktalama Ýþareti Deðildir !\n");
	}
	if(isascii(kr))
	{
		puts("Ascii Koddur!\n");
		if(iscntrl(kr)) //Kontrol Karakteri mi?
			printf("Kontrol Karakteridir !\n"); 
		else
		{
			if(isspace(kr)) //Boþluk Karakterleri mi?
				printf("Boþluk Karakterleridir !\n");
			else
				printf("Boþluk Karakterleri Deðildir !\n");
		}
		if(isgraph(kr)) //Kontrol Karakteri deðil mi?
			printf(" isgraph ile -> Kontrol Karakteri Deðildir !\n");
	}
	else
		printf("Ascii Karakter Deðildir !\n");
	if(isprint(kr)) // Yazýlabilir karakter mi?
		printf("%c Karakteri -> Yazýlabilen Bir Karakterdir !\n",kr);
	else
		printf("%c Karakteri -> Yazýlamayan Bir Karakterdir !\n",kr);
}

void isim_soyisim()
{
	char isim[30], soyisim[30];
	char isim_soyisim[60];
	printf( "Ýsim : " );
	scanf( "%s", isim);
	printf( "SoyÝsim : " );
	scanf( "%s", soyisim);
	strcat( isim_soyisim, isim );
	strcat( isim_soyisim, " " );
	strcat( isim_soyisim, soyisim );
	printf( "Tam Ýsim: %s\n", isim_soyisim );
}

void keke()
{
	char k1[20];
	char k2[20];
	char *src;
	int i;
	printf("parçalanacak metin: ");
	gets(k1);
	printf("parçalayacak metin: ");
	gets(k2);
	src = strtok(k1,k2);
	i = 1;
	while(src != NULL)
	{
		printf("%d.Parça: %s\n", i++, src);
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
	printf("Parçalanacak Metini Giriniz: ");
	gets(buffer);
	buflenght = strlen(buffer);
	k1 = (char *)malloc(sizeof(char) * buflenght);
	strcpy(k1, buffer);
	printf("Parçalama karakterini Giriniz: ");
	gets(buffer);
	buflenght = strlen(buffer);
	k2 = (char *)malloc(buflenght);
	strcpy(k2, buffer);
	k3 = strtok(k1, k2);
	i = 1;
	 while(k3 != NULL)
	{
		printf("%d.Parça: %s\n", i++, k3);
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

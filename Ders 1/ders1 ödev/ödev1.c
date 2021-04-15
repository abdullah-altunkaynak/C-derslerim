#include <stdio.h>
#include <locale.h>

int czdn = 25;
void hesap(x)
{
	static int toplam = 0;
	toplam = toplam + x;
	czdn = czdn - x;
}

void main()
{
	int elma = 0, portakal = 0, limon = 0, mandalina = 0, cilek = 0, salatalik = 0, domates = 0, secim = 0;
	setlocale(LC_ALL, "Turkish");
	printf("Manava Hoşgeldin Hakan\n\n Cüzdanındaki toplam para 25 tl ----------> Dilediğin gibi harca\n\n\n");
	
	
	do
	{
		if(czdn > 0)
		{
			printf("Elma(1tl)[1]\nPortakal(2tl)[2]\nLimon(3tl)[3]\nMandalina(2tl)[4]\nÇilek(4tl)[5]\nSalatalık(1tl)[6]\nDomates(1tl)[7]\nÇıkış[8]\n");
			scanf("%d",&secim);
			switch(secim)
			{
				case 1:
					hesap(1);
					elma++;
					break;
				case 2:
					hesap(2);
					portakal++;
					break;
				case 3:
					hesap(3);
					limon++;
					break;
				case 4:
					hesap(2);
					mandalina++;
					break;
				case 5:
					hesap(4);
					cilek++;
					break;
				case 6:
					hesap(1);
					salatalik++;
					break;
				case 7:
					hesap(1);
					domates++;
					break;
				case 8:
					printf("Çıkış yapılıyor...");
					break;
				default:
					printf("seçim yanlış !!");
					break;			
			}
		}
		else
		{
			printf("tüm paranı harcadın maalesef");
			secim = 8;	
		}
	}while(secim != 8);
	printf("Cüzdanında kalan para = %d \n",czdn);
	printf("elmadan %d kg\nportakaldan %d kg\nlimondan %d kg\nmandalinadan %d kg\ncilekden %d kg\nsalataliktan %d kg\ndomatesten %d kg aldınız\n\n",elma,portakal,limon,mandalina,cilek,salatalik,domates);
	printf("Bizi Tercih Ettiğiniz İçin Teşekkür Ederiz \n---------------->Kesene Bereket<-------------------");
}

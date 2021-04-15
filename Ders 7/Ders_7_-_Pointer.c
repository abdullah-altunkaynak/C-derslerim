#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <limits.h>
#include <locale.h>

/*Pointer:
	pointer T�rk�e anlam� ile i�aret�iler ram de de�er yerine adres tutan de�i�kenlerdir. C dilini en etkin ve hala pop�ler k�lan nedenlerden biri de bu pointerlard�r. O halde pointerlar
bir C programc�s�n�n etkin kullanmas� gereken �eylerden biridir. Adreslerin tutulmas� �e�itli �ekilde �ok fazla i�imize yararlar. Dizi tan�mlamas�nda bilindi�i gibi ba�lang�� ta tan�mlama
an�nda boyutu bildirilmesi gerekmektedir ve bu dizi i�levini yitirse veya kullan�lmayan alanlar oldu�u zaman da ram de bo�una yer tutmaktad�r. Bunun i�in pointerlar kullanarak C standart
k�t�phanelerinde bulunan baz� fonksiyonlar i�imizi g�recektir. Buna dinamik bellek y�netimi ismi verilmektedir. Ayn� �ekilde katarlar�n tutulmas�nda da bir�ok avantaj� vard�r. Bir katar�n
boyutu �o�unlukla e�er dizi ile kullan�lacaksa tahmin usul� yap�lacakt�r. Bunun yerine dinamik bellek y�netimi ile istenilen karakter boyutu kadar yer ayr�l�rsa katarlar da daha
performansl� ve etkin bir bi�imde kullan�lacabilecektir. Di�er bir avantaj� ise, bilindi�i gibi fonksiyonlar geriye return deyimi ile de�er d�nderebilir ve sadece tek bir de�er
d�nderebilirler. E�er pointer kullan�larak return edilirse birden fazla bir de�eri de geriye d�nderme �ans�n� bulabiliriz. Dikkat edilmesi gereken pointerlar ram de ayr�lan alan�n
ba�lang�� adresini tutarlar. Genel olarak �zellikleri de �u �ekilde �zetlenebilir.
	-Daha performansl�.
	-Daha h�zl�.
	-Verilere eri�im daha kolay.
	Bildirilirken normal bir de�i�ken bildiriminde de�i�ken isminin �n�ne '*' koyularak bildirilirler. Tip belirtilmesi gerekse de t�m tiplerde bildirilen pointerlar ram de ayn� miktarda
derleyiciye ba�l� yer i�gal eder.
NOT: Normal bir de�i�ken i�in isminin ba��na e�er '&' gelir ise adresini g�sterir. Ayn� �ekilde bir pointer i�in de '&' gelir ise kendi adresini g�stermektedir. Pointerlarda sadece ismi
ile yaz�l�rsa g�sterdi�i adresi, isminin ba��na '*' gelir ise g�sterdi�i adresin de�erini d�ndermektedir.

Pointer Aritmeti�i:
	int *ptr; �rne�i �st�nden bir �rnekleme ile &ptr, ptr ve *ptr i�in aritmetik i�lemleri inceleyece�iz.
	-&ptr: Hi� bir aritmetik i�lem yap�lamaz.
	-ptr: T�m hepsi yap�labilir fakat bu sefer g�sterdi�i adresin tipi kadar sekizli ilerletilir.
	*ptr: Normal bir de�i�ken gibi t�m aritmetik i�lemler yap�labilir fakat dikkat edilmesi gereken '*' operat�r�n�n kapsad��� aland�r. �rne�in *ptr++; adres artt�rd�ktan sonra
	artt�rl�lan adresin de�erini g�sterecektir. G�sterdi�i de�eri artt�rmak i�in (*ptr)++; �eklinde kullan�lmas� gerekmektedir. ++*ptr; �iminde kullanmakta da hi�bir sak�nca yoktur.
 
Pointer Kar��la�t�r�lmas�:
	Yine &ptr, ptr ve *ptr i�in ayr� ayr� konu�mak gerekmektedir.
	-&ptr ve ptr: �kisi de adres g�sterdi�inden �t�r� kar��la�t�rma operat�rlerinin hepsi kullan�lmas�na kar�� ek olarak bilinmesi gereken NULL de�eri. &ptr asla NULL de�erini alamaz
	dolay�s�yla bu sadece ptr i�in ge�erli olmaktad�r. ptr = 5; gibi bilindi�i gibi atama yap�lamaz 0 hari�. 0 stdio.h k�t�phanesi i�erisinde NULL de�erine e�ittir. Bir adres asla 0
	olamaz dolay�s� ile 0 veya NULL olarak kullan�labilir.
	*ptr: Normal de�i�kenler ile ayn� kar��la�t�rma i�lemi yap�l�r.

Dinamik Bellek Y�netimi:
	stdlib.h k�t�phanesi i�erisindeki, malloc, calloc, realloc ve free fonksiyonlar� ile (baz� derleyicilerde farkl� fonksiyonlarda vard�r) yap�l�r. Bu fonksiyonlar�n i�levleri �nceki
derste i�lenmi�ti. program1 fonksiyonu i�erisinde yap�lan �rnek te gerekli yerler a��klanm��t�r.

��aret�i Fonksiyonlar:
	Bu fonksiyonlar da geriye belirtilen tipdeki adresleri d�nderir. Dolay�s� ile bir dizinin adresini d�ndererek asl�nda diziyi geriye d�nderebiliriz.


�DEVLER:
	**-program1() in kay�tlar� istenilen yerden silen program� yaz�n�z.
	**-Kullan�c�dan ald���n�z dizinin elemanlar�n� rastgele �arpan ve geriye yeni bir dizi halinde d�nderen bir program yaz�n�z.
	**-int bir dizi i�in parametre olarak girilen bir de�er bu dizi i�erisinde ise 1, de�ilse 0 d�nderen bir fonksiyon yaz�n�z.
	**-�ki boyutlu pointer dizi kullanarak isim, soyisim, passport_no tutan bir program yaz�n�z.
	
*/

typedef struct
{
	char *passport_no;
	char *name;
	char *surname;
	struct tm *birth_date;
	short int age;
}person;

void program1()
{
	person *p = NULL; /*Ki�ileri tutan de�i�ken.*/
	time_t now = time(NULL); /*�uan ki zaman� saniye cinsinden tutan de�i�ken.*/ time_t bd; /*Do�um tarihini saniye cinsinden tutan de�i�ken.*/ time_t tempt;
	struct tm *temptime;
	int n = 0; /*Kay�t say�s�n� tutan de�i�ken.*/ int selection; int i; int a = 0; int j; int k;
	do
	{
		printf("Ki�i ekle[1]\nSon kayd� sil[2]\nKay�tlar� g�ster[3]\nSil[4]��k��[0]\nSe�im: ");
		selection  = getch() - '0';
		switch(selection)
		{
			case 1:
				n++;
				if(p != NULL)
					p = (person *)realloc(p, sizeof(person) * n);
				else
					p = (person *)malloc(sizeof(person) * n);
				(p + (n - 1))->passport_no = (char *)malloc(sizeof(char) * 11);
				(p + (n - 1))->name = (char *)malloc(sizeof(char) * 50); /*Ge�ici olarak ka� adet karakter girilece�ini bilmedi�imiz i�in 50 girildi.*/
				(p + (n - 1))->surname = (char *)malloc(sizeof(char) * 50);
				printf("Ki�i ekle\nPasaport no: ");
				scanf("%s", (p + (n - 1))->passport_no);
				printf("�sim: ");
				scanf(" ");
				gets((p + (n - 1))->name);
				printf("Soyisim: ");
				scanf(" ");
				gets((p + (n - 1))->surname);
				(p + (n - 1))->name = (char *)realloc((p + (n - 1))->name, sizeof(char) * strlen((p + (n - 1))->name)); /*Bo� alanlar� bo�una yer i�gal etmemesi i�in
				serbest b�rak�l�yor.*/
				(p + (n - 1))->surname = (char *)realloc((p + (n - 1))->surname, sizeof(char) * strlen((p + (n - 1))->surname));
				
				(p + (n - 1))->birth_date = (struct tm *)malloc(sizeof(struct tm));
				(p + (n - 1))->birth_date->tm_hour = (p + (n - 1))->birth_date->tm_isdst = (p + (n - 1))->birth_date->tm_min = (p + (n - 1))->birth_date->tm_sec = 0;
				printf("g�n/ay/y�l format�nda do�um tarihi: ");
				scanf("%d/%d/%d", &((p + (n - 1))->birth_date->tm_mday), &((p + (n - 1))->birth_date->tm_mon), &((p + (n - 1))->birth_date->tm_year));
				(p + (n - 1))->birth_date->tm_year -= 1900; /*Zaman toplulu�u i�erisinde zamanlar -1900 ile tutulur.*/
				bd = mktime((p + (n - 1))->birth_date);
				tempt = difftime(now, bd);
				temptime = (struct tm *)localtime(&tempt);
				(p + (n - 1))->age =  temptime->tm_year - 70;
				
				puts("Ekleme i�lemi ba�ar� ile tamamland� !\n");
				break;
			case 2:
				n--;
				printf("Son kayd� sil\n");
				p = (person *)realloc(p, sizeof(person) * n);
				puts("Son kay�t ba�ar� ile silindi !");
				break;
			case 3:
				printf("Kayd� g�ster\n\n");
				for(i = 0; i < n; i++)
				{
					printf("%d.Kay�t:\nPasaport no: %s\n�sim Soyisim: %s %s\nDo�um tarihi: %d/%d/%d\nYa�: %d\n\n", i + 1, (p + i)->passport_no, (p + i)->name, (p + i)->surname
					, (p + i)->birth_date->tm_mday, (p + i)->birth_date->tm_mon, (p + i)->birth_date->tm_year + 1900, (p + i)->age);
				}
				puts("Kay�tlar ba�ar� ile s�raland� !\n");
				break;
			case 4:
				if(n == 0)
					puts("Eleman Yok");
				else
				{
					char *aranan =(char *)malloc(sizeof(char) * 20);
					printf("Silinecek Eleman ");
					scanf("%s", aranan);
					aranan =(char *)realloc(aranan, sizeof(char) * strlen(aranan));
					while(a != n)
					{
						if(strcmp((p + a)->passport_no, aranan) == 0)
						{
							for(j = a; j < (n - 1) ; j++)
								p[j] = p[j + 1];		
							p = (person *)realloc(p, sizeof(person) * --n);
						}
						a++;
					}
				}	
				break;	
			case 0:
				puts("��k��\n");
				break;
			default:
				puts("Se�im ge�erli de�il tekrar deneyiniz !\n");
				break;
		}
	}while(selection != 0);
	free(p);
}

void main()
{
	setlocale(LC_ALL, "Turkish");
	program1();
}

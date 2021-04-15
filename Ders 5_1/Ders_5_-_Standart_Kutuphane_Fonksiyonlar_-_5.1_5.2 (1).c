#include <stdio.h>
#include <stdlib.h> /*malloc gibi fonksiyonlar� i�eren k�t�phane*/
#include <ctype.h> /*KARAKTERLER �ZER�NDE ��LEM YAPAN K�T�PHANE 1.1*/
#include <string.h> /*KATARLAR �ZER�NDE ��LEM YAPAN K�T�PHANE 2.1*/
#include <locale.h>

/*STANDART K�T�PHANE FONKS�YONLARI:
	C dili dedi�imiz gibi k�t�phanelerden olu�an bir dildir. Dolay�s� ile C de profesyonel yada amat�r bir �ok k�t�phane vard�r ve yaz�lmaya devam edilebilir. Bu da bizim bir program�
farkl� i�letim sistemleri �zerinde �al��t�rmam�z� engeller. Yani biz windows �zerinde �al��t�r�l�p derlenen bir program� linux i�erisinde derleyip �al��t�ramayabiliriz, ��nk�
k�t�phaneler ve derleyiciler farkl�d�r. Bu y�zden standartla�t�rma ad�na ANSI C(American National Standards Institute C) ile belirli standartla�t�rmalar getirilmi�tir. Bu b�l�mde
standart k�t�phaneler ve i�eriklerini, 11 b�l�mde inceleyece�iz.
NOT: B�t�n fonksiyonlar�n �rnekleri main fonksiyonu i�erisinde yukardan a�a�� do�ru vard�r.
NOT: Ge�en b�l�mlerde standart giri� ��k�� fonksiyonlar�n� ara�t�r�lmas�n� �dev olarak istemi�tik bu b�l�mde not olarak 6 adet standart giri�/��k�� fonksiyonlar� vard�r bunlardan
printf ve scanf fonksiyonu esge�ilerek
	puts(parametre) -> Tek bir metinsel parametre al�r, int, float vb gibi parametreler yazd�r�lamazlar. Yani char dizisi veya �ift t�rnak i�erisinde metinsel ifade yazd�r�labilir. Bu
	fonksiyon ile yaz�lan metinsel ifadeden sonra direkt olarak \n yapar ve alt sat�ra ge�ilir.
	gets(parametre) -> Char dizisini parametre olarak kabul eder fakat direkt char kullanarak bir de�i�ken yaz�l�rsa uyar� verir ama hata vermez �nerilmez. Bu char dizisi olarak ald���
	parametrenin i�erisine ekrandan girilen bir metini atar peki bu fonksiyonun scanf fonksiyonundan fark� nedir ? scanf fonksiyonu bo�luk tab ve enter karakterlerini girilen metin
	i�erisine almaz yani bu karakterlerden enter a bas�l�rsa fonksiyon kesin olarak sonlan�r, bo�luk ve taba bas�l�rsa bu karakterlerden sonra yaz�lan hi� bir metin scanf ile okunamaz.
	gets fonksiyonunda ise sadece enter ile sonland�rma yap�l�r bo�luk ve tab karakterleri de bu fonksiyon ile okunur.

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
1-Karakter �zerine ��lem Yapan Fonksiyonlar Ve K�t�phanesi:
	Ad� �zerinde bu b�l�mde karakterler �zerinde i�lem yapan fonksiyonlar� g�rece�iz bunlar i�in kullan�lacak bir adet k�t�phane vard�r. Bu k�t�phane i�erisindeki fonksiyonlar�n tamam�
"MAKRO" fonksiyonlard�r ve karakter k�mesinin i�erisindeki s�n�f�n� belirleyen ve de�i�tirme fonksiyonlar� ikiye ayr�labilirler.
	1.1-<ctype.h>
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*isalnum(); -> ��erisine int parametre al�r bu int ifade ondal�k say� taban�ndaki binary koda denk gelir yani i�erisine char koyarsak kendisi otamatik cast ederek int a �evirir
		yani binary koda �evirir. ��erisine g�nderilen karakterin veya ascii kodun kar��l�k geldi�i karakterin alfasay�sal kod(a-z, A-Z,0-9) ise 0'dan farkl� bir say� de�il ise 0
		d�nderen bir fonksiyondur.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*isalpha(); -> Bu fonksiyonunda parametre g�nderimi isalnum fonksiyonu ile ayn�d�r. Bu fonksiyon girilen karakterin veya binary kodun kar��l�k geldi�i karakterin say�sal de�er
		mi yoksa harf mi kontrol eden fonksiyondur. Harf ise 0'dan farkl� de�er say� ise 0 d�nderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*isascii() -> Di�erleri ile ayn� �ekilde parametre al�r. Bu fonksiyon girilen karakterin veya binary kodun standart ascii(7 bitlik binary kod 0 - 127) kod mu de�il mi
		anla��lmas�	i�indir. Geri d�nen ifade 0'dan farkl� ise ascii kod, 0 ise ascii kod de�il anlam�na gelir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*iscntrl() -> Di�erleri ile ayn� �ekilde parametre al�r. E�er karakter kontrol karakteri ise 0'dan farkl�, kontrol karakteri de�il ise 0 d�nderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*isgraph() -> Di�erleri ile ayn� �ekilde parametre al�r. iscntrl fonksiyonunun tersidir. Yani e�er karakter kontrol karakteri de�il ise 0'dan farkl�, kontrol karakteri ise 0
		d�nderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*isdigit() -> Di�erleri ile ayn� �ekilde parametre al�r. E�er 0-9 ondal�k say� ise 0'dan farkl�, de�il ise 0 d�nderir. (0-9 rakamlar�n�n say�sal kodu 48-57)
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*isxdigit() -> Di�erleri ile ayn� �ekilde parametre al�r. E�er 0-9 ve Aa-Ff aras�nda ise 0'dan farkl� de�il ise 0 d�nderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*islower() ve isupper() -> Di�erleri ile ayn� �ekilde parametre al�r. Girilen karakter veya say�sal kodu girilen karakter k���k harf ise islower i�in 0'dan farkl�, isupper i�in
		0, b�y�k harf ise isupper i�in 0'dan farkl� ve islower i�in 0 d�nderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*isprint() -> Di�erleri ile ayn� �ekilde parametre al�r. E�er karakter yaz�labilen bir karakter ise 0'dan farkl�, de�il ise 0 d�nderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*ispunct() -> Di�erleri ile ayn� �ekilde parametre al�r. E�er karakter noktalama karakteri ise 0'dan farkl�, de�il ise 0 d�nderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*isspace() -> Di�erleri ile ayn� �ekilde parametre al�r. E�er karakter tab(9), yeni sat�r(10), bo�luk(32), sayfa alta(page down 12) ve sayfa �ste(page up 13) ise 0'dan farkl�
		de�il ise 0 d�nderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*toupper() ve tolower() -> Di�erleri ile ayn� �ekilde parametre al�r. De�i�tirme fonksiyonu olarak bahsedilen fonksiyonlard�r. toupper parametre olarak girilen harfi b�y�k
		harfe d�n��t�r�r. tolower ise k���k harfe d�n��t�r�r. Yani toupper geriye parametre olarak g�nderilen harfin b�y�k harfini d�nderir. tolower geriye parametre olarak g�nderilen
		harfin k���k harfini d�nderir.
Abdullah
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
2-Katarlar �zerinde ��lem Yapan Fonksiyonlar Ve K�t�phanesi:
	Katar, NULL('\0') ile sonland�r�lm�� karakter dizisidir. �zerinde i�lem yapan fonksiyonlar (str... ile ba�lar), kopyalama i�lemi yapan fonksiyonlar ve sorgulama i�lemi yapan
fonksiyonlar olmak �zere ikiye ayr�l�r. Kopyalama i�lemi yapan fonksiyonlar genelde karakter i�aret�i d�nderirler. Sorgulama yapan fonksiyonlar ise genelde mant�ksal sonu�(0 veya 1)
d�nderirler.
	Buna ek olarak bellek �zerinde i�lem yapan fonksiyonlar (mem... ile ba�lar) katar �zerine i�lem yapanlara benzer, fakat bunlar NULL ile sonland�r�lmazlar.
NOT: Bir katar di�erine kopyalan�rken yeteri kadar bellek alan� olmad��� durumlarda, hatalar ile kar��la��labilir.
	2.1-<string.h> (char k1[size]; char k2[size]; �zerinden gidilecektir. Pointer bi�imi ile tan�mlanm�� katarlar da bu fonksiyonlara dahildir.)
		*strcat(char k1, const char k2) -> G�r�ld��� �zere bu fonksiyon iki adet parametre al�r ve ikinci parametresi const olarak tan�mlanm��t�r. Bunun sebebi e�er g�rd���m�z call by
		referance �eklinde yani pointer �eklinde bir veri g�nderilir ise de�i�imden korumak i�in const olarak belirlenmi�tir. Bu fonksiyon k1 katar�n�n sonuna(yani NULL olan yerine)
		k2 katar�n� ekler. Geriye d�n�� de�eri k1 katar�n�n ba�lang�� adresidir.(Dizilerde adresleme konusunu s�zel olarak anlataca��m)
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*strncat(char k1, const char k2, int size) -> strcat fonksiyonundan tek fark� k1 katar�na k2 katar�n�n 3.parametre olan size parametresi kadar olan elemanlar�n� eklemesi
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	--	*strchr(const char k1, int aranan) -> G�r�ld��� gibi iki adet parametre al�r. aranan parametresi bir say�sal koda denk gelir. Bu fonksiyon bu girilen say�sal koda kar��l�k gelen
		karakter, k1 katar� i�erisinde var ise(Bulunan ilk yerde durur yani hakan da iki adet a vard�r ilk a y� g�rd���nde durur soldan sa�a okur) katar i�erisinde bulunan yerin
		adresini d�nderir, yok ise NULL d�nderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		strrchr(const char k1, int aranan) -> strchr fonksiyonundan tek fark� arama i�lemine sa�dan ba�lamas�d�r.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*strcmp(const char k1, const char k2) -> �ki adet parametre al�r. Bu girilen parametrelerin e�itli�ini kontrol eder. E�er bu iki katar e�it ise 0 d�nderir. k1 alfabetik s�rada
		k2 den sonra ise pozitif, �nceyse negatif d�nderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*strncmp(const char k1, const char k2, int size) -> strcmp fonksiyonundan tek fark� k1 katar� ile k2 katar�n� 3.parametre olan size kadar kar��la�t�rma yapmas�.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*strcoll(const char k1, const char k2) -> strcmp fonksiyonu gibi katarlar aras�ndaki ili�kiyi kontrol eder. Aras�ndaki fark strcmp alfabesel �st�nl��e g�re kontrol ederken
		bu fonksiyon ascii kod tablosundaki say�sal �st�nl��e g�re kontrol eder. Geri d�n�� de�eri strcmp ile ayn�d�r. pozitif ise b�y�k, negatif ise k���k veya 0 ise e�it.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*strcpy(char k1, const char k2) -> k1 katar�na(k1 katar�n�n eski hali silinir) k2 katar�n�n de�erini yerle�tirir. Geriye k1 katar�n�n ba�lang�� adresini d�nderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*strncpy(char k1, const char k2, int size) -> strcpy fonksiyonundan tek fark� k1 katar�na k2 katar�n�n 3.parametre olan size kadar eleman� kopyalamas�.(atama)
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------		
		*strcspn(const char k1, const char k2) -> strchr() fonksiyonuna benzer bir i�lem g�r�r. strchr fonksiyonu girilen katar i�erisinde girilen karakterin var m� yok mu oldu�unu 
		kontrol edip ilk bulundu�u yerin adresini d�nderir, bulunmaz ise null d�nderirdi. Bu fonksiyon ise k1 katar�n�n i�erisinde k2 katar�n�n karakterleri aras�nda varm� yok mu
		kontrol eder.(k1 katar�n�n ba��ndan ba�layarak) k1 katar�n�n i�erisinde olmayan karakter say�s�n� verir.(�rne�in kullan�c�dan bir metin girilmesini istedik ve baz�
		karakterlerin olmas�n� istemedik yani strcpsn fonksiyonunun 0 d�nmesini istedik buna g�re kontrol ettirebiliriz.) D�KKAT: BULUNMADI�I ALT K�MEY� D�NDER�R.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*strspn(const char k1, const char k2) -> strcspn fonksiyonu k2 katar�n�n elemanlar�n�n olmad��� en uzun alt k�meyi d�nderiyordu. Bu fonksiyon ise i�erdi�i en uzun alt k�meyi
		d�nderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*strerror(int errno) -> Genellikle parametre yerine g�nderilirken errno sabiti kullan�l�r. E�er hata adresi biliniyorsa hata adresi girilir ve geriye hata mesaj�n� d�nderir.
		Hata adresi bilinmiyor ise kendi �a�r�ld��� yerden �nce kar��la��lan hatan�n hata mesak�n� d�nderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*strlen(const char k1) -> Girilen katar�n NULL d���nda i�erdi�i karakter say�s�n� d�nderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*strpbrk(const char k1, const char k2) -> k1 katar�n�n i�erisinde k2 katar�n�n herhangi bir eleman� olup olmad���n� ara�t�r�r. Bulunursa bulunan ilk yerin adresini, bulunmazsa
		NULL d�nderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*strstr(const char k1, const char k2) -> k1 katar�n�n i�erisinde k2 katar�n�n(fark edildi�i �zere strpbrk fonksiyonundan fark�, strpbrk fonksiyonu k2 katar�n�n elemanlar�ndan
		herhangi birinin i�ermesi durumunu kontrol ederken bu fonksiyon k2 katar�n�n tamam�n�n i�erip i�ermedi�in kontrol ediyor) varl���n� ara�t�r�r. E�er varsa bulunan yerin ilk
		adresini d�nderir, yoksa NULL d�nderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*strtok(cosnt char k1, const char k2) -> k1 katar�n� k2 katar�na g�re par�alamak i�in kullan�l�r. �rnek �zerinden gitmek gerekirse "Merhaba c d�nyas� ne haber, ne i�" �eklinde
		olan bir katar� strtok("Merhaba c d�nyas� ne haber, ne i�", " ,") G�r�ld��� �zere k2 katar�na virg�l ve bo�luk koyduk bu fonksiyon bo�luk veya , g�rene kadar ki k�sm�
		b�ler geriye "Merhaba" kal�r ve adresini d�nderir. Daha sonra null koyarak bunu devam ettirirsek yani strtok(NULL, " ,") �eklinde sona kadar par�alama devam eder.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*strxfrm(char k1, const char k2, int size) -> Bu fonksiyon, farkl� say� k�melerinde ki(�rne�in ASCII olmayan ve olan) de�erleri k�yaslamak i�in uygun bir forma d�n��t�r�r.
		k2 katar�n�n size kadar eleman�n� d�n��t�rerek k1 katar�na atar.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*memchr(char *adres, char ch, int size) -> Bu fonksiyon, verilen adresten ba�layarak size kadar 8 bitlik ilerleyerek kr karakterinin varl���n� ara�t�r�r. E�er bulursa buldu�u
		yerin adresini bulamaz ise NULL d�nderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*memcmp(char *adres, char *adres, int size) -> Verilen iki adresteki de�erleri size kadar 8 bitlik de�er okuyarak kar��la�t�r�r. Ayn� ise 0, ilk parametredeki adreste var olan
		metin alfabetik olarak daha �nce ise negatif, daha sonra ise pozitif de�er d�nderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*memcpy(char *adres, char *adres, int size) -> Verilen ikinci adresteki de�eri size kadar 8 bitlik veriyi, birinci adresteki de�ere atar ve ilk adresi d�nderir. �ki bellek
		alan� kesi�irse yani ilk adresten 8 bitlik ilerlemeye ba�lad�ktan sonra ikinci adres ile kesi�irse ne olaca�� belli de�ildir.(overlap)
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*memmove(char *adres, char *adres, int size) -> memcpy ile ayn� g�revi yapar fakat iki adres kesi�tikleri zaman bile do�ru bi�imde kopyalama i�lemi yapar.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*memset(char *adres, char ch, int size) -> Verilen parametredeki adrese ch karakteri veya say�sal kodu verilmi� karakteri, size kadar 8 bitlik alana yerle�tirir.
		(Baz� fonksiyonlarda verilen 8 bitlik yani 1 byte l�k alan denmesinin sebebi c deki her bir karakter 1 byte yer kaplamas�d�r. Biz kadar olarak kulland���m�z zaman �rne�in
		8 harfli bir katar kullan�rsak bu ramde 8 byte yer kaplar.)
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		NOT: errno say�sal bir de�er tutar. Nas�l ascii kod tablosunda 32 space anlam�na gelirse, errno i�in de say�sal kodlar baz� hata mesajlar�na denk gelir. Hata ile kar��la��ld���
		anda errno sabitine o hata ile ilgili hata kodu de�eri at�l�r.
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

�DEVLER
	**-Mant�ksal bir ili�ki kurarak karakter �zerinde i�lem yapan fonksiyonlar ile her durumu kontrol edecek �ekilde bir program yaz�n�z.
	-Mant�ksal bir ili�ki kurarak katarlar �zerinde i�lem yapan fonksiynolar ile ayr� ayr� �rnekler yaz�n�z.
*/

void program1()
{
	/*1 Karakter �zerinde i�lem yapan fonksiyonlar �rnekleri*/
	char ch;
	printf("Test edilecek karakteri girin: ");
	ch = getch(); /*getch fonksiyonu getchar fonksiyonu ile ayn�d�r bir k�saltmas�d�r. Ayn� �ekilde putch fonksiyonu da putchar fonksiyonunun k�saltmas�d�r.*/
	printf("%c\n",ch); /*Getch fonksiyonu ile klavyeden bas�lan tu� direkt olarak al�n�r ve ekrana girilen tu� g�z�kmez bu y�zden biz manuel olarak bas�yoruz.*/
	if(isalnum(ch))   /*E�er kontrol operat�r� koymadan direkt olarak fonksiyon bu �ekilde yaz�l�rsa 0'dan farkl� de�erler true 0 olan de�erler false say�l�r.*/
	{
		/*Girilen karakter alfasay�sal ise ya harftir yada say�d�r. Say� m� harf mi ayr�m�n� da bu if i�erisinde yapmam�z gerekir.*/
		puts("Alfasay�sal bir karakterdir !");
		if(isalpha(ch))
		{
			/*islower ve isupper alfa karakterler i�in i�lem yap�l�r dolay�s� ile alfa karakter anlam�na gelmesi yani bu if i�erisinde kullan�lmas� gerekir.*/
			puts("	Alfa Bir Karakterdir !"); /*Alfa Harf Anlam�na Gelir.*/
			if(islower(ch))
			{
				puts("		islower Fonksiyonu �le K���k Harf !");
				ch = toupper(ch);
				printf("		toupper Fonksiyonu �le B�y�k Harf'e D�n��t�r�ld� !(KARAKTER: %c)\n", ch);
			}
			else
			{
				puts("		islower Fonksiyonu �le K���k Harf De�il !");
				ch = tolower(ch);
				printf("		tolower Fonksiyonu �le K���k Harf'e D�n��t�r�ld� !(KARAKTER: %c)\n", ch);
			}
			if(isupper(ch))
			{
				puts("		isupper Fonksiyonu �le B�y�k Harf !");
				ch = tolower(ch);
				printf("		tolower Fonksiyonu �le K���k Harf'e D�n��t�r�ld� !(KARAKTER: %c)\n", ch);
			}
			else
			{
				puts("		isupper Fonksiyonu �le B�y�k Harf De�il !");
				ch = toupper(ch);
				printf("		toupper Fonksiyonu �le B�y�k Harf'e D�n��t�r�ld� !(KARAKTER: %c)\n", ch);
			}
		}
		else
		{
			/*Say�sal olmayan bir rakam olamad��� i�in isdigit ve isxdigit fonksiyonlar�n�n da bu else i�erisinde kullan�lmas� gerekir. isxdigit fonksiyonunun ayr� olarak alfa
			kodlara	ait rakamlar� o*/
			puts("	Say�sal Bir Karakterdir !");
			if(isdigit(ch)) /*0-9 aras�nda rakamm� kontrol edilir.*/
				puts("		Ondal�k Bir Rakam !");
			else
				puts("		Ondal�k Bir Rakam De�il !");
			if(isxdigit(ch))
				puts("		Onalt�l�k Bir Rakam !");
			else
				puts("		Onalt�l�k Bir Rakam De�il !");
		}
	}
	else
	{
		/*E�er girilen alfasay�sal bir karakter de�il ise noktalama i�areti olma �ans� var bu y�zden bu else i�erisinde ispunct fonksiyonu kullan�lacak.*/
		puts("Alfasay�sal Bir Karakter De�ildir !");
		if(ispunct(ch))
			puts("	Noktalama ��aretidir !");
		else
			puts("	Noktalama ��areti De�ildir !");
	}
	if(isascii(ch))
	{
		/*Burada bir de kontrol karakteri mi de�il mi onu kontrol edece�iz. Kontrol karakterleri ascii kod olarak 0 - 32 ve 127 ye denk gelir dolay�s� ile ascii kod olmayan kontrol
		karakteri yoktur o y�zden bu if i�erisinde kontrol edece�iz.*/
		puts("Ascii Koddur!");
		if(iscntrl(ch))
			puts("	iscntrl Fonksiyonu �le Kontrol Karakteridir !"); /*non-printing yani enter home vb tu�lar gibi de denilebilir.*/
		else
		{
			/*G�r�ld��� �zere isspace fonksiyonu i�in kontrol edilen de�erler iscntrl ile kontrol edilen de�erler k�mesi ile ayn� bu y�zden bu else i�erisinde kullan�r�z.*/
			puts("	iscntrl Fonksiyonu �le Kontrol Karakteri De�ildir !");
			if(isspace(ch))
				puts("		Girilen Karakter Bo�luk Karakterleridir !");
			else
				puts("		Girilen Karakter Bo�luk Karakterleri De�ildir !");
		}
		if(isgraph(ch)) /*G�r�ld��� gibi yaz�labilir de�erleri kontrol eder yani iscntrl fonksiyonunun tersidir.*/
			puts("	isgraph Fonksiyonu �le Kontrol Karakteri De�ildir !");
		else
		{
			/*G�r�ld��� �zere isspace fonksiyonu i�in kontrol edilen de�erler iscntrl ile kontrol edilen de�erler k�mesinin tersi ile ayn� bu y�zden bu else i�erisinde kullan�r�z.*/
			puts("	isgraph Fonksiyonu �le Kontrol Karakteridir !");
			if(isspace(ch))
				puts("		Girilen Karakter Bo�luk Karakterleridir !");
			else
				puts("		Girilen Karakter Bo�luk Karakterleri De�ildir !");
		}
	}
	else
		puts("Ascii Kod De�ildir !");
	if(isprint(ch))
		puts("Yaz�labilen Bir Karakterdir !");
	else
		puts("Yaz�lamayan Bir Karakterdir !");
}

void program2_1()
{
	/*2 Katarlar �zerinde i�lem yapan fonksiyonlar �rnekleri*/
	/*A�a��da yap�lan i�lem k�saca anlat�lmak istenirse, biz klavyeden girilecek karater say�s�n� bilemiyoruz dolay�s� ile buna g�re static olarak yani dizi bi�iminde bir de�i�ken
	olu�turmak performans� etkiler. Bu y�zden bir tane klavyeden girilen metni tutan ge�ici bir buf isiminde sabit bir dizi ile tutulup daha sonradan bunun say�s�na g�re pointera bellek
	ay�rma yap�yoruz. k1 pointer�n�n boyutunu artt�r�yoruz ki k2 pointer�n�n de�erini de tutabilsin.*/
	char buf[100]; /*Klavyeden girilen yaz�n�n boyutunu ��renmek i�in kullan�lan ge�ici bellek olarak d���n�lebilir.*/
	char *k1; char *k2; char src;
	int buflenght; int i;
	printf("�sim: ");
	gets(buf);
	buflenght = strlen(buf); /*Klavyeden girilen ismin karakter say�s�n� buluyor. (NULL KARAKTER OLARAK SAYILMAZ)*/
	k1 = (char *)malloc(sizeof(char) * buflenght);
	strcat(k1, buf); /*k1 zaten bo� bu y�zden ekleme i�lemi yapt�k ayn� zamanda ta��ma i�lemi de yapt�k.*/
	printf("Soyisim: ");
	gets(buf);
	buflenght = strlen(buf);
	k2 = (char *)malloc(buflenght);
	strcat(k2, buf);
	strcpy(buf, "\0");
	k1 = (char *)realloc(k1, sizeof(char) * (buflenght + 1 + strlen(k1))); /*+1 a�a��da yap�lan bo�luk eklemesinden dolay�d�r.*/
	strcat(k1, " ");
	strcat(k1, k2);
	printf("Ho�geldin %s\n", k1); /*Katar pointerlar yaz�l�rken * ihmal edilir.*/
	puts("");
	free(k1);
	free(k2);
}

void program2_2()
{
	char buf[100]; /*Klavyeden girilen yaz�n�n boyutunu ��renmek i�in kullan�lan ge�ici bellek olarak d���n�lebilir.*/
	char *k1; char *k2; char src;
	int buflenght; int i;
	printf("k1 katar�: ");
	gets(buf);
	buflenght = strlen(buf); /*Klavyeden girilen ismin karakter say�s�n� buluyor. (NULL KARAKTER OLARAK SAYILMAZ)*/
	k1 = (char *)malloc(sizeof(char) * buflenght);
	strcat(k1, buf); /*k1 zaten bo� bu y�zden ekleme i�lemi yapt�k ayn� zamanda ta��ma i�lemi de yapt�k.*/
	printf("k2 katar�: ");
	gets(buf);
	buflenght = strlen(buf);
	k2 = (char *)malloc(buflenght);
	strcat(k2, buf);
	strcpy(buf, "\0");
	printf("k1 katar�n�n uzunlu�u %d, k2 katar�n�n uzunlu�u %d\n", strlen(k1), strlen(k2));
	printf("\nGirilen k1 katar�nda aratmak istedi�iniz karakter: ");
	src = getch();
	if(isspace(src)) /*Girilen karakter bo�luk ise bo�luk karakteri nonprinting oldu�u i�in yaz�lamaz bu y�zden bu if yap�s�n� kurduk.*/
		printf("BO�LUK\n");
	else
		printf("%c\n", src);
	if(strchr(k1, src) != NULL)
	{
		/*While i�lemi ka��nc� indiste bulundu�unu bulmak i�in*/
		i = 0;
		while((k1 + i) != strchr(k1, src))
			i++;
		printf("Aranan karakter %p bellek adresinde %d. indiste bulundu !\n", strchr(k1, src), i);
	}
	else
		puts("Aranan karakter bulunamad� !");
	/*k1 katar�na harf, k2 katar�na say�sal bir de�er girilmesini istemedi�imizi farzederek bir kontrol yap�s�.*/
	if(strcspn(k1, "abcdefgh�ijklmno�prs�tu�vyzABCDEFGHI�JKLMNO�PRS�TU�VYZ") != 0)
		puts("Ba�ar�l� k1 katar�na harf girilmedi !");
 else
		puts("Ba�ar�s�z k1 katar�na harf girildi !");
	if(strcspn(k2, "0123456789") != 0)
		puts("Ba�ar�l� k2 katar�na rakam girilmedi !");
	else
		puts("Ba�ar�s�z k2 katar�na rakam girildi !");
	FILE *fp; /*Dosyalama i�leminde g�r�lecek kodlar.*/
	fp = fopen("file.txt", "r");
	printf("Error: %s\n", strerror(errno));
	puts("");
	free(k1);
	free(k2);
}

void program2_3()
{
	char buf[100]; /*Klavyeden girilen yaz�n�n boyutunu ��renmek i�in kullan�lan ge�ici bellek olarak d���n�lebilir.*/
	char *k1; char *k2; char *src;
	int buflenght; int i;
	printf("Yaz�lacak metin: ");
	gets(buf);
	buflenght = strlen(buf); /*Klavyeden girilen ismin karakter say�s�n� buluyor. (NULL KARAKTER OLARAK SAYILMAZ)*/
	k1 = (char *)malloc(sizeof(char) * buflenght);
	strcpy(k1, buf); /*k1 zaten bo� bu y�zden ekleme i�lemi yapt�k ayn� zamanda ta��ma i�lemi de yapt�k.*/
	printf("Ayr�m operat�rleri: ");
	gets(buf);
	buflenght = strlen(buf);
	k2 = (char *)malloc(buflenght);
	printf("k1 katar�: %s\n", k1);
	strcpy(k2, buf);
	strcpy(buf, "\0");
	i = 1;
	/*Burada akl�n�zda bir soru olmas� gerekir yoksa da sorulan soruyu cevaplaman�z gerekir.*/
	src = strtok(k1, k2);
	while(src != NULL)
	{
		printf("%d.Par�a: %s\n", i++, src);
		src = strtok((char *)NULL, k2);
	}
	free(k1);
	free(k2);
}

void program2_4()
{
	char buf[100]; /*Klavyeden girilen yaz�n�n boyutunu ��renmek i�in kullan�lan ge�ici bellek olarak d���n�lebilir.*/
	char *k1; char *k2; char *src;
	int buflenght; int i;
	printf("Yaz�lacak metin: ");
	gets(buf);
	buflenght = strlen(buf); /*Klavyeden girilen ismin karakter say�s�n� buluyor. (NULL KARAKTER OLARAK SAYILMAZ)*/
	k1 = (char *)malloc(sizeof(char) * buflenght);
	strcpy(k1, buf); /*k1 zaten bo� bu y�zden ekleme i�lemi yapt�k ayn� zamanda ta��ma i�lemi de yapt�k.*/
	printf("Ayr�m operat�rleri: ");
	gets(buf);
	buflenght = strlen(buf);
	k2 = (char *)malloc(buflenght);
	printf("k1 katar�: %s\n", k1);
	strcpy(k2, buf);
	strcpy(buf, "\0");
	src = memchr(k1, 'A', 10);
	if(src == NULL)
		puts("Bulunamad� !");
	else
		printf("%p adresinde %c de�eri bulundu !\n", src, *src);
}

void main()
{
	setlocale(LC_ALL, "Turkish");
	/*1 Karakter �zerinde i�lem yapan fonksiyonlar �rnekleri*/
	//program1();
	/*2 Katarlar �zerinde i�lem yapan fonksiyonlar �rnekleri*/
	//program2_1();
	program2_2();
	//program2_3();
	//program2_4();
}


























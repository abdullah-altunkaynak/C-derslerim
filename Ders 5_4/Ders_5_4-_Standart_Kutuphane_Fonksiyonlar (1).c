#include <stdio.h> /*STANDART I/O K�T�PHANES�*/
#include <stdlib.h> /*MALLOC G�B� BAZI STANDART FONKS�YON K�T�PHANES�*/
#include <stdarg.h> /*ESNEK ARG�MAN AKTARIMI K�T�PHANES�*/
#include <errno.h> /*errno DE���KEN�N�N B�LD�R�M� YAPILAN K�T�PHANE*/
/*#define NDEBUG*/
#include <assert.h> /*HATA AYIKLAMA ASSERT FONKS�YONUNUN B�LD�R�M� YAPILAN K�T�PHANE*/
#include <setjmp.h> /*YEREL OLMAYAN DALLANMA FONKS�YONU B�LD�R�M� YAPILAN K�T�PHANE*/
#include <time.h> /*TAR�H VE ZAMAN FONSK�YONLARININ K�T�PHANES�*/
#include <ctype.h> /*KARAKTERLER �ZER�NDE ��LEM YAPAN K�T�PHANE 1.1*/
#include <signal.h> /*AYRICALIKLI DURUM KONTROL� FONKSY�ONLARININ B�LD�R�MLER� YAPILAN K�T�PHANE*/
#include <string.h> /*KATARLAR �ZER�NDE ��LEM YAPAN K�T�PHANE 2.1*/
#include <locale.h> /*LOKAL�ZASYON FONKS�YONLARININ B�LD�R�M� YAPILAN K�T�PHANE*/

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

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
1-Karakter �zerine ��lem Yapan Fonksiyonlar Ve K�t�phanesi:
	Ad� �zerinde bu b�l�mde karakterler �zerinde i�lem yapan fonksiyonlar� g�rece�iz bunlar i�in kullan�lacak bir adet k�t�phane vard�r. Bu k�t�phane i�erisindeki fonksiyonlar�n tamam�
"MAKRO" fonksiyonlard�r ve karakter k�mesinin i�erisindeki s�n�f�n� belirleyen ve de�i�tirme fonksiyonlar� ikiye ayr�labilirler.
	1.1-<ctype.h>
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*isalnum(); -> ��erisine int parametre al�r bu int ifade ondal�k say� taban�ndaki binary koda denk gelir yani i�erisine char koyarsak kendisi otamatik cast ederek int a �evirir
		yani binary koda �evirir. ��erisine g�nderilen karakterin veya ascii kodun kar��l�k geldi�i karakterin alfasay�sal kod(a-z, A-Z,0-9) ise 0'dan farkl� bir say� de�il ise 0
		d�nderen bir fonksiyondur.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		/*isalpha(); -> Bu fonksiyonunda parametre g�nderimi isalnum fonksiyonu ile ayn�d�r. Bu fonksiyon girilen karakterin veya binary kodun kar��l�k geldi�i karakterin say�sal de�er
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
		*strchr(const char k1, int aranan) -> G�r�ld��� gibi iki adet parametre al�r. aranan parametresi bir say�sal koda denk gelir. Bu fonksiyon bu girilen say�sal koda kar��l�k gelen
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
		NOT: errno OLARAK KULLANDI�IMIZ DE���KEN, errno.h STANDART K�T�PHANES� ��ER�S�NDE TANIMLANMI�TIR.
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
3-Standart I/O (Input/Giri�, Output/��k��) Fonksiyonlar� Ve K�t�phanesi
	B�t�n giri�/��k�� fonksiyonlar�, bir dosyaya veya bir �evre biriminine (monitor, printer) eri�irken, tampon ad� verilen bir arabellek �zerinden eri�ir. (getch fonksiyonunda bu
yoktu do�rudan klavye den al�r) Bir dosya a��ld���nda da ona bir tampon atan�r. Dosya kapat�ld��� zaman da bu tampon sisteme geri verilir. FILE tipi dosyaya eri�im i�in gerekli t�m
bilgilerin i�erildi�i bir topluluk (struct) yap�s�nda olup, hangi �yelere sahip oldu�u sisteme ba�l�d�r. Olmas� gereken t�m temel elemanlar a�a��daki gibidir.
typdef struct
{
	int cnt; Tampon da kullan�lan yer miktar�.
	unsigned char *b_ptr; Bir sonraki eri�im i�in kullan�lan de�i�ken.
	unsigned char *base; Tampon ba�lang�c�.
	int bufsize; Tampon boyutu.
	short flags;
	char fd; Dosya tan�mlay�c�s�
}FILE;
	1-<stdio.h>
									Bu k�t�phanede bulunan;
									YEN� VER� T�PLER�
									post_t -> fsetpos fonksiyonunda kullan�l�yor. (long)
									size_t -> Bir�ok fonksiyonda kullan�l�yor. Byte cinsinden verileri ifade etmek i�in kullan�l�r.(unsigned)
									va_list -> vprintf() ailesince kullan�l�yor. (char *)
									S�MGESEL SAB�TLER
									BUFFSIZE -> Aksi s�ylenmedi�i s�rece tampon boyutu.
									EOF -> Dosya sonu karakteri (-1)
									FILENAME_MAX Dosya ad�n�n en fazla karakter say�s�.
									FOPEN_MAX Ayn� anda a��labilecek dosya say�s�.
									_IOFBF (errno gibi sistem taraf�ndan olu�turulmu� fonksiyona g�nderilecek parametre) -> setvbuf(): Tam tamponlu. (0)
									_IOLBF (errno gibi sistem taraf�ndan olu�turulmu� fonksiyona g�nderilecek parametre) -> setvbuf(): Sat�r tamponlu. (0x80)
									_IONBF (errno gibi sistem taraf�ndan olu�turulmu� fonksiyona g�nderilecek parametre) -> setvbuf(): Tamponsuz. (0x04)
									SEEK_SET (errno gibi sistem taraf�ndan olu�turulmu� fonksiyona g�nderilecek parametre) -> fseek(): Dosya ba��na.(0)
									SEEK_CUR (errno gibi sistem taraf�ndan olu�turulmu� fonksiyona g�nderilecek parametre) -> fseek(): O anda bulunan yere. (1)
									SEEK_END (errno gibi sistem taraf�ndan olu�turulmu� fonksiyona g�nderilecek parametre) -> fseek(): Dosya sonuna. (2)
									STANDART G�R�� ��ARET��LER�
									(Standart olmayan ancak dos alt�nda �al��an bir�ok derleyicide stdprn ve stdaux adl� i�aret�iler de vard�r.)
									stdin -> Standart giri� i�in. Varsay�lan olarak klavye.
									stdout -> Standart ��k�� i�in. Varsay�lan olarak monit�r ve console ekran�.
									stderr -> Standar hata ��k��� i�in. Varsay�lan olarak console ekran�d�r.
		FILE *f;
		f = fopen("dosya.txt", "r");
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
																		DOSYALAMA �LE �LG�L� FONKS�YONLAR
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*clearerr(FILE *f) -> E�er dosya a�ma i�lemi ba�ar�s�z olur ve hata al�rsa, dosya toplulu�unda ki flags de�i�keninin de�eri yani hata bayra�� birlenir ve dosya kapat�lmad���
		s�rece b�yle kal�r. Bu fonksiyon ise i�erisine parametre olarak ald��� dosyan�n hata bayra��n� ve di�er hatalar� s�f�rlar. Geriye herhangi bir�ey d�ndermez.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*fopen(const char *dosya_adi(xxx.txt gibi), const char *dosya_modu) -> Diskte dosya olu�turmak veya var olan dosya �zerinde i�lem yapmak i�in kullan�l�r. fclose ile a��ld�ktan
		sonra hata ile kar��la�mamak i�in(veri kayb�) kapat�lmal�d�r. E�er dosya a�ma i�lemi ba�ar�l� olursa geriye a��lan dosyan�n adresini, ba�ar�s�z olursa geriye NULLL d�nderir.
		6 adet dosya a�ma modu vard�r.
			-"r" -> read-only bi�iminde var olan dosyay� sadece okumak i�in a�ar. E�er diskte dosya yok ise fopen fonksiyonu NULL d�nderir. Cursor dosya ba��na konumlan�r.
			-"w" -> write-only bi�iminde dosyay� yanl�zca yazmak i�in a�ar. E�er diskte zaten bir dosya var ise dosya s�f�rlan�r. Yok ise yeni dosya a��l�r. Cursor dosya ba��na gelir.
			-"a" -> input-only bi�iminde dosyay� yanl�zca eklemek i�ni a�ar. E�er diskte zaten bir dosya var ise dosya a��l�r cursor dosya sonuna konumland�r�l�r. E�er diskte dosya yok
			ise yeni dosya a��l�r.
			-"r+" -> Okuma ve yazma i�in a�ar, cursor dosya ba��na gelir. Dosya yoksa NULL d�nderir.
			-"w+" -> "w" modu ile ayn�d�r. Ek olarak okuma i�lemi de yap�labilir.
			-"a+" -> Eklemek i�in a��l�r. E�er dosya yok ise yeniden olu�turur ve cursor ba�a gelir. Dosya var ise cursor dosya sonuna konumland�r�l�r. Okuma ve yazma i�lemleri de
			yap�l�r.
			(BINARY VE TXT B���M�DE �K� ADET DOSYA T�R� VARDIR BUNLARI BEL�RTMEK �ST�YORSAK BINARY ���N MOD SONUNA B, TXT VARSAYILANDIR AMA BEL�RTMEK ���N MOD SONUNA t GEL�R)
			(KONUM BEL�RT�LMEZ �SE KAYNAK KODUNUN BULUNDU�U DOSYA ��ER�S�NE KAYIT YAPILIR. KAYIT BEL�RTMEK �STEN�RSE DE "\\" KULLANILIR. C::\\dosya_ismi.txt G�B�)
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*fclose(FILE *f) -> Herhangi bir modda a��lm�� ve i�erisine parametre olarak g�nderilen pointer i�erisinde tutulan dosyay� kapat�r ve tampon s�f�rlan�r. E�er dosya yazma veya
		ekleme modunda a��lm�� ise �nce tampondaki verileri diske kaydeder daha sonra tampon s�f�rlan�r ve dosya kapan�r.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*feof(FILE *f) -> E�er a��lm�� dosya i�erisindeki cursor ismini verdi�imiz �o�u yerde yatay �izgi halinde bir konum �zerinde duran i�aret�i i�in, e�er bu cursor dosya sonunda
		ise geriye 0'dan farkl� bir de�er, dosya sonunda de�il ise 0 d�nderir.
		(�rne�in txt dosyas� i�erisinde "Merhaba dosyalama i�lemleri" �eklinde bir verimiz olsun. Cursor e�er i'nin sa��nda ise dosya sonunda oldu�u i�in 0'dan farkl� bir de�er, farkl�
		herhangi bir yerde ise 0 d�nderir.)
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*ferror(FILE *f) -> Parametre olarak g�nderilen dosyada en son yap�lan okuma, yazma veya ekleme i�leminde herhangi bir hata var ise 0'dan farkl� bir de�er, hata yok ise 0
		d�nderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*fflush(FILE *f) -> Parametre olarak g�nderilen dosyan�n tampon i�erisindeki verileri e�er yazma veya ekleme modunda a��lm�� ise �nce diske kaydeder daha sonra t�m modlar i�in
		tampon belle�i s�f�rlar. �rne�in stdin klavye olarak bildirilmi� ve tamponda daha �nceden kalma bir veri varsa, klavyeden yeni de�erin girilmesi beklenmez tampondaki eski
		veriler okunur. Bunu �nlemek i�in kullan�l�r. Geriye int tipinde bir de�er d�nderir ne d�nderdi�ini siz deneyerek bulun.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*fgetpos(FILE *f, pos_t *position) -> Parametre olarak g�nderilen dosya i�in, yine parametre olarak g�nderilen pos_t veri tipinde position isimli i�aret�i parametreye bu
		dosyan�n cursor pozisyonunu d�nderir. ��lem ba�ar�l� ise 0'dan farkl�, ba�ar�s�z ise 0 d�nderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*fsetpos(FILE *f, pos_t *position) -> Parametre olarak g�nderilen dosyan�n cursor pozisyonunu, yine parametre olarak g�nderilen pos_t veri tipindeki bir parametre ile ayarlar.
		��lem ba�ar�l� ise 0'dan farkl�, ba�ar�s�z ise 0 d�nderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*putc(char ch, FILE *f) -> f parametresinin g�sterdi�i dosyan�n, cursor'unun sa��na verilen karakter veya say�sal kodun ifade etti�i karakteri yazar. Ba�ar�l� olursa yaz�lan
		karakteri, ba�ar�s�z olursa EOF(-1) d�nderir. Makro fonksiyondur.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*getc(FILE *f) -> f parametresinin g�sterdi�i dosyan�n cursor'unun ba�lang�c�ndan bir sekizlik veri okur ve geriye d�nderir. E�er hata olu�ursa veya dosya sonunda gelinirse
		geriye EOF(-1) d�nderir. Makro fonksiyondur.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*fputc(char ch, FILE *f) -> f parametresinin g�sterdi�i dosyanan�n cursorun sa��na belirtilen karakteri veya say�sal kodu g�nderilen karakteri yazar. Ba�ar�l� olursa geriye
		yaz�lan karakteri, ba�ar�s�z olursa EOF(-1) d�nderir. putc ile (putch ile kar��t�rma) ayn� i�levi g�r�r. Tek fark� putc makro fonksiyondur bu fonksiyon de�ildir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*fgetc(FILE *f) -> Parametre olarak g�nderilen dosya i�erisinde cursor'un sa��nda bulununan karakterin say�sal kodunu (int tipinde) d�nderir. getc foknsiyonundan tek fark�
		(getch ile kar��t�rma) getc fonksiyonu makro fonksiyondur bu makro fonksiyon de�ildir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*fputs(char *k1, FILE *f) -> f dosya i�aret�isinin g�sterdi�i dosyaya k1 katar�n�n� cursorun sa��ndan ba�layarak yazmak i�in kullan�l�r. Ba�ar�l� olursa pozitif bir say�,
		ba�ar�s�z olursa EOF(-1) d�nderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*fgets(char *k1, int n, FILE *f) -> Parametre olarak g�nderilen k1 katar�n�n i�erisine, f dosyas�n�n i�erisindeki (cursor oldu�u yerden) veriyi n-1 karakter olarak atar ve
		katarlarda oldu�u gibi k1 katar�n�n sonuna NULL atar. (\n yani newline g�r�rse veya dosya sonuna gelinir ise okuma i�lemi sonlan�r.) E�er i�lem ba�ar�l� ise k1 katar�n�n
		adresini ba�ar�s�z ise geriye NULL d�nderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*fprintf(FILE *f, const char *k1, ...arguman) -> Parametre olarak g�nderilen f dosya i�aret�isinin g�sterdi�i dosyaya standart I/O �zerinde i�lem yapan printf'e benzer �ekilde
		yaz� veya formatl� yaz� yazmam�z� sa�lar. Geriye int bir de�er d�nderir bunu siz bulun.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*fscanf(FILE *f, const char *k1, ...arguman) -> Parametre olarak g�nderilen f dosya i�aret�isinin g�sterdi�i dosyaya standart I/O �zerinde i�lem yapan scanf'e benzer �ekilde
		formatl� veri almam�z� sa�lar. Geriye int bir de�er d�nderir bunu siz bulun.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*fwrite(void *k1, size_t s, size_t n, FILE *f) -> f dosyas�na tek karakteri s sekizli(char i�in 1, int i�in 4 gibi) olan bir de�i�kenin n karakterini dosya i�erisine cursor'un
		sa��ndan yazmaya yarar. E�er ba�ar�l� olursa n, ba�ar�s�z olursa n'den k���k bir de�er d�nderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*fread(void *k1, size_t s, size_t n, FILE *f) -> f dosyas�ndan tek karakteri s sekizli(char i�in 1, int i�in 4 gibi) n karakteri okuyarak k1 de�i�keninie yerle�tirir. Bu
		fonksiyon ba�ar�l� ise geriye okunan eleman say�s�n�, ba�ar�s�z ise 0 d�nderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*fseek(FILE *f, Belirtti�imiz(SEEK_SET - 0, SEEK_CUR - 1, SEEK_END - 2), int n) -> f ile belirtilen i�aret�inin g�sterdi�i dosyan�n cursor'unu, SEEK_SET(Ba�tan), SEEK_CUR(
		Cursor'un oldu�u yerden) veya SEEK_END(Dosya sonundan) itibaren n kadar �telemeyi sa�lar. Ba�ar�l� olursa 0, ba�ar�s�z olursa 0'dan farkl� bir de�er d�nderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*ftell(FILE *f) -> Belirtilen f dosya i�aret�isinin g�sterdi�i dosya i�in, dosya ba��ndan itibaren cursor'un uzakl���n� 8 bitlik(1 byte sayarak) geriye d�nderir. E�er ba�ar�s�z
		olursa geriye -1 d�nderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*freopen(const char *dosyaAdi, const char *dosyaAcilmaModu, FILE *f) -> fopen fonksiyonu gibi bu fonksiyon da, belirtilen dosya ad� ve mod da dosya a�ar ve adresini f
		pointer�na g�nderir. Bu fonksiyon daha �ok standart I/O i�lemlerini dosyaya y�neltmek i�in kullan�l�r. FILE *f ile belirtilen parametreye stdin, stdout veya stderr yaz�l�r.
		�rne�in freopen("dosya.txt", "w", stdout); fonksiyonunu kulland���m�z zaman, standart ��k��a ��k�� sa�layan fonksiyonlar (printf, puts gibi) art�k dosya.txt isimli dosyaya
		��k�� sa�larlar. Ba�ar�l� olursa FILE *f ile belirtilen parametrenin adresini, ba�ar�s�z olursa NULL d�nderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*remove(const char *dosyaAdi) -> Disk �zerinde dosyaAdi katar�n�n de�eri ile isimlendirilmi�(katar �rne�in dosya.txt) dosyay� diskten kald�r�r. E�er ba�ar�l� olursa 0, ba�ar�s�z
		olursa 0'dan farkl� bir de�er d�nderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*rename(const char *eskiDosyaAdi, const char *yeniDosyaAdi) -> Diskte eskiDosyaAdi ile isimlendirilmi� dosyan�n ismini yeniDosyaAdi ile de�i�tirir. Verilen yeni dosya ad� e�er
		o disk klas�r� i�erisinde zaten varsa ne yap�laca�� sisteme ba�l�d�r. Genellikle �zerine yazar. E�er i�lem ba�ar�l� ise 0, ba�ar�s�z ise 0'dan farkl� bir de�er d�nderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*rewind(FILE *f) -> Geriye bir de�er d�ndermez. Cursor'u dosya ba��na konumland�r�r ve clearerr fonksiyonu gibi hatalar� ve bayraklar� temizler.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*setbuf(FILE *f, char *tampon) -> Geriye de�er d�ndermeyen bu fonksiyonun kullan�m� i�in, dosya a��lm�� fakat hi� i�lem yap�lmam�� olmas� gerekmektedir. Bu �artlar sa�land���
		noktada, a��lan bir dosyaya otomatik bir tampon atand���n� s�ylemi�tik, e�er tamponu biz manule olarak atamak istiyorsak bu fonksiyonu kullan�r�z. Tampon yerine e�er NULL
		girilirse bu dosya ivedi olarak tamponsuz �al��acakt�r.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*setvbuf(FILE *f, char *tampon, int mod, size_t n) -> Bu fonksiyon da tampon de�i�tirmek i�in kullan�l�r. Belirtilen dosya �zerinde yine bir i�lem yap�lmamas� gerekir. tampon
		ile belirtilen bellek adresinden ba�layarak n sekizli (n 1 byte) olarak tamponu ayarlar. mod i�in ise 3 adet sabit vard�r.
			_IONBF -> Arabellek boyu s�f�rlan�r. Eri�imler direkt olarak yap�l�r.
			_IOFBF -> Arabellek boyunu verilen parametreler do�rultusunda de�i�tirir.
			_IOLBF -> _IOFBF ile ayn� i�e yarar tek farkl� arabellekden dosyaya veri aktar�lmas� ya doldu�unda ya da \n newline ile kar��la�t���nda olur.
		Geriye e�er ba�ar�l� olursa 0, ba�ar�s�z olursa 0'dan farkl� bir int de�er d�nderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*tmpfile(void) -> Ge�ici olarak disk dosyas� olu�turarak e�er olu�turma ba�ar�l� ise bu dosyan�n adresini, ba�ar�s�z ise NULL d�nderir. Dosya w+ modunda a��l�r e�er
		destekleniyorsa binary dosya yap�s� olarak a��l�r. Program sonland���nda dosya da diskten silinir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*tmpnam(char *fileName) -> Bu fonksiyon TMP_MAX sabiti kadar L_tmpnam karakterlik ve kullan�lmayan, var olmayan rastgele dosya ismi �retir. �retilen dosya ismini geriye
		d�nderir. E�er ba�ar�s�z olursa NULL d�nderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*ungetc(char kr, FILE *f) -> Belirtilen dosyadan okunan karakteri geri tampona atar. Ard� ard�na iki kez kullan�lmaz. Geriye e�er ba�ar�l� ise eklenen karakterin say�sal
		kodunu, ba�ar�s�z ise NULL d�nderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*vfprintf(FILE *f, "", ...) -> Standart I/O konusunda belirtilen vprintf yap�s� ile ayn�d�r tek fark� stdout'a de�il belirtilen dosya i�aret�isinin g�sterdi�i dosyaya verileri
		yazd�r�r.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
																		STANDART I/O �LE �LG�L� FONKS�YONLAR
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*perror(const char *k1) -> Geriye bir de�er d�ndermez. ��erisine ald��� k1 katar�n� ekrana basar ve ": " koyar daha sonra errno sabitinin i�erdi�i say�sal kdoun kar��l�k
		geldi�i hata kodunu basar.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*putchar(char ch) -> stdout (varsay�lan monit�r - console) �zerine tampon kullanmadan direkt olarak veriyi aktarmay� sa�lar. Parametre olarak girilen say�sal kodun kar��l�k
		geldi�i karakteri veya girilen karateri basar. Geriye e�er ba�ar�l� ise bas�lan karakterin say�sal kodunu, ba�ar�s�z ise EOF(-1) d�nderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*getchar(void) -> stdin (varsay�lan klavye) �zerinden tampon kullanmadan direkt olarak veri al�nmas�n� sa�lar. Parametre almaz geriye stdin den gelen verinin say�sal kodunu
		d�nderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*printf("%n", ...) -> �lk parametresine yaz�lan metin baz� kontrol karakterleri, sabitler ve de�i�kenler hari� direkt olarak yazd�r�l�r. Kontrol karakterlerinden % ve \ i�areti
		nin ayr� ayr� g�revleri vard�r ve kendilerinin ka��� karakterleridir. Yani bu kontrol karakterlerinin g�revleri oldu�u i�in metin i�erisinde tek ba�lar�na yaz�lamazlar. Bundan
		dolay� e�er % karakteri stdout a yazd�r�lmak isteniyorsa �ift %% �eklinde, \ karakteri i�in se �ift \\ �eklinde yaz�lmas� gerekir. Bu karakterlerin g�revleri de yine stdout
		�zerinde i�lem yapar. K�sacas� printf formatl� bir bi�imde stdout �zerine veri yazmak i�in kullan�l�r. E�er ba�ar�l� olursa bas�lan karakter say�s�, ba�ar�s�z olursa geriye
		negatif bir say� d�nderir.
		% KARAKTER� VE G�REVLER�
			c -> Karakter de�i�keni yaz�lmas� i�ni.
			d ve i -> int (anahtar kelimeler dahil long, short) yaz�lmas� i�in.
			u -> unsigned int yaz�lmas� i�in.
			o -> Sekizlik say� sisteminde say� yaz�lmas� i�in. (E�er onluk veya onalt�l�k say� sisteminde bir de�er varsa bunu otomatik convert ederek yazd�r�r.)
			f -> Ger�el say�lar� yazmak i�in kullan�l�r. Ayn� zamanda a ve b tam say� olmak �zere %a.bf �eklinde yaz�l�r ise solda a kadar say� ve sa�da b kadar say� format�nda yazar.
			NOT: Duyarl�l��� ikinci parametreden alma printf("%*.*f", 5, 3, degisken); Yukardaki a, b �rne�i ile ayn� i�i g�r�r.
			lf -> Double yazd�r�rken kullan�l�r.
			x ve X -> Onalt�l�k say� sisteminde say� yaz�lmas� i�in. (Otomatik convert eder.)
			e ve E -> Ger�el say�y� e tabanl� [-/+]a.bbbbbbbbe[-/+]cccc bi�iminde yazar. (�rne�in 3.142857e+002)
			g ve G -> Ger�el say�lar� %f veya %e hangisi k�sa yaz�l�r ise onunla yaz�lmas�n� tercih eder. %f ile yaz�l�rsa gereksiz 0 lar yok say�l�r. E�er tamamen 0 ise nokta koyulmaz.
			p -> Bellek adresi yazd�rmak i�in kullan�l�r. (pointerlar veya & ile adres d�nderenler.)
			s -> Katarlar� yazd�rmak i�in kullan�l�r.
			n -> Kar��l�k olarak bir int de�i�ken gelmelidir ve &(ampersant) kullan�larak yaz�lmal�d�r. Bu de�i�kene %n den �nce yaz�lan karakter say�s� atan�r.
		\ KARAKTER� VE G�REVLER�
			a -> Ses �retir.
			b -> �mle� bir sola kayar. (backspace)
			f -> Sayfa atla, bir sonraki sayfan�n ba��na ge�. (Bir world dosyas�nda 2. sayfan�n ba��na ge�irir.)
			n -> Sat�r atla, alt sat�ra ge�.(newline)
			r -> Sat�r ba�� yap.
			t -> Yatay tab yapar yani n kadar bo�luk b�rak�r. (n derleyici ayarlar�na ba�l� olarak de�i�ir.)
			v -> Dikey tab yapar yani s�tun de�i�meden kald��� s�t�ndan alt sat�ra ge�er.
			NOT: Float de�i�keni i�in ka� hane yaz�laca�� gibi bir sistem anlat�ld�, b�t�n de�i�kenler i�in yaz�labilecek bayrak sistemi % den hemen sonra yaz�lan 4 adet bayrak vard�r.
				' '(space) -> pozitif say�lar�n �n�ne ' '(space) negatif say�lar�n �n�ne (-) yaz�lmas�n� sa�lar.
				(+) -> T�m say�lar�n �n�ne, pozitif ise (+), negatif ise (-) koyulmas�n� sa�lar.
				(-) -> �rne�in char k1[] = "Merhaba"; �eklindeki katar� printf("[%10s]", k1); �eklinde yazarsak soluna 10 bo�luk b�rakarak [          Merhaba] �eklinde yazar. �n�ne
				bu bayra�� koyarsak printf("[%-10s]", k1); [Merhaba          ] �eklinde yazar.
				# ->
					c, s, d, i, ve u da bir etkisi yoktur.
					o i�in �n�ne '0' koyar.
					x i�in �n�ne '0x' koyar.
					f, e ve g i�in tam ve kesirli k�s�mlar�n her zaman ayr�laca��n� belirtir.
			BAYRAKLAR AYNI ANDA KULLANILAB�L�R.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*scanf("", a, ...) -> Yine i�erisine belirsiz say�da de�i�ken al�r. �lk parametrede belirtildi�i formatta stdin �zerinden (burada tampon console ekran�d�r.) istenile veri
		tiplerinde de�er okumam�z� sa�lar. Asl�nda b�t�n her�eyi katar olarak okur fakat belirtilen formata g�re ilgili de�i�kenlere cast ederek de�er atamas� yapar. E�er ba�ar�l�
		olursa okunan atama adetini, ba�ar�s�z olursa EOF(-1) d�nderir. Formatlamada belirleyici olan % karakteridir.
		% KARAKTER� VE G�REVLER�
			* -> c, d gibi (s yani katarlar hari�) karakterler ile % karakteri aras�na yaz�l�rsa o formatta o noktada hi� bir atama yap�lmayaca�� anlam�na gelir atama yap�lmaz.
			[...] ve [^...] -> Birbirlerinin de�ili olan iki g�rev, sadece katarlar i�in kullan�l�r. K��eli parantez i�erisine al�nan k�me elemanlar�n�n i�erdikleri yere kadar okunur,
			e�er i�ermeyen yer varsa okuma sonland�r�l�r.(�rne�in scanf("%[Abdula]", k1); ve girdisi Abdullah oldu�unu varsayarsak k1 katar�n�n de�eri Abdulla olur ��nk� h harfi ile
			kar��la��lm��t�r.) De�ili yani [^...] ise bulunmayana kadar okur e�er bulunan varsa okuma sonland�r�l�r.(�rne�in scanf("%[^lh]", k1); girdi yine Abdullah olsun bu sefer
			k1 katar�n�n de�eri Abdu olur ��nk� verilen k�me elemanlar�ndan birini i�ermektedir ve okuma sonland�r�lm��t�r.)
			Geni�lik: Float da oldu�u gibi t�m de�i�kenlerde geni�lik verilebilmektedir. �nt de�i�keni i�in ise bu indis anlam�na gelir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*puts(const char *k1) -> k1 katar�n� veya "" ile yaz�l�rsa yaz�lan� ekrana basar ve newline yapar. Ba�ar�l� olursa pozitif bir de�er, ba�ar�s�z olursa EFO(-1) d�nderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*gets(char *k1) -> Ekrandaki sat�r� k1 katar�na atar. Bu okuma i�lemi karakter karakter olur e�er \n(newline) veya sat�r sonu(EOF) ile kar��la��l�rsa sonlan�r. ��lem ba�ar�l�
		olursa geriye k1 katar�n�n adresini, ba�ar�s�z olursa NULL d�nderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		sprintf(char *k1, "", ...) -> printf fonksiyonu ile ayn� i�i g�r�r fakat printf fonksiyonunda oldu�u gibi stdout'a de�il de k1 katar� i�erisine formatl� veri giri�i yap�l�r.
		Geri d�n��� printf fonksiyonu ile ayn�d�r.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		sscanf(const char *k1, "", ...) -> Bu da scanf fonksiyonu ile ayn�d�r. Farklar� stdin �zerinden de�il de verilen katar �zerinden formatl� okuma yap�l�r. Geri d�n��� scanf
		fonksiyonu ile ayn�d�r.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		vprintf("", va_list arguman) -> G�r�ld��� �zere stdarg k�t�phanesi tipi olan va_list arg�man kabul ediyor. Biz �oklu parametre g�ndermede g�rd���m�z va_arg fonksiyonu ile
		teker teker �a��rarak okuyorduk, bunun yerine vprintf ile yazd�r�lan va_list argumanlar t�m argumanlar� ekrana yazar. Geriye arg�man say�s�n� d�nderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		vsprintf(char *k1, "", va_list arguman) -> vprintf ile ayn�d�r. stdout yerine k1 katar�na yerle�tirir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
4-Matematiksel Fonksiyonlar Ve K�t�phanesi:
	Matematiksel fonksiyonlar�n tipleri �ift duyarl� ger�el say�lard�r. (double) math.h k�t�phanesi i�erisinde tan�mlanm��lard�r. Bu k�t�phane i�erisinde de baz� simgesel
sabitler (errno gibi de�i�kenler) tan�mlanm��t�r. Fonksiyonlara gelen parametreler belirtilen s�n�rlar�n d��ar�s�nda ise errno de�i�keninie EDOM atan�r. (�rne�in sqrt kare k�k
hesaplayan fonksiyon parametre olarak negatif de�er alamaz hesaplayamaz.) E�er fonksiyonlar�n geriye d�ndermek i�in hesaplanan de�erleri �ok b�y�k veya �ok k���k ise, errno
de�i�kenine ERANGE atan�r ve �a�r�lana HUGE_VAL (Bu k�t�phanenin simgesel sabiti) d�nderilir.
NOT: ANLATILAN T�M FONKS�YONLAR GER�YE DOUBLE D�NDER�R.
		1-<math.h>
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
																			TR�GONOMETR�K FONKS�YONLAR
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*cos(double) -> Radyan cinsinden verilen a��n�n kosin�s�n� hesaplar ve geriye d�nderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*acos(double) -> Verilen parametrenin ters kosin�s�n� hesaplar. E�er parametre [-1, +1] kapal� aral���nda de�ilse, errno de�i�kenine EDOM atan�r; aras�nda ise hesaplanan sonu�
		[0, PI] aras�nda d�nderilir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*cosh(double) -> Radyan cinsinden verilen a��n�n hiperbolik kosin�s�n� hesaplar ve geriye d�nderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*sin(double) -> Radyan cinsinden verilen a��n�n sin�s�n� hesaplar ve geriye d�nderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*asin(double) -> Verilen parametrenin ters sin�s�n� hesaplar. E�er parametre [-1, +1] kapal� aral���nda de�ilse, errno de�i�kenine EDOM atan�r; aras�nda ise hesaplanan sonu�
		[-PI/2, +PI/2] aras�nda d�nderilir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*sinh(double) -> Radyan cinsinden verilen a��n�n hiperbolik sin�s�n� hesaplar ve geriye d�nderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*tan(double) -> Radyan cinsinden verilen a��n�n tanjant�n� hesaplar ve geriye d�nderir. E�er a�� PI/2'nin tek katlar�na yakla��rsa hata �retilir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*atan(double) -> Verilen parametrenin ters tanjant�n� hesaplar ve geriye d�nderir. Sonu� [-PI/2, +PI/2] aras�nda olur.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*tanh(double) -> Radyan cinsinden verilen a��n�n hiperbolik tanjant�n� hesaplar ve geriye d�nderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
																		    D��ER MATEMAT�KSEL FONKS�YONLAR
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*ceil(double) -> Verilen parametreden k���k olmayan, en k���k tamsay� de�erini d�nderir. (�rne�in 8.2 ise en k���k tam say� de�eri 9 olmal�d�r.)
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*floor(double) -> Verilen parametreden b�y�k olmayan, en b�y�k tamsay� de�erini d�nderir. (�rne�in 8.2 ise en b�y�k tam say� de�eri 8 olmal�d�r.)
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*exp(double) -> e'nin verilen paramtre �ss�n� al�r ve geriye d�nderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*frexp(double val, int *us) -> val ismindeki parametre val = k*2^n bi�iminde d���n�l�r, k ve n de�erleri hesaplan�r. (k, [0.5, 1) aral���nda olmal�d�r) Hesaplanan n de�erinin
		adresi *us parametresine, k de�erini ise geriye d�nderir.
		NOT: E�er val = 0 ise k ve n = 0 olacakt�r.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*ldexp(double val, int n) -> val*2^n i�lemini hesaplar ve geriye d�nderir. Bu fonksiyon frexp fonksiyonunun e�leni�idir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*fabs(double) -> Verilen paramtrenin mutlak de�erini al�r ve geriye d�nderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*log(double) -> Verilen parametrenin e taban�nda log yani ln'ini hesaplar ve geriye d�nderir. E�er verilen parametre negatif bir de�ere sahip ise, errno de�i�kenine EDOM atan�r.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*log10(double) -> Verilen parametrenin 10 taban�nda log yani ln'ini hesaplar ve geriye d�nderir. E�er verilen parametre negatif bir de�ere sahip ise, errno de�i�kenine EDOM
		atan�r.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*modf(double x, double *tam) -> x ger�el say�s�n�n tam ve kesirli k�s�mlar�n� ay�r�r ve tam k�sm�n� *tam de�i�kenine, kesirli k�sm�n� geriye d�nderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*fmod(double x, double y) -> x/y i�leminden kalan� d�nderir. E�er y = 0 ise 0, s�f�rdan farkl�ysa i tam say� olmak �zere, x = i * y + fmod(x, y) sa�lama y�ntemini sa�layacak
		�ekilde kalan� hesaplar ve geriye d�nderir. Geriye d�nderilen de�erin i�areti, x de�i�keninin i�areti ile ayn�d�r. (+ / -)
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*mod(double x, double y) -> x^y de�erini hesapla ve geriye d�nderir. E�er x negatif ve y tam say� de�ilse veya x = 0 ve y <= 0 ise EDOM hatas� �retilir ve �o�u derleyicide
		geriye 0.0 d�nderilir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*sqrt(double) -> Verilen parametrenin karak�k�n� hesaplar ve geriye d�nderir. E�er x negatif bir say�ysa EDOM hatas� �retilir ve �o�u derleyicide geriye 0.0 de�eri d�nderilir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
5-Genel Ama�l� Foknsiyonlar Ve K�t�phanesi:
	Baz� simgesel sabitler ve yeni veri tipleri a�a��da verilmi�tir.
EXIT_SUCCESS -> exit fonksiyonunda kullan�l�r. exit(0)
EXIT_FAILURE -> exit fonksiyonunda kullan�l�r. exit(1)
RAND_MAX -> rand fonksiyonun d�nderebilece�i maximum de�er.
typedef struct
{
	int quot;
	int rem;
}div_t;

typedef struct
{
	long int quot;
	long int rem;
}ldiv_t;
	1-<stdlib.h>
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*abort(void) -> Program� ivedi olarak sonland�r�r. Bu normal olmayan bir sonland�rma anlam�nda kullan�l�r. Bunun i�in raise(SIGABRT) fonksiyonu �a�r�l�r. Derleyiciye ba�l�
		olmas�na kar��n, �o�unda a��k olan dosyalar kapat�l�r. Sisteme hatal� sonlanma anlam�nda say� g�nderilir. (DOS'ta bu say� 3'd�r.)
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*abs(int) -> Verilen int tipindeki parametrenin mutlak de�erini hesaplay�p geriye d�nderir. ��aretli say�lar e�er ikiye t�mleyen aritmeti�i ile hesaplan�yor ise en k��k eksi
		say�n�n mutlak de�erine kar��l�k gelen art� say� yoktur. ��nk� farzedelim ki unsigned bir de�i�ken 255 dahil de�er alabiliyor, e�er unsigned olmasayd� [-228, +227] aras�nda
		olacakt�, bu y�zden -228'in mutlak de�er kar��l��� verilemez.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*labs(long int) -> abs fonksiyonundan tek fark� long tipinde olmas�d�r.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*atexit(fonksiyon adresi) -> Program sonland�ktan sonra �al��t�r�lmas� i�in fonksiyonlar� kuyru�e ekler ve program sonland�ktan sonra bu fonksiyonlar �al��t�r�l�r. Maximum
		32 adet fonksiyon kuyru�a kay�t edilebilir. Y�r�tmeler kay�t s�ras�n�n tersi s�rada ilerler yani en son atexit fonksiyonu kullan�ld��� yerden ba�lan�l�r.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*atof(const char *k1) -> k1 katar� i�erisindeki [0, 9] ve '+, -, ., e, E' karakterlerinden herhangi birini buldu�u noktadan ba�layarak i�ermeyen noktaya veya NULL ile
		kar��la�ana kadar okur ve geriye double tipinde d�nderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*atoi(const char *k1) -> k1 katar� i�erisindeki rakamsal karakter olan noktadan ba�layarak i�ermeyen noktaya veya NULL ile kar��la�ana kadar okur ve geriye int tipinde d�nderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*atol(const char *k1) -> atoi fonksiyonu ile ayn�d�r. Tek fark geriye int de�il long int d�nderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*qsort(void *dizi, size_t dizielemansay�s�, size_t elemanbyte, int fonk(int *, int *)) -> Buradaki parametre olarak g�nderilen fonksiyon s�nama i�in kullan�lan
		fonksiyondur. Geriye hi� bir de�er d�ndermez. Dizinin adresi g�nderilmelidir ��nk� dizinin elemanlar�n� de�i�tirmesi gerekmektedir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*bsearch(const void *aranan, const void *dizi, size_t dizielemansay�s�, size_t elemanbyte, int fonk(int *, int *)) -> void olarak bildirilen yerler tipi belirli de�il anlam�nda
		herhangi bir tip i�in ge�erli olabilir olarak kullan�lm��t�r. Bu fonksiyon k���kten b�y��e s�ralanm�� bir dizi i�erisinde aranan de�i�kenini ilerde g�rece�imiz ikili arama
		(binary search) algoritmas� ile arayarak, e�er bulunursa bulunan de�erin adresini, bulunamazsa NULL d�nderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*malloc(size_t) -> ��letim sisteminden verilen parametre kadar sekizli (1 byte) bellek tahsis etmek i�in kullan�l�r. E�er bellek de istenilen bellek miktar� var ise bellek de
		yer ayr�l�r ve ba�lang�� adresini geriye d�nderir. E�er bellek de istenilen kadar yer yoksa geriye NULL d�nderir. Geriye d�n�� tipi void olarak belirtildi�inden dolay� t�m
		veri tipleri i�in kullan�labilir fakat cast edilmesi gerekir.(�rne�in int *a; i�in kullan�rsak a = (int *)malloc(size_t) �eklinde kullan�lmal�d�r.)
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*calloc(size_t n, size_t k) -> Temelinde malloc fonksiyonu ile ayn� g�revi yapan calloc fonksiyonu, n*k byte bellek tahsilat� i�in kullan�l�r. Yani k yerine genellikle bellek
		alan� almak istedi�imiz de�i�ken tipinin ka� byte alan kaplad���d�r. Geriye e�er alan ay�rma ba�ar�l� ise ba�lang�� adresini, ba�ar�s�z ise NULL d�nderir. Yine malloc fonksiyonu
		gibi bu fonksiyon da geriye void d�nderir, dolay�s� ile cast etme gereklidir. (int a = (int *)calloc(lenght, sizeof(int)))
		NOT: malloc ve calloc s�ylenildi�i gibi temellerinde ayn� i�levi g�r�rler ve g�zle g�r�lebilir farklar� malloc 1 byte varsay�lan olarak se�erken, calloc fonksiyonu i�in byte
		say�s�n� manuel olarak se�iliyor fakat aralar�nda tek fark da bu de�ildir. malloc fonksiyonu varsay�lan olarak char haricindeki veri tiplerinde bir de�er atmazken, calloc
		varsay�lan olarak 0 de�erini atamaktad�r.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*realloc(void *val, size_t n) -> Daha �nce malloc veya calloc ile bellek alan� tahsis edilmi� ve bu tahsis edilen bellek ba�lang�� adresini tutan val de�i�keni i�in, tahsis
		edilen bellek adresinin de�i�tirilmesini sa�lar. Verilen bellek miktar�n�n artt�r�lmas� veya azalt�lmas�n� sa�lar. E�er artt�r�lmas� isteniyorsa �nceden tahsis edilmi� bellek
		alan�ndaki veriler kopyalan�r ve yeni tahsis edilen bellek alan�na yerle�tirilir yani eski verilerin kaybolmas� engellenir. E�er azalt�lmas� isteniyorsa �nceden tahsis edilmi�
		bellek alan�ndaki veriler kopyalan�r ve ba�tan itibaren s��abildi�i kadar� ile yerle�tirilir. Eski bellek alan� serbest b�rak�l�r. �stenilen kadar yer yoksa geriye NULL,
		tahsis edilme i�lemi yap�l�r ise hem val parametresine hem de geriye ba�lang�� adresi d�nderilir. E�er val parametresi yerine NULL yerle�tirilirse n > 0 i�in malloc fonksiyonu
		i�levi, n = 0 ise free fonksiyon i�levini yapar.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*free(void *p) -> Verilen parametre ram de ayr�lm�� bir bellek alan�n�n ba�lang�� adresini g�sterdi�i varsay�larak bu bellek adresini serbest b�rakmak i�in kulan�l�r. Geriye
		herhangi bir de�er d�ndermez.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*div(int pay, int payda) -> Yukarda verilen div_t tipinde geriye d�n�� sa�lar. Sa�lad��� bu div_t tipindeki ilk �yeye (quat) (int)23/4 = 5, ikinci �yeye (rem) kalan yani 3
		atan�r.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*ldiv(long int pay, long int payda) -> div fonksiyonundan tek fark� long olmas�d�r.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*exit(int durum) -> A�a��daki i�lemler yap�ld�ktan sonra program sonland�r�l�r ve verilen parametreyi sisteme g�nderir. Geriye d�n�� sa�lamaz.
			-atexit fonksiyonuna bildirilmi� t�m fonksiyonlar �al��t�r�l�r.
			-B�t�n dosyalar kapat�l�r.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*getenv(const char *k1) -> ��letim sistemi �zerinde �al��an simgesel sabitlerin de�erinin ba�lang�� adreslerini d�nderir. �rne�in "PATH" parametre olarak g�nderilirse i�letim
		sistemi �zerinde �al��an i�lemlerin dosya konumlar�n�n char tipindeki ba�lang�� adresleri d�nderilir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*rand(void) -> Rastgele say� �retmek i�in kullan�l�r. Say� 0 ile RAND_MAX aras�ndad�r. % operat�r� ile bunu k���ltebiliriz. Geriye �retilen say�y� d�nderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*srand(int cekirdek) -> Rastgele say� �reticisinin �ekirdek say�s�n� de�i�tirmek i�in kullan�l�r. B�ylece rand fonksiyonu pe� pe�e �a�r�ld��� zaman farkl� say� vermesi sa�lan�r.
		Program �al��t�ktan sonra �ekirdek say�s� de�i�tirilmemi� ise 1 dir. �ekirdek say�s�n�n de�i�tirilmesi i�in genellikle zaman fonksiyonlar� kullan�l�r. Geriye herhangi bir de�er
		d�ndermez.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*strtod(const char *k1, char **sonch) -> Verilen katar i�erisindeki [0, 9] ve "+, -, ., e ve E" karakterlerininden herhangi birinden ba�layarak bunlar d���ndaki karakterleri
		g�rene kadar veya NULL ile kar��la�ana kadar okur ve geriye d�nderir. sonch pointer pointer�na okuman�n bitmesine sebep olan bellek adresini atar. Geriye double tipine
		d�n��t�r�lm�� de�eri d�nderir. E�er sonch yerine NULL g�nderilirse atof fonksiyonu ile ayn� �ekilde �al���r. E�er d�n��t�r�lme i�lemi ba�ar�l� olmazsa sonch de�i�kenine k1
		katar�n�n ba�lang�� adresi at�l�r ve geriye d�necek de�er derleyiciye kalm��t�r ve �o�u derleyicide 0.0 d�r.
		(�rne�in double val; char k1[] = {Abdullah 2003.57 ile c dersleri}; char *ptr; de�i�kenleri i�in val = strtod(k1, ptr) i�leminde val = 2003.57000 ve ptr = ba�lang�� adresi
		ve bu ba�lang�� adresininin de�erini yazd�r�rsak = "ile c dersleri.")
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*strtol(const char *k1, char **sonch, int taban) -> k1 katar� i�erisindeki say�sal de�eri tabana g�re (0 girilir ise sekizlik anlama gelir ve [0, 7] ve "+, -, ., e ve E"
		karakterleri, 0x girilir ise onalt�l�k anlama gelir ve [0, 9] - [A, F] ve "+, -, ., e ve E" geri kalanlar i�in ondal�k [0, 9] ve "+, -, ., e ve E" karakterleri) d�n���m
		i�lemine ba�lar. NULL veya d�n���me uymayan karakter ile kar��la��ld��� zaman okuma i�lemi sonland�r�l�r ve sonch ye bu karakterin adresi atan�r. Geriye d�n��t�r�len bu de�er
		long int tipinde d�nderilir. E�er sonch yerine NULL girilirse atol fonksiyonu ile ayn� �al���r. E�er okuma i�lemi ba�ar�s�z olursa sonch parametresine k1 katar�n�n ba�lang��
		adresi atan�r. Taban parametresi 2 ile 36 aras�nda olabilir (0 da yaz�labilir).
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*strtoul(const char *k1, char **sonch, int taban) -> strtol ile ayn�d�r tek fark� "+, -, ., e ve E" i�erisindeki - i�aretini okuma yapmaz. ��nk� unsigned dir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	 	*system(const char *cmd) -> Kendisine verilen sistem komutunu y�r�tmek i�in kullan�r. Bu komutu y�r�tmek i�in komut yorumlay�c�s�na ihtiya� vard�r. E�er komut yorumlay�c�s�
	 	i�in cmd yerine NULL yaz�l�r ise, sonu� 0 dan farkl� ise vard�r, 0 ise yoktur.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
6-Esnek Arg�man Aktar�m Fonksiyonlar� Ve K�t�phanesi:
	Bir fonksiyonun farkl� say�larda arg�man alabilmesi i�in 1 tip bildirimi ve 3 makro fonksiyonu olan stdarg.h k�t�phanesi yaz�lm��t�r.
	1-<stdarg.h>
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*va_start(va_list, ilkarguman) -> Bilindi�i gibi farkl� say�da parametre ile �al��an bir fonksiyon yazabilmek i�in sabit bir adet formal bildirim yap�lmas� gerekir. Bu
		fonksiyon verilen bu ilkarguman'dan sonra gelen ilk paremetreden ba�layarak sona kadar verilen va_list tipindeki parametre i�erisine atar. �lk bu fonksiyon �a�r�l�r.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*va_arg(va_list, type) -> va_start fonksiyonu �a�r�ld��� anda ilk olarak birtane static counter tan�mland���n� d���nelim ve bu counter va_arg fonksiyonu ile artar. Arguman
		listesinden belirtilen tipdeki ve counter indisindeki de�eri geriye d�nderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*va_end(va_list) -> Belirtilen alma i�leminin kapat�lmas� i�in kullan�l�r.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
7-Tarih Ve Zaman Fonksiyonlar� Ve K�t�phanesi:
	Zaman ve tarih ile ilgili fonksiyonlar�n bildirilmesi ve baz� yeni veri tiplerinin bildirilmeri yap�lan time.h k�t�phanesi
typedef long clock_t;
typedef long time_t;

struct tm 
{
	int tm_sec; -> Saniye i�in [0, 59]
	int tm_min; -> Dakika i�in [0, 59]
	int tm_hour; -> Saat i�in [0, 23]
	int tm_mday; -> G�n i�in [0, 31]
	int tm_mon; -> Ay i�in [0, 11]
	int tm_year; -> Y�l i�in [1900, ...]
	int tm_wday; -> Haftan�n g�nleri i�in (Pazartesi, Sal�, ...., Cumartesi, Pazar)[0, 6]
	int tm_yday; -> Y�l�n g�nleri i�in [0, 365]
	int tm_isdst; -> tm_isdst > 0 ise yaz saati uygulan�yor.
}
	1-<time.h>
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*clock(void) -> Program ba�lad�ktan sonra ka� saat darbesi ge�ti�ini geriye d�nderir. Saniye cinsinden ��renmek i�in CLK_TCK adl� simgesel sabite b�l�nerek ��renilebilir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*time(time_t *) -> 1970 tarihinden itibaren ge�en zaman� saniye cinsinden fonksiyona gelen parametreye g�nderir ve geriye d�nderir. E�er parametre olarak NULL girilirse geriye
		yine 1970 tarihinden bu yana ge�en zaman� saniye cinsinden d�nderir.
		Not: time_t de�i�keni bildirildi�i zaman varsay�lan olarak 70 ler saniyesine g�re de�er al�r.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*gmtime(time_t *) -> Parametre olarak gelen saniye cinsinden zamana g�re, GMT (Greenwich Mean Time) uygun olarak struct tm toplulu�una yerle�tirir ve geriye ba�lang�� adresini
		d�nderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*localtime(time_t *) -> gmtime fonksiyonu ile ayn� i�levi g�r�r. Aralar�ndaki fark bu fonksiyon GMT'ye g�re de�il yerel zamana g�re toplulu�a yerle�tirir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*asctime(const struct tm *) -> Kendisine gelen saniye cinsinden zaman� (Burada zaman toplulu�unun tamam� bildirilmi�) kullanaraki zaman ve tarihle ilgili bilgileri ekrana
		yaz�lacak bi�imde (Sonuna NULL ekleyerek) karakter katar�na d�n��t�r�r. Katar, GGG(G�n thu gibi) AAA(Ay aug gibi) gg(Ay 15 gibi) ss(Saat):dd(Dakika):xx(Saniye) YYYY(Y�l)\n\0
		format�nda olur.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*ctime(const time_t *) -> asctime ile ayn� i�levi g�r�r fakat bu sefer toplulu�a g�re de�il de saniyeye g�re i�lem yapar.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*mktime(const struct tm *) -> gmtime ve localtime fonksiyonlar�n�n tam tersini yapar. Yani toplulu�a g�re geriye saniye d�nderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*strftime(char *k1, size_t katarboyutu, const char *format, const struct tm *) -> Bu fonksiyon k1 katar� i�erisine katarboyutu kadar *formatda struct tm i�erisindeki zaman
		ve tarih bilgilerini atar. Geriye at�lan karakter say�s�n� size_t tipinde d�nderir.
			%a -> Fri bi�iminde haftan�n g�nleri.
			%A -> Friday bi�iminde haftan�n g�nleri.
			%s -> Apr bi�iminde aylar.
			%S -> April bi�iminde aylar.
			%c -> Apr 15 21:10:15 2020 bi�iminde tarih ve zaman.
			%d -> Ay�n say�sal g�n� 15.
			%h -> a.m - p.m bi�iminde saat.
			%H -> 24'l�k bi�imde saat.
			%j -> Y�l�n g�n�.
			%m -> Y�l�n ay�.
			%M -> Dakika.
			%p -> a.m - p.m.
			%s -> Saniye.
			%U -> Y�l�n haftas�.
			%w -> Haftan�n g�n� say�sal olarak.
			%x -> Apr 15 2020 bi�iminde tarih.
			%X -> 21:10:15 bi�iminde zaman.
			%y -> Y�zy�l�n tarihi. (�rne�in 1970 i�in 70 2020 i�in 120)
			%Y -> Y�l.
			%Z -> Zaman b�lgesi.
			%% -> % karakteri.
 		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*difftime(time_t, time_t) -> Saniye cinsinden verilen iki zaman� ��kart�r ve yine saniye cinsinden geriye d�nderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
8-Yerel Olmayan Dallanma Foknsiyonlar� Ve K�t�phanesi:
	Yap�sal bir dil olan C programlama dili i�inde dallanma deyimi 'goto' kullan�lmas�na gerek olmayacak bi�imde esnek kontrol ve d�ng� deyimleri vard�r. Ama yine de baz� zamanlarda
bu dallanma yap�lmas� gerekebilir. Dallanma fonksiyonlar� 'goto' ile yap�lan yerel dallanma ve setjmp.h fonksiyonu ile yap�lan yerel olmayan dallanma olarak ikiye ayr�l�r. Bu k�t�phane
i�erisinde bir adet �zel de�i�ken bildirimi ve iki adet makro fonksiyon tan�mlanm��t�r. De�i�ken tipi jmp_buf olup bu tipte bir de�i�ken, i�lemci i�erisindeki saklay�c�lar�n
herhangi bir andaki de�erlerini tutacak yap�dad�r.
	1-<setjmp.h>
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*setjmp(jmp_buf) -> ��erisine ald��� parametreye g�re geli� kap�s� a�ar ve ilk �a�r�ld���nda 0 d�nderir. Daha sonra longjmp fonksiyonuna g�nderilen 2. parametrenin de�erini
		d�nderir. D�n�� tipi int. 
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*longjmp(jmp_buf, int) -> Belirtilen ilk parametredeki jmp_buf tipindeki de�i�ken set edilmi� ise set edilen noktaya gider ve o noktadaki set fonksiyonunun geri d�n�� de�erini
		ikinci parametre olarak ayarlar.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
9-Ayr�cal�kl� Durum Kontrol� Fonksiyonlar� Ve K�t�phanesi:
	Baz� durumlarda program (s�f�ra b�lme gibi) i�erisinde ayr�cal�kl� durumlar meydana gelebilir ve sistem bunun i�in baz� fonksiyonlar� �a��r�r.
	1-<signal.h>
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*signal(int, fonk) -> Sistemin kendine ait belirtilen ayr�cal�kl� durum kontrol fonksiyonu (1. parametre) yerine ikinci parametredeki fonksiyon bu belirtilen durumda �al���r.
		Sadece bir kerelik olarak bu de�i�imi yapar. Tekrar yapmak isteniyorsa fonksiyon tekrar �a�r�lmal�d�r.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*raise(int) -> Belirtilen ayr�cal�kl� durumunu �a��r�r ve �a��rmas�na neden olan durum i�in fonksiyon de�i�ir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
10-Hata Ay�klama (Diagnostics) Fonksiyonlar Ve K�t�phanesi:
	Hatalar yaz�m ve mant�k hatas� olarak ikiye ayr�l�r. Yaz�m hatalar� derleyici taraf�ndan bildirilirken, mant�k halatar� i�in �zel edit�rler veya assert.h k�t�phanesi kullan�labilir.
	1-<assert.h>
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*assert(ko�ul) -> Belirtilen ko�ul sa�lan�rsa stderr'in i�aret etti�i dosyaya (varsay�lan olarak console) Assertion Failed: dosya ad� sat�rno bi�iminde bir mesaj g�nderir.
		Geriye hi�bir�ey d�ndermez. Bu hata ay�klaman�n en iyi yan� istenilen yere istenildi�i say�da assert i�lemi yaz�labilmesidir. E�er kald�r�lmak isteniyorsa k�t�phane
		bildiriminden �nce #define NDEBUG yaz�lmas� yeterlidir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
11-Lokalizasyon Fonksiyonlar Ve K�t�phanesi:
	Baz� durumlarda �rne�in �ngilizce de T�rk�e karakterler desteklenmemektedir ve bu y�zden kullan�c�ya sunulan bir programda e�er kullan�c� T�rk ise baz� sorunlar ortaya ��kacakt�r.
Bu sorunlardan bir tanesi � harfi gibi baz� harflerin yaz�lamamas�d�r.

		1-<locale.h>
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*setlocale(simgesel sabit, const char *k1) -> �lk parametre locale.h k�t�phanesi i�erisinde bildirilen baz� simgesel sabitleri al�r. Bu simgesel sabitler
			-LC_ALL -> T�m durumlar i�in.
			-LC_COLLATE -> Katar kar��la�t�rma i�lemlerinin yap�lmas� durumlar�na g�re kullan�l�r.
			-LC_CTYPE -> Karakter kar��la�t�ma fonksiyonlar� i�in kullan�l�r.
			-LC_NUMERIC -> Ger�el say�larda bilindi�i gibi tam k�s�m ile ondal�kl� k�s�m . ile ayr�l�yor. Baz� dillerde bu nokta karateri desteklenmez ise bu fonksiyon da o b�lge i�in
			set edilirse . yerine , kullan�labilir.
			-LC_TIME -> Zaman fonksiyonlar�nda desteklenmeyen bir karakter var ise belirtilen dile g�re desteklenen ba�ka bir karakter yerle�tirilir.
			�kinci olarak belirtilen simgesel sabit yerine belirtilen konumu "Turkish" "Euro" "English" gibi belirtilir. E�er set i�lemi ba�ar�s�z olursa geriye NULL, ba�ar�l� olursa
		geriye katar bir adres d�nderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

�DEVLER
	**-Mant�ksal bir ili�ki kurarak karakter �zerinde i�lem yapan fonksiyonlar ile her durumu kontrol edecek �ekilde bir program yaz�n�z.
	**-Mant�ksal bir ili�ki kurarak katarlar �zerinde i�lem yapan fonksiynolar ile ayr� ayr� �rnekler yaz�n�z.
	**-Dosyalama i�lemlerinde kullan�lan freopen fonksiyonunda stdin, stdout veya stderr fonksiyonlar�n�n de�erlerini de�i�tirdikten sonra tekrardan console ekran� nas�l yap�l�r ?
	**-tmpfile() fonksiyonunu ara�t�r kullanmay� dene hatalar� ��z.
	//-E-Ticaret sitesi kurdu�unuzu ve �ye ol, �ye giri�i ve parolam� unuttum k�sm� olsun. �ye ol k�sm�nda da �zel soru ba�l��� alt�nda �zel bir veri isteyin. Daha sonra parolam�
	unuttum yap�ld��� zaman o �zel karakter ile s�f�rlama yap�labilsin. �ye giri�i yap�ld�ktan sonra stok ta olan �r�nler listelensin stokta biten �r�nler g�r�nt�lenmesin fakat
	silinmesinde. Bir c�zdan olsun ve c�zdana giri� yap�ld���nda bakiye g�sterilsin ve bakiye y�kleme se�ene�i olsun. Bakiye y�klemede 16 haneli bir kart numaras� istensin ve bu
	kart numaras� e�er birinci ve ikinci hanelerinin toplam�n�n birler basama�� onalt�nc� hanesinin basama��na e�it ve 2 ye b�l�nebilir olmas� �art� olsun. B�t�n bunlar dosyalama
	i�lemi ile yap�lacakt�r.
	**-vscanf, vsscanf, vfscanf fonksiyonlar� varm� varsa ara�t�r.
	**-��letim sistemi simgesel sabitlerini ara�t�r�n.
	//-scanf fonksiyonunu yaz.
	**-Standart k�t�phaneler yard�m� ile atoi fonksiyonunun yapt��� i�i yapan bir fonksiyon yaz.
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
	olu�turmak performans� etkiler. Bu y�zden bir tane klavyeden girilen metni tutan ge�ici bir buf isiminde sabit bir dizi ile tutulup daha sonradan bunun say�s�na g�re pointera
	bellek ay�rma yap�yoruz. k1 pointer�n�n boyutunu artt�r�yoruz ki k2 pointer�n�n de�erini de tutabilsin.*/
	char buf[100]; /*Klavyeden girilen yaz�n�n boyutunu ��renmek i�in kullan�lan ge�ici bellek olarak d���n�lebilir.*/
	char *k1;
	char *k2;
	char src;
	int buflenght;
	int i;
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
	char *k1;
	char *k2;
	char src;
	int buflenght;
	int i;
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
	char *k1;
	char *k2;
	char *src;
	int buflenght;
	int i;
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
	char *k1;
	char *k2;
	char *src;
	int buflenght;
	int i;
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

program3()
{
	FILE *f;
	char mod;
	char selection;
	char *dataToFile;
	do
	{
		/*mod tek karater alabildi�i i�in r+, w+ ve a+ yerine R, W ve A yaz�lmas� istenmi�tir.*/
		printf("Yanl�zca Okuma(Yeni dosya olu�turulamaz.)[r]\nYanl�zca Yazma(Yeni dosya olu�turulur.)[w]\nYanl�zca Ekleme(Dosya yoksa yeni dosya olu�turulabilir.)[a]\n");
		printf("Okuma Ve Yazma(Yeni dosya olu�turulamaz.)[R(r+)]\nYazma Ve Okuma(Yeni dosya olu�turulur.)[W(w+)]\nEkleme, Yazma ve Okuma(Dosya yoksa yeni dosya olu�turulabilir.)");
		printf("[A(a+)]\nDosya hangi mod da a��lacak: ");
		mod = getch();
		printf("%c\n", mod);
		switch(mod)
		{
			case 'r':
				if(fopen("dosya.txt", "r") == NULL) /*Dosya dizinde yoksa, yazma modu ile a��lamaz NULL d�nderir.*/
				{
					printf("\n");
					puts("Dosya dizinde yoktur ! Tekrar y�nlendiriliyorsunuz.");
					mod = '\0';
				}
				else
				{
					int i;
					f = fopen("dosya.txt", "r");
					printf("\n");
					puts("Dosya r modunda a��ld� !");
				}
				break;
			case 'w':
				if(fopen("dosya.txt", "r") != NULL)
				{
					do
					{
						printf("Dosya dizinde mevcuttur. Yeniden yazma modunda a�mak dosya i�erisindeki verilerin s�f�rlanmas�na neden olacakt�r. Yinede a�mak istiyormusunuz");
						printf("[E]/[H]: ");
						selection = getch();
						switch(tolower(selection)) /*Kullan�c� b�y�k harf de girebilir e�er b�y�k harf girerse kontrol etmek zorla�aca�� i�in k���k harfe d�n��t�r�l�yor.*/
						{
							case 'e':
								f = fopen("dosya.txt", "w");
								printf("E\n");
								puts("Dosya olu�turuldu ! w modun da a��ld�.");
								break;
							case 'h':
								printf("H\n");
								puts("Mod se�imine tekrar y�nlendiriliyorsunuz !");
								break;
							default:
								printf("\n");
								printf("Se�im anla��lmad� !\n");
								selection = '\0';
								break;
						}
					}
					while(selection == '\0');
				}
				else
				{
					f = fopen("dosya.txt", "w");
					printf("\n");
					puts("Dosya olu�turuldu ! w modun da a��ld�.");
				}
				break;
			case 'a':
				f = fopen("dosya.txt", "a");
				printf("\n");
				puts("Dosya a modunda a��ld� !");
				break;
			case 'R':
				if(fopen("dosya.txt", "r") == NULL) /*Dosya dizinde yoksa, yazma modu ile a��lamaz NULL d�nderir.*/
				{
					printf("\n");
					puts("Dosya dizinde yoktur ! Tekrar y�nlendiriliyorsunuz.");
					mod = '\0';
				}
				else
				{
					int i;
					f = fopen("dosya.txt", "r+");
					printf("\n");
					puts("Dosya r+ modunda a��ld� !");
				}
				break;
			case 'W':
				if(fopen("dosya.txt", "r") != NULL)
				{
					do
					{
						printf("\n");
						printf("Dosya dizinde mevcuttur. Yeniden yazma modunda a�mak dosya i�erisindeki verilerin s�f�rlanmas�na neden olacakt�r. Yinede a�mak istiyormusunuz");
						printf("[E]/[H]:");
						selection = getch();
						switch(tolower(selection))
						{
							case 'e':
								f = fopen("dosya.txt", "w+");
								printf("E\n");
								puts("Dosya olu�turuldu ! w+ modun da a��ld�.");
								break;
							case 'h':
								printf("H\n");
								puts("Mod se�imine tekrar y�nlendiriliyorsunuz !");
								break;
							default:
								printf("\n");
								printf("Se�im anla��lmad� !\n");
								selection = '\0';
								break;
						}
					}
					while(selection == '\0');
				}
				else
				{
					f = fopen("dosya.txt", "w+");
					printf("\n");
					puts("Dosya olu�turuldu ! w+ modun da a��ld�.");
				}
				break;
			case 'A':
				f = fopen("dosya.txt", "a+");
				printf("\n");
				puts("Dosya a+ modunda a��ld� !");
				break;
			default:
				puts("\nGe�ersiz bir de�er girildi tekrar y�nlendiriliyorsunuz !");
				mod = '\0';
				break;
		}
	}
	while(mod == '\0');
	/*Yukarda sadece dosya a��lmas� yap�lm��t�r.*/
	fclose(f);
	f = tmpfile(); /*w+ modunda ge�ici bir dosya a�ar. Program kapat�ld���nda silinir.*/
	perror("Hata mesaj�");
	getch();
	/*A�a��da bir hata alacaks�n�z hata �u ilk yaz� ve ikinci yaz� yazd�ktan sonra ���nc� yaz�dan �nce bir Abdullah yaz�s� g�r�n�yor dosyada peki bu neden*/
	dataToFile = (char *)malloc(sizeof(char) * 8);
	strcpy(dataToFile, "Abdullah");
	fopen("dosya1.txt", "w");
	fprintf(f, "%s ile c dersleri ilk yaz� !\n", dataToFile);
	fwrite("Abdullah ile c dersleri ikinci yaz� !", 1/*Her verinin ka� binary oldu�u bizimde char oldu�u i�in 1*/, 50/*Ka� binary belirtildi ise tek eleman 1 olmak �zere *binary*/, f);
	fputs("\nAbdullah ile c dersleri ���nc� yaz� !\n", f);
	fputc(103, f); /*g harfi*/
	fclose(f);
}

void program5_1()
{
	puts("Program sonland�r�lmadan �nce !");
	atexit(program2_1);
	atexit(program1);
	/*abort(); Console ekran�nda return value de�eri 3 oldu�u g�zlenecektir. atexit fonksiyonlar� abort yani anormal bi�imde sonlanma halinde �al��mazlar.*/
	exit(1);
}

int program5_2fonk(int *a, int *b) /*S�nama fonksiyonu*/
{
	/*Buran�n i�erisinde e�er a - b = 0 ise e�it, a - b > 0 ise a b'den b�y�k veya a - b < 0 ise b a'dan b�y�k olur ve biz bu fonksiyondan geriye bunu d�ndeririz ve bu fonksiyondaki
	geri d�n�� de�erine g�re bsearch fonksiyonu i�lem yapar.*/
	return *a - *b;
}

void program5_2()
{
	int arylenght;
	int i;
	int *ary;
	int *found;
	int sval;
	srand(time(NULL));
	printf("Kullan�lacak dizinin eleman say�s�: ");
	scanf("%d", &arylenght);
	ary = (int *)malloc(sizeof(int) * arylenght);
	puts("");
	/*Dizinin elemanlar�n� rastgele at�yoruz.*/
	for(i = 0; i < arylenght; i++)
		*(ary + i) = rand() % 1000;
	/*Dizinin elemanlar�n� bsearch fonksiyonunda kullanmak i�in qsort fonksiyonu ile k���kten b�y��e s�ral�yoruz.*/
	qsort(ary, arylenght, sizeof(int), (void *)program5_2fonk);
	for(i = 0; i < arylenght; i++)
		printf("%d.eleman: %d\n", i + 1, *(ary + i));
	/*Arama i�lemi yap�yoruz.*/
	printf("Aranan de�er: ");
	scanf("%d", &sval);
	found = bsearch(&sval, ary, arylenght, sizeof(int), (void *)program5_2fonk); /*Aranan de�erin adresi girilmelidir.*/
	/*Bulunup bulunmad���n� kontrol ediyoruz.*/
	if(found != NULL)
	{
		/*Bulunan de�erin indis numaras�n� buluyoruz.*/
		i = 0;
		while(found != (ary + i))
			i++;
		printf("Aranan de�er %p adresinde %d.indiste bulundu !\n", found, i);
	}
	else
		puts("Aranan de�er dizi i�ersiinde bulunmuyor !");
	free(ary);
}

void program5_3()
{
	int pay;
	int payda;
	div_t bolme;
	printf("B�lme i�lemini a/b format�nda giriniz: ");
	scanf("%d/%d", &pay, &payda);
	bolme = div(pay, payda);
	printf("B�lme i�leminde b�l�m: %d, kalan: %d\n\n", bolme.quot, bolme.rem);
	printf("Sorgulama sonucu: \n%s", getenv("DATE"));
}

void program5_4()
{
	system("HELP");
}

typedef struct
{
	int d;
	char c;
	float f;	
}v;

void yaz(char *str, ...)
{
	/*Bu uygulamada printf fonksiyonu gibi �al��an bir fonksiyon yaz�lacak.*/
	int i; int counter;
	i = counter = 0; 
	char temp; char buf[100];
	va_list argumans;
	v var;
	va_start(argumans, str);
	while(*(str + i) != '\0')
	{
		if(*(str + i) == '%')
		{
			i++;
			temp = *(str + i);
			switch(temp)
			{
				case 'd':
					counter = 0;
					var.d = va_arg(argumans, int);
					itoa(var.d, buf, 10);
					while(buf[counter] != '\0')
					{
						putch(buf[counter++]);
					}
					i++;
					break;
				case 'i':
					counter = 0;
					var.d = va_arg(argumans, int);
					itoa(var.d, buf, 10);
					while(buf[counter] != '\0')
					{
						putch(buf[counter++]);
					}
					i++;
					break;
				case 'f':
					counter = 0;
					var.f = va_arg(argumans, double);
					gcvt(var.f, 8, buf);
					while(buf[counter] != '\0')
					{
						putch(buf[counter++]);
					}
					i++;
					break;
				case 'c':
					var.c = va_arg(argumans, int);
					putch(var.c);
					i++;
					break;
				case 's':
					strcpy(buf, va_arg(argumans, char*));
					for(counter = 0; counter < strlen(buf); counter++)
						putch(buf[counter]);
					i++;
					break;
				case '%':
					putch('%');
					i++;
					break;
			}
		}
		else
		{
			putch(*(str + i));
			i++;
		}
	}
	va_end(argumans);
}

void program7()
{
	time_t s = time(NULL);
	time(&s);
	/*Yukar�daki iki i�lem de ayn� �eyi ifade eder.*/
	clock_t cl;
	clock_t cl1;
	struct tm *z;
	char ktr[250];
	z = gmtime(&s);
	puts("GMT'ye g�re");
	printf("Saat: %d, Dakika: %d, Saniye: %d, G�n: %d, Ay: %d, Y�l: %d\n", z->tm_hour, z->tm_min, z->tm_sec, z->tm_mday, z->tm_mon + 1, z->tm_year + 1900);
	z = localtime(&s);
	puts("Yerel zamana g�re");
	printf("Saat: %d, Dakika: %d, Saniye: %d, G�n: %d, Ay: %d, Y�l: %d\n", z->tm_hour, z->tm_min, z->tm_sec, z->tm_mday, z->tm_mon + 1, z->tm_year + 1900);
	puts("");
	printf("asctime: %s\nctime: %s\n", asctime(z), ctime(&s));
	s = mktime(z);
	printf("Toplulu�a g�re zaman %d\n", s);
	strftime(ktr, 250, "%B(%m) - %A(%d) - %Y", z);
	puts(ktr);
	int i = 0;
	puts("Registers�z de�i�ken ile while d�ng�s�.");
	getch();
	cl1 = clock();
	while(i < 10000)
		printf("%d\n", i++);
	cl = clock();
	printf("%d saniye oldu.\n", ((cl - cl1) / CLK_TCK));
	puts("Register de�i�ken ile while d�ng�s�.");
	getch();
	register int a;
	cl1 = clock();
	while(a < 10000)
		printf("%d\n", a++);
	cl = clock();
	printf("%d saniye oldu.\n", ((cl - cl1) / CLK_TCK));
}

void jmpfonk(jmp_buf *p)
{
	puts("Fonksiyon �a�r�ld�. Geri dallanma yap�l�yor...");
	longjmp(*p, 1); /*Bu fonksiyon �a�r�ld�ktan sonra setjmp fonksiyonuna return de�eri olarak 2. parametreyi g�nderir.*/
}

void program8()
{
	int x;
	jmp_buf p;
	x = setjmp(p); /*goto deyiminde nokta: gibi gidi� kap�s� a��l�yor.*/
	if(x)
	{
		printf("Yerel olmayan dallanma yap�ld�, x: %d\n", x);
		exit(x);
	}
	puts("�f i�erisine girilmedi fonksiyon �a�r�l�yor...");
	jmpfonk(&p);
}

void ayricalik()
{
	int selection;
	printf("Ayr�cal�kl� durum alg�land�.\n");
	do
	{
		printf("��k��[0]\nDevam[1]\nSe�im: ");
		selection = getch() - '0';
		switch(selection)
		{
			case 0:
				exit(1);
				break;
			case 1:
				puts("Devam ediliyor.");
				signal(SIGINT, ayricalik); /*SIGINT de�i�keni e�er 0 a b�lme ayr�cal�k durum ya�an�rsa sistem taraf�ndan �al��t�r�lacak fonksiyondur.*/
				break;
		}
	}while(selection == 0);

}

void program9()
{
	float a; float b; float result;
	int selection;
	signal(SIGINT, ayricalik); /*SIGINT de�i�keni e�er 0 a b�lme ayr�cal�k durum ya�an�rsa sistem taraf�ndan �al��t�r�lacak fonksiyondur.*/
	do
	{
		printf("a/b format�nda iki adet say� giriniz: ");
		scanf("%f/%f", &a, &b);
		if(!a) /*a == false yani a == 0 durumu kontrol ediliyor.*/
			raise(SIGINT);
		if(!b)
			raise(SIGINT);
		result = a / b;
		printf("Tekrar B�lme Yap�lacak m�\n��k��[0]\nDevam[1]\nSe�im: ");
		selection = getch() - '0';
		switch(selection)
		{
			case 0:
	
				break;
			case 1:
				puts("Devam ediliyor.");
				break;
		}
	}while(selection != 0);
	printf("Sonu�: %f", result);
}

void program10()
{
	int inpval;
	printf("0'dan b�y�k bir de�er giriniz: ");
	scanf("%d", &inpval);
	if(inpval > 0)
		printf("Girilen de�er: %d\n", inpval);
	else
		assert(inpval > 0);
	puts("Element");
}

void main()
{
	puts(setlocale(LC_ALL, "Turkish"));
	/*1 Karakter �zerinde i�lem yapan fonksiyonlar �rnekleri*/
	//program1();
	/*2 Katarlar �zerinde i�lem yapan fonksiyonlar �rnekleri*/
	//program2_1();
	//program2_2();
	//program2_3();
	//program2_4();
	/*3 Standart I/O fonksiyonlar� �rnekleri*/
	//program3();
	/*5 Genel ama�l� fonksiyonlar �rnekleri*/
	//program5_1();
	//program5_2();
	//program5_3();
	//program5_4();
	/*6 Esnek arg�man aktar�m� fonksiyonu*/
	/*int a = 5; float b = 128.4782; char temp[] = "(Bu bir string)";
	yaz("Abdullah %d ile %d%d deneme. Float: %f String: %s Char: %c  %%", 2000, a, 500, b, temp, 'a');*/
	/*7 Zaman ve tarih fonksiyonu*/
	//program7();
	/*8 Yerel olmayan dallanma fonksiyonu*/
	//program8();
	/*9 Ayr�cal�kl� durum kontrol� fonksiyonlar�*/
	//program9();
	/*10 Hata ay�klama fonksiyonu*/
	//program10();
}

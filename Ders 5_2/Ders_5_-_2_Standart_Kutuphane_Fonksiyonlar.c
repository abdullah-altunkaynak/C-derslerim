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
		*printf("", ...) -> �lk parametresine yaz�lan metin baz� kontrol karakterleri, sabitler ve de�i�kenler hari� direkt olarak yazd�r�l�r. Kontrol karakterlerinden % ve \ i�areti
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
		*scanf("", ...) -> Yine i�erisine belirsiz say�da de�i�ken al�r. �lk parametrede belirtildi�i formatta stdin �zerinden (burada tampon console ekran�d�r.) istenile veri
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
//		teker teker �a��rarak okuyorduk, bunun yerine vprintf ile yazd�r�lan va_list argumanlar t�m argumanlar� ekrana yazar. Geriye arg�man say�s�n� d�nderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		vsprintf(char *k1, "", va_list arguman) -> vprintf ile ayn�d�r. stdout yerine k1 katar�na yerle�tirir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		
	
�DEVLER
	**-Mant�ksal bir ili�ki kurarak karakter �zerinde i�lem yapan fonksiyonlar ile her durumu kontrol edecek �ekilde bir program yaz�n�z.
	**-Mant�ksal bir ili�ki kurarak katarlar �zerinde i�lem yapan fonksiynolar ile ayr� ayr� �rnekler yaz�n�z.
	-Dosyalama i�lemlerinde kullan�lan freopen fonksiyonunda stdin, stdout veya stderr fonksiyonlar�n�n de�erlerini de�i�tirdikten sonra tekrardan console ekran� nas�l yap�l�r ?
	---tmpfile() fonksiyonunu ara�t�r kullanmay� dene hatalar� ��z.
	-E-Ticaret sitesi kurdu�unuzu ve �ye ol, �ye giri�i ve parolam� unuttum k�sm� olsun. �ye ol k�sm�nda da �zel soru ba�l��� alt�nda �zel bir veri isteyin. Daha sonra parolam� unuttum
	yap�ld��� zaman o �zel karakter ile s�f�rlama yap�labilsin. �ye giri�i yap�ld�ktan sonra stok ta olan �r�nler listelensin stokta biten �r�nler g�r�nt�lenmesin fakat silinmesinde.
	Bir c�zdan olsun ve c�zdana giri� yap�ld���nda bakiye g�sterilsin ve bakiye y�kleme se�ene�i olsun. Bakiye y�klemede 16 haneli bir kart numaras� istensin ve bu kart numaras� e�er
	birinci ve ikinci hanelerinin toplam�n�n birler basama�� onalt�nc� hanesinin basama��na e�it ve 2 ye b�l�nebilir olmas� �art� olsun. B�t�n bunlar dosyalama i�lemi ile yap�lacakt�r.
	**-vscanf, vsscanf, vfscanf fonksiyonlar� varm� varsa ara�t�r.
	-
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
	//program2_2();
	//program2_3();
	//program2_4();
	/*3 Standart I/O fonksiyonlar� �rnekleri*/
	FILE *f;
	char mod; char selection; char *dataToFile;
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
					}while(selection == '\0');
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
					}while(selection == '\0');
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
	}while(mod == '\0');
	/*Yukarda sadece dosya a��lmas� yap�lm��t�r.*/
	fclose(f);
	/*A�a��da bir hata alacaks�n�z hata �u ilk yaz� ve ikinci yaz� yazd�ktan sonra ���nc� yaz�dan �nce bir Abdullah yaz�s� g�r�n�yor dosyada peki bu neden*/
	dataToFile = (char *)malloc(sizeof(char) * 8);
	strcpy(dataToFile, "Abdullah");
	fopen("dosya1.txt", "w");
	fprintf(f, "%s ile c dersleri ilk yaz� !\n", dataToFile);
	fwrite("Abdullah ile c dersleri ikinci yaz� !", 1/*Her verinin ka� byte oldu�u bizimde char oldu�u i�in 1*/, 50/*Ka� binary belirtildi ise tek eleman 1 olmak �zere *binary*/, f);
	fputs("\nAbdullah ile c dersleri ���nc� yaz� !\n", f);
	fputc(103, f); /*g harfi*/
	fclose(f);
	getch();
}



#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <stat.h>
#include <fcntl.h>
#include <locale.h>

/*D�SK DOSYALARI: 
	C dilinde elimizdeki baz� verileri kal�c� olarak bir yere depolamam�z gerekebilir. Bu t�r durumlarda dosyalama i�lemleri kullan�l�r. C dilinde dosyalar olu�turulduktan sonra 
dosyalara eri�mek i�in iki t�rl� y�ntem kullan�l�r. �lki, �st d�zey I/O (high level I/O) ya da tamponlanm�� I/O (buffered I/O) olarak, ikincisi alt t�zey I/O yada UNIX vebzeri I/O 
(unix like I/O) olarak adland�r�l�r. �kinci eri�im ANSI C standartlar�nda olmamas�na kar��n baz� derleyiciler sanki standartm�� gibi bu y�ntemi destekler. Bizim derleyicimiz de 
desteklemektedir. (devc++)
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
1-�st D�zey I/O Y�ntemi:
	Bu y�ntemde okuma ve yazma i�lemleri, temelde, karakter d�zeyinde yap�l�r ve kullan�m� alt d�zey I/O y�ntemine nazaran daha kolayd�r. Tampon bellek tan�mlama, veri d�n���m� ve 
formatl� okuma yazma i�in fonksiyon yazmaya gerek yoktur. Destekleniyorsa metin dosyas� ile birlikte ikili dosya �eklinde de kullan�labilir. Daha �nce anlat�landan farkl� bir i�lem 
yoktur.
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
2-Alt D�zey I/O Y�ntemi:
	Bir disk dosyas� i�erdi�i veriye g�re, metin dosyas� ve ikili dosya olarak ikiye ayr�l�r. Metin dosyas�nda sat�r sonu karakteri CR/LF ikilisine d�n��t�r�lerek yaz�l�r. Tersi durumda
CR/LF karakter �ifti sat�r sonu karakterine d�n��t�r�l�r �kili dosyada ise yanl�zca tek bir karakter ile sonland�r�l�r. UNIX ve XENIX de dosyalar yanl�zca ikili dosya tipindedir.
	UNIX ve benzeri i�letim sistemlerinde, programc�n�n k�t�phane fonksiyonu gibi �a��r�p kullanabilece�i baz� fonksiyonlar bulunur. Dolay�s� ile bu fonksiyonlar ile kullan�m daha
h�zl�d�r. Alt d�zey y�ntemde programc� tampon'u(buffer) kendisi bildirmek zorundad�r. �st d�zey y�ntemindeki gibi karakter d�zeyinde eri�im ve formatl� eri�im yoktur. Bunlar;
	-open(const char *k1, const char *k2, eri�imlik), creat(const char *k1, const char *k2) -> �ki adet parametre al�r ve k1 parametresi isminde ve k2 modunda dosyay� a�mak i�in 
	kullan�l�r. k2 modu i�in �st d�zey y�ntemden farkl� olarak	3 adet mod vard�r fakat kullan�mlar� farkl�d�r.
		*r -> Yazma izni.
		*w -> Okuma izni.
		*x -> Y�r�tme izni.
			Bu izinleri sekizlik say� sisteminde depolan�r ve bitlerin anlamlar�na g�re verilir. xyz 3 bitinden z biti y�r�tme iznine, y biti yazma iznine ve x biti okuma iznine e�ittir.
		�zinleri verirken, verilmek istenmeyen izinler yerine '-' karakteri konulur. UNIX benzeri i�letim sistemlerinde kullan�c�lar, owner, group ve others olarak ayr�l�r. Dolay�s� ile
		izinleri verirken;
		owner	group	others
		 rwx	 rwx	 rwx
		bi�iminde araya bo�luk koyarak verilir. creat fonksiyonu belirtilen izinler ile dosyay� olu�turur. E�er dosya diskte yok ise yeni dosyay� olu�turur, var ise dosyan�n i�eri�ini
		siler fakat izinleri de�i�tirmeden b�rak�r. open fonksiyonu ise farkl� izinler ile dosyaya ula�mak i�in kullan�l�r. Bu fonksiyonlar ba�ar�l� olursa geriye pozitif bir
		say�, ba�ar�s�z olurlarsa -1 d�nderirler ve errno de�i�kenine hata koduna kar��l�k gelen say�sal de�eri atarlar. open fonksiyonundaki 3. parametre olan eri�imlik parametresi ise
		e�er dosya yok ise kullan�l�r. Dosya zaten disk de var ise yok say�l�r. open fonksiyonu i�in izinler birinci liste ve ikinci liste olarak iki �ekilde verilir. Bu izinler araya
		| veya operat�r� koyarak birden �ok verilebilir fakat birinci liste i�in sadece bir tane kullan�l�r. fcntl.h adl� ba�l�k dosyas�nda ayr�lm�� bu bayraklar;
		B�R�NC� L�STE
		*O_RDONLY -> Yanl�zca okuma i�in a�.
		*O_WRONLY -> Yanl�zca yazma i�in a�.
		*O_RDWR -> Okuma ve yazma i�in a�.
		�K�NC� L�STE
		*O_NDELAY -> Bu bayrak UNIX ve benzeri i�letim sistemleri i�in kullan�l�r. E�er yaz�rsa ise okuma i�in se�ilen dosyan�n e�leni�i olan dosya yazma modunda a��lmam��
		ise a��lana kadar ilgili i�lem ask�ya al�n�r. Yaz�lmazsa dosya a��ld�ktan sonra fopen fonksiyonundan d�n�l�r.
		*O_APPEND -> Ekleme i�in a�ar ve cursor dosya sonuna konumland�r�l�r.
		*O_CREAT -> Dosyay� 3.parametre olan eri�im iznine g�re tekrar olu�turur.
		*O_EXCL -> O_CREAT bayra�� kullan�ld���nda diskte zaten ayn� isimli dosya var ise -1 d�ndertir.
		*O_TRUNC -> Zaten ayn� isimli dosya varsa dosyan�n i�eri�ini siler.
		*O_BINARY -> Dosyay� ikili dosya olarak a�t�r�r.
		*O_TEXT -> Dosyay� metin dosyas� �eklinde a�t�r�r.
		DOS ALTINDA �ALI�AN BAZI DERLEY�C�LERDE stat.h K�T�PHANES� ��ER�S�NDEK� BAYRAKLAR
		*S_IWRITE -> Benim i�in yazma izni.
		*S_IREAD -> Benim i�in okuma izni.
	-close(int) -> ��erisine parametre olarak girilen say�sal kodun kar��l�k geldi�i dosyay� fclose gibi kapat�r.
	-write(int dt, char *tampon, int tamponboyut) -> Belirtilen dosyaya verileri tamponboyut kadar tampon parametresinden yerle�tirir. Geriye yazolan karakter say�s�n� d�nderir.
	-read(int dt, char *tampon, int tamponboyut) -> write fonksiyonun tam tersi i�lem g�r�r. E�er ba�ar�s�z ise negatif bir de�er, ba�ar�l� ise pozitif bir de�er d�nderir.
	-lseek(dt, oteleme, 0, 1 veya 2) -> fseek fonksiyonu ile ayn� kullan�ma sahiptir.
*/

void main()
{
	setlocale(LC_ALL, "Turkish");
	
}

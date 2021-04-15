#include <stdio.h>
#include <stdarg.h>
#include <locale.h>
#define kareal(x) (x * x)
#define dairealan(r) (3.14 * kareal(r))
#define < (
#define > )
#define makro<x> (x + x)

/*Fonksiyonlar:
	C Programlama dili fonksiyonlardan in�a edilen bir programlama dili olarak tan�mlanabilir. B�t�n fonksiyonlar �a�r�lma yolu ile �al��maya ba�lar ve i�lemi bittikten sonra 
�a�r�ld�klar�yere tekrar d�nerler. Her fonksiyonun geriye d�nderdi�i bir tip olabilir veya olmayabilir. E�er bir fonksiyonun geriye d�n�� tipi olmamas�n� yani return kullanmak
istemiyorsak void olarak, e�er geriye d�n�� tipi olmas�n� istiyorsak da tip belirttiysek mecburen return kullanmam�z gerekir yoksa program hatal� olacakt�r. B�t�n de�i�ken tiplerinde
fonksiyon olabilir. Bir fonksiyon void veya tip olmadan yaz�l�r ise varsay�lan olarak bu fonksiyon int olur. Fonksiyonlar� da 3 grupta inceleyebiliriz.

1-main() Fonksiyonu: Fonksiyonlar�n �a�r�lmas� gerekti�ini s�ylemi�tik peki main fonksiyonunun �a�r�ld��� yer nerede ? main fonksiyonu da �a�r�l�r fakat program kodlar� i�erisinde de�il
de i�letim sistemi taraf�ndan �a�r�l�rlar, yani C program�n� yazd�ktan sonra derleyip �al��t�r�yoruz, daha sonra i�letim sistemi �al��t�rma s�ras�nda main fonksiyonunu �a��r�yor.
	main fonksiyonunu bu zamana kadar parametresiz g�rd�k, bu derste ise main fonksiyonunun 2 adet parametresi vard�r ve biz bunlardan bahsedece�iz. El ile yazd���m�z fonksiyonlarda
nas�l parametreleri tan�mlama varsa burada da vard�r fakat bunlar�n tipleri int ve pointer char olmak �zere s�n�rl�d�r. �rne�in biz bir oyun program� yazd�k ve kullan�c�n�n oyuna
girmeden �nce kullan�c� ad� ve �ifresini girmesini istedik. Bizim 2 adet 5 lvl ve 10 lvl olan kullan�c�lar�m�z olsun ve bunlar�n oyuna girdiklerinde girecekleri mapler farkl� olsun,
ne yapmam�z gerekir ? Girilen kullan�c�n�n �nce levelini al�p sonra buna g�re map.c program�n� �al��t�rmam�z gerekir. Bunu da console �zerinden derleyerek (windows i�in cmd, linux i�in
komut defterine) parametre girerek �al��t�rmam�z gerekir. Derlenirken -> Bu ders i�in derlenen exe dosyas�n�n konumunu bulmam�z gerekir ve ona g�re �al��t�r�lmal�d�r. (C dizinininin 
i�erisindeki program files dosyas� i�erisinde oldu�unu varsayarak) 
										kullanici leveli (�rne�imiz i�in level 5 veya 10) C/program files/Ders #4 - Fonksiyonlar.exe
	------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	int genellikle argc (arguman count): Bu parametre fonksiyona g�nderilen verilerilerin adetini tutar varsay�lan olarak 1'dir. Bu uygulaman�n ismidir bizim ders dosyas� i�in
	Ders #4 - Fonksiyonlar.exe'dir.
	------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	char genellikle *argv (arguman variable): Bu parametre fonksiyona g�nderilen verileri tutar. Varsay�lan olarak yukarda da dedi�imiz gibi uygulaman�n ismini bar�nd�r�r.
	------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
NOT: Burda main fonksiyonu i�in bir �rnek program yazd�k ve ne kadar parametre g�nderilirse g�nderilsin �al��acakt�r, siz de kendi istedi�iniz parametreleri girerek, derlenen exe 
dosyas�n�n konumuna g�re derleyin ve �rne�i inceleyin.


2-Programc� Taraf�ndan Yaz�lan Fonksiyonlar:
	Programc�n�n bir i�i ger�ekle�tirmek i�in, fonksiyonun tipini ve arg�manlar�n�(parametreler) belirleyerek yazd��� fonksiyonlard�r. Fonksiyonlar�n isimleri, okunmada kolayl�k
sa�lamas� ve ekip �al��mas�na uygun olmas� gere�i, yapt��� i� ile ilgili olmal�d�r. Bu fonksiyonlar void(tipsiz), int, char vb.(tipli) veya i�aret�i(pointer) bi�iminde olabilir. void
bir fonksiyon geriye bir de�er d�ndermez(return anahtar kelimesi kullan�lmaz) �al���r ve biter. int vb.(tipli) fonksiyonlar geriye return anahtar kelimesi ile belirtilen tipde
�a�r�ld��� yere de�er d�nderir. ��aret�i tipinde bir fonksiyon ise geriye address d�nderir.(NOT: ��aret�i fonksiyonlar haricindeki fonksiyonlar geriye NULL d�ndermezler.) Fonksiyon
tan�mlarken;
'fonksiyon tipi' fonksiyon_ismi(parametre_tipi parametre_ismi) �stenilen say�da istenilen tipte parametre girilebilir.
{
	�al��mas�n� istedi�imiz kodlar.
	
	return 'de�er'; Fonksiyon return g�rd��� yerde �a�r�ld��� yere gider yani return break gibi fonksiyonu sonland�r�r.
}
�eklinde tan�mlama yapabilirken ilk ba�ta prototip olarak tipini, parametrelerin tipini ve ismini belirtti�imiz bir fonksiyon yazabiliriz. Prototip fonksiyon yaz�l�rken
'fonksiyon tipi' fonksiyon_ismi(parametre_tipi, parametre_tipi) parametrelerin sadece tipleri belirtilir.
�eklinde yaz�l�r ve daha sonra bu fonksiyonun i�eri�ini yazmamak i�in
'fonksiyon tipi' fonksiyon_ismi(parametre_ismi, parametre_ismi) Bu sefer de yanl�zca parametre ismi girilir ��nk� prototipde parametrelerin tipini belirlemi�tik
{
	yap�lacak i�lemler.
}
	Fonksiyonlar sadece tipleri gere�i de�il parametreleri gere�i de birbirlerinden ayr�labilirler. �lk olarak int topla(int, int); �eklinde fonksiyon olu�turmu� olal�m bu fonksiyonun
yapt��� i� de iki tamsay�y� toplay�p geriye d�ndermek olsun. Daha sonra da float topla(float, float) �eklinde iki adet ondal�kl� say�y� toplay�p geriye bu toplam� d�nderen bir fonksiyon
olsun. Peki iki adet de�i�keni farkl� tiplerde olsalar bile tan�mlayamazken, iki adet ayn� isimli fonksiyon nas�l olu�tu ve madem yap�l�yor program hangisine gidece�ini nerden biliyor ?
Bunu �u �ekilde a��klarsak tipleri ve arg�manlar� farkl� istedi�imiz say�da ayn� isimde fonksiyon olu�turabiliriz ve program �a�r�lma k�sm�nda e�er float ise ondal�kl� i�in yaz�lan
fonksiyonu, tam say� ise tamsay� i�in yaz�lan fonksiyonu �a��r�r. Yine fonksiyonlar sadece tipleri ve parametreleri gere�i de�il yapt�klar� i�lem ile de birbirleri ile ayr�l�rlar.
Bunlara "CALL BY VALUE" ve "CALL BY REFERANCE" denir.
	�K� YAPI DA int a = 5; int b = 3; �EKL�NDE TANIMLANMI� �K� DE���KEN ���N  a'NIN DE�ER� �LE b'N�N DE�ER�N� DE���T�RMEYE Y�NEL�K OLACAKTIR �RNEKLER� cbvOrnek VE cbrOrnek FONKS�YONLARI
	-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	"CALL BY VALUE" -> Bir fonksiyon yanl�zca tek bir de�eri return eder, yani return etmemiz bizim bir i�imize yaramaz dolay�s� ile fonksiyonun tipi void olacakt�r. E peki biz burda ne
	yapaca��z ? Mecburen yer de�i�tirme i�leminin ard�ndan fonksiyon i�erisinde de�i�ken de�erlerini yazd�rmam�z gerekecektir ��nk�, de�erler fonksiyondan sonra ram �zerinden silinecek.
	
��aret�i �le Fonksiyon �a��rma:
	Baz� durumlarda i�aret�i ile fonksiyon �a��rmak gerekebilir. �rne�in kullan�c�dan iki adet say� alal�m ve bunlar�n toplamlar�, farklar�, b�l�mleri ve �arp�mlar�n� bulan
fonksiyonlara g�ndermek isteyelim bunun i�in direkt fonksiyon ismi ile �a��rmak amelelik olacakt�r bu y�zden i�aret�i ile fonksiyon �a��rma y�ntemine ihtiya� duyulur. Bu i�lem
'fonksiyonun_tipi' (*foknsiyonun_�a�r�laca��_de�i�ken_ismi) (arg�man_tipleri);
�eklinde olacakt�r. Bu �ekilde i�lem yap�l�r yukarda da birden fazla fonksiyonu ayn� arg�manlar i�in �al��t�rmak i�in �rnek verdik iki adet �rnek verilecektir bunlar main fonksiyonunda
incelenerek anla��lacakt�r.

Bir Foknsiyona Belirsiz Say�da Parametre G�nderimi
	Bu konuda bize gerekli olan <stdarg.h> k�t�phanesidir. �rnek �zerinden bizim bir firmam�z oldu�unu ve bu firman�n herhangi x departman�nda 50 tane personel �al��t���n� d���nelim,
bu personellere ortalama ne kadar maa� verildi�i ��renilip bu ortalamaya g�re b�t�n �al��anlara y�lda 1 kez prim verilece�ini varsay�l�m. Biz C dili �zerinden bu fonksiyonu yazd�k
fakat hem zahmetli oldu hemde departmana yeni bir personel girece�i zaman tekrardan kodlar� a�arak d�zeltmemiz gerekti�i g�zlendi. O halde bizim bir fonksiyon olu�turmam�z ve otomatik
olarak t�m parametreleri toplay�p parametre say�s�na b�len bir program yazmam�z gerekiyor. Bir �rnek ile ortalamaOrnek fonksiyonu i�erisinde anlat�lacakt�r.

Recursive (�zyinemeli) Fonksiyon:
	Kendi kendini yineleyen, �a��ran fonksiyonlard�r. D�ng�ler gibi �al���r ve kendi i�erisinde fonksiyon tekrar �a�r�l�r. Fonksiyon i�erisinde bir kontrol yap�s� olmazsa, ilk
�a�r�ld��� yere d�nemez ve sonsuz d�ng�ye girer. Recursive fonksiyonlar d�ng�lere g�re daha yava�t�r ve daha fazla bellek alan� kullan�rlar. Fakat recursive fonksiyononun avantaj�
daha kolay ve daha okunabilir yaz�lmas�d�r. Ayn� zamanda recursive olmadan yap�lamayacak veya yap�lsa bile daha performans�z veya daha zor uygulamalar olacakt�r. recursive isimli 
fonksiyon ile faktoriyel hesaplanan �rnek bir program yaz�lm��t�r.

#define �ni�lemci Kodu:
	#include gibi #define da �ni�lemci kodudur. Peki nedir bu �ni�lemci kodu ? �ni�lemci kodu program derlenmeye ba�lad�ktan sonra ilk ba�ta �al��t�r�lan sonra ana kodumuza d�nd�kten
sonra bu �ni�lemci kodlar�na g�re i�lem yapmam�za yarayan �eydir. #include enjekte etmek gibi d���n�lebilir. #define ise tan�mlama veya yerine tan�mlama olarak d���n�lebilir. Nas�l
yani ?
#define 'printf' 'yaz'
#define sonuna ';' koyulmaz. Yukardaki tan�mlama �rne�inde programda yaz g�r�len yerde (b�y�k k���k harf duyarl�d�r) printf yazmas� anlam�na gelir yani bu ne i�imize yarar ?
yaz("metin"); �eklinde yaz�lan �ey asl�nda -> printf("metin"); anlam�na gelir.

Makro Fonksiyonlar:
	Makro fonksiyonlar #define �ni�lemci kodu ile tan�mlanan ve belirli bir i�i yapmak amac� ile yaz�lan fonksiyonlard�r. Yaz�mlar� da performanslar� da di�er fonksiyonlara g�re
olduk�a iyidir. Bunun yan� s�ra makro fonksiyonlar geriye bir de�er d�ndermez, aritmetik i�lemlerin yapt��� gibi do�as� gere�i yapt��� i�lemi d�nderir. Ayn� zamanda da bu fonksiyonlar
arg�manlar� i�in bir tip istemezler istedikleri tipde arg�man ile i�lem yapabilirler. Sadece arg�man say�lar� belirlidir. K�t�phane tan�mlamas� yap�lan yerde makro fonksiyonlar tan�ml�
ve i�lemleri yine main �zerinden takip ediniz.

�DEVLER
	// -Bir fonksiyon 3 adet parametre al�yor ve biz de bu fonksiyona yanl�zca 2 adet parametre g�ndermek istiyoruz bunun i�in ne yapabiliriz ?
	// -Ayn� isimli farkl� parametreli iki adet fonksiyon olu�turmak ile ilgili bir �rnek yap�n.
	**-Recursive fonksiyon ile yaz�lmas� daha uygun olan bir program yaz�n�z.
	-Kendi k�t�phaneni (header, ba�l�k dosyas�, .h) nas�l olu�turursun ��ren ve yaz.
	**-Bir say�n�n karesini, karek�k�n�, �iftmi tek mi oldu�unu ve asal olup olmad���n� ��renen program� i�aret�i ile fonksiyon �a�r�ma y�ntemi kullanarak yaz�n�z.
*/
 
void cbvOrnek(int a, int b)
{
	int temp; /*De�i�ken isimlerini ingilizce tercih etmek buna al��mak daha yararl�d�r. temp(ge�ici) bir de�i�ken*/
	temp = a;
	a = b;
	b = temp;
	printf("Call By Value De�i�tirme Fonksiyonu ��erisinde a = %d, b = %d\n", a, b);
	/*G�r�ld��� �zere burada parametrelere akdar�lan de�erlerin yerlerini de�i�tirebildik fakat printf fonksiyonu ile burada yazd�k ��nk�, fonksiyonlar i�erisinde olu�turulmu� yerel
	de�i�kenler ve parametreler fonksiyon bittikten sonra ram �zerinden silinirler(static de�i�kenler hari�).*/
}

/*CALL BY REFERANCE FONKS�YONLARI ���N �K� SE�ENEK VARDIR 1.S� ���N cbrOrnek1, 2.S� ���N cbrOrnek2 FONKS�YONLARI YAZILACAKTIR.*/
void cbrOrnek1(int *a, int *b)
{
	int temp;
	temp = *a; /* (*a) �eklnide yazd�k ��nk� pointer tan�mlamadan sonra de�i�ken (*) ile kullan�rsa, g�sterdi�i adresteki de�er b�lmesini g�sterir.*/
	*a = *b;
	*b = temp;
	printf("Call By Referance De�i�tirme Fonksiyonu ��erisinde a = %d, b = %d\n", *a, *b);
}

/*void cbrOrnek1(int &a, int &b)
{
	/*Parametre tan�mlamalar�n�n ve parametrelerin de�i�kenlerden pek bir fark� yoktu ve biz burda ilk defa &(ampersant) i�areti ile de�i�ken tan�mlama g�rm�� olduk. Bu de�i�kenin
	ismi referance de�i�kenidir genellikle de bu tip i�lemler i�in ge�ici s�reli�ine olu�turulurlar. Ad� �st�nde referans olarak bir de�i�keni al�rlar vekalet verme gibi d���n�lebilir
	ve daha sonra bu referans de�i�kenleri normal de�i�ken gibi kullan�l�r fakat bu de�i�ken �zerinde yap�lan de�i�iklikler referans al�nan de�i�ken �zerinde de yap�lm�� olur. Fakat
	C dilinde bu tip tan�mlama yoktur C++ dilinde vard�r yani C dilinde bu tan�mlama hata verecektir bu fonksiyon �al��mayacakt�r.
	
	int temp;
	temp = a;
	a = b;
	b = temp;
	printf("Call By Referance De�i�tirme Fonksiyonu ��erisinde a = %d, b = %d\n", a, b);
}
*/
 
void prototipFonksiyon(int, int); /*Prototip fonksiyon baz� durumlarda hatalardan ka��nmak i�in kullan�l�r. Parametrelerin tiplerinin verilmesi yeterlidir isimlere gerek yoktur.*/ 

/*Prototipi tan�mlanm�� fonksiyonu daha sonra olu�tururken de�i�ken tipleri vermemize gerek yoktur.*/
void prototipFonksiyon(a, b)
{
	printf("Toplamlar�: %d\n", a + b);
}

void isaretciIle(int x, int y)
{
	printf("��aret�i ile fonksiyon �a�r�ld�, Say�lar: x = %d, y = %d\n", x, y);	
}

void toplam(int x, int y)
{
	printf("�ki Say�n�n Toplam�: %d\n", x + y);	
} 

void fark(int x, int y)
{
	printf("�ki Say�n�n Fark�: %d\n", x - y);	
} 

void carpim(int x, int y)
{
	printf("�ki Say�n�n �arp�m�: %d\n", x * y);	
} 

void bolum(int x, int y)
{
	printf("�ki Say�n�n B�l�m�: %d\n", x / y);	
}

/*A�a��da da g�r�ld��� gibi istenilen say�da parametre g�nderilecek fonksiyona mecburen 1 adet belirli bir parametre bildirimi yap�lmal� ve daha sonra '...' ile daha sonra gelen
parametrelerin belirsiz oldu�u g�sterilmelidir. Belirtilen ilk parametre yani bizim �rne�imiz i�in argumanSayisi isimli parametre, bu fonksiyona �a�r�lma s�ras�nda g�nderilen parametre
say�s�n� tutar.*/
float ortalamaOrnek(const int argumanSayisi, ...)
{
	/*A�a��da <stdarg.h> k�t�phanesi i�erisinde bulunan va_list isimli tip ile argumanlar isimli bir liste tan�mlam�� olduk. Bu liste diziler mant��� gibi de�ildir bu listede �u anda
	bu fonksiyona �a�r�lma s�ras�nda g�nderilen arg�manlar tutulmaktad�r. az sonra a��klayaca��m�z va_stard ve va_end aras�nda va_arg ile her kullan�mda bir sonraki parametreye ge�ecek
	tir.*/
	va_list argumanlar;
	int top = 0; int i; int value; /*value isimli de�i�ken argumanlar listesindeki yani t�m parametrelerdeki de�erleri tutmas� ve toplam de�i�kenine atmas� i�indir.*/
	va_start(argumanlar, argumanSayisi); /*Bu fonksiyonda argumanlar listesindeki argumanSayisina kadar olan elemanlar� g�sterece�imizi belirttik, bir t�rl� d�ng� gibi d���n�lebilir.*/
	for(i = 0; i < argumanSayisi; i++) /*Arg�man say�s� kadar d�necek bir for d�ng�s� olu�turduk.*/
	{
		value = va_arg(argumanlar, int); /*Arg�manlar i�erisinden ba�tan ba�layarak int tipte olan de�i�keni d�nderdi. For d�ng�s� tekrar d�nd��� zaman bir sonraki d�necektir.*/
		top += value;
	}
	va_end(argumanlar); /*Bu fonksiyonda argumanlar listesinin elemanlar�n�n listelenmesinin bitece�ini belirttik.*/
	printf("\n%d/%d\n", top, argumanSayisi);
	return (float)(top / argumanSayisi); /*Aritmetik ortalamay� d�nderdik.*/
}

int recursive(int f)
{
	/*Bu de�i�keni static olarak olu�turduk ��nk� recursive fonksiyonun �zelli�i tekrar tekrar �a�r�lmas�d�r ve bu �a�r�lma s�ras�nda tekrar tekrar de�i�ken olu�turulmas� program�
	yava�lat�r. Recursive foknsiyonlar� i� i�e fonksiyon i�erisindeki kod sat�rlar�n�n a��lmas� olarak d���nebiliriz. E�er static olarak olu�turmasak bile program �al��acakt�r ama
	faktoriyel hesaplamak i�in buna gerek yoktur en iyi yol budur.*/
	static int result = 1;
	if(f > 1) /*f'in 1'den b�y�k oldu�u durumlarda �al��mas�n� istedik ��nk� 1 ve 1'in alt�ndaki de�erlerde sonu� 0 ve negatif olacakt�r.*/
		result = f * recursive(f - 1); /*fonksiyona f - 1 g�nderdik. Dikkat e�er --f g�nderirsek f! yerine (f-1) faktoriyelin cevab� bulunur sizce neden ?*/
	return result;	
} 
 
void main(int argc, char *argv[]) /*Fonsiyonumuz void yani geriye bir�ey d�ndermeyen fonksiyon.*/
{
	setlocale(LC_ALL, "Turkish"); 
	int i; int a = 5; int b = 3;
	printf("Bu uygulaman�n ismi: %s\n", argv[0]); /*argv pointer dizi parametresi ilk eleman�nda uygulama ismini verir.*/
	printf("%d adet parametre girildi.", argc - 1); /* Girilen parametre say�s� + 1 (bu bir program isminden geliyor) */
	if(argc > 1)
	{
		printf(" Bunlar:\n");
		for(i = 0; i < argc - 1; i++)
			printf("%d.Parametre: %s\n", i + 1, argv[i + 1]);
	}
	else
		printf("\n");
	printf("\n");
	printf("Call By Value De�i�tirme Fonksiyonundan �nce a = %d, b = %d\n", a, b);
	cbvOrnek(a ,b);
	printf("Call By Value De�i�tirme Fonksiyonundan Sonra a = %d, b = %d\n", a, b);
	printf("\n");
	printf("Call By Referance De�i�tirme Fonksiyonundan �nce a = %d, b = %d\n", a, b);
	/*a ve b de�i�kenleri d�z de�i�kenlerdir ve bizim fonksiyonumuzun parametreleri pointer yani adres tutan de�i�kenlerdir bu y�zden & ile de�i�kenlerin adresleri g�nderilmi� oldu*/
	cbrOrnek1(&a, &b);
	printf("Call By Referance De�i�tirme Fonksiyonundan Sonra a = %d, b = %d\n", a, b);
	printf("\n");
	prototipFonksiyon(15, 18);
	/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
	/*��aret�i de�i�ken ile fonksiyon �a��rma*/
	/*Bu �rnekte yap�lan i�lem ��yle a��klanabilir. Pointerlar dedi�imiz gibi bellek adreslerini tutar. Biz bir de�i�kenin bellek adresini tutan bir pointer yaparken de�i�ken gibi
	bir pointer tan�ml�yorduk, �imdi ise fonksiyon gibi a�a��daki 1 ile i�aretli noktada fonksiyon adresi tutan bir pointer tan�mlam�� olduk ve 2 nolu yerde ise fonksiyonun adresini
	bu pointer'a atm�� olduk. Bundan sonra da de�i�ken ile 3 nolu yerdeki gibi �a��rma i�lemi yap�labilir.*/
	int x; int y;
	void (*isaretci) (int, int); /*1*/
	isaretci = isaretciIle; /*2*/
	printf("Aralar�nda Bo�luk B�rakarak �ki Adet Say� Girin: ");
	scanf("%d %d", &x, &y);
	isaretci(x, y); /*3*/
	/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
	/*Dizi i�aret�i ile fonksiyon �a��rma*/
	/*Bu �rnekte de g�r�ld��� gibi hep typedef ile (hen�z g�rmedik) hem de yukarda tan�mlama yapt���m�z gibi tan�mlama yapabildik. 1 Numarada kendimize ait bir tip tan�mlad�k ve bu
	tipi "void tipli iki adet int parametre alan fonksiyon i�aret�isi" olarak tan�mlad�k ve 2 no da bunun i�in normal diziye de�er atar gibi de�er atamas� yapabildik. Tip tan�mlamadan
	da 3 no da g�r�ld��� gibi tan�mlama da yap�labilirdi ve ayn� �ekilde de 4 no da g�r�ld��� gibi de her iki �ekilde (tip tan�mlama ile veya 3 no da oldu�u gibi) de�er atamas�
	yap�labilecektir. 5 no da g�r�ld��� gibi de fonksiyonlar �a�r�labilmektedir.*/
	typedef void (*fonksiyonIsaretcisi) (int, int); /*1*/
	fonksiyonIsaretcisi fonksiyonlar[4] = {toplam, fark, carpim, bolum}; /*2*/
	void (*fonksiyon[4])(int, int) = {toplam, fark, carpim, bolum}; /*3*/
	/*A�a��n�n 4 no*/
	/*fonksiyon[0] = toplam;
	fonksiyon[1] = fark;
	fonksiyon[2] = carpim;
	fonksiyon[3] = bolum;*/
	/*A�a�� 5 no*/
	for(i = 0; i < 4; i++)
		fonksiyonlar[i](x, y);
	for(i = 0; i < 4; i++)
		fonksiyon[i](x, y);
	/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
	printf("Girilen say�lar�n aritmetik ortalamas� = %f 	\n", ortalamaOrnek(8, 10, 15, 14, 12, 48, 65, 88, 5));
	printf("\nFaktoriyeli hesaplanacak say�y� giriniz: ");
	scanf("%d", &x); /*Yukarda x tan�mlanm��t� tekrar ba�ka de�i�ken tan�mlamaya gerek duymad�m.*/
	printf("x! = %d\n\n", recursive(x));
	int r;
	printf("Alan� hesaplanacak dairenin yar��ap�: ");
	scanf("%d", &r);
	printf("%d Yar��apl� dairenin alan�: %f", r, dairealan(r));
	printf("%d\n", makro<r>); 
}


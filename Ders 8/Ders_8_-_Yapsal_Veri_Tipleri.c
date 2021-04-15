#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

/*Yap�sal Veri Tipleri:
	C dili yap�sal bir programlama dilidir ve kolayca geni�letilebilir. �rne�in, makro fonksiyonlar tan�mlay�p var olan k�t�phanelere veya yeni k�t�phanelere eklenebilir. Yine ayn�
�ekilde yeni yaz�lan fonksiyonlar da bu �ekilde k�t�phanelere eklenebilir. Var olan veri tipleri veya daha �nce programc� taraf�ndan bildirilmi� veri tipleri kullan�larak, yeni veri
tipleri olu�turulabilir. Bu yeni veri tiplerinin bildirilmesi "typedef", "struct", "union" ve "enum" anahtar s�zc�kleri kullan�larak yap�l�r. "typedef" deyimi ile var olan veri tiplerinin
adlar� de�i�tirilerek daha okunakl� program yaz�labilir. "struct" ile bir�ok de�i�ken bir araya getirilip bir isim verilebilir. "union" da "struct" gibi bir�ok veri tipini k�melemek i�in
kullan�lsa da ama� farkl�d�r. Ama� bu veri tiplerinin ayn� ram g�z�n� payla�malar�d�r. "enum" ise s�n�rl� olarak yeni veri tip k�mesi olu�turabilir. T�m bu anahtar kelimeleri inceleyelim.
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
1-typedef Deyimi:
	#define �n i�lemci komutu gibi bu da var olan veri tipini tekrar isimlendirmek i�in kullan�l�r. �rne�in typdef int tamsayi; �eklinde bir tan�mlama yap�lm�� ise art�k tamsayi degisken;
�eklinde int bir de�i�ken olu�turabiliriz.
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
2-struct Deyimi: 
	Farkl� tiplerden verileri veya ayn� veri tiplerinden verileri k�melemek i�in kullan�l�r. ��erisine yaz�lan de�i�kenlere bu toplulu�un �yesi olarak isimlendirilir. Bu toplulukta bir
de�i�ken bildirirken struct topluluk_ismi degisken_ismi; veya struct topluluk_ismi *degisken_ismi; olarak iki �ekilde tan�mlama yapabilir. E�er normal bir de�i�ken tan�mlamas� yap�l�rsa
�yelere eri�irken degisken_ismi.uye, pointer tan�mlamas� yap�lm�� ise, degisken_ismi->uye, �eklinde kullanabiliriz. struct deyimini tan�mlama ve sistemlerini typedef deyimi ile, typedef
deyimi olmadan ve typedef deyimini d��arda kullanarak yapabiliriz. Ram de kaplad��� alan �yelerinin kaplad��� alan�n toplam�na e�ittir.
	---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	2.1-typedef Deyimi olmadan struct:
	struct struct_ismi
	{
		�yeler.
	}degisken_bildirimi, degisken_bildirimi2;
		Yukardaki �ekilde tan�mlama yap�labilir fakat struct_ismi ve degisken_bildirimi k�s�mlar� olmayabilir. E�er struct_ismi olmaz ise yeni bir topluluk de�i�keni olu�turmak m�mk�n
	olamaz ve e�er degisken_bildirimi k�sm� doldurulmu� ise bu k�s�mlardan ba�ka da de�i�ken bulunamaz. degisken_bildirim k�sm� yaz�lmaz ise olu�turma an�nda bir de�i�ken bildirimi
	yap�lm�� olmaz. E�er struct_ismi k�sm� var ise yeni bir de�i�ken olu�turulabilir. E�er struct_ismi k�sm� yok ise bu topluluk hi� bir i�imize yaramaz.
	---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	2.2-typedef Deyimi ile struct:
	typedef struct struct_ismi
	{
		�yeler.
	}kisaadlandirma, kisaadlandirma2;
		Yukar�daki �ekilde tan�mlama yap�l�labilir ve yine struct_ismi ve kisaadlandirma k�s�mlar� olmayabilir. Bu �ekilde bildirilmi� bir topluluk de�i�keni olu�tururken;
			*struct struct_ismi degisken;
			*kisaadlandirma degisken;
			*kisaadlandirma2 degisken;
		�eklinde yeni de�i�kenler olu�turulabilir. 2.1 bildiriminin aksine alttaki kisaadlandirma k�sm� de�i�ken bildirmek i�in de�il struct struct_ismi yerine kisaadlandirma
	k�sa isimleri kullanabilmemize olanak sa�lar.
	---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	2.3-typedef Deyimi d��arda ile struct:
	struct struct_ismi
	{
	
	}degisken1, degisken2;
	typedef struct_ismi kisaadlandirma;
		Yukarda g�r�ld��� gibi typedef deyimini d��arda tan�mlayarak 2.1 bildirimi ile 2.2 bildirimlerinin �zelliklerini birle�tirmi� olduk. Yani iki bildiriminde �zelliklerini
	kullanabiliriz.
	---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	Yukar�daki tan�mlamalar� yapt�k fakat 2.1 ve 2.3 s�ras�nda tan�mlanm�� topluluk de�i�kenlerine veya 2.1, 2.2 ve 2.3 topluluk de�i�kenleri olu�turuldu�u s�rada ba�lang�� de�eri
at�lmak istenebilir. Ba�lang�� de�eri atamalar� dizi ba�lang�� de�erleri atamas� ile ayn�d�r.	
	
NOT: Baz� donan�mlarda de�i�kenlerin �ift alanlara yerle�tirilme kural� olabilir. Bu da bizim struct tan�mlamam�zda bo�a giden bellek alan� olabilece�ini g�sterir ��nk�, struct tipinde
tan�mlanan bir de�i�ken tan�mlama yap�ld��� anda ram de �yeleri s�ras� ile bir tan�mlama yapar.
struct t
{
	int val1; 0XAD0 - AXAD4
	char ch; 0XAD5 - 0XAD6
	float val2; 0XAD8 - 0XADA
};
	Yukardaki struct bildirimini int de�i�kenlerini 4'e b�l�nebilen, float de�i�kenlerini 2'ye b�l�nebilen adreslere yerle�tiren bir donan�ma ait bilgisayar �zerinde �al��t�rd���m�z�
d���nelim. Bu durumda val1 de�i�keni i�in ram de 4'e b�l�nebilen bir adres tutulacak ve ard�ndan char de�i�keni i�in 1 byte yer ayr�lacak. Dolay�s�yla alttaki k�s�m 2'ye b�l�nemez bir
adres olacakt�r ve bu bellek g�z� atlanarak 2'ye b�l�nebilen alt g�ze float yerle�tirilecektir. Dolay�s� ile ram de 1 bellek g�z� bo�a harcanm�� olacakt�r.
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
3-union Deyimi: 
	Ortakl�k deyimi olarak adland�r�l�r. struct deyimi ile bildirilme ve olu�turulma yap�s�ndan bire bir ayn�d�r. Aralar�ndaki tek fark, struct gibi t�m �yelerin ram de kaplad�klar� alan
kadar yer kaplamay�p, en �ok yer kaplayan �ye kadar alan olu�turulmas�d�r.
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
4-enum Deyimi:
	enum deyimi yeni veri tipi olu�turmak i�in kullan�l�r. Bu veri tiplerini aktif olarak kullanmaktan ziyade program okunurlu�unu artt�rmak i�in tercih edilir. Yapt��� i�i int bir
de�i�ken ile de yap�labilir.
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

/*Art�k pointer yaz�lan yere tip * gelecektir.*/
typedef char *char_pointer; 
typedef int *int_pointer;
typedef float *float_pointer;

void program1()
{
	char_pointer katar = (char_pointer)malloc(sizeof(char) * 50);
	int_pointer age = (int_pointer)malloc(sizeof(int));
	float_pointer money = (float_pointer)malloc(sizeof(float));
	printf("�sim soyisim: ");
	gets(katar);
	katar = (char_pointer)realloc(katar, strlen(katar));
	printf("Ya�: ");
	scanf("%d", age);
	printf("Para: ");
	scanf("%f", money);
	printf("\n\n�sim soyisim: %s\nYa�: %d\nPara: %f TL\n\n", katar, *age, *money);
	free(katar); free(age); free(money);
}

struct program2_1
{
	int intnum;
	char ch;
	float floatnum;
}staticval1 =  {87, 'H', 49.8745}, staticval2;

void program2_1()
{
	puts("Program 1");
	struct program2_1 newstruct = {45};
	staticval2.intnum = 87; staticval2.ch = 'A'; staticval2.floatnum = 147.55;
	printf("%d - %c - %f\n", staticval1.intnum, staticval1.ch, staticval1.floatnum);
	printf("%d - %c - %f\n", newstruct.intnum, newstruct.ch, newstruct.floatnum);
	printf("%d - %c - %f\n", staticval2.intnum, staticval2.ch, staticval2.floatnum);
	puts("\n");
}

typedef struct program2_2
{
	int intnum;
	char ch;
	float floatnum;
}st;

void program2_2()
{
	puts("Program 2");
	st val1; struct program2_2 val2 = {758, 'E', 123.69};
	val1.intnum = 89; val2.ch = 'Y'; val2.floatnum = 78.012;
	printf("%d - %c - %f\n", val1.intnum, val1.ch, val1.floatnum);
	printf("%d - %c - %f\n", val2.intnum, val2.ch, val2.floatnum);
	puts("\n");
}

struct program2_3
{
	int intnum;
	char ch;
	float floatnum;
}staticval3 = {23, 'H', 29.371};

typedef struct program2_3 st2;

void program2_3()
{
	puts("Program 3");
	st2 val1; struct program2_3 val2 = {758, 'E', 123.69};
	val1.intnum = 94; val2.ch = 'A'; val2.floatnum = 231.476;
	printf("%d - %c - %f\n", val1.intnum, val1.ch, val1.floatnum);
	printf("%d - %c - %f\n", val2.intnum, val2.ch, val2.floatnum);
	puts("\n");
}

typedef union program3
{
	unsigned int b; /*4 byte*/
	unsigned char c; /*1 byte*/
}ortak;

void program3()
{
	/*Union deyimi bilindi�i gibi en b�y�k veri tipi kadar alan ay�rt�r. O halde ortak union toplulu�u int (4 byte kadar) yer ay�rtacak.*/
	ortak shareval;
	shareval.b = 321; /*0000 0000 0000 0000 0000 0001 0100 0001*/
	/*G�r�ld��� gibi shareval de�i�keninin char �yelesine eleman at�lma i�lemi yap�lmad�. Char i�in int'�n en sa�daki 1 byte yaz�l�r.*/
	shareval.c = (char)128;
	printf("�nt: %u\nChar: %c\n\n", shareval.b, shareval.c);
}

typedef enum md
{
	evli, bekar, dul
}medenidurum;

void program4()
{
	medenidurum kisi;
	kisi = bekar;
	printf("%d\n", kisi);
	kisi = evli;
	printf("%d\n", kisi);
	kisi = dul;
	printf("%d\n", kisi);
}

void main()
{
	setlocale(LC_ALL, "Turkish");
	//program1();
	/*program2_1();
	program2_2();
	program2_3();*/
	program3();
	program4();
}

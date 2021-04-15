#include <stdio.h>
#include <locale.h>

/*Bu fonksiyon i�in int val olarak bir parametre belirttik fakat bunu farkl� bir bi�imde de belirtme imkan�m�z vard� yani
int pow(val)
int val; -> Bu parametrelerin bildirimine ise "FORMAL B�LD�R�M" denir.
{
	
}
	�eklinde de belirtebilirdik bunun �rne�ini iki ye modunu alan bir fonksiyon yaparak belirleyelim;
*/

char text[67] = "Bu da genel bir de�i�kendir. Fonksiyonlar�n d��ar�s�nda tan�mlan�r."; /*GENEL B�LD�R�M*/

int poww(int val) /*Kare alma fonksiyonu.*/
{
	int newval = val * val; /*Kendi olu�turdu�um fonksiyonun i�erisindeki yerel de�i�ken. YEREL B�LD�R�M*/
	return newval;
	/*Bu fonksiyon i�erisindeki de�i�kenler yani ki�isel olarak olu�turdu�umuz fonksiyon i�erisindeki de�i�ken ve parametreler fonksiyon kullan�l�p bitirildikten sonra ram den temelli
	olarak silinirler.*/
}

int mod(val) /*�ki ye mod alma fonksiyonu.*/
int val;
{
	return val % 2;
}

/*EXTERN (DI�SAL) B�LD�R�M:
	B�y�k bir program yazd���m�z zaman ve ekip halinde �al��t���m�z zaman program� k�s�m k�s�m ay�rmak isteyebiliriz. Hesap.c program k�sm�nda int val; �eklinde bir de�i�ken
tan�mlad�ktan sonra bunu Cikti.c k�sm�nda ki bir fonksiyon i�erisinde parametre olarak g�rmek isteyebiliriz. ��te bu y�zden de�i�kenin ilk olu�turuldu�u yerde normal, di�er yerlerde ise
'extern' anahtar kelimesini ekleyer kullanaca��m�z her k�s�mda tan�mlamam�z gerekir, aksi halde program derlenirken hata verir.
*/

int staticdefination()
{
	/*STATIC (SAB�T) B�LD�R�M:
		Fonksiyon i�erisine normal bir de�i�ken tan�mlad���m�z zaman de�i�ken kullan�l�r ve fonksiyon sonland�r�ld��� anda de�i�ken ramden kald�r�l�r. Fakat 'static' anahtar kelimesi
	ile fonksiyon i�erisine static bir de�i�ken koyarsak program sonland�r�lana kadar bu static de�i�ken fonksiyon i�erisinde kal�r.
	*/
	static int x = 5;
	return x++;
}

/*REGISTER (SAKLAYICI) B�LD�R�M:
	Register olmayan bir de�i�ken tan�mlad���m�z zaman bu de�i�ken ramde tutulur. Register olan bir de�i�ken tan�mlad���m�z zaman i�lemci i�erisinde bulunan register alan�nda tutulan
yani daha h�zl� eri�im sa�lamam�z� sa�lan de�i�ken tan�mlam�� oluruz. 'register' anahtar kelimesi ile tan�mlan�r. �o�unlukla s�k kullan�lan �rne�in d�ng� saya�lar� gibi de�i�kenler
i�in kullan�l�r.
*/

/*VOLATILE B�LD�R�M:
	C derleyicileri istenildi�i taktirde bellek kullan�m� ve h�z a��s�ndan optimizasyona sokulabilir. Bu optimizasyon s�ras�nda baz� de�i�kenlerin bozulma yada beklenmedik hatalar
al�nmas�na neden olabilir. Bu optimizasyona sokmak istemedi�imiz de�i�kenlerin �n�ne 'volatile' anahtar kelimesini ekleriz.
*/

void main()
{
	setlocale(LC_ALL, "Turkish");
	int val1 = 4; /*Main fonksiyonu i�erisinde bulunan bir yerel de�i�kendir. YEREL B�LD�R�M*/
	int val2;
	register int i = 0;
	int nri = 0;
	printf("Program i�erisinde tan�mlanm�� de�i�kenin karesi: %d\n", poww(val1));
	printf("Bir de�er gir: ");
	scanf("%d", &val2);
	printf("Girilen say�n�n iki ye modu: %d\n", mod(val2));
	printf("%s\n", text);
	/*Bu k�s�mda da g�r��d��� �zere de�i�ken ramden program kapat�lana kadar silinmiyor.*/
	printf("Bu static de�i�kene sahip fonksiyonu ilk �a��r�m: %d\n", staticdefination());
	printf("Bu da ikinci �a��r�m: %d\n", staticdefination());
	printf("Bu register olmadan �al��an for d�ng�s�\n");
	getch();
	for(nri; nri < 10000; nri++)
		printf("%d\n", nri);
	printf("Bu register de�i�ken ile �al��an for d�ng�s�\n");
	getch();
	for(i; i < 10000; i++)
		printf("%d\n", i);
	const char ch = 'p'; /*Buna sabit bildirimi denir tan�mland��� anda de�er atanmal�d�r. Bu de�i�kenin de�eri de�i�tirilemez veya eklenemez.*/
}

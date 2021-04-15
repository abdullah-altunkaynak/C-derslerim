#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*DE���KENLER:
	De�i�kenler register anahtar kelimesi olanlar hari� ramde ikilik yani binary say� sistemi ile tutulur. De�i�ken t�rleri C dili i�in ��e ayr�l�r.
	
1-Tam Say�: Ad�ndan da anla��laca�� gibi tam say�lar� tutar. 'short', 'long' ve 'unsigned' olmak �zere �� adet anahtar kelime ile tan�mlan�r. Anahtar kelime olmadan int olarak tan�mlanan
bir tam say� ramde 32 bit kadar yer tutar.
	*short: T�rk�e anlam� ile k�sa tam say�lar� tutar. Ramde depolan�rken 16 bit kadar yer tutar.
	*long: T�rk�e anlam� ile uzun tam say�lar� tutar. Ramde depolan�rken 64 bit kadar yer tutar.
	*unsigned: signed T�rk�e anlam� ile i�aretli, unsigned ise i�aretsiz anlam�na gelir. '-'(negatif) say�lar� signed anahtar kelimesi ile tan�mlar�z fakat zaten anahtar kelime olmadan
	tan�mlamada default(varsay�lan) olarak signed anahtar kelimesi vard�r. unsigned anahtar kelimesi ise i�aretsiz anlam� ta��r. Bu anahtar kelime tan�mland��� zaman '-'(negatif)
	say�lar tutulmaz ve negatif alabilece�i de�erlikler de pozitif tarafa aktar�l�r. Yani unsigned anahtar kelimesi ile de�i�kenin alabilece�i say� miktar�n� ikiye katlam�� oluruz.
	NOT: Dedi�imiz gibi de�i�kenler ikilik tabanda yani binary say� sistemi ile ramde tutulur, i�aretli(signed) ve i�aretsiz(unsigned) tutulma bi�imi farkl�d�r. ��aretsiz ise normal olarak
	binary say� sisteminde nas�l ise ramde de �yle tutulur. ��aretli ise eksi say�lar (�o�u i�lemcide) ikiye tamamlama aritmeti�i ile elde edilir. Baz� i�lemcilerde ise ikiye t�mleme
	aritmeti�i yerine mutlak de�er ile de g�sterilebilir.
	�K�YE TAMAMLAMA AR�TMET���:
		�lk olarak elimizdeki bir tamsay�y� ele alal�m. 3 say�s� ramde 16 bitlik �ekilde "0000 0000 0000 0011" �eklinde tutulur. Bunun negatifini yani '-' i�aretlisini almak istedi�imiz
	zaman 1'e t�mlemesi yap�l�r. -> "1111 1111 1111 1100" ve bire t�mlenmi� hali budur. 1'e t�mlemeden sonra 2'ye t�mleme i�lemi i�in, 1'e t�mlenmi� haline binary sistemde 1 say�s�n�
	ekleriz yani. "1111 1111 1111 1100" + "0000 0000 0000 0001" = "1111 1111 1111 1101" �eklinde ikiye t�mleyen bulunmu� olur ve sonu� bu ��kar.
		Ayr�ca de�i�kenlere de�erleri sekizlik, onluk ve onalt�l�k bi�imde de atabiliriz.
	*sekizlik de�er atamas� i�in: Ba��na '0' konarak [0, 7] kapal� aral���nda istenilen de�eri yazabiliriz.
	*onluk de�er atamas� i�in: Standart olarak herhangi bir ek olmadan [0, 9] kapal� aral���nda istenilen de�eri yazabiliriz.
	*onalt�l�k de�er atamas� i�in: Ba��na '0X' koyarak [0, 9] -> [A, F] kapal� aral���nda istenilen de�eri yazabiliriz.
2-Ger�ek Say�: Ad�ndan da anla��laca�� gibi rasyonel, ondal�kl� veya ger�ek say�lar� tutar. Tam say�larda oldu�u gibi bunun i�in de anahtar kelimeler vard�r. �ki adet ger�el say�
vard�r. Ger�el say�lar kayan noktal�(floating point) bi�iminde ramde saklan�r. Dolay�s�yla kayan noktal� say�lar olarak da an�labilir.
	1-Tek Duyarl�: 'float' �eklinde tan�mlan�r. Herhangi bir standart getirilmedi�i i�in derleyiciden derleyiciye farkl�d�r fakat 6 hane alabilir olarak d���nebiliriz. Virg�l yada nokta
	say�lmadan en fazla 6 hane duyarl�l��� vard�r.
	2-�ift Duyarl�: 'double' �eklinde tan�mlan�r. Yine derleyiciden derleyiciye de�i�ir fakat 15 hane olarak d���nebiliriz. Virg�l yada nokta say�lmadan en fazla 15 hane duyarl�d�r.
	3-Uzun �ift Duyarl�: 'long' anahtar kelimesi ile 'long double' �eklinde tan�mlan�r. Yine elimizdeki herhangi bir say�y� anahtar kelime olmadan de�er �n�ne L veya F eklersen 
	l-> long, f-> float tek duyarl� �eklini alabilir. Bu normalde double dan daha b�y�k olmas� gerekir fakat baz� derleyiciler duyarl�l���n� ayn� varsay�yor.

3-Karakter: Karakterler tek t�rnak i�erisinde char tan�mlamas� yap�larak olu�turulur. E�er dizi bi�iminde yap�l�r ise �ift t�nak aras�na da metin kelime vb. �eyler yaz�labilir. B�t�n
her�ey bir karakterdir say�lar da buna dahildir ve b�t�n bu karakterlerin en �ok kullan�lan ascii ve ebcdic tablolar�nda kar��l��� vard�r ve ramde yine binary say� sistemi ile tutulur.
char tan�mlamas�n�n kar��s�na ikilik, sekizlik, onluk ve onalt�l�k say� sisteminde de�er de girilebilir. Kar��l��� ise tablodaki kar��l��� olacakt�r.
*/

/*OPERAT�RLER:
	De�i�kenler veya sabitler �zerinde belirli i�lem yapan i�aretler anlam�na gelir. Aritmetik, mant�ksal, kar��la�t�rma ve bitsel operat�rler olarak d�rde ayr�l�r. ?:, * ve &
operat�rleri bitsel operat�rler veya mant�ksal operat�rler i�erisine girse de ayr� yerleri vard�r.

1-Aritmetik Operat�rler: 7 adet operat�r vard�r bunlar +(toplama), -(��karma), *(�arpma), /(b�lme), %(mod alma), --(azaltma) ve ++(artt�rma) operat�rleridir.
	Toplama (+) -> �ki say�sal de�eri toplamaya veya iki karakterleri yan yana birle�tirmeye yarar. Sola sa� ekleme yapar.
	��karma (-) -> �ki say�sal de�eri ��karmaya yarar. Sola sa� ��kartma yapar.
	�arpma (*) -> �ki say�sal de�eri �arpmaya yarar. Sola sa� �arpma yapar.
	B�lme (/) -> �ki say�sal de�eri b�lmeye yarar. Sola sa� b�lme yapar.
	Mod (%) -> �ki say�sal de�erin b�l�m�nden ��kan kalan� verir. Sola sa� mod bulur.
	Artt�rma (++) -> Tek say�sal de�er �zerinden veya karatker �zerinden 1 artt�rma yapar. E�er say�sal ise 1 artt�r�r e�er karakter ise bir sonraki harfi g�sterir. E�er bu artt�rma
	operat�r� ba�ka bir de�ere atan�rken kullan�l�yorsa (int number = ++5; veya int number = 5++;) solda olmas� ilk �nce artt�r�p sonra de�er atamas� yapt�r�r. Sa�da olmas� ise �nce
	de�eri at�p sonra belirtilen de�eri bir artt�rmas� anlam�na gelir.
	NOT: % Operat�r� belirtildi�i gibi mod almaya yarar lakin rand() fonksiyoni ile 'int randomnumber = rand() % 100;' bi�imide yaz�m g�rm��s�n�zd�r. Burada mod operat�r�n�n g�revi
	de�i�miyor rand() fonksiyonu 0 ile 32767 aras�nda rastgele de�er d�nderir. Mod alma i�lemine sokmam�z demek rand() fonksiyonundan �retilen say�n�n 100 e kalan�n� vermesi demek, 
	yani elimizde 0 ile 99 kapal� aral���nda rastgele say� olmas� demektir.
	 
2-Kar��la�t�rma Operat�rler: 6 Adet operat�r vard�r bunlar >(b�y�k m�), >=(b�y�k veya e�it mi), <(k���k m�), <=(k���k veya e�it mi), ==(e�it mi) ve !=(e�it de�il mi) operat�rlerdir.
Stringler i�in yani char dizileri i�in kullan�lamazlar bunlar string.h k�t�phanesi i�erisinde bulunan fonksiyonlar ile sa�lan�r. G�revleri de isimlerinden anla��ld��� gibidir. E�er
ko�ul sa�lan�yor ise true sa�lanm�yor ise geriye false d�ner.

3-Mant�ksal Operat�rler: 3 Adet operat�r vard�r bunlar &&(ve), ||(veya) ve !(de�il) operat�rleridir. Kar��la�t�rma operat�rlerini birbirine ba�lamak, birle�tirmek i�in kullan�l�r.
	Ve (&&) -> Ad�ndan da anla��laca�� gibi birden fazla ko�ul aras�na ve gelir ve hepsi true ise ancak true d�ner geri kalan i�lemlerde false d�ner.
	Veya (||) -> Yine ad�ndan da anla��laca�� gibi birden fazla ko�ul aras�na veya gelir e�er hepsi false ise ancak false d�ner, geri kalan i�lemlerde true d�ner.
	De�il (!) -> E�er ko�ul true d�nderiyor ise false, false d�nderiyor ise true ya �evirir yani tersini almam�z� sa�lar.
	
4-Bitwise Operat�rler: Bitler �zerinde i�lem yapmak i�in kullan�l�r. Ramde tutulan bir de�i�kenin de�erleri ile de�il de bitleri �zerinde direkt olarak i�lem yapmak i�in kullan�l�r.
6 Adet bitwise operat�r vard�r bunlar &(bit d�zeyinde ve), |(bit d�zeyinde veya), ^(bit d�zeyinde yada), ~(bire t�mleme yani 1'ler 0, 0'lar 1), <<(sola �teleme) ve >>(sa�a �teleme) dir.
	Bit D�zeyinde Ve (&) -> Direkt olarak �rnek �zerinden ilerleyelim. Ve nin anlam� ikisi de ayn� anda olmas� anlam�na gelir. Yani ikiside true(1) ise true, e�lenen de�erlerden
	herhangi biri false(0) ise false olacakt�r. �rne�in: int bitnumber = 'value'; �eklinde herhangi bir de�ere e�it binary bi�imde "xxxx xxxx" �eklinde olan bir de�i�ken alal�m ve bitwise
	operat�rler ile i�lem yapal�m bu da -> bitnumber = bitnumber & 4; �eklinde olsun. 4'�n binary kodu -> "0001 0000" �eklindedir. Ve'nin anlam� herhangi e�le�en eleman 0 oldu�u anda
	false olmas�yd� 4 i�in sadece 3 c� yani onluk tabanda 2^2 de�erine sahip bit. Bu y�zden 0 olanlar� & operat�r� gere�i 0 olmas� gerekir yeni bitnumber de�i�kenin binary kodu ise
	-> "0000 0x00" �eklinde olur. x e�er 1 ise -> "0000 0100", 0 ise -> "0000 0000" �eklindedir.
	Bit D�zeyinde Veya (|) -> Veya'n�n da ve gibi �al��t��� s�ylenilebilir. Veya da herhangi e�le�en bitlerden biri true(1) ise true gelir. Yine �rnek �zerinde: int bitnumber = 'value';
	�eklindeki de�i�kenin binary kodu -> "xxxx xxxx" olacakt�r. bitnumber = bitnumber | 7; i�lemini yaparsak 7 nin binary kodu -> "0000 0111"; �eklindedir. Veya da herhangi bir e�le�en
	bit true olmas� yeterli demi�tik yani bitnumber de�i�keninin binary kodu -> "xxxx x1111" olacakt�r. Burada belirleyici olan bitnumber de�i�keninin ilk halindeki binary kodu, e�er
	bu x'ler 1 ise sonu�taki o bit yerine 1, 0 ise o yere 0 gelecektir.
	Bit D�zeyinde Yada (^) -> Yada operat�r�nde ise birbiriyle e�le�en ve farkl� olan bitlerin de�eri true, ikisi de ayn�, yani 1 - 1 veya 0 - 0 olan bitlerin de�erinin 0 olmas�
	anlam�na gelir. Yine bir �rnek �zerinden: int bitnumber = 27; de�i�kenini tan�mlayal�m. Bu de�i�kenin binary kodu -> "0001 1011" �eklindedir. Bu de�i�keni yada i�lemine sokarsak
	bitnumber = bitnumber ^ 41; 41 say�s�n�n binary kodu -> "0010 1001" �eklindedir. Dolay�s�yla yada i�lemi ile ayn� olanlar 0, farkl� olanlar 1 olacakt�r. bitnumber de�i�keninin
	yeni binary kodu -> "0011 0010" olacakt�r.
	NOT: Genel olarak yukardaki operat�rler bitleri 0 lamak veya 1 lemek i�in farkl� i�lemler i�in sadece mant�k kullanarak ��zmemize olanak sa�layan ara�lard�r.
	Bir'e T�mleme (~) -> �rnek olarak 42 say�s�n� alal�m, binary kodu -> "0010 1010" �eklindedir. Bu say�n�n t�mleyenini ald���m�z zaman binary kodu -> "1101 0101" yani onluk tabanda
	213 say�s�na e�ittir. Biz 42 say�s�n� 8 bit ile yazabiliyoruz ve 8 bitin maximum alabilece�i de�er 255 dir. Dikkat ettiysek alabilece�i maximum de�erden kendisini ��kard���m�z
	zaman 213 yani t�mleyenini bulmu� oluyoruz.
	�teleme (<< veya >>) -> Sa�a veya sola �teleme operat�rleri ayn� i�i g�r�r, 1 olan t�m bitler istenildi�i de�er kadar belirtilen (<< veya >>) y�nde �telenir. Sa�dan ve soldan
	devaml� 0 gelir yani e�er fazla sa�a veya sola �telersek 1 olan bitler kay�p yok olacakt�r ve biz elimizdeki binary kodu -> "0000 0000 0000 0000" �eklinde bulabiliriz.
	
Di�er Operat�rler: +=, -=, *=, /=, %=, &=, |=, ^=, <<= ve >>= gibi baz� operat�rler vard�r bunlar da bildi�imiz gibi i�lemi yap�p atamay� sa�larar. Bir di�er operat�r ise ?: operat�r�
bu operat�r:
if(ko�ul)
{
	ko�ul sa�lan�rsa(true gelirse) yap�lacak i�lemler.
}
if yap�s�n�n fazla yer kaplamamas�n�, direkt olarak sorgu yapabilmemizi sa�lar.
Kullan�m� -> (Ko�ul) ? (Sa�lan�rsa - True ise yap�lacak i�lem) : (Sa�lanmazsa - False ise yap�lacak i�lem);

��aret�i Operat�rler: '*' ve '&' olmak �zere iki adet i�aret�i operat�r� vard�r.
	pointer (*) -> Bu i�aret�i anahtar kelimeler gibi de�i�ken tan�mlamada kullan�l�r. Normal bir int de�i�ken tan�mlamas� bildi�imiz gibi �u �ekildedir -> int number = 'value';
	pointer tan�mlamas�nda ise '*' operat�r� de�i�ken isminin sol taraf�na koyulur ve tercihen biti�ik yaz�l�r. (int *number = 'address') Bu �ekilde tan�mlamaya pointer tan�mlamas�
	denir. Pointer de�i�ken normal de�i�kenlerden farkl� olarak bir de�er tutmaz adres tutar. Yani pointer ramdeki bir adresi tutar. O halde bir pointer de�i�kenine ba�ka bir
	pointer de�i�kenini atmak istersek atabiliriz ��nk� di�er pointer da adres tutar. (int *ptr1 = 'address'; int *ptr2 = ptr1;) Burada kar��t�r�lmamas� gereken '*' operat�r�n�
	sadece tan�mlama yaparken kulland�k, yani e�er adrese ula�mak istiyorsak, '*' operat�r�n� koymamam�z gerekir. Peki koyarsak ne olur ? Dedi�imiz gibi bu de�i�ken ramdeki bir g�z�n
	adresini tutar, e�er '*' operat�r� ile tan�mlamadan sonra de�i�keni kullan�rsak tutulan o adresteki de�eri bize d�nderir. Ram'in �rneksel �izimi a�a��daki gibidir.
															
																    		   ADDRESS			    VALUE
																		-----------------------------------------
	Pointer buradaki adres g�z�n� tutar. (atama haricinde * olmadan)  <-|				   |					| -> Normal de�i�ken buray� tutar. E�er atama haricinde * koyulur ise
	Normal de�i�kenin ba��na & gelirse o da buradaki adresi d�nderi		-----------------------------------------	 pointer de�i�keni de buradaki de�eri d�nderir.	
																		|				   |					|
																		-----------------------------------------
																		|				   |					|
																		-----------------------------------------
																		|				   |					|
																		-----------------------------------------
																		|				   |					|
																		-----------------------------------------
																		|				   |					|
																		-----------------------------------------
	NOT: E�er pointer ba��na & gelir ise pointer da ramde biryer tutar ve & ile pointer�n kendi sabit adresi d�nderilir. Pointerlar da mant�k gerektiren ve i�imizi kolayla�t�ran
	de�i�kenlerdir.

sizeof(de�i�ken tipi veya de�i�ken ismi); -> Geriye byte olan bir de�er d�nderir. (1 byte = 8 bit) ramde kaplad��� alan� bulmam�z� sa�lar.
*/

/*�DEVLER
	-Bitwise operat�rlerinin nerelerde kullan�labilece�ini ara�t�r.1 **buna s�ylenecek bir�ey yok mant�ksal i�lem gertektiren heryerde kullan�l�r.Mant�k devreleri dersinde yapabilece�imiz t�m mekanizmalarda kullanabiliriz
	-T�m operat�rlerin ve aritmetik i�lemlerin �nceliklerini ara�t�r.1
	-�kilik tabanda toplama ve ��karma i�lemlerini ��ren.1
	-Cast etme yani d�n���m yapma nedir nas�l yap�l�r ?1
	-Bitwise operat�rler hangi tip de�i�kenler ile yap�labilir ?0
	-Bir metin yazmak istedi�imiz zaman char dizileri kullan�yoruz, peki bir char dizisi olu�turdu�umuz zaman diziye ay�rd���m�z boyuttan k���k boyutlu eleman eklersek bo� kalan yerlere
	ne olur ?\0
	-strlen() haz�r k�t�phane fonksiyonu ne i�e yarar ?1
*/
void main()
{
	setlocale(LC_ALL, "Turkish");
	int octal = 047; /*Sekizlik say� sisteminde de�i�kene de�er atama.*/
	int decimal = 93; /*Onluk say� sisteminde de�i�kene de�er atama.*/
	int hexadecimal = 0XFA; /*Onalt�l�k say� sisteminde de�i�kene de�er atama*/
	/*%d decimal anlam�na gelir de�i�kenlere hangi say� sisteminde de�er at�lm�� olursa olsun say�n�n decimal kar��l���n� bize verir.*/
	printf("Onluk tabandaki de�erleri\n");
	printf("Sekizlik: %d, Onluk: %d, Onalt�l�k: %d\n", octal, decimal, hexadecimal);
	/*%o herhangi bir say� sistemindeki say�y� sekizlik tabanda, %x ise herhangi bir say� sistemindeki say�y� onalt�l�k tabanda yazd�r�r.*/
	printf("Onluk tabandaki de�erleri\n");
	printf("Sekizlik: %o, Onluk: %d, Onalt�k�k :%x\n", octal, decimal, hexadecimal);
	/*A�a��daki gibi anahtar kelime kullanmadan de�erlerin sonuna l->long U->unsigned �eklinde de belirlemeler yapabiliriz. T�m say� sistemleri i�in ge�erlidir.*/
	int ld = 19;
	int uld = 29UL;
}

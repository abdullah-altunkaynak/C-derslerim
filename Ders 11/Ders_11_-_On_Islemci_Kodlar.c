#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*C Dili �n ��lemci Kodlar�:
	Bir C program�nda simgesel sabitler, makro fonksiyonlar veya program�n ko�ullu derlenmesi istenirse bu �n i�lemci kodlar� kullan�l�r. �n i�lemci komutlar� C program kodunun 
derlenmeden �nce bu komutlar i�levlerini yerine getirir. Bu �n i�lemci kodlar� ile yaz�lan bir program� farkl� bir sisteme ge�irerek �al��mas�n� veya yaz�lan ortak bir program par�as�n�
tekrar tekrar yazmak yerine �n i�lemci kodlar� ile haz�r halde kullan�labilir.
	�n i�lemci kodlar� '#' karakteri ile ba�larlar ve sonuna ';' karakteri konulmaz, t�m sat�r o �n i�lemci koduna aitdir. E�er sat�r yetmez ve alt sat�rdan devam edilmesi istenirse
sat�r sonuna '\' karakteri konulur ve alt sat�rdan �n i�lemci kodu devam eder. Bu derste 12 adet ANCI C deki �n i�lemci kodlar�n� inceleyece�iz.
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
1-#define �ni�lemci Kodu:
	Bu kod ile simgesel sabit bildirimi, bir program par�as�na simgesel bir isim ve makro fonksiyon tan�mlamas� yap�labilir. Tan�mlan�rken #define simgeselsabitadi sabitdeger bi�iminde
tan�mlan�rlar. Dikkat edilmesi gereken tip tan�mlama i�in ge�erli olmamas�d�r. Tip tan�mlamak i�in typedef deyimi kullan�l�r.
	STANDART K�T�PHANEDE B�LD�R�LM�� BAZI S�MGESEL SAB�TLER
		*__FILE__ -> Kaynak kodunun bulundu�u dosya ad�n� tutar.(katar)
		*__LINE__ -> Kaynak kodunun bulundu�u dosyadaki sat�r say�s�n� tutar. (tamsay�)
		*__DATE__ -> Derleme tarihini tutar. (ay, g�n, y�l)
		*__TIME__ -> Derleme saatini tutar. (saat dakika saniye)
		*__STDC__ -> Derleyicinin standard� destekleyip desteklemedi�ini g�sterir. (1 - 0)
2-#undef �ni�lemci Kodu:
	Daha �nce #define �ni�lemci kodu ile tan�mlanm�� simgesel sabit, program deyimi veya makro fonksiyonu ge�ersiz k�lmak i�in kullan�l�r. Tan�mlanmas� #undef simgeselsabit �eklindedir.
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
3-#include �ni�lemci Kodu:
	Program i�erisinde ba�l�k dosyas� veya bir kaynak kod eklemek i�in kullan�l�r. E�er derleyicinin belirledi�i alandaki dosya i�in ise tan�mlanmas� #include <dosyaismi> bi�iminde, 
de�ilse #include "dosyaismi" bi�imindedir.
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
4, 5, 6, 7, 8, 9 -> #if, #else, #endif, #elif, #ifdef ve #ifndef �ni�lemci Kodlar�:
	#if, #elif, #else ve #endif �ni�lemci kodlar� bilinen if - else if - else yap�s� ile ayn�d�r. Tek farklar� #endif g�r�lene kadar olan t�m sat�rlar� i�ler bu y�zden sonuna #endif
koyulmal�d�r. #ifdef ve #ifndef ise tan�mlanm�� ise veya tan�mlanmam�� ise i�lem yapmak i�in kullan�l�r. Yine #endif beklenir. Bunlar yerine defined deyimi de kullan�labilir.
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
10-#line �ni�lemci Kodu:
	Standart k�t�phanede bildirilen __FILE__ ve __LINE__ simgesel sabitlerinin de�erlerinin de�i�tirilmesi i�in kullan�l�r. #line satirno "dosyaismi" �eklinde kullan�l�r ve e�er
__FILE__ de�i�tirilmek istenmez ise "dosyaismi" k�sm� olan ikinci parametre yaz�lmaz.
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
11-#error �ni�lemci Kodu:
	Yan�na yaz�lan metini standart ��k��a yazar ve derleme i�lemini durdurur.
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
12-#pragma �ni�lemci Kodu:
	�lk parametre olarak verilen sistem de�i�keni i�in ikinci ve di�er parametrelerde de�erlerini de�i�tirir.
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/	
void main()
{
	setlocale(LC_ALL, "Turkish");
	
}

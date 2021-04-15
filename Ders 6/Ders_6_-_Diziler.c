#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

/*D�Z�LER:
	Diziler ayn� tipde verilerin bir arada k�melenmesidir. Bir dizinin boyutu [size] aras�na boyut bildirilerek yap�l�r. Daha fazla k��eli parantez eklenerek boyut artt�r�labilir.
Diziler tek boyutlu (vekt�r), iki boyutlu (matris) ve �ok boyutlu olarak s�n�fland�r�labilir.
1-Tek Boyutlu Diziler (Vekt�r): 
	type name[size] bi�iminde tan�mlan�rlar ve e�er type name[] = {elements}; �eklinde tan�mlama yap�lmaz ise mecburen k��eli parantezler aras�na size bildirimi yap�lmal�d�r.
2-�ki Boyutlu Diziler (Matris):
	type name[size(sat�r olarak d���n�lebilir)][size(s�tun olarak d���n�lebilir)]; bi�iminde tan�mlan�r ve e�er type name[][size] = {elements}; �eklinde tan�mlama yap�lmaz ise ilk
size belirtilmelidir. �kinci size her daim belirtilmelidir ��nk� dizi [3][2] mi [2][3] m� bi�imde bildirilece�ini bilemez. Eleman atamas�nda ise �rne�in [5][3] l�k bir dizi d���nelim
bunun atamas� iki �ekilde yap�labilir.
	-K�me i�inde k�meleme: {{77, 88, 54}(Burada 0 i�in 0, 1 ve 2. indislere atama yap�l�yor), {48, 88, 97}(Burada 1 i�in 0, 1, 2. indislere atama yap�l�yor), ...} �eklinde k�melenerek
	ait olunan yerlere de�er atamas� yap�labilir.
	-Direkt olarak: {0, 1, 5, 8} �eklinde atama yap�l�rsa e�er indisleme 00, 01, ... �eklinde ilerleyecektir.
3-�ok Boyutlu Diziler:
	Tek boyutlu diziden sonra iki boyutlu diziler i�in nas�l bir de�i�iklik yap�ld� ise �ok boyutlu i�in de ayn� kurallar ge�erlidir. Ek olarak sadece boyut kadar [] eklenir.
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Dizilerin Fonksiyona Parametre Olarak G�nderilmesi:
	Diziler fonksiyonlara parametre g�nderilirken yine tek ve iki boyutlu i�in incelenirler. �ki boyutlu dizilerde uygulanacak kural da �ok boyutlular i�in ge�erlidir.
1-Tek Boyutlu Diziler ��in:
	�ncelikle fonksiyonlara parametre aktar�m� y���n �zerinden yap�lmaktad�r. Biz t�m dizi elemanlar�n� g�ndermek yerine dizi ismi yaz�larak sadece dizinin ilk eleman�n�n adresini
g�nderiyoruz ve dizinin asl�nda iki elemanl�ym�� gibi davranmas�n� sa�l�yoruz. �lerlettik�e ilk adres sabit kalsa da ikinci alt�ndaki adres de�i�mekte olur. [] aras�na bir�ey
NOT: Dizi ismi ary i�in
	ary = &ary[0]
	*ary = ary[1]
tan�mlamas�na gerek yoktur parametre aktar�m� da atama i�lemi ile benzerdir.
2-�ki Ve �ok Boyutlu Diziler ��in:
	Yine ayn� �ekilde ilk size i�in [] de�er yaz�lmas� gerekmez ama di�erleri belirtilmek zorundad�r.
NOT: Dizi ismi ary i�in
	ary = ary[0] = &ary[0][0]
	*ary = ary[0] = &ary[0][0]
	**ary = ary[0][0]
	Yukarda g�r�ld��� �zere *ary ile ary ayn� gibi g�z�k�r farklar� ise �udur; ary t�m k�meyi kapsayacak �ekilde ba�lang�� adresi tutarken, *ary belirtilen indis i�in yani 0. indisin
0, 1, ...., n. idisleri i�in adres tutar.
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

int enbuyuk(int dizi[10], int lenght)
{
	int enbuyuk = 0; int i;
	printf("%d\n", sizeof(dizi));
	for(i = 0; i < lenght; i++)
	{
		if(dizi[i] > enbuyuk)
			enbuyuk = dizi[i];
	}
	return enbuyuk;
}

void main()
{
	setlocale(LC_ALL, "Turkish");
	srand(time(NULL));
	int ary[10]; int i; int j; int mary[5][2]; int counter = 0;
	int tary[2][3] = {{0, 1}, {8, 7, 3}};
	for(i = 0; i < 2; i++)
	{
		for(j = 0; j < 3; j++)
			printf("tary[%d][%d]: %d\n", i, j, tary[i][j]);
	}
	for(i = 0; i < 10; i++)
		*(ary + i) = rand() % 100;
	for(i = 0; i < 10; i++)
		printf("%d.eleman: %d\n", i + 1, *(ary + i));
	printf("%p - %p\n", ary, &ary[0]);
	for(i = 0; i < 5; i++)
	{
		for(j = 0; j < 2; j++, counter++)
				*(mary[i] + j) = rand() % 100;
			
	}
	counter = 0;
	for(i = 0; i < 5; i++)
	{
		for(j = 0; j < 2; j++, counter++)
			printf("[%d]", **(mary + counter));
		printf("\n");
	}
	printf("%p - %p - %p\n", mary, mary[0], &mary[0][0]);
	printf("En b�y�k eleman: %d\n", enbuyuk(ary, sizeof(ary) / 4));
}

#include <stdio.h>
#include <ctype.h> /*�rneklerde g�rece�imiz toupper fonksiyonunun bar�nd�rd��� standar c k�t�phanesi.*/
#include <locale.h>

/*PROGRAM DENET�M DEY�MLER�
	Program denetim deyimleri kar��la�t�ma ve d�ng� deyimleri olarak ikiye ayr�l�r.

1-Kar��la�t�rm Deyimleri: if ve switch olmak �zere iki tip kar��la�t�rma deyimi vard�r.
	if - else if - else -> else if ve else yap�lar� if yap�s�ndan farkl� olarak d���n�lmemesi gerekir. if yap�s� ingilizce e�er anlam�na gelir. Parantezleri aras�na bir ko�ul yaz�l�r ve
	ko�ul true d�nderiyor ise scopelar� aras�ndaki i�lem yap�l�r. Sadece if yazarak else if veya else deyimlerini kullanmadan if yap�s�n� tek olarak yazabiliriz. if yap�s�n� yazd�ktan 
	sonra i�erisindeki ko�ul sa�lanm�yor ise else deyimi, sa�lanm�yor fakat ba�ka bir ko�ulun sa�lanmas� bekleniyor ise else if yap�s� kullan�l�r. else ingilizce de�il anlam�na gelir 
	yani e�er if i�erisindeki ko�ul false gelir ise alt�nda da else var ise bu yap� �al���r. else if ingilizce de�ilse e�er anlam�na gelir. �lk olarak if yap�s� i�erisindeki ko�ul
	false gelmelidir. Daha sonra alt tarafta else if var ise oraya girilir ve else if yap�s�n�n ko�ulu incelenir. Alt tarafta yine bir yap� varsa oraya ge�i� yap�l�r.
	if(ko�ul)
	{
		ko�ul true d�nderirse buraya girer.
	}
	else if(ko�ul)
	{
		if yap�s�ndaki ko�ul false bu yap�daki ko�ul true d�nderirse buraya girer.
	}
	else
	{
		yukakar�daki t�m ko�ullar�n sa�lanmad��� yani false d�nderdi�i durumda buraya girer. en sona yaz�l�r devam� olarak else veya else if deyimi kullan�lmaz.
	}
	NOT: if yap�s� alt�na if yazarsak, yani iki adet if yaparsak ikisi de ayr� olarak de�erlendirilir ve iki if yaps�n�n ko�ulu da sa�lan�yor ise ikisine de giri� yapar. Yukardaki
	yazd���m�z if, else if ve else yap�s�n� ba�ta kesinlikle if olmak, else kullan�lmak isteniyorsa en alta koymak �art� ile birle�ik bir yap�d�r. �stendildi�i kadar else if eklenebilir
	fakat sadece bir tane if ve else yap�s� olmak zorundad�r. Burada kurdu�umuz birle�ik yap�da birbirine ba�l� ko�ullar vard�r. Yada operat�r�n� g�rm��t�k asl�na yada operat�r�ne 
	benzerdir, sadece bir yap�da true olmas� beklenir, e�er bir ko�ulda true g�zlenir ve scopelar� aras�na girerse di�er yap�lara bak�lmaz. Bu birle�ik yap�y� kurmak zorunda de�iliz
	bunda �zg�r�z ama dikkat edilmesi gerekenler �unlard�r.
		-if yap�s� olmadan else if deyimi kullan�lamaz.
		-else if yap�s� istenildi�i miktarda yaz�labilir, i�erisine bir ko�ul almal�d�r.
		-else yap�s� if yap�s� olmadan kullan�lmaz ve else yap�s�, her if yap�s�na aittir. Yani else yap�s�n�n say�s� if yap�s�n�n say�s�n� ge�emez.
		-Her if yap�s�n�n else veya else if yap�s� olmak zorunda de�ildir.
		-else yap�s� ko�ul i�ermez.
	�rnek program1_1 fonksiyonunda yaz�lm��t�r. �nceleyin ve kullan�c� ad�, �ifre isteyen e�er do�ru ise program� sonland�ran ve ho�geldiniz mesaj� yazan, e�er yanl�� ise tekrar
	deneyiniz diyip tekrardan kullan�c� ad� �ifre isteyen program� yaz�n.
	------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	switch -> switch yap�s� da bir kontrol deyimidir. if yap�s�ndan farkl� olarak say�sal ve karakter de�i�kenlerin i�eri�ine g�re i�lem yapar. if yap�s�ndan daha h�zl�d�r fakat if
	yap�s� kadar kapsaml� de�ildir. �rnek vermek gerekirse d�rt mevsim vard�r, yaz->1, sonbahar->2, k��->3 ve ilkbahar->4 de�erleri alan short int mevsim; isimli bir de�i�kenimiz olsun,
	mevsimlerin her biri i�in ayr� ayr� i�lem yapt�racak olal�m, bunun i�in if yap�s� kullan�labilir fakat switch yap�s� direkt olarak de�i�ken i�eri�ine g�re i�lem yapt��� i�in,
	switch yap�s� kullan�l�r.
	switch(de�erine g�re kontrol edilecek de�i�kenin ismi)
	{
		case 'de�er':
			case yan�na yaz�lan de�er de�i�kende aranan de�er ise true d�ner ve buraya giri� yap�l�r.
			break; /*i�lemler bittikten sonra alt case lere ge�memesi i�in break diyerek switch deyimi bitirilir.
		case 'de�er':
		
			break;
		default:
			Yukar�daki hi� bir switch deyimindeki de�erler do�ru de�il ise yani sa�lanm�yor ise son olarak buradaki i�lem yap�l�r yani kullan�c� 4 adet mevsim var giri� yapabilece�i
			de�erler aras�nda se�im yapmaz ise buradaki i�lem yap�l�r.
			break;
	}
	�rnek program1_2 fonksiyonunda yaz�lm��t�r. �nceleyin ve switch yap�s�n�n avantajlar� ve dezavantajlar�n� ara�t�r�n, switch deyimi kullan�lmas� daha performansl� oldu�unu
	d���nd���n�z ba�ka bir �rnek program yaz�n�z.
	
2-D�ng� Deyimleri: while, do while ve for olmak �zere �� adet d�ng� deyimi vard�r. D�ng� deyimleri bir program� belirli bir ko�ul i�in true d�nderdi�i zaman yani if de ko�ul sa�land���
zaman scope aras�n girip i�lem yap�yorken d�ng� deyimlerinde scope aras� tekrarlan�yor.
	while -> Belirli bir ko�ul veya mant�ksal operat�rler ile birle�tirilmi� ko�ullar (Kar��la�t�rma deyimlerinde de bu �ekildedir) true d�nderirse d�ng� scopelar� aras�na girer.
	while(ko�ul)
	{
		ko�ul true d�nderirse buraya girer bu i�lemler bittikten sonra tekrar ko�ul kontrol edilir e�er hala ko�ul true ise tekrar scope aras�na girilir. ko�ul sa�lanmayana kadar
		program buraya girer.
	}
	�rnek program2_1 fonksiyonunda g�sterilmi�tir.
	-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	do while -> while ile ayn� i�i yapar fakat tek fark� ba�lang�c�nda do oldu�u i�in d�ng�y� program ilk okudu�u anda ko�ul sa�lanmasa dahi i�eriye girer ve daha sonra ko�ul kontrol
	edilir e�er ko�ul sa�lan�yor ise tekrardan scope aras�na girilir.
	do
	{
		ilk seferde bu scope aras�na girilir ikinci seferde ko�ul alan�na gider e�er true d�n�yorsa tekrardan buraya girer sa�lanm�yor ise program devam eder.
	}while(ko�ul);
	-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	for -> while ve do while d�ng�lerinden iki adet fark� vard�r. Bunlar for d�ng� deyiminde saya� olmas� ve bu saya� ile ilgili i�lem yapabilmemizdir.
	for(saya� i�in kullan�lacak de�i�kene verilecek ilk de�er; ko�ul; saya� i�in yap�lacak i�lem)
	{
		�lk de�er ve i�lem b�l�m� bo� b�rak�labilir sanki varm��da yazm���z gibi ; konur. ko�ul sa�lan�r ise true d�nderir ve scope i�erisine girer.
			-�lk �al��mada ilk de�er k�sm� okunur daha sonra ko�ul okunur true ise scope aras�na girer.
			-Scope aras�na girip ��kt�ktan sonra ilk olarak saya� i�lem k�sm�na girer i�lem varsa yap�l�r daha sonra ko�ul k�sm�na girer ko�ul true ise tekrarlan�r.
	}
	�dev Yazd���m�z banka program�n� for d�ng�s�yle yaz�n ve for d�ng�s� ne i�in program deyimi olarak kullan�lmaktad�r ara�t�r�n.(while ve do while varken neden for a ihtiya� olmu�)
	
'break' VE 'continue' DEY�MLER�:
	break -> Sadece d�ng� deyimleri ve switch deyimi i�erisinde kullan�l�r. Program break deyimi �zerinde geldi�i zaman yani okudu�u zaman hi� bir ko�ula bakmaks�z�n i�inde bulundu�u
	deyimden d��ar� ��kar.
	�dev �� i�e d�ng� kulland���m�z zaman ve en i�te break deyimini kullan�rsak ne olur ?
	-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	continue -> Saece d�ng� deyimleri i�erisinde kullan�lan continue, d�ng� scopelar� aras�ndan ��kmam�za, devam etmemize yarar. Yani bir d�ng� ko�ulu sa�land���nda(true) scope aras�na
	giriyordu, program continue deyimini g�rd��� anda scope i�erisindeki continue alt�ndaki her�eyi yoksayarak tekrar while ve do while ise ko�ul, for ise artt�rma i�lemine daha sonra
	ko�ula gider.
	�dev �� i�e d�ng� kulland���m�z zaman ve en i�te continue deyimi kullan�rsak ne olur ?
	
goto DEY�M�
	Programc�lar taraf�ndan kodlar�n okunabilirli�ini azalt�yor gibi �e�itli nedenlerden �nerilmese de bazen kullanmam�z gerekecek alanlar olabilir. goto �ngilizce git anlam�na gelir.
Program�n herhangi bir yerine (birden fazla olabilir) etiket koyar�z ve goto diyerek o etiketi i�aret ederiz. Program kodlar� sat�r sat�r okur ve goto 'etiket'; dedi�imiz zaman program
etiketin bulundu�u sat�ra gider ve sanki orda kalm�� gibi a�a��ya do�ru sat�r sat�r devam eder. Etiket -> 'etiket ismi': tek t�rnaklar olmadan etiketin ismi ve daha sonra ':' operat�r�
ile koyulur goto deyimi ise -> goto 'etiket ismi'; �eklinde tek t�rnaklar olmadan kullan�l�r.
	
�DEVLER
	**-puts ve gets haz�r k�t�phane fonksiyonlar�n� ara�t�r.
	**-switch case d�ng�s�nde break deyimi kullan�lmazsa ne olur ?
	*-do while ile while aras�nda ki fark� bildi�inizi g�stermek i�in while kullan�lmas� gereken bir program ard�ndan da do while kullan�lmas� gereken program yaz�n�z.
	**-Asal say� bulma program�n� ayr� bir fonksiyon kullanarak (recursive olmadan) yaz�n�z.
	**-Klavyeden iki adet say� isteyin ve bir adet aritmetik i�lem operat�rlerinden herhangi birini isteyin. Kullan�c�n�n girdi�i operat�re g�re sonucu hesaplayan program� yaz�n�z.
	**-rand() fonksiyonunu ara�t�r�n ve say� tahmin oyunu yap�n.
	
ZOR �DEV: Kullan�c�dan ikinci dereceden bir denklem isteyip denkleminin k�kleri reel farkl� m�, reel e�it mi veya karma��k m� bulan program� yaz�n. �dev bitene kadar zaman var.
*/

void program1_1()
{
	/*Bu �rnek recursive fonksiyon ile yap�lm��t�r. Recursive fonksiyonu daha sonra ��renece�iz.*/
	/*Static tan�mlad�k ��nk� program1.1 fonksiyonuna her girildi�inde tekrardan ramde de�i�ken olu�turulup, her ��k�ld���nda de�i�ken silerek program�n yava�lamas�n� engelledik.*/
	static char ch;
	printf("Devam i�in 'E'\n�ptal i�in 'H'\nSe�iminiz: ");
	ch = getch(); /*Getch klavyeden bir tu�a bas�lmas�n� bekler ve geriye bas�lan tu�u d�nderir.*/
	printf("%c\n", ch); /*getch() fonksiyonu kullan�ld�ktan sonra yani bir tu�a bas�ld�ktan sonra bast���m�z tu� ekranda g�sterilmez. Biz manuel olarak ekranda g�steriyoruz.*/ 
	if(toupper(ch) == 'E') /*Kullan�c� harfi k���k olarak da girmi� olabilece�i i�in ne girilirse girilsin b�y�k harfe d�n��t�rmek i�in toupper() fonksiyonu kullan�ld�.*/
		program1_1(); /*Burada e�er bas�lan tu� 'E' harfi ise tekrardan fonksiyonu �a��r dedik.*/
	else if(toupper(ch) == 'H')
		printf("Ba�ar� ile ��k�� yap�ld� !\n"); /*Burada ��k�� yap�ld��� i�in mesaj yazd�k ve fonksiyonu tekrar �a��rmad�k.*/
	else
	{
		/*'E' veya 'H' harfleri girilmedi ise yanl�� se�im yap�lm��t�r else bu iki ko�ulda sa�lanmad��� i�in �al���r ve tekrar fonksiyon �a�r�l�r.*/
		printf("Yanl�� se�im yap�ld� tekrar deneyiniz !\n");
		program1_1();
	}
}

void program1_2()
{
	static char ch;
	printf("Yaz[y]\nK��[k]\n�lkbahar[i]\nSonbahar[s]\nSe�im yap�n�z: ");
	ch = getch();
	/*�ngilizce de b�y�k '�' harfi olmad��� i�in hata ile kar��la�abiliriz. B�y�k '�' harfinin ascii kodu -104 d�r if yap�s� ile e�er b�y�k '�' girilmi� ise k���k 'i' harfi yap�yoruz.*/
	if((int)ch == -104)
		ch = 'i';
	switch(tolower(ch)) /*B�y�k harf girilmi� olabilir, tolower fonksiyonu ile k���k harfe d�n��t�rme yap�yoruz.*/
	{
		case 'y':
			printf("y\n"); /*getch fonksiyonunun bas�lan tu�u ekrana yazmad���n� s�ylemi�tik bu y�zden y harfi yazd�rd�k ba�ta.*/
			printf("Yaz mevsiminin aylar�: Haziran, Temmuz ve A�ustos aylar�d�r.\n");
			break;
		case 'k':
			printf("k\nK�� mevsiminin aylar�: Aral�k, Ocak ve �ubat aylar�d�r.\n");
			break;
		case 'i':
			printf("i\n�lkbahar mevsiminin aylar�: Mart, Nisan ve May�s aylar�d�r.\n");
			break;
		case 's':
			printf("s\nSonbahar mevsiminin aylar�: Eyl�l, Ekim ve Kas�m aylar�d�r.\n");
			break;
		default:
			printf("Yanl�� se�im yapt�n�z tekrar deneyiniz !\n");
			program1_2();
			break;
	}
}

void program2_1()
{
	/*Bir banka gibi d���nelim ve kullan�c� bankaya bir miktar para yat�rs�n ve 0.02 oran�nda vadeli olsun bu hesap. Yat�r�lan para da vade ile 0.02 oran�nda artacakt�r. Bir noktadan
	sonra durmas� gerekir e�er hesaptaki para yat�r�lan para miktar�n�n 12 kat�n� ge�erse vade bozulsun ve vade bitmi�tir uyaras�s� verilsin.*/
	float vadeOran = 0.02;
	double hesap; double vadeSonu; double yatanPara; double oncekiPara;
	short int i = 1;
	short int ctrl;
	printf("Yat�rmak istedi�iniz para: ");
	scanf("%lf", &hesap);
	yatanPara = hesap;
	vadeSonu = hesap * 12;
	printf("Hesab�n�za %lf TL yat�r�lm��t�r vade oran�n�z %f, hesab�n�zda %lf TL olduktan sonra vadeniz sonland�r�lacakt�r.\n", hesap, vadeOran, vadeSonu);
	while(hesap < vadeSonu)
	{
		oncekiPara = hesap;
		hesap += (hesap * vadeOran);
		printf("%d.G�n\nHesab�n�za %lf TL vadeden dolay� eklenmi�tir.\n", i++, (hesap - oncekiPara));
		do
		{
			printf("Hesap G�r�nt�le[1]\nToplam Kazan�[2]\nDevam[3]\nSe�iminiz: ");
			ctrl = getch() - '0'; /*getch karakterin ascii kodunu al�r, '0' karakterinin ascii kodunu ald���m�z zaman say�sal de�ere ula��r�z.*/
			switch(ctrl)
			{
				case 1:
					printf("1\nHesab�n�zda %lf TL bulunuyor.\n", hesap);
					break;
				case 2:
					printf("2\nToplam kazan�: %lf TL\n", (hesap - yatanPara));
					break;
				case 3:
					printf("3\n");
					break;
				default:
					printf("Se�im yanl��t�r tekrar deneyiniz !\n");
					break;
			}
		}while(ctrl != 3);
	}
	printf("Vadeniz bitmi�tir.\nToplam kazan�: %lf TL\nHesap: %lf TL\n", (hesap - yatanPara), hesap);
}

void main()
{
	a:
	int a; int b;
	setlocale(LC_ALL, "Turkish");
	//program1_1(); /*�lk kar��la�tr�ma deyimi �rnek*/
	printf("\n");
	//program1_2(); /*�kinci kar��la�t�rma deyimi �rnek*/
	printf("\n");
	program2_1(); /*�lk d�ng� deyimi �rnek*/
	goto a;
	goto b;
}

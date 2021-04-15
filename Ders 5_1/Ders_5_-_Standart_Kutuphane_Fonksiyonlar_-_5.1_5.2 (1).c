#include <stdio.h>
#include <stdlib.h> /*malloc gibi fonksiyonlarý içeren kütüphane*/
#include <ctype.h> /*KARAKTERLER ÜZERÝNDE ÝÞLEM YAPAN KÜTÜPHANE 1.1*/
#include <string.h> /*KATARLAR ÜZERÝNDE ÝÞLEM YAPAN KÜTÜPHANE 2.1*/
#include <locale.h>

/*STANDART KÜTÜPHANE FONKSÝYONLARI:
	C dili dediðimiz gibi kütüphanelerden oluþan bir dildir. Dolayýsý ile C de profesyonel yada amatör bir çok kütüphane vardýr ve yazýlmaya devam edilebilir. Bu da bizim bir programý
farklý iþletim sistemleri üzerinde çalýþtýrmamýzý engeller. Yani biz windows üzerinde çalýþtýrýlýp derlenen bir programý linux içerisinde derleyip çalýþtýramayabiliriz, çünkü
kütüphaneler ve derleyiciler farklýdýr. Bu yüzden standartlaþtýrma adýna ANSI C(American National Standards Institute C) ile belirli standartlaþtýrmalar getirilmiþtir. Bu bölümde
standart kütüphaneler ve içeriklerini, 11 bölümde inceleyeceðiz.
NOT: Bütün fonksiyonlarýn örnekleri main fonksiyonu içerisinde yukardan aþaðý doðru vardýr.
NOT: Geçen bölümlerde standart giriþ çýkýþ fonksiyonlarýný araþtýrýlmasýný ödev olarak istemiþtik bu bölümde not olarak 6 adet standart giriþ/çýkýþ fonksiyonlarý vardýr bunlardan
printf ve scanf fonksiyonu esgeçilerek
	puts(parametre) -> Tek bir metinsel parametre alýr, int, float vb gibi parametreler yazdýrýlamazlar. Yani char dizisi veya çift týrnak içerisinde metinsel ifade yazdýrýlabilir. Bu
	fonksiyon ile yazýlan metinsel ifadeden sonra direkt olarak \n yapar ve alt satýra geçilir.
	gets(parametre) -> Char dizisini parametre olarak kabul eder fakat direkt char kullanarak bir deðiþken yazýlýrsa uyarý verir ama hata vermez önerilmez. Bu char dizisi olarak aldýðý
	parametrenin içerisine ekrandan girilen bir metini atar peki bu fonksiyonun scanf fonksiyonundan farký nedir ? scanf fonksiyonu boþluk tab ve enter karakterlerini girilen metin
	içerisine almaz yani bu karakterlerden enter a basýlýrsa fonksiyon kesin olarak sonlanýr, boþluk ve taba basýlýrsa bu karakterlerden sonra yazýlan hiç bir metin scanf ile okunamaz.
	gets fonksiyonunda ise sadece enter ile sonlandýrma yapýlýr boþluk ve tab karakterleri de bu fonksiyon ile okunur.

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
1-Karakter Üzerine Ýþlem Yapan Fonksiyonlar Ve Kütüphanesi:
	Adý üzerinde bu bölümde karakterler üzerinde iþlem yapan fonksiyonlarý göreceðiz bunlar için kullanýlacak bir adet kütüphane vardýr. Bu kütüphane içerisindeki fonksiyonlarýn tamamý
"MAKRO" fonksiyonlardýr ve karakter kümesinin içerisindeki sýnýfýný belirleyen ve deðiþtirme fonksiyonlarý ikiye ayrýlabilirler.
	1.1-<ctype.h>
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*isalnum(); -> Ýçerisine int parametre alýr bu int ifade ondalýk sayý tabanýndaki binary koda denk gelir yani içerisine char koyarsak kendisi otamatik cast ederek int a çevirir
		yani binary koda çevirir. Ýçerisine gönderilen karakterin veya ascii kodun karþýlýk geldiði karakterin alfasayýsal kod(a-z, A-Z,0-9) ise 0'dan farklý bir sayý deðil ise 0
		dönderen bir fonksiyondur.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*isalpha(); -> Bu fonksiyonunda parametre gönderimi isalnum fonksiyonu ile aynýdýr. Bu fonksiyon girilen karakterin veya binary kodun karþýlýk geldiði karakterin sayýsal deðer
		mi yoksa harf mi kontrol eden fonksiyondur. Harf ise 0'dan farklý deðer sayý ise 0 dönderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*isascii() -> Diðerleri ile ayný þekilde parametre alýr. Bu fonksiyon girilen karakterin veya binary kodun standart ascii(7 bitlik binary kod 0 - 127) kod mu deðil mi
		anlaþýlmasý	içindir. Geri dönen ifade 0'dan farklý ise ascii kod, 0 ise ascii kod deðil anlamýna gelir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*iscntrl() -> Diðerleri ile ayný þekilde parametre alýr. Eðer karakter kontrol karakteri ise 0'dan farklý, kontrol karakteri deðil ise 0 dönderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*isgraph() -> Diðerleri ile ayný þekilde parametre alýr. iscntrl fonksiyonunun tersidir. Yani eðer karakter kontrol karakteri deðil ise 0'dan farklý, kontrol karakteri ise 0
		dönderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*isdigit() -> Diðerleri ile ayný þekilde parametre alýr. Eðer 0-9 ondalýk sayý ise 0'dan farklý, deðil ise 0 dönderir. (0-9 rakamlarýnýn sayýsal kodu 48-57)
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*isxdigit() -> Diðerleri ile ayný þekilde parametre alýr. Eðer 0-9 ve Aa-Ff arasýnda ise 0'dan farklý deðil ise 0 dönderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*islower() ve isupper() -> Diðerleri ile ayný þekilde parametre alýr. Girilen karakter veya sayýsal kodu girilen karakter küçük harf ise islower için 0'dan farklý, isupper için
		0, büyük harf ise isupper için 0'dan farklý ve islower için 0 dönderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*isprint() -> Diðerleri ile ayný þekilde parametre alýr. Eðer karakter yazýlabilen bir karakter ise 0'dan farklý, deðil ise 0 dönderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*ispunct() -> Diðerleri ile ayný þekilde parametre alýr. Eðer karakter noktalama karakteri ise 0'dan farklý, deðil ise 0 dönderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*isspace() -> Diðerleri ile ayný þekilde parametre alýr. Eðer karakter tab(9), yeni satýr(10), boþluk(32), sayfa alta(page down 12) ve sayfa üste(page up 13) ise 0'dan farklý
		deðil ise 0 dönderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*toupper() ve tolower() -> Diðerleri ile ayný þekilde parametre alýr. Deðiþtirme fonksiyonu olarak bahsedilen fonksiyonlardýr. toupper parametre olarak girilen harfi büyük
		harfe dönüþtürür. tolower ise küçük harfe dönüþtürür. Yani toupper geriye parametre olarak gönderilen harfin büyük harfini dönderir. tolower geriye parametre olarak gönderilen
		harfin küçük harfini dönderir.
Abdullah
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
2-Katarlar Üzerinde Ýþlem Yapan Fonksiyonlar Ve Kütüphanesi:
	Katar, NULL('\0') ile sonlandýrýlmýþ karakter dizisidir. Üzerinde iþlem yapan fonksiyonlar (str... ile baþlar), kopyalama iþlemi yapan fonksiyonlar ve sorgulama iþlemi yapan
fonksiyonlar olmak üzere ikiye ayrýlýr. Kopyalama iþlemi yapan fonksiyonlar genelde karakter iþaretçi dönderirler. Sorgulama yapan fonksiyonlar ise genelde mantýksal sonuç(0 veya 1)
dönderirler.
	Buna ek olarak bellek üzerinde iþlem yapan fonksiyonlar (mem... ile baþlar) katar üzerine iþlem yapanlara benzer, fakat bunlar NULL ile sonlandýrýlmazlar.
NOT: Bir katar diðerine kopyalanýrken yeteri kadar bellek alaný olmadýðý durumlarda, hatalar ile karþýlaþýlabilir.
	2.1-<string.h> (char k1[size]; char k2[size]; üzerinden gidilecektir. Pointer biçimi ile tanýmlanmýþ katarlar da bu fonksiyonlara dahildir.)
		*strcat(char k1, const char k2) -> Görüldüðü üzere bu fonksiyon iki adet parametre alýr ve ikinci parametresi const olarak tanýmlanmýþtýr. Bunun sebebi eðer gördüðümüz call by
		referance þeklinde yani pointer þeklinde bir veri gönderilir ise deðiþimden korumak için const olarak belirlenmiþtir. Bu fonksiyon k1 katarýnýn sonuna(yani NULL olan yerine)
		k2 katarýný ekler. Geriye dönüþ deðeri k1 katarýnýn baþlangýç adresidir.(Dizilerde adresleme konusunu sözel olarak anlatacaðým)
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*strncat(char k1, const char k2, int size) -> strcat fonksiyonundan tek farký k1 katarýna k2 katarýnýn 3.parametre olan size parametresi kadar olan elemanlarýný eklemesi
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	--	*strchr(const char k1, int aranan) -> Görüldüðü gibi iki adet parametre alýr. aranan parametresi bir sayýsal koda denk gelir. Bu fonksiyon bu girilen sayýsal koda karþýlýk gelen
		karakter, k1 katarý içerisinde var ise(Bulunan ilk yerde durur yani hakan da iki adet a vardýr ilk a yý gördüðünde durur soldan saða okur) katar içerisinde bulunan yerin
		adresini dönderir, yok ise NULL dönderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		strrchr(const char k1, int aranan) -> strchr fonksiyonundan tek farký arama iþlemine saðdan baþlamasýdýr.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*strcmp(const char k1, const char k2) -> Ýki adet parametre alýr. Bu girilen parametrelerin eþitliðini kontrol eder. Eðer bu iki katar eþit ise 0 dönderir. k1 alfabetik sýrada
		k2 den sonra ise pozitif, önceyse negatif dönderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*strncmp(const char k1, const char k2, int size) -> strcmp fonksiyonundan tek farký k1 katarý ile k2 katarýný 3.parametre olan size kadar karþýlaþtýrma yapmasý.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*strcoll(const char k1, const char k2) -> strcmp fonksiyonu gibi katarlar arasýndaki iliþkiyi kontrol eder. Arasýndaki fark strcmp alfabesel üstünlüðe göre kontrol ederken
		bu fonksiyon ascii kod tablosundaki sayýsal üstünlüðe göre kontrol eder. Geri dönüþ deðeri strcmp ile aynýdýr. pozitif ise büyük, negatif ise küçük veya 0 ise eþit.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*strcpy(char k1, const char k2) -> k1 katarýna(k1 katarýnýn eski hali silinir) k2 katarýnýn deðerini yerleþtirir. Geriye k1 katarýnýn baþlangýç adresini dönderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*strncpy(char k1, const char k2, int size) -> strcpy fonksiyonundan tek farký k1 katarýna k2 katarýnýn 3.parametre olan size kadar elemaný kopyalamasý.(atama)
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------		
		*strcspn(const char k1, const char k2) -> strchr() fonksiyonuna benzer bir iþlem görür. strchr fonksiyonu girilen katar içerisinde girilen karakterin var mý yok mu olduðunu 
		kontrol edip ilk bulunduðu yerin adresini dönderir, bulunmaz ise null dönderirdi. Bu fonksiyon ise k1 katarýnýn içerisinde k2 katarýnýn karakterleri arasýnda varmý yok mu
		kontrol eder.(k1 katarýnýn baþýndan baþlayarak) k1 katarýnýn içerisinde olmayan karakter sayýsýný verir.(Örneðin kullanýcýdan bir metin girilmesini istedik ve bazý
		karakterlerin olmasýný istemedik yani strcpsn fonksiyonunun 0 dönmesini istedik buna göre kontrol ettirebiliriz.) DÝKKAT: BULUNMADIÐI ALT KÜMEYÝ DÖNDERÝR.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*strspn(const char k1, const char k2) -> strcspn fonksiyonu k2 katarýnýn elemanlarýnýn olmadýðý en uzun alt kümeyi dönderiyordu. Bu fonksiyon ise içerdiði en uzun alt kümeyi
		dönderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*strerror(int errno) -> Genellikle parametre yerine gönderilirken errno sabiti kullanýlýr. Eðer hata adresi biliniyorsa hata adresi girilir ve geriye hata mesajýný dönderir.
		Hata adresi bilinmiyor ise kendi çaðrýldýðý yerden önce karþýlaþýlan hatanýn hata mesakýný dönderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*strlen(const char k1) -> Girilen katarýn NULL dýþýnda içerdiði karakter sayýsýný dönderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*strpbrk(const char k1, const char k2) -> k1 katarýnýn içerisinde k2 katarýnýn herhangi bir elemaný olup olmadýðýný araþtýrýr. Bulunursa bulunan ilk yerin adresini, bulunmazsa
		NULL dönderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*strstr(const char k1, const char k2) -> k1 katarýnýn içerisinde k2 katarýnýn(fark edildiði üzere strpbrk fonksiyonundan farký, strpbrk fonksiyonu k2 katarýnýn elemanlarýndan
		herhangi birinin içermesi durumunu kontrol ederken bu fonksiyon k2 katarýnýn tamamýnýn içerip içermediðin kontrol ediyor) varlýðýný araþtýrýr. Eðer varsa bulunan yerin ilk
		adresini dönderir, yoksa NULL dönderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*strtok(cosnt char k1, const char k2) -> k1 katarýný k2 katarýna göre parçalamak için kullanýlýr. Örnek üzerinden gitmek gerekirse "Merhaba c dünyasý ne haber, ne iþ" þeklinde
		olan bir katarý strtok("Merhaba c dünyasý ne haber, ne iþ", " ,") Görüldüðü üzere k2 katarýna virgül ve boþluk koyduk bu fonksiyon boþluk veya , görene kadar ki kýsmý
		böler geriye "Merhaba" kalýr ve adresini dönderir. Daha sonra null koyarak bunu devam ettirirsek yani strtok(NULL, " ,") þeklinde sona kadar parçalama devam eder.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*strxfrm(char k1, const char k2, int size) -> Bu fonksiyon, farklý sayý kümelerinde ki(örneðin ASCII olmayan ve olan) deðerleri kýyaslamak için uygun bir forma dönüþtürür.
		k2 katarýnýn size kadar elemanýný dönüþtürerek k1 katarýna atar.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*memchr(char *adres, char ch, int size) -> Bu fonksiyon, verilen adresten baþlayarak size kadar 8 bitlik ilerleyerek kr karakterinin varlýðýný araþtýrýr. Eðer bulursa bulduðu
		yerin adresini bulamaz ise NULL dönderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*memcmp(char *adres, char *adres, int size) -> Verilen iki adresteki deðerleri size kadar 8 bitlik deðer okuyarak karþýlaþtýrýr. Ayný ise 0, ilk parametredeki adreste var olan
		metin alfabetik olarak daha önce ise negatif, daha sonra ise pozitif deðer dönderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*memcpy(char *adres, char *adres, int size) -> Verilen ikinci adresteki deðeri size kadar 8 bitlik veriyi, birinci adresteki deðere atar ve ilk adresi dönderir. Ýki bellek
		alaný kesiþirse yani ilk adresten 8 bitlik ilerlemeye baþladýktan sonra ikinci adres ile kesiþirse ne olacaðý belli deðildir.(overlap)
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*memmove(char *adres, char *adres, int size) -> memcpy ile ayný görevi yapar fakat iki adres kesiþtikleri zaman bile doðru biçimde kopyalama iþlemi yapar.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*memset(char *adres, char ch, int size) -> Verilen parametredeki adrese ch karakteri veya sayýsal kodu verilmiþ karakteri, size kadar 8 bitlik alana yerleþtirir.
		(Bazý fonksiyonlarda verilen 8 bitlik yani 1 byte lýk alan denmesinin sebebi c deki her bir karakter 1 byte yer kaplamasýdýr. Biz kadar olarak kullandýðýmýz zaman örneðin
		8 harfli bir katar kullanýrsak bu ramde 8 byte yer kaplar.)
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		NOT: errno sayýsal bir deðer tutar. Nasýl ascii kod tablosunda 32 space anlamýna gelirse, errno için de sayýsal kodlar bazý hata mesajlarýna denk gelir. Hata ile karþýlaþýldýðý
		anda errno sabitine o hata ile ilgili hata kodu deðeri atýlýr.
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

ÖDEVLER
	**-Mantýksal bir iliþki kurarak karakter üzerinde iþlem yapan fonksiyonlar ile her durumu kontrol edecek þekilde bir program yazýnýz.
	-Mantýksal bir iliþki kurarak katarlar üzerinde iþlem yapan fonksiynolar ile ayrý ayrý örnekler yazýnýz.
*/

void program1()
{
	/*1 Karakter üzerinde iþlem yapan fonksiyonlar örnekleri*/
	char ch;
	printf("Test edilecek karakteri girin: ");
	ch = getch(); /*getch fonksiyonu getchar fonksiyonu ile aynýdýr bir kýsaltmasýdýr. Ayný þekilde putch fonksiyonu da putchar fonksiyonunun kýsaltmasýdýr.*/
	printf("%c\n",ch); /*Getch fonksiyonu ile klavyeden basýlan tuþ direkt olarak alýnýr ve ekrana girilen tuþ gözükmez bu yüzden biz manuel olarak basýyoruz.*/
	if(isalnum(ch))   /*Eðer kontrol operatörü koymadan direkt olarak fonksiyon bu þekilde yazýlýrsa 0'dan farklý deðerler true 0 olan deðerler false sayýlýr.*/
	{
		/*Girilen karakter alfasayýsal ise ya harftir yada sayýdýr. Sayý mý harf mi ayrýmýný da bu if içerisinde yapmamýz gerekir.*/
		puts("Alfasayýsal bir karakterdir !");
		if(isalpha(ch))
		{
			/*islower ve isupper alfa karakterler için iþlem yapýlýr dolayýsý ile alfa karakter anlamýna gelmesi yani bu if içerisinde kullanýlmasý gerekir.*/
			puts("	Alfa Bir Karakterdir !"); /*Alfa Harf Anlamýna Gelir.*/
			if(islower(ch))
			{
				puts("		islower Fonksiyonu Ýle Küçük Harf !");
				ch = toupper(ch);
				printf("		toupper Fonksiyonu Ýle Büyük Harf'e Dönüþtürüldü !(KARAKTER: %c)\n", ch);
			}
			else
			{
				puts("		islower Fonksiyonu Ýle Küçük Harf Deðil !");
				ch = tolower(ch);
				printf("		tolower Fonksiyonu Ýle Küçük Harf'e Dönüþtürüldü !(KARAKTER: %c)\n", ch);
			}
			if(isupper(ch))
			{
				puts("		isupper Fonksiyonu Ýle Büyük Harf !");
				ch = tolower(ch);
				printf("		tolower Fonksiyonu Ýle Küçük Harf'e Dönüþtürüldü !(KARAKTER: %c)\n", ch);
			}
			else
			{
				puts("		isupper Fonksiyonu Ýle Büyük Harf Deðil !");
				ch = toupper(ch);
				printf("		toupper Fonksiyonu Ýle Büyük Harf'e Dönüþtürüldü !(KARAKTER: %c)\n", ch);
			}
		}
		else
		{
			/*Sayýsal olmayan bir rakam olamadýðý için isdigit ve isxdigit fonksiyonlarýnýn da bu else içerisinde kullanýlmasý gerekir. isxdigit fonksiyonunun ayrý olarak alfa
			kodlara	ait rakamlarý o*/
			puts("	Sayýsal Bir Karakterdir !");
			if(isdigit(ch)) /*0-9 arasýnda rakammý kontrol edilir.*/
				puts("		Ondalýk Bir Rakam !");
			else
				puts("		Ondalýk Bir Rakam Deðil !");
			if(isxdigit(ch))
				puts("		Onaltýlýk Bir Rakam !");
			else
				puts("		Onaltýlýk Bir Rakam Deðil !");
		}
	}
	else
	{
		/*Eðer girilen alfasayýsal bir karakter deðil ise noktalama iþareti olma þansý var bu yüzden bu else içerisinde ispunct fonksiyonu kullanýlacak.*/
		puts("Alfasayýsal Bir Karakter Deðildir !");
		if(ispunct(ch))
			puts("	Noktalama Ýþaretidir !");
		else
			puts("	Noktalama Ýþareti Deðildir !");
	}
	if(isascii(ch))
	{
		/*Burada bir de kontrol karakteri mi deðil mi onu kontrol edeceðiz. Kontrol karakterleri ascii kod olarak 0 - 32 ve 127 ye denk gelir dolayýsý ile ascii kod olmayan kontrol
		karakteri yoktur o yüzden bu if içerisinde kontrol edeceðiz.*/
		puts("Ascii Koddur!");
		if(iscntrl(ch))
			puts("	iscntrl Fonksiyonu Ýle Kontrol Karakteridir !"); /*non-printing yani enter home vb tuþlar gibi de denilebilir.*/
		else
		{
			/*Görüldüðü üzere isspace fonksiyonu için kontrol edilen deðerler iscntrl ile kontrol edilen deðerler kümesi ile ayný bu yüzden bu else içerisinde kullanýrýz.*/
			puts("	iscntrl Fonksiyonu Ýle Kontrol Karakteri Deðildir !");
			if(isspace(ch))
				puts("		Girilen Karakter Boþluk Karakterleridir !");
			else
				puts("		Girilen Karakter Boþluk Karakterleri Deðildir !");
		}
		if(isgraph(ch)) /*Görüldüðü gibi yazýlabilir deðerleri kontrol eder yani iscntrl fonksiyonunun tersidir.*/
			puts("	isgraph Fonksiyonu Ýle Kontrol Karakteri Deðildir !");
		else
		{
			/*Görüldüðü üzere isspace fonksiyonu için kontrol edilen deðerler iscntrl ile kontrol edilen deðerler kümesinin tersi ile ayný bu yüzden bu else içerisinde kullanýrýz.*/
			puts("	isgraph Fonksiyonu Ýle Kontrol Karakteridir !");
			if(isspace(ch))
				puts("		Girilen Karakter Boþluk Karakterleridir !");
			else
				puts("		Girilen Karakter Boþluk Karakterleri Deðildir !");
		}
	}
	else
		puts("Ascii Kod Deðildir !");
	if(isprint(ch))
		puts("Yazýlabilen Bir Karakterdir !");
	else
		puts("Yazýlamayan Bir Karakterdir !");
}

void program2_1()
{
	/*2 Katarlar üzerinde iþlem yapan fonksiyonlar örnekleri*/
	/*Aþaðýda yapýlan iþlem kýsaca anlatýlmak istenirse, biz klavyeden girilecek karater sayýsýný bilemiyoruz dolayýsý ile buna göre static olarak yani dizi biçiminde bir deðiþken
	oluþturmak performansý etkiler. Bu yüzden bir tane klavyeden girilen metni tutan geçici bir buf isiminde sabit bir dizi ile tutulup daha sonradan bunun sayýsýna göre pointera bellek
	ayýrma yapýyoruz. k1 pointerýnýn boyutunu arttýrýyoruz ki k2 pointerýnýn deðerini de tutabilsin.*/
	char buf[100]; /*Klavyeden girilen yazýnýn boyutunu öðrenmek için kullanýlan geçici bellek olarak düþünülebilir.*/
	char *k1; char *k2; char src;
	int buflenght; int i;
	printf("Ýsim: ");
	gets(buf);
	buflenght = strlen(buf); /*Klavyeden girilen ismin karakter sayýsýný buluyor. (NULL KARAKTER OLARAK SAYILMAZ)*/
	k1 = (char *)malloc(sizeof(char) * buflenght);
	strcat(k1, buf); /*k1 zaten boþ bu yüzden ekleme iþlemi yaptýk ayný zamanda taþýma iþlemi de yaptýk.*/
	printf("Soyisim: ");
	gets(buf);
	buflenght = strlen(buf);
	k2 = (char *)malloc(buflenght);
	strcat(k2, buf);
	strcpy(buf, "\0");
	k1 = (char *)realloc(k1, sizeof(char) * (buflenght + 1 + strlen(k1))); /*+1 aþaðýda yapýlan boþluk eklemesinden dolayýdýr.*/
	strcat(k1, " ");
	strcat(k1, k2);
	printf("Hoþgeldin %s\n", k1); /*Katar pointerlar yazýlýrken * ihmal edilir.*/
	puts("");
	free(k1);
	free(k2);
}

void program2_2()
{
	char buf[100]; /*Klavyeden girilen yazýnýn boyutunu öðrenmek için kullanýlan geçici bellek olarak düþünülebilir.*/
	char *k1; char *k2; char src;
	int buflenght; int i;
	printf("k1 katarý: ");
	gets(buf);
	buflenght = strlen(buf); /*Klavyeden girilen ismin karakter sayýsýný buluyor. (NULL KARAKTER OLARAK SAYILMAZ)*/
	k1 = (char *)malloc(sizeof(char) * buflenght);
	strcat(k1, buf); /*k1 zaten boþ bu yüzden ekleme iþlemi yaptýk ayný zamanda taþýma iþlemi de yaptýk.*/
	printf("k2 katarý: ");
	gets(buf);
	buflenght = strlen(buf);
	k2 = (char *)malloc(buflenght);
	strcat(k2, buf);
	strcpy(buf, "\0");
	printf("k1 katarýnýn uzunluðu %d, k2 katarýnýn uzunluðu %d\n", strlen(k1), strlen(k2));
	printf("\nGirilen k1 katarýnda aratmak istediðiniz karakter: ");
	src = getch();
	if(isspace(src)) /*Girilen karakter boþluk ise boþluk karakteri nonprinting olduðu için yazýlamaz bu yüzden bu if yapýsýný kurduk.*/
		printf("BOÞLUK\n");
	else
		printf("%c\n", src);
	if(strchr(k1, src) != NULL)
	{
		/*While iþlemi kaçýncý indiste bulunduðunu bulmak için*/
		i = 0;
		while((k1 + i) != strchr(k1, src))
			i++;
		printf("Aranan karakter %p bellek adresinde %d. indiste bulundu !\n", strchr(k1, src), i);
	}
	else
		puts("Aranan karakter bulunamadý !");
	/*k1 katarýna harf, k2 katarýna sayýsal bir deðer girilmesini istemediðimizi farzederek bir kontrol yapýsý.*/
	if(strcspn(k1, "abcdefghýijklmnoöprsþtuüvyzABCDEFGHIÝJKLMNOÖPRSÞTUÜVYZ") != 0)
		puts("Baþarýlý k1 katarýna harf girilmedi !");
 else
		puts("Baþarýsýz k1 katarýna harf girildi !");
	if(strcspn(k2, "0123456789") != 0)
		puts("Baþarýlý k2 katarýna rakam girilmedi !");
	else
		puts("Baþarýsýz k2 katarýna rakam girildi !");
	FILE *fp; /*Dosyalama iþleminde görülecek kodlar.*/
	fp = fopen("file.txt", "r");
	printf("Error: %s\n", strerror(errno));
	puts("");
	free(k1);
	free(k2);
}

void program2_3()
{
	char buf[100]; /*Klavyeden girilen yazýnýn boyutunu öðrenmek için kullanýlan geçici bellek olarak düþünülebilir.*/
	char *k1; char *k2; char *src;
	int buflenght; int i;
	printf("Yazýlacak metin: ");
	gets(buf);
	buflenght = strlen(buf); /*Klavyeden girilen ismin karakter sayýsýný buluyor. (NULL KARAKTER OLARAK SAYILMAZ)*/
	k1 = (char *)malloc(sizeof(char) * buflenght);
	strcpy(k1, buf); /*k1 zaten boþ bu yüzden ekleme iþlemi yaptýk ayný zamanda taþýma iþlemi de yaptýk.*/
	printf("Ayrým operatörleri: ");
	gets(buf);
	buflenght = strlen(buf);
	k2 = (char *)malloc(buflenght);
	printf("k1 katarý: %s\n", k1);
	strcpy(k2, buf);
	strcpy(buf, "\0");
	i = 1;
	/*Burada aklýnýzda bir soru olmasý gerekir yoksa da sorulan soruyu cevaplamanýz gerekir.*/
	src = strtok(k1, k2);
	while(src != NULL)
	{
		printf("%d.Parça: %s\n", i++, src);
		src = strtok((char *)NULL, k2);
	}
	free(k1);
	free(k2);
}

void program2_4()
{
	char buf[100]; /*Klavyeden girilen yazýnýn boyutunu öðrenmek için kullanýlan geçici bellek olarak düþünülebilir.*/
	char *k1; char *k2; char *src;
	int buflenght; int i;
	printf("Yazýlacak metin: ");
	gets(buf);
	buflenght = strlen(buf); /*Klavyeden girilen ismin karakter sayýsýný buluyor. (NULL KARAKTER OLARAK SAYILMAZ)*/
	k1 = (char *)malloc(sizeof(char) * buflenght);
	strcpy(k1, buf); /*k1 zaten boþ bu yüzden ekleme iþlemi yaptýk ayný zamanda taþýma iþlemi de yaptýk.*/
	printf("Ayrým operatörleri: ");
	gets(buf);
	buflenght = strlen(buf);
	k2 = (char *)malloc(buflenght);
	printf("k1 katarý: %s\n", k1);
	strcpy(k2, buf);
	strcpy(buf, "\0");
	src = memchr(k1, 'A', 10);
	if(src == NULL)
		puts("Bulunamadý !");
	else
		printf("%p adresinde %c deðeri bulundu !\n", src, *src);
}

void main()
{
	setlocale(LC_ALL, "Turkish");
	/*1 Karakter üzerinde iþlem yapan fonksiyonlar örnekleri*/
	//program1();
	/*2 Katarlar üzerinde iþlem yapan fonksiyonlar örnekleri*/
	//program2_1();
	program2_2();
	//program2_3();
	//program2_4();
}


























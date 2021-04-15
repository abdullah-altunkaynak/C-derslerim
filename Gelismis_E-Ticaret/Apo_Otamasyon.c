#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <time.h>
#include <locale.h>

unsigned short int n;
unsigned short int urun_id;

typedef enum
{
	normal, admin
}authority;

typedef enum
{
	false, true
}bool;

typedef struct
{
	unsigned short int primary_key;
	authority yetki;
	char *name;
	char *password;
	char *special_code;
	double fund;
}member;

typedef struct
{
	unsigned short int primary_key;
	char *product_name;
	unsigned short int unit;
	double price;
}stock;

/*Using file names
	*struct uye -> uyeler.txt
	*struct stok -> stok.txt
	*log -> log.txt (giri� ��k�� i�emlerinin kay�tlar�n� tutar.)
*/

/*�ye ��in Primary Key Artt�rma*/
void setkey()
{
	FILE *temp = fopen("key.txt", "w");
	n++;
	fprintf(temp, "%d", n);
	fclose(temp);
}

/*Stok ��in Primary Key Artt�rma*/
void seturun_id()
{
	FILE *temp = fopen("urun_id.txt", "w");
	urun_id++;
	fprintf(temp, "%d", urun_id);
	fclose(temp);
}

/*�ye'nin Veri Taban�nda Varl���n� Kontrol Etme*/
bool checkLogin(char *inpname, char *inppassword, member *uye)
{
	FILE *f = fopen("uyeler.txt", "r"); struct tm *z; time_t nows;
	if(f != NULL)
	{
		while(!feof(f))
		{
			fscanf(f, "%u %d %s %s", &(uye->primary_key), &(uye->yetki), uye->name, uye->password);
			fscanf(f, "%s %lf", uye->special_code, &(uye->fund));
			if(!strcmp(uye->name, inpname) && !strcmp(uye->password, inppassword))
			{
				
				fclose(f);
				return 1;
			}
		}
		fclose(f);
		return 0;	
	}
	else
	{
		puts("Dosya a��lamad� !\n");
		time(&nows);
		z = localtime(&nows);
		f = fopen("log.txt", "a+");
		fprintf(f, "[%d.%d.%d %d:%d:%d] - uyeler.txt dosyas� a��lamad�.\n",z->tm_mday, z->tm_mon + 1, z->tm_year + 1900, z->tm_hour, z->tm_min, z->tm_sec);
		fclose(f);
		return 0;
	}
}

/*�ye Giri�i*/
bool login(member *uye)
{
	system("CLS");
	char *inpname = (char *)malloc(sizeof(char) * 50); char *inppassword = (char *)malloc(sizeof(char) * 50);
	struct tm *z; time_t nows; FILE *f;
	unsigned short int selection;
	do
	{
		printf("Kullan�c� Ad�: ");
		fflush(stdin);
		gets(inpname);
		inpname = (char *)realloc(inpname, sizeof(char) * (strlen(inpname) + 1));
		fflush(stdin);
		printf("�ifre: ");
		gets(inppassword);
		inppassword = (char *)realloc(inppassword, sizeof(char) * (strlen(inppassword) + 1));
		if(checkLogin(inpname, inppassword, uye))
			selection = 2;
		else
		{
			do
			{
				time(&nows);
				z = localtime(&nows);
				f = fopen("log.txt", "a+");
				fprintf(f, "[%d.%d.%d %d:%d:%d] - name: %s, password: %s ile yanl�� kullan�c� giri� denemesi yap�ld�.\n", 
				z->tm_mday, z->tm_mon + 1, z->tm_year + 1900, z->tm_hour, z->tm_min, z->tm_sec, inpname, inppassword);
				fclose(f);
				printf("Kullan�c� ad� veya �ifre yanl�� !\nTekrar Dene[1]\nGeri[2]\nSe�im: ");
				selection = getch() - '0';
				switch(selection)
				{
					case 1:
						puts("Tekrar Dene\n");
						free(inpname);
						free(inppassword);
						inpname = (char *)malloc(sizeof(char) * 50); 
						inppassword = (char *)malloc(sizeof(char) * 50);
						break;
					case 2:
						puts("Geri\n");
						free(inpname);
						free(inppassword);
						return 0;
						break;
					default:
						puts("Yanl�� se�im !\n");
						break;
				}
			}while(selection != 1 && selection != 2);
		}
	}while(selection != 2);
	free(inpname);
	free(inppassword);
	return 1;
}

/*Giri� Yap�lan �ye ��in Kullan�lan Struct Verilerini Optimize Etme*/
void optimization(member *uye)
{
	uye->name = (char *)realloc(uye->name, sizeof(char) * (strlen(uye->name) + 1));
	uye->password = (char *)realloc(uye->password, sizeof(char) * (strlen(uye->password) + 1));
	uye->special_code = (char *)realloc(uye->special_code, sizeof(char) * (strlen(uye->special_code) + 1));
}

/*Yeni Admin Ekleme*/
bool insertAdmin()
{
	FILE *f = fopen("uyeler.txt", "a+");
	struct tm *z; time_t nows;
	if(f != NULL)
	{
		member yeni;
		char *temp = (char *)malloc(sizeof(char) * 50);
		yeni.name = (char *)malloc(sizeof(char) * 50);
		yeni.password = (char *)malloc(sizeof(char) * 50);
		yeni.special_code = (char *)malloc(sizeof(char) * 50);
		printf("Kullan�c� Ad�: ");
		fflush(stdin);
		gets(yeni.name);
		yeni.name = (char *)realloc(yeni.name, sizeof(char) * (strlen(yeni.name) + 1));
		fclose(f);
		f = fopen("uyeler.txt", "r");
		while(!feof(f))
		{
			fscanf(f, "%u %d %s %s %s %d", &(yeni.primary_key), &(yeni.yetki), temp, yeni.password, yeni.special_code, &(yeni.fund));
			if(!strcmp(temp, yeni.name))
			{
				fclose(f);
				time(&nows);
				z = localtime(&nows);
				f = fopen("log.txt", "a+");
				fprintf(f, "[%d.%d.%d %d:%d:%d] - %s admin zaten var oldu�undan dolay� ekleme ba�ar�s�z oldu.\n", z->tm_mday, z->tm_mon + 1, z->tm_year + 1900,
				z->tm_hour, z->tm_min, z->tm_sec, yeni.name);
				fclose(f);
				free(yeni.name);
				free(yeni.password);
				free(yeni.special_code);
				free(temp);
				puts("Eklenmek istenen admin zaten var !");
				return 0;
			}
		}
		fclose(f);
		f = fopen("uyeler.txt", "a+");
		printf("�ifre: ");
		fflush(stdin);
		gets(yeni.password);
		yeni.password = (char *)realloc(yeni.password, sizeof(char) * (strlen(yeni.password) + 1));
		printf("�zel Kod: ");
		fflush(stdin);
		gets(yeni.special_code);
		yeni.special_code = (char *)realloc(yeni.special_code, sizeof(char) * (strlen(yeni.special_code) + 1));
		yeni.fund = 0;
		yeni.primary_key = n;
		yeni.yetki = admin;
		setkey();
		fprintf(f, "%u %d %s %s %s %d\n", yeni.primary_key, yeni.yetki, yeni.name, yeni.password, yeni.special_code, (int)yeni.fund);
		fclose(f);
		time(&nows);
		z = localtime(&nows);
		f = fopen("log.txt", "a+");
		fprintf(f, "[%d.%d.%d %d:%d:%d] - %s yeni admin eklendi.\n", z->tm_mday, z->tm_mon + 1, z->tm_year + 1900, z->tm_hour, z->tm_min, z->tm_sec, yeni.name);
		fclose(f);
		free(yeni.name);
		free(yeni.password);
		free(yeni.special_code);
		free(temp);
		return 1;
	}
	else
	{
		puts("Dosya a��lamad� !\n");
		time(&nows);
		z = localtime(&nows);
		f = fopen("log.txt", "a+");
		fprintf(f, "[%d.%d.%d %d:%d:%d] - uyeler.txt dosyas� a��lamad�.\n", z->tm_mday, z->tm_mon + 1, z->tm_year + 1900, z->tm_hour, z->tm_min, z->tm_sec);
		fclose(f);
		return 0;
	}
}

/*Yeni �r�n Ekleme*/
bool insertProduct()
{
	FILE *f = fopen("stok.txt", "a+");
	struct tm *z; time_t nows;
	if(f != NULL)
	{
		stock yeni;
		char * temp = (char *)malloc(sizeof(char) * 50);
		yeni.product_name = (char *)malloc(sizeof(char) * 50);
		printf("�r�n �smi: ");
		fflush(stdin);
		gets(yeni.product_name);
		fclose(f);
		f = fopen("stok.txt", "r");
		while(!feof(f))
		{
			fscanf(f, "%u %s %u %lf", &(yeni.primary_key), temp, &(yeni.unit), &(yeni.price));
			if(!strcmp(temp, yeni.product_name))
			{
				fclose(f);
				time(&nows);
				z = localtime(&nows);
				f = fopen("log.txt", "a+");
				fprintf(f, "[%d.%d.%d %d:%d:%d] - %s �r�n� zaten var oldu�undan dolay� ekleme ba�ar�s�z oldu.\n", z->tm_mday, z->tm_mon + 1, z->tm_year + 1900,
				z->tm_hour, z->tm_min, z->tm_sec, yeni.product_name);
				fclose(f);
				free(yeni.product_name);
				free(temp);
				puts("Eklenmek istenen �r�n zaten var !");
				return 0;
			}
		}
		fclose(f);
		f = fopen("stok.txt", "a+");
		yeni.primary_key = urun_id;
		seturun_id();
		printf("Adet - Kilo: ");
		scanf("%u", &(yeni.unit));
		printf("Fiyat: ");
		scanf("%lf", &(yeni.price));
		fprintf(f, "%u %s %u %lf\n", yeni.primary_key, yeni.product_name, yeni.unit, yeni.price);
		fclose(f);
		time(&nows);
		z = localtime(&nows);
		f = fopen("log.txt", "a+");
		fprintf(f, "[%d.%d.%d %d:%d:%d] - %s �r�n� sto�a eklendi.\n", z->tm_mday, z->tm_mon + 1, z->tm_year + 1900, z->tm_hour, z->tm_min, z->tm_sec, yeni.product_name);
		fclose(f);
		free(yeni.product_name);
		return 1;
	}
	else
	{
		puts("Dosya a��lamad� \n");
		time(&nows);
		z = localtime(&nows);
		f = fopen("log.txt", "a+");
		fprintf(f, "[%d.%d.%d %d:%d:%d] - stok.txt dosyas� a��lamad�.\n", z->tm_mday, z->tm_mon + 1, z->tm_year + 1900, z->tm_hour, z->tm_min, z->tm_sec);
		fclose(f);
		return 0;
	}
}

/*Var Olan �r�n�n Stokuna Veri Ekleme*/
bool insertUnit()
{
	FILE *f = fopen("stok.txt", "r+");
	struct tm *z; time_t nows;
	if(f != NULL)
	{
		stock tmp;
		char *src = (char *)malloc(sizeof(char) * 50);
		char *filedata = (char *)malloc(sizeof(char) * 50);
		tmp.product_name = (char *)malloc(sizeof(char) * 50);
		char *tmpdata = (char *)malloc(sizeof(char) * 50);
		printf("Aranan �r�n �smi: ");
		fflush(stdin);
		gets(src);
		src = (char *)realloc(src, sizeof(char) * (strlen(src) + 1));
		while(!feof(f))
		{
			fscanf(f, "%u %s %u %lf", &(tmp.primary_key), filedata, &(tmp.unit), &(tmp.price));
			if(!strcmp(filedata, src))
			{
				short int newunit;
				printf("Eklenecek Adet - Kilo: ");
				scanf("%d", &newunit);
				fclose(f);
				FILE *temp = fopen("temp.txt", "w");
				f = fopen("stok.txt", "r");
				strcpy(tmpdata, " ");
				while(!feof(f))
				{
					fscanf(f, "%u %s %u %lf", &(tmp.primary_key), tmp.product_name, &(tmp.unit), &(tmp.price));
					if(strcmp(tmpdata, tmp.product_name) != 0) /*A�a��da tmpdata ya son veri eklendikten sonra yine scanf den gelen veri ayn�ysa hi� bir i�lem yap�lm�yor.*/
					{
						if(!strcmp(tmp.product_name, src))
						{
							if(tmp.unit + newunit < 0) /*Stok -1 e d��mesi engelleniyor.*/
								tmp.unit = 0;
							else
								tmp.unit += newunit;
						}
						fprintf(temp, "%u %s %u %lf\n", (tmp.primary_key), tmp.product_name, (tmp.unit), (tmp.price));
					}
					strcpy(tmpdata, tmp.product_name); /*Son veri iki kez okunur bunu engellemek amac�yla kullanmak i�in tmpdata ya son okunan�n verisini aty�yoruz.*/
				}
				fclose(temp);
				fclose(f);
				strcpy(tmpdata, " ");
				temp = fopen("temp.txt", "r");
				f = fopen("stok.txt", "w");
				while(!feof(temp))
				{
					fscanf(temp, "%u %s %u %lf", &(tmp.primary_key), tmp.product_name, &(tmp.unit), &(tmp.price));
					if(strcmp(tmp.product_name, tmpdata) != 0)
						fprintf(f, "%u %s %u %lf\n", (tmp.primary_key), tmp.product_name, (tmp.unit), (tmp.price));
					strcpy(tmpdata, tmp.product_name);
				}
				fclose(temp);
				fclose(f);
				remove("temp.txt");
				free(tmp.product_name);
				free(filedata);
				free(tmpdata);
				time(&nows);
				z = localtime(&nows);
				f = fopen("log.txt", "a+");
				fprintf(f, "[%d.%d.%d %d:%d:%d] - %s �r�n�ne %d kilo - adet eklendi.\n", z->tm_mday, z->tm_mon + 1, z->tm_year + 1900, z->tm_hour, z->tm_min, z->tm_sec, src, newunit);
				fclose(f);
				free(src);
				return 1;
			}
		}
		fclose(f);
		time(&nows);
		z = localtime(&nows);
		f = fopen("log.txt", "a+");
		fprintf(f, "[%d.%d.%d %d:%d:%d] - %s �r�n� bulunamad�.\n", z->tm_mday, z->tm_mon + 1, z->tm_year + 1900, z->tm_hour, z->tm_min, z->tm_sec, src);
		fclose(f);
		free(src);
		return 0;	
	}
	else
	{
		puts("Dosya a��lmad� !\n");
		time(&nows);
		z = localtime(&nows);
		f = fopen("log.txt", "a+");
		fprintf(f, "[%d.%d.%d %d:%d:%d] - stok.txt dosyas� a��lamad�.\n", z->tm_mday, z->tm_mon + 1, z->tm_year + 1900, z->tm_hour, z->tm_min, z->tm_sec);
		fclose(f);
		return 0;
	}
}

bool listandbuy(member *uye)
{
	FILE *f = fopen("stok.txt", "r");
	struct tm *z; time_t nows;
	if(f != NULL)
	{
		stock stok;
		unsigned short int wantunit;
		double total;
		char *tempdata = (char *)malloc(sizeof(char) * 50);
		char *want = (char *)malloc(sizeof(char) * 50);
		stok.product_name = (char *)malloc(sizeof(char) * 50);
		while(!feof(f))
		{
			fscanf(f, "%u %s %u %lf", &(stok.primary_key), (stok.product_name), &(stok.unit), &(stok.price));
			if(strcmp(stok.product_name, tempdata))
				printf("%u %s %u %lf\n", stok.primary_key, stok.product_name, stok.unit, stok.price);
			strcpy(tempdata, stok.product_name);
		}
		printf("Al�nacak �r�n: ");
		fflush(stdin);
		gets(want);
		want = (char *)realloc(want, sizeof(char) * (strlen(want) + 1));
		fseek(f, 0, SEEK_SET); /*Cursor dosya ba��na konumland�r�l�yor.*/
		while(!feof(f))
		{
			fscanf(f, "%u %s %u %lf", &(stok.primary_key), (stok.product_name), &(stok.unit), &(stok.price));
			if(!strcmp(want, stok.product_name))
			{
				printf("Miktar: ");
				scanf("%d", &wantunit);
				total =	(double)(wantunit * stok.price);
				if(total <= uye->fund && stok.unit >= wantunit)
				{
					FILE *temp = fopen("temp.txt", "w");
					FILE *temp2 = fopen("uyeler.txt", "r");
					member tempuser;
					tempuser.name = (char *)malloc(sizeof(char) * 50);
					tempuser.password = (char *)malloc(sizeof(char) * 50);
					tempuser.special_code = (char *)malloc(sizeof(char) * 50);
					uye->fund -= total;
					while(!feof(temp2))
					{
						fscanf(temp2, "%u %d %s %s", &(tempuser.primary_key), &(tempuser.yetki), tempuser.name, tempuser.password);
						fscanf(temp2, "%s %lf", tempuser.special_code, &(tempuser.fund));
						if(strcmp(tempdata, tempuser.name))
						{
							if(!strcmp(uye->name, tempuser.name))
								tempuser.fund = uye->fund;
							fprintf(temp, "%u %d %s %s %s %lf\n", tempuser.primary_key, tempuser.yetki, tempuser.name, tempuser.password, tempuser.special_code, tempuser.fund);
						}
						strcpy(tempdata, tempuser.name);
						
					}
					fclose(temp);
					fclose(temp2);
					temp = fopen("temp.txt", "r");
					temp2 = fopen("uyeler.txt", "w");
					while(!feof(temp))
					{
						fscanf(temp, "%u %d %s %s", &(tempuser.primary_key), &(tempuser.yetki), tempuser.name, tempuser.password);
						fscanf(temp, "%s %lf", tempuser.special_code, &(tempuser.fund));
						if(strcmp(tempdata, tempuser.name))
							fprintf(temp2, "%u %d %s %s %s %lf\n", tempuser.primary_key, tempuser.yetki, tempuser.name, tempuser.password, tempuser.special_code, tempuser.fund);
						strcpy(tempdata, tempuser.name);
					}
					fclose(temp);
					fclose(temp2);
					free(tempuser.name);
					free(tempuser.password);
					free(tempuser.special_code);
					fseek(f, 0, SEEK_SET);
					temp = fopen("temp.txt", "w");
					while(!feof(f))
					{
						fscanf(f, "%u %s %u %lf", &(stok.primary_key), (stok.product_name), &(stok.unit), &(stok.price));
						if(strcmp(stok.product_name, tempdata))
							fprintf(temp, "%u %s %u %lf\n", stok.primary_key, stok.product_name, stok.unit, stok.price);
						strcpy(tempdata, stok.product_name);
					}
					fclose(f);
					fclose(temp);
					f = fopen("stok.txt", "w");
					temp = fopen("temp.txt", "r");
					while(!feof(temp))
					{
						fscanf(temp, "%u %s %u %lf", &(stok.primary_key), (stok.product_name), &(stok.unit), &(stok.price));
						if(strcmp(stok.product_name, tempdata))
						{
							if(!strcmp(stok.product_name, want))
								stok.unit -= wantunit;
							fprintf(f, "%u %s %u %lf\n", stok.primary_key, stok.product_name, stok.unit, stok.price);
						}
						strcpy(tempdata, stok.product_name);
					}
					fclose(f);
					fclose(temp);
					time(&nows);
					z = localtime(&nows);
					f = fopen("log.txt", "a+");
					fprintf(f, "[%d.%d.%d %d:%d:%d] - %s �r�n� %u adet %lf TL'ye sat�n al�nd�.\n", z->tm_mday, z->tm_mon + 1,
					z->tm_year + 1900, z->tm_hour, z->tm_min, z->tm_sec, want, wantunit, total);
					fclose(f);
					free(want);
					free(tempdata);
					free(stok.product_name);
					remove("temp.txt");
					return 1;
				}
				else if(wantunit > stok.unit)
				{
					puts("Stok yetersiz !\n");
					fclose(f);
					time(&nows);
					z = localtime(&nows);
					f = fopen("log.txt", "a+");
					fprintf(f, "[%d.%d.%d %d:%d:%d] - %s �r�n� %u stok yetersiz oldu�undan %lf * %u sat�n al�m� ba�ar�s�z.\n", z->tm_mday, z->tm_mon + 1,
					z->tm_year + 1900, z->tm_hour, z->tm_min, z->tm_sec, want, stok.unit,  stok.price, wantunit);
					fclose(f);
					free(want);
					free(tempdata);
					free(stok.product_name);
					return 0;
				}
				else
				{
					puts("Bakiye yetersiz !\n");
					fclose(f);
					time(&nows);
					z = localtime(&nows);
					f = fopen("log.txt", "a+");
					fprintf(f, "[%d.%d.%d %d:%d:%d] - %s �ye bakiyesi %lf yetersiz oldu�undan %s �r�n� %lf * %u sat�n al�m� ba�ar�s�z.\n", z->tm_mday, z->tm_mon + 1,
					z->tm_year + 1900, z->tm_hour, z->tm_min, z->tm_sec, uye->name, uye->fund, want, stok.price, wantunit);
					fclose(f);
					free(tempdata);
					free(want);
					free(stok.product_name);
					return 0;
				}
			}
		}
		fclose(f);
		time(&nows);
		z = localtime(&nows);
		f = fopen("log.txt", "a+");
		fprintf(f, "[%d.%d.%d %d:%d:%d] - %s �r�n� bulunamad�.\n", z->tm_mday, z->tm_mon + 1,
		z->tm_year + 1900, z->tm_hour, z->tm_min, z->tm_sec, want);
		fclose(f);
		free(want);
		free(tempdata);
		free(stok.product_name);
		return 0;
	}
	else
	{
		puts("Dosya a��lmad� !\n");
		time(&nows);
		z = localtime(&nows);
		f = fopen("log.txt", "a+");
		fprintf(f, "[%d.%d.%d %d:%d:%d] - stok.txt dosyas� a��lamad�.\n", z->tm_mday, z->tm_mon + 1, z->tm_year + 1900, z->tm_hour, z->tm_min, z->tm_sec);
		fclose(f);
	}
}

bool insertfund(member *uye)
{
	int cardno[4]; int a; int b; double addmoney;
	struct tm *z; time_t nows; FILE *f;
	printf("Kredi kart numaras�: ");
	scanf("%d %d %d %d", &cardno[0], &cardno[1], &cardno[2], &cardno[3]);
	a = ((cardno[0]) - (cardno[0] % 1000)) / 1000;
	b = ((cardno[0] % 1000) - (cardno[0] % 100)) / 100;
	if((cardno[3] % 10) == ((a + b) % 10) && (cardno[3] % 10) % 2 == 0)
	{
		printf("Eklenecek bakiye: ");
		scanf("%lf", &addmoney);
		time(&nows);
		z = localtime(&nows);
		f = fopen("log.txt", "a+");
		fprintf(f, "[%d.%d.%d %d:%d:%d] - %d %d %d %d - Kart numaras� do�ru girildi.\n", z->tm_mday, z->tm_mon + 1,
		z->tm_year + 1900, z->tm_hour, z->tm_min, z->tm_sec, cardno[0], cardno[1], cardno[2], cardno[3]);
		fclose(f);
		FILE *temp = fopen("temp.txt", "w");
		f = fopen("uyeler.txt", "r");
		char *tempdata = (char *)malloc(sizeof(char) * 50);
		member tempuser;
		tempuser.name = (char *)malloc(sizeof(char) * 50);
		tempuser.password = (char *)malloc(sizeof(char) * 50);
		tempuser.special_code = (char *)malloc(sizeof(char) * 50);
		while(!feof(f))
		{
			fscanf(f, "%u %d %s %s", &(tempuser.primary_key), &(tempuser.yetki), tempuser.name, tempuser.password);
			fscanf(f, "%s %lf", tempuser.special_code, &(tempuser.fund));
			if(strcmp(tempdata, tempuser.name))
			{
				if(!strcmp(uye->name, tempuser.name))
				{
					uye->fund += addmoney;
					tempuser.fund = uye->fund;
				}
				fprintf(temp, "%u %d %s %s %s %lf\n", tempuser.primary_key, tempuser.yetki, tempuser.name, tempuser.password, tempuser.special_code, tempuser.fund);
			}
			strcpy(tempdata, tempuser.name);					
		}
		fclose(temp);
		fclose(f);
		temp = fopen("temp.txt", "r");
		f = fopen("uyeler.txt", "w");
		while(!feof(temp))
		{
			fscanf(temp, "%u %d %s %s", &(tempuser.primary_key), &(tempuser.yetki), tempuser.name, tempuser.password);
			fscanf(temp, "%s %lf", tempuser.special_code, &(tempuser.fund));
			if(strcmp(tempdata, tempuser.name))
				fprintf(f, "%u %d %s %s %s %lf\n", tempuser.primary_key, tempuser.yetki, tempuser.name, tempuser.password, tempuser.special_code, tempuser.fund);
			strcpy(tempdata, tempuser.name);
		}
		fclose(temp);
		fclose(f);
		time(&nows);
		z = localtime(&nows);
		f = fopen("log.txt", "a+");
		fprintf(f, "[%d.%d.%d %d:%d:%d] - %s kullan�c�s�na %lf bakiye y�klendi.\n", z->tm_mday, z->tm_mon + 1,
		z->tm_year + 1900, z->tm_hour, z->tm_min, z->tm_sec, uye->name, addmoney);
		fclose(f);
		remove("temp.txt");
		free(tempuser.name);
		free(tempuser.password);
		free(tempuser.special_code);
		free(tempdata);
	}
	else
	{
		time(&nows);
		z = localtime(&nows);
		f = fopen("log.txt", "a+");
		fprintf(f, "[%d.%d.%d %d:%d:%d] - Kart numaras� do�ru olmad��� i�in bakiye y�klenmedi.\n", z->tm_mday, z->tm_mon + 1,
		z->tm_year + 1900, z->tm_hour, z->tm_min, z->tm_sec);
		fclose(f);
		return 0;
	}
}

/*Login ��lemleri*/
void adminLogin()
{
	unsigned short int selection;
	do
	{
		printf("Y�netici Ekle[1]\n�r�n Ekle[2]\nStok Ekle[3]\nGeri[4]\nSe�im: ");
		selection = getch() - '0';
		switch(selection)
		{
			case 1:
				puts("Y�netici Ekle");
				if(insertAdmin())
					puts("Admin Ba�ar� �le Eklendi !\n");
				else
					puts("Admin Ekleme ��lemi Ba�ar�s�z !\n");
				break;
			case 2:
				puts("�r�n Ekle");
				if(insertProduct())
					puts("�r�n Ba�ar� �le Eklendi !\n");
				else
					puts("�r�n Ekleme ��lemi Ba�ar�s�z !\n");
				break;
			case 3:
				puts("Stok Ekle");
				if(insertUnit())
					puts("Stok Ba�ar� �le Eklendi !\n");
				else
					puts("Stok Ekleme ��lemi Ba�ar�s�z !\n");
				break;
			case 4:
				puts("Geri\n");
				break;
			default:
				puts("Yanl�� se�im !\n");
				break;
		}
	}while(selection != 4);
}

/*Login ��lemleri*/
void normalLogin(member *uye)
{
	unsigned short int selection;
	do
	{
		printf("Al��veri� Yap[1]\nBakiye G�ster[2]\nGeri[3]\nSe�im: ");
		selection = getch() - '0';
		switch(selection)
		{
			case 1:
				puts("Al��veri� Yap");
				if(listandbuy(uye))
					puts("Sat�n al�m ba�ar�l� !\n");
				else
					puts("Sat�n al�m ba�ar�s�z !\n");
				break;
			case 2:
				puts("Bakiye G�ster");
				printf("Mevcut bakiye: %lf\n", uye->fund);
				do
				{
					printf("Bakiye Y�kle[1]\nGeri[2]\nSe�im: ");
					selection = getch() - '0';
					switch(selection)
					{
						case 1:
							puts("Bakiye Y�kle");
							if(insertfund(uye))
								puts("Bakiye y�kleme i�lemi ba�ar�l� !\n");
							else
								puts("Bakiye y�kleme i�lemi ba�ar�s�z !\n");
							break;
						case 2:
							puts("Geri");
							break;
						default:
							puts("Yanl�� se�im !\n");
							break;
					}
				}while(selection != 2);
				break;
			case 3:
				puts("Geri");
				break;
			default:
				puts("Se�im yanl�� !\n");
				break;
		}
	}while(selection != 3);
}

/*�ye Olma*/
bool signup(member *uye)
{
	FILE *f = fopen("uyeler.txt", "a+"); struct tm *z; time_t nows;
	if(f != NULL)
	{
		member yeni;
		yeni.name = (char *)malloc(sizeof(char) * 50);
		yeni.password = (char *)malloc(sizeof(char) * 50);
		yeni.special_code = (char *)malloc(sizeof(char) * 50);
		printf("Kullan�c� ad�: ");
		fflush(stdin);
		gets(uye->name);
		uye->name = (char *)realloc(uye->name, (strlen(uye->name) + 1));
		fclose(f);
		f = fopen("uyeler.txt", "r");
		while(!feof(f))
		{
			fscanf(f, "%u %d %s %s", &(yeni.primary_key), &(yeni.yetki), yeni.name, yeni.password);
			fscanf(f, "%s %lf", yeni.special_code, &(yeni.fund));
			if(!strcmp(yeni.name, uye->name))
			{
				puts("Kullan�c� ad� kullan�l�yor !\n");
				fclose(f);
				time(&nows);
				z = localtime(&nows);
				f = fopen("log.txt", "a+");
				fprintf(f, "[%d.%d.%d %d:%d:%d] - %s kullan�c� ad� zaten kullan�l�yor.\n", z->tm_mday, z->tm_mon + 1, z->tm_year + 1900, z->tm_hour, z->tm_min, z->tm_sec, uye->name);
				fclose(f);
				free(yeni.name);
				free(yeni.password);
				free(yeni.special_code);
				return 0;
			}
		}
		free(yeni.name);
		free(yeni.password);
		free(yeni.special_code);
		fclose(f);
		f = fopen("uyeler.txt", "a+");
		printf("�ifre: ");
		fflush(stdin);
		gets(uye->password);
		printf("�zel kod: ");
		gets(uye->special_code);
		uye->fund = 0;
		uye->yetki = normal;
		uye->primary_key = n;
		setkey();
		fprintf(f, "%u %d %s %s %s %lf\n", uye->primary_key, uye->yetki, uye->name, uye->password, uye->special_code, uye->fund);
		fclose(f);
		time(&nows);
		z = localtime(&nows);
		f = fopen("log.txt", "a+");
		fprintf(f, "[%d.%d.%d %d:%d:%d] - %s kullan�c� ad� ile �ye olundu.\n", z->tm_mday, z->tm_mon + 1, z->tm_year + 1900, z->tm_hour, z->tm_min, z->tm_sec, uye->name);
		fclose(f);
		return 1;
	}
	else
	{
		time(&nows);
		z = localtime(&nows);
		f = fopen("log.txt", "a+");
		fprintf(f, "[%d.%d.%d %d:%d:%d] - Dosya a��lmad�.\n", z->tm_mday, z->tm_mon + 1,
		z->tm_year + 1900, z->tm_hour, z->tm_min, z->tm_sec);
		fclose(f);
		return 0;
	}
}

bool changepassword(member *uye)
{
	struct tm *z; time_t nows; FILE *f;
	char *src = (char *)malloc(sizeof(char) * 50);
	printf("Kullan�c� Ad�: ");
	fflush(stdin);
	gets(src);
	src = (char *)realloc(src, sizeof(char) * (strlen(src) + 1));
	time(&nows);
	z = localtime(&nows);
	f = fopen("log.txt", "a+");
	fprintf(f, "[%d.%d.%d %d:%d:%d] - %s kullan�c� ad� i�in �ifre s�f�rlama talebi al�nd�.\n", z->tm_mday, z->tm_mon + 1, z->tm_year + 1900, z->tm_hour, z->tm_min, z->tm_sec, src);
	fclose(f);
	f = fopen("uyeler.txt", "r");
	if(f != NULL)
	{
		while(!feof(f))
		{
			fscanf(f, "%u %d %s %s", &(uye->primary_key), &(uye->yetki), uye->name, uye->password);
			fscanf(f, "%s %lf", uye->special_code, &(uye->fund));
			if(!strcmp(src, uye->name))
			{
				char *inpsc = (char *)malloc(sizeof(char) * 50);
				printf("�zel Kod: ");
				fflush(stdin);
				gets(inpsc);
				inpsc = (char *)realloc(inpsc, sizeof(char) * (strlen(inpsc) + 1));
				if(!strcmp(inpsc, uye->special_code))
				{
					char *tempdata = (char *)malloc(sizeof(char) * 50);
					char *newpassword = (char *)malloc(sizeof(char) * 50);
					member yeni;
					yeni.name = (char *)malloc(sizeof(char) * 50);
					yeni.password = (char *)malloc(sizeof(char) * 50);
					yeni.special_code = (char *)malloc(sizeof(char) * 50);
					fseek(f, 0, SEEK_SET);
					FILE *temp = fopen("temp.txt", "w");
					while(!feof(f))
					{
						fscanf(f, "%u %d %s %s", &(yeni.primary_key), &(yeni.yetki), yeni.name, yeni.password);
						fscanf(f, "%s %lf", yeni.special_code, &(yeni.fund));
						if(strcmp(tempdata, yeni.name))
						{
							if(!strcmp(yeni.name, uye->name))
							{
								printf("Yeni �ifre: ");
								fflush(stdin);
								gets(newpassword);
								strcpy(yeni.password, newpassword);
							}
							fprintf(temp, "%u %d %s %s %s %lf\n", yeni.primary_key, yeni.yetki, yeni.name, yeni.password, yeni.special_code, yeni.fund);
						}
						strcpy(tempdata, yeni.name);
					}
					fclose(f);
					fclose(temp);
					f = fopen("uyeler.txt", "w");
					temp = fopen("temp.txt", "r");
					while(!feof(temp))
					{
						fscanf(temp, "%u %d %s %s", &(yeni.primary_key), &(yeni.yetki), yeni.name, yeni.password);
						fscanf(temp, "%s %lf", yeni.special_code, &(yeni.fund));
						if(strcmp(tempdata, yeni.name))
							fprintf(f, "%u %d %s %s %s %lf\n", yeni.primary_key, yeni.yetki, yeni.name, yeni.password, yeni.special_code, yeni.fund);
						strcpy(tempdata, yeni.name);
					}
					fclose(f);
					fclose(temp);
					remove("temp.txt");
					time(&nows);
					z = localtime(&nows);
					f = fopen("log.txt", "a+");
					fprintf(f, "[%d.%d.%d %d:%d:%d] - %s kullan�c� ad� i�in �ifre %s olarak de�i�tirildi.\n", z->tm_mday, z->tm_mon + 1, z->tm_year + 1900, z->tm_hour, z->tm_min,
					z->tm_sec, src, newpassword);
					strcpy(uye->password, newpassword);
					fclose(f);
					free(tempdata);
					free(src);
					free(inpsc);
					free(yeni.name);
					free(yeni.password);
					free(yeni.special_code);
					free(newpassword);
					return 1;
				}
				else
				{
					puts("�zel kod yanl�� !\n");
					time(&nows);
					z = localtime(&nows);
					f = fopen("log.txt", "a+");
					fprintf(f, "[%d.%d.%d %d:%d:%d] - %s kullan�c� ad� i�in %s �zel kod do�ru de�il kay�tl� de�il.\n", z->tm_mday, z->tm_mon + 1, z->tm_year + 1900, z->tm_hour,
					z->tm_min, z->tm_sec, src, inpsc);
					fclose(f);
					free(src);
					free(inpsc);
					return 0;
				}
			}
		}
		puts("Kullan�c� ad� kay�tl� de�il !\n");
		time(&nows);
		z = localtime(&nows);
		f = fopen("log.txt", "a+");
		fprintf(f, "[%d.%d.%d %d:%d:%d] - %s kullan�c� ad� kay�tl� de�il.\n", z->tm_mday, z->tm_mon + 1, z->tm_year + 1900, z->tm_hour, z->tm_min, z->tm_sec, src);
		fclose(f);
		free(src);
		return 0;
	}
	else
	{
		puts("Dosya a��lmad� !");
		time(&nows);
		z = localtime(&nows);
		f = fopen("log.txt", "a+");
		fprintf(f, "[%d.%d.%d %d:%d:%d] - %s Dosya a��lmad�.\n", z->tm_mday, z->tm_mon + 1, z->tm_year + 1900, z->tm_hour, z->tm_min, z->tm_sec, src);
		free(src);
		fclose(f);
		return 0;
	}
}

void main()
{
	setlocale(LC_ALL, "Turkish");
	unsigned short int selection;
	struct tm *z; time_t nows;
	FILE *f = fopen("key.txt", "r");
	fscanf(f, "%d", &n);
	fclose(f);
	f = fopen("urun_id.txt", "r");
	fscanf(f, "%d", &urun_id);
	fclose(f);
	member *uye = (member *)malloc(sizeof(member));
	uye->name = (char *)malloc(sizeof(char) * 50);
	uye->password = (char *)malloc(sizeof(char) * 50);
	uye->special_code = (char *)malloc(sizeof(char) * 50);
	do
	{
		printf("�ye Giri�i[1]\n�ye Ol[2]\nParolam� Unuttum[3]\n��k��[4]\nSe�im: ");
		selection = getch() - '0'; /*getch - getchar*/
		switch(selection)
		{
			case 1:
				puts("�ye Giri�i");
				if(login(uye))
				{
					puts("Giri� ba�ar�l� !\n");
					if(uye->yetki == admin)
					{
						puts("\tADM�N");
						optimization(uye);
						time(&nows);
						z = localtime(&nows);
						f = fopen("log.txt", "a+");
						fprintf(f, "[%d.%d.%d %d:%d:%d] - %s Admin kullan�c� giri� yapt�.\n", z->tm_mday, z->tm_mon + 1, z->tm_year + 1900, z->tm_hour, z->tm_min, z->tm_sec, uye->name);
						fclose(f);
						adminLogin();
						system("CLS");
						time(&nows);
						z = localtime(&nows);
						f = fopen("log.txt", "a+");
						fprintf(f, "[%d.%d.%d %d:%d:%d] - %s Admin kullan�c� ��k�� yapt�.\n",  z->tm_mday, z->tm_mon + 1, z->tm_year + 1900, z->tm_hour, z->tm_min, z->tm_sec, uye->name);
						fclose(f);
						uye->name = (char *)realloc(uye->name, sizeof(char) * 50);
						uye->password = (char *)realloc(uye->password, sizeof(char) * 50);
						uye->special_code = (char *)realloc(uye->special_code, sizeof(char) * 50);
						uye = (member *)realloc(uye, sizeof(member));
					}
					else
					{
						puts("\t�YE");
						optimization(uye);
						time(&nows);
						z = localtime(&nows);
						f = fopen("log.txt", "a+");
						fprintf(f, "[%d.%d.%d %d:%d:%d] - %s Normal kullan�c� giri� yapt�.\n", z->tm_mday, z->tm_mon + 1, z->tm_year + 1900, z->tm_hour, z->tm_min, z->tm_sec, uye->name);
						fclose(f);
						normalLogin(uye);
						system("CLS");
						time(&nows);
						z = localtime(&nows);
						f = fopen("log.txt", "a+");
						fprintf(f, "[%d.%d.%d %d:%d:%d] - %s Normal kullan�c� ��k�� yapt�.\n", z->tm_mday, z->tm_mon + 1, z->tm_year + 1900, z->tm_hour, z->tm_min, z->tm_sec, uye->name);
						fclose(f);
						uye->name = (char *)realloc(uye->name, sizeof(char) * 50);
						uye->password = (char *)realloc(uye->password, sizeof(char) * 50);
						uye->special_code = (char *)realloc(uye->special_code, sizeof(char) * 50);
						uye = (member *)realloc(uye, sizeof(member));
					}
				}
				else
				{
					uye->name = (char *)realloc(uye->name, sizeof(char) * 50);
					uye->password = (char *)realloc(uye->password, sizeof(char) * 50);
					uye->special_code = (char *)realloc(uye->special_code, sizeof(char) * 50);
					uye = (member *)realloc(uye, sizeof(member));
					time(&nows);
					z = localtime(&nows);
					f = fopen("log.txt", "a+");
					fprintf(f, "[%d.%d.%d %d:%d:%d] - �ye giri�i yap�lmad�.\n", z->tm_mday, z->tm_mon + 1, z->tm_year + 1900, z->tm_hour, z->tm_min, z->tm_sec);
					fclose(f);
					puts("Giri� yap�lmad� !\n");
				}
				break;
			case 2:
				puts("�ye Ol");
				if(signup(uye))
					puts("�ye olundu !\n");
				else
					puts("�ye olma i�lemi ba�ar�s�z !\n");
				uye->name = (char *)realloc(uye->name, sizeof(char) * 50);
				uye->password = (char *)realloc(uye->password, sizeof(char) * 50);
				uye->special_code = (char *)realloc(uye->special_code, sizeof(char) * 50);
				uye = (member *)realloc(uye, sizeof(member));
				break;
			case 3:
				puts("Parolam� Unuttum");
				if(changepassword(uye))
				{
					puts("�ifre s�f�rland� !\n");
					time(&nows);
					z = localtime(&nows);
					f = fopen("log.txt", "a+");
					fprintf(f, "[%d.%d.%d %d:%d:%d] - �ifre s�f�rland�.\n", z->tm_mday, z->tm_mon + 1, z->tm_year + 1900, z->tm_hour, z->tm_min, z->tm_sec);
					fclose(f);
				}
				else
				{
					puts("�ifre S�f�rlanmad� !\n");
					time(&nows);
					z = localtime(&nows);
					f = fopen("log.txt", "a+");
					fprintf(f, "[%d.%d.%d %d:%d:%d] - �ifre s�f�rlanmad�.\n", z->tm_mday, z->tm_mon + 1, z->tm_year + 1900, z->tm_hour, z->tm_min, z->tm_sec);
					fclose(f);
				}
				uye->name = (char *)realloc(uye->name, sizeof(char) * 50);
				uye->password = (char *)realloc(uye->password, sizeof(char) * 50);
				uye->special_code = (char *)realloc(uye->special_code, sizeof(char) * 50);
				uye = (member *)realloc(uye, sizeof(member));
					
				break;
			case 4:
				puts("��k��");
				free(uye->name);
				free(uye->password);
				free(uye->special_code);
				free(uye);
				break;
			default:
				puts("Se�im yanl�� !\n");
				break;
		}
	}while(selection != 4);
}

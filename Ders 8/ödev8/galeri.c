#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

typedef enum
{
	red = 0,
	black = 1,
	blue = 2,
	yellow = 3,
	silver = 4,
	white = 5
}color;

typedef enum
{
	audi = 0,
	bmw = 1,
	mercedes = 2,
	tofas = 3,
	ford = 4,
}mark;

typedef struct araba
{
	char *seri_no;
	color renk;
	int model;
	mark marka;
	double fiyat;
	struct araba *next;
}car;


car *ekle(car *araba)
{
	static car *iter = NULL; 
	if(araba == NULL)
	{
		araba = (car *)malloc(sizeof(car));
		araba->next = NULL; 
		iter = araba;
	}
	else
	{
		iter->next = (car *)malloc(sizeof(car));
		iter = iter->next;
		iter->next = NULL;
	}
	iter->seri_no = (char *)malloc(sizeof(char) * 50);	
	printf("Seri No Giriniz: ");
	scanf("%s", iter->seri_no);
	iter->seri_no = (char *)realloc(iter->seri_no,sizeof(char) * strlen(iter->seri_no));
	printf("Renk Se�imi\nK�r�m�z�[0]\nSiyah[1]\nMavi[2]\nSar�[3]\nG�m��[4]\nBeyaz[5]\nAraba rengini giriniz: ");
	scanf("%d", &iter->renk);
	printf("Model Giriniz: ");
	scanf("%d", &iter->model);
	printf("Marka Se�enekleri\nAudi[0]\nBmw[1]\nMercedes[2]\nTofas[3]\nFord[4]\nSe�iminiz: ");
	scanf("%d", &iter->marka);
	printf("Fiyat Giriniz: ");
	scanf("%lf", &iter->fiyat);
	puts("Ekleme i�lemi ba�ar�l�\n");
	return araba;
}

car *sil(car *araba)
{
	car *iter = araba;
	if(araba == NULL)
		puts("Araba Yok!");
	else
	{
		char *istenen = (char *)malloc(sizeof(char) * 20) ;
		printf("Silinecek araban�n seri no'su: ");
		scanf("%s", istenen);
		istenen = (char *)realloc(istenen,sizeof(char) * strlen(istenen));
		if(strcmp(araba->seri_no, istenen) != 0)
		{
			while(iter->next != NULL)
			{
				if(strcmp(iter->next->seri_no, istenen) == 0)
					break;
				iter = iter->next;			
			}
			if(iter->next != NULL && strcmp(iter->next->seri_no, istenen) == 0) 
			{
				car *temp = iter->next;
				iter->next = iter->next->next;
				free(temp);
				printf("Silme ��lemi Ba�ar�l�!\n\n");
			}
			else
			{
				if(strcmp(iter->seri_no, istenen) == 0) 
				{
					car *temp = araba;
					while(temp->next != iter)
						temp = temp->next;
					temp->next = NULL;
					free(iter);
				}
				else
					puts("Aranan Ara� Yok\n");
			}
		}	
		else
		{
			if(araba->next == NULL)
			{
				free(araba);
				araba = NULL;
			}
			else
			{
				car *temp = araba; 
				araba = araba->next;
				free(temp);	
			}
			printf("Silme ��lemi Ba�ar�l�!\n\n");
		}
		return araba;	
	}	
}

void listele(car *araba)
{
	car *iter = araba;
	int i = 1;
	if(araba == NULL)
		puts("Hi� Araba Yok!\n");
	else
	{	
		puts("");	
		while(iter->next != NULL)
		{
			printf("%d.Araba->->\n", i++);
			switch(iter->marka)
			{
				case 0:
					puts("Audi Marka");
					break;
				case 1:
					puts("Bmw Marka");
					break;
				case 2:
					puts("Mercedes Marka");
					break;
				case 3:
					puts("Tofas Marka");
					break;
				case 4:
					puts("Ford Marka");
					break;			
			}
			printf("%d->Model\n%lf->Fiyat\n%s->Seri No\n", iter->model, iter->fiyat, iter->seri_no);
			switch(iter->renk)
			{
				case 0:
					puts("k�rm�z�->Renk");
					break;
				case 1:
					puts("siyah->Renk");
					break;
				case 2:
					puts("mavi->Renk");
					break;
				case 3:
					puts("sar�->Renk");
					break;
				case 4:
					puts("g�m��->Renk");
					break;
				case 5:
					puts("beyaz->Renk");
					break;				
			}
			puts("");
			iter = iter->next;
		}
		printf("%d.Araba->->\n", i++);
		switch(iter->marka)
		{
			case 0:
				puts("Audi Marka");
				break;
			case 1:
				puts("Bmw Marka");
				break;
			case 2:
				puts("Mercedes Marka");
				break;
			case 3:
				puts("Tofas Marka");
				break;
			case 4:
				puts("Ford Marka");
				break;			
		}
		printf("%d->Model\n%lf->Fiyat\n%s->Seri No\n", iter->model, iter->fiyat, iter->seri_no);
		switch(iter->renk)
		{
			case 0:
				puts("k�rm�z�->Renk");
				break;
			case 1:
				puts("siyah->Renk");
				break;
			case 2:
				puts("mavi->Renk");
				break;
			case 3:
				puts("sar�->Renk");
				break;
			case 4:
				puts("g�m��->Renk");
				break;
			case 5:
				puts("beyaz->Renk");
				break;				
		}
		puts("");
	}
}

void main()
{
	setlocale(LC_ALL, "Turkish");
	int secim; 
	car *araba = NULL;
	car *temp;
	do
	{
		printf("Araba Ekle[1]\nAraba Sil[2]\nArabalar� Listele[3]\n��k��[4]\nSe�iminiz: ");
		scanf("%d", &secim);
		switch(secim)
		{
			case 1:
				araba = ekle(araba);
				break;
			case 2:
				araba = sil(araba);
				break;
			case 3:
				listele(araba);
				break;
			case 4:
				if(araba != NULL)
				{
					while(araba->next != NULL)
					{
						temp = araba;
						araba = araba->next;
						free(temp);
					}
					free(araba);
				}
				break;	
			default:
				printf("Yanl�� Se�im");
				break;		
		}
	}while(secim != 4);
}



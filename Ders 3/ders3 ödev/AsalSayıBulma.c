#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int *i;

void asalbulma(int x)
{
	int j, k;
	for( *i = 3; *i < x; (*i)++)
	{
		for( j = 2; j < *i; j++)
		{
			k=1;
			if( *i % j == 0)
			{
				k=0;
				break; //istenilmeyen sonu� ��kt�, say� bir say�ya b�l�nd� bu y�zden d�ng�den ��k�yoruz !!
			}
		}
		if( k == 1)
		{
			printf("%d \n" , *i);
		}
	}
}


void main()
{
	i = (int*)malloc(sizeof(int));
	int sinir = 0;
	setlocale(LC_ALL, "Turkish");
	printf("Ka�a kadar olan asal say�lar� bulmak istiyorsunuz ?");
	scanf("%d",&sinir);
	asalbulma(sinir);
}

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
				break; //istenilmeyen sonuç çýktý, sayý bir sayýya bölündü bu yüzden döngüden çýkýyoruz !!
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
	printf("Kaça kadar olan asal sayýlarý bulmak istiyorsunuz ?");
	scanf("%d",&sinir);
	asalbulma(sinir);
}

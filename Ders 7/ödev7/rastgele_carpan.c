#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>

void main()
{
	setlocale(LC_ALL, "Turkish");
	int dizi[6] = {3,8,4,3,9,7}; int rastgele; int rastgele_dizi[6] = {6,6,6,6,6,6}; int i = 0; int j = 0;
	srand(time(NULL));
	while(i != 6)
	{	
		rastgele = rand()%5;
		printf("%d\n", rastgele);
		for(j = 0; j < 6 ;j++)
		{
			if(rastgele == rastgele_dizi[j]);
			else if(rastgele_dizi[j] == 6) // Hatalý
			{
				rastgele_dizi[j] = rastgele;
				printf("%d.---%d", i, rastgele_dizi[i]);
				i++;
			}					
		}
	}
}

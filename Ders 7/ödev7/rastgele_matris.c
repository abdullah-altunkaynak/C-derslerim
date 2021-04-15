#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

typedef enum
{
	false, true
}bool;

void main()
{
	setlocale(LC_ALL, "Turkish");
	srand(time(NULL));
	int **ptr; int satir; int sutun; int i; int j; int *gecmis; int n = 1; int random; int k;
	bool isfound = false;
	printf("Matrisin satýr sayýsý: ");
	scanf("%d", &satir);
	ptr = (int **)malloc(sizeof(void *) * satir);
	printf("Matrisin sütun sayýsý: ");
	scanf("%d", &sutun);
	for(i = 0; i < satir; i++)
	{
		for(j = 0; j < sutun; j++)
			*(ptr + i) = (int *)malloc(sizeof(int) * sutun);
	}
	gecmis = (int *)malloc(sizeof(int));
	*gecmis = -1;
	for(i = 0; i < satir; i++)
	{
		for(j = 0; j < sutun; j++)
		{
			random = rand() % 10;
			for(k = 0; k < n; k++)
			{
				if(random == *(gecmis + k))
				{
					j--;
					isfound = true;
					break;	
				}	
			}
			if(isfound)
				isfound = false;
			else
			{
				n++;
				gecmis = (int *)realloc(gecmis, sizeof(int) * n);
				*(gecmis + (n - 1)) = random;
				*(*(ptr + i) + j) = random;	
			}		
		}	
	}
	for(i = 0; i < satir; i++)
	{
		for(j = 0; j < sutun; j++)
			printf("ptr[%d][%d]: %d\n", i, j, ptr[i][j]);
	}
	for(i = 0; i < satir; i++)
		free(*(ptr + i));
	free(ptr);
	free(gecmis);
}

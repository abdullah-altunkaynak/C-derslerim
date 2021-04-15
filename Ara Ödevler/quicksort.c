#include <stdio.h>
#include <locale.h>

void quicksort(int number[25],int ilk,int son)
{
	int sol, sag, pivot, temp;
	if(ilk < son)
	{
		pivot = ilk;
		sol = ilk;
		sag = son;
		while(sol < sag)
		{
			while(number[sol] <= number[pivot]) // baz� durumlarda sol pivottan k���k oldugu halde ilerlememesi gerekir ��nk� zaten pivottan b�y�klerin bulundu�u sa� k�s�ma ge�mesini istemiyoruz bu y�zden sa��n bulundugu konumdan ileri ge�mesini engelliyoruz.
				sol++;
			while(number[sag] > number[pivot])
				sag--;
			if(sol < sag)
			{
				temp = number[sol];
				number[sol] = number[sag];
				number[sag] = temp;
			}
		}
		temp = number[pivot];
		number[pivot] = number[sag];
		number[sag] = temp;
		quicksort(number, ilk, sag-1);
		quicksort(number, sag+1, son);
	}
}

void main()
{
	int i, count, number[25];
	setlocale(LC_ALL, "Turkish");
	printf("Ka� Adet Say� Gireceksiniz: ");
	scanf("%d",&count);
	printf("%d Tane Say� Giriniz: ", count);
	for(i = 0; i < count ; i++)
		scanf("%d",&number[i]);
	quicksort(number, 0, count-1);
	printf("S�ralanm�� Hali: ");
	for(i = 0; i < count ; i++)
		printf(" %d",number[i]);
}

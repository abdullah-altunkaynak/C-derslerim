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
			while(number[sol] <= number[pivot]) // bazý durumlarda sol pivottan küçük oldugu halde ilerlememesi gerekir çünkü zaten pivottan büyüklerin bulunduðu sað kýsýma geçmesini istemiyoruz bu yüzden saðýn bulundugu konumdan ileri geçmesini engelliyoruz.
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
	printf("Kaç Adet Sayý Gireceksiniz: ");
	scanf("%d",&count);
	printf("%d Tane Sayý Giriniz: ", count);
	for(i = 0; i < count ; i++)
		scanf("%d",&number[i]);
	quicksort(number, 0, count-1);
	printf("Sýralanmýþ Hali: ");
	for(i = 0; i < count ; i++)
		printf(" %d",number[i]);
}

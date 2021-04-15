#include <stdio.h>
#include <locale.h>

// Hakan�n H sini yazd�ran recursive fonksiyon.

int recursive(int n)
{
	if(n > 0)
	{
		printf("   *           *\n");
		recursive(n-1);
	}
	
	else if(n == 0)
	{
		printf("   *************\n");
		recursive(n-1);
	}
	else if(n > -12)
	{
		printf("   *           *\n");
		recursive(n-1);	
	} 
	return 1;	
}


void main()
{
	setlocale(LC_ALL ,"Turkish");
	recursive(10);
}

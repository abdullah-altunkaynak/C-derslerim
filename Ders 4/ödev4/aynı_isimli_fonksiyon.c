#include <stdio.h>
#include <locale.h>

// Zann�mca ka� arg�man ald�g�na bakarak ayn� adda 2 fonksiyon tan�mlayaca��z.

//void fonksiyon(char)
//{
//	printf("%d",a);
//}

void fonksiyon(int a,int b)
{
	printf("%d",b);
}

void main()
{
	setlocale(LC_ALL, "Turkish");
	fonksiyon(5);
    //fonksiyon(5);
}

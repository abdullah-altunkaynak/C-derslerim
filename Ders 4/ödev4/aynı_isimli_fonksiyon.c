#include <stdio.h>
#include <locale.h>

// Zannýmca kaç argüman aldýgýna bakarak ayný adda 2 fonksiyon tanýmlayacaðýz.

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

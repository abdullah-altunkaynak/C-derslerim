#include <stdio.h>
#include <locale.h>


void matriscarpim(int satir, int sutun, int satir0, int sutun0)
{
	int dizi_1[satir][sutun]; int dizi_2[satir0][sutun0]; int carpim[satir][sutun];
	int i;	int	j; int k; int l; int x; int y;       int eleman = 0;
	printf("�lk matrise eleman ekleme yap�n�z l�tfen -->\n");
	for(i = 0; i < satir; i++)
	{
		for(j = 0; j < sutun; j++)
		{
			printf("%d.sat�r %d.s�tun eleman�n� giriniz: ", i, j);
			scanf("%d", &eleman);
			dizi_1[i][j] = eleman; 
		}
	}
	system("CLS");
	printf("�kinci matrise eleman ekleme yap�n�z l�tfen -->\n");	
	for(k = 0; k < satir0; k++)
	{
		for(l = 0; l < sutun0; l++)
		{
			printf("%d.sat�r %d.s�tun eleman�n� giriniz: ", k, l);
			scanf("%d", &eleman);
			dizi_2[k][l] = eleman;
		}
	}
	for(k = 0; k < satir; k++)
	{
		for(l = 0; l < sutun; l++)
			carpim[k][l] = 0;
	}
	
	for(i = 0; i < satir; i++)
    {
        for(j = 0; j < sutun0; j++)
        {
            for(k = 0; k < satir0; k++)
            {
                carpim[i][j] += dizi_1[i][k] * dizi_2[k][j];
            }
        }
    }
    for(x = 0; x < satir ; x++)
    {
    	for(y = 0; y < sutun ; y++)
    		printf("%d.sat�r %d.sutun = [%d]\n", x+1, y+1,carpim[x][y]);
	}
    	
}



void main()
{
	int satir; int sutun; int satir0; int sutun0;
	setlocale(LC_ALL, "Turkish");
	printf("�lk Matris sat�r ve s�tun say�s�n� giriniz[UNUTMAYINIZ �LK MATR�S'�N S�TUN SAYISIYLA �K�NC� MATR�S�N SATIR SAYISI E��T OLMALIDIR]: ");
	scanf("%d %d", &satir, &sutun);
	printf("�kinci Matris sat�r ve s�tun say�s�n� giriniz: ");
	scanf("%d %d", &satir0, &sutun0);
	if(sutun != satir0)
		printf("L�tfen Se�imini Uyar�y� Dikkate alarak ger�ekle�tir");
	else	
		matriscarpim(satir,sutun,satir0,sutun0);
}

#include <stdio.h>
#include <locale.h>


void matriscarpim(int satir, int sutun, int satir0, int sutun0)
{
	int dizi_1[satir][sutun]; int dizi_2[satir0][sutun0]; int carpim[satir][sutun];
	int i;	int	j; int k; int l; int x; int y;       int eleman = 0;
	printf("Ýlk matrise eleman ekleme yapýnýz lütfen -->\n");
	for(i = 0; i < satir; i++)
	{
		for(j = 0; j < sutun; j++)
		{
			printf("%d.satýr %d.sütun elemanýný giriniz: ", i, j);
			scanf("%d", &eleman);
			dizi_1[i][j] = eleman; 
		}
	}
	system("CLS");
	printf("Ýkinci matrise eleman ekleme yapýnýz lütfen -->\n");	
	for(k = 0; k < satir0; k++)
	{
		for(l = 0; l < sutun0; l++)
		{
			printf("%d.satýr %d.sütun elemanýný giriniz: ", k, l);
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
    		printf("%d.satýr %d.sutun = [%d]\n", x+1, y+1,carpim[x][y]);
	}
    	
}



void main()
{
	int satir; int sutun; int satir0; int sutun0;
	setlocale(LC_ALL, "Turkish");
	printf("Ýlk Matris satýr ve sütun sayýsýný giriniz[UNUTMAYINIZ ÝLK MATRÝS'ÝN SÜTUN SAYISIYLA ÝKÝNCÝ MATRÝSÝN SATIR SAYISI EÞÝT OLMALIDIR]: ");
	scanf("%d %d", &satir, &sutun);
	printf("Ýkinci Matris satýr ve sütun sayýsýný giriniz: ");
	scanf("%d %d", &satir0, &sutun0);
	if(sutun != satir0)
		printf("Lütfen Seçimini Uyarýyý Dikkate alarak gerçekleþtir");
	else	
		matriscarpim(satir,sutun,satir0,sutun0);
}

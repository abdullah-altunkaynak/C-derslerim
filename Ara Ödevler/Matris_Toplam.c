#include <stdio.h>
#include <locale.h>

void matristoplam(int satir, int sutun, int satir0, int sutun0)
{
	int dizi_1[satir][sutun]; int dizi_2[satir0][sutun0]; int dizi_toplam[10];
	int i; int j; int k; int l; int eleman = 0; int toplam = 0; int x;
	printf("�lk matrise eleman ekleme yap�n�z l�tfen -->\n");
	for(i = 0; i < satir; i++)
	{
		for(j = 0; j < sutun; j++)
		{
			printf("%d.sat�r %d.s�tun eleman�n� giriniz: ", i, j);
			scanf("%d", &eleman);
			dizi_1[i][j] = eleman;
			toplam += eleman; 
		}
		dizi_toplam[i] = toplam;
		toplam = 0;
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
			toplam += eleman;
		}
		dizi_toplam[k] += toplam;
		toplam = 0;
	}
	system("CLS");
	printf("Matrislerin Toplam� �u �ekildedir: \n");
	if(satir >= satir0)
	{
		for(x = 0; x < satir ; x++)
			printf("%d.sat�r�n toplamlar� = [%d]\n", x+1, dizi_toplam[x]);
	}
	else
	{
		for(x = 0; x < satir0 ; x++)
			printf("%d.sat�r�n toplamlar� = [%d]\n", x+1, dizi_toplam[x]);
	}
}


void main()
{
	int satir; int sutun; int satir0; int sutun0;
	setlocale(LC_ALL, "Turkish");
	printf("�lk Matris sat�r ve s�tun say�s�n� giriniz: ");
	scanf("%d %d", &satir, &sutun);
	printf("�kinci Matris sat�r ve s�tun say�s�n� giriniz: ");
	scanf("%d %d", &satir0, &sutun0);
	matristoplam(satir,sutun,satir0,sutun0);
}

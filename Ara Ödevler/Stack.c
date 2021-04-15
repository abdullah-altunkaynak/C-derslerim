#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <conio.h>


typedef struct n
{
        int data;
        struct n * next;        
}node;

node *iter = NULL;
node *temp = NULL;
void push(int data)
{
	printf("keke");
	if(iter == NULL)
	{
		printf("Stack boþ ilk eleman eklenecek..");
		iter = (node *)malloc(sizeof(node));
		iter->next = NULL;
	}
	iter->data = data;
	node *neww = (node *)malloc(sizeof(node));
	neww->next = iter;
	iter = neww;	
}
 
 void pop()
 {
 	if(iter->next == NULL)
 		printf("Stack Boþ");
 	else
	 {
	 	temp = iter;
	 	iter = iter->next;
	 	free(temp);
	 }	
 }

void print()
{
	if(iter == NULL)
		printf("Stack Boþ !");
	else
	{
		temp = iter->next;
		while(temp != NULL)
		{
			printf("%d",temp->data);
			temp = temp->next;
		}
	}	
} 

void main()
{
	int secim; int a;
	setlocale(LC_ALL, "Turkish");
    do
    {
    	printf("Ekle[1]\nÇýkar[2]\nListele[3]\nÇýkýþ[4]\nSeçiminiz: ");
    	scanf("%d",&secim);
    	switch(secim)
    	{
    		case 1:
    			printf("Eklenecek Eleman: ");
    			scanf("%d",&a);
    			push(a);
    			break;	
    		case 2:
    			pop();
    			printf("Çýkarma Ýþlemi Baþarýlý");
    			break;
    		case 3:
				print();
				break;
			default:
				printf("Yanlýþ Seçim Tekrar Deneyiniz");
				break;		
		}
	}while(secim != 4);
	printf("Teþekkürler...  <3");
}

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
		printf("Stack bo� ilk eleman eklenecek..");
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
 		printf("Stack Bo�");
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
		printf("Stack Bo� !");
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
    	printf("Ekle[1]\n��kar[2]\nListele[3]\n��k��[4]\nSe�iminiz: ");
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
    			printf("��karma ��lemi Ba�ar�l�");
    			break;
    		case 3:
				print();
				break;
			default:
				printf("Yanl�� Se�im Tekrar Deneyiniz");
				break;		
		}
	}while(secim != 4);
	printf("Te�ekk�rler...  <3");
}

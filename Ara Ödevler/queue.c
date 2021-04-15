#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>

typedef struct n
{
	int data;
	struct n *next;
}node;

node *finish = NULL;
node *start = NULL;

void push(int data)
{
	if(start == NULL)
	{
		printf("Kuyruk Boþ Ýlk Eleman Eklenecek\n");
		start = (node *)malloc(sizeof(node));
		finish = (node *)malloc(sizeof(node));
		start->data = data;
		finish = start;
		
	}
	else
	{
		finish->next = (node *)malloc(sizeof(node));
		node *temp = finish->next;
		temp->data = data;
		printf("keke");
		finish = temp;
	}
}

void pop()
{
	if(start == NULL)
		printf("Kuyruk Boþ..\n");
	else if(start->next == NULL)
	{
		free(start);
		finish = start = NULL;
	}
	else
	{
		node *temp = start;
		start = temp->next;
		free(temp);
	}
}

void print()
{
	if(start == NULL)
		printf("Kuyruk Boþ");
	else
	{
		node *temp = (node *)malloc(sizeof(node));
		temp = start;
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

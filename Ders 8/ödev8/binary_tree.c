#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <conio.h>
#include <locale.h>

typedef struct n
{
	struct n *left;
	int data;
	struct n *right;
}node;

node *Insert(node *root, node *iter, int inpdata)
{
	if(root == NULL)
	{
		printf("Kök girilmemiþ köke ekleniyor !\n");
		root = (node *)malloc(sizeof(node));
		root->data = inpdata;
		root->left = root->right = NULL;
		puts("Kök eklendi !\n");
		return root;
	}
	else
	{
		if(iter->data > inpdata)
		{
			if(iter->left != NULL)
				Insert(root, iter->left, inpdata);
			else
			{
				iter->left = (node *)malloc(sizeof(node));
				iter = iter->left;
				iter->data = inpdata;
				iter->left = iter->right = NULL;
			}
		}
		else
		{
			if(iter->right != NULL)
				Insert(root, iter->right, inpdata);
			else
			{
				iter->right = (node *)malloc(sizeof(node));
				iter = iter->right;
				iter->data = inpdata;
				iter->left = iter->right = NULL;
			}
		}
	}
	return root;
}

void Delete(node *root, node *iter, int ipndata)
{
	if(root->data == inpdata)
	{
		
	}
	else
	{
		if(root == NULL)
			puts("Aranan veri yok !");
		else
		{
			iter = root;
			if(inpdata < root->data)
				Delete(root->left, iter, inpdata);
			else
				Delete(root->right, iter, inpdata);
		}
	}
}

void show(node *root)
{
	if(root != NULL)
	{
		show(root->left);
		printf("Veri: %d\n", root->data);
		show(root->right);
	}
}

void clear(node *root)
{
	if(root != NULL)
	{
		clear(root->left);
		clear(root->right);
		free(root);
	}
}

void main()
{
	setlocale(LC_ALL, "Turkish");
	int selection; int inpdata;
	node *root = NULL;
	do
	{
		printf("Ekle[1]\nSil[2]\nListele[3]\nÇýkýþ[4]\nSeçiminiz: ");
		selection = getch() - '0';
		switch(selection)
		{
			case 1:
				printf("Ekle\nEklenecek veri: ");
				scanf("%d", &inpdata);
			 	root = Insert(root, root, inpdata);
				break;
			case 2:
				if(root != NULL)
				{
					printf("Silinecek veri: ");
					scanf("%d", &inpdata);
					Delete(root, root, inpdata);
				}
				else
					puts("Aðaçta veri yok !\n");
				break;
			case 3:
				puts("Listele");
				if(root == NULL)
					puts("Aðaç boþ !\n");
				else
					show(root);
				puts("");
				break;
			case 4:
				puts("Çýkýþ");
				clear(root);
				break;
			default:
				puts("Yanlýþ seçim !\n");
				break;
		}
	}while(selection != 4);
}

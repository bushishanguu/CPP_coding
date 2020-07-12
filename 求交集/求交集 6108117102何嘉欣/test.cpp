#define _CRT_SECURE_NO_WARNINGS 1
#include"stdio.h"
#include<malloc.h> 
#include<stdlib.h> 
typedef struct node
{ int data;
struct node *next;
}LNODE, *linkedlist;
linkedlist listinit()
{
	linkedlist L;
	L = (LNODE *)malloc(sizeof (LNODE));
	if (L == NULL) { printf("memory not enough"); exit(0); } L->next = NULL;
	return L;
}
linkedlist listbuild()
{
	int x;
	LNODE *L, *p;
	L = (LNODE*)malloc(sizeof(LNODE));
	L->next = NULL; 
	scanf("%d", &x);
	while (x != 0) {
		p = (LNODE*)malloc(sizeof(LNODE)); p->data = x;
		p->next = L->next;
		L->next = p;
		scanf("%d", &x);
	} return(L);
}
linkedlist listinv(linkedlist L)
{
	linkedlist p, r; p = L->next;
	L->next = NULL; while (p != NULL)
	{
		r = p->next;
		p->next = L->next;
		L->next = p; p = r;
	}
	return(L);
}
void main()
{
	linkedlist La, Lb, Lc, p, q, r;
	La = listinit(); Lb = listinit();
	Lc = listinit(); printf("	请输入	La 表的元素： \n");
	La = listbuild(); printf("La	表为： \n");
	p = La->next; while (p != NULL)
	{
		printf("%d\n", p->data); p = p->next;
	} La = listinv(La);
	p = La->next; while (p != NULL)
	{
		q = (LNODE*)malloc(sizeof(LNODE)); q->data = p->data;
		q->next = Lb->next;
		Lb->next = q;
		p = p->next;
		if (p != NULL)
		{
			r = (LNODE*)malloc(sizeof(LNODE)); r->data = p->data;
			r->next = Lc->next;
			Lc->next = r; p = p->next;
		}
	}
	printf("Lb	表为： \n");
	p = Lb->next; while (p != NULL)
	{
		printf("%d\n", p->data); p = p->next;
	}
	printf("Lc	表为： \n");
	p = Lc->next; while (p != NULL)
	{
		printf("%d\n", p->data); p = p->next;
	}
}
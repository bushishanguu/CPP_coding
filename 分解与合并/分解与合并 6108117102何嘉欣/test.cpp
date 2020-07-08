#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h> 
#include<malloc.h>
typedef int status;
typedef int ElemType;
#define TRUE 1
#define ERROR 0
#define FALSE 0
#define OK 1
#define OVERFLOW -2
#define list_init_size 100
#define listincrement 10
typedef struct{
	ElemType *elem;
	int length;
	int listsize;
}sqlist;
status equal(ElemType a, ElemType b)
{
	if (a == b)
		return TRUE;
	else
		return FALSE;
}
int listlength(sqlist l)
{
	return l.length;
}
status listinsert(sqlist *l, int i, ElemType e)
{
	ElemType *newbase, *q, *p;
	if (i<1 || i>(*l).length + 1)
		return ERROR;
	if ((*l).length >= (*l).listsize){
		newbase = (ElemType*)realloc((*l).elem, ((*l).listsize + listincrement)*sizeof(ElemType));
		if (!newbase)  exit(OVERFLOW);
		(*l).elem = newbase;
		(*l).listsize += listincrement;
	}
	q = &((*l).elem[i - 1]);
	for (p = &((*l).elem[(*l).length - 1]); p >= q; --p)
		*(p + 1) = *p;
	*q = e;
	++(*l).length;
	return OK;
}
status initlist(sqlist *l){
	(*l).elem = (ElemType*)malloc(list_init_size*sizeof(ElemType));
	if (!(*l).elem)
		exit(OVERFLOW);
	(*l).length = 0;
	(*l).listsize = list_init_size;
	return OK;
}
status getelem(sqlist l, int i, ElemType *e)
{
	if (i<1 || i>l.length)
		exit(ERROR);
	*e = *(l.elem + i - 1);
	return OK;
}
int LocateElem(sqlist L, ElemType e, status(*compare)(ElemType, ElemType))
{
	ElemType *p;
	int i = 1;
	p = L.elem;
	while (i <= L.length&&!compare(*p++, e))
		++i;
	if (i <= L.length)
		return i;
	else
		return 0;
}
void print(ElemType *c)
{
	printf("%d ", *c);
}
status ListTraverse(sqlist l, void(*vi)(ElemType *))
{
	ElemType *p;
	int i;
	p = l.elem;
	for (i = 1; i <= l.length; i++)
		vi(p++);
	printf("\n");
	return OK;
}
void Union(sqlist *la, sqlist lb)
{
	int la_len, lb_len;
	int i;
	ElemType e;
	la_len = listlength(*la);
	lb_len = listlength(lb);
	for (i = 1; i <= lb_len; i++)
	{
		getelem(lb, i, &e);
		if (!LocateElem(*la, e, equal))
			listinsert(la, ++la_len, e);
	}
}
void main()
{
	sqlist la, lb;
	int j, i;
	i = initlist(&la);
	if (i == 1)
	for (j = 1; j <= 6; j++)
		i = listinsert(&la, j, j);
	printf("la= ");
	ListTraverse(la, print);
	initlist(&lb);
	for (j = 1; j <= 5; j++)
		i = listinsert(&lb, j, 2 * j);
	printf("lb= :");
	ListTraverse(lb, print);
	Union(&la, lb);
	printf("la :");
	ListTraverse(la, print);
	system("pause");
}
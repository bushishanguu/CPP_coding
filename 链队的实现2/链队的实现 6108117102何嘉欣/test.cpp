#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<stdlib.h>
#include <malloc.h>

typedef int ElemType;
typedef int Status;
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef struct Node
{
	ElemType data;
	struct Node *next;
}Node;

typedef struct
{
	Node *front;
	Node *rear;
}LinkQueue;

Status InitQueue(LinkQueue *q)
{
	q->front = NULL;
	q->rear = NULL;
	return OK;
}//InitQueue

Status DestroyQueue(LinkQueue *q)
{
	Node *p = q->front;
	while (p)
	{
		q->front = p->next;
		free(p);
		p = q->front;
	}
	puts("���������٣�");
	return OK;
}

bool isEmpty(LinkQueue *q)
{
	if (q->front == NULL && q->rear == NULL)
		return TRUE;
	return FALSE;
}//isEmpty

Status Push(LinkQueue *q, ElemType e)
{
	Node *p = (Node*)malloc(sizeof(Node));
	if (!p)
	{
		puts("�洢�ռ����ʧ��!");
		return ERROR;
	}
	p->data = e;
	p->next = NULL;//��ֹ����Ұָ��
	if (isEmpty(q))//����ǿն��У���frontָ��p����һ��Ԫ�أ�
		q->front = p;
	else
		q->rear->next = p;
	q->rear = p;//q->rearָ���β
	return OK;
}//Push

Status Pop(LinkQueue *q, ElemType *e)
{
	Node *p = q->front;
	if (isEmpty(q))
	{
		puts("����Ϊ�գ�");
		return ERROR;
	}
	*e = p->data;
	q->front = p->next;
	free(p);
	if (q->front == NULL)//��������к���п��ˣ���q->rearӦָ��NULL��
		q->rear = NULL;
	return OK;
}//Pop

Status createQueue(LinkQueue *q)
{
	InitQueue(q);
	puts("������Ҫ����Ķ���Ԫ�ظ�����");
	int n;
	scanf("%d", &n);
	while (n--)
	{
		int m;
		scanf("%d", &m);
		Push(q, m);
	}
	return OK;
}//createQueue

Status PrintQueue(LinkQueue *q)
{
	Node *p = q->front;
	puts("������������Ԫ��:");
	while (p)
	{
		printf("%d   ", p->data);
		p = p->next;
	}
	puts("");
	return OK;
}

int main()
{
	LinkQueue q;
	int e;
	createQueue(&q);
	PrintQueue(&q);
	Pop(&q, &e);
	puts("�����е�Ԫ���ǣ�");
	printf("%d\n", e);
	PrintQueue(&q);
	Push(&q, 8);
	puts("8�����к�");
	PrintQueue(&q);
	DestroyQueue(&q);
	system("pause");
	return 0;
}

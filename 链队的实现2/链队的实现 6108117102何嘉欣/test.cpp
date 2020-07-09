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
	puts("队列已销毁！");
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
		puts("存储空间分配失败!");
		return ERROR;
	}
	p->data = e;
	p->next = NULL;//防止出现野指针
	if (isEmpty(q))//如果是空队列，则front指向p（第一个元素）
		q->front = p;
	else
		q->rear->next = p;
	q->rear = p;//q->rear指向队尾
	return OK;
}//Push

Status Pop(LinkQueue *q, ElemType *e)
{
	Node *p = q->front;
	if (isEmpty(q))
	{
		puts("队列为空！");
		return ERROR;
	}
	*e = p->data;
	q->front = p->next;
	free(p);
	if (q->front == NULL)//如果出队列后队列空了，则q->rear应指向NULL，
		q->rear = NULL;
	return OK;
}//Pop

Status createQueue(LinkQueue *q)
{
	InitQueue(q);
	puts("请输入要输入的队列元素个数：");
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
	puts("队列中有以下元素:");
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
	puts("出队列的元素是：");
	printf("%d\n", e);
	PrintQueue(&q);
	Push(&q, 8);
	puts("8进队列后：");
	PrintQueue(&q);
	DestroyQueue(&q);
	system("pause");
	return 0;
}

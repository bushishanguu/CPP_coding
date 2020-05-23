#define _CRT_SECURE_NO_WARNINGS 1
//二叉排序树 
#include<stdio.h>  
#include<stdlib.h>  

typedef struct BiTNode
{
	int key;
	struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

int SearchBST(BiTree T, int key, BiTree f, BiTree &p)//查找 
{
	
	if (!T)  { p = f; return 0; }
	else if (key == T->key) { p = T; return 1; }
	else if (key<T->key) SearchBST(T->lchild, key, T, p);
	else SearchBST(T->rchild, key, T, p);
}

int InsertBST(BiTree &T, int key)//插入 
{
	if (!T)
	{
		T = (BiTree)malloc(sizeof(BiTNode));
		T->key = key;
		T->lchild = (T)->rchild = NULL;
	}
	if (key == T->key) return 0;
	if (key>T->key) InsertBST(T->rchild, key);
	else InsertBST(T->lchild, key);
}

void InorderTraverse(BiTree T)//中序遍历
{
	if (T)
	{
		InorderTraverse(T->lchild);
		printf("%d ", T->key);
		InorderTraverse(T->rchild);
	}
}

int main()
{
	int e, n;

	BiTree T = NULL, f=NULL, p=NULL;
	printf("输入长度：");
	scanf("%d", &n);
	printf("输入元素：");
	while (n--)
	{
		scanf("%d", &e);
		InsertBST(T, e);
	}
	printf("中序遍历：");
	InorderTraverse(T);
	printf("\n");
	while (1)
	{
		printf("输入要查找元素：");
		scanf("%d", &e);
		if (SearchBST(T, e,f, p)) printf("找到了\n");
		else printf("没找到\n");
	}
}
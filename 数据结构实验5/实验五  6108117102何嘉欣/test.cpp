#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef char TElemType;
typedef struct SBiTNode
{
	TElemType data;
	struct SBiTNode *lchild, *rchild;
}BiTNode, *BiTree;

void CreateBiTree(BiTree *T)
{
	TElemType ch;
	scanf("%c", &ch);
	if (ch == '#')
		*T = NULL;
	else
	{
		*T = (BiTree)malloc(sizeof(BiTNode));
		if (!*T)
			exit(-1);
		(*T)->data = ch;
		CreateBiTree(&(*T)->lchild);
		CreateBiTree(&(*T)->rchild);
	}
}
//先序遍历
void PreOrderTraverse(BiTree T)
{
	if (T == NULL)
		return;
	printf("%c", T->data);
	PreOrderTraverse(T->lchild);
	PreOrderTraverse(T->rchild);
}
//中序遍历
void InOrderTraverse(BiTree T)
{
	if (T == NULL)
		return;
	InOrderTraverse(T->lchild);
	printf("%c", T->data);
	InOrderTraverse(T->rchild);
}
//后序遍历
void PostOrderTraverse(BiTree T)
{
	if (T == NULL)
		return;
	PostOrderTraverse(T->lchild);
	PostOrderTraverse(T->rchild);
	printf("%c", T->data);
}
//主函数
int main()
{
	BiTree T;
	CreateBiTree(&T);		//创建二叉树
	PreOrderTraverse(T);	//先序遍历
	printf("\n");
	InOrderTraverse(T);		//中序遍历
	printf("\n");
	PostOrderTraverse(T);	//后序遍历
	printf("\n");
	system("pause");
	return 0;
}

#ifndef RB_TREE_H_
#define RB_TREE_H_

template<class Compareble>
class RedBlackTree;

template<class Compareble>
class RedBlackNode;

template<class Compareble>
class RedBlackTree
{
public:
	RedBlackTree(const Compareble & negInf);
	~RedBlackTree();

	enum { RED, BLACK };	//����ö�ٱ�ʾ������ɫ

	typedef RedBlackNode<Compareble> Node;

	bool isEmpty() const;
	void makeEmpty();

	bool find(const Compareble & x) const;

	void insert(const Compareble & x);

	//private:
	Node *header;	//ͷ�ڵ�
	Node *nullNode;	//�սڵ�

	Node *current;
	Node *parent;	//���ڵ�
	Node *grand;	//�游�ڵ�
	Node *great;	//���游�ڵ�

	void reclaimMemory(Node *t) const;

	void rotateWithLeftChild(Node * &k2) const;
	void rotateWithRightChild(Node * &k1) const;
	void doubleRotateWithLeftChild(Node * &k3) const;
	void doubleRotateWithRightChild(Node * &k1) const;

	void handleReorient(const Compareble &item);
	RedBlackNode<Compareble> * rotate(const Compareble & item, Node *theParent) const;
};
//������ڵ�
template<class Compareble>
class RedBlackNode
{
public:
	Compareble		element;
	RedBlackNode	*left;
	RedBlackNode	*right;
	int				color;

	RedBlackNode(const Compareble & theElement = Compareble(),
		RedBlackNode *lt = NULL,
		RedBlackNode *rt = NULL,
		int c = RedBlackTree<Compareble>::BLACK)
		:element(theElement), left(lt), right(rt), color(c){}

	friend class RedBlackTree<Compareble>;	//���������Ϊ��Ԫ�����ڲ���˽�ж���
};


template<class Compareble>
RedBlackTree<Compareble>::RedBlackTree(const Compareble & negInf)
{
	nullNode = new Node();
	nullNode->left = nullNode->right = nullNode;

	header = new Node(negInf);
	header->left = header->right = nullNode;	//���Һ��Ӷ�ָ��սڵ�
}

template<class Compareble>
RedBlackTree<Compareble>::~RedBlackTree()
{
	delete nullNode;
	delete header;
}

//�������в������ݣ��ڲ����������Ҫʵ���Զ�ƽ��
template<class Compareble>
void RedBlackTree<Compareble>::insert(const Compareble & x)
{
	current = parent = grand = header;
	nullNode->element = x;

	while (current->element != x)	//���ܲ�����ͬ������
	{
		great = grand; grand = parent; parent = current;	//�ɵ�Ԫ��������һ��
		current = x < current->element ? current->left : current->right;	//������Ѱ

		//1.�����ǰ�ڵ�����Ҷ��Ӷ��Ǻ�ɫ����Ҫ���д���
		if (current->left->color == RED && current->right->color == RED)
			handleReorient(x);
	}

	if (current != nullNode)
		throw "element repeat!";

	current = new Node(x, nullNode, nullNode);
	if (x < parent->element)
		parent->left = current;
	else
		parent->right = current;

	//�����²���ڵ�ҲҪ���д���
	handleReorient(x);
}

//������ת
template<class Compareble>
void RedBlackTree<Compareble>::rotateWithLeftChild(Node * &k2) const
{
	Node *k1 = k2->left;
	//�����ƶ�
	k2->left = k1->right;
	//�������½�
	k1->right = k2;
	k2 = k1;
}
//������ת
template<class Compareble>
void RedBlackTree<Compareble>::rotateWithRightChild(Node * &k1) const
{
	Node *k2 = k1->right;
	k1->right = k2->left;
	k2->left = k1;
	k1 = k2;
}
//����˫��ת
template<class Compareble>
void RedBlackTree<Compareble>::doubleRotateWithLeftChild(Node * &k3) const
{
	rotateWithRightChild(k3->left);
	rotateWithLeftChild(k3);
}

//����˫��ת
template<class Compareble>
void RedBlackTree<Compareble>::doubleRotateWithRightChild(Node * &k1) const
{
	rotateWithLeftChild(k1->right);
	rotateWithRightChild(k1);
}

//���ݺ�ڹ�����������
template<class Compareble>
void RedBlackTree<Compareble>::handleReorient(const Compareble &item)
{
	//��ɫ
	//1.������������ɫ�ӽڵ�Ľڵ���б�ɫ����
	current->color = RED;
	current->left->color = BLACK;
	current->right->color = BLACK;

	//2.��ǰ�ڵ�ĸ��ڵ�Ϊ��ɫ
	if (parent->color == RED)
	{
		//үү��ɫ���
		grand->color = RED;
		//������ת����
		//�ж�������ڲ����Ӿ���������ת���ⲿ����һ����ת
		if (item < grand->element != item < parent->element)
			parent = rotate(item, grand);
		current = rotate(item, great);
		//��ת֮��ѵ�ǰ�ڵ���
		current->color = BLACK;
	}
	//���ڵ�����ɫ
	header->right->color = BLACK;
}

//���������Զ��ж���ת����
//����������ת->LL
//����������ת->LR
//����������ת->RL
//����������ת->RR
//����1����ǰ�ڵ����ݣ�����2���游�ڵ㣨Ӧ�ȵ�ǰitem��������
template<class Compareble>
RedBlackNode<Compareble> * RedBlackTree<Compareble>::rotate(const Compareble & item, Node *theParent) const
{
	if (item < theParent->element)	//������
	{
		//���itemС��theParent->left->element,֤��item�������Ҫ����ת
		item < theParent->left->element ?
			rotateWithLeftChild(theParent->left) :
			rotateWithRightChild(theParent->left);

		return theParent->left;
	}
	else	//������
	{
		item < theParent->right->element ?
			rotateWithLeftChild(theParent->right) :
			rotateWithRightChild(theParent->right);

		return theParent->right;
	}
}
//�жϺ�����Ƿ�Ϊ��
template<class Compareble>
bool RedBlackTree<Compareble>::isEmpty() const
{
	return header->right == nullNode;
}

//��պ����
template<class Compareble>
void RedBlackTree<Compareble>::makeEmpty()
{
	reclaimMemory(header->right);
	header->right = nullNode;
}

template<class Compareble>
void RedBlackTree<Compareble>::reclaimMemory(Node *t) const
{
	//�ݹ����
	//t����t->leftʱ֤��������ֹͣ�ݹ飨����nullNode��
	if (t != t->left)
	{
		reclaimMemory(t->left);
		reclaimMemory(t->right);
		delete t;
	}
}

//��պ����
template<class Compareble>
bool RedBlackTree<Compareble>::find(const Compareble & x) const
{
	nullNode->element = x;

	Node *curr = header->right;

	while (1)
	{
		if (x < curr->element)
			curr = curr->left;
		else if (x>curr->element)
			curr = curr->right;
		else if (curr != nullNode)
			return true;
		else
			return false;
	}
}

#endif

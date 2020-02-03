#define _CRT_SECURE_NO_WARNINGS 1
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

	enum { RED, BLACK };	//利用枚举表示两种颜色

	typedef RedBlackNode<Compareble> Node;

	bool isEmpty() const;
	void makeEmpty();

	bool find(const Compareble & x) const;

	void insert(const Compareble & x);

	//private:
	Node *header;	//头节点
	Node *nullNode;	//空节点

	Node *current;
	Node *parent;	//父节点
	Node *grand;	//祖父节点
	Node *great;	//曾祖父节点

	void reclaimMemory(Node *t) const;

	void rotateWithLeftChild(Node * &k2) const;
	void rotateWithRightChild(Node * &k1) const;
	void doubleRotateWithLeftChild(Node * &k3) const;
	void doubleRotateWithRightChild(Node * &k1) const;

	void handleReorient(const Compareble &item);
	RedBlackNode<Compareble> * rotate(const Compareble & item, Node *theParent) const;
};
//红黑树节点
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

	friend class RedBlackTree<Compareble>;	//将红黑树作为友元类用于操作私有对象
};


template<class Compareble>
RedBlackTree<Compareble>::RedBlackTree(const Compareble & negInf)
{
	nullNode = new Node();
	nullNode->left = nullNode->right = nullNode;

	header = new Node(negInf);
	header->left = header->right = nullNode;	//左右孩子都指向空节点
}

template<class Compareble>
RedBlackTree<Compareble>::~RedBlackTree()
{
	delete nullNode;
	delete header;
}
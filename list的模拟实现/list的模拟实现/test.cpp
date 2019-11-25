#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


//插入元素
//遍历链表
//删除元素
//迭代器访问链表，并可以在访问时修改值

//建立基本结点
template <class T>
struct Node
{
	Node<T>* _prev;
	Node<T>* _next;
	T _val;

	//构造函数
	Node(const T& val = T()) :
		_prev(nullptr), _next(nullptr), val(val)
	{}
};


//list的迭代器需要自己封锁
template <class T>
struct Iterator{
	typedef Node<T> Node;
	Node* _node;
	//重载
	Iterator(Node* node) :
		_node(node){}

	T& operator*(){
		return _node->_val;
	}

	//前置++的重载
	Iterator& operator++(){
		_node = _node->_next;
		return *this;
	}
	//!=的重载
	bool operator!=(const Iterator& it){
		return it.node != this->node;
	}

	//->的重载
	T* operator->(){
		return &_node->val;

	}
};

//const迭代器
template<class T>
struct Const_Iterator{
	typedef Node<T> Node;
	Node* _node;
	Const_Iterator(Node* node) :
		_node(node)
	{}

	//只读T&
	const T& operator*()const{
		return _node->_val;
	}

	const Const_Iterator operator++(){
		_node = _node->_next;
		return *this;
	}

	const T* operator->(){
		return &_node->_val;
	}

	bool operator!=(const Const_Iterator& cit){
		return _node != cit._node;
	}

//List类
template <class T>
class List{
public:
	typedef Node<T> Node;
	typedef Iterator<T> iterator;
	typedef Const_Iterator<T> const_iterator;
	//构造函数，建立一个不存在数据元素的结点—头节点
	List()
		:_head(new Node){
		_head->_next = head;
		_head->_prev = head;
	}

	//尾插
	void PushBack(const T& val){
		Node* node = new Node;
		node->val = val;
		//原链表中没有有效结点
		if (_head->_prev == _head){
			_head->_prev = node;
			_head->_next = node;
			node->_next = _head;
			node->_prev = _head;
		}
		//原链表中存在有效元素
		else{
			node->_next = _head;
			node->_prev = _head->_prev;
			_head->_prev->_next = node;
			_head->_prev = node;
		}
	}



	};





};





int main()
{
	system("pause");
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


//����Ԫ��
//��������
//ɾ��Ԫ��
//���������������������ڷ���ʱ�޸�ֵ

//�����������
template <class T>
struct Node
{
	Node<T>* _prev;
	Node<T>* _next;
	T _val;

	//���캯��
	Node(const T& val = T()) :
		_prev(nullptr), _next(nullptr), val(val)
	{}
};


//list�ĵ�������Ҫ�Լ�����
template <class T>
struct Iterator{
	typedef Node<T> Node;
	Node* _node;
	//����
	Iterator(Node* node) :
		_node(node){}

	T& operator*(){
		return _node->_val;
	}

	//ǰ��++������
	Iterator& operator++(){
		_node = _node->_next;
		return *this;
	}
	//!=������
	bool operator!=(const Iterator& it){
		return it.node != this->node;
	}

	//->������
	T* operator->(){
		return &_node->val;

	}
};

//const������
template<class T>
struct Const_Iterator{
	typedef Node<T> Node;
	Node* _node;
	Const_Iterator(Node* node) :
		_node(node)
	{}

	//ֻ��T&
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

//List��
template <class T>
class List{
public:
	typedef Node<T> Node;
	typedef Iterator<T> iterator;
	typedef Const_Iterator<T> const_iterator;
	//���캯��������һ������������Ԫ�صĽ�㡪ͷ�ڵ�
	List()
		:_head(new Node){
		_head->_next = head;
		_head->_prev = head;
	}

	//β��
	void PushBack(const T& val){
		Node* node = new Node;
		node->val = val;
		//ԭ������û����Ч���
		if (_head->_prev == _head){
			_head->_prev = node;
			_head->_next = node;
			node->_next = _head;
			node->_prev = _head;
		}
		//ԭ�����д�����ЧԪ��
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
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
		_prev(nullptr), _next(nullptr), _val(val)
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
		return it._node != this->_node;
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
};

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
		_head->_next = _head;
		_head->_prev = _head;
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
	//头插
	void PushFront(const T& val){
		Node* node = new Node;
		node->_val = val;
		//如果原链表没有有效元素
		if (_head->_next == _head){
			node->_next = _head;
			_head->_next = node;
			node->_prev = _head;
			_head->_prev = node;
		}
		//原链表中存在有效元素
		else{
			node->_next = _head->_next;
			_head->_next->_prev = node;
			_head->_next = node;
			node->_prev = _head;
		}
	}

	//尾删
	void PopBack(){
		//如果没有有效元素
		if (_head->_next == _head){
			return;
		}
		//存在有效元素
		Node* tmp = _head->_prev;
		_head->_prev = tmp->_prev;
		tmp->_prev->_next = _head;
		delete tmp;
	}

	//头删
	void PopFront(){
		//如果没有有效元素
		if (_head->_next == _head){
			return;
		}
		//存在有效元素
		Node* tmp = head->_next;
		_head->next = tmp->_next;
		tmp->_next->_prev = _head;
		delete tmp;
	}

	iterator begin(){
		return iterator(_head->_next);
	}

	iterator end(){
		return iterator(_head);
	}

	const_iterator cbegin(){
		return const_iterator(_head->_next);
	}

	const_iterator cend(){
		return const_iterator(_head);
	}


	iterator Erase(iterator pos){
		//判断链表是否为空
		if (pos != end()){
			iterator tmp = pos;
			tmp._node->_prev->_next = tmp._node->_next;
			tmp._node->_next->_prev = tmp._node->_prev;
			++pos;
			delete tmp._node;
			tmp._node = nullptr;
		}
		return pos;
	}

	//打印
	void Print(){
		iterator it = begin();
		while (it != end()){
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}
private:
	Node* _head;
};


void test(){
	List<int> l;
	/*l.PushBack(1);
	l.PushBack(2);*/
	l.PushFront(1);
	l.PushFront(2);
	//l.PopBack();
	//l.PopBack();
	//l.PopFront();
	//l.PopFront();

	List<int>::iterator it = l.begin();
	*it = 100;
	cout << it._node->_val << endl;


	List<int>::iterator it2 = l.Erase(it);
	cout << it2._node->_val << endl;
	l.Print();
	List<int>::const_iterator cit = l.cbegin();

}




int main()
{
	test();
	system("pause");
	return 0;
}
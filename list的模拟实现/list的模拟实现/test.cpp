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
		_prev(nullptr), _next(nullptr), _val(val)
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
		return it._node != this->_node;
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
};

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
		_head->_next = _head;
		_head->_prev = _head;
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
	//ͷ��
	void PushFront(const T& val){
		Node* node = new Node;
		node->_val = val;
		//���ԭ����û����ЧԪ��
		if (_head->_next == _head){
			node->_next = _head;
			_head->_next = node;
			node->_prev = _head;
			_head->_prev = node;
		}
		//ԭ�����д�����ЧԪ��
		else{
			node->_next = _head->_next;
			_head->_next->_prev = node;
			_head->_next = node;
			node->_prev = _head;
		}
	}

	//βɾ
	void PopBack(){
		//���û����ЧԪ��
		if (_head->_next == _head){
			return;
		}
		//������ЧԪ��
		Node* tmp = _head->_prev;
		_head->_prev = tmp->_prev;
		tmp->_prev->_next = _head;
		delete tmp;
	}

	//ͷɾ
	void PopFront(){
		//���û����ЧԪ��
		if (_head->_next == _head){
			return;
		}
		//������ЧԪ��
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
		//�ж������Ƿ�Ϊ��
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

	//��ӡ
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
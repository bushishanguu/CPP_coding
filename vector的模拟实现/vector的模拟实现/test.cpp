#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
#include<string>
using namespace std;
template<class T>

class Vector{
public:
	typedef T* iterator;
	//ģ��ָ��
	typedef const T* const_iterator;

	Vector()//���캯��
		:_start(nullptr)
		, _finish(nullptr)
		, _end0fStorage(nullptr)  //����õĿռ�Ľ���λ��
	{}

	//�������캯��
	Vector(const Vector<T>& v){
		T* _start = new T[v.Capacity()];
		for (int i = 0; i < v.Size(); i++){
			_start[i] = v[i];//���ݿ���
		}
		_finish = _start = v.Size();
		_end0fStorage = _start + v.Capacity();
	}

	//��ֵ���������
	T& operator=(Vector<T> v){
		Swap(v);//������Դ�Ϳռ�
		return this;
	}

	//��������
	~Vector(){
		if (_start){
			delete[] _start;
			_start = _finish = _end0fStorage = nullptr;
		}
	}


	//��������
	void Swap(Vector<T> v){
		swap(_start, v._start);
		swap(_finish, v._finish);
		swap(_end0fStorage, v._end0fStorage);
	}

	//������Ч����
	size_t Size()const{
		return _finish - _start;
	}

	//����������
	size_t Capacity()const{
		return _end0fStorage - _start;
	}

	//β��
	void PushBack(const T&val){
		if (_finish == _end0fStorage)
		{
			//����
			size_t newc = ((_start == nullptr) ? 1 : 2 * Capacity());
			Reserve(newc);
		}
		*_finish = val; //����finish
		++_finish;
	}
	//���ݺ���
	void Reserve(size_t n){
		if (n > Capacity()){
			size_t sz = Size();

			T* tmp = new T[n];//����ռ�
			if (_start){
				for (int i = 0; i<sz; i++){
					tmp[i] = _start[i];
				}
				delete[] _start;
			}
			_start = tmp;//�¿ռ丳ֵ 
			_finish = _start + sz;//���³��Ⱥ�����
			_end0fStorage = _start + n;
		}
	}


	//[]�����غ���
	T& operator[](size_t pos){
		assert(pos < Size());
		return _start[pos];

	}

	//ʵ�ֿɹ���const��const������õ�[]���غ���
	const T& operator[](size_t pos)const{
		assert(pos < Size());
		return _start[pos];
	}

	//����������ع���
	iterator begin(){
		return _start;
	}
	iterator end(){
		return _finish;
	}
	//const�������Ĺ���
	const_iterator begin() const{
		return _start;
	}
	const_iterator end() const{
		return _finish;
	}

	//���뺯��
	void Insert(iterator pos, const T& val){
		assert(pos <= _finish&&pos >= _start);
		size_t len = pos - _start;
		//�������ĵ���ʼ�ľ��� �����ȷ��posλ��
		if (_finish == _end0fStorage){
			size_t newc = (_start == nullptr ? 1 : 2 * Capacity());
			Reserve(newc);
		}

		//���µ�����
		pos = _start + len;
		iterator end = _finish;

		while (end > pos){
			*end = *(end - 1);
			end--;//��β��λ�õ������λ������ƶ�һλ
		}

		*pos = val;//����Ԫ��
		++_finish;//����_finish
	}


	//ʵ���ͷź���
	iterator Erase(iterator pos){
		assert(pos >= _start&& pos < _finish);
		iterator begin = pos + 1;
		//��ǰŲ��Ԫ��
		while (begin < _finish){
			*(begin - 1) = *begin;
			begin++;
		}
		--_finish;//����_finish ��λ��
		return pos;
	}

	//���ÿռ�ĺ���
	void Resize(size_t n, const T& val = T()){
		//�ж�����ռ��ָ������Ĵ�С��ϵ
		//������� �ͽ�������
		if (n <= Size()){
			_finish = _start + n;
		}
		else{
			if (n > Capacity())
				Reserve(n);
			while (_finish != _start + n){
				*_finish = val;//�����Ӻ�Ŀռ丳ֵ
				_finish++;
			}
		}
	}
private:
	T* _start;
	T* _finish;
	T* _end0fStorage;

};

template <class T>
void PrintVector(const Vector<T>& v){
	for (int i = 0; i < v.Size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
}

template <class T>
void PrintVectorFor(const Vector<T>& v){
	for (auto& e : v){
		cout << e << " ";
	}
	cout << endl;
}



//����������Դ���� 





void testInsertErase(){
	Vector<int> v;
	v.PushBack(1);
	v.PushBack(2);
	v.PushBack(3);
	v.PushBack(4);
	v.Insert(v.end(), 5);
	PrintVectorFor(v);
	//ɾ������ż��
	Vector<int>::iterator vit = v.begin();
	while (vit != v.end()){
		if (*vit % 2 == 0){
			vit = v.Erase(vit);
			//����Erase�����ķ���ֵ����ֹ������ʧЧ
		}
		else
			vit++;
	}

	PrintVectorFor(v);
}


void testResize(){
	Vector<int> v;
	v.PushBack(1);
	v.PushBack(2);
	v.PushBack(3);
	v.PushBack(4);

	v.Resize(3);
	PrintVectorFor(v);
}


int main(){
	Vector<int> v;
	v.PushBack(1);
	v.PushBack(1);
	v.PushBack(1);
	v.PushBack(1);
	v.PushBack(1);
	PrintVectorFor(v);
	Vector<string> v1;
	v1.PushBack("hello");
	v1.PushBack(" world!");
	PrintVectorFor(v1);
	testInsertErase();
	testResize();
	system("pause");
	return 0;
}

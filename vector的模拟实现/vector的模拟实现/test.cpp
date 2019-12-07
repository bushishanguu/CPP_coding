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
		, _finsh(nullptr)
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
		_start = finish = _end0fStorage = nullptr;
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
		*finish = val; //����finish
		++finish;
	}
	//���ݺ���
	void Reserve(size_t n){
		if (n > Capacity()){
			size_t sz = Size();

			T* tmp = new T[n];//����ռ�
			if (_start){
				for (int i = 0; i < sz; i++){
					tmp[i] = _start[i];
				}
				delete[] _start;
			}
			_start = tmp;//�¿ռ丳ֵ 
			_finish = _start + sz;//���³��Ⱥ�����
			__end0fStorage = _start + n;
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
















};


int main()
{
	//Vector<int> v;
	system("pause");
	return 0;
}
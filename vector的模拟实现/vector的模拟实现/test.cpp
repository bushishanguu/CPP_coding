#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
#include<string>
using namespace std;
template<class T>

class Vector{
public:
	typedef T* iterator;
	//模板指针
	typedef const T* const_iterator;

	Vector()//构造函数
		:_start(nullptr)
		, _finsh(nullptr)
		, _end0fStorage(nullptr)  //以配好的空间的结束位置
	{}

	//拷贝构造函数
	Vector(const Vector<T>& v){
		T* _start = new T[v.Capacity()];
		for (int i = 0; i < v.Size(); i++){
			_start[i] = v[i];//内容拷贝
		}
		_finish = _start = v.Size();
		_end0fStorage = _start + v.Capacity();
	}

	//赋值运算符重载
	T& operator=(Vector<T> v){
		Swap(v);//交换资源和空间
		return this;
	}

	//析构函数
	~Vector(){
		if (_start){
		delete[] _start;
		_start = finish = _end0fStorage = nullptr;
	    }
	}


	//交换函数
	void Swap(Vector<T> v){
		swap(_start, v._start);
		swap(_finish, v._finish);
		swap(_end0fStorage, v._end0fStorage);
	}

	//计算有效长度
	size_t Size()const{
		return _finish - _start;
	}

	//计算总容量
	size_t Capacity()const{
		return _end0fStorage - _start;
	}

	//尾插
	void PushBack(const T&val){
		if (_finish == _end0fStorage)
		{
			//扩容
			size_t newc = ((_start == nullptr) ? 1 : 2 * Capacity());
			Reserve(newc);
		}
		*finish = val; //更新finish
		++finish;
	}
	//增容函数
	void Reserve(size_t n){
		if (n > Capacity()){
			size_t sz = Size();

			T* tmp = new T[n];//申请空间
			if (_start){
				for (int i = 0; i < sz; i++){
					tmp[i] = _start[i];
				}
				delete[] _start;
			}
			_start = tmp;//新空间赋值 
			_finish = _start + sz;//更新长度和容量
			__end0fStorage = _start + n;
		}
	}


	//[]的重载函数
	T& operator[](size_t pos){
		assert(pos < Size());
		return _start[pos];

	}

	//实现可供非const和const对象调用的[]重载函数
	const T& operator[](size_t pos)const{
		assert(pos < Size());
		return _start[pos];
	}

	//迭代器的相关功能
	iterator begin(){
		return _start;
	}
	iterator end(){
		return _finish;
	}
	 //const迭代器的功能
	const_iterator begin() const{
		return _start;
	}
	const_iterator end() const{
		return _finish;
	}

	//插入函数
	void Insert(iterator pos, const T& val){
		assert(pos <= _finish&&pos >= _start);
		size_t len = pos - _start;
		//计算插入的到开始的距离 插入后确定pos位置
		if (_finish == _end0fStorage){
			size_t newc = (_start == nullptr ? 1 : 2 * Capacity());
			Reserve(newc);
		}

		//更新迭代器
		pos = _start + len;
		iterator end = _finish;

		while (end > pos){
			*end = *(end - 1);
			end--;//将尾端位置到插入的位置向后移动一位
		}

		*pos = val;//插入元素
		++_finish;//更新_finish
	}
















};


int main()
{
	//Vector<int> v;
	system("pause");
	return 0;
}
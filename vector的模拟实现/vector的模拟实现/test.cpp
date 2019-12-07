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
		, _finish(nullptr)
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
			_start = _finish = _end0fStorage = nullptr;
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
		*_finish = val; //更新finish
		++_finish;
	}
	//增容函数
	void Reserve(size_t n){
		if (n > Capacity()){
			size_t sz = Size();

			T* tmp = new T[n];//申请空间
			if (_start){
				for (int i = 0; i<sz; i++){
					tmp[i] = _start[i];
				}
				delete[] _start;
			}
			_start = tmp;//新空间赋值 
			_finish = _start + sz;//更新长度和容量
			_end0fStorage = _start + n;
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


	//实现释放函数
	iterator Erase(iterator pos){
		assert(pos >= _start&& pos < _finish);
		iterator begin = pos + 1;
		//向前挪动元素
		while (begin < _finish){
			*(begin - 1) = *begin;
			begin++;
		}
		--_finish;//更新_finish 的位置
		return pos;
	}

	//重置空间的函数
	void Resize(size_t n, const T& val = T()){
		//判断所需空间和指定对象的大小关系
		//如果不够 就进行增容
		if (n <= Size()){
			_finish = _start + n;
		}
		else{
			if (n > Capacity())
				Reserve(n);
			while (_finish != _start + n){
				*_finish = val;//给增加后的空间赋值
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



//测试用例来源网络 





void testInsertErase(){
	Vector<int> v;
	v.PushBack(1);
	v.PushBack(2);
	v.PushBack(3);
	v.PushBack(4);
	v.Insert(v.end(), 5);
	PrintVectorFor(v);
	//删除所有偶数
	Vector<int>::iterator vit = v.begin();
	while (vit != v.end()){
		if (*vit % 2 == 0){
			vit = v.Erase(vit);
			//接收Erase函数的返回值，防止迭代器失效
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

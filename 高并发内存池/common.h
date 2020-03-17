#pragma once

#include<iostream>
#include<assert.h>
#include<windows.h>
#include<map>
#include<unordered_map>
#include<thread>
#include<mutex>

using std::cout;
using std::endl;


const size_t MAX_SIZE = 64 * 1024;//��ö������꣬�����Ժ����
const size_t NFRER_LIST = MAX_SIZE / 8;
const size_t MAX_PAGES = 129;
const size_t PAGE_SHIFT = 12;//4k


inline void*& NextObj(void* obj)//�˺�����ΪƵ���ĵ��ã�����ʹ����������
{
	//��Ϊ*(int*)p��32λ����4�ֽڣ���64λ����8�ֽ�
	//����ת��Ϊ*(void**)������֮�����void*����ָ��Ĵ�С������ϵͳΪ�ı���ı�
	return *((void**)obj);
}

class FreeList
{
public:
	void push(void* obj)//���ڴ�
	{
		//ͷ��
		NextObj(obj) = _freelist;//��objָ�������ͷ
		_freelist = obj;//��ͷ��ֵΪobj
		++_num;//ͳ������
	}

	void* Pop()//ȡ�ڴ�
	{
		//ͷɾ
		void* obj = _freelist;
		_freelist = NextObj(obj);
		--_num;

		return obj;
	}

	void PushRange(void* head, void* tail, size_t num)
	{
		NextObj(tail) = _freelist;
		_freelist = head;
		_num += num;
	}


	size_t PopRange(void*& start, void*& end, size_t num)
	{
		size_t actualNum = 0;
		void* prev = nullptr;
		void* cur = _freelist;
		for (; actualNum < num && cur != nullptr; ++actualNum)
		{
			prev = cur;
			cur = NextObj(cur);
		}

		start = _freelist;
		end = prev;
		_freelist = cur;

		_num -= actualNum;

		return actualNum;
	}
	size_t Num()
	{
		return _num;
	}
	
	bool Empty()
	{
		return _freelist == nullptr;
	}

	void Clear()
	{
		_freelist = nullptr;
		_num = 0;
	}
private:
	void* _freelist = nullptr;//Ĭ�Ϲ��캯����ʼ��
	size_t _num = 0;//�����С
};


class SizeClass //�����С����
{
public:
	static size_t _ListIndex(size_t size, size_t alignment_shift) //�����±�
	{
		return ((size + (1 << alignment_shift) - 1) >> alignment_shift) - 1;		/*if (size % 8 == 0)
		{
			return size / 8 - 1;
		}
		else
			return size / 8;*/
	}

	static inline size_t Index(size_t size)
	{
		assert(size <= MAX_SIZE);
		// ÿ�������ж��ٸ���
		static int group_array[4] = { 16, 56, 56, 56 };
		if (size <= 128){
			return _ListIndex(size, 3);//��8�ֽڶ�����������±�
		}
		else if (size <= 1024){
			return _ListIndex(size - 128, 4) + group_array[0];
		}
		else if (size <= 8192){
			return _ListIndex(size - 1024, 7) + group_array[1] + group_array[0];
		}
		else if (size <= 65536){
			return _ListIndex(size - 8192, 9) + group_array[2] + group_array[1] +
				group_array[0];
		}
		assert(false);
		return -1;
	}

	static inline size_t _RoundUp(size_t size, size_t alignment)//������ȡ���ֽ���Ӧ�ò��뵽���٣�9-16��~~�������16
	{
		return (size + alignment - 1)&(~(alignment - 1));
		/*if (size % 8 != 0)
			return (size / 8 + 1) * 8;
		else
			return size;*/
	}

// �����С����
	static inline size_t RoundUp(size_t size)
	{
		assert(size <= MAX_SIZE);
		if (size <= 128){
			return _RoundUp(size, 8);
		}
		else if (size <= 1024){
			return _RoundUp(size, 16);
		}
		else if (size <= 8192){
			return _RoundUp(size, 128);
		}
		else if (size <= 65536){
			return _RoundUp(size, 512);
		}
		return -1;
	}

	//��̬��Ӧ�����ĸ�����thread �� central Ҫ
	static size_t NumMoveSize(size_t size)
	{
		if (size == 0)
			return 0;

		int num = (MAX_SIZE / size);
		if (num < 2)
			num = 2;

		if (num > 512)
			num = 512;
		return num;
	}

	static size_t NumMovePage(size_t size)//һ����pagecacheȡ����
	{
		size_t num = NumMoveSize(size);
		size_t npage = num*size;
		
		npage >>= 12;
 		if (npage == 0)
			npage = 1;

		return npage;
	}
};

#ifdef _WIN32
typedef unsigned int PAGE_ID;
#else
typedef unsigned long long PAGE_ID;
#endif


struct Span
{
	PAGE_ID _pagid = 0;//ҳ��
	PAGE_ID _pagesize = 0;//ҳ������
	size_t _objSize = 0;//�����������Ĵ�С
	int _usecount = 0;//�ڴ�����ʹ�ü���
	FreeList _freeList;
	//Ĭ�Ϲ��캯����ʹ��ȱʡֵ���г�ʼ��
 	//size_t objsize;
	Span* _next = nullptr;
	Span* _prev = nullptr;
};


class SpanList
{
public:
	SpanList()
	{
		_head = new Span;
		_head->_next = _head;
		_head->_prev = _head;
	}

	Span* Begin()
	{
		return _head->_next;
	}

	Span* End()
	{
		return _head;//����ҿ������Է���ͷ
	}

	void Insert(Span* pos, Span* newspan)//���λ�ò���
	{
		Span* prev = pos->_prev;

		//prev newspan pos
		prev->_next = newspan;
		newspan->_prev = prev;

		pos->_prev = newspan;
		newspan->_next = pos;
	}

	void Erase(Span* pos)
	{
		assert(pos != _head);

		Span* prev = pos->_prev;
		Span* next = pos->_next;

		prev->_next = next;
		next->_prev = prev;
	}

	void PushFront(Span* newspan)//ͷ��
	{
		Insert(_head->_next,newspan);
	}

	void PopFront()
	{
		Erase(_head->_next);
	}

	void PushBack(Span* newspan)
	{
		Insert(_head->_prev, newspan);
	}

	void PopBack()
	{
		Erase(_head->_prev);
	}

	bool Empty()
	{
		return Begin() == End();
	}

	void Lock()
	{
		_mut.lock();
	}

	void Unlock()
	{
		_mut.unlock();
	}

private:
	Span* _head;//��ͷ˫������
	std::mutex _mut;
};

inline static void* SystemAlloc(size_t num_page)
{
#ifdef _WIN32
	void* ptr = VirtualAlloc(0, num_page*(1 << PAGE_SHIFT),
		MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
#else
	//linux
#endif
	if (ptr == nullptr)
		throw std::bad_alloc();

	return ptr;
}

inline static void SystemFree(void* ptr)
{
#ifdef _WIN32
	VirtualFree(ptr,0,MEM_RELEASE);
#else
#endif
}
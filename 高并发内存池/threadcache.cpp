#include"threadcache.h"
#include"centrlcache.h"

//�������Threadcache���ͻᵼ�����Ӳ��ϣ���Ϊû��ָ������������Ǹ�������
void* Threadcache::Allocate(size_t size)//�ɴ˴���size%8���Լ��������������±�
{
	size_t index = SizeClass::Index(size);
	FreeList& freeList = _freeLists[index];

	if (!freeList.Empty())
	{
		return freeList.Pop();
	}
	else
	{
		//û�������Ļ���ȡ
		return FetchFromCentralCache(SizeClass::RoundUp(size));
	}
}
void Threadcache::Deallocate(void* ptr, size_t size)//�黹�ڴ�
{
	size_t index = SizeClass::Index(size);
	FreeList& freelist = _freeLists[index];
	freelist.push(ptr);//���黹���ڴ棬�ҵ�����������ȥ

	size_t num = SizeClass::NumMoveSize(size);
	if (freelist.Num() >= num)
	{
		ListLong(freelist, num , size); 
	}

}

void Threadcache::ListLong(FreeList& freelist, size_t num, size_t size)
{
	void* start = nullptr, *end = nullptr;
	freelist.PopRange(start, end, num);

	NextObj(end) = nullptr;//��ʽ�ڴ�����
	CentrlCache::GetInsatnce().ReleaseListToSpans(start, size);
}
//void* Threadcache::FetchFromCentralCache(size_t index)
//{
//	size_t num = 20;
//	size_t size = (index + 1) * 8;
//	char* start = (char*)malloc(size*num);
//	char* cur = start;
//
//	for (size_t i = 0; i < num-1; ++i)
//	{
//		char* next = cur + size;
//		NextObj(cur) = next;//��next��Ϊ��һ��ָ���ֵ������NextObj
//
//		cur = next;//
//	}
//	NextObj(cur) = nullptr;
//
//	void* head = NextObj(start); //��Ϊ�˴�ֻȡ��һ����Ҳ����start����������������ҵ�ʱ����Ҫstart����һ����Ϊͷ�ҽ�ȥ
//	void* tail = cur;
//	
//	_freeLists[index].PushRange(head, tail);
//
//	return start;
//}

void* Threadcache::FetchFromCentralCache(size_t size)
{
	size_t num = SizeClass::NumMoveSize(size);//������Ҫ�ĸ���

	void* start = nullptr, *end = nullptr;

	// �����Ļ����ȡһ�������Ķ����threadcache
	size_t realNum = CentrlCache::GetInsatnce().FetchRangeObj(start, end, num, size);

	if (realNum == 1)//����һ��ʱ��ֱ�ӷ���
	{
		return start;
	}
	else//�����ʱ����Ҫ���ص�һ������ʣ��Ĺ�����
	{
		size_t index = SizeClass::Index(size);
		FreeList& list = _freeLists[index];
		list.PushRange(NextObj(start), end,realNum - 1);

		return start;
	}
}

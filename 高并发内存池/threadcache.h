#pragma once

#include"common.h"

class Threadcache
{
public:
	//�����ڴ���ͷ��ڴ�
	void* Allocate(size_t size);
	void Deallocate(void* ptr, size_t size);
	//������cacheȡ�ڴ�
	void* FetchFromCentralCache(size_t index);
	//������������ж��󳬹�һ������
	void ListLong(FreeList& freelist, size_t num, size_t size);
private:
	FreeList _freeLists[NFRER_LIST];
};

_declspec (thread) static Threadcache* tlsThread = nullptr;
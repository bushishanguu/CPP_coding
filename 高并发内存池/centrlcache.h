#pragma once

#include"common.h"
#include"PageCache.h"
//Լ��numΪ������sizeΪ��С
class CentrlCache
{
public:
	// �����Ļ����ȡһ�������Ķ����thread cache
	size_t FetchRangeObj(void*& start, void*& end, size_t num, size_t size);
	// ��һ�������Ķ����ͷŵ�span���
	void ReleaseListToSpans(void* start,size_t size);
	// ��spalist ���� page cache��ȡһ��span
	Span* GetOneSpan(size_t size);

	static CentrlCache& GetInsatnce()
	{
		static CentrlCache in;
		return in;
	}
private:
	SpanList _spanLists[NFRER_LIST];

	CentrlCache()
	{}

	CentrlCache(const CentrlCache&) = delete;
};

//��Ϊ����ģʽ���ﵽȫ��ֻ��һ��__centrlCache
//static CentrlCache __centrlcache;//����̹߳���̬��
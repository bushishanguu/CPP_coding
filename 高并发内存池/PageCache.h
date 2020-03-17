#pragma once

#include"common.h"

class PageCache
{
public:
	Span* NewSpan(size_t num);
	Span* _NewSpan(size_t num);

	//上一次还内存
	void ReleaseSpanToPageCache(Span* span);
	//返回id号所对应的地址
	Span* GetIdToSpan(PAGE_ID id);

	static PageCache& GetInsatnce()
	{
		static PageCache in;
		return in;
	}

private:
	SpanList _spanLists[MAX_PAGES];//用map映射，通过页号可以找到对应的span地址
	std::unordered_map<PAGE_ID, Span*> _idSpanMap;
	std::mutex _mut;

	PageCache()
	{}

	PageCache(const PageCache&) = delete;
};
//同centralcache一样改为单例模式
//static PageCache __pageCache;
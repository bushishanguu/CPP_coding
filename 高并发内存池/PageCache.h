#pragma once

#include"common.h"

class PageCache
{
public:
	Span* NewSpan(size_t num);
	Span* _NewSpan(size_t num);

	//��һ�λ��ڴ�
	void ReleaseSpanToPageCache(Span* span);
	//����id������Ӧ�ĵ�ַ
	Span* GetIdToSpan(PAGE_ID id);

	static PageCache& GetInsatnce()
	{
		static PageCache in;
		return in;
	}

private:
	SpanList _spanLists[MAX_PAGES];//��mapӳ�䣬ͨ��ҳ�ſ����ҵ���Ӧ��span��ַ
	std::unordered_map<PAGE_ID, Span*> _idSpanMap;
	std::mutex _mut;

	PageCache()
	{}

	PageCache(const PageCache&) = delete;
};
//ͬcentralcacheһ����Ϊ����ģʽ
//static PageCache __pageCache;
#include"PageCache.h"

Span* PageCache::_NewSpan(size_t numpage)
{

	if (!_spanLists[numpage].Empty())
	{
		Span* span = _spanLists[numpage].Begin();
		_spanLists[numpage].PopFront();
		return span;
	}

	for (size_t i = numpage + 1; i < MAX_PAGES; ++i)//��spanlist����
	{
		if (!_spanLists[i].Empty())
		{
			Span* span = _spanLists[i].Begin();
			_spanLists[i].PopFront();

			Span* splitpage = new Span;
			splitpage->_pagid = span->_pagid + span->_pagesize - numpage;//�ҵ�β��Ȼ����
			splitpage->_pagesize = numpage;
			for (PAGE_ID i = 0; i < numpage; ++i)
			{
				_idSpanMap[splitpage->_pagid + i] = splitpage;
			}
			//splitpage->_pagid = span->_pagid + numpage;//
			//splitpage->_pagesize = span->_pagesize - numpage;

			//span->_pagesize = numpage;

			//_spanLists[splitpage->_pagesize].PushFront(splitpage);
			span->_pagesize -= numpage;

			_spanLists[span->_pagesize].PushFront(span);

			return splitpage;
		}
	}

	//spanlist��������������ϵͳ����
	void* ptr = SystemAlloc(MAX_PAGES - 1);//��ϵͳ����128ҳ

	Span* maxspan = new Span;
	maxspan->_pagid = (PAGE_ID)(ptr) >> PAGE_SHIFT;//�˴���ptr��дΪmaxspan
	maxspan->_pagesize = MAX_PAGES - 1;

	for (PAGE_ID i = 0; i < maxspan->_pagesize; ++i)
	{
		_idSpanMap[maxspan->_pagid + i] = maxspan; //����ʼҳ��һֱӳ�䵽+=128��
	}

	_spanLists[maxspan->_pagesize].PushFront(maxspan);

	return _NewSpan(numpage);//��һ�εݹ��������
}


Span* PageCache::NewSpan(size_t numpage)
{
	_mut.lock();
	Span* span = _NewSpan(numpage);
	_mut.unlock();

	return span;
}
void PageCache::ReleaseSpanToPageCache(Span* span)
 {
	// ��ǰ�ϲ�
	while (1)
	{
		PAGE_ID prevPageId = span->_pagid - 1;
		auto pit = _idSpanMap.find(prevPageId);//��idͨ��ӳ���ϵ���ҵ�ͷ
		// ǰ���ҳ������
		if (pit == _idSpanMap.end())
		{
			break;
		}

		// ˵��ǰһ��Ҳ����ʹ���У����ܺϲ�
		Span* prevSpan = pit->second;
		if (prevSpan->_usecount != 0)
		{
			break;
		}

		// �ϲ�
		if (span->_pagesize + prevSpan->_pagid >= MAX_PAGES)
		{
			break;
		}
		span->_pagid = prevSpan->_pagid;
		span->_pagesize += prevSpan->_pagesize;
		for (PAGE_ID i = 0; i < prevSpan->_pagesize; ++i)
		{
			_idSpanMap[prevSpan->_pagid + i] = span;
		}

		_spanLists[prevSpan->_pagesize].Erase(prevSpan);


		delete prevSpan;

	}


	// ���ϲ�
	while (1)
	{
		PAGE_ID nextPageId = span->_pagid + span->_pagesize;
		auto nextIt = _idSpanMap.find(nextPageId);
		if (nextIt == _idSpanMap.end())
		{
			break;
		}

		Span* nextSpan = nextIt->second;
		if (nextSpan->_usecount != 0)
		{
			break;
		}

		if (span->_pagesize + nextSpan->_pagid >= MAX_PAGES)
		{
			break;
		}

		span->_pagesize += nextSpan->_pagesize;
		for (PAGE_ID i = 0; i < nextSpan->_pagesize; ++i)
		{
			_idSpanMap[nextSpan->_pagid + i] = span;
		}

		_spanLists[nextSpan->_pagesize].Erase(nextSpan);

		delete nextSpan;
	}

	_spanLists[span->_pagesize].PushFront(span);
	
}


Span* PageCache::GetIdToSpan(PAGE_ID id)
{
	//std::map<PAGE_ID, Span*>::iterator it = _idSpanMap.find(id);
	auto it = _idSpanMap.find(id);
	if (it != _idSpanMap.end())
	{
		return it->second;//����span
	}
	else
	{
		return nullptr;
	}
}
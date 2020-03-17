#pragma once

#include"threadcache.h"
#include"PageCache.h"

static void* ConcurrencyMalloc(size_t size)
{
	if (tlsThread == nullptr)
	{
		tlsThread = new Threadcache;
	}

	if (size <= MAX_SIZE) // 1byte - 64kb ֱ����threadcache�����ڴ�
	{
		return tlsThread->Allocate(size);
	}
	else if (size <= (MAX_PAGES - 1) << PAGE_SHIFT) // 64kb - 128*4 kb ����64kֱ����pagecache
	{
		size_t align_size = SizeClass::_RoundUp(size, 1 << PAGE_SHIFT);//��һҳ����
		size_t pagenum = (align_size >> PAGE_SHIFT);//��Ϊ��4k���룬������Ҫ����
		Span* span = PageCache::GetInsatnce().NewSpan(pagenum);
		span->_objSize = align_size;
		void* ptr = (void*)(span->_pagid << PAGE_SHIFT);
		return ptr;
	}
	else
	{
		size_t align_size = SizeClass::_RoundUp(size, 1 << PAGE_SHIFT);//��һҳ����
		size_t pagenum = (align_size >> PAGE_SHIFT);//��Ϊ��4k���룬������Ҫ����
		return SystemAlloc(pagenum);
	}
}

static void ConcurrencyFree(void* ptr)
{
	size_t pageid = (PAGE_ID)ptr >> PAGE_SHIFT;
	Span* span = PageCache::GetInsatnce().GetIdToSpan(pageid);
	if (span == nullptr)//ֱ����ϵͳ���ͷţ�û��ӳ��
	{
		SystemFree(ptr);
		return;
	}
	size_t size = span->_objSize;
	if (size <= MAX_SIZE) // 1byte - 64kb��С��һҳ������cache
	{
		return tlsThread->Deallocate(ptr, size);
	}
	else if (size <= (MAX_PAGES - 1) << PAGE_SHIFT) // 64kb - 128*4 kb
	{
		PageCache::GetInsatnce().ReleaseSpanToPageCache(span);
	}
}
#pragma once

#include"threadcache.h"
#include"PageCache.h"

static void* ConcurrencyMalloc(size_t size)
{
	if (tlsThread == nullptr)
	{
		tlsThread = new Threadcache;
	}

	if (size <= MAX_SIZE) // 1byte - 64kb 直接找threadcache申请内存
	{
		return tlsThread->Allocate(size);
	}
	else if (size <= (MAX_PAGES - 1) << PAGE_SHIFT) // 64kb - 128*4 kb 大于64k直接找pagecache
	{
		size_t align_size = SizeClass::_RoundUp(size, 1 << PAGE_SHIFT);//以一页对齐
		size_t pagenum = (align_size >> PAGE_SHIFT);//因为以4k对齐，所以需要右移
		Span* span = PageCache::GetInsatnce().NewSpan(pagenum);
		span->_objSize = align_size;
		void* ptr = (void*)(span->_pagid << PAGE_SHIFT);
		return ptr;
	}
	else
	{
		size_t align_size = SizeClass::_RoundUp(size, 1 << PAGE_SHIFT);//以一页对齐
		size_t pagenum = (align_size >> PAGE_SHIFT);//因为以4k对齐，所以需要右移
		return SystemAlloc(pagenum);
	}
}

static void ConcurrencyFree(void* ptr)
{
	size_t pageid = (PAGE_ID)ptr >> PAGE_SHIFT;
	Span* span = PageCache::GetInsatnce().GetIdToSpan(pageid);
	if (span == nullptr)//直接找系统，释放，没有映射
	{
		SystemFree(ptr);
		return;
	}
	size_t size = span->_objSize;
	if (size <= MAX_SIZE) // 1byte - 64kb，小于一页找中心cache
	{
		return tlsThread->Deallocate(ptr, size);
	}
	else if (size <= (MAX_PAGES - 1) << PAGE_SHIFT) // 64kb - 128*4 kb
	{
		PageCache::GetInsatnce().ReleaseSpanToPageCache(span);
	}
}
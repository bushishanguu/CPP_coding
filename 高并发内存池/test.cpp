#pragma once

#include"common.h"
#include"threadcache.h"
#include"ConcurrencyMalloc.h"
#include<vector>


void func1()
{
	// ������[1%��10%]���ҵ�����Ƭ�˷�
	// [1,128] 8byte���� freelist[0,16)
	// [129,1024] 16byte���� freelist[16,72)
	// [1025,8*1024] 128byte���� freelist[72,128)
	// [8*1024+1,64*1024] 1024byte���� freelist[128,184)
	cout << SizeClass::RoundUp(1) << endl;
	cout << SizeClass::RoundUp(127) << endl;
	cout << endl;

	cout << SizeClass::RoundUp(129) << endl;
	cout << SizeClass::RoundUp(1023) << endl;
	cout << endl;

	cout << SizeClass::RoundUp(1025) << endl;
	cout << SizeClass::RoundUp(8 * 1024 - 1) << endl;
	cout << endl;

	cout << SizeClass::RoundUp(8 * 1024 + 1) << endl;
	cout << SizeClass::RoundUp(64 * 1024 - 1) << endl;
	cout << endl << endl;

	cout << SizeClass::Index(1) << endl;
	cout << SizeClass::Index(128) << endl;
	cout << endl;

	cout << SizeClass::Index(129) << endl;
	cout << SizeClass::Index(1023) << endl;
	cout << endl;

	cout << SizeClass::Index(1025) << endl;
	cout << SizeClass::Index(8 * 1024 - 1) << endl;
	cout << endl;

	cout << SizeClass::Index(8 * 1024 + 1) << endl;
	cout << SizeClass::Index(64 * 1024 - 1) << endl;
	cout << endl;
	void* ptr = SystemAlloc(MAX_PAGES - 1);
	PAGE_ID id = (PAGE_ID)ptr >> PAGE_SHIFT;
	void* ptrshift = (void*)(id << PAGE_SHIFT);

	char* obj1 = (char*)ptr;
	char* obj2 = (char*)ptr + 8;
	char* obj3 = (char*)ptr + 16;
	PAGE_ID id1 = (PAGE_ID)obj1 >> PAGE_SHIFT;
	PAGE_ID id2 = (PAGE_ID)obj2 >> PAGE_SHIFT;
	PAGE_ID id3 = (PAGE_ID)obj3 >> PAGE_SHIFT;
}
void func2()
{
	std::vector<void*> v;
	size_t size = 7;
	for (size_t i = 0; i < 512; ++i)
	{
		v.push_back(ConcurrencyMalloc(size));
	}

	v.push_back(ConcurrencyMalloc(size));


	for (size_t i = 0; i < v.size(); ++i)
	{
		//printf("[%d]->%p\n", i, v[i]);
	}

	for (auto ptr : v)
	{
		ConcurrencyFree(ptr);
	}

	v.clear();
}

//int main()
//{
//	func2();
//	system("pause");
//	return 0;
//}
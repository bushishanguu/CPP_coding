#define _CRT_SECURE_NO_WARNINGS 1


void TestString()
{
	string s1;                // ����յ�string�����s1    
	string s2("hello bit");   // ��C��ʽ�ַ�������string�����s2    
	string s3(s2);            // ��������s3
}
	// size/clear/resize void 
TestString1() 
{    // ע�⣺string�����֧��ֱ����cin��cout������������
	string s("hello, bit!!!"); 
	cout << s.size() << endl;    
	cout << s.length() << endl;    
	cout << s.capacity() << endl;    
	cout << s << endl;        
	// ��s�е��ַ�����գ�ע�����ʱֻ�ǽ�size��0�����ı�ײ�ռ�Ĵ�С    
	s.clear();    
	cout << s.size() << endl;    
	cout << s.capacity() << endl;

	// ��s����Ч�ַ��������ӵ�10�������λ����'a'�������    
	// ��aaaaaaaaaa��    
	s.resize(10, 'a');    
	cout << s.size() << endl;    
	cout << s.capacity() << endl;

	// ��s����Ч�ַ��������ӵ�15�������λ����ȱʡֵ'\0'�������   

	// "aaaaaaaaaa\0\0\0\0\0"    
	// ע���ʱs����Ч�ַ������Ѿ����ӵ�15��    
	s.resize(15);    
	cout << s.size() << endl;    
	cout << s.capacity() << endl;    
	cout << s << endl;

	// ��s����Ч�ַ�������С��5��    
	s.resize(5);    
	cout << s.size() << endl;    
	cout << s.capacity() << endl;    
	cout << s << endl; 
}

#define _CRT_SECURE_NO_WARNINGS 1


void TestString()
{
	string s1;                // 构造空的string类对象s1    
	string s2("hello bit");   // 用C格式字符串构造string类对象s2    
	string s3(s2);            // 拷贝构造s3
}
	// size/clear/resize void 
TestString1() 
{    // 注意：string类对象支持直接用cin和cout进行输入和输出
	string s("hello, bit!!!"); 
	cout << s.size() << endl;    
	cout << s.length() << endl;    
	cout << s.capacity() << endl;    
	cout << s << endl;        
	// 将s中的字符串清空，注意清空时只是将size清0，不改变底层空间的大小    
	s.clear();    
	cout << s.size() << endl;    
	cout << s.capacity() << endl;

	// 将s中有效字符个数增加到10个，多出位置用'a'进行填充    
	// “aaaaaaaaaa”    
	s.resize(10, 'a');    
	cout << s.size() << endl;    
	cout << s.capacity() << endl;

	// 将s中有效字符个数增加到15个，多出位置用缺省值'\0'进行填充   

	// "aaaaaaaaaa\0\0\0\0\0"    
	// 注意此时s中有效字符个数已经增加到15个    
	s.resize(15);    
	cout << s.size() << endl;    
	cout << s.capacity() << endl;    
	cout << s << endl;

	// 将s中有效字符个数缩小到5个    
	s.resize(5);    
	cout << s.size() << endl;    
	cout << s.capacity() << endl;    
	cout << s << endl; 
}

#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


class String;//������

	ostream& operator<<(ostream &out, const String &s);
    istream& operator>>(istream &in, String &s);//���������


class String
{
	friend ostream& operator<<(ostream &out,const String &s);
	friend istream& operator>>(istream &in, String &s);

public:
	String(const char *str = NULL)
	{
		if (str == NULL)
		{
			m_data = new char[1];
			m_data[0] = '\0';
		}
		else
		{
			m_data = new char[strlen(str) + 1];
			strcpy(m_data, str);
		}
	}
	String(const String &s)
	{
		m_data = new char[strlen(s.m_data) + 1];
		strcpy(m_data, s.m_data);
	}

	String& operator=(const String &s)
	{
		if (this != &s)
		{
			free(m_data);
			m_data = new char[strlen(s.m_data) + 1];
			strcpy(m_data, s.m_data);
		}
		return *this;
	}

	~String()
	{
		delete[]m_data;
		m_data = NULL;
	}

	String operator+(const String &s)       //s1+s2
	{
		char *p = new char[strlen(m_data) + strlen(s.m_data) + 1];
		strcpy(p, m_data);
		strcat(p, s.m_data);
		String tmp(p);
		delete[]p;
		return tmp;
	}

	String operator+=(const String &s)        //s1+=s2
	{
		char *p = m_data;
		p = new char[strlen(m_data) + strlen(s.m_data) + 1];
		strcpy(p, m_data);
		strcat(p, s.m_data);
		String tmp(p);
		delete []p;
		return tmp;
	}

	char& operator[](int index)        //�����±������
	{
		return m_data[index];
	}

	bool operator==(String &s)         //s1=s2
	{
		if (strcmp(m_data, s.m_data) == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator != (String &s)         //s1!=s2
	{
		if (strcmp(m_data, s.m_data) != 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator>(String &s)    //s1>s2
	{
		if (strcmp(m_data, s.m_data) > 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}


	bool operator<=(String &s)    //s1<=s2
	{
		if (strcmp(m_data, s.m_data) <= 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	

	bool operator<(String &s)    //s1<s2
	{
		if (strcmp(m_data, s.m_data) < 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator>=(String &s)   //s1>=s2
	{
		if (strcmp(m_data, s.m_data) >= 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}



private:    //˽�г�Ա
	char *m_data;
};


ostream& operator<<(ostream &out, const String &s)
{
	out << s.m_data;
	return out;
}

istream& operator>>(istream &in, String &s)
{
	in >> s.m_data;
	return in;
}


void main()    //���Ժ���
{
	String s1("hello");
	String s2("world");
	String s3 = s1 + s2;
	String s;
	s = s1 += s2;
	cout << s1[0] << endl;
	cout << s1 << endl;
	cout << s3 << endl;
	cout << s << endl;

	String s4("helloworld");
	String s5("helloworld");
	String s6("hello");
	String s7("hi");

	if (s4 == s5)
	{
		cout << "s4��s5���!" << endl;
	}
	else
	{
		cout << "s4��s5�����!" << endl;
	}
	if (s4 > s7)
	{
		cout << "s4����s7!" << endl;
	}
	else if (s4 < s7)
	{
		cout << "s4С��s7!" << endl;
	}
	else
	{
		cout << "s4����s7!" << endl;
	}
	if (s4 >= s6)
	{
		cout << "s4�����s6!" << endl;
	}
	else if (s4 <= s6)
	{
		cout << "s4С����s7!" << endl;
	}

	system("pause");
	
}

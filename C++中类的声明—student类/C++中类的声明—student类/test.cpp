#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class Student // Student�������
{ 
public: // ���г�Ա 
	Student(); // ���캯�� 
	~Student(); // ��������
	char* GetName(); // ��ѯ����
	int GetAge(); // ��ѯ���� 
	char GetSex(); // ��ѯ���� 
	int GetNumber(); // ��ѯѧ��
    bool SetName(char* n); // �������� 
    bool SetAge(int age); // �������� 
    bool SetSex(char* s); // �����Ա� 
    bool SetNumber(int num);// ����ѧ�� 
protected: // ������Ա 
	char m_strName[20]; // �������ַ������� 
	int m_nAge; // ���䣬���� 
	char m_cSex; // �Ա��ַ��� 
	int m_nNumber; // ѧ�ţ����� 
};

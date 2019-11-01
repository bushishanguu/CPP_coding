#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class Student // Student类的声明
{ 
public: // 公有成员 
	Student(); // 构造函数 
	~Student(); // 析构函数
	char* GetName(); // 查询姓名
	int GetAge(); // 查询年龄 
	char GetSex(); // 查询姓名 
	int GetNumber(); // 查询学号
    bool SetName(char* n); // 设置姓名 
    bool SetAge(int age); // 设置年龄 
    bool SetSex(char* s); // 设置性别 
    bool SetNumber(int num);// 设置学号 
protected: // 保护成员 
	char m_strName[20]; // 姓名，字符串数组 
	int m_nAge; // 年龄，整型 
	char m_cSex; // 性别，字符型 
	int m_nNumber; // 学号，整型 
};

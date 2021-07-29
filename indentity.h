#pragma once
#include<iostream>
using namespace std;

//身份抽象基類
class Identity {
public:

	//操作菜單 純虛函數
	virtual void operMenu() = 0;

	//用戶名
	string m_Name;


	//密碼
	string m_Pwd;





};


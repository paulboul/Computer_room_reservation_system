#pragma once
#include<iostream>
#include "indentity.h"
using namespace std;
#include<string>
#include "orderFile.h"
#include<vector>

class Teacher :public Identity {
public:
	//默認構造
	Teacher();

	//有參構造
	Teacher(int empId,string name,string pwd);

	//菜單介面
	virtual void operMenu();

	//查看所有預約
	void showAllOrder();


	//審核預約
	void validOrder();


	//職工號
	int m_EmpId;


};

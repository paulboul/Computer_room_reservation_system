#pragma once
#include<iostream>
#include "indentity.h"
using namespace std;
#include<string>
#include "orderFile.h"
#include<vector>

class Teacher :public Identity {
public:
	//�q�{�c�y
	Teacher();

	//���Ѻc�y
	Teacher(int empId,string name,string pwd);

	//��椶��
	virtual void operMenu();

	//�d�ݩҦ��w��
	void showAllOrder();


	//�f�ֹw��
	void validOrder();


	//¾�u��
	int m_EmpId;


};

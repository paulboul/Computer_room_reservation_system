#pragma once
#include<iostream>
using namespace std;
#include "indentity.h"
#include<string>
#include<vector>
#include "computerRoom.h"
#include <fstream>
#include "globalFile.h"
#include "orderFile.h"
//�ǥ���
class Student :public Identity {

public:

	//�q�{�c�y
	Student();
	
	//���Ѻc�y �Ѽ�: �Ǹ� �m�W �K�X
	Student(int id,string name,string pwd);
	
	//��椶��
	virtual void operMenu() ;

	//�ӽйw��
	void applyOrder();
	
	//�d�ݦۨ��w��
	void showMyOrder();

	//�d�ݩҦ��w��
	void showAllOrder();

	
	//�����w��
	void cancelOrder();

	//�ǥ;Ǹ�
	int m_Id;

	
	//���Юe��
	vector<ComputerRoom> vCom;

};


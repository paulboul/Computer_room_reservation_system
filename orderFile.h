#pragma once
#include<iostream>
using namespace std;
#include<fstream>
#include "globalFile.h"
#include<map>
#include<string>

class OrderFile {
public:

	//�c�y���
	OrderFile();

	//��s�w������
	void updateOrder();

	//��s�w���O��
	int m_Size;

	//�O���Ҧ��H�����e��  key�������� value��������w���H��
	map<int, map<string, string>>m_orderData;

	


};


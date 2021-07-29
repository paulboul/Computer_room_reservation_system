#pragma once
#include<iostream>
using namespace std;
#include<fstream>
#include "globalFile.h"
#include<map>
#include<string>

class OrderFile {
public:

	//構造函數
	OrderFile();

	//更新預約紀錄
	void updateOrder();

	//更新預約記錄
	int m_Size;

	//記錄所有信息的容器  key紀錄條數 value具體紀錄預約信息
	map<int, map<string, string>>m_orderData;

	


};


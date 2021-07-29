#pragma once
#include<iostream>
using namespace std;
#include<string>
#include "indentity.h"
#include<fstream>
#include "globalFile.h"
#include "student.h"
#include "teacher.h"
#include<vector>
#include<algorithm>
#include "computerRoom.h"

class Manager :public Identity {
public:


	//默認構造
	Manager();

	//有參構造 
	Manager(string name, string pwd);
	
	//菜單介面
	virtual void operMenu();
	
	//添加帳號
	void addPerson();
	
	//查看帳號
	void showPerson();
	
	//查看機房信息
	void showComputer();

	
	//清空預約紀錄
	void cleanFile();

	//初始化容器
	void initVecotr();

	//檢測重複      //學號職工號  //學生老師
	bool checkRepeat(int id, int type);

	//學生容器
	vector<Student>vStu;

	//老師容器
	vector<Teacher> vTea;

	//機房信息容器
	vector<ComputerRoom>vCom;
};

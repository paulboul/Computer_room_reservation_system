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


	//�q�{�c�y
	Manager();

	//���Ѻc�y 
	Manager(string name, string pwd);
	
	//��椶��
	virtual void operMenu();
	
	//�K�[�b��
	void addPerson();
	
	//�d�ݱb��
	void showPerson();
	
	//�d�ݾ��ЫH��
	void showComputer();

	
	//�M�Źw������
	void cleanFile();

	//��l�Ʈe��
	void initVecotr();

	//�˴�����      //�Ǹ�¾�u��  //�ǥͦѮv
	bool checkRepeat(int id, int type);

	//�ǥͮe��
	vector<Student>vStu;

	//�Ѯv�e��
	vector<Teacher> vTea;

	//���ЫH���e��
	vector<ComputerRoom>vCom;
};

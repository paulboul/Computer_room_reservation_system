#include<iostream>
#include "indentity.h"
#include "globalFile.h"
#include<fstream>
#include<string>
#include "student.h"
#include "teacher.h"
#include "manager.h"
using namespace std;
//進入老師子菜單介面
void TeacherMenu(Identity*& teacher) {

	while (true) {

		//調用子菜單介面
		teacher->operMenu();

		Teacher* tea = (Teacher*)teacher;

		int select = 0;//接受用戶選擇

		cin >> select;

		if (select == 1) {//查看所有預約
			tea->showAllOrder();
		}
		else if (select == 2) {//審核預約
			tea->validOrder();
		}
		else {
			delete teacher;
			cout << "註銷成功" << endl;
			system("pause");
			system("cls");
			return;
			
		}


	}

}






//進入學生子菜單介面
void studentMenu(Identity*& student) {

	while (true) {

		//調用學生子菜單
		student->operMenu();

		Student* stu = (Student*)student;

		int select = 0;
		cin >> select;//接受用戶選擇

		if (select == 1) {//申請預約
			stu->applyOrder();

		}
		else if (select == 2) {//查看自身預約
			stu->showMyOrder();
		}
		else if (select == 3) {//查看所有預約
			stu->showAllOrder();
		}
		else if (select == 4) {//取消預約
			stu->cancelOrder();
		}
		else {
			//註銷登錄
			delete student;
			cout << "註銷成功" << endl;
			system("pause");
			system("cls");
			return;
		}


	}

}

//進入管理員子菜單介面
void managerMenu(Identity*& manager) {

	while (true) {

		//調用管理員子菜單
		manager->operMenu();

		//將父類指針轉為子類指針,調用子類裡其他接口
		Manager* man = (Manager*)manager;

		int select = 0;
		//接受用戶選擇
		cin >> select;

		if (select == 1) {//添加帳號
			//cout << "添加帳號" << endl;
			man->addPerson();
		}
		else if (select == 2) {//查看帳號
			//cout << "查看帳號" << endl;
			man->showPerson();
		}
		else if (select == 3) {//查看機房
			//cout << "查看機房" << endl;
			man->showComputer();
		}
		else if (select == 4) {//清空預約
			//cout << "清空預約" << endl;
			man->cleanFile();
		}
		else {
			//註銷
			delete manager;//銷毀掉堆區對象
			cout << "註銷成功" << endl;
			system("pause");
			system("cls");
			return;

		}


	}

}

//登錄功能     操作文件名       操作身份類型
void LoginIn(string fileName, int type) {
	
	//父類指針,用於指向子類對象
	Identity* person = NULL;


	//讀文件
	ifstream ifs;
	ifs.open(fileName, ios::in);

	//判斷文件是否存在
	if (!ifs.is_open()) {
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}

	//準備接收用戶信息
	int id = 0;
	string name;
	string pwd;

	//判斷身份
	if (type == 1) {//學生身份
		cout << "請輸入你的學號: " << endl;
		cin >> id;

	}
	else if (type == 2) {//老師身份
		cout << "請輸入你的職工號: " << endl;
		cin >> id;
	}

	cout << "請輸入用戶名: " << endl;
	cin >> name;

	cout << "請輸入密碼: " << endl;
	cin >> pwd;

	if (type == 1) {
		//學生身份驗證
		int fId;//從文件讀取的id號
		string fName;//從文件讀取的姓名
		string fPwd;//從文件讀取的密碼
		
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			
			if (fId == id && fName == name && fPwd == pwd) {
				cout << "學生驗證錄成功!" << endl;
				system("pause");
				system("cls");
				person = new Student(id,name,pwd);
				
				//進入到學生身份子菜單
				studentMenu(person);

				return;

			}
		}
	}
	else if (type == 2) {
		//老師身份驗證

		int fId;//從文件讀取的id號
		string fName;//從文件讀取的姓名
		string fPwd;//從文件讀取的密碼
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {

			if (fId == id && fName == name && fPwd == pwd) {
				cout << "老師驗證錄成功!" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//進入到老師身份子菜單
				TeacherMenu(person);

				return;

			}

		}
	}
	else if (type == 3) {
		//管理員身份驗證

		string fName;//從文件讀取的姓名
		string fPwd;//從文件讀取的密碼
		while (ifs >> fName && ifs >> fPwd) {

			if (fName == name && fPwd == pwd) {
				cout << "管理員驗證錄成功!" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				//進入到管理員身份子菜單
				managerMenu(person);

				return;

			}


		}
	}

	cout << "驗證登錄失敗!" << endl;
	system("pause");
	system("cls");

	return;

}
int main() {

	int select = 0;///接收用戶選擇
	while (true) {
		cout << "=========================== 歡迎來到傳智播客機房預約系統 ===========================" << endl;
		cout << endl << "請輸入你的身分" << endl;
		cout << "\t\t -----------------------------------\n";
		cout << "\t\t|                                   |\n";
		cout << "\t\t|          1.學生代表               |\n";
		cout << "\t\t|                                   |\n";
		cout << "\t\t|          2.老    師               |\n";
		cout << "\t\t|                                   |\n";
		cout << "\t\t|          3.管 理 員               |\n";
		cout << "\t\t|                                   |\n";
		cout << "\t\t|          0.退    出               |\n";
		cout << "\t\t|                                   |\n";
		cout << "\t\t -----------------------------------\n";
		cout << "輸入你的選擇: ";

		cin >> select;//接受用戶選擇

		switch (select) {//根據用戶選擇 實現不同接口

		case 1://學生
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2://老師 
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3://管理員
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0://退出系統
			cout << "歡迎下一次使用" << endl;
			system("pause");
			return 0;
			break;


		default:
			cout << "輸入有誤,請重新輸入!" << endl;
			system("pause");
			system("cls");
			break;

		}

	}











	return 0;
}
#include<iostream>
#include "indentity.h"
#include "globalFile.h"
#include<fstream>
#include<string>
#include "student.h"
#include "teacher.h"
#include "manager.h"
using namespace std;
//�i�J�Ѯv�l��椶��
void TeacherMenu(Identity*& teacher) {

	while (true) {

		//�եΤl��椶��
		teacher->operMenu();

		Teacher* tea = (Teacher*)teacher;

		int select = 0;//�����Τ���

		cin >> select;

		if (select == 1) {//�d�ݩҦ��w��
			tea->showAllOrder();
		}
		else if (select == 2) {//�f�ֹw��
			tea->validOrder();
		}
		else {
			delete teacher;
			cout << "���P���\" << endl;
			system("pause");
			system("cls");
			return;
			
		}


	}

}






//�i�J�ǥͤl��椶��
void studentMenu(Identity*& student) {

	while (true) {

		//�եξǥͤl���
		student->operMenu();

		Student* stu = (Student*)student;

		int select = 0;
		cin >> select;//�����Τ���

		if (select == 1) {//�ӽйw��
			stu->applyOrder();

		}
		else if (select == 2) {//�d�ݦۨ��w��
			stu->showMyOrder();
		}
		else if (select == 3) {//�d�ݩҦ��w��
			stu->showAllOrder();
		}
		else if (select == 4) {//�����w��
			stu->cancelOrder();
		}
		else {
			//���P�n��
			delete student;
			cout << "���P���\" << endl;
			system("pause");
			system("cls");
			return;
		}


	}

}

//�i�J�޲z���l��椶��
void managerMenu(Identity*& manager) {

	while (true) {

		//�եκ޲z���l���
		manager->operMenu();

		//�N�������w�ର�l�����w,�եΤl���̨�L���f
		Manager* man = (Manager*)manager;

		int select = 0;
		//�����Τ���
		cin >> select;

		if (select == 1) {//�K�[�b��
			//cout << "�K�[�b��" << endl;
			man->addPerson();
		}
		else if (select == 2) {//�d�ݱb��
			//cout << "�d�ݱb��" << endl;
			man->showPerson();
		}
		else if (select == 3) {//�d�ݾ���
			//cout << "�d�ݾ���" << endl;
			man->showComputer();
		}
		else if (select == 4) {//�M�Źw��
			//cout << "�M�Źw��" << endl;
			man->cleanFile();
		}
		else {
			//���P
			delete manager;//�P������Ϲ�H
			cout << "���P���\" << endl;
			system("pause");
			system("cls");
			return;

		}


	}

}

//�n���\��     �ާ@���W       �ާ@��������
void LoginIn(string fileName, int type) {
	
	//�������w,�Ω���V�l����H
	Identity* person = NULL;


	//Ū���
	ifstream ifs;
	ifs.open(fileName, ios::in);

	//�P�_���O�_�s�b
	if (!ifs.is_open()) {
		cout << "��󤣦s�b" << endl;
		ifs.close();
		return;
	}

	//�ǳƱ����Τ�H��
	int id = 0;
	string name;
	string pwd;

	//�P�_����
	if (type == 1) {//�ǥͨ���
		cout << "�п�J�A���Ǹ�: " << endl;
		cin >> id;

	}
	else if (type == 2) {//�Ѯv����
		cout << "�п�J�A��¾�u��: " << endl;
		cin >> id;
	}

	cout << "�п�J�Τ�W: " << endl;
	cin >> name;

	cout << "�п�J�K�X: " << endl;
	cin >> pwd;

	if (type == 1) {
		//�ǥͨ�������
		int fId;//�q���Ū����id��
		string fName;//�q���Ū�����m�W
		string fPwd;//�q���Ū�����K�X
		
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			
			if (fId == id && fName == name && fPwd == pwd) {
				cout << "�ǥ����ҿ����\!" << endl;
				system("pause");
				system("cls");
				person = new Student(id,name,pwd);
				
				//�i�J��ǥͨ����l���
				studentMenu(person);

				return;

			}
		}
	}
	else if (type == 2) {
		//�Ѯv��������

		int fId;//�q���Ū����id��
		string fName;//�q���Ū�����m�W
		string fPwd;//�q���Ū�����K�X
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {

			if (fId == id && fName == name && fPwd == pwd) {
				cout << "�Ѯv���ҿ����\!" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//�i�J��Ѯv�����l���
				TeacherMenu(person);

				return;

			}

		}
	}
	else if (type == 3) {
		//�޲z����������

		string fName;//�q���Ū�����m�W
		string fPwd;//�q���Ū�����K�X
		while (ifs >> fName && ifs >> fPwd) {

			if (fName == name && fPwd == pwd) {
				cout << "�޲z�����ҿ����\!" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				//�i�J��޲z�������l���
				managerMenu(person);

				return;

			}


		}
	}

	cout << "���ҵn������!" << endl;
	system("pause");
	system("cls");

	return;

}
int main() {

	int select = 0;///�����Τ���
	while (true) {
		cout << "=========================== �w��Ө�Ǵ����Ⱦ��йw���t�� ===========================" << endl;
		cout << endl << "�п�J�A������" << endl;
		cout << "\t\t -----------------------------------\n";
		cout << "\t\t|                                   |\n";
		cout << "\t\t|          1.�ǥͥN��               |\n";
		cout << "\t\t|                                   |\n";
		cout << "\t\t|          2.��    �v               |\n";
		cout << "\t\t|                                   |\n";
		cout << "\t\t|          3.�� �z ��               |\n";
		cout << "\t\t|                                   |\n";
		cout << "\t\t|          0.�h    �X               |\n";
		cout << "\t\t|                                   |\n";
		cout << "\t\t -----------------------------------\n";
		cout << "��J�A�����: ";

		cin >> select;//�����Τ���

		switch (select) {//�ھڥΤ��� ��{���P���f

		case 1://�ǥ�
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2://�Ѯv 
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3://�޲z��
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0://�h�X�t��
			cout << "�w��U�@���ϥ�" << endl;
			system("pause");
			return 0;
			break;


		default:
			cout << "��J���~,�Э��s��J!" << endl;
			system("pause");
			system("cls");
			break;

		}

	}











	return 0;
}
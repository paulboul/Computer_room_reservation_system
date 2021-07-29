#include "teacher.h"


//�q�{�c�y
Teacher::Teacher() {

}

//���Ѻc�y
Teacher::Teacher(int empId, string name, string pwd) {
	this->m_Name = name;
	this->m_EmpId = empId;
	this->m_Pwd = pwd;
}

//��椶��
void  Teacher::operMenu() {
	cout << "�w��Юv: " << this->m_Name << "�n��! " << endl;
	cout << "\t\t -----------------------------------\n";
	cout << "\t\t|                                   |\n";
	cout << "\t\t|          1.�d�ݩҦ��w��           |\n";
	cout << "\t\t|                                   |\n";
	cout << "\t\t|          2.�f�ֹw��               |\n";
	cout << "\t\t|                                   |\n";
	cout << "\t\t|          0.�h�X�n��               |\n";
	cout << "\t\t|                                   |\n";
	cout << "\t\t -----------------------------------\n";
	cout << "�п�ܧA���ާ@: ";


 }

//�d�ݩҦ��w��
void Teacher::showAllOrder() {
	OrderFile of;
	if (of.m_Size == 0) {
		cout << "�L�w������" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_Size; i++) {
		cout << i + 1 << ", ";
		cout << "�w�����:  �P" << of.m_orderData[i]["date"];
		cout << " �ɶ��q: " << (of.m_orderData[i]["interval"] == "1" ? "�W��" : "�U��");
		cout << " �Ǹ�: " << of.m_orderData[i]["stuId"];
		cout << " �m�W: " << of.m_orderData[i]["stuName"];
		cout << " ���и�: " << of.m_orderData[i]["roomId"] << " ";

		string status = "���A";
		//1.�f�֤� 2.�w�w�� -1�w������ 0�����w��
		if (of.m_orderData[i]["status"] == "1") {
			status += "�f�֤�";
		}
		else if (of.m_orderData[i]["status"] == "2") {
			status += "�w�w��";
		}
		else if (of.m_orderData[i]["status"] == "-1") {
			status += "�w������,�f�֥��q�L";
		}
		else {
			status += "�w���w����";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");
}


//�f�ֹw��
void Teacher::validOrder() {

	OrderFile of;
	if (of.m_Size == 0) {
		cout << "�L�w������" << endl;
		system("pause");
		system("cls");
		return;
	}
	vector<int>v;
	int index = 0;
	cout << "�ݼf�֪��w���O���p�U: " << endl;

	for (int i = 0; i < of.m_Size; i++) {
		if (of.m_orderData[i]["status"] == "1") {

			v.push_back(i);
			cout << ++index << ", ";
			cout << "�w�����:  �P" << of.m_orderData[i]["date"];
			cout << " �ɶ��q: " << (of.m_orderData[i]["interval"] == "1" ? "�W��" : "�U��");
			cout << " �Ǹ�: " << of.m_orderData[i]["stuId"];
			cout << " �m�W: " << of.m_orderData[i]["stuName"];
			cout << " ���и�: " << of.m_orderData[i]["roomId"] << " ";
			string status = "���A: �f�֤�";
			cout << status << endl;

		}
	}

	cout << "�п�J�f�֪��w���O��,0�N���^" << endl;

	int select=0;//�����Τ��ܪ��w������
	int ret = 0;//�����w�����G�O��

	while (true) {

		cin >> select;

		if (select >= 0 && select <= v.size()) {
			
			if (select == 0) {
				break;
			}
			else {
				cout << "�п�J�f�ֵ��G" << endl;
				cout << "1.�q�L" << endl;
				cout << "2.���q�L" << endl;
				cin >> ret;
				if (ret == 1) {
					//�q�L
					of.m_orderData[v[select - 1]]["status"] = "2";
				}
				else {
					//���q�L
					of.m_orderData[v[select - 1]]["status"] = "-1";
				}
				of.updateOrder();//��s����
				cout << "�f�֧���" << endl;
				break;
			}

		}
		
		cout << "��J���~,�Э��s��J" << endl;

	}
	system("pause");
	system("cls");

}
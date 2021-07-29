#include "student.h"

//�q�{�c�y
Student::Student() {

}

//���Ѻc�y �Ѽ�: �Ǹ� �m�W �K�X
Student::Student(int id, string name, string pwd) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;
	//��l�ƾ��ЫH��

	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	ComputerRoom com;
	while (ifs >> com.m_ComId && ifs >> com.m_MaxNum) {
		
		//�NŪ�����H����J��e��
		vCom.push_back(com);

	}
	ifs.close();
}

//��椶��
void Student::operMenu() {
	cout << "�w��ǥͥN��: " << this->m_Name << "�n��! " << endl;
	cout << "\t\t -----------------------------------\n";
	cout << "\t\t|                                   |\n";
	cout << "\t\t|          1.�ӽйw��               |\n";
	cout << "\t\t|                                   |\n";
	cout << "\t\t|          2.�d�ݦۨ��w��           |\n";
	cout << "\t\t|                                   |\n";
	cout << "\t\t|          3.�d�ݩҦ��w��           |\n";
	cout << "\t\t|                                   |\n";
	cout << "\t\t|          4.�����w��               |\n";
	cout << "\t\t|                                   |\n";
	cout << "\t\t|          0.�h�X�n��               |\n";
	cout << "\t\t|                                   |\n";
	cout << "\t\t -----------------------------------\n";
	cout << "�п�ܧA���ާ@: ";
}

//�ӽйw��
void Student::applyOrder() {

	cout << "���ж}��ɶ����P�@��P��!" << endl;
	cout << "�п�J�ӽйw�����ɶ�" << endl;
	cout << "1.�P�@" << endl;
	cout << "2.�g�G" << endl;
	cout << "3.�P�T" << endl;
	cout << "4.�g�|" << endl;
	cout << "5.�g��" << endl;

	int date = 0;//���
	int interval = 0;//�ɶ��q
	int room = 0;//���нs��

	while (true) {

		cin >> date;
		if (date >= 1 && date <= 5) {
			break;
		}
		cout << "��J���~,�Э��s��J" << endl;

	}
	cout << "�ФJ�ӽйw���ɶ��q" << endl;
	cout << "1. �W��" << endl;
	cout << "2. �U��" << endl;

	while (true) {
		cin >> interval;
		if (interval >= 1 && interval <= 2) {
			break;
		}
		cout << "��J���~,�Э��s��J" << endl;

	}

	cout << "�п�ܾ���: " << endl;
	for (int i = 0; i < vCom.size(); i++) {
		cout << vCom[i].m_ComId << "�����Юe�q: " << vCom[i].m_MaxNum << endl;
	}
	while (true) {
		cin >> room;
		if (room >= 1 && room <= 3) {
			break;
		}
		cout << "��J���~,�Э��s��J" << endl;
	}


	cout << "�w�����\!�f�֤�" << endl;

	ofstream ofs;
	ofs.open(ORDER_FILE, ios::app);

	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuId:" << this->m_Id << " ";
	ofs << "stuName:" << this->m_Name << " ";
	ofs << "roomId:" << room << " ";
	ofs << "status:" << 1 << endl;
	
	ofs.close();

	system("pause");
	system("cls");



}

//�d�ݦۨ��w��
void Student::showMyOrder() {
	OrderFile  of;

	if (of.m_Size == 0) {
		cout << "�L�w������" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_Size; i++) {
		//string �� int
		if (this->m_Id == atoi(of.m_orderData[i]["stuId"].c_str())) {//���ۨ��w��
			cout << "�w�����:  �P" << of.m_orderData[i]["date"];
			cout << " �ɶ��q: " << (of.m_orderData[i]["interval"] == "1" ? "�W��" : "�U��");
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
	}

	system("pause");
	system("cls");


}
//�d�ݩҦ��w��
void  Student::showAllOrder() {
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

//�����w��
void Student::cancelOrder(){

	OrderFile of;
	if (of.m_Size == 0) {
		cout << "�L�w������" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "�f�֤��ιw�����\�������i�H�����A�п�J��������" << endl;
	vector<int>v;	//�s��b�̤j�e�������U�нs��


	int index = 1;
	for (int i = 0; i < of.m_Size; i++) {
		//���P�_�ܦۨ��Ǹ�
		if (this->m_Id == atoi(of.m_orderData[i]["stuId"].c_str())) {
			string status = "���A";
			//�A�z�窱�A �f�֤��ιw�����\
			if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2") {

				v.push_back(i);
				cout << index++ << ", ";
				cout << "�w�����:  �P" << of.m_orderData[i]["date"];
				cout << " �ɶ��q: " << (of.m_orderData[i]["interval"] == "1" ? "�W��" : "�U��");
				cout << " ���и�: " << of.m_orderData[i]["roomId"] << " ";

				if (of.m_orderData[i]["status"] == "1") {
					status += "�f�֤�";
				}
				else if (of.m_orderData[i]["status"] == "2") {
					status += "�w�����\";
				}
				cout << status << endl;

			}

		}

	}
	cout << "�п�J�����O��,0�N���^" << endl;
	int select = 0;

	while (true) {
		cin >> select;

		if (select >= 0 && select <= v.size()) {

			if (select == 0) {
				break;
			}
			else {
				of.m_orderData[v[select - 1]]["status"] = "0";

				of.updateOrder();

				cout << "�w�����w��" << endl;
				break;
			}


		}
		else {
			cout << "��J���~,�Э��s��J" << endl;
		}
	}

	system("pause");
	system("cls");
}
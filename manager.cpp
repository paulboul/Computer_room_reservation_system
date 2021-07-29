#include "manager.h"


//�q�{�c�y
Manager::Manager() {
	
}

//���Ѻc�y 
Manager::Manager(string name, string pwd) {
	//��l�ƺ޲z���H��
	this->m_Name = name;
	this->m_Pwd = pwd;

	//��l�Ʈe�������Ҧ����,�ǥ�,�Ѯv�H��

	this->initVecotr();

	//��l�ƾ��ЫH��
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom com;
	while (ifs >> com.m_ComId && ifs >> com.m_MaxNum) {
		vCom.push_back(com);

	}
	ifs.close();
	cout << "���Ъ��ƶq: " << vCom.size() << endl;
}

//��椶��
void Manager::operMenu() {
	cout << "�w��޲z��: " << this->m_Name << "�n��! " << endl;
	cout << "\t\t -----------------------------------\n";
	cout << "\t\t|                                   |\n";
	cout << "\t\t|          1.�K�[�b��               |\n";
	cout << "\t\t|                                   |\n";
	cout << "\t\t|          2.�d�ݱb��               |\n";
	cout << "\t\t|                                   |\n";
	cout << "\t\t|          3.�d�ݾ���               |\n";
	cout << "\t\t|                                   |\n";
	cout << "\t\t|          4.�M�Źw��               |\n";
	cout << "\t\t|                                   |\n";
	cout << "\t\t|          0.�h�X�n��               |\n";
	cout << "\t\t|                                   |\n";
	cout << "\t\t -----------------------------------\n";
	cout << "�п�ܧA���ާ@: ";
}

//�K�[�b��
void Manager::addPerson() {

	cout << "�п�J�K�[�b������" << endl;
	cout << "1.�K�[�ǥ�" << endl;
	cout << "2.�K�[�Ѯv" << endl;

	string fileName;//�ާ@���W
	string tip;//����id��
	string errorTip;//���ƿ��~����

	ofstream ofs;//���ާ@��H

	int select = 0;
	cin >> select;

	if (select == 1) {
		//�K�[���O�ǥ�
		fileName = STUDENT_FILE;
		tip = "�п�J�Ǹ�: ";
		errorTip = "�Ǹ�����,�Э��s��J";
	}
	else {
		fileName = TEACHER_FILE;
		tip = "�п�J¾�u�s��: ";
		errorTip = "¾�u�s������,�Э��s��J";
	}

	//�ΰl�[�覡�g���
	ofs.open(fileName, ios::out | ios::app);

	int id;//�Ǹ� ¾�u�s��
	string name;//�m�W
	string pwd;//�K�X



	cout << tip << endl;
	while (true) {

		cin >> id;
		bool ret = checkRepeat(id, select);
		if (ret) {//������
			cout << errorTip << endl;

		}
		else {
			break;
		}

	}

	cout << "�п�J�m�W: " << endl;
	cin >> name;

	cout << "�п�J�K�X: " << endl;
	cin >> pwd;

	//�V��󤤲K�[�ƾ�
	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "�K�[���\" << endl;

	system("pause");
	system("cls");

	ofs.close();

	//��l�Ʈe�����s����ƾ�

	this->initVecotr();


}
void printStudent(Student& s) {
	cout << "�Ǹ�: " << s.m_Id << " �m�W: " << s.m_Name << " �K�X: " << s.m_Pwd << endl;
}
void printTeacher(Teacher& t) {
	cout << "¾�u��: " << t.m_EmpId << " �m�W: " << t.m_Name << " �K�X: " << t.m_Pwd << endl;
}


//�d�ݱb��
void Manager::showPerson() {
	cout << "�п�ܬd�ݤ��e" << endl;
	cout << "1.�d�ݩҦ��ǥ�" << endl;
	cout << "2.�d�ݩҦ��Ѯv" << endl;

	int select = 0;//�����Τ���
	cin >> select;

	if (select == 1) {
		//�d�ݾǥ�
		cout << "�Ҧ��ǥͫH���p�U" << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);
	}
	else {
		//�d�ݦѮv
		cout << "�Ҧ��Ѯv�H���p�U" << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);

	}
	system("pause");
	system("cls");

}

//�d�ݾ��ЫH��
void Manager::showComputer() {

	cout << "���Ъ��H���p�U: " << endl;

	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++) {
		cout << "���нs��: " << it->m_ComId << " ���г̤j�e��: " << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");

}


//�M�Źw������
void Manager::cleanFile() {
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();
	cout << "�M�Ŧ��\!" << endl;
	system("pause");
	system("cls");

}


//��l�Ʈe��
void Manager::initVecotr() {

	//�T�O�e���M��
	vStu.clear();
	vTea.clear();


	//Ū���H��
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "���Ū������" << endl;
		return;
	}

	//Ū���ǥͫH��
	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd) {
		vStu.push_back(s);
	}

	cout << "��e�ǥͼƶq" << vStu.size() << endl;
	ifs.close();


	//Ū���Ѯv�H��
	ifs.open(TEACHER_FILE, ios::in);
	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd) {
		vTea.push_back(t);
	}

	cout << "��e�Ѯv�ƶq" << vTea.size() << endl;
	ifs.close();


}
//�˴�����      //�Ǹ�¾�u��  //�ǥͦѮv
bool Manager::checkRepeat(int id, int type) {

	if (type == 1) {
		//�˴��ǥ�

		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++) {

			if (id == it->m_Id) {
				return true;
			}


		}

	}
	else {

		//�˴��Ѯv
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++) {

			if (id == it->m_EmpId) {
				return true;
			}


		}
	}

	return false;

}


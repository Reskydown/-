#include "Login.h"
#include "ManagerMenu.h"
#include "Course.h"
#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;
//��ʾ�˵�
void ManagerMenu::showManagerMenu() {
	cout << "        --------------------ѧ��ѡ�ι���ϵͳ(��ʦ��)--------------------" << endl;
	cout << "        --                                                            --" << endl;
	cout << "        --                 1. ����ѧ��  2. ɾ��ѧ��                   --" << endl;
	cout << "        --                 3. �鿴ѧ��  4. ���ӿγ�                   --" << endl;
	cout << "        --                 5. ɾ���γ�  6. �鿴���пγ�               --" << endl;
	cout << "        --                 7. ������ʦ  8. �޸�ѧ����Ϣ�ͳɼ�         --" << endl;
	cout << "        --                 9. �˳�ϵͳ                                --" << endl;
	cout << "        ----------------------------------------------------------------" << endl;
	cout << "                           ������Ҫ�����ı��:" << endl;
}
//���������ŵĹ���
void ManagerMenu::handleNum(int h, Manager &m) {
	clearScreen();
	switch (h)
	{
	case 1:
		m.addStudent();
		break;
	case 2:
		m.deleteStudent();
		break;
	case 3:
		m.viewStudent();
		break;
	case 4:
		m.addCourse();
		break;
	case 5:
		m.deleteCourse();
		break;
	case 6:
		m.viewCourse();
		break;
	case 7:
		m.addTeacher();
		break;
	case 8:
		m.modifyStudent();
		break;
	case 9:
		m.writeStudent();
		m.writeCourse();
		m.writeUser();
		m.writeAdmin();
		m.writeTeacher();
		m.exitSystem();
		break;
	default:
		cout << "�����������׼���˳�" << endl;
		exitSystem();
		break;
	}
}
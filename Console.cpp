#include"Console.h"
#include"Menu.h"
#include<iostream>
#include"Login.h"
void Console::operatorNum(int h) {
	Menu m = this->menu;
	m.clearScreen();
	switch (h)
	{
	case 1:
	{
		bool hasTeacher;
		char tempUsername[20];
		char tempPassword[20];
		char username[20], password[20];
	begin1:
		cout << "����������ʺź�����:" << endl;
		m.showLogin();
		m.position(39, 2);
		cin >> username;
		ifstream is("admin.data", ios_base::in);
		while (!is.eof()) {
			is >> tempUsername >> tempPassword;
			if (strcmp(tempUsername, username) == 0) {
				hasTeacher = true;
				break;
			}
		}
		is.close();
		Login login(tempUsername, tempPassword);
		m.position(39, 4);
		cin >> password;
		Manager manager;
		if (login.isLogin(username, password))
		{
			int t;

			manager.setUsername(username);
			manager.setPassword(password);
			while (1)
			{
				m.clearScreen();
				m.getManagerMenu().showManagerMenu();
				cin >> t;
				m.clearScreen();
				m.getManagerMenu().handleNum(t, manager);
			}
		}
		else
		{
			cout << endl;
			cout << "�û����������������,����������." << endl;
			m.pauseScreen();
			m.clearScreen();
			goto begin1;
		}
		break;
	}
	case 2:
	{

		bool hasStudent;
		char tempUsername[20];
		char tempPassword[20];
		char username[20], password[20];
	begin2:
		cout << "����������ʺź�����:" << endl;
		m.showLogin();
		m.position(39, 2);
		cin >> username;
		ifstream is("user.data", ios_base::in);
		while (!is.eof()) {
			is >> tempUsername >> tempPassword;
			if (strcmp(tempUsername, username) == 0) {
				hasStudent = true;
				break;
			}
		}
		is.close();
		Login login(tempUsername, tempPassword);
		m.position(39, 4);
		cin >> password;
		if (login.isLogin(username, password))
		{
			
			int t;
			string tnum, tname, tclass;
			ofstream cu("current.data", ios_base::out);
			
			cu << username << " " << password;
			cu.close();
			
			Student student;
			student.setUsername(username);
			
			student.setPassword(password);
			
			while (1)
			{
				m.clearScreen();
				m.getStudentMenu().showStudentMenu();
				cin >> t;
				m.clearScreen();
				m.getStudentMenu().handleNum(t, student);
			}
		}
		else
		{
			cout << endl;
			cout << "�û��������ڻ����������." << endl;
			m.pauseScreen();
			m.clearScreen();
			goto begin2;
		}
		break;
	}
	case 3:
		m.exitSystem();
		m.pauseScreen();
		break;
	}
}
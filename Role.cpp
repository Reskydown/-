#include "Role.h"
#include<iostream>
using namespace std;
//�����û���
void Role::setUsername(string n) {
	cout << "OK";
	this->username = n;
	
}
//��������
void Role::setPassword(string p) {
	this->password = p;
}
//��ȡ�û���
string Role::getUsername() {
	return username;
}
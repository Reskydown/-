#include "Manager.h"
#include "Teacher.h"
#include <iomanip>
//���캯��
Manager::Manager() {
	if (getFileSize("course.data") > 0) {
		ifstream is("course.data", ios_base::in);
		Course tempCourse;
		while (!is.eof())
		{
			is >> tempCourse;
			course.insert(map<string, Course>::value_type(tempCourse.getNum(), tempCourse));
		}
		is.close();
	}
	if (getFileSize("teacher.data") > 0) {
		ifstream is("teacher.data", ios_base::in);
		Teacher tempTeacher;
		while (!is.eof())
		{
			is >> tempTeacher;
			teacher.insert(map<string, Teacher>::value_type(tempTeacher.getNum(), tempTeacher));
		}
		is.close();
	}
	if (getFileSize("student.data") > 0) {
		ifstream isStudent("student.data", ios_base::in);
		Student tempStudent;
		while (!isStudent.eof())
		{
			isStudent >> tempStudent;
			student.insert(map<string, Student>::value_type(tempStudent.getNum(), tempStudent));
		}
		isStudent.close();
	}
}
//����ѧ��
void Manager::addStudent() {
	cout << "������������Ϣ��" << endl;
	cout << "ѧ��  ����  �༶  �Ա�  ����" << endl;
	string num, name, hisClass,gender;
	int age;
	cin >> num >> name >> hisClass >> gender >> age;
	Student s;
	s.setNum(num);
	s.setName(name);
	s.setHisClass(hisClass);
	s.setGender(gender);
	s.setAge(age);
	map<string, Student>::iterator it = student.find(num);
	if (it == student.end()) {
		student.insert(map<string, Student>::value_type(s.getNum(), s));
		cout << "��ӳɹ�" << endl;
	}
	else {
		cout << "��ѧ���Ѵ���" << endl;
	}
	pauseScreen();

}
//ɾ��ѧ��
void Manager::deleteStudent() {
	string num;
	cout << "������ɾ��ѧ����ѧ��" << endl;
	cin >> num;
	map<string, Student>::iterator it = student.find(num);
	if (it == student.end()) {
		cout << "��ѧ��������" << endl;
	}
	else {
		student.erase(it);
		cout << "ɾ���ɹ���" << endl;
	}
	pauseScreen();
}
//���ӿγ�
void Manager::addCourse() {
	cout << "������������Ϣ��" << endl;
	cout << "�γ̱��" << " " << "�γ�����" << " " << "�ڿ���ʦ" << " " << "�γ�ѧ��" << " " << "�γ�ѧʱ" << endl;
	string num, name, teacher;
	double credit;
	int times;
	cin >> num >> name >> teacher >> credit >> times;
	Course c;
	c.setNum(num);
	c.setName(name);
	c.setTeacher(teacher);
	c.setCredit(credit);
	c.setTimes(times);
	c.setScore(-1);
	map<string, Course>::iterator it = course.find(num);
	if (it == course.end()) {
		course.insert(map<string, Course>::value_type(c.getNum(), c));
		cout << "��ӳɹ�" << endl;
	}
	else {
		cout << "�ÿγ��Ѵ���" << endl;
	}
	pauseScreen();

}
//ɾ���γ�
void Manager::deleteCourse() {
	string num;
	cout << "������ɾ���γ̵ı��" << endl;
	cin >> num;
	map<string, Course>::iterator it = course.find(num);
	if (it == course.end()) {
		cout << "�ÿγ̲�����" << endl;
	}
	else {
		course.erase(it);
		cout << "ɾ���ɹ���" << endl;
	}
	pauseScreen();
}
//�鿴ѧ��
void Manager::viewStudent() {

	if (student.size() == 0) {
		cout << "Ŀǰû��ѧ����" << endl;
	}
	else {
		cout << "ѧ��\t����\t�༶\t\t�Ա�\t����\t" << endl;
		
		for (map<string, Student>::iterator it = student.begin(); it != student.end(); ++it) {
			cout << (it->second).getNum() << "\t" << (it->second).getName() << "\t" << (it->second).getHisClass() << "\t" << (it->second).getGender() << "\t" << (it->second).getAge() << endl;
		}
	}
	pauseScreen();
}
//�鿴�γ�
void Manager::viewCourse() {
	if (course.size() == 0) {
		cout << "Ŀǰû�пγ̣�" << endl;
	}
	else {
		cout << "�γ̱��" << '\t' << "�γ�����" << '\t' << "�ڿ���ʦ" << '\t' << "�γ�ѧ��" << '\t' << "�γ�ѧʱ" << endl;
		for (map<string, Course>::iterator it = course.begin(); it != course.end(); ++it) {
			cout << (it->second).getNum() << "\t\t" << (it->second).getName() << '\t' << (it->second).getTeacher() << "\t\t" << (it->second).getCredit() << "\t\t" << (it->second).getTimes() << endl;
		}
	}
	pauseScreen();
}
void Manager::modifyStudent() {
	cout << "��������Ҫ�޸���Ϣ���ߵǼǳɼ���ѧ�����:";
	string num;
	cin >> num;
	map<string, Student>::iterator it = student.find(num);
	if (it == student.end()) {
		cout << "��ѧ��������" << endl;
	}
	else{
		cout << "�޸ĸ�����Ϣ������1,�Ǽǳɼ�������2:";
		int temp;
		cin >> temp;
		if (temp == 1) {
			string n1, n2, n3;
			int n4;
			cout << "�������ѧ������ �༶ �Ա� ����" << endl;
			cin >> n1 >> n2 >> n3 >> n4;
			(it->second).setName(n1);
			(it->second).setHisClass(n2);
			(it->second).setGender(n3);
			(it->second).setAge(n4);
			cout << "�޸����" << endl;
		}
		else{
			Student stu = it->second;
			cout << "������Ҫ����ɼ��Ŀγ̱��:";
			string x;
			cin >> x;
			stu.setScore(x);
			
		}
	}
	pauseScreen();
}
void Manager::addTeacher() {
	cout << "������������Ϣ��" << endl;
	cout << "����  ����  Ժϵ  �Ա�" << endl;
	string num, name, hisClass, gender;
	int age;
	cin >> num >> name >> hisClass >> gender;
	Teacher s;
	s.setNum(num);
	s.setName(name);
	s.setHisClass(hisClass);
	s.setGender(gender);
	map<string, Teacher>::iterator it = teacher.find(num);
	if (it == teacher.end()) {
		teacher.insert(map<string, Teacher>::value_type(s.getNum(), s));
		cout << "��ӳɹ�" << endl;
	}
	else {
		cout << "��ѧ���Ѵ���" << endl;
	}
	pauseScreen();
}
//д���ļ�
void Manager::writeStudent() {
	remove("student.data");
	ofstream os("student.data", ios_base::app);
	for (map<string, Student>::iterator it = student.begin(); it != student.end(); ++it) {
		if (it == student.begin()) {
			os << (it->second).getNum() << " " << (it->second).getName() << " " << (it->second).getHisClass() << " "<< (it->second).getGender() << " " << (it->second).getAge();
		}
		else {
			os << endl;
			os << (it->second).getNum() << " " << (it->second).getName() << " " << (it->second).getHisClass() << " " << (it->second).getGender() << " " << (it->second).getAge();
		}

	}
}
//д���ļ�
void Manager::writeCourse() {
	remove("course.data");
	ofstream os("course.data", ios_base::app);
	for (map<string, Course>::iterator it = course.begin(); it != course.end(); ++it) {
		if (it == course.begin()) {
			os << (it->second);
		}
		else {
			os << endl;
			os << (it->second);
		}
	}
}
//д���ļ�
void Manager::writeUser() {
	remove("user.data");
	ofstream os("user.data", ios_base::app);
	for (map<string, Student>::iterator it = student.begin(); it != student.end(); ++it) {
		if (it == student.begin()) {
			os << (it->second).getNum() << " " << (it->second).getNum();
		}
		else {
			os << endl;
			os << (it->second).getNum() << " " << (it->second).getNum();
		}

	}
}
void Manager::writeAdmin() {
	remove("admin.data");
	ofstream os("admin.data", ios_base::app);
	for (map<string, Teacher>::iterator it = teacher.begin(); it != teacher.end(); ++it) {
		if (it == teacher.begin()) {
			os << (it->second).getNum() << " " << (it->second).getNum();
		}
		else {
			os << endl;
			os << (it->second).getNum() << " " << (it->second).getNum();
		}

	}
}
void Manager::writeTeacher() {
	remove("teacher.data");
	ofstream os("teacher.data", ios_base::app);
	for (map<string, Teacher>::iterator it = teacher.begin(); it != teacher.end(); ++it) {
		if (it == teacher.begin()) {
			os << (it->second).getNum() << " " << (it->second).getName() << " " << (it->second).getHisClass() << " " << (it->second).getGender() ;
		}
		else {
			os << endl;
			os << (it->second).getNum() << " " << (it->second).getName() << " " << (it->second).getHisClass() << " " << (it->second).getGender();
		}

	}
}
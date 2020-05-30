#include "Student.h"
#include <iomanip>
//���������>>
ifstream & operator>> (ifstream &in, Student &s) {
	string num, name, cl,gender;
	int age;
	in >> num >> name >> cl >> gender >> age;
	s.setNum(num);
	s.setName(name);
	s.setHisClass(cl);
	s.setGender(gender);
	s.setAge(age);
	return in;
}
//���������<<
ofstream & operator<< (ofstream &out, Student &s) {
	out << s.getNum() << " " << s.getName() << " " << s.getHisClass() << "" << s.getGender() << "" << s.getAge() << endl;
	return out;
}
//���캯��
Student::Student() {
	string tu;
	string tp;
	Course tempCourse;
	if (getFileSize("course.data") > 0) {
		ifstream is("course.data", ios_base::in);
		while (!is.eof())
		{
			is >> tempCourse;
			all.insert(map<string, Course>::value_type(tempCourse.getNum(), tempCourse));
		}
		is.close();
	}

	if (getFileSize("current.data") > 0) {
		ifstream ru("current.data", ios_base::in);
		ru >> tu >> tp;
		ru.close();
	}
	num = tu;
	string file = ".\\data\\" + tu + ".txt";
	if (getFileSize(file.c_str()) > 0) {
		ifstream is2(file.c_str(), ios_base::in);
		Course tempCourse1;
		while (!is2.eof())
		{
			is2 >> tempCourse1;
			course.insert(map<string, Course>::value_type(tempCourse1.getNum(), tempCourse1));
		}
		is2.close();
	}

}
//ѡ��
void Student::selectCourse() {
	string num;
	cout << "������Ҫѡ��Ŀγ̱��" << endl;
	cin >> num;
	map<string, Course>::iterator it = all.find(num);
	if (it == all.end()) {
		cout << "�ÿγ̲����ڣ�����ѡ��" << endl;
	}
	else {
		course.insert(map<string, Course>::value_type((it->second).getNum(), (it->second)));
		cout << "���ѳɹ�ѡ��ÿγ̣�" << endl;
	}
	pauseScreen();
}
//�˿�
void Student::cancelCourse() {
	string num;
	cout << "������Ҫȡ��ѡ��Ŀγ̱��" << endl;
	cin >> num;
	map<string, Course>::iterator it = course.find(num);
	if (it == course.end()) {
		cout << "��û��ѡ��ÿγ̣�" << endl;
	}
	else {
		course.erase(it);
		cout << "���ѳɹ�ȡ��ѡ��ÿγ̣�" << endl;
	}
	pauseScreen();
}
//�鿴��ѡ�γ�
void Student::viewCourse() {
	if (course.size() == 0) {
		cout << "û��ѡ���κογ�" << endl;
	}
	else {
		cout << "����ѡ��Ŀγ�����:" << endl;
		cout << "�γ̱��" << '\t' << "�γ�����" << '\t' << "�ڿ���ʦ" << '\t'<< "�γ�ѧ��" << '\t' << "�γ�ѧʱ"  << '\t' << "�γ̷���"<< endl;
		for (map<string, Course>::iterator it = course.begin(); it != course.end(); ++it) {
			cout << (it->second).getNum() << "\t\t" << (it->second).getName() << '\t' << (it->second).getTeacher() << "\t\t" << (it->second).getCredit() << "\t\t" << (it->second).getTimes() << "\t\t" << (it->second).getScore() << endl;
		}
	}
	pauseScreen();
}
//�鿴���пγ�
void Student::allCourse() {
	if (all.size() == 0) {
		cout << "û�пγ̿�ѡ��" << endl;
	}
	else
	{
		cout << "���п�ѡ�Ŀγ�����:" << endl;
		cout << "�γ̱��" << '\t' << "�γ�����" << '\t' << "�ڿ���ʦ" << '\t' << "�γ�ѧ��" << '\t' << "�γ�ѧʱ" << endl;
		for (map<string, Course>::iterator it = all.begin(); it != all.end(); ++it) {
			cout << (it->second).getNum() << "\t\t" << (it->second).getName() << '\t' << (it->second).getTeacher() << "\t\t" << (it->second).getCredit() << "\t\t" << (it->second).getTimes() << endl;
		}
		
	}
	pauseScreen();
}
void Student::setScore(string x) {
	string file = ".\\data\\" + getNum() + ".txt";
	if (getFileSize(file.c_str()) > 0) {
		ifstream is2(file.c_str(), ios_base::in);
		Course tempCourse1;
		while (!is2.eof())
		{
			is2 >> tempCourse1;
			course.insert(map<string, Course>::value_type(tempCourse1.getNum(), tempCourse1));
		}
		is2.close();
	}
	map<string, Course>::iterator it = course.find(x);
	if (it == course.end()) {
		cout << "��ѧ��û��ѡ��ÿγ�" << endl;
	}
	else {
		cout << "��������Ҫ���õķ���" << endl;
		int x;
		cin >> x;
		(it->second).setScore(x);
		cout << "�޸����" << endl;
	}
	writeCourse();
}
//��ӡ��Ϣ
void Student::printInformation() {
	cout << "������Ϣ����:" << endl;
	ifstream isStudent("student.data", ios_base::in);
	string n1, n2, n3,n4;
	int n5;
	while (!isStudent.eof())
	{
		isStudent >> n1 >> n2 >> n3 >> n4 >> n5;
		if (n1 == num) {
			cout << "ѧ��\t����\t�༶\t\t�Ա�\t����\t" << endl;
			cout << n1 << '\t' << n2 << '\t' << n3 << '\t' << n4 << '\t' << n5 <<endl;
			break;
		}
	}
	isStudent.close();
	viewCourse();
	double cnt = 0, _max = -1000;
	for (map<string, Course>::iterator it = course.begin(); it != course.end(); ++it) {
		cnt += (it->second).getScore();
		_max = max(_max, (it->second).getScore());
	}
	int temp = 0;
	cout << "��Ҫ�鿴�����߷���ƽ������(ȷ�ϲ鿴������1,�˳��밴0):";
	cin >> temp;
	if (temp == 1) {
		cout << "�����߷�Ϊ:" << _max << endl << "ƽ����Ϊ:" << cnt / course.size() << endl;
		pauseScreen();
	}
}
//д���ļ�
void Student::writeCourse() {
	remove("current.data");
	string file = ".\\data\\" + getNum() + ".txt";
	remove(file.c_str());
	ofstream os(file.c_str(), ios_base::app);
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
//��ȡ����
string Student::getName() {
	return name;
}
//��ȡѧ��
string Student::getNum() {
	return num;
}
//��ȡ�༶
string Student::getHisClass() {
	return hisClass;
}
string Student::getGender() {
	return this->gender;
}
int Student::getAge() {
	return this->age;
}
map<string, Course> Student::getCourse() {
	return course;
}
//��������
void Student::setName(string n) {
	this->name = n;
}
//����ѧ��
void Student::setNum(string n) {
	this->num = n;
}
//���ð༶
void Student::setHisClass(string c) {
	this->hisClass = c;
}
void Student::setGender(string gender) {
	this->gender = gender;
}
void Student::setAge(int age) {
	this->age = age;
}

#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

struct Student {                     //½á¹¹Ìå
	int num;
	string name;
	char sex;
	int age;
};

int main() {
	Student stu = { 97001,"Li Ming",'F',19 };
	cout << "Num:" << stu.num << endl;
	cout << "Name:" << stu.name << endl;
	cout << "Sex:" << stu.sex << endl;
	cout << "Age:" << stu.age << endl;
	return 0;
}
#include <iostream>
#include <algorithm>

using namespace std;

class Student {
public:
	string name;
	int score;
	Student(string name, int score) {
		this->name = name;
		this->score = score;
	}
	//���� ������ ' ������ ���� ����'
	bool operator <(Student& student) {
		return this->score < student.score;
		//������ ������ ���� ���
		//�� ������ �ٸ� �л��� �� 
	}
};

int main(void) {
	Student students[]{
		Student("����û",99),
		Student("�̴���",93),
		Student("������",80),
		Student("������",100),
		Student("�� ��",85),
	};
	sort(students, students + 5);
	for (int i = 0; i < 5; i++)
		cout << students[i].name << endl;
}
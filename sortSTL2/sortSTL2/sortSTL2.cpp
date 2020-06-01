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
	//정렬 기준은 ' 점수가 작은 순서'
	bool operator <(Student& student) {
		return this->score < student.score;
		//점수가 작으면 먼저 출력
		//내 점수와 다른 학생을 비교 
	}
};

int main(void) {
	Student students[]{
		Student("박현청",99),
		Student("이다인",93),
		Student("박현강",80),
		Student("박현은",100),
		Student("보 라",85),
	};
	sort(students, students + 5);
	for (int i = 0; i < 5; i++)
		cout << students[i].name << endl;
}
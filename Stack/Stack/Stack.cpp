#include <iostream>
#include <stack>//스택을 위한 라이브러리 

using namespace std;

int main(void) {
	stack<int> s;//스택생성 
	s.push(4); //원소 삽입 
	s.push(3);
	s.push(2);
	s.push(1);
	s.pop(); //원소 삭제 
	s.pop();
	while (!s.empty()) {
		cout << s.top() << ' ';
		//가장 윗쪽 원소 출력,삭제는 아님 
		s.pop(); //원소 삭제  
	}
}


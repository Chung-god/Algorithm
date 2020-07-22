#include <iostream>
#include <cmath>
#include <string>
#include <stdio.h>
using namespace std;
int N;
void hanoi(int n, int from, int tmp, int to) {

	if (n == 1) {
		printf("%d %d\n", from, to);
	}
	else {
		hanoi(n - 1, from, to, tmp);
		printf("%d %d\n", from, to);
		hanoi(n - 1, tmp, from, to);
	}
}

int main(void) {

	scanf("%d", &N);
	string answer = to_string(pow(2, N)); 
	//N의 값이 커지는 경우, answer의 범위가 long long을 넘어가므로 string 계산으로 처리한다.
	int idx = answer.find('.'); 
	answer = answer.substr(0, idx); //소수점 이하부분을 뗀다
	answer[answer.length() - 1] -= 1;
	printf("%s\n", answer.c_str());

	if (N <= 20) //N이 20이하의 경우만 이동과정 출력
		hanoi(N, 1, 2, 3);

	return 0;
}
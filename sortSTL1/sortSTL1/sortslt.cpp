#include <iostream>
#include <algorithm>

using namespace std;
//sort 기준을 스스로 정할 수 있음
//단순 데이터 정렬 기법은 현실적이지 않음 
bool compare(int a, int b) {
	return a < b;
}
int main(void) {
	int a[10] = { 9, 3, 5, 4, 1 ,10, 8, 6, 7, 2 };
	sort(a, a + 10, compare); // 배열과 정렬할 원소 개수 
	for (int i = 0; i < 10; i++) {
		cout << a[i] << ' ';
	}

}
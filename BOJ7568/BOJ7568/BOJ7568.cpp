// BOJ7568.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 200
using namespace std;

vector<pair<int, int> > v;
int a[MAX];
int b[MAX];
//p1.first > p2.first
//p1.second > p2.second
int cmp(pair<int, int> p1, pair<int, int> p2) {
	if (p1.first > p2.first) {
		if (p1.second > p2.second) {
			return 1;
		}
		else if (p1.second == p2.second) {
			return 0;
		}
		else {//(p1.second < p2.second
			return 0;
		}
	}
	else if (p1.first == p2.first) {
		if (p1.second > p2.second) {
			return 0;
		}
		else if (p1.second == p2.second) {
			return 0;
		}
		else {//(p1.second < p2.second
			return 0;
		}
	}
	else {//(p1.first < p2.first
		if (p1.second > p2.second) {
			return 0;
		}
		else if (p1.second == p2.second) {
			return 0;
		}
		else {//(p1.second < p2.second
			return -1;
		}
	}
	

}

int main()
{
	int N;
	int weight, height;
	cin >> N;

	
	for (int i = 0;i < N; i++) {
		cin >> weight >> height;
		v.push_back(make_pair(weight,height));
	}

	

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) continue;
			int result = cmp(v[i], v[j]);
			a[i] += result;
			//printf("(%d,%d) (%d,%d) -> %d\n", v[i].first, v[i].second, v[j].first, v[j].second, result);
		}
	}
	
	
	
	for (int i = 0; i < N; i++) {
		int num = N+1;
		for (int j = 0; j < N; j++) {
			if (a[i] >= a[j]) {
				num -= 1;
			}
		}
		b[i] = num;
		cout << b[i] << " ";
	}
		
	
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.

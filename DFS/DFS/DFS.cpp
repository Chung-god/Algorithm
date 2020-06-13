// DFS.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

using namespace std;
int number = 7;//노드 수
int c[8];//방문처리를 위한 배열
vector<int> a[8];//7개의 노드가 각각 인접한 노드를 가질 수 있게

void dfs(int x) {

    if (c[x]) return;//방문한 노드이면 바로 리턴
    //방문을 안 한 노드
    c[x] = true;//방문 처리 
    cout << x << ' ';
    for (int i = 0; i < a[x].size();i++) {
        int y = a[x][i];//인접한 노드
        dfs(y);
    }
}

int main()
{

	//1과 2를 연결 
		a[1].push_back(2);
a[2].push_back(1);

	//1과 3을 연결 
	a[1].push_back(3);
	a[3].push_back(1);

	//2과 3을 연결 
	a[2].push_back(3);
	a[3].push_back(2);
	//2와 4를 연결 
	a[2].push_back(4);
	a[4].push_back(2);

	//2과 5을 연결 
	a[2].push_back(5);
	a[5].push_back(2);

	//4과 5를 연결 
	a[4].push_back(5);
	a[5].push_back(4);

	//3과 6을 연결 
	a[3].push_back(6);
	a[6].push_back(3);

	//3과 7을 연결 
	a[3].push_back(7);
	a[7].push_back(3);

	//6과 7을 연결 
	a[6].push_back(7);
	a[7].push_back(6);

	dfs(1);
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

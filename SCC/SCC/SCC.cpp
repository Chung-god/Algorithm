// SCC.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#define MAX 10001
using namespace std;

int id = 0, d[MAX];//각 노드마다 고유한 번호 할당
bool finished[MAX];//현재 특정 노드에 대한 DFS 가 끝났는지 판단
vector<int> a[MAX];
vector<vector<int> > SCC;
stack<int> s;

//DFS는 총 정점의 갯수만큼 실행됩니다.
int dfs(int x) {
    d[x] = ++id;//노드마다 코유한 번호 할당
    s.push(x); //스택에 자기 자신을 삽입
    int parent = d[x]; //자신의 부모가 누구인지 확인, 처음에는 자기 자신
    for (int i = 0; i < a[x].size(); i++) {
        int y = a[x][i];//인접한 노드 자체를 가리키기
        if (d[y] == 0) parent = min(parent, dfs(y)); //만약 해당노드를 반복한 적이 없다면 해당 노드로 dfs 수행
        //여기서는 3의 노드가 1보다 작기 때문에 1을 부모노드로 정한다.
        else if (!finished[y]) parent = min(parent, d[y]); //처리 중인 이웃
    }
    //부모노드가 자기자신인 경우
    if (parent == d[x]) {
        vector<int> scc;
        while (1) {
            int t = s.top();
            s.pop();
            scc.push_back(t);
            finished[t] = true;
            if (t == x) break;
        }
        SCC.push_back(scc);
    }
    return parent;//자신의 부모 값 반환
}
int main()
{
    int v = 8;
    a[1].push_back(2);
    a[2].push_back(3);
    a[3].push_back(1);
    a[4].push_back(3);
    a[4].push_back(5);
    a[5].push_back(6);
    a[6].push_back(7);
    a[7].push_back(8);
    a[8].push_back(5);
    for (int i = 1; i <= v; i++) {
        if (d[i] == 0) dfs(i);
    }
    printf("SCC의 갯수 : %d\n", SCC.size());
    for (int i = 0; i < SCC.size(); i++) {
		printf("%d번째 SCC:", i + 1);
        for (int j = 0; j < SCC[i].size(); j++) {
			printf("%d ", SCC[i][j]);
        }
		printf("\n");
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
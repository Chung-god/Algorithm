// Topology Sort.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>
#define MAX 10

using namespace std;

int n, inDegree[MAX];
vector<int> a[MAX];
void topoloySort() {
    int result[MAX];
    queue<int> q;

    //진입차수가 0인 노드를 큐에 삽입
    for (int i = 1; i <= n; i++) {
        if (inDegree[i] == 0) q.push(i);
    }

    //위상정렬이 완전히 수행되려면 모든 노드를 방문해야함
    for (int i = 1; i <= n;i++) {
        //n개를 방문하기 전에 큐가 빈다면 사이클이 발생
        if (q.empty()) {
            printf("cycle\n");
            return;
        }
        int x = q.front();
        q.pop();
        result[i] = x; //큐에서 꺼낸 순서가 위상 정렬을 한 순서
        for (int i = 0; i < a[x].size();i++) {
            int y = a[x][i];
            //새롭게 진입차수가 0인 된 정점을 큐에 삽입
            if (--inDegree[y] == 0) {
                q.push(y);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", result[i]);
    }
}

int main()
{
    n = 7;
    a[1].push_back(2);
    inDegree[2]++;
    a[1].push_back(5);
    inDegree[5]++;
    a[2].push_back[3]
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

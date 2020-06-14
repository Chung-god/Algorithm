// Network  Flow.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 100
#define INF 1000000000

using namespace std;
int n = 6, result;
int c[MAX][MAX], f[MAX][MAX], d[MAX];//용량, 현재 흐르고 있는 유량, 방문을 했는지
vector<int> a[MAX];

void maxFlow(int start, int end) {
    while (1) {
        fill(d, d + MAX, -1); //모든 정점 방문하지 않은 상태로 
        queue<int> q;
        q.push(start);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int i = 0; i < a[x].size(); i++) {
                int y = a[x][i];
                //방문하지 않은 노드 중에서 용량이 남은 경우
                //그리고 방문한적이 없는 경우
                if (c[x][y] - f[x][y] > 0 && d[y] == -1) {
                    q.push(y);
                    d[y] = x; //방문처리, 경로기억
                    if (y == end) break; //도착지에 도달을 한 경우
                }
            }
        }
        //모든 경로를 다 찾은 뒤에 탈출
        if (d[end] == -1)break;
        int flow = INF;
        //거꾸로 최소 유량 탐색
        for (int i = end; i != start; i = d[i]) {
            flow = min(flow, c[d[i]][i] - f[d[i]][i]);
            
        }
            //최소 유량만큼 추가합니다. 
        for (int i = end; i != start; i = d[i]) {
            f[d[i]][i] += flow;
            f[i][d[i]] -= flow;
        }
        result += flow;
    }
}
int main()
{
    a[1].push_back(2);
    a[2].push_back(2);
    c[1][2] = 12;

    a[1].push_back(4);
    a[4].push_back(1);
    c[1][4] = 11;

    a[2].push_back(3);
    a[3].push_back(2);
    c[2][3] = 6;

    a[2].push_back(4);
    a[4].push_back(2);
    c[2][4] = 3;

    a[2].push_back(5);
    a[5].push_back(2);
    c[2][5] = 5;


    a[3].push_back(6);
    a[6].push_back(3);
    c[3][6] = 8;
    
    a[4].push_back(5);
    a[5].push_back(4);
    c[4][5] = 9;
    
    a[5].push_back(3);
    a[3].push_back(5);
    c[5][3] = 3;

    
    a[5].push_back(6);
    a[6].push_back(5);
    c[5][6] = 4;

    maxFlow(1, 6);
    printf("%d", result);
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

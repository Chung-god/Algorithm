#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int number = 7;
int c[8]; //방문처리 1~7까지 방문을 해주기 때문에 
vector<int> a[8]; //연결된 노드들 표시  

void bfs(int start) {//시작 노드를 넣어준다 
	queue<int> q;
	q.push(start);
	c[start] = true;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		printf("%d ", x);
		for (int i = 0; i < a[x].size(); i++) {
			int y = a[x][i];//x와 인접한 노드  
			if (!c[y]) {//방문했던 노드가 아니라면 
				q.push(y);
				c[y] = true;//방문함 
			}
		}
	}
}

int main(void) {
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

	bfs(1);

	return 0;
}
// Union-Find.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <stdio.h>

// 부모 노드를 찾는 함수 
int getParent(int parent[], int x) {
	if (parent[x] == x) return x; //부모노드가 없을때
	return parent[x] = getParent(parent, parent[x]);
}

// 두 부모 노드를 합치는 함수
int unionParent(int parent[], int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	//인덱스 값이 작은 걸 부모 노드로 정함 
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

//같은 부모를 가지는지 확인하는 함수 
int findParent(int parent[], int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a == b)
		return 1;
	return 0;
}

int main(void) {
	int parent[11];
	//자기 자신이 부모가 되게 초기화 
	for (int i = 1; i <= 10;i++) {
		parent[i] = i;
	}
	unionParent(parent, 1, 2); //1과 2을 연결 
	unionParent(parent, 2, 3); //2과 3을 연결 
	unionParent(parent, 3, 5); //3과 5을 연결 
	unionParent(parent, 4, 6); //4과 6을 연결 
	unionParent(parent, 6, 7); //6과 7을 연결 


	printf("1과 4는 연결되어 있나요? %d\n", findParent(parent, 1, 4));
	unionParent(parent, 1, 4);
	printf("1과 4는 연결되어 있나요? %d\n", findParent(parent, 1, 4));
}


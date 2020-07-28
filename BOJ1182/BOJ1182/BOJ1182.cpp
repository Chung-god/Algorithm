#include <iostream>
#define MAX 20

using namespace std;

int Arr[MAX];
bool Select[MAX];
int K;
int ans = 0;
int S, N;
void Print() {
	int result = 0;
	for (int i = 0; i < N; i++) {
		if (Select[i] == true) {
			//cout<<Arr[i]<<" ";
			result += Arr[i];
		}
	}
	if (result == S) {
		ans += 1;
		//cout<<"Here";
	}
	//cout<<"\n"; 
}
//DFS 로 조합 구현  
void DFS(int Idx, int Cnt) {
	if (Cnt == K) {
		Print();
		return;
	}

	for (int i = Idx; i < N; i++) {
		if (Select[i] == true) continue;
		Select[i] = true;

		DFS(i, Cnt + 1);
		Select[i] = false;
	}
}

int main(void) {
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		scanf("%d", &Arr[i]);
	}
	for (int i = 1; i <= N; i++) {
		K = i;
		DFS(0, 0);
	}
	cout << ans;
}
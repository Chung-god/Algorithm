#include <iostream>
using namespace std;

int M;
int N;
int K; // 배추 개수
bool farm[51][51];
bool visited[51][51];

void dfs(int x){
    if(visited) return;
}

int main(){
    cin>>M>>N>>K;
    for(int i = 0 ; i < K; i++){
        int t1,t2;
        cin>>t1>>t2;
        farm[t1-1][t2-1] = 1;
    }

    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++)
            cout<<farm[i][j]<<" ";
        cout<<"\n";   
    }

}
#include <iostream>
using namespace std;

int test;
int M;
int N;
int K; // 배추 개수
int bug = 0;
bool farm[51][51];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
bool visited[4];
void dfs(int x,int y){
    farm[x][y] = 0;
    for(int i = 0 ; i < 4; i++){
        int Nx = x + dx[i];
        int Ny = y + dy[i];
        if(Nx < 0 || Nx > M || Ny < 0 || Ny > N)  continue;
        if(!farm[Nx][Ny]) continue;
        dfs(Nx,Ny);
    }
    return;
}

int main(){
    cin>>test;
    while(test > 0){
        cin>>M>>N>>K;
        for(int i = 0 ; i < K; i++){
            int t1,t2;
            cin>>t1>>t2;
            farm[t1][t2] = 1;
        }

        // for(int i = 0; i < M; i++){
        //     for(int j = 0 ; j < N; j ++)
        //         cout<<farm[i][j]<<" ";
        //     cout<<"\n";
        // }

        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                if(farm[i][j]){
                    dfs(i,j);
                    bug++;
                } 
            }
        }

        cout<<bug<<"\n";
        bug = 0;
        test--;
    }
}
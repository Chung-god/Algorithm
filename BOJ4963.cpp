#include <iostream>
using namespace std;

int island[51][51];
int H,W; 
int dx[8] = {1,0,-1,0,1,-1,1,-1};
int dy[8] = {0,1,0,-1,1,-1,-1,1};
int result = 0;

void findIsland(int x,int y){
    if(!island[x][y]) return;
    island[x][y] = 0;
    for(int i = 0; i < 8; i++){
        int Nx = x + dx[i];
        int Ny = y + dy[i];
        if(island[Nx][Ny]==1) //1을 안해주면 인덱스 범위 에러가 남
            findIsland(Nx,Ny);
    }
}

int main(){
    
    cin>>W>>H;//너비와 높이
    while(W != 0 && H !=0){
        for(int i = 0; i < H; i++){
            for(int j = 0; j < W; j ++){
                cin>>island[i][j];
            }
        }    
        for(int i = 0; i < H; i ++){
            for(int j = 0; j < W; j++){
                if(island[i][j]){
                    findIsland(i,j);
                    result++;
                }
            }
        }
        cout<<result<<"\n";
        result = 0;
        cin>>W>>H;
   }
}
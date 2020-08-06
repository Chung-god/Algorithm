#include <iostream>
#include <queue>
using namespace std;

int arr[501][501];
int col,row;
int SUM = 0;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int total = 0;
bool checked[501][501];
void tetro1(int x, int y , int cnt){
    if(cnt == 4){
        if(total < SUM){ 
            SUM = total;
            cout<<SUM<<" ";
            return;
        }

    }
    for(int i = 0; i < 4; i ++){
        int Nx = x + dx[i];
        int Ny = y + dy[i];
        if(checked[Nx][Ny]) continue;
        checked[Nx][Ny] = true;
        tetro1(Nx,Ny,cnt+1);
        checked[Nx][Ny] = false;
    }
}


int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin>>col>>row;
    for(int i =0; i < col; i++)
        for(int j = 0; j < row; j++)
            cin>>arr[i][j];

    for(int i = 0;i < col; i++){
        for(int j = 0; j < row; j++){
            tetro1(i,j,0);

        }
    }
    cout<<SUM;
}
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

char mineral[102][102];
bool visited[102][102];
int R,C,N;
int attack[101];

int dx[4]={-1,1,0,0};
int dy[4]={0,0,1,-1};

int numOfmineral = 0;
int numOfTempMineral = 0;
bool isClusterResult;

vector<pair<int,int>> v;
void gravity(int x,int y){
    for(int i = 0; i < 4; i++){
        int Nx = x + dx[i];
        int Ny = y + dy[i];
        if(Nx < 1 || Nx > R || Ny < 1 || Ny > C) continue; //범위 넘으면 넘어감
        if(visited[Nx][Ny]) continue; //방문 했으면 넘어감
        if(mineral[Nx][Ny] == '.') continue;
        visited[Nx][Ny] = true;
        v.push_back(make_pair(Nx,Ny));
        gravity(Nx,Ny);
    }
}

void isCluster(int x,int y){
    for(int i = 0; i < 4; i++){
        int Nx = x + dx[i];
        int Ny = y + dy[i];
        if(Nx < 1 || Nx > R || Ny < 1 || Ny > C) continue; //범위 넘으면 넘어감
        if(visited[Nx][Ny]) continue; //방문 했으면 넘어감
        if(mineral[Nx][Ny] == '.') continue;
        visited[Nx][Ny] = true;
        cout<<Nx<<","<<Ny<<"\n";
        numOfTempMineral++;
        isCluster(Nx,Ny);        
    }
}

int main(){
    cin>>R>>C;

    for(int i = 1; i <= R; i++)
        for(int j = 1; j <= C; j++){
            cin>>mineral[i][j];
            if(mineral[i][j]=='x') numOfmineral++;
        }

    cin>>N;
    for(int i = 0; i < N; i++){
        int temp;
        cin>> temp;
        attack[i] = R-temp +1;
        cout<<attack[i];
    }
   
    for(int i = 0; i < N; i++){
        if(i%2==0){ //왼쪽에서 던질 경우
            int temp = 1;
            while(temp<= N){
                if(mineral[attack[i]][temp] == 'x'){
                     mineral[attack[i]][temp] = '.';
                     numOfmineral--;
                     break;
                }
                temp++;
            }
       }else{//오른쪽에서 던질 경우
            int temp = R;
            while(temp>= 1){
                if(mineral[attack[i]][temp] == 'x'){
                    mineral[attack[i]][temp] = '.';
                    numOfmineral--;
                    break;
                }
                temp--;
            }
        }
        isClusterResult = 0;
        numOfTempMineral = 0; 
            memset(visited,0,sizeof(visited));
        for(int j = 1; j <= R; j++){
            int k = 1;
            for(; k <= C; k++){
                if(mineral[j][k] =='x'){
                    numOfTempMineral++;
                    visited[j][k] = true;
                    //cout<<"Into "<<j<<","<<k<<"\n";
                    isCluster(j,k);
                    cout<<"Mineral real num: "<<numOfmineral<<"\n";
                    cout<<"Mineral num: "<<numOfTempMineral<<"\n";
                    memset(visited,0,sizeof(visited));
                    break;
                }
            }
            if(k != C+1) break;
        }
        
        if(numOfmineral != numOfTempMineral){
            for(int j = 1; j <= R; j++){
                for(int k = 1; k <=C; k++ ){
                    if(mineral[j][k]=='x'){
                        gravity(i,k);
                        cout<<"gravity:\n";
                        sort(v.begin(),v.end());
                        for(int i=0; i < v.size();i++){
                            cout<<v[i].first<<"."<<v[i].second<<"\n";
                        }
                    }
                }
            }
        }
        for(int i = 1; i <= R; i++){
            for(int j = 1; j <= C; j++)
                cout<<mineral[i][j];
            cout<<"\n";
        }
    }
    cout<<"\n";
    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++)
            cout<<mineral[i][j];
        cout<<"\n";
    }
}

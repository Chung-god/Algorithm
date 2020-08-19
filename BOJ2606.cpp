#include <iostream>
using namespace std;

int ComN;
int NetN;
bool Network[101][101];
bool visited[101];
int result = 0;

void virus(int Com){

    for(int i = 2; i <= ComN; i++){
        if(Com == i) continue;
        if(visited[i]) continue;
        if(!Network[Com][i]) continue; 
        visited[i] = true;
        result++;
        virus(i);
    }
}
int main(void){
    cin>>ComN>>NetN;
    for(int i = 0; i < NetN; i++){
        int t1,t2;
        cin>>t1>>t2;
        Network[t1][t2] = true;
        Network[t2][t1] = true;
    }
    virus(1);
    cout<<result;
}
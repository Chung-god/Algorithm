#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int number = 9; //노드의 수
bool visited[8];//방문 노드 검사
vector<int> tall;//키 넣을 노드
int Sum =0;
void dfs(int x,int cnt){
    if(cnt>7||Sum >100) return; // 100이 넘거나 7넘게 세면 return
    if(Sum == 100 && cnt ==7){ // 7개 이면서 합이 100개 이면 true 인걸 출력
        for(int i = 0;i < 9; i++){
            if(visited[i]) cout<<tall[i]<<"\n";
        }
        exit(0);//중복된 답을 체크하는 게 아니기 때문에 탈출 
    }
    for(int i =x;i < number;i++){
        if(visited[i]) continue; //방문한 노드이면 넘어감
        visited[i]=true;  
        Sum += tall[i];
        dfs(i,cnt+1);//탐색
        visited[i] = false;
        Sum -= tall[i];
    }
}

int main(){
    for(int i =0; i <number; i++){
        int temp;
        cin>>temp;
        tall.push_back(temp);
    }
    sort(tall.begin(),tall.end());
    dfs(0,0);
}
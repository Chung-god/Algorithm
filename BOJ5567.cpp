#include <iostream>
using namespace std;

bool Friend[502][502]={{0,},};
bool visited[502];
int FNum;
int relation;
int result = 0;

void FindFriend(int node, int cnt){
    if(cnt > 1) return; //친구의친구의친구이면

    for(int i = 1; i <= FNum; i++){
        if(node == i ) continue; 
        if(!Friend[node][i]) continue;//친구가 아니거나 방문했으면 넘어간다. 
        if(!visited[i]) result++; //친구 수 증가
        visited[i] = true; //방문 표시
        //cout<<cnt<<"번째 "<<node <<"의 친구 "<< i<<"\n";
        FindFriend(i,cnt+1);
    }
}
int main(){
    cin>>FNum>>relation;
    for(int i = 0; i < relation; i++){
        int a,b;
        cin>>a>>b;
        Friend[a][b] = true;
        Friend[b][a] = true;
    }
    visited[1] = true;
    FindFriend(1,0);
    cout<<result;
}
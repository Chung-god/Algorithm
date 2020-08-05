#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;

int nodeNum; //노드의 수
int edgeNum; //간선의 수
int c[1001];//방문처리를 위한 배열 
int start; //시작 노드
vector<int> a[1001]; //노드마다 인접노드 

void dfs(int x){
    if(c[x]) return;
    c[x] = true;
    cout<<x<<" ";
    for(int i = 0 ; i<a[x].size();i++){
        int y = a[x][i];
        dfs(y);
    } 
}

void bfs(int start){
    queue<int> q;
    q.push(start);
    c[start] = true;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        cout<<x<<" ";
        for(int i =0; i < a[x].size();i++) {
            int y = a[x][i];
            if(!c[y]){
                q.push(y);
                c[y] = true;
            }
        }
    }
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    vector< pair<int,int> > temp;
    set<int> s;
    cin>>nodeNum>>edgeNum>>start;

    for(int i = 0; i < edgeNum; i++){
        int n1,n2;
        cin>>n1>>n2;
        s.insert(n1);
        s.insert(n2);
        a[n1].push_back(n2);
        a[n2].push_back(n1);
    }
    for(auto i =s.begin(); i != s.end(); i ++)
        sort(a[*i].begin(),a[*i].end());
   
    dfs(start);
    cout<<"\n";
    for(int i = 0 ; i < 1001; i++) c[i] = 0;
    bfs(start);
}
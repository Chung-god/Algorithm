#include <iostream>
#include <vector>
using namespace std;

int node,edge;
int c[1005];//범위 때문에 계속 틀림 1000까지 하면 안됨 
vector<int> a[1005];

void dfs(int x){
    if(c[x]) return;
    c[x]=true;
    //cout<<x<<' ';
    for(int i = 0;i < a[x].size();i++){
        int y = a[x][i];
        dfs(y); 
    }
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>node>>edge;
    if(edge == 0){
        cout<<node;
        return 0;
    }
    for(int i = 0; i < edge; i++){
        int e1,e2;
        cin>>e1>>e2;
        a[e1].push_back(e2);
        a[e2].push_back(e1);
    }

    int result =0;
    for(int i = 1;i <= node; i++){
        //cout<<i<<" ";
        if(c[i]) continue;
        dfs(i); 
        result+=1;
    }
    cout<<result;

}
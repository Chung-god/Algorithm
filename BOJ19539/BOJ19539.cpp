#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> tree;
int one = 0;
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>N;
    for(int i = 0; i < N; i++){
        int temp;
        cin>>temp;
        tree.push_back(temp);
        if(temp == 1) one++; 
    }
    if(one != 0&&one % 2 == 1){ //1의 개수가 홀수면 안됨
        cout<<"NO";
        return 0;
    }
    int odd  = 0;
    int even = 0;
    for(int i = 0; i < N; i++){
        tree[i] = tree[i] % 3;
        if(tree[i] == 1) odd++;
        else if(tree[i] == 2) even++;
    }
    if(even == 0 && odd == 0){
        cout<<"YES";
        return 0;
    }
    if(even ==0 && odd % 2 == 1) cout<<"YES";
    else if(odd % 2 == 1 && even % 2 ==0) cout<<"NO";
    else cout<<"YES";
}
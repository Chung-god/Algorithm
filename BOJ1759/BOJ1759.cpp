#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int length;
int alpN;
vector<char> alp;
vector<char> result;//결과를 담을 벡터
char cnst[5] = {'a','e','i','o','u'};
bool visited[15];
int cnsTrue(vector<char> n){
    int result = 0;
    for(int i =0; i < n.size(); i++)
        for(int j =0; j < 5; j++)
            if(n[i] == cnst[j]){
                result+=1;
                break;
            } 
    return result;
}

void enc(int idx,int cnt){
    if(cnt > length) return;
    if(cnt == length){
        int cns = cnsTrue(result);
        if(cns < 1 ) return;
        if( length - cns < 2) return;
        for(int i = 0;i < alpN; i++){
            if(visited[i]) cout<< alp[i];
        }
        cout<<"\n";
    }

    for(int i = idx; i< alp.size(); i++){
        if(visited[i]) continue;
        visited[i] = true;
        result.push_back(alp[i]);
        enc(i,cnt+1);
        visited[i] = false;
        result.pop_back();
    }
}

int main() {
    cin>>length>>alpN;
    for(int i = 0; i < alpN; i++){
        char temp;
        cin>>temp;
        alp.push_back(temp);
    }
    sort(alp.begin(),alp.end());
    enc(0,0);
}
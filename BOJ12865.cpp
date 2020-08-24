#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int,int> > Bag;
int N,K;
int Max;
int W;
int money = 0;
bool visited[101];
bool sortbyfirst(const pair<int,int> &a, const pair<int,int> &b){
    return a.first < b.first;
}

void Pack(int index){// 담은 중량, 돈
    if(W <= 0)  return;
    
    for(int i = index; i < N; i++){
        int w = Bag[i].first;
        int m = Bag[i].second; 
        W -= w;        
        if(W >= 0){
            if(visited[i])

        }else{
            W += w;
        }
    }
}
int main(){
    cin>>N>>K;
    W = K;
    for(int i = 0; i < N; i++){
        int t1,t2;
        cin>>t1>>t2;
        Bag.push_back(make_pair(t1,t2));//무게와 가격
    }
    sort(Bag.begin(),Bag.end(),sortbyfirst);

    for(int i = 0 ; i < Bag.size(); i++){
        cout<<Bag[i].first<<' '<<Bag[i].second<<"\n";
    }


}
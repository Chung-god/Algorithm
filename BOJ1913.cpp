#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<int, int > > cfn;
vector<pair<int, int > > result;

bool small(pair<int,int> p1, pair<int,int> p2){
    if(p1.second < p2.second) return 1;
    else if(p1.second == p2.second){
        if(p1.first < p2.first) return 1;
        else return 0;
    }
    return 0;
}
int main(){
    int j = 0;
    cin>>N;
    for(int i = 0; i < N; i++){
        int p1,p2;
        cin>>p1>>p2;
        cfn.push_back(make_pair(p1,p2));
    }
    sort(cfn.begin(),cfn.end(),small);
    // for(int i = 0; i < N; i++){
    //     cout<<cfn[i].first<<", "<<cfn[i].second<<"\n";
    // }

    result.push_back(cfn[0]);
    
    for(int i = 1; i < N; i++){
        if(cfn[i].first >= result[j].second){
            result.push_back(cfn[i]);
            j++;
           // cout<<cfn[i].first<<","<<cfn[i].second<<" ";
        } 
    }
    cout<<j+1;
}

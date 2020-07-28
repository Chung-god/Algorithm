#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int cross[101];
vector<pair<int,int> > line;
int N;
int total = 0;
void crossFind(int t,int first,int second){
    if(t ==0 || t ==1 ) return;
    for(int i = 0; i <line.size(); i++ ){
        if(line[i].first > first){
            if(line[i].second < second){
                total +=1;
                cross[first] +=1;
                cross[line[i].first] +=1;
            } 
        }else{
            if(line[i].second > second){
                total +=1;
                cross[first] +=1;
                cross[line[i].first] +=1;
            }
        }
    }
}

void removeLine(){
    int a = 0;
    int max = 0;
    for(int i = 1; i < 501; i++){
        if(a == N) break;
        if(!cross[i]){
            a++; 
            continue;
        }
        if(cross[i] > max) max = cross[i];
    }
    total -= max;
        

}
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>N;
    int t1,t2;
    for(int i = 0; i < N; i++){
        cin>>t1>>t2;
        crossFind(i,t1,t2);
        line.push_back(make_pair(t1,t2));
    }
    for(int i = 0; i < 101; i++)
        cout<<cross[i]<<" ";
    cout<<"\ntotal : "<<total;

    while(total > 0){
        removeLine();
    }
}
#include <iostream>
#include <vector>
using namespace std;
int N;
vector<pair<int, int> > v;
int line[101];
int visited[101];
int cross(pair<int,int> p1, pair<int,int> p2){
    if((p1.first > p2.first) && (p1.second < p2.second)) return 1;
    if((p1.first < p2.first) && (p1.second > p2.second)) return 1;
    return 0;
}
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>N;

    for(int i = 0; i < N; i++){
        int p1,p2;
        cin>>p1>>p2;
        v.push_back(make_pair(p1,p2));
    }
    int temp = N;
    int crossPoint = 0;
    int result = 0;
    while(true){ 
        for(int i = 0; i < temp; i++){
            for(int j = 0; j < temp; j ++){
                if(i == j) continue;
                if(cross(v[i],v[j])){ 
                    line[i]++;
                    crossPoint++;
                }
            }
        }
        if(crossPoint == 0) break;
        int maxIndex = 0;
        for(int i = 0; i < N; i++){
            if(line[maxIndex] < line[i] && (visited[i]==false)){
                maxIndex = i;
            }
        }
        visited[maxIndex] = true;//방문
        result++;
        crossPoint -= line[maxIndex];
        line[maxIndex] = 0;
        temp--;
    }
    for(int i = 0; i < N; i++) cout<<line[i]<<" ";
    cout<<result;
}
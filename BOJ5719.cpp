#include <iostream>
#include <vector>
#include <queue> //우선순위힙을 사용하기 위해
using namespace std;

int N,M;//장소 수, 도로 수 
int S,D;//시작점, 도착점
int U,V,P; //U에서 V 로 가는 도로의 길이 P

vector<pair<int,int> > road[501]; 
vector<pair<int,int> > info[501];//도로들의 정보
int d[501];
int INF = 100000000;

void dijkstra(int start){
    d[start] = 0;
    priority_queue<pair<int,int> > pq; 
    pq.push(make_pair(start,0));

    while(!pq.empty()){
        int current = pq.top().first;
        int distance = -pq.top().second;
        pq.pop();
        if(d[current]<distance) continue;
        for(int i =0; i < road[current].size();i++){
            int next = road[current][i].first;
            int nextDistance = distance + road[current][i].second;
            cout<<current<<"->"<<road[current][i].first<< ": "<<road[current][i].second<<"\n";
            //간선들의 정보 담기
            if(nextDistance < d[next]){
                d[next] = nextDistance;
                pq.push(make_pair(next,-nextDistance));
            }
        }
    }
}

int main(){
    cin>>N>>M;
    cin>>S>>D;
    for(int i = 0; i < N; i++){
        d[i] = INF;
    }
    for(int i = 0; i < M; i++){
        cin>>U>>V>>P;
        road[U].push_back(make_pair(V,P));
    }

    dijkstra(S);

    for(int i = 1; i < N; i++)
        printf("%d ",d[i]);

}
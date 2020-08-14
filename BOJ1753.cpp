#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N,time,start;
int INF = 100000000;

vector<pair<int, int> > a[20002];
int d[20001];

void dijkstra(int start){
    d[start] = 0;
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0,start));

    while(!pq.empty()){
        int current = pq.top().second;
        int distance = -pq.top().first;
        pq.pop();
        if(d[current]< distance) continue;
        for(int i = 0; i < a[current].size(); i++){
            int next = a[current][i].first;
            int nextDistance = distance + a[current][i].second;
            if(nextDistance < d[next]){
                d[next] = nextDistance;
                pq.push(make_pair(-nextDistance,next));
            }
        }
    }
} 

int main(void){
    scanf("%d%d%d",&N,&time,&start);
    for(int i = 1; i <= N; i++){
        d[i] = INF;
    }
    while(time--){
        int first,end,money;
        scanf("%d%d%d",&first,&end,&money);
        a[first].push_back(make_pair(end,money));
    }
    dijkstra(start);

    for(int i = 1; i <= N; i++){
        if(d[i] >= INF)
            printf("INF\n");
        else
            printf("%d\n",d[i]);
    }
}
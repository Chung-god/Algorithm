//최대힙과 최소힙 활용하기 
#include <iostream>
#include <queue>
using namespace std;

priority_queue<int, vector<int>,less<int> > max_heap;
priority_queue<int, vector<int>,greater<int> > min_heap;

//1. 최대 힙의 크기는 최소 힙의 크기와 같거나 하나 더 큼
//2. 최대 힙의 최대 원소는 최소 합의 최소 원소보다 작거나 같다.

int main(){
    int N;
    scanf("%d",&N);
    while(N--){
        int temp;
        scanf("%d",&temp);
        if(max_heap.empty()) max_heap.push(temp);
        else if(max_heap.size() == min_heap.size())
            max_heap.push(temp);
        else min_heap.push(temp);


        if(!max_heap.empty()&&!min_heap.empty()&& !(max_heap.top() <= min_heap.top())){
            int t1 = max_heap.top();
            int t2 = min_heap.top();

            max_heap.pop();
            min_heap.pop();

            max_heap.push(t2);
            min_heap.push(t1);
        }
        printf("%d\n",max_heap.top());
    }

}
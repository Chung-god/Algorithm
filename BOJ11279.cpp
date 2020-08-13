//cout 를 사용하면 시간 초과가 뜬다. 
#include <iostream>
#include <queue>
using namespace std;

int N;
int num;

priority_queue<int,vector<int>,less<int> > minheap;

int main(){
    scanf("%d",&N);
    while(N--){
        scanf("%d",&num);
        if(num == 0 ){
            if(minheap.empty()) {
                printf("0\n");
            }
            else{
                printf("%d\n",minheap.top());
                minheap.pop();
            }
        }else{
            minheap.push(num);
        }
    }
}
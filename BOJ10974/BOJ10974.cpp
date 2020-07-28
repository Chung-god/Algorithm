#include <iostream>
#include <vector>
using namespace std;
int arr[8] = {1,2,3,4,5,6,7,8}; 
bool Select[9];//Select 가 8이 아니라 9
int N;
vector<int> v;

void printArr(){
    for(int i =0;i < 8; i++){
        if(Select[i])
            cout<<v[i]<<" ";
    }    
    printf("\n");
}

void permutation(int cnt){
    if(cnt == N){
        printArr();
        return;
    }
    for(int i = 0; i < N;i++){
        if(Select[i]) continue;
        Select[i]=true;
        v.push_back(arr[i]);
        permutation(cnt+1);
        v.pop_back();
        Select[i]=false;
    }
}
int main() {
    scanf("%d",&N);
    permutation(0);
}
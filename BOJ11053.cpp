#include <iostream>
using namespace std;

int DP[1001];
int N;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>N;
    for(int i = 0; i < N; i++){
        cin>>DP[i];
    }
    int max;
    int result = 1;
    int flag = false;
    for(int i = 1; i < N; i++){
        if(flag){
            if(DP[i] > max){
                max = DP[i];
                result++;
                continue;
            }
            continue;
        }
        if(!flag&&(DP[i] > DP[i-1])){
            flag = true;
            result++;
            max = DP[i];
        }
    }
   
    cout<<result;
}
#include <iostream>
#include <vector>
using namespace std;

int arr[1001];
int dp[1001];
int N;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>N;
    int max = 0;
    for(int i = 0; i < N; i++)
        cin>>arr[i];
    for(int i =0; i < N; i++){
        int min = 0;
        for(int j = 0; j < i; j++){
            if(arr[i] > arr[j]){
                if(min < dp[j]) 
                    min = dp[j];
            }
        }
        dp[i] = min + 1;
        if(max < dp[i]) max = dp[i];
    }
    for(int i = 0; i < N; i++) cout<<dp[i]<<" ";
}
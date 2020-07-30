#include <iostream>
using namespace std;
int N;
int DP[501][501];

int MAX(int a,int b){
    return a>b? a:b;
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n,result = -1;
    cin>>n;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <=i; j++)
            cin>>DP[i][j];

    for(int i = 2; i <= n; i++){
        for(int j = 1; j <=i; j++){
            if(j==1) DP[i][j] += DP[i-1][j];
            else if(j==n) DP[i][j] += DP[i-1][j-1];
            else DP[i][j] += MAX(DP[i-1][j],DP[i-1][j-1]); 
        }
    }

    for(int i = 1; i<=n; i++){
        result = MAX(result,DP[n][i]);
    }
    cout<<result;
}
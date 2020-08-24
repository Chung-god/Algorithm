#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    int temp;
    int n = 0;
    vector<int> v;
    
    cin>>N;
    
    while(n++ < N){
        cin>>temp;
        v.push_back(temp);
        sort(v.begin(),v.end());
 
        if(n == 1){
            cout<<v[0]<<"\n";
            continue;
        }else if(n == 2){
            int temp = v[0] < v[1]? v[0] : v[1];
            cout<<temp<<"\n";
            continue;
        } 
        
        if(n % 2 ==0){
            int index = n/2;
            int temp = v[index] < v[index-1] ? v[index] : v[index-1];
            cout<<temp<<"\n";
        }else{
            int index = n/2;
            cout<<v[index]<<"\n";
        }
    }
}
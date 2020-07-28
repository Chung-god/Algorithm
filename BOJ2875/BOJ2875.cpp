#include <iostream>
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int W,M,Contest;//여자,남자,대회수
    int rest;//남은 학생 수 
    int team;
    cin>>W>>M>>Contest;
    if(W > 1 && M > 0) team = (W/2 > M)? M : W/2;
    else team = 0;
    //cout<<"team is : "<<team;
    rest = W + M - team*3;
    if(Contest <= rest){
        cout<<team;
    }else{
        Contest -= rest;
        while(Contest > 0){
            Contest -= 3;
            team -= 1;
        }
        if(team < 0) team = 0;
        cout<<team;
    }

}
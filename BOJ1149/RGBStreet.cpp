#include <iostream>
#include <vector>
using namespace std;
int RGB[1001][3];
int leastArr[1001];
int result = 0;

int cmpColor(int idx){
   if(leastArr[idx] == leastArr[idx+1]) return 0;
   return 1; 
}

void changeColor(int idx){
    int p0 = RGB[idx][(leastArr[idx]+1)%3] - RGB[idx][leastArr[idx]];
    int p1 = RGB[idx][(leastArr[idx]+2)%3] - RGB[idx][leastArr[idx]];
    int p2 = RGB[idx+1][(leastArr[idx+1]+1)%3]-RGB[idx+1][leastArr[idx+1]];
    int p3 = RGB[idx+1][(leastArr[idx+1]+2)%3]-RGB[idx+1][leastArr[idx+1]];
    int cmp[4] = {p0,p1,p2,p3};
    int min = 100000;
    int index;
    // for(int i = 0 ; i < 4; i++)
    //     cout<< "cmp"<<i<<" : "<<cmp[i]<<"\n";
    for(int i =0; i < 4; i++){
        if(cmp[i] < min){
            min = cmp[i];
            index = i;
        }  
    }
    //cout<<"min index : "<<index<<"\n"; 
    result += min;
    switch(index){
        case 0:
            leastArr[idx] = (leastArr[idx]+1)%3;
            break;
        case 1:
            leastArr[idx] = (leastArr[idx]+2)%3;
            break;
        case 2:
            leastArr[idx+1] = (leastArr[idx+1]+1)%3;
            break;
        case 3:
            leastArr[idx+1] = (leastArr[idx+1]+2)%3;
            break;
    }
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin>>N;
    for(int i = 0; i < N; i++)
        for(int j =0; j < 3; j++)
            cin>>RGB[i][j]; 
    for(int i = 0; i < N; i++){ //최소값 더하는 반복문
        int r1 = (RGB[i][0] < RGB[i][1]) ? 0 : 1;  
        int r2 = r1 < RGB[i][2] ? r1 : 2;
        result += RGB[i][r2];
        leastArr[i] = r2; 
        // cout<<leastArr[i]<<" ";
    }
    
    for(int i = 0; i < N-1; i++){
        if(cmpColor(i)) continue; 
        else changeColor(i);
    }
    // cout<<"\n";
    //  for(int i = 0; i < N; i++){ //최소값 더하는 반복문
    //     cout<<leastArr[i]<<" ";
    // }

    cout<<result;
}
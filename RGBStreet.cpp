#include <iostream>
using namespace std;

long long int N;
long long int RGB[1001][3];
int main(){
    cin>>N;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < 3; j++)
            cin>>RGB[i][j];
    
    
    for(int i = 1; i < N; i++){
        for(int j = 0; j < 3; j++){
            if(j == 0){ //빨강
                RGB[i][j] += (RGB[i-1][1] > RGB[i-1][2]) ? RGB[i-1][2] : RGB[i-1][1];
            }else if(j == 1){//초록
                RGB[i][j] += (RGB[i-1][0] > RGB[i-1][2]) ? RGB[i-1][2] : RGB[i-1][0];
            }else{//파랑
                RGB[i][j] += (RGB[i-1][0] > RGB[i-1][1]) ? RGB[i-1][1] : RGB[i-1][0];
            }
        }
    }



    // for(int i = 0; i < N; i++){
    //     for(int j = 0; j < 3; j++)
    //         cout<<RGB[i][j]<<" ";
    //     cout<<"\n";
    // }

    int min = RGB[N-1][0];
    for(int i = 0 ; i < 3; i++)
        if(RGB[N-1][i] < min) min = RGB[N-1][i];
    cout<<min;
}
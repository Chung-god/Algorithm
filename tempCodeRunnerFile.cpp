#include <iostream>
using namespace std;

int N;
int minus1 = 0,zero = 0, plus1 = 0 ;
int paper[3000][3000];

bool nineSame(int x, int y,int size){ //size 는 n/3 이어야함
    int temp = paper[x][y];
    for(int i = x; i < x + size; i++)
        for(int j = y; j < y + size; j++)
            if(paper[i][j]!= temp) return false;
    return true;
}

void cutPaper(int x, int y,int n){
    int gap = n/3;
    for(int i = x; i < x + n; i=i+gap){
        for(int j = y; j < y + n; j=j+gap){
            if(nineSame(i,j,gap)){
                //cout<<"Same "<<i<<","<<j;
                if(paper[i][j] == -1){
                     minus1++;
                 //    cout<<" minus1\n";
                }
                else if(paper[i][j] == 0){
                     zero++;
               //     cout<<" zero\n";
                }
                else{ 
                    plus1++;
             //       cout<<" Plus1\n";
                }
            }
            else{
                //cout<<"different "<<i<<","<<j<<"\n";
                cutPaper(i,j,n/3);
                //cout<<"\n";
            }
        }
    }
}

int main(){
    cin>> N;
    
    if(N == 1){
        int temp;
        cin>>temp;
        if(temp == 1) plus1++;
        else if(temp == -1) minus1++;
        else zero++;

        cout<<minus1<<"\n"<<zero<<"\n"<<plus1<<"\n";
        return 0;
    }

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            int temp;
            cin>>temp;
            paper[i][j] = temp;
        }
    }
    

    
    cutPaper(1,1,N);
    cout<<minus1<<"\n"<<zero<<"\n"<<plus1<<"\n";
}
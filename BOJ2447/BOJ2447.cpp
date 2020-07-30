#include <iostream>
using namespace std;


void star(int N){
    if(N == 1){
        for(int i = 0; i < 9; i++){
            if(i % 3 == 0&&i != 0) printf("\n");
            if(i == 4) printf(" ");
            else printf("*");
        }
    }
    
}
int main(){
    star(1);
    star(1);
}
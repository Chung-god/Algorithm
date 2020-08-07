#include <stdio.h>

int City;
int Bus;
int map[102][102];
int INF = 1000000000;
void floydWarshall(){
    for(int k = 1; k <= City; k++){
        for(int i = 1; i <=City; i++){
            for(int j = 1; j <= City; j++){
                if(map[i][k] + map[k][j] < map[i][j]){
                    map[i][j] = map[i][k] + map[k][j];
                }
            }
        }
    }
}

int main(){
    scanf("%d%d",&City,&Bus);
    for(int i = 0; i < Bus; i++){
        int x,y,m;
        scanf("%d %d %d",&x,&y,&m);
        if(map[x][y] != 0){
            if(map[x][y] > m) map[x][y] = m;
        }
        else map[x][y] = m;
    }
     for(int i = 1; i <= City; i++){
        for(int j = 1 ; j <= City; j++)
            if(i!=j && map[i][j]==0){
                map[i][j] =INF;
            }
            else if(i==j) map[i][j] = 0;
    }

    floydWarshall();
    for(int i = 1; i <= City; i++){
        for(int j = 1 ; j <= City; j++){
            if(map[i][j] == INF){// INF 인 경우 0으로 바꾸어줘야함.
                map[i][j] = 0;
            }
            printf("%d ",map[i][j]);
        }
        printf("\n");
    }
}
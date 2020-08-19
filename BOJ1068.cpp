#include <iostream>

using namespace std;
int node[51];
int N;
int eraseNode;
bool result[51];
void cutTree(int n){
    node[n] = -1;
    for(int i = 0; i < N; i++){
        if(node[i] == n){
            node[i] = -1;
            cutTree(i);
        }
    }
    return;
}

int main(){
    cin>>N;
    int temp = 0;
    int root;
    for(int i = 0; i < N ; i++){
        int temp;
        cin>>temp;
        if(temp == -1){
            root = i;
            temp = -2;
        }
        node[i] = temp;
    }
    cin>>eraseNode;
    if(eraseNode == root) {
        cout<<"0";
        return 0;
    }
   
    cutTree(eraseNode);

    for(int i = 0; i < N; i++){
        if(node[i]==-1){
            result[i] = true;
        }
        result[node[i]] = true;
    }

    for(int i = 0; i < N; i++){
        if(!result[i]) temp++;
    }
    cout<<temp;

}
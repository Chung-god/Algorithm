#include <iostream>

using namespace std;

int arr[100][100];
int main() {
    int r,c;
    cin>>r>>c;
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < r; j++)
        {
            cin>>arr[i][j];
        }
    }
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < r; j++)
        {
            cout<<arr[i][j]<<" ";
        }cout<<"\n";
    }
    
}
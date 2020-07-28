#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) {
    return a > b;
}
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N;
    vector<int> rope;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        rope.push_back(temp);
    }
     sort(rope.begin(), rope.end(), cmp);
    
     int Sum = 0;

     for(int i = 0; i < rope.size(); i++){
        int temp = rope[i] *(i+1);
        if (temp > Sum) Sum = temp;
     }
     cout<<Sum;
}






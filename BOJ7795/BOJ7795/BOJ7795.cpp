#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void cmp(vector<int> a, vector<int> b) {
	int result = 0;
	int temp = 0;
	for (int i = 0;i < a.size();i++) {
		for (int j = temp;j < b.size();j++) {//j = 0 으로 하면 비교를 너무 많이 해야하기 때문에 시간초과가 발생함.
			//이미 계산한거는 계산할 필요가 없음.
			if (a[i] > b[j]) {
				temp += 1;
			}
		}
		result += temp;
	}
	cout << result << "\n";
}
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	while (N--) {
		int NA, NB;
		cin >> NA >> NB;
		vector<int> vA;
		vector<int> vB;
		for (int i = 0;i < NA;i++) {
			int temp;
			cin >> temp;
			vA.push_back(temp);
		}
		for (int i = 0;i < NB;i++) {
			int temp;
			cin >> temp;
			vB.push_back(temp);
		}
		sort(vA.begin(), vA.end());
		sort(vB.begin(), vB.end());
		cmp(vA, vB);
	}
}
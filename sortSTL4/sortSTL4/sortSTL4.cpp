//2���� ������ �̿��ؼ� ���� 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<string, pair<int, int> >a,
	pair<string, pair<int, int> >b) {
	if (a.second.first == b.second.first) {
		return a.second.second > b.second.second;
	}
	else {
		return a.second.first > b.second.first;
	}
}
int main(void) {
	vector<pair<string, pair<int, int> > > v;
	v.push_back(pair<string, pair<int, int> >("����û", pair<int, int>(90, 19990430)));
	v.push_back(pair<string, pair<int, int> >("������", pair<int, int>(90, 19970217)));
	v.push_back(pair<string, pair<int, int> >("������", pair<int, int>(80, 19940803)));
	v.push_back(pair<string, pair<int, int> >("������", pair<int, int>(100, 19620217)));
	v.push_back(pair<string, pair<int, int> >("�ڿ���", pair<int, int>(60, 19621020)));

	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << ' ';
	}
}

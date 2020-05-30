//2개의 기준을 이용해서 정렬 

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
	v.push_back(pair<string, pair<int, int> >("박현청", pair<int, int>(90, 19990430)));
	v.push_back(pair<string, pair<int, int> >("박현강", pair<int, int>(90, 19970217)));
	v.push_back(pair<string, pair<int, int> >("박현은", pair<int, int>(80, 19940803)));
	v.push_back(pair<string, pair<int, int> >("유제광", pair<int, int>(100, 19620217)));
	v.push_back(pair<string, pair<int, int> >("박영수", pair<int, int>(60, 19621020)));

	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << ' ';
	}
}

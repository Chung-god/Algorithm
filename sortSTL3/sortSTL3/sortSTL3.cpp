//실제 대회에서 문제 하나를 풀기 위해 클래스를 정의하고 있는 것은 적절치 않음
//실무에선 많이 씀
//대회에선 페어(Pair) 라이브러리를 사용함

#include <iostream>
#include <vector> //단순배열, 연결리스트 기반 vector 
#include <algorithm>

using namespace std;

int main(void) {
	vector<pair<int, string> > v;
	v.push_back(pair<int, string>(90, "박현청"));
	v.push_back(pair<int, string>(65, "박현강"));
	v.push_back(pair<int, string>(87, "박현은"));
	v.push_back(pair<int, string>(88, "유제광"));
	v.push_back(pair<int, string>(60, "박영수"));

	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].second << ' ';
	}
}

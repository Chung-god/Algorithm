#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int>a, pair<int, int> b) {
	if (a.second < b.second) return true;
	else if (a.second == b.second) return true;
	return false;
}
int main()
{
	int N;
	scanf("%d", &N);;
	vector<pair<int, int> > v(N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &v[i].first, &v[i].second);
	}

	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < N; i++) {
		printf("%d %d\n", v[i].first, v[i].second);
	}
	return 0;
}

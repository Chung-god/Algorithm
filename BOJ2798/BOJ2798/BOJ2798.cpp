#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
vector<int> result;

int MaxSum(int M) {
	int max = 0, sum;//최대 값 , 세수의 합 변수
	
	//반복문을 통해 세수의 합 구하기
	for (int i = 0; i < v.size() - 2; i++) {
		if (v[i] > M) break;
		for (int j = i + 1;j < v.size() - 1;j++) {
			if ((v[i] + v[j]) > M) break;
			for (int k = j + 1; k < v.size(); k++) {
				sum = v[i] + v[j] + v[k];
				//	printf("%d %d %d = %d\n", v[i], v[j], v[k], sum);
				if (sum > M) break;
				else if ((M - sum) < (M - max)) max = sum;
				//구한 최대값의 차가 그전 최대값의 차가 작으면 대입
			}
		}
	}
	return max;
}
int main()
{
	int num, max;
	scanf("%d %d", &num, &max);
	for (int i = 0; i < num; i++) {
		int temp;
		scanf("%d", &temp);
		v.push_back(temp);
	}
	sort(v.begin(), v.end()); //빠른 반복문을 위한 오름차순 정렬

	printf("%d", MaxSum(max));
}
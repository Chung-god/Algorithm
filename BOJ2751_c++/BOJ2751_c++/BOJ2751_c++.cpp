// BOJ2751_c++.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <stdio.h>
#include <algorithm>

int num, data[1000000];

int main()
{
	scanf_s("%d", &num);
	for (int i = 0; i < num; i++)
		scanf_s("%d", &data[i]);

	std::sort(data, data + num);
	for (int i = 0; i < num; i++)
		printf("%d\n", data[i]);
	return 0;
}

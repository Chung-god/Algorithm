#include <iostream>
#include <math.h>
using namespace std;

int N;

void HanoiTower(int num, int from, int by, int to) {
	if (num == 1 && N < 20) {
		printf("%d %d\n",from,to);
	}
	else {
		HanoiTower(num - 1, from, to, by); 
		printf("%d %d\n",from,to);
		HanoiTower(num - 1, by, from, to);
	}
}

int main()
{	
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    scanf("%d",&N);
  
	
	for (i = 0; i < N; i++)
		data *= 2;

	sprintf(str, "%.0Lf", data);
	size = strlen(str);
	str[size - 1] = (char)(((int)(str[size - 1] - 48) - 1) + 48);
	printf("%s\n", str);

	if (N <= 20)
		HanoiTower(N,1,2,3);;
}
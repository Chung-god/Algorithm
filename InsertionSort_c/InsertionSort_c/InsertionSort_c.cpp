#include <stdio.h> 
int main(void) {
	int i, j, temp;
	int array[10] = { 1,10,5,8,7,6,4,3,2,9 };
	for (i = 0; i < 9; i++) {
		j = i;
		while (array[j] > array[j + 1]) {
			temp = array[j];
			array[j] = array[j + 1];
			array[j + 1] = temp;
			j--;
		}
	}

	for (i = 0; i < 10; i++) {
		printf("%d ", array[i]);
	}
}
/*
정렬되어있으면 삽입정렬이 가장 효율적인 알고리즘임.
정렬이 되어 있지 않으면 버블 정렬과 비슷한 시간 복잡도를 가지게 됨
O(N^2)인 세가지 정렬 중에서 가장 효율적 임
*/
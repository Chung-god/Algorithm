#include <stdio.h>

int main(void) {
	int i, j, temp;
	int array[10] = { 1,4,6,7,8,2,3,10,9,5 };

	for (i = 0; i < 10;i++)
		for (j = 0;j < 9 - i; j++) {
			if (array[j] > array[j + 1]) { //앞에 원소가 뒤에 원소보다 작으면 바꿔줌 
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}

	for (i = 0; i < 10; i++)
		printf("%d ", array[i]);

}
//O(N*N) 이지만 선택정렬보다 느림. 
//선택 정렬은 가장 작은 거를 찾아서 마지막에 한번 swap하지만
//버블 정렬은 매번 swap 동작을 수행하기 때문에 선택 정렬보다 수행시간이 오래걸린다. 
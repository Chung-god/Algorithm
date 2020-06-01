#include <stdio.h>

int main(void) {
	int temp;
	int count[6]; //0을 포함시키지 않아서 인덱스 코드 구현을 용이하게 하기 위해 
	int array[30] = {
	1,3,5,2,3,1,3,4,4,3,
	4,2,3,4,3,1,1,2,4,3,
	3,1,2,3,4,5,1,3,2,4 };

	for (int i = 0;i < 5;i++) {
		count[i] = 0;
	}
	for (int i = 0; i < 30; i++) {
		count[array[i]] += 1; //해당 수의 인덱스 수 + 1 
	}

	for (int i = 1; i <= 5; i++) {
		if (count[i] != 0) {
			for (int j = 0; j < count[i]; j++) {
				printf("%d ", i);
			}
		}
	}
}


//SelectionSort
//inefficient Sorting
#include <stdio.h>

int main(void) {
	int i, j, min, index, temp;
	//i,j using repeat
	//least num is min
	// least num in index
	//for swaping 

	int array[10] = { 1,5,7,8,2,9,10,3,6,4 };
	for (i = 0;i < 10; i++) {
		min = 9999;
		for (j = i; j < 10; j++) {//j = i don't touch already sort num
			if (min > array[j]) {
				min = array[j];
				index = j;
			}
		}
		//Swaping : two element values 
		temp = array[i];
		array[i] = array[index];
		array[index] = temp;
	}

	for (i = 0; i < sizeof(array) / sizeof(int);i++) {
		printf("%d ", array[i]);
	}
}

/*
1 2 3 4 5 6 7 8 9 10

10 + 9 + 8 + ... + 1 (equidistant sequence)

=> 10 *(10 + 1)/2 = 55

=> N * (N + 1)/2

=> O(N * N)

*/
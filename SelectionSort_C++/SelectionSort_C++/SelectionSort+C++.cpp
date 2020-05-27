#include <iostream>
using namespace std;

int main() {
	int min, index, temp;
	int array[10] = { 1,5,7,8,2,9,10,3,6,4 };
	
	for (int i = 0; i < 10; i++) {
		min = 9999;
		for (int j = i; j < 10; j++) {
			if (min > array[j]) {
				min = array[j];
				index = j;
			}
		}
		temp = array[i];
		array[i] = array[index];
		array[index] = temp;
	}

	for (int i = 0; i < sizeof(array) / sizeof(int);i++) {
		printf("%d ", array[i]);
	}
}


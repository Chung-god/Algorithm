#include <stdio.h>

int main(void) {
	int i, j, temp;
	int array[10] = { 1,4,6,7,8,2,3,10,9,5 };

	for (i = 0; i < 10;i++)
		for (j = 0;j < 9 - i; j++) {
			if (array[j] > array[j + 1]) { //�տ� ���Ұ� �ڿ� ���Һ��� ������ �ٲ��� 
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}

	for (i = 0; i < 10; i++)
		printf("%d ", array[i]);

}
//O(N*N) ������ �������ĺ��� ����. 
//���� ������ ���� ���� �Ÿ� ã�Ƽ� �������� �ѹ� swap������
//���� ������ �Ź� swap ������ �����ϱ� ������ ���� ���ĺ��� ����ð��� �����ɸ���. 
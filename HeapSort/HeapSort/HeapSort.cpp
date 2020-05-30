#include <stdio.h>

int num = 9;
int heap[9] = { 7,3,1,2,4,8,9,0,10 };

int main(void) {
	int temp;
	//전체 트리 구조를 최대 힙 구조로 바꿉다. 
	//부모 노드로 이동하면서 
	for (int i = 1; i < num; i++) {
		int c = i;
		do {
			int root = (c - 1) / 2;
			if (heap[root] < heap[c]) {
				temp = heap[root];
				heap[root] = heap[c];
				heap[c] = temp;
			}
			c = root;
			//반복문이지만 재귀적 구조
		} while (c != 0);
	}
	//크기를 줄여가며 반복적으로 힙을 구성
	for (int i = num - 1; i >= 0; i--) {
		//가장 큰 값을 제일 뒤로 보냄 -> 오름차순 정렬
		int temp = heap[0];
		heap[0] = heap[i];
		heap[i] = temp;
		int root = 0; 
		int c = 1;
		//힙구조 만들기
		do {
			c = 2 * root + 1; 
			//자식 중에 더 큰 값 찾기
			if (heap[c] < heap[c + 1] && c < i - 1) {
				c++;
			}
			//루트보다 자식 값이 더 크다면 교환
			if (heap[root] < heap[c] && c < i) {
				temp = heap[root];
				heap[root] = heap[c];
				heap[c] = temp;
			}
			root = c;
		} while (c < i);
	}

	for (int i = 0; i < num; i++)
		printf("%d ", heap[i]);
}
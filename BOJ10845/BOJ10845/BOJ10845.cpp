#include <stdio.h>

int main()
{
	int N; //명령어의 수
	int queue[10001];//큐 
	int x;
	scanf("%d", &N);
	int front = 0, back = 0;

	while (N--) {
		char cmd[6];
		scanf("%s", &cmd);
		if (cmd[0] == 'p') {
			if (cmd[1] == 'u') {
				int num;
				scanf("%d", &num);
				queue[back++] = num; //위치를 올리면서 queue에 푸시
			}
			else {
				if (front == back) printf("-1\n");
				else {
					printf("%d\n", queue[front]);
					queue[front++] = NULL;
				}
			}
		}
		else if (cmd[0] == 's') {
			if (back == front) {
				printf("0\n");
				continue;
			}
			printf("%d\n", back - front); //back-front 아님 back 위치를 생각해보면 됨
		}
		else if (cmd[0] == 'f' || cmd[0] == 'b') {
			if (back == front) {
				printf("-1\n");
				continue;
			}
			if (cmd[0] == 'f')
				printf("%d\n", queue[front]);
			else
				printf("%d\n", queue[back - 1]);
		}
		else if (cmd[0] == 'e')
			if (back == front) printf("1\n");
			else printf("0\n");

	}
}
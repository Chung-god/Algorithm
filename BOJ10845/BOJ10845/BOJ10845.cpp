﻿// BOJ10845.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <stdio.h>

int main()
{
	int N; //명령어의 수
	int queue[10000];//큐 
	int x;
	scanf_s("%d", &N);
	int front = 0, back = 0;

	while (N--) {
		char cmd[6];
		scanf_s("%s", &cmd);
		printf("%c", cmd[0], cmd[1]);
		if (cmd[0] == 'p') {
			if (cmd[1] == 'u') {
				int num;
				scanf_s("%d", &num);
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
			printf("%d\n", back - front + 1);
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

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.

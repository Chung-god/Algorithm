// BOJ1018.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
/*
전체를 담을 배열 
8x8을 담을 임시 배열
첫번째 칸이 검은색/흰색
최소 저장할 변수 선언
8x8 체스판 선정
*/

#include <iostream>
#define LEN 8
#define MAX 50

using namespace std;

int M, N;
int minNum = 1000;
//검은색 체스판
char check1[LEN+1][LEN+1] = {
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
};
//흰색 체스판
char check2[LEN+1][LEN+1] = {
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
};
char myCheck[MAX+1][MAX+1];
//입력 받은 체스판

//최소값구하기
void checkMin(int row,int col) {
    int temp1 = 0;
    int temp2 = 0;
    int minTemp;
    for (int i = row,n =0; i < row + LEN; i++,n++) {
        for (int j = col,m =0; j < col + LEN; j++,m++) {
            if (myCheck[i][j] != check1[n][m]) temp1++;
            if (myCheck[i][j] != check2[n][m]) temp2++;
        }
    }
    
    minTemp = (temp1 < temp2) ? temp1 : temp2;
    if (minTemp < minNum) minNum = minTemp;
}

 int main()
{
     //입력 받기
     cin >> M >> N;
     for (int i = 0; i < M; i++)
         for (int j = 0; j < N; j++)
             cin >> myCheck[i][j];
    
    //최소 값 반환 함수 

     for (int i = 0; i <= M - 8; i++) {
        for (int j = 0; j <= N - 8; j++) {
            checkMin(i, j);
        }
    }
     printf("%d", minNum);
     //for (int i = 0; i < M; i++) {
     //    for (int j = 0; j < N; j++) {
     //        cout << myCheck[i][j];
     //    }
     //    cout << endl;
     //}
            
 }

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.  //   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.

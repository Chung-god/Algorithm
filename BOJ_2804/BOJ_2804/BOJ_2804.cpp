// BOJ_2804.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h> // sqrt()
//
//int prime(long long num) {
//    if (num < 2) {
//        return 0;
//    }if (num == 3) {
//        return 1;
//    }if (num % 2 == 0) {
//        return 0;
//    }
//
//    int max = sqrt((double)num);
//    for (int i = 3; i <= max; i=i+2) {
//        if (num % i == 0) {
//            return 0;
//        }
//    }
//    return 1;
//}

long long power(long long x, long long y, long long mod) {
    long long res = 1;
    x %= mod;
    while (y) {
        if (y % 2) res = (res * x) % mod;
        y /= 2;
        x = (x * x) % mod;
    }
    return res;
}

//if n is prime, return true
bool miller(long long n, long long a) {
    if (a % n == 0) return false;
    long long k = n - 1;
    while (1) {
        long long temp = power(a, k, n);
        if (temp == n - 1) return true; //a^k = -1 (mod n)
        if (k % 2) return (temp == 1 || temp == n - 1);
        k /= 2;
    }
}




int prime(long long num) {
  
}
int main()
{
    int m;
    long long k;
    scanf_s("%d %lld", &m, &k);
    int len = 0;
   
    if (prime(k)) {
        while (k != 0) {
            k /= 10;
            len++;
        }
        if (m == len)
            printf("GOD");
        else
            printf("POK*8");
    }
    else {
        printf("POK*8");
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

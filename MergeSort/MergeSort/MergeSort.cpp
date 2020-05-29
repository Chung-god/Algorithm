// MergeSort.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <stdio.h>

int num = 8;
int sorted[8];//결과 배열 
//정렬배열 반드시 전역변수로 만들어야함.  
//불필요한 메모리 사용 최소화
//정렬을 위한 임시 배열
void merge(int a[], int m, int middle, int n) {
    int i = m;
    int j = middle + 1;
    int k = m;
    //작은 순서대로 배열에 삽입
    while (i <= middle && j <= n) {
        if (a[i] <= a[j]) {
            sorted[k] = a[i];
            i++;
        }
        else {
            sorted[k] = a[j];
            j++;
        }
        k++;
    }
    //남은 데이터 삽입
    int t;
    if (i > middle) {
        for (t = j; t <= n;t++)
            sorted[k++] = a[t];
    }
    else {
        for (t = i; t <= middle; t++)
            sorted[k++] = a[t];
    }
    //정렬된 배열 삽입 
    for (t = m; t <= n; t++) {
        a[t] = sorted[t];
    }
}


//일단 반으로 나누고 합친다.
void mergeSort(int a[], int m, int n) {
    //크기가 1보다 큰 경우 
    if (m < n) {
        int middle = (m + n) / 2;
        mergeSort(a, m, middle);
        mergeSort(a, middle + 1, n);
        merge(a, m, middle, n);
    }
}
int main()
{
    int array[8] = { 7,6,5,8,3,5,9,1};
    mergeSort(array, 0, num - 1);
    int i;
    for (i = 0; i < num ;i++)
        printf("%d ", array[i]);

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

// BinaryTree.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

int number = 15;

//하나의 노드 정보를 선언
typedef struct node* treePointer;
typedef struct node {
    int data;
    treePointer leftChild, rightChild;
}node;

//전위 순회 구현
void preorder(treePointer ptr) {
    if (ptr) {
        cout << ptr->data << ' '; // (1) 먼저 자기 자신을 처리
        preorder(ptr->leftChild); // (2) 왼쪽 자식 방문
        preorder(ptr->rightChild); //(3) 오른쪽 자식 방문
    }
}

//중위 순회 구현
void inorder(treePointer ptr) {
    if (ptr) {
        preorder(ptr->leftChild); //(1) 왼쪽 자식 방문
        cout << ptr->data << ' '; //(2) 자기 자신을 처리
        preorder(ptr->rightChild);//(3) 오른쪽 자식 방문
    }
}

//후위 순회 구현
void postorder(treePointer ptr) {
    if (ptr) {      
        preorder(ptr->leftChild); //(1) 왼쪽 자식 방문
        preorder(ptr->rightChild);//(2) 오른쪽 자식 방문
        cout << ptr->data << ' '; //(3) 자기 자신을 처리
    }
}
int main()
{
    node nodes[16];

    //노드 생성
    for (int i = 0; i <= number; i++) {
        nodes[i].data = i;
        nodes[i].leftChild = NULL;
        nodes[i].rightChild = NULL;
    }

    //노드 연결
    for (int i = 1; i <= number; i++) {
        if (i % 2 == 0) {
            nodes[i / 2].leftChild = &nodes[i]; //짝수면 왼쪽 자식이 됨
        }
        else {
            nodes[i / 2].rightChild = &nodes[i]; //홀수면 오른쪽 자식이 됨
        }
    }

    //전위 진행
    printf("전위순회 방문 순서: ");
    preorder(&nodes[1]);
    printf("\n\n");
    printf("중위순회 방문 순서: ");
    inorder(&nodes[1]);
    printf("\n\n");
    printf("후위순회 방문 순서: ");
    postorder(&nodes[1]);
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

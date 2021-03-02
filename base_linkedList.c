 
#include <stdio.h>
#include <string.h>

/*단일 연결리스트*/

typedef struct { //노드에 담을 자료 멤버
	int num;
	char *name;
}Member;

//노드
typedef struct __node {
	Member data;
	struct __node *next;
}Node;

//연결리스트
typedef struct _list{
	Node *head;  //머리 노드에 대한 포인터
    int size; //리스트 크기
}List;

//단순 연결 리스트를 초기화 & 할당하는 함수
List *listInit() {
    // 리스트를 선언
    List *newList;
    newList = (List *)malloc(sizeof(List));
    // 새로운 리스트의 head 초기화
    newList->head = NULL;
    newList->size = 0;
    return newList;
}

//노드를 초기화하는 함수
Node *nodeInit(char *str, int N) {
    Node *newNode = (Node *)malloc(sizeof(Node));

    newNode->data.name = (char *)malloc(strlen(str) + 1);
    strcpy(newNode->data, str);
    newNode->data.num = N;
    // 새로운 노드의 포인터를 NULL로 지정
    newNode->next = NULL;

    return newNode;
}

//리스트에 노드를 추가

//리스트의 끝에 노드를 추가하는 함수
void addLast(LinkedList *list, char *str, int N) {
    // 새로운 노드를 생성하고 newNode 변수에 할당
    Node *newNode = nodeInit(str,N);
    // selectNode : 리스트의 노드를 선택하기 위한 변수. 리스트의 head부터 시작
    Node *selectNode = list->head;

    // 리스트에 노드가 없는 경우
    if (list->head == NULL) {
        list->head = newNode;
    }
    // 리스트에 노드가 있는 경우
    else {
        // while문으로 리스트의 head부터 마지막 노드까지 이동
        while (selectNode->next != NULL) {
            selectNode = selectNode->next;
        }
        // 마지막 노드의 next를 새로운 노드로 지정
        selectNode->next = newNode;
    }
    // 리스트에 노드가 추가되었으니 +1
    list->size++;
}

//리스트의 처음에 노드 추가
void addFirst(LinkedList *list, char *str, int N) {
    Node *newNode = nodeInit(str, N);

    if (list->head == NULL) {
        list->head = newNode;
    }
    else {
        newNode->next = list->head;
        list->head = newNode;
    }
    list->size++;
}

//리스트의 head로부터 n번째 위치에 노드를 추가
void addNodeAt(LinkedList *list, char *str,int N, int n) { //data & n번째
    Node *newNode;
    Node *selectNode = list->head;
    int i;

    // 리스트에 노드가 없거나 인수 n의 값이 올바르지 않을 경우
    if (list->size == 0 || n < 0 || list->size - 1 < n) {
        // 리스트의 마지막에 노드를 추가
        addLast(list, str, N);
        // 함수를 종료
        return 0;
    }

    // 새로운 노드를 만들고 newNode에 할당
    newNode = nodeInit(str);

    if (n == 0) {
        newNode->next = list->head;
        list->head = newNode;
    }
    else {
        // 리스트의 head부터 시작해서 추가할 n번째 위치 이전의 노드(-1)까지 이동
        for (int i = 0; i < n - 1; i++) {
            selectNode = selectNode->next;
        }
        // 새로운 노드의 next를 현재의 n번째 노드로 설정
        newNode->next = selectNode->next;
        // 현재의 n-1번째 노드의 next를 새로운 노드의 설정
        selectNode->next = newNode;
    }
    list->size++;
}

/*이중 연결리스트*/
/*이중 연결리스트*/


typedef struct { //노드에 담을 자료 멤버
    int num;
    char *name;
}Member;

//노드
typedef struct __node {
    //Member data; -> 데이터 여러개 담을 수도 있음
    char *data;
    struct __node *prev;
    struct __node *next;
}Node;

//연결리스트
//header&trailer 존재
typedef struct _list {
    Node *header;  //머리 노드에 대한 포인터
    Node *trailer;
    int size; //리스트 크기
}List;

//단순 연결 리스트를 초기화 & 할당하는 함수
List *listInit() {
    // 리스트를 선언
    List *newList;
    newList = (List *)malloc(sizeof(List));
    // 새로운 리스트의 head 초기화
    newList->header->next = newList->trailer;
    newList->trailer->prev = newList->header;
    newList->header->prev = NULL;
    newList->trailer->next = NULL;

    newList->size = 0;
    return newList;
}

//노드를 주어진 문자열로 초기화하는 함수
Node *nodeInit(char *str) {
    Node *newNode = (Node *)malloc(sizeof(Node));

    newNode->data.name = (char *)malloc(strlen(str) + 1);
    strcpy(newNode->data, str);

    newNode->next = NULL;

    return newNode;
}

/*추가*/ //-> 여기부터

//리스트의 끝에 노드를 추가하는 함수
void addLast(List *list, char *str) {
    Node *newNode = nodeInit(str);
    Node *selectNode = list->head;

    // 리스트에 노드가 없는 경우
    if (list->head == NULL) {
        list->head = newNode;
    }
    // 리스트에 노드가 있는 경우
    else {
        while (selectNode->next != NULL) {
            selectNode = selectNode->next;
        }
        selectNode->next = newNode;
    }
    list->size++;
}

//리스트의 처음에 노드 추가
void addFirst(List *list, char *str) {
    Node *newNode = nodeInit(str);

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
void addNodeAt(List *list, char *str, int n) {
    Node *newNode;
    Node *selectNode = list->head;
    int i;

    if (list->size == 0 || n < 0 || list->size - 1 < n) {
        addLast(list, str);
        return 0;
    }

    newNode = nodeInit(str);

    if (n == 0) {
        newNode->next = list->head;
        list->head = newNode;
    }
    else {
        for (int i = 0; i < n - 1; i++) {
            selectNode = selectNode->next;
        }
        newNode->next = selectNode->next;
        selectNode->next = newNode;
    }
    list->size++;
}

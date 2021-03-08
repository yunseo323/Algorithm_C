/*���� ���Ḯ��Ʈ*/


typedef struct { //��忡 ���� �ڷ� ���
    int num;
    char *name;
}Member;

//���
typedef struct __node {
    //Member data; -> ������ ������ ���� ���� ����
    char *data;
    struct __node *prev;
    struct __node *next;
}Node;

//���Ḯ��Ʈ
//header&trailer ����
typedef struct _list {
    Node *header;  //�Ӹ� ��忡 ���� ������
    Node *trailer;
    int size; //����Ʈ ũ��
}List;

//�ܼ� ���� ����Ʈ�� �ʱ�ȭ & �Ҵ��ϴ� �Լ�
List *listInit() {
    // ����Ʈ�� ����
    List *newList;
    newList = (List *)malloc(sizeof(List));
    // ���ο� ����Ʈ�� head �ʱ�ȭ
    newList->header->next = newList->trailer;
    newList->trailer->prev = newList->header;
    newList->header->prev = NULL;
    newList->trailer->next = NULL;

    newList->size = 0;
    return newList;
}

//��带 �־��� ���ڿ��� �ʱ�ȭ�ϴ� �Լ�
Node *nodeInit(char *str) {
    Node *newNode = (Node *)malloc(sizeof(Node));

    newNode->data.name = (char *)malloc(strlen(str) + 1);
    strcpy(newNode->data, str);

    newNode->next = NULL;

    return newNode;
}

/*�߰�*/ //-> �������

//����Ʈ�� ���� ��带 �߰��ϴ� �Լ�
void addLast(List *list, char *str) {
    Node *newNode = nodeInit(str);
    Node *selectNode = list->head;

    // ����Ʈ�� ��尡 ���� ���
    if (list->head == NULL) {
        list->head = newNode;
    }
    // ����Ʈ�� ��尡 �ִ� ���
    else {
        while (selectNode->next != NULL) {
            selectNode = selectNode->next;
        }
        selectNode->next = newNode;
    }
    list->size++;
}

//����Ʈ�� ó���� ��� �߰�
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

//����Ʈ�� head�κ��� n��° ��ġ�� ��带 �߰�
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

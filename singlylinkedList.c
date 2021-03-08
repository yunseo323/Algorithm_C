 
#include <stdio.h>
#include <string.h>

/*���� ���Ḯ��Ʈ*/

typedef struct { //��忡 ���� �ڷ� ���
	int num;
	char *name;
}Member;

//���
typedef struct __node {
	//Member data; -> ������ ������ ���� ���� ����
    char *data;
	struct __node *next;
}Node;

//���Ḯ��Ʈ
typedef struct _list{
	Node *head;  //�Ӹ� ��忡 ���� ������ -> ������ ���� �ٷ� ��
    int size; //����Ʈ ũ��
}List;

//�ܼ� ���� ����Ʈ�� �ʱ�ȭ & �Ҵ��ϴ� �Լ�
List *listInit() {
    // ����Ʈ�� ����
    List *newList;
    newList = (List *)malloc(sizeof(List));
    // ���ο� ����Ʈ�� head �ʱ�ȭ
    newList->head = NULL;
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


/*�߰�*/

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



/*����*/


//������ ��� ����
void removeLast(List *list) {
    // prvNode : ���� ���������� �ι�° ��带 ���� ����
    Node *prvNode;
    Node *selectNode = list->head;

    if (list->head == NULL) return;

    // ����Ʈ�� ��尡 �ϳ��� ��� head�� ������ ��带 ����
    if (list->head->next == NULL) {
        free(list->head->data);
        free(list->head);
        list->head = NULL;
    }
    // ����Ʈ�� ��尡 �ϳ� �̻��� ���
    else {
        while (selectNode->next != NULL) {
            prvNode = selectNode;
            selectNode = selectNode->next;
        }
        
        free(selectNode->data);
        free(selectNode);
        // prvNode�� ������ ���� ����
        prvNode->next = NULL;
    }
    
    list->size--;
}

//ù��° ��� ����
void removeLast(List *list) {
    Node *nextNode; //head �������
    Node *selectNode = list->head;

    // ����Ʈ�� ��尡 ���°�� �Լ��� ����
    if (list->head == NULL) return;

    // ����Ʈ�� ��尡 �ϳ��� ��� head�� ������ ��带 ����
    if (list->head->next == NULL) {
        free(list->head->data);
        free(list->head);
        list->head = NULL;
    }
    // ����Ʈ�� ��尡 �ϳ� �̻��� ���
    else {
        nextNode = list->head->next;

        free(selectNode->data);
        free(selectNode);
        
        list->head = nextNode;
    }
    list->size--;
}

// ����Ʈ�� head�κ��� n��° ��ġ�� ��带 ����
void removeNodeAt(List *list, int n) {
    Node *selectNode = list->head;
    Node *deleteNode;
    int i;

    // ����Ʈ�� ��尡 ���ų� �μ� n�� ���� �ùٸ��� ���� ���
    if (list->head == NULL || n < 0 || list->size - 1 < n) {
        return;
    }

    if (n == 0) {
        list->head = list->head->next;
        free(selectNode->data);
        free(selectNode);
        list->size--;
    }
    
    else {
        // ����Ʈ�� head���� �����ؼ� ������ n��° ��ġ�� ���� ���� �̵�
        for (int i = 0; i < n - 1; i++) {
            selectNode = selectNode->next;
        }
        
        deleteNode = selectNode->next;        
        selectNode->next = selectNode->next->next;
        // ��� ����
        free(deleteNode->data);
        free(deleteNode);
        list->size--;
    }
}

/*Ž��*/

// searchNodes : ���ڿ� str�� head�κ��� ���° ��ġ�� �ִ��� Ȯ�� -> ����
void searchArrNodes(List *list, char *str) {
    // access[] : ��ġ�� ������ �迭�� ���� (���� ������ �����Ͱ� �������� ������)
    int access[100] = { -1 };
    int accessCount = 0;
    // selectNode : ����Ʈ�� ��带 �����ϱ� ���� ����. ����Ʈ�� head���� ����
    Node *selectNode = list->head;
    int i;

    // ����Ʈ�� head���� ������ ������ ����
    for (i = 0; i < list->size; i++) {
        if (!strcmp(selectNode->data, str)) {
            // ���� ���� ���ڿ��� �ִٸ� access �迭�� ��ġ�� ����
            access[accessCount] = i;
            // ���� ǥ���ϱ����� �迭�� ������ ������ ���� -1�� ����
            access[accessCount + 1] = -1;
            accessCount++;
        }
        selectNode = selectNode->next;
    }

    // �˻� ����� ���
    // access�� ���� ���� �ʾ����� �ش� �����Ͱ� ������ ���
    if (access[0] == -1) {
        printf("%s Not Found!\n\n", str);
    }
    // �ش� �����Ͱ� �����ÿ� ��ġ�� ���
    else {
        for (int i = 0; i < 100; i++) {
            if (access[i] == -1) {
                break;
            }
            else {
                printf("%d ", access[i]);
            }
        }
        printf("\n\n");
    }
}

//��� ������ ���
void printList(List *list) {
    Node *selectNode = list->head;

    // ���
    while (selectNode != NULL) {
        printf("%s", selectNode->data);
        selectNode = selectNode->next;
        if (selectNode != NULL) {
            printf("\n");
        }
    }
}
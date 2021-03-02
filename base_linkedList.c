 
#include <stdio.h>
#include <string.h>

/*���� ���Ḯ��Ʈ*/

typedef struct { //��忡 ���� �ڷ� ���
	int num;
	char *name;
}Member;

//���
typedef struct __node {
	Member data;
	struct __node *next;
}Node;

//���Ḯ��Ʈ
typedef struct _list{
	Node *head;  //�Ӹ� ��忡 ���� ������
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

//��带 �ʱ�ȭ�ϴ� �Լ�
Node *nodeInit(char *str, int N) {
    Node *newNode = (Node *)malloc(sizeof(Node));

    newNode->data.name = (char *)malloc(strlen(str) + 1);
    strcpy(newNode->data, str);
    newNode->data.num = N;
    // ���ο� ����� �����͸� NULL�� ����
    newNode->next = NULL;

    return newNode;
}

//����Ʈ�� ��带 �߰�

//����Ʈ�� ���� ��带 �߰��ϴ� �Լ�
void addLast(LinkedList *list, char *str, int N) {
    // ���ο� ��带 �����ϰ� newNode ������ �Ҵ�
    Node *newNode = nodeInit(str,N);
    // selectNode : ����Ʈ�� ��带 �����ϱ� ���� ����. ����Ʈ�� head���� ����
    Node *selectNode = list->head;

    // ����Ʈ�� ��尡 ���� ���
    if (list->head == NULL) {
        list->head = newNode;
    }
    // ����Ʈ�� ��尡 �ִ� ���
    else {
        // while������ ����Ʈ�� head���� ������ ������ �̵�
        while (selectNode->next != NULL) {
            selectNode = selectNode->next;
        }
        // ������ ����� next�� ���ο� ���� ����
        selectNode->next = newNode;
    }
    // ����Ʈ�� ��尡 �߰��Ǿ����� +1
    list->size++;
}

//����Ʈ�� ó���� ��� �߰�
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

//����Ʈ�� head�κ��� n��° ��ġ�� ��带 �߰�
void addNodeAt(LinkedList *list, char *str,int N, int n) { //data & n��°
    Node *newNode;
    Node *selectNode = list->head;
    int i;

    // ����Ʈ�� ��尡 ���ų� �μ� n�� ���� �ùٸ��� ���� ���
    if (list->size == 0 || n < 0 || list->size - 1 < n) {
        // ����Ʈ�� �������� ��带 �߰�
        addLast(list, str, N);
        // �Լ��� ����
        return 0;
    }

    // ���ο� ��带 ����� newNode�� �Ҵ�
    newNode = nodeInit(str);

    if (n == 0) {
        newNode->next = list->head;
        list->head = newNode;
    }
    else {
        // ����Ʈ�� head���� �����ؼ� �߰��� n��° ��ġ ������ ���(-1)���� �̵�
        for (int i = 0; i < n - 1; i++) {
            selectNode = selectNode->next;
        }
        // ���ο� ����� next�� ������ n��° ���� ����
        newNode->next = selectNode->next;
        // ������ n-1��° ����� next�� ���ο� ����� ����
        selectNode->next = newNode;
    }
    list->size++;
}

/*���� ���Ḯ��Ʈ*/
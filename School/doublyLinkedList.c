#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
5
A 1 S
A 2 t
A 3 r
A 3 a
P

9
A 1 D
A 2 a
A 3 y
D 1
P
G 3
A 1 S
P
G 3
*/
typedef struct _node {
	char elem;
	struct _node *prev;
	struct _node *next;
}Node;

typedef struct _list {
	int size;
	Node *header;
	Node *trailer;
}List;

List *listInit() {
	List *newList; 
	newList = (List *)malloc(sizeof(List)); 
	newList->header = (Node *)malloc(sizeof(Node));
	newList->trailer = (Node *)malloc(sizeof(Node));

	newList->header->next = newList->trailer;
	newList->header->prev = NULL;
	newList->trailer->prev = newList->header;
	newList->trailer->next = NULL;

	newList->size = 0;
	return newList;
}

void add(List *list, int r, char e) {
	int i;
	Node *newNode = (Node *)malloc(sizeof(Node));
	Node *s = list->header;
	Node *new = list->header;

	newNode->elem = e;
	for (i = 0; i < r - 1; i++) {
		s = s->next;
	}
	s->next->prev = newNode;
	newNode->next = s->next;
	s->next = newNode;
	newNode->prev = s;

	list->size++;
}
void delete(List *list, int r) {
	int i;
	Node *s = list->header;

	for (i = 0; i < r - 1; i++) {
		s = s->next;
	}
	//s는 선택 노드의 전 노드
	s->next = s->next->next;
	s->next->prev = s;

	list->size--;
}
char get(List *list, int r) {
	int i;
	Node *s = list->header->next;

	for (i = 0; i < r - 1; i++) {
		s = s->next;
	}
	return s->elem;
}
void print(List *list) {
	int i;
	Node *s = list->header->next;
	for (i = 0; i < list->size; i++) {
		printf("%c", s->elem);
		s = s->next;
	}
}
int main() {
	int N, i, index;
	char command, ch;
	List *list = listInit();

	scanf("%d", &N);
	getchar();
	for (i = 0; i < N; i++) {
		scanf("%c", &command);
		if (command == 'A') {
			scanf("%d %c", &index, &ch);
			if (list->size + 1 < index || index < 1) {
				printf("invalid position\n");
				getchar();
				continue;
			}
			add(list, index, ch);
		}
		else if (command == 'D') {
			scanf("%d", &index);
			if (list->size < index || index < 1) {
				printf("invalid position\n");
				getchar();
				continue;
			}
			delete(list, index);
		}
		else if (command == 'G') {
			scanf("%d", &index);
			if (list->size < index || index < 1) {
				printf("invalid position\n");
				getchar();
				continue;
			}
			printf("%c", get(list, index));
		}
		else if (command == 'P') {
			print(list);
			printf("\n");
		}
		getchar();
	}
	return 0;
}
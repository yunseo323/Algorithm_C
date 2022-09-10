#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
8
A 1 S
A 2 t
A 3 r
A 3 a
P
S 3 4
C
P

10
A 1 D
A 2 a
A 3 y
D 1
P
G 3
A 1 S
P
R
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
	/*for (i = 0; i < list->size; i++) {
		new = new->next;
		printf("%c\n", new->elem);
	}*/
}
void delete(List *list, int r) {
	int i;
	Node *s = list->header;

	for (i = 0; i < r - 1; i++) {
		s = s->next;
	}
	//s는 선택 노드의 전 노드
	s->next = s->next->next;
	s->next->prev = s; //순서 주의하기!! s->next->next->prev 아님 : 위에서 바꿨기 때문

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
void removeAll(List *list) {
	int i;
	list->header->next = list->trailer;
	list->trailer->prev = list->header;
	list->size = 0;
}
void count(List *list) {
	int cnt = 0;
	Node *s = list->header->next;

	while (s != list->trailer) {
		cnt++;
		s = s->next;
	}
	printf("%d\n", cnt);
}
void swap(List *list, int r1, int r2) {
	Node *a = (Node *)malloc(sizeof(Node));
	Node *b = (Node *)malloc(sizeof(Node));
	Node *tmp = (Node *)malloc(sizeof(Node));
	Node *s = list->header;
	int i;
	for (i = 0; i < r1; i++) {
		s = s->next;
	}
	a = s;
	s = list->header;
	for (i = 0; i < r2; i++) {
		s = s->next;
	}
	b = s;
	tmp->elem = b->elem;
	tmp->next = a->next;
	a->next->prev = tmp;
	tmp->prev = a->prev;
	a->prev->next = tmp;

	a->next = b->next;
	b->next->prev = a;
	a->prev = b->prev;
	b->prev->next = a;
}
int main() {
	int N, i, index;
	int r1, r2;
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
		else if (command == 'R') {
			removeAll(list);
		}
		else if (command == 'C') {
			count(list);
		}
		else if (command == 'S') {
			scanf("%d %d", &r1, &r2);
			if (r1 > list->size || r1<1 || r2>list->size || r2 < 1) {
				printf("invalid position\n");
				getchar();
				continue;
			}
			swap(list, r1, r2);
		}

		getchar();
	}
	return 0;
}